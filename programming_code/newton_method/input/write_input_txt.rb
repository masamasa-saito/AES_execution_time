####################################################
#
# write_input_txt.rb
#
# Write 20000 random numbers from -10000 to 9999 
# on a line of "./input.txt" line by line.
#
####################################################



### Write a random value from -10000 to 9999 on a line for external input  ###
File.open("./input.txt","w+") do |f|
    for i in 1..20000 do
        f.puts((rand(20000)-10000).to_s)
    end
end

