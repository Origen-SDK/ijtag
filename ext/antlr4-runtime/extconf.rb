require "mkmf"

srcdir = Pathname.new(File.join(File.dirname(__FILE__))).realpath

$srcs = Dir.glob("#{$srcdir}/**/*.cpp").map { |path| File.basename(path) }

Dir.glob("#{$srcdir}/**/*/") do |dir|
  dir = Pathname.new(dir).expand_path.relative_path_from(srcdir).to_s
  $VPATH << "$(srcdir)/#{dir}"
end

create_makefile "antlr4-runtime"
