####################################################
#
# write_input_txt.rb
#
# 決められた3次の方程式に対し、
# 「../input/input.txt」のファイルから一行ずつ数値を読み込み、
# それらを初期値としたニュートン法で求めて、
# 全てを解き終わるまでの実行時間を求める
####################################################



### 外部の入力ファイルから1行ずつ読み込んで、入力用の配列に入れる ###
File.open("./input.txt","w+") do |f|
    for i in 1..500 do
        f.puts((rand(20000)-10000).to_s)
    end
end

### ここから時間測定開始 ###
=begin
execution_time = Benchmark.realtime do
  input_arr.each do |initial_value| 
    answer = newton_method( initial_value )
    puts "answer = #{answer}"
    puts "==============================="
  end
end


puts "全ての解を求めるまでにかかった時間：#{execution_time*1000}[ms]"
=end
