#ifndef FRACTAL_H_
#define FRACTAL_H_

namespace fractalCore
{
	class Fractal
	{
	public:
		static const int MAX_ITERATIONS = 1000;

	public:
		Fractal();
		virtual ~Fractal();

		static int getIterations(double x, double y);
	};
}


#endif // FRACTAL_H_
