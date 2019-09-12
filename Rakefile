# Add your own tasks in files placed in lib/tasks ending in .rake,
# for example lib/tasks/i_jtag.rake, and they will automatically
# be available to Rake.
#
# Any task files found in lib/tasks/shared/*.rake will be made available to 3rd party
# apps that use this plugin
require "bundler/setup"
require 'rake/extensiontask'
require "origen"

Origen.app.load_tasks

Rake::ExtensionTask.new('ijtag')
