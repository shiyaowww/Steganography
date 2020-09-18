#ifndef _COLORCLASS_H_
#define _COLORCLASS_H_

#include <fstream>
#include <iostream>

#include "constants.h"

using namespace std;

//Created by: Shiyao Wang
//Date: March 3, 2020
//Class object: Color of a single pixel represented by RGB
//with input and outpuf functionality

class ColorClass
{
  private:
    int redVal;
    int greenVal;
    int blueVal;
    //Member function of ColorClass: Set a single attribute value to even
    void setToEven(
      int &colorVal);
    //Member function of ColorClass: Set a single attribute value to odd
    void setToOdd(
      int &colorVal);
    //Member function of ColorClass: Decode even attribute to null color
    //and odd attribute to full color
    void decodeTo(
      int &colorVal);
    //Member function of ColorClass: Read a single attribute from infile
    //stream and return error as needed
    int readSingleRGB(
      ifstream &inFile, 
      int &colorVal);
    //Member function of ColorClass: Write a single attribute to outfile
    //stream and return error as needed
    int writeSingleRGB(
      ofstream &outFile,
      int &colorVal);

  public:
    //Default ctor of ColorClass: Initialize ColorClass to null color
    ColorClass();
    //Member function of ColorClass: Encode message codes to even or
    //odd numbers of attributes
    void encodePixel(
      int codeVal);
    //Member function of ColorClass: Decode even or odd attributes
    //to null or full colors respectively
    void decodePixel();
    //Member function of ColorClass: Read RGB of the pixel from infile
    //stream and return error as needed
    int readPixel(
      ifstream &inFile);
    //Member function of ColorClass: Write RGB of the pixel to outfile
    //stream and return error as needed
    int writePixel(
      ofstream &outFile);
    //Member function of ColorClass: Print RGB values of color
    void printComponentValues();
};

#endif
