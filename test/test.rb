#! /usr/bin/env ruby

VERBOSE = false

def compile_and_test(test, *exflags)
  file = File.dirname(__FILE__) + "/test_#{test}.c"
  flags = "-std=c99 -Wall -Werror -fvisibility=hidden"
  exflags = exflags.join " "
  flags = "#{flags} #{exflags}"
  command = "clang #{flags} #{file} -otempfile.out > /dev/null 2>&1"
  puts command if VERBOSE
  rc = system command
  if File.exists? "tempfile.out"
    rc = rc and system "tempfile.out" 
    File.unlink "tempfile.out"
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
  
  #test disabling the debug environment
  %w{NDEBUG}.each do |flag|
    if !compile_and_test "debug_defines_f", "-D#{flag}=1"
      errors << "#{flag} should disable debug" 
    end
  end
  
  errors
end

errs = main
errlines = errs.join "\n"
puts "tests failed\n#{errlines}" if errs.length > 0
exit errs.length
