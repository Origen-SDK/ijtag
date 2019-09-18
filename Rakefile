# Add your own tasks in files placed in lib/tasks ending in .rake,
# for example lib/tasks/i_jtag.rake, and they will automatically
# be available to Rake.
#
# Any task files found in lib/tasks/shared/*.rake will be made available to 3rd party
# apps that use this plugin
require "bundler/setup"
require 'rake/extensiontask'
require "origen"

#Origen.app.load_tasks

task :default => :build

desc 'Compile the C++ extension'
task :build => 'ext/icl-parser/iclParser.cpp' do
  Rake::Task["compile"].invoke 
end

Rake::ExtensionTask.new('antlr4-runtime')
Rake::ExtensionTask.new('icl-parser')
Rake::ExtensionTask.new('ijtag')

file 'ext/icl-parser/iclParser.cpp' => 'grammars/icl.g4' do
  Dir.chdir 'grammars' do
    sh "java -jar #{ENV['ANTLR4']} -Dlanguage=Cpp -no-listener -visitor -o ../ext/icl-parser icl.g4"
  end
end

