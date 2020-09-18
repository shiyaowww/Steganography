#ifndef _MESSAGECLASS_H_
#define _MESSAGECLASS_H_

#include <fstream>
#include <iostream>
#include <string>

#include "constants.h"

using namespace std;

//Created by: Shiyao Wang
//Date: March 3, 2020
//Class object: Message text code with read-in functionality

class MessageClass
{
  private:
    int numRow;
    int numCol;
    string textFileName;
    int * codeArray2DAs1D;
    //Member function of MessageClass: Read an integer
    //from infile stream and return error as needed
    int readInt(
      ifstream &inFile,
      int &inInt);
    //Member function of MessageClass: Read the size of the text code
    //from infile stream and return error as needed
    int readMessageSize(
      ifstream &inFile);
    //Member function of MessageClass: Read the text code
    //from infile stream and return error as needed
    int readTextCode(
      ifstream &inFile);
      
  public:
    //Default ctor of MessageClass: Construct the message object 
    //with pointer pointing to heap
    MessageClass();
    //dtor of MessageClass：Unclaim the heap space when the object
    //gets out of scope
    ~MessageClass();
    //Member function of MessageClass: Read the message file
    //from infile stream and return error as needed
    int readMessageFile(
      string &textFileName);
    //Member function of MessageClass: Get the attribute: number of rows
    int getNumRow();
    //Member function of MessageClass: Get the attribute: number of columns
    int getNumCol();
    //Member function of MessageCLass: Get element of the code array
    int getElement(
      int rowIndex,
      int colIndex);
};

#endif
