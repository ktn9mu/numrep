# a simle gnuplot macro

# Plot Bessel functions j0, j3, j5, j8
set terminal pngcairo size 1000,700 enhanced font "Arial,12"
set output "bessel.png"

set xlabel "x"
set ylabel "j_n(x)"
set title "Upward vs Downward Recursion for Bessel Functions"
set key outside top center horizontal box
set grid

# Define line styles for clarity
# Upward = solid lines
# Downward = thick dotted lines with distinct colors
set style line 1 lc rgb "blue"   lt 1 lw 2   # j0 upward
set style line 2 lc rgb "blue"   lt 1 lw 3 dt (10,5)  # j0 downward

set style line 3 lc rgb "green"  lt 1 lw 2   # j3 upward
set style line 4 lc rgb "green"  lt 1 lw 3 dt (10,5)  # j3 downward

set style line 5 lc rgb "red"    lt 1 lw 2   # j5 upward
set style line 6 lc rgb "red"    lt 1 lw 3 dt (10,5)  # j5 downward

set style line 7 lc rgb "purple" lt 1 lw 2   # j8 upward
set style line 8 lc rgb "purple" lt 1 lw 3 dt (10,5)  # j8 downward

plot \
"bessel0.dat" using 1:3 with lines ls 1 title "j0 upward", \
"bessel0.dat" using 1:2 with lines ls 2 title "j0 downward", \
"bessel3.dat" using 1:3 with lines ls 3 title "j3 upward", \
"bessel3.dat" using 1:2 with lines ls 4 title "j3 downward", \
"bessel5.dat" using 1:3 with lines ls 5 title "j5 upward", \
"bessel5.dat" using 1:2 with lines ls 6 title "j5 downward", \
"bessel8.dat" using 1:3 with lines ls 7 title "j8 upward", \
"bessel8.dat" using 1:2 with lines ls 8 title "j8 downward"



