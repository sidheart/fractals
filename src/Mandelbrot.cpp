#include "Mandelbrot.h"

void Mandelbrot::gen_fractal()
{
	// Real (-2.5, 1)
	// Imaginary (-1, 1)
    
    // Iterate over each pixel and determine the corresponding complex coordinate (or several complex coordinates if you're anti-aliasing)
    

        // For each pixel, compute the corresponding complex coordinate C (or multiple sub-coordinates, for AA)   

        // let z_r and z_i be 0
        // Begin iterating... while z is not infinity and not too many iterations have passed...
        
            // Z = Z^2 + C
            // increment an iteration counter

        // Color each pixel...
	int width = get_width(), height = get_height();
	const int NUM_PIXELS = width * height;

	for(int i = 0; i < NUM_PIXELS; i++) {
		int x = i % height;
		int y = i / height;
		int iter = 0;
		double c_r = (((double) x) / width) * 3.5 - 2.5;
		double c_i = (((double) y) / height) * 2 - 1;
		double z_r = 0, z_i = 0;
		double z_temp;

		for(iter; iter < MAXITER; iter++) {
			//Real component is a^2 - b^2
			z_temp = pow(z_r, 2.0) - pow(z_i, 2.0) + c_r;
			//Imaginary component is 2abi
			z_i = 2 * z_r * z_i + c_i;
			z_r = z_temp;

			//If Z escapes to infinity, it is not part of the Mandelbrot set
			if(pow(z_r, 2.0) + pow(z_i, 2.0) > 4) {
				break;
			}
		}

		//RGB respectively, when iter = MAXITER, the color will be white
		m_bitmap[x * height * 4 + y * 4] = pow( ((double) iter) / MAXITER, 0.6) * 255;
		m_bitmap[x * height * 4 + y * 4 + 1] = pow( ((double) iter) / MAXITER, 0.5) * 255;
		m_bitmap[x * height * 4 + y * 4 + 2] = pow( ((double) iter) / MAXITER, 0.4) * 255;
		m_bitmap[x * height * 4 + y * 4 + 3] = 255;
	}
}
