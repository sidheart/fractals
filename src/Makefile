all: objs/Fractal.o objs/Buddhabrot.o objs/Mandelbrot.o objs/fractalgen.o objs/lodepng.o
	g++ -fopenmp -g -o fractalgen objs/Fractal.o objs/Buddhabrot.o objs/Mandelbrot.o objs/fractalgen.o objs/lodepng.o -ansi -pedantic -Wall -Wextra -O3

objs/Fractal.o: Fractal.cpp
	g++ -fopenmp -g -c -o objs/Fractal.o Fractal.cpp

objs/Mandelbrot.o: Mandelbrot.cpp 
	g++ -fopenmp -g -c -o objs/Mandelbrot.o Mandelbrot.cpp

objs/fractalgen.o: fractalgen.cpp
	g++ -fopenmp -g -c -o objs/fractalgen.o fractalgen.cpp

objs/Buddhabrot.o: Buddhabrot.cpp
	g++ -fopenmp -g -c -o objs/Buddhabrot.o Buddhabrot.cpp

objs/lodepng.o: lodepng.cpp
	g++ -fopenmp -g -c -o objs/lodepng.o lodepng.cpp

clean:
	rm objs/*.o fractalgen
