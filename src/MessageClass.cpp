#include <fstream>
#include <iostream>
#include <string>

#include "constants.h"

#include "MessageClass.h"

using namespace std;

//Created by: Shiyao Wang
//Date: March 3, 2020
//Class object: Message text code with read-in functionality

MessageClass::MessageClass():
  numRow(DEFAULT_MESSAGE_NUM_ROW),
  numCol(DEFAULT_MESSAGE_NUM_COL),
  textFileName(DEFAULT_STRING_VAL)
{
  codeArray2DAs1D = new int;
}

MessageClass::~MessageClass()
{
  delete [] codeArray2DAs1D;
}

int MessageClass::getNumRow()
{
  return numRow;
}

int MessageClass::getNumCol()
{
  return numCol;
}

int MessageClass::getElement(
  int rowIndex,
  int colIndex)
{
  int oneDIndex = rowIndex * numCol + colIndex;

  return codeArray2DAs1D[oneDIndex];
}

int MessageClass::readInt(
  ifstream &inFile,
  int &inInt)
{
  inFile >> inInt;

  if(inFile.eof())
  {
    return EOF_BEFORE_EXPECTED;
  }
  else if(inFile.fail())
  {
    return INFILE_STREAM_FAILED;
  }
  else 
  {
    return 0;
  }
}

int MessageClass::readMessageSize(
  ifstream &inFile)
{
  int numColReturnVal = 0;
  int numRowReturnVal = 0;

  numColReturnVal = readInt(inFile, numCol);
  if(numColReturnVal == 0)
  {
    if(numCol > 0)
    {
      numRowReturnVal = readInt(inFile, numRow);
      if(numRowReturnVal == 0)
      {
        if(numRow > 0)
        {
          return 0;
        }
        else
        {
          cout << "Error: Reading message value at message size" << endl;
          cout << "Error: Invalid number of row";
          cout << endl;
          return INVALID_MESSAGE_SIZE;
        }
      }
      else
      {
        cout << "Error: Reading message value at message size" << endl;
        cout << "Error: Failed to read number of row" << endl;
        return numRowReturnVal;
      }
    }  
    else
    {
      cout << "Error: Reading message value at message size" << endl;
      cout << "Error: Invalid number of column";
      cout << endl;
      return INVALID_MESSAGE_SIZE;
    }  
  }
  else
  {
    cout << "Error: Reading message value at message size" << endl;
    cout << "Error: Failed to read number of column" << endl;
    return numColReturnVal;
  }
}

int MessageClass::readTextCode(
  ifstream &inFile)
{
  int i = 0;
  int j = 0;
  int oneDIndex = 0;
  int textCodeReturnVal = 0;

  codeArray2DAs1D = new int[numCol * numRow];
  for(i = 0; i < numRow; i++)
  {
    for(j = 0; j < numCol; j++)
    {
      oneDIndex = i * numCol + j;

      textCodeReturnVal = readInt(inFile, codeArray2DAs1D[oneDIndex]);
      if(textCodeReturnVal == 0)
      {
        if(codeArray2DAs1D[oneDIndex] > CODE_CYAN
          || codeArray2DAs1D[oneDIndex] < CODE_BLACK)
        {
          cout << "Error: Reading message value at row/col: ";
          cout << i << " " << j << endl;
          cout << "Error: Invalid code value read from the message file"; 
          cout << endl;
          return CODE_VAL_OUT_OF_BOUND;
        }
      }
      else
      {
        cout << "Error: Reading message value at row/col: ";
        cout << i << " " << j << endl;
        cout << "Error: Failed to read text code" << endl;
        return textCodeReturnVal;
      }
    }
  }

  return 0;
}

int MessageClass::readMessageFile(
  string &textFileName)
{
  int sizeReturnVal = 0;
  int textReturnVal = 0;
  int endMarker = 0;

  ifstream inFile;
  inFile.open(textFileName.c_str());

  if(inFile.fail())
  {
    cout << "Error: Failed to open the message file: ";
    cout << textFileName << endl;
    cout << "Error: No access to the file or the file does not exist"; 
    cout << endl;

    return FILE_NO_ACCESS;
  }
  else
  {
    sizeReturnVal = readMessageSize(inFile);
    if(sizeReturnVal == 0)
    {
      textReturnVal = readTextCode(inFile);
      if(textReturnVal == 0)
      {
        inFile >> endMarker;
        if(inFile.eof())
        {
          inFile.close();
          return 0;
        }
        else
        {
          inFile.close();
          cout << "Error: Reading message file longer than expected"; 
          cout << endl;
          return INFILE_EXTRA_LONG;
        }        
      }
      else
      {
        inFile.close();
        return textReturnVal;
      }
    }
    else
    {
      inFile.close();
      return sizeReturnVal;
    }
  }
}

