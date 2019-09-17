#require 'ffi'
#module IJTAG
#  class Network
#    extend FFI::Library
#
#    ffi_lib File.join(File.dirname(__FILE__), "../ijtag.so")
#
#    attach_function :string_from_library, [:string], :string
#    attach_function :number_from_library, [:int], :int
#    attach_function :boolean_from_library, [:int], :int
#  end
#end
