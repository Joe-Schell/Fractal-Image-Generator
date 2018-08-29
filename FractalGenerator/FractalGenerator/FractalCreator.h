#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <string>
#include <cstdint>
#include <memory>
#include <math.h>
#include "Fractal.h"
#include "Bitmap.h"
#include "Zoom.h"
#include "ZoomList.h"
#include "RGB.h"

namespace fractalCore
{
	class FractalCreator
	{
	public:
		FractalCreator(int width, int height);
		virtual ~FractalCreator();
		void run(std::string name);
		void addZoom(const Zoom& zoom);

	private:
		int m_width;
		int m_height;
		int m_total{0};
		std::unique_ptr<int[]> m_histogram;
		std::unique_ptr<int[]> m_fractal;
		Bitmap m_bitmap;
		ZoomList m_zoomList;

		void calculateIteration();
		void calculateTotalIterations();
		void drawFractal();
		void writeBitmap(std::string name);
	};
}

#endif // FRACTALCREATOR_H_

