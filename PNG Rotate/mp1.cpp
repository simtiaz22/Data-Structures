#include <string>
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include "mp1.h"
using namespace cs225;

void rotate(std::string inputFile, std::string outputFile) {
PNG image1 = PNG();
image1.readFromFile(inputFile);
PNG image2 = PNG(image1);
for (unsigned x = 0; x < image1.width(); x++){
 for (unsigned y = 0; y < image1.height(); y++){
	int newX = image1.width() - 1 - x;
	int newY = image1.height() - 1 - y;
	HSLAPixel *pixel1 = image1.getPixel(x,y);
	HSLAPixel *pixel2 = image2.getPixel (newX, newY);
	*pixel2 = *pixel1;

}
}
image2.writeToFile(outputFile);
return;
}
