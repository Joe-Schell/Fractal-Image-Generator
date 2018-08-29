/*
*  Project:  Fractal Image Generator
*  Date:     08/27/2018
*  Author:   Joseph Schell
*/
#include <iostream>
#include <cstdint>
#include <memory>
#include <math.h>
#include "Bitmap.h"
#include "Fractal.h"
#include "Zoom.h"
#include "ZoomList.h"
#include "FractalCreator.h"

using namespace fractalCore;

int main()
{
	FractalCreator fractalCreator(800, 600);

	fractalCreator.run("fractal.bmp");

	std::cout << "Execution Complete!" << std::endl;

	//system("pause");

	return 0;
}