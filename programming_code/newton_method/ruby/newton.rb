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
def f ( x )
  return (1 * (x**3)) + ((-16) * (x**2)) + (73 * x) + (-90)
end

#=== dfdx関数：引数xに対しf'(x)を返す ===#
def dfdx ( x )
  return (3 * (x**2)) + ((-32) * x) + (73)
end

#--- 終端条件の最小値を規定する ---#
Epsilon = 1e-5

#=== newton_method関数：ニュートン法を用いて、「f(x) = 0」の解をどれか一つ求める ===#
def newton_method ( initial_value )
  x = initial_value
  i = 0
  while (f( x )).abs > Epsilon do
    p sprintf("i = %2d   x = %20.16f",i,x)
    x = x - f(x) / dfdx(x)
    i += 1
  end
  return x
end





### 外部の入力ファイルから1行ずつ読み込んで、入力用の配列に入れる ###
input_arr = Array.new
File.foreach("../input/input.txt") do |line|
    input_arr << line.to_f
end

### ここから時間測定開始 ###
execution_time = Benchmark.realtime do
  input_arr.each do |initial_value| 
    answer = newton_method( initial_value )
    puts "answer = #{answer}"
    puts "==============================="
  end
end


puts "全ての解を求めるまでにかかった時間：#{execution_time*1000}[ms]"

