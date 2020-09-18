#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

#include "constants.h"

#include "processImage.h"

#include "RowColumnClass.h"
#include "ColorClass.h"
#include "MessageClass.h"
#include "ImageClass.h"

using namespace std;

//Created by: Shiyao Wang
//Date: March 3, 2020
//Purpose: This program will encode text messages into a ppm image file
//and decode the image as required by the user

int main(
  int argc,
  char * argv[])
{
  string fileName;

  if(argc != NUM_MAIN_INPUT + 1)
  {
    cout << "Error: Invalid number of main input" << endl;
    cout << "Usage: " << argv[COMMAND_PROMPT];
    cout << " <startPPM.ppm>" << endl;
    return 0;
  }
  else
  {
    cout << "Reading initial image from: ";
    cout << argv[NUM_MAIN_INPUT] << endl;
    
    fileName.append(argv[NUM_MAIN_INPUT]);

    ImageClass ppmImage(fileName);

    processImage(ppmImage);

    return 0;
  }
}

