#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <string>
#include <cstdint>
#include <memory>
#include <math.h>
#include <vector>
#include "Fractal.h"
#include "Bitmap.h"
#include "Zoom.h"
#include "ZoomList.h"
#include "RGB.h"

namespace fractalCore
{
	class FractalCreator
	{
	private:
		int m_width;
		int m_height;
		std::unique_ptr<int[]> m_histogram;
		std::unique_ptr<int[]> m_fractal;
		Bitmap m_bitmap;
		ZoomList m_zoomList;
		int m_total{0};
		std::vector<int> m_ranges;
		std::vector<RGB> m_colors;
		std::vector<int> m_rangeTotals;
		bool m_bGotFirstRange{false};

		void calculateIteration();
		void calculateTotalIterations();
		void calculateRangeTotals();
		void drawFractal();
		void writeBitmap(std::string name);


	public:
		FractalCreator(int width, int height);
		virtual ~FractalCreator();
		void run(std::string name);
		void addZoom(const Zoom& zoom);
		void addRange(double rangeEnd, const RGB& rgb);
		int getRange(int iterations) const;
	};
}

#endif // FRACTALCREATOR_H_

