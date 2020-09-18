#ifndef _IMAGECLASS_H_
#define _IMAGECLASS_H_

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

#include "constants.h"

#include "RowColumnClass.h"
#include "ColorClass.h"
#include "MessageClass.h"

using namespace std;

//Created by: Shiyao Wang
//Date: March 3, 2020
//Class object: A ppm image with message encoding and decoding functionality

class ImageClass
{
  private:
    string imageHeader;
    int numRow;
    int numCol;
    int maxColorVal;
    ColorClass * pixelArray2DAs1D;
    RowColumnClass messagePlacement;
    //Member function of ImageClass: Print a report before exiting the
    //program if errors are encountered while reading from the image file
    void printExit();
    //Member function of ImageClass: Read the header of the ppm image
    //from infile stream and exit the program if error occurs
    int readImageHeader(
      ifstream &inFile);
    //Member function of ImageClass: Read an integer
    //from infile stream and return error as needed
    int readInt(
      ifstream &inFile, 
      int &inInt);
    //Member function of ImageClass: Rutput an integer
    //to outfile stream and return error as needed
    int writeInt(
      ofstream &outFil,
      int &outInt);
    //Member function of ImageClass: Read the size the ppm image
    //from infile stream and exit the program if error occurs
    int readImageSize(
      ifstream &inFile);
    //Member function of ImageClass: Read the max color of the ppm image
    //from infile stream and exit the program if error occurs
    int readMaxColor(
      ifstream &inFile);
    //Member function of ImageClass: Read the pixel array of the ppm image
    //from infile stream and exit the program if error occurs
    int readPixelArray(
      ifstream &inFile);
    //Member function of ImageClass: Read the named ppm image
    //from infile stream and exit the program if error occurs
    int readImageFile(
      string &fileName);
    //Member function of ImageClass: Judge if the attribute encodingLocation
    //is in bound of the 2d pixel array
    bool isInBound(
      RowColumnClass &inLocation);
    //Member function of ImageClass: Initialize the RowColumnClass object
    //messagePlacement from cin and return to the option menu if 
    //error occurs
    int readMessagePlacement();
    //Member function of ImageClass: Read a string from cin as the filename
    //of the message or the output file and return to the option menu if
    //error occurs
    int readString(
      string &outString);
    //Member function of ImageClass: Encode the code array of the message 
    //file to the pixel array of the ppm file
    int encodeArrays(
      string &textFileName);
    //Member function of ImageClass: Output the header of the ppm image
    //to outfile stream and return to the option menu if error occurs
    int writeImageHeader(
      ofstream &outFile);
    //Member function of ImageClass: Output the size the ppm image
    //to outfile stream and return to the option menu if error occurs
    int writeImageSize(
      ofstream &outFile);
    //Member function of ImageClass: Output the max color of the ppm image
    //to outfile stream and return to the option menu if error occurs
    int writeMaxColor(
      ofstream &outFile);
    //Member function of ImageClass: Output the pixel array of the ppm image
    //to outfile stream and return to the option menu if error occurs
    int writePixelArray(
      ofstream &outFile);

  public:
    //Value ctor of ImageClass: Construct the object by calling
    //function: readImageFile
  	ImageClass(
      string &fileName);
    //dtor of ImageClass: Unclaim the heap space when the object
    //gets out of scope
  	~ImageClass();
    //Member function of ImageClass: Encode the named message file to the
    //ppm image and return to the option menu if error occurs
  	int encodeMessage();
    //Member function of ImageClass: Decode the whole image
  	void decodeImage();
    //Member function of ImageClass: Output the whole image by calling
    //output member functions
  	int writeImageFile();
};

#endif
