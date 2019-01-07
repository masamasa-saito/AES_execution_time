require 'benchmark'

i = 0
execution_time = Benchmark.realtime do
  for i in 0..9999 do
    puts "Hello world!"
  end
end

puts "Time taken to output Hello world! 10000 times (Ruby)：#{execution_time*1000}[ms]"
