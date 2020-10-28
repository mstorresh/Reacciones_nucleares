
set xlabel 'Energia (MeV)'
set ylabel '\delta (DEG)'
set title 'Desfase '
set term pdf


set out "graficosshif.pdf"
plot 'datosl0.txt' w l t "L=0", 'datosl1.txt' w l t "L=1", 'datosl2.txt' w l t "L=2", 'datosl3.txt' w l t "L=3" 
