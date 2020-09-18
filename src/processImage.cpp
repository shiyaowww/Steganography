#include <fstream>
#include <iostream>
#include <string>

#include "constants.h"

#include "processImage.h"

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
   ImageClass &inImage)
{
  bool validOptionInput = false;
  int userChoice = 0;

  cout << OPTION_ENCODE;
  cout << ". Encode a message from file" << endl;
  cout << OPTION_DECODE; 
  cout << ". Perform decode" << endl;
  cout << OPTION_WRITE;
  cout << ". Write current image to file" << endl;
  cout << OPTION_EXIT;
  cout << ". Exit the program" << endl;

  cout << "Enter your choice: "; 

  while(!validOptionInput)
  {
    cin >> userChoice;

    if(!cin.fail() 
       && userChoice >= OPTION_ENCODE 
       && userChoice <= OPTION_EXIT)
    {
      validOptionInput = true;
    }
    else
    {
      cin.clear();
      cin.ignore(NUM_BYTES_IGNORED,'\n');
      cout << "Invalid input, please re-enter:" << endl;
    } 
  }

  if(userChoice == OPTION_ENCODE)
  {
    inImage.encodeMessage();
    processImage(inImage);
    return 0;
  }
  else if(userChoice == OPTION_DECODE)
  {
    inImage.decodeImage();
    processImage(inImage);
    return 0;
  }
  else if(userChoice == OPTION_WRITE)
  {
    inImage.writeImageFile();
    processImage(inImage);
    return 0;
  }
  else
  {
    cout << "Thanks for using this program!" << endl;
    return 0;
  }
}
