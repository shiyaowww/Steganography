#include <fstream>
#include <iostream>

#include "constants.h"

#include "ColorClass.h"

using namespace std;

//Created by: Shiyao Wang
//Date: March 3, 2020
//Class object: Color of a single pixel represented by RGB
//with input and outpuf functionality

ColorClass::ColorClass():
  redVal(NULL_COLOR_VAL),
  greenVal(NULL_COLOR_VAL),
  blueVal(NULL_COLOR_VAL)
{}

void ColorClass::setToEven(
  int &colorVal)
{
  if(colorVal % 2 == 1) //An odd number 
  {
    colorVal--;
  }
}

void ColorClass::setToOdd(
  int &colorVal)
{
  if(colorVal % 2 == 0)//An even number 
  {
    colorVal++; 
  }
}

void ColorClass::decodeTo(
  int &colorVal)
{
  if(colorVal % 2 == 1)//An odd number
  {
    colorVal = FULL_COLOR_VAL;//To full color
  }
  else //An even number
  {
    colorVal = NULL_COLOR_VAL;//To null color
  }
}

void ColorClass::encodePixel(
  int codeVal)
{
  if(codeVal == CODE_BLACK)
  {
    setToEven(redVal);
    setToEven(greenVal);
    setToEven(blueVal);
  }
  else if(codeVal == CODE_RED)
  {
    setToOdd(redVal);
    setToEven(greenVal);
    setToEven(blueVal);
  }
  else if(codeVal == CODE_GREEN)
  {
    setToEven(redVal);
    setToOdd(greenVal);
    setToEven(blueVal);
  }
  else if(codeVal == CODE_BLUE)
  {
    setToEven(redVal);
    setToEven(greenVal);
    setToOdd(blueVal);
  }
  else if(codeVal == CODE_WHITE)
  {
    setToOdd(redVal);
    setToOdd(greenVal);
    setToOdd(blueVal);
  }
  else if(codeVal == CODE_YELLOW)
  {
    setToOdd(redVal);
    setToOdd(greenVal);
    setToEven(blueVal);
  }
  else if(codeVal == CODE_MAGENTA)
  {
    setToOdd(redVal);
    setToEven(greenVal);
    setToOdd(blueVal);
  }
  else if(codeVal == CODE_CYAN)
  {
    setToEven(redVal);
    setToOdd(greenVal);
    setToOdd(blueVal);
  }
}

void ColorClass::decodePixel()
{
  decodeTo(redVal);
  decodeTo(greenVal);
  decodeTo(blueVal);
}

void ColorClass::printComponentValues()
{
  cout << "R: ";
  cout << redVal << " ";
  cout << "G: ";
  cout << greenVal << " ";
  cout << "B: ";
  cout << blueVal;
}

int ColorClass::readSingleRGB(
  ifstream &inFile, 
  int &colorVal)
{
  inFile >> colorVal;

  if(inFile.eof())
  {
    return EOF_BEFORE_EXPECTED;
  }
  else if(inFile.fail())
  {
    return INFILE_STREAM_FAILED;
  }
  else if(colorVal < NULL_COLOR_VAL || colorVal > FULL_COLOR_VAL)
  {
    return INVALID_COLOR_VAL;
  }
  else
  {
    return 0;
  } 
}

int ColorClass::writeSingleRGB(
  ofstream &outFile,
  int &colorVal) 
{
  outFile << colorVal;

  if(outFile.fail())
  {
    return OUTFILE_STREAM_FAILED;
  }
  else
  {
    outFile << ' ';
    return 0;
  }
}

int ColorClass::readPixel(
  ifstream &inFile)
{
  int redReturnVal = 0;
  int greenReturnVal = 0;

  redReturnVal = readSingleRGB(inFile, redVal);
  if(redReturnVal == 0)
  {
    greenReturnVal = readSingleRGB(inFile, greenVal);
    if(greenReturnVal == 0)
    {
      return readSingleRGB(inFile, blueVal);
    }
    else
    {
      return greenReturnVal;
    }
  }
  else
  {
    return redReturnVal;
  }
}

int ColorClass::writePixel(
  ofstream &outFile) 
{
  int redReturnVal = 0;
  int greenReturnVal = 0;
  
  redReturnVal = writeSingleRGB(outFile, redVal);
  if(redReturnVal == 0)
  {
    greenReturnVal = writeSingleRGB(outFile, greenVal);
    if(greenReturnVal == 0)
    {
      return writeSingleRGB(outFile, blueVal);
    }
    else
    {
      return greenReturnVal;
    }
  }
  else
  {
    return redReturnVal;
  }
}
