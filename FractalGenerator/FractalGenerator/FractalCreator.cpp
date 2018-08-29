#include "FractalCreator.h"
#include <assert.h>

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

	void FractalCreator::calculateRangeTotals()
	{
		int rangeIndex = 0;

		for(int i = 0; i < Fractal::MAX_ITERATIONS; i++)
		{
			int pixels = m_histogram[i];

			if(i >= m_ranges[rangeIndex + 1])
			{
				rangeIndex++;
			}

			m_rangeTotals[rangeIndex] += pixels;
		}
	}

	void FractalCreator::drawFractal()
	{
		RGB startColor(0, 0, 0);
		RGB endColor(0, 0, 255);
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

					// pow(255, hue)

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

	void FractalCreator::addRange(double rangeEnd, const RGB& rgb)
	{
		m_ranges.push_back(rangeEnd * Fractal::MAX_ITERATIONS);
		m_colors.push_back(rgb);

		if(m_bGotFirstRange)
		{
			m_rangeTotals.push_back(0);
		}

		m_bGotFirstRange = true;
	}

	int FractalCreator::getRange(int iterations) const
	{
		int range = 0;

		for(int i = 1; i < m_ranges.size(); i++)
		{
			range = i;

			if(m_ranges[i] > iterations)
			{
				break;
			}

		}

		range--;

		assert(range > -1);
		assert(range < m_ranges.size());

		return range;
	}
}

