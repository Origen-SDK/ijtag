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

  unless find_header('boost/graph/adjacency_list.hpp')
    abort "libboost is missing.  please install libboost"
  end
  unless have_library('boost_graph')
    abort "libboost is missing.  please install libboost"
  end
end

antlr_dir = Pathname.new(File.join(File.dirname(__FILE__), '..', 'antlr4-runtime')).realpath.to_s
icl_parser_dir = Pathname.new(File.join(File.dirname(__FILE__), '..', 'icl-parser')).realpath.to_s
lib_dir = Pathname.new(File.join(File.dirname(__FILE__), '..', '..', 'lib')).realpath.to_s

with_cflags("-x c++") do
  dir_config('antlr4-runtime', [antlr_dir], [lib_dir])

  unless find_header('antlr4-runtime.h')
    abort "Something has gone wrong, can't find antlr4-runtime.h"
  end
  unless have_library('antlr4-runtime')
    abort "Something has gone wrong, can't find libantlr4-runtime.so"
  end

  dir_config('icl-parser', [icl_parser_dir], [lib_dir])

  unless find_header('iclParser.h')
    abort "Something has gone wrong, can't find iclParser.h"
  end
  unless have_library('icl-parser')
    abort "Something has gone wrong, can't find libicl-parser.so"
  end
end


#$INCFLAGS << " -I$(srcdir)/../antlr4-runtime"
#$VPATH << "$(srcdir)/../antlr4-runtime"
#
#$srcs = []
#$objs = []
#$headers = []
#
#srcdir = Pathname.new(File.join(File.dirname(__FILE__))).realpath
#
#['.', '../antlr4-runtime'].each do |tdir|
#  Dir.glob("#{$srcdir}/#{tdir}/**/*.cpp").sort.map do |path|
#    $srcs << File.basename(path) unless tdir == '.'
#    $objs <<  File.basename(path).sub('.cpp', '.o')
#  end
#
#  #Dir.glob(["#{$srcdir}/#{tdir}/**/*.h", "#{$srcdir}/#{tdir}/**/*.hpp"]).sort.map do |path|
#  #  $srcs << File.basename(path)
#  #end
#
#  #Dir.glob("#{$srcdir}/#{tdir}/**/*.hpp").sort.map do |path|
#  #  $headers << File.basename(path)
#  #end
#
#  Dir.glob("#{$srcdir}/#{tdir}/**/*/").sort.each do |dir|
#    dir = Pathname.new(dir).expand_path.relative_path_from(srcdir).to_s
#    $VPATH << "$(srcdir)/#{dir}"
#  end
#end

create_makefile "ijtag"
