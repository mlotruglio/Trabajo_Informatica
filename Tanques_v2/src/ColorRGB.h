#pragma once 
#include "freeglut.h" 
typedef unsigned char Byte;
class ColorRGB
{
public:
	ColorRGB(Byte r = 255, Byte g = 255, Byte b = 255) {
		set(r, g, b);
	};
	void set(Byte r = 255, Byte g = 255, Byte b = 255) {
		red = r; green = g; blue = b;
	}
	Byte red, green, blue;
};