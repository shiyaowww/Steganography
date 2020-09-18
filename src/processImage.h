#ifndef _PROCESSIMAGE_H_
#define _PROCESSIMAGE_H_

#include <fstream>
#include <iostream>
#include <string>

#include "constants.h"

#include "RowColumnClass.h"
#include "ColorClass.h"
#include "MessageClass.h"
#include "ImageClass.h"

using namespace std;

//Created by: Shiyao Wang
//Date: March 3, 2020
//Global functon: Encode or decode a ppm image
//with an option menu for the user

int processImage(
   ImageClass &inImage);

#endif
