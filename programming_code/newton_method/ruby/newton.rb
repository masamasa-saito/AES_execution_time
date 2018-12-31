####################################################
#
# newton2.rb
#
# 決められた3次の方程式に対し、
# 「../input/input.txt」のファイルから一行ずつ数値を読み込み、
# それらを初期値としたニュートン法で求めて、
# 全てを解き終わるまでの実行時間を求める
####################################################

require 'benchmark'


#=== f関数：引数xに対しf(x)を返す ===#
#=== f function : Return f (x) for argument x ===#

# 今回使用した f(x) は、「 f(x) = x^3 - 16x^2 + 73x -90 」である #
# The f(x) used this time is  " f(x) =  x^3 - 16x^2 + 73x - 90 " #
def f ( x )
  return (1 * (x**3)) + ((-16) * (x**2)) + (73 * x) + (-90)
end

#=== dfdx関数：引数xに対しf'(x)を返す ===#
#=== dfdx function: Return f'(x) for argument x ===#

# 今回使用した f'(x) は、「 f'(x) = 3x^2 - 32x + 73 」である #
# The f'(x) used this time is  " f'(x) = 3x^2 - 32x + 73 " #
def dfdx ( x )
  return (3 * (x**2)) + ((-32) * x) + (73)
end

#--- 終端条件の最小値を規定する ---#
#--- Define minimum value of termination condition ---#
Epsilon = 1e-5

#=== newton_method関数：ニュートン法を用いて、「f(x) = 0」の解をどれか一つ求める ===#
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





### 外部の入力ファイルから1行ずつ読み込んで、入力用の配列に入れる ###
### Read each line from an external input file and place it in the input array ###
input_arr = Array.new
File.foreach("../input/input.txt") do |line|
    input_arr << line.to_f
end

### ここから時間測定開始 ###
### Start time measurement from here ###
execution_time = Benchmark.realtime do
  input_arr.each do |initial_value| 
    answer = newton_method( initial_value )
  end
end

#puts "全ての解を求めるまでにかかった時間：#{execution_time*1000}[ms]"
puts "Time taken to obtain 20000 solutions (Ruby)：#{execution_time*1000}[ms]"
