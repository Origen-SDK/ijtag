# This file is used to boot your plugin when it is running in standalone mode
# from its own workspace - i.e. when the plugin is being developed.
#
# It will not be loaded when the plugin is imported by a 3rd party app - in that
# case only lib/i_jtag.rb is loaded.
#
# Therefore this file can be used to load anything extra that you need to boot
# the development environment for this app. For example this is typically used
# to load some additional test classes to use your plugin APIs so that they can
# be tested and/or interacted with in the console.
require "ijtag"

# Load a Top-level/DUT class that is defined within this plugin's lib directory
# and is required by some of our tests.
# Normally such a class should not be exposed to 3rd party users of the plugin,
# so we required it here rather than in lib/i_jtag.rb.
#require "i_jtag/test/top_level"
