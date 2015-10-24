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

      def process(node, params=nil)
        @params = params if params
        super(node)
      end
    end
  end
end
