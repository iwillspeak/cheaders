#! /usr/bin/env ruby

def compile_and_test(test)
  file = File.dirname(__FILE__) + "/test_#{test}.c"
  flags = "-std=c99 -Wall -Werror -fvisibility=hidden"
  command = "clang #{flags} #{file} -otempfile.out > /dev/null 2>&1"
  rc = system command
  if File.exists? "tempfile.out"
    rc = rc and system "tempfile.out" 
    File.unlink "tempfile.out"
  end
  rc
end

def main()
  
  errors = []
  %w[asserts_exports].each do |test|
    errors << "#{test} should compile" if !compile_and_test test
  end

  %w[assert_false1 assert_false2].each do |test|
    errors << "#{test} should not compile" if compile_and_test test
  end
  
  errors
end

errs = main
puts "#{errs.join '\n'} tests failed" if errs.length > 0
exit errs.length
