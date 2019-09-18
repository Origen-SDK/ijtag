require "mkmf"
require 'byebug'

antlr_dir = Pathname.new(File.join(File.dirname(__FILE__), '..', 'antlr4-runtime')).realpath.to_s
lib_dir = Pathname.new(File.join(File.dirname(__FILE__), '..', '..', 'lib')).realpath.to_s

with_cflags("-x c++") do
  dir_config('antlr4-runtime', [antlr_dir], [lib_dir])

  unless find_header('antlr4-runtime.h')
    abort "Something has gone wrong, can't find antlr4-runtime.h"
  end
  unless have_library('antlr4-runtime')
    abort "Something has gone wrong, can't find antlr4-runtime.so"
  end
end

create_makefile "icl-parser"
