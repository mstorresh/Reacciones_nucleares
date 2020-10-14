all : tarea2.x datos.txt graficos.pdf okular

tarea2.x : tarea2.cpp
		g++ tarea2.cpp -o $@

	
datos.txt : tarea2.x
		./tarea2.x > datos.txt


graficos.pdf : datos.txt
		gnuplot graf.gp 

okular : graficos.pdf
		okular graficos.pdf

clean:
	rm -f datos.txt tarea2.x a.out graficos.pdf
