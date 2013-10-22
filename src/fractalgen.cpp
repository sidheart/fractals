#include <iostream>
#include <time.h>
#include <cstdlib>
#include "Mandelbrot.h"
#include "Buddhabrot.h"

using namespace std;

int main(int argc, char *argv[])
{
    // Seed the random number generator
	srand(time(0));
   
    // Read command line input (if you're on windows, you might want to replace this with some I/O code)
    double a;
    char *str; 
	string fractal_type;
    str = (char *) malloc(sizeof(char) * 11);
	
    if (argc < 4)
    {
        a = 1.0;
		fractal_type = "Mandelbrot";
        strcpy(str,"output.png");
    }
    else
    {
        a = (double) atoi(argv[1]);
        str = argv[2];
		fractal_type = argv[3];
    }

    // Create a fractal object
	if(fractal_type == "Mandelbrot" || fractal_type == "mandelbrot") {
		Mandelbrot my_fractal(a);
		cout << "Fractal Allocated" << endl;

		// Generate the fractal
    	my_fractal.gen_fractal();
    	cout << "Fractal Created" << endl;
    
    	// Save the fractal to a file
		my_fractal.save_file(str);
    	cout << "Fractal Saved to file" << endl;

	}
	else if(fractal_type == "Buddhabrot" || fractal_type == "buddhabrot") {
		Buddhabrot my_fractal(a);
		cout << "Fractal Allocated" << endl;

		// Generate the fractal
    	my_fractal.gen_fractal();
    	cout << "Fractal Created" << endl;
    
    	// Save the fractal to a file
		my_fractal.save_file(str);
    	cout << "Fractal Saved to file" << endl;
	}
	else {
		cerr << "4th argument is not recognized, please specify Mandelbrot or Buddhabrot\n";
	}
	
    if (argc < 4)
    {
        free(str);
    }
	
    return 0;
}
