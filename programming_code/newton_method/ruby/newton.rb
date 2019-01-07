####################################################
#
# newton2.rb
#
# For a given cubic equation,
# read numerical values line by line from "../input/input.txt"
# by using the Newton method with their initial values,
# obtain execution time until solving all.
#
####################################################

require 'benchmark'


#=== f function : Return f (x) for argument x ===#

# The f(x) used this time is  " f(x) =  x^3 - 16x^2 + 73x - 90 " #
def f ( x )
  return (1 * (x**3)) + ((-16) * (x**2)) + (73 * x) + (-90)
end

#=== dfdx function: Return f'(x) for argument x ===#

# The f'(x) used this time is  " f'(x) = 3x^2 - 32x + 73 " #
def dfdx ( x )
  return (3 * (x**2)) + ((-32) * x) + (73)
end

#--- Define minimum value of termination condition ---#
Epsilon = 1e-5

#=== newton_method function: Find one solution of "f (x) = 0" using Newton's method ===#
def newton_method ( initial_value )
  x = initial_value
  i = 0
  while (f( x )).abs > Epsilon do
    x = x - f(x) / dfdx(x)
    i += 1
  end
  return x
end





### Read each line from an external input file and place it in the input array ###
input_arr = Array.new
File.foreach("../input/input.txt") do |line|
    input_arr << line.to_f
end

### Start time measurement from here ###
execution_time = Benchmark.realtime do
  input_arr.each do |initial_value| 
    answer = newton_method( initial_value )
  end
end

puts "Time taken to obtain 20000 solutions (Ruby)：#{execution_time*1000}[ms]"
