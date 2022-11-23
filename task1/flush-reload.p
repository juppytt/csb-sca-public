#!/usr/bin/env gnuplot
set datafile separator ','
set terminal png size 1600,600
set term png font "arial"
set style data histogram
set style histogram clustered
set style histogram gap 0
set style fill solid noborder
set output 'flush-reload.png'
set ylabel 'Number of memory accesses'
set ylabel font ",18"
set xlabel 'Cycles to load into memory'
set xlabel font ",18"
set xtics rotate
set key font ",14"
plot for [i=2:3] 'flush-reload.csv' using i:xtic(1) title columnheader
