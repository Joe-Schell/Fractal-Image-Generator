
#include <iostream>
#include <cstdint>
#include "Bitmap.h"
#include "Fractal.h"

using namespace bitmapFunctions;

int main()
{
	int const WIDTH = 800;
	int const HEIGHT = 600;

	Bitmap bitmap(WIDTH, HEIGHT);

	//bitmap.setPixel(WIDTH / 2, HEIGHT / 2, 255, 255, 255);

	double min = 999999;
	double max = -999999;

	for (int y = 0; y < HEIGHT; y++)
	{
		for(int x = 0; x < WIDTH; x++)
		{
			double xFractal = (x - WIDTH/2 - 150) * (2.0/WIDTH);
			double yFractal = (y - HEIGHT/2) * (2.0/HEIGHT);

			int iterations = Fractal::getIterations(xFractal, yFractal);

			uint8_t red = (uint8_t)(256 * (double)iterations/Fractal::MAX_ITERATIONS);

			bitmap.setPixel(x, y, red, red, red);

			if(red < min) min = red;
			if(red > max) max = red;
		}
	}

	std::cout << min << ", " << max << std::endl;

	bitmap.write("fractal.bmp");

	std::cout << "Execution Complete!" << std::endl;

	//system("pause");

	return 0;
}