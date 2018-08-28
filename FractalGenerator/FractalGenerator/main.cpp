
#include <iostream>
#include "Bitmap.h"

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
			double xFractal = (x - WIDTH / 2) * 2.0 / WIDTH;
			double yFractal = (y - HEIGHT / 2) * 2.0 / HEIGHT;

			if(yFractal < min) min = yFractal;
			if(yFractal > max) max = yFractal;
		}
	}

	std::cout << min << ", " << max << std::endl;

	bitmap.write("fractal.bmp");

	std::cout << "Execution Complete!" << std::endl;

	return 0;
}