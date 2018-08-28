/*
*  Project:  Fractal Image Generator
*  Date:     08/27/2018
*  Author:   Joseph Schell
*/
#include <iostream>
#include "Bitmap.h"

using namespace bitmapFunctions;

int main()
{
	//Bitmap bitmap(800, 600);

	int const WIDTH = 800;
	int const HEIGHT = 600;

	Bitmap bitmap(WIDTH, HEIGHT);

	

	for (int y = 0; y < HEIGHT; y++)
	{
		for(int x = 0; x < WIDTH; x++)
		{
			bitmap.setPixel(x, y, 0, 0, 255);
		}
	}

	bitmap.write("test.bmp");

	std::cout << "Execution Complete!" << std::endl;

	return 0;
}