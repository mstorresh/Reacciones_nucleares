
all : tarea1.x datos.txt graficos.pdf okular

tarea1.x : tarea1.cpp
		g++ tarea1.cpp -o $@

	
datos.txt : tarea1.x
		./tarea1.x > datos.txt


graficos.pdf : datos.txt
		gnuplot plotfigure.gp 

okular : graficos.pdf
		okular graficos.pdf

clean:
	rm -f datos.txt tarea1.x a.out graficos.pdf
