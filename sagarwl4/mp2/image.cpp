#include "image.h"
#include "png.h"
#include<iostream>

using namespace std;

void Image::flipleft()
{
//:: scope resolution - resolves the scope to the image class /basically this function 
//belongs to the image class
	int width_temp = width();  		//unsigned int is the same as size_t and there is no concept of negative numbers	
	int height_temp = height();		//unsigned int
	
	RGBAPixel temp;
	
	for (int x = 0; x < width_temp/2; x++)
	{
		for (int y = 0; y < height_temp; y++)
		{
			temp = (*(*this)(x,y));		//have a doubt about the pointers
			
			(*(*this)(x,y)) = (*(*this)(width_temp-x-1,y));
			(*(*this)(width_temp-x-1,y)) = temp;
		}	
	}
/*

	for (int x = 0; x < width_temp/2; x++)
	{
		for (int y = 0; y < height_temp; y++)
		{
			RGBApixel pixel1 = (*(*this)(x,y));
			(*(*this)(x,y)) = (*(*this)(width-x-1, y));
			(*(*this)(widthx-1,y)) = pixel1;
		}
	}
*/

}	

void Image::adjustbrightness(int r, int g, int b)
{
	int width_temp = width(); 		
	int height_temp = height();
	
	for (int y = 0; y < height_temp; y++)
	{
		for (int x = 0; x < width_temp; x++)
		{
			if (((*this)(x,y))->red + r > 255)
				((*this)(x,y))->red = 255;
			else if (((*this)(x,y))->red + r < 0)
				((*this)(x,y))->red = 0;
			else	 
				((*this)(x,y))->red = ((*this)(x,y))->red + r;
				
			
			if (((*this)(x,y))->blue + b > 255)
				((*this)(x,y))->blue = 255;
			else if (((*this)(x,y))->blue + b < 0)
				((*this)(x,y))->blue = 0;
			else	 
				((*this)(x,y))->blue = ((*this)(x,y))->blue + b;
			
			
			if (((*this)(x,y))->green + g > 255)
				((*this)(x,y))->green = 255;
			else if (((*this)(x,y))->green + g < 0)
				((*this)(x,y))->green = 0;
			else	 
				((*this)(x,y))->green = ((*this)(x,y))->green + g;	
		}
	}
}

void Image::invertcolors()
{
	int width_temp = width(); 		
	int height_temp = height();
	
	for (int y = 0; y < height_temp; y++)
	{
		for (int x = 0; x < width_temp; x++)
		{
			((*this)(x,y))->red = 255 - ((*this)(x,y))->red;
			((*this)(x,y))->blue = 255 - ((*this)(x,y))->blue;
			((*this)(x,y))->green = 255 - ((*this)(x,y))->green;
		
		}
	}
}


