all: Fractal.o Buddhabrot.o Mandelbrot.o fractalgen.o lodepng.o
	g++ -fopenmp -g -o fractalgen Fractal.o Buddhabrot.o Mandelbrot.o fractalgen.o lodepng.o -ansi -pedantic -Wall -Wextra -O3

Fractal.o: Fractal.cpp
	g++ -fopenmp -g -c -o Fractal.o Fractal.cpp

Mandelbrot.o: Mandelbrot.cpp 
	g++ -fopenmp -g -c -o Mandelbrot.o Mandelbrot.cpp

fractalgen.o: fractalgen.cpp
	g++ -fopenmp -g -c -o fractalgen.o fractalgen.cpp

Buddhabrot.o: Buddhabrot.cpp
	g++ -fopenmp -g -c -o Buddhabrot.o Buddhabrot.cpp

lodepng.o: lodepng.cpp
	g++ -fopenmp -g -c -o lodepng.o lodepng.cpp

clean:
	rm *.o fractalgen
