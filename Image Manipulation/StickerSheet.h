
#ifndef STICKERSHEET_H
#define STICKERSHEET_H
#include "cs225/PNG.h"
#include "Image.h"

using namespace std;


namespace cs225{
class StickerSheet{
	public:
	StickerSheet(const Image &picture, unsigned max);
	~StickerSheet();
	StickerSheet(const StickerSheet &other);
	const StickerSheet& operator= (const StickerSheet &other);
	void changeMaxStickers(unsigned max);
	int addSticker (Image &sticker, unsigned x, unsigned y);
	bool translate (unsigned index, unsigned x, unsigned y);
	void removeSticker(unsigned index);
	Image* getSticker(unsigned index) const;
	Image render() const;
	private:
	void _copy(const StickerSheet &s);
	Image* pic_;
	Image** arr_; //Array of Image pointers
	unsigned max_;
	// Array of coords
	unsigned* x_;
	unsigned* y_;
};
}
#endif

