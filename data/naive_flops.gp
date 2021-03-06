#set terminal dumb enhanced ansi256
#set term dumb 94 44
set terminal png 
set autoscale
set output "naive_flops.png" 
set xlabel "N"
set ylabel "Gflop/s"
set title "Intel Core i7-9750H, gcc 9.3.0"
set border 3 lw 1
set tics nomirror
set key inside left 
plot "naive_perf.dat" using 1:($3/1e9) with linespoints title "Naive"
