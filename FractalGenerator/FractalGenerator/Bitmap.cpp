#include <fstream>
#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

using namespace bitmapFunctions;
using namespace std;

namespace bitmapFunctions {

	Bitmap::Bitmap(int width, int height) :
		m_width(width), m_height(height)
	{

	}

	bool Bitmap::write(string filename) 
	{
		return false;
	}

	void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue)
	{

	}

	Bitmap::~Bitmap() {
		// TODO Auto-generated destructor stub
	}
}