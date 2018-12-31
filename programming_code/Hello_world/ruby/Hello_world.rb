require 'benchmark'
i = 0
execution_time = Benchmark.realtime do
  for i in 0..9999 do
    puts "Hello world!"
  end
end

#puts "全ての解を求めるまでにかかった時間：#{execution_time*1000}[ms]"
puts "Time taken to obtain all solutions (Ruby)：#{execution_time*1000}[ms]"
