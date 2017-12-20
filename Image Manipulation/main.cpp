#include "cs225/PNG.h"
#include "Image.h"
#include "StickerSheet.h"
#include <string>
#include <iostream>

using namespace std;
#include "cs225/HSLAPixel.h"
using namespace cs225;





int main() 
{
 /*Image alma;
 *   alma.readFromFile("tests/alma.png");
 *
 *     Image i;
 *       i.readFromFile("tests/i.png");
 *
 *         StickerSheet sheet(alma, 5);
 *           sheet.addSticker(i, 20, 200);
 *
 *             Image expected;
 *               expected.readFromFile("tests/expected.png");
 *                 sheet.render().writeToFile("tester.png");
 *
 *                   REQUIRE( sheet.render() == expected );
 **/
	Image alma;
	alma.readFromFile("tests/alma.png");
	alma.scale(3);
	Image sticker1,sticker2,sticker3,sticker4, sticker5;
	sticker1.readFromFile("skeleton.png");
	StickerSheet sheet1(alma, 5);
	

	unsigned index1 = sheet1.addSticker(sticker1, 1400, 1200-150);
	

	sticker5.readFromFile("pumpkin.png");
	sticker2.readFromFile("wade.png");
	sticker3.readFromFile("top-hat.png");
	sticker4.readFromFile("pumpkin.png");
	sticker2.scale(1.25);
	sticker3.scale(200,200);
	sticker4.scale(300,300);
	sticker5.scale(300, 300);
	

	unsigned index2 = sheet1.addSticker(sticker2, 1200, 50);
	unsigned index3 = sheet1.addSticker(sticker3, 1250, 0);
        unsigned index4 = sheet1.addSticker(sticker4,2400 , 1500); 
	unsigned index5 = sheet1.addSticker(sticker5, 0, 1500);	

	sheet1.render().writeToFile("myImage.png");


  return 0;

}
