#include <cmath>
#include <vector>
#include <time.h>
#include "Buddhabrot.h"
using namespace std;

bool IsMandelbrot(double c_r, double c_i) {
	double z_r = 0, z_i = 0, z_temp;	
	double q = pow(c_r - .25, 2.0) + pow(c_i, 2.0);

	//Checks if point is in main cardioid
	if(q * (q + (c_r - .25)) < .25 * pow(c_i, 2.0)) {
		return true;
	}

	//Check if point is in period 2 bulb
	if(pow(c_r + 1, 2.0) + pow(c_i, 2.0) < .0625) {
		return true;
	}

	for(int iter = 0; iter < MAXITER; iter++) {
		z_temp = pow(z_r, 2.0) - pow(z_i, 2.0) + c_r;
		z_i = 2 * z_r * z_i + c_i;
		z_r = z_temp;

		if(pow(z_r, 2.0) + pow(z_i, 2.0) > 4) { 
			return false;
		}
	}
	return true;
}

void Buddhabrot::gen_fractal()
{
	// Real (-2.5, 1)
	// Imaginary (-1, 1)
    // Initialize a bucket array (one integer for each pixel) (this is the outer bucket array)

    // iterate over the following several thousand times (at least more times than # of pixels)
  
        // Create a temporary bucket array (one integer for each pixel
        //
        // Let C be a random point in the complex plane
        //
        // Trace the orbit of C, incrementing the temporary bucket that z falls in for each iteration
        // If Z is in the mandelbrot set, discard the temporary bucket
        // Else, merge the temporary bucket with the outer bucket array
        

     // Normalize the global bucket array by dividing each value by the maximum value
     // Color each pixel however you wish
     //
     // Parallelizing this function is tricky. It helps to have a list of temporary bucket arrays
     // Which are merged after the computation has finished.
     
     // Parallelizing is not required, but will save you a lot of time.
	int width = get_width(), height = get_height();
	const int NUM_PIXELS = width * height;
	double buckets [NUM_PIXELS];
	int max_value = 0;
	srand(time(NULL));

	 //Initialize each bucket to 0
	for(int i = 0; i < NUM_PIXELS; i++) {
		buckets[i] = 0;	
	}


	for(int i = 0; i < NUM_PIXELS * 15; i++) {
	 	double buckets_temp [NUM_PIXELS];
		double z_r = 0, z_i = 0;
		double z_temp;
		double c_r, c_i;
	 	int iter = 0;
		
		do {
			c_r = (double) rand() / RAND_MAX * 3.5 - 2.5;
			c_i = (double) rand() / RAND_MAX * 2 - 1;			
		} while(IsMandelbrot(c_r, c_i));

		for(int j = 0; j < NUM_PIXELS; j++) {
				buckets_temp[j] = buckets[j];
	 	}

		for(iter; iter < MAXITER; iter++) {
			z_temp = pow(z_r, 2.0) - pow(z_i, 2.0) + c_r;
			z_i = 2 * z_r * z_i + c_i;
			z_r = z_temp;

			if(pow(z_r, 2.0) + pow(z_i, 2.0) > 4) { 
				for(int i = 0; i < NUM_PIXELS; i++) {
					buckets[i] = buckets_temp[i];
	 			}
				break;
			}

			//x shifts up for decrease down for increase
			//Compresses vertically for increasing divisor
			//y shifts right for increase left for decrease
			//Compresses horizontally for increasing divisor
			int x = (int) (((z_r + 1.6) / 2.5) * (width));
			int y = (int) (((z_i + 1.03) /  2.05) * (height));
			
			if(0 <= x && x < width && 0 <= y && y < height) {
				buckets_temp[height * x + y]++;
			}
	 	}

	}

	for(int i = 0; i < NUM_PIXELS; i++) {
		if(buckets[i] > max_value) {
			max_value = buckets[i];
		}
	}

	for(int i = 0; i < NUM_PIXELS; i++) {
			buckets[i] /= max_value;
			m_bitmap[i * 4] = (int) (buckets[i] * 255);
			m_bitmap[i * 4 + 1] = (int) (buckets[i] * 51);
			m_bitmap[i * 4 + 2] = (int) (buckets[i] * 51);
			m_bitmap[i * 4 + 3] = 255;
	}
}
    

