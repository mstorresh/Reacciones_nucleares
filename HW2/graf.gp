set xlabel 'thetaCM (deg)'
set ylabel 'thetalab (deg)'
set xrange [-1:182]
set yrange [-1: 35]
set title 'Relation between the 2 angles'
set term pdf
set out "graficos.pdf"
plot 'datos.txt'  w l t 'relation', 30 w l t 'max'
