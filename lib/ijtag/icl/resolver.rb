require 'ijtag/icl/processor'
module IJTAG
  module ICL
    # The resolver processes the AST before it is used to build the network
    # model. Its job is to resolve any expressions, substituting parameters as
    # required, and perform any cleanup/simplification that can be done to make
    # the job of building the network easier.
    #
    # At this point we can start to move away from strict alignment with the spec
    # grammar and start to introduce our own internal representations.
    class Resolver < Processor
      def process(node, params = nil)
        @params = params if params
        super(node)
      end

      def compute_op(node)
        # Process all child nodes to convert everything to INTs and
        # resolve parameters
        nodes = process_all(node)

        if nodes.all? { |node| node.type == :POS_INT }
          values = nodes.map { |node| node.children.first }
          AST::Node.new(:POS_INT, [
            yield(values)
          ])
        else
          # Should this really be an error, no where to go from here really?
          node.updated(nil, nodes)
        end
      end

      def on_add(node)
        compute_op(node) { |left, right| left + right }
      end

      def on_UNSIZED_BIN_NUMBER(node)
        n :POS_INT, node.children[0].to_i(2)
      end

      def on_UNSIZED_HEX_NUMBER(node)
        n :POS_INT, node.children[0].to_i(16)
      end

      # These just get rid of the size component so that it can be treated
      # like a regular number in additions, don't think the size is really
      # required anywhere
      def on_sized_dec_number(node)
        node.children[1]
      end

      def on_sized_bin_number(node)
        on_UNSIZED_BIN_NUMBER(node.children[1])
      end

      def on_sized_hex_number(node)
        on_UNSIZED_HEX_NUMBER(node.children[1])
      end
    end
  end
end
