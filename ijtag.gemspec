# coding: utf-8
config = File.expand_path('../config', __FILE__)
require "#{config}/version"

Gem::Specification.new do |spec|
  spec.name          = "ijtag"
  spec.version       = IJTAG::VERSION
  spec.authors       = ["Stephen McGinty"]
  spec.email         = ["stephen.mcginty@freescale.com"]
  spec.summary       = "Origen interface/driver for the IEEE 1687 (IJTAG) standard"
  spec.homepage      = "http://origen-sdk.org/ijtag"

  spec.required_ruby_version     = '>= 2'
  spec.required_rubygems_version = '>= 1.8.11'

  # Only the files that are hit by these wildcards will be included in the
  # packaged gem, the default should hit everything in most cases but this will
  # need to be added to if you have any custom directories
  spec.files         = Dir["lib/**/*.rb", "templates/**/*", "config/**/*.rb",
                           "bin/*", "lib/tasks/**/*.rake", "pattern/**/*.rb",
                           "program/**/*.rb"
                          ]
  spec.executables   = []
  spec.require_paths = ["lib"]

  # Add any gems that your plugin needs to run within a host application
  spec.add_runtime_dependency "origen", ">= 0.5.7"
  spec.add_runtime_dependency "treetop", '~>1'
  spec.add_runtime_dependency "ast"
  spec.add_runtime_dependency "origen_jtag"

  # Add any gems that your plugin needs for its development environment only
  spec.add_development_dependency "origen_doc_helpers"
  spec.add_development_dependency "stackprof"
end
