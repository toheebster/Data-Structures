#ifndef RGBAPIXEL_H
#define RGBAPIXEL_H

#include <ostream>

class RGBAPixel{
public:

	RGBAPixel();
	RGBAPixel(unsigned char red, unsigned char green, unsigned char blue);

	unsigned char red;
	unsigned char blue;
	unsigned char green;
	unsigned char alpha;
};

#endif
