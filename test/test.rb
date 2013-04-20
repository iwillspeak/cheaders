#! /usr/bin/env ruby

VERBOSE = false

def make_flags(*flag_list)
  flags = "-std=c99 -Wall -Werror -fvisibility=hidden"
  flags = "#{flags} #{flag_list.join ' '}"
end

def delete_files(*paths)
  paths.each do |path|
    File.unlink path if File.exists? path
  end
end

def compile_file_with_flags(file, flags, outfile)
  command = "clang #{flags} #{file} -o#{outfile} > /dev/null 2>&1"
  puts command if VERBOSE
  system command
end

def compile_and_test(test, *exflags)
  file = File.dirname(__FILE__) + "/test_#{test}.c"
  flags = make_flags(exflags)
  rc = compile_file_with_flags file, flags, "tempfile.out"
  if File.exists? "tempfile.out"
    rc = rc and system "tempfile.out" 
    delete_files "tempfile.out"
  end
  rc
end

def main()
  
  errors = []
  
  # Tests that should pass
  %w[DEBUG NDEBUG].each do |flag|
    flag = "-D#{flag}"
    
    %w[asserts_exports].each do |test|
      errors << "#{test} should compile (#{flag})" if !compile_and_test test, flag
    end

    # tests that should fail
    %w[assert_false1 assert_false2].each do |test|
      errors << "#{test} should not compile (#{flag})" if compile_and_test test, flag
    end
  end
  
  # test enabling the debug environment
  %w{DEBUG __DEBUG __DEBUG__ _DEBUG}.each do |flag|
    if !compile_and_test "debug_defines_t", "-D#{flag}=1"
      errors << "#{flag} should enable debug" 
    end
  end
  
  # test disabling the debug environment
  %w{NDEBUG}.each do |flag|
    if !compile_and_test "debug_defines_f", "-D#{flag}=1"
      errors << "#{flag} should disable debug" 
    end
  end
  
  # test creating a library and using it
  if !compile_file_with_flags "test/test_lib_bar.c", make_flags("-shared", "-Bdynamic"), "libbar.dylib"
    errors << "Can't compile libbar"
  end
  if !compile_file_with_flags "test/test_lib_foo.c", make_flags("-shared", "-Bdynamic", "-L./", "-lbar"), "libfoo.dylib"
    errors << "Can't compile libfoo"
  end
  if !compile_and_test "lib_main", "-L./", "-lfoo"
    errors << "Can't link library test"
  end
  delete_files "libfoo.dylib", "libbar.dylib"
  
  errors
end

errs = main
errlines = errs.join "\n\t"
puts "tests failed:\n\t#{errlines}" if errs.length > 0
exit errs.length
