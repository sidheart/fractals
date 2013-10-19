#include "Buddhabrot.h"
using namespace std;

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
	double buckets [height][width];
	int max_value;
	srand(0);

	 //Initialize each bucket to 0
	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			buckets[i][j] = 0;
		}
	 }

	for(int i = 0; i < height * width * 5; i++) {
	 	double buckets_temp [height][width];
		double z_r = 0, z_i = 0;
		double z_temp;
		double c_r = (double) rand() / RAND_MAX * 3.5 - 2.5;
		double c_i = (double) rand() / RAND_MAX * 2 - 1;
	 	int iter = 0;
		
		for(int i = 0; i < height; i++) {
			for(int j = 0; j < width; j++) {
				buckets_temp[i][j] = buckets[i][j];
			}
	 	}

		for(iter; iter < MAXITER; iter++) {
			z_temp = pow(z_r, 2.0) - pow(z_i, 2.0) + c_r;
			z_i = 2 * z_r * z_i + c_i;
			z_r = z_temp;
			int x = (int) (z_r) % width;
			int y = (int) (z_i) % height;
			buckets_temp[y][x]++;		
	 	}

		if(pow(z_r, 2.0) + pow(z_i, 2.0) > 4) { 
			for(int i = 0; i < height; i++) {
				for(int j = 0; j < width; j++) {
					buckets[i][j] = buckets_temp[i][j];
				}
	 		}
		}
	}

	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			if(buckets[i][j] > max_value) {
				buckets[i][j] = max_value;
			}
		}
	}

	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			buckets[i][j] /= max_value;
			//THERES A PROBLEM HERE, FIND IT ASSHOLE
			m_bitmap[j * height * 4 + i * 4] = buckets[i][j] * 255;
			m_bitmap[j * height * 4 + i * 4 + 1] = buckets[i][j] * 255;
			m_bitmap[j * height * 4 + i * 4 + 2] = buckets[i][j] * 255;
			m_bitmap[j * height * 4 + i * 4] = 255;
		}
	}
}
    

