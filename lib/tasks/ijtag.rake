# You can define any Rake tasks to support your application here (or in any file
# ending in .rake in this directory).
#
# Rake (Ruby Make) is very useful for creating build scripts, see this short video
# for a quick introduction:
# http://railscasts.com/episodes/66-custom-rake-tasks

task default: [:compile]

desc 'Compile the latest grammar files'
task :compile do
  Dir.chdir Origen.root do
    #    sh %(lbin/tt --force grammars/icl.treetop)
    sh %(lbin/tt --force grammars/pdl.treetop)
  end
end
