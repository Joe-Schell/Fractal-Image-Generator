#include <fstream>
#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

using namespace bitmapFunctions;

namespace bitmapFunctions {

	Bitmap::Bitmap(int width, int height) : m_width(width),
		m_height(height), m_pPixels(new uint8_t[width * height * 3]{})
	{

	}

	bool Bitmap::write(std::string filename) 
	{
		BitmapFileHeader fileHeader;
		BitmapInfoHeader infoHeader;

		fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width * m_height * 3;
		fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

		infoHeader.width = m_width;
		infoHeader.height = m_height;

		std::ofstream outFile;
		outFile.open(filename, std::ios::out | std::ios::binary);

		if(!outFile)
		{
			return false;
		}

		outFile.write((char *) &fileHeader, sizeof(fileHeader));
		outFile.write((char *) &infoHeader, sizeof(infoHeader));
		outFile.write((char *) m_pPixels.get(), m_width * m_height * 3);

		outFile.close();

		if(!outFile)
		{
			return false;
		}

		return true;
	}

	void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue)
	{

	}

	Bitmap::~Bitmap() {
		// TODO Auto-generated destructor stub
	}
}