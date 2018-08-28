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

	bitmap.setPixel(WIDTH / 2, HEIGHT / 2, 255, 255, 255);

	bitmap.write("test.bmp");

	std::cout << "Execution Complete!" << std::endl;

	return 0;
}