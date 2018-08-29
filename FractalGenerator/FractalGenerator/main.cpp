
#include <iostream>
#include <cstdint>
#include <memory>
#include <math.h>
#include "Bitmap.h"
#include "Fractal.h"
#include "Zoom.h"
#include "ZoomList.h"

using namespace bitmapFunctions;

int main()
{
	int const WIDTH = 800;
	int const HEIGHT = 600;

	Bitmap bitmap(WIDTH, HEIGHT);

	double min = 999999;
	double max = -999999;

	ZoomList zoomList(WIDTH, HEIGHT);

	zoomList.add(Zoom(WIDTH/2, HEIGHT/2, 1));

	std::unique_ptr<int[]> histogram(new int[Fractal::MAX_ITERATIONS]{0});
	std::unique_ptr<int[]> fractal(new int[WIDTH * HEIGHT]);

	for (int y = 0; y < HEIGHT; y++)
	{
		for(int x = 0; x < WIDTH; x++)
		{
			double xFractal = (x - WIDTH/2 - 200) * (2.0/WIDTH);
			double yFractal = (y - HEIGHT/2) * (2.0/HEIGHT);

			int iterations = Fractal::getIterations(xFractal, yFractal);

			fractal[y * WIDTH + x] = iterations;
			
			if (iterations != Fractal::MAX_ITERATIONS)
			{
				histogram[iterations]++;
			}
		}
	}

	int total = 0;

	for (int i = 0; i < Fractal::MAX_ITERATIONS; i++)
	{
		total += histogram[i];
	}
	
	for(int y = 0; y < HEIGHT; y++)
	{
		for(int x = 0; x < WIDTH; x++)
		{
			int iterations = fractal[y * WIDTH + x];

			double hue = 0.0;

			for (int i = 0; i <= iterations; i++)
			{
				hue += ((double) histogram[i]) / total;
			}

			uint8_t red = 0;
			uint8_t green = pow(255, hue);
			uint8_t blue = 0;

			bitmap.setPixel(x, y, red, green, blue);
		}
	}

	bitmap.write("fractal.bmp");

	std::cout << "Execution Complete!" << std::endl;

	//system("pause");

	return 0;
}