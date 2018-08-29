#include "FractalCreator.h"

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
		RGB startColor(0, 0, 0);
		RGB endColor(255, 0, 0);
		RGB colorDiff = endColor - startColor;

		for(int y = 0; y < m_height; y++)
		{
			for(int x = 0; x < m_width; x++)
			{
				uint8_t red = 0;
				uint8_t green = 0;
				uint8_t blue = 0;

				int iterations = m_fractal[y * m_width + x];

				if(iterations != Fractal::MAX_ITERATIONS)
				{
					double hue = 0.0;

					for(int i = 0; i <= iterations; i++)
					{
						hue += ((double) m_histogram[i]) / m_total;
					}

					red = startColor.r + pow(colorDiff.r, hue);
					green = startColor.g + pow(colorDiff.g, hue);
					blue = startColor.b + pow(colorDiff.b, hue);
				}

				m_bitmap.setPixel(x, y, red, green, blue);
			}
		}
	}

	void FractalCreator::writeBitmap(std::string name)
	{
		m_bitmap.write(name);
	}
}

