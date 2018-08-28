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
	Bitmap bitmap(800, 600);

	bitmap.write("test.bmp");

	std::cout << "Execution Complete!" << std::endl;

	return 0;
}