#include "Image.h"
#include "cs225/PNG.h"
using namespace std;
using namespace cs225;
void Image::lighten(){
	this->lighten(0.1);
}
void Image::lighten(double amount)
{
	for (unsigned x = 0; x < this->width(); x++)
	{
		for (unsigned y = 0; y < this->height(); y++)
		{
			HSLAPixel *pixel = this->getPixel(x,y);
			double luminance = pixel->l;
			luminance += amount;
			if (luminance < 0)
			{
				luminance = 0;
			}
			if (luminance > 1)
			{
				luminance = 1;
			}
			pixel->l = luminance;
		}
	}
}
void Image::darken()
{
	this->lighten(-0.1);
}
void Image::darken(double amount)
{
	this->lighten(-1.0*amount);
}
void Image::saturate()
{
	this->saturate(0.1);
}
void Image::saturate(double amount)
{
	for (unsigned x=0; x < this -> width(); x++)
	{
		for (unsigned y = 0; y <  this -> height(); y++)
		{
			HSLAPixel* pixel  = this -> getPixel(x,y);
			double saturation = pixel->s;
			saturation += amount;
			if (saturation > 1)
			{
				saturation = 1;
			}
			if (saturation < 0)
			{
				saturation = 0;
			}
			pixel->s = saturation;		
		}
	}
}
void Image::desaturate()
{
	this->saturate(-0.1);
}
void Image::desaturate(double amount)
{
	this->saturate(amount*-1.0);
}
void Image::grayscale()
{
	this->saturate(-1.0);

}
void Image::scale(double factor)
{
	this->_scale(factor, factor);	
}
void Image::scale(unsigned w, unsigned h)
{
	double scaleX = (1.0 * w) / (1.0 * this->width());
	double scaleY = (1.0 * h) / (1.0 * this->height());
	this->_scale(scaleX,scaleY);
}
void Image:: _scale(double scaleX, double scaleY)
{
	unsigned newX = scaleX * this->width();
	unsigned newY = scaleY * this->height();
	PNG * copied = new PNG(*this);
	this->resize(newX, newY);
	for (unsigned x=0; x < newX; x++)
	{
		for (unsigned y = 0; y < newY; y++)
		{
			HSLAPixel* newPixel = this->getPixel(x,y);
			unsigned oldX = x / scaleX;
			unsigned oldY = y / scaleY;
			HSLAPixel* oldPixel = copied->getPixel(oldX, oldY);
			*newPixel = *oldPixel;
		}
	}
}
void Image::illinify()
{
 for (unsigned x = 0; x < this->width(); x++){
  for (unsigned y = 0; y < this->height(); y++){
        HSLAPixel *pixel = getPixel(x,y);
        double hue = pixel->h;
        bool blue = true;
        if (hue < 11)
        {
                blue = false;
        }
        else if(hue > 216)
        {
                if (hue - 216 > 371 - hue)
                {
                        blue = false;
                }
        }
        else
        {
                if (216 - hue > hue - 11)
                {
                        blue = false;
                }
        }
        if (blue == true)
        {
                pixel->h = 216;
        }
        else
        {
                pixel->h = 11;
        }

}
}

}
void Image::rotateColor(double degrees)
{
	for (unsigned x = 0; x < this -> width(); x++)
	{
		for (unsigned y = 0;y< this -> height(); y++)
		{
			HSLAPixel *pixel = getPixel(x,y);
			double hue = pixel->h;
			hue += degrees;
			while(hue < 0)
			{
				hue += 360;
			}
			while (hue > 360)
			{
				hue -= 360;
			}
			pixel->h = hue;
		}
	}
}
