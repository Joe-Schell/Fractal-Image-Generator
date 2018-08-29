#include "FractalCreator.h"
#include <assert.h>

using namespace std;

namespace fractalCore
{
	FractalCreator::FractalCreator(int width, int height) :
		m_width(width), m_height(height), m_histogram(
			new int[Fractal::MAX_ITERATIONS]{0}), m_fractal(
				new int[m_width * m_height]), m_bitmap(m_width, m_height), m_zoomList(
					m_width, m_height)
	{
		m_zoomList.add(Zoom(m_width / 2, m_height / 2, 4.0 / m_width));
	}

	FractalCreator::~FractalCreator() {}

	void FractalCreator::run(std::string name)
	{
		addZoom(Zoom(351, 435, 0.1));
		addZoom(Zoom(512, 265, 0.1));
		addZoom(Zoom(504, 462, 0.3));
		addZoom(Zoom(110, 365, 0.005));

		calculateIteration();
		calculateTotalIterations();
		drawFractal();
		writeBitmap(name);
	}

	void FractalCreator::addZoom(const Zoom& zoom)
	{
		m_zoomList.add(zoom);
	}

	void FractalCreator::calculateIteration()
	{
		for(int y = 0; y < m_height; y++)
		{
			for(int x = 0; x < m_width; x++)
			{
				std::pair<double, double> coords = m_zoomList.doZoom(x, y);

				int iterations = Fractal::getIterations(coords.first, coords.second);

				m_fractal[y * m_width + x] = iterations;

				if(iterations != Fractal::MAX_ITERATIONS)
				{
					m_histogram[iterations]++;
				}
			}
		}
	}

	void FractalCreator::calculateTotalIterations()
	{
		for(int i = 0; i < Fractal::MAX_ITERATIONS; i++)
		{
			m_total += m_histogram[i];
		}
	
	}

	void FractalCreator::drawFractal()
	{
		for(int y = 0; y < m_height; y++)
		{
			for(int x = 0; x < m_width; x++)
			{
				int iterations = m_fractal[y * m_width + x];

				double hue = 0.0;

				for(int i = 0; i <= iterations; i++)
				{
					hue += ((double) m_histogram[i]) / m_total;
				}

				uint8_t red = pow(255, hue);
				uint8_t green = 0;
				uint8_t blue = 0;

				m_bitmap.setPixel(x, y, red, green, blue);
			}
		}

	}

	void FractalCreator::writeBitmap(string name)
	{
		m_bitmap.write(name);
	}

} /* namespace caveofprogramming */

