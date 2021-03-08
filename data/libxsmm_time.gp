#set terminal dumb enhanced ansi256 
#set term dumb 94 44
set terminal png 
set autoscale
set output "libxsmm_time.png" 
set xlabel "N"
set ylabel "s"
set border 3 lw 1
set title "Intel Core i7-9750H, gcc 9.3.0"
set tics nomirror
set key inside left
plot "openblas_perf.dat" using 1:2 with linespoints title "OpenBLAS",\
     "libxsmm_perf.dat" using 1:2 with linespoints title "LIBXSMM"
