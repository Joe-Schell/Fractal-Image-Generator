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
#include "RGB.h"

using namespace fractalCore;

int main()
{
	FractalCreator fractalCreator(800, 600);

	fractalCreator.addRange(0.0, RGB(0, 0, 0));
	fractalCreator.addRange(0.3, RGB(255, 0, 0));
	fractalCreator.addRange(0.5, RGB(255, 255, 0));
	fractalCreator.addRange(1.0, RGB(255, 255, 255));

	std::cout << fractalCreator.getRange(999) << std::endl;

	fractalCreator.addZoom(Zoom(351, 435, 0.1));
	fractalCreator.addZoom(Zoom(512, 265, 0.1));
	fractalCreator.addZoom(Zoom(504, 462, 0.3));
	fractalCreator.addZoom(Zoom(110, 365, 0.01));
	fractalCreator.run("fractal.bmp");

	std::cout << "Execution Complete!" << std::endl;

	//system("pause");

	return 0;
}