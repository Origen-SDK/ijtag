require 'origen'
require_relative '../config/application.rb'
require 'treetop'
module IJTAG
  # Load all files in the lib directory via a wildcard, if your project becomes
  # large or load order dependencies start to creep in then you may need to
  # start taking control of this manually as described above.
  # Note that there is no problem from requiring a file twice (Ruby will ignore
  # the second require), so if you have a file that must be required up front
  # you can do that one manually and the let the wildcard take care of the rest.
  Dir.glob("#{File.dirname(__FILE__)}/**/*.rb").sort.each do |file|
    require file
  end

  class << self

    def icl_to_model(icl_str = nil, options = {})
      icl_str, options = nil, icl_str if icl_str.is_a?(Hash)
      icl_str ||= File.read(options[:file])
      ICL::Builder.build(icl_str)
    end
    alias :icl_to_network :icl_to_model
  end
end
