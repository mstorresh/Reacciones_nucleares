
set xlabel 'angulo (deg)'
set ylabel 'Cross section (fm^2)'
set title 'Cross sections'
set term pdf
set out "graficos.pdf"
plot 'datos.txt'  u 1:6 w lp t 'razon'
plot 'datos.txt' u 1:2 w lp t  'rutherforcm', '' u 1:4 w lp t 'CM', '' u 5:3 w lp t 'Lab'
