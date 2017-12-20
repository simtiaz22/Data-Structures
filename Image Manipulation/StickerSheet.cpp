#include "cs225/PNG.h"
#include "Image.h"
#include "StickerSheet.h"
#include <iostream>


using namespace std;
using namespace cs225;

StickerSheet :: StickerSheet(const Image &picture, unsigned max)
{
	pic_ = new Image(picture);
	max_ = max;
	arr_ = new Image*[max];
	x_ = new unsigned[max];
	y_ = new unsigned[max];
	for (unsigned i=0; i < max; i++)
	{
		arr_[i] = NULL;
		x_[i] = 0;
		y_[i] = 0;
	}
}
StickerSheet:: StickerSheet(const StickerSheet &other)
{
	this->_copy(other);
}
const StickerSheet& StickerSheet:: operator= (const StickerSheet &other)
{
	if (this != &other)
	{
		this->_copy(other);
	}

	return *this;
}
StickerSheet::~StickerSheet()
{
	 delete pic_;
        delete[] arr_;
        delete[] x_;
        delete[] y_;

}
void StickerSheet::changeMaxStickers(unsigned max)
{
//CHANGE TO UNSIGNED YOU HOE
	Image** newArray = new Image*[max];
	unsigned* newX = new unsigned[max];
	unsigned* newY = new unsigned[max];
	if (max < this->max_)
	{
		/*for(unsigned i = max; i < this->max_; i++)
		{
			this->arr_[i] = NULL;
			newX[i] = 0;
			newY[i] = 0;
		}*/
		for (unsigned i = 0; i < max; i++)
		{
			newArray[i] = this->arr_[i];
			newX[i] = this->x_[i];
			newY[i] = this->y_[i];
		}
	}
	else
	{
		for (unsigned i = 0; i < this->max_; i++)
		{
			newArray[i] = this-> arr_[i];
			newX[i] = this->x_[i];
			newY[i] = this->y_[i];

		}
		for (unsigned i = this->max_; i < max; i++)
		{
			newArray[i] = NULL;
			newX[i] = 0;
			newY[i] = 0;		
		}
	}
	this->max_ = max;
	delete[] this->x_;
	delete[] this->y_;
	delete[] this->arr_;
	this->arr_ = newArray;
	this->x_ = newX;
	this->y_ = newY;
}
int StickerSheet::addSticker(Image &sticker, unsigned x, unsigned y)
{
	for (unsigned i = 0; i < this->max_; i++)
	{
		if (arr_[i] == NULL)
		{
			arr_[i] = &sticker;
			x_[i] = x;
			y_[i] = y;
			return i;
		}

	}
	return -1;
	/*if (this-> size_ == this-> max_)
	{
		return -1;
	}
	else
	{
		this->arr_[this->size_] = &sticker;
		this->x_[this->size_] = x;
		this->y_[this->size_] = y;
		size_++;
		return (this->size_ - 1);
	}*/

}
bool StickerSheet::translate (unsigned index, unsigned x, unsigned y)
{
	/*if (index >= this->size_ - 1)
	{
		return false;
	}
	else
	{
		this->x_[index] = x;
		this->y_[index] = y;
		return true;
	}*/
	if (index >= max_)
	{
		return false;
	}
	else
	{
		if (arr_[index] == NULL)
		{
			return false;
		}
		else
		{
			x_[index] = x;
			y_[index] = y;
			return true;
		}
	}
}

void StickerSheet::removeSticker(unsigned index)
{
	if (index < this->max_)
	{
		/*delete this->arr_[index];
		for (unsigned i = index; i < this->size_ - 1; i++)
		{
			this->arr_[index] = this->arr_[index+1];
			this->x_[index] = this->x_[index+1];
			this->y_[index] = this->y_[index+1];
		fd	this->size_--;
		}*/


		this->arr_[index] = NULL;
	}

}
Image* StickerSheet::getSticker(unsigned index) const
{
	if (index >= this->max_)
	{
		return NULL;
	}
	else
	{
		return this->arr_[index];
	}



}
Image StickerSheet::render() const
{
	Image* rendered =  pic_;
	for (unsigned i = 0; i < max_; i++)
	{
		if (arr_[i] != NULL)
		{
			unsigned startX = x_[i];
			unsigned startY = y_[i];
			Image* sticker = arr_[i];
			unsigned maxX = startX + sticker->width();
			unsigned maxY = startY + sticker->height();
			//Resizing
			if(rendered->width() < maxX || rendered->height() < maxY)
			{
				unsigned newW = rendered->width();
				unsigned newH = rendered->height();
				if (rendered->width() < maxX)
				{
					newW = maxX;
				}
				if (rendered->height() < maxY)
				{
					newH = maxY;
				}
				rendered->resize(newW, newH);
			}
			for (unsigned i = startX; i < maxX; i++)
			{
				for (unsigned j = startY; j < maxY; j++)
				{
					HSLAPixel* stickerPix = sticker->getPixel(i-startX, j-startY);
					HSLAPixel* imagePix = rendered -> getPixel(i,j);
					if (stickerPix -> a > 0)
					{
						*imagePix = *stickerPix;
					}
				}
			}

		}
	}

	return *rendered;
}
void StickerSheet:: _copy(const StickerSheet &s)
{
	this->pic_ = new Image(*(s.pic_));
       this->max_ = s.max_;
        this->arr_ = new Image*[this->max_];
	this->x_ = new unsigned[this->max_];
	this->y_ = new unsigned[this->max_];
        for(unsigned i = 0; i < this->max_; i++)
        {
		this-> arr_[i] =  s.arr_[i];
		this->x_[i] = s.x_[i];
		this->y_[i] = s.y_[i];

        }
}
