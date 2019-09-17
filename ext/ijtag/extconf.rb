require "mkmf-rice"

HEADER_DIRS = [
  # First search /opt/local for boost
  '/opt/local/include',

  # Then search /usr/local for people that installed from source
  '/usr/local/include',

  # Finally fall back to /usr
  '/usr/include',
]

LIB_DIRS = [
  # First search /opt/local for boost
  '/opt/local/lib',

  # Then search /usr/local for people that installed from source
  '/usr/local/lib',

  # Finally fall back to /usr
  '/usr/lib',

  # Ubuntu
  '/usr/lib/x86_64-linux-gnu'
]

with_cflags("-x c++") do
  dir_config('boost', HEADER_DIRS, LIB_DIRS)

  unless find_header('boost/graph/directed_graph.hpp')
    abort "libboost is missing.  please install libboost"
  end
  unless have_library('boost_graph')
    abort "libboost is missing.  please install libboost"
  end
end

$INCFLAGS << " -I$(srcdir)/antlr4-runtime"

srcdir = Pathname.new(File.join(File.dirname(__FILE__))).realpath

$srcs = Dir.glob("#{$srcdir}/**/*.cpp").map { |path| File.basename(path) }

Dir.glob("#{$srcdir}/**/*/") do |dir|
  dir = Pathname.new(dir).expand_path.relative_path_from(srcdir).to_s
  $VPATH << "$(srcdir)/#{dir}"
end

create_makefile "ijtag"
