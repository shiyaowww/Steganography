#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

#include "constants.h"

#include "RowColumnClass.h"
#include "ColorClass.h"
#include "MessageClass.h"
#include "ImageClass.h"

using namespace std;

//Created by: Shiyao Wang
//Date: March 3, 2020
//Class object: A ppm image with message encoding and decoding functionality

ImageClass::ImageClass(
  string &fileName)
{
  readImageFile(
    fileName);
}

ImageClass::~ImageClass()
{
  delete [] pixelArray2DAs1D;
}

void ImageClass::printExit()
{
  cout << "Image read successful: No" << endl;
  cout << "Error: While reading the image, en error was encountered. ";
  cout << "Exiting the program!" << endl;
}

int ImageClass::readImageHeader(
  ifstream &inFile)
{
  inFile >> imageHeader;

  if(inFile.eof())
  {
    cout << "Error: Reading header from file" << endl;
    cout << "Error: Reached the end of the file while reading image header";
    cout << endl;
    printExit();
    exit(EOF_BEFORE_EXPECTED);
  }
  else if(inFile.fail())
  {
    cout << "Error: Reading header from file" << endl;
    cout << "Error: Failed while reading image header" << endl;
    printExit();
    exit(INFILE_STREAM_FAILED);
  }
  else if(imageHeader != PPM_HEADER)
  {
    cout << "Error: Reading header from file" << endl;
    cout << "Error: Image header not for ppm" << endl;
    printExit();
    exit(IMAGE_HEADER_NOT_PPM);
  }
  else
  {
    return 0;
  }
}

int ImageClass::readInt(
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

int ImageClass::writeInt(
  ofstream &outFile,
  int &outInt)
{
  outFile << outInt;

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

int ImageClass::readImageSize(
  ifstream &inFile)
{
  int numColReturnVal = 0;
  int numRowReturnVal = 0;

  numColReturnVal = readInt(inFile, numCol);
  if(numColReturnVal == 0)
  {
    if(numCol >= MIN_IMAGE_ROW_COL && numCol <= MAX_IMAGE_ROW_COL)
    {
      numRowReturnVal = readInt(inFile, numRow);
      if(numRowReturnVal == 0)
      {
        if(numRow >= MIN_IMAGE_ROW_COL && numRow <= MAX_IMAGE_ROW_COL)
        {
          return 0;
        }
        else
        {
          cout << "Error: Reading image size from file" << endl;
          cout << "Error: Invalid row number" << endl;
          printExit();
          exit(INVALID_IMAGE_SIZE);
        }       
      }
      else
      {
        cout << "Error: Reading image size from file" << endl;
        cout << "Error: Failed to read row number" << endl;
        printExit();
        exit(numRowReturnVal);
      }  
    }
    else
    {
      cout << "Error: Reading image size from file" << endl;
      cout << "Error: Invalid column number" << endl;
      printExit();
      exit(INVALID_IMAGE_SIZE);
    }
  }
  else
  {
    cout << "Error: Reading image size from file" << endl;
    cout << "Error: Failed to read column number" << endl;
    printExit();
    exit(numColReturnVal);
  }
}

int ImageClass::readMaxColor(
  ifstream &inFile)
{
  int maxColorReturnVal = 0;
  
  maxColorReturnVal = readInt(inFile, maxColorVal); 
  if(maxColorReturnVal == 0)
  {
    if(maxColorVal == FULL_COLOR_VAL)
    {
      return 0;
    }
    else
    {
      cout << "Error: Reading maximum color from file" << endl;
      cout << "Error: Invalid maximum color" << endl;
      printExit();
      exit(INVALID_MAX_COLOR_VAL);
    }
  }
  else
  {
    cout << "Error: Reading maximum color from file" << endl;
    cout << "Error: Failed to read maximum color" << endl;
    printExit();
    exit(maxColorReturnVal);
  }
}

int ImageClass::readPixelArray(
  ifstream &inFile)
{
  int i = 0;
  int j = 0;
  int oneDIndex = 0;
  int pixelReturnVal = 0;
  
  pixelArray2DAs1D = new ColorClass[numCol * numRow];
  
  for(i = 0; i < numRow; i++)
  {
    for(j = 0; j < numCol; j++)
    {
      oneDIndex = i * numCol + j;
      pixelReturnVal = pixelArray2DAs1D[oneDIndex].readPixel(inFile);
      if(pixelReturnVal != 0)
      {
        cout << "Error: Reading color from file" << endl;
        cout << "Error: Reading image pixel at row: ";
        cout << i;
        cout << " col: ";
        cout << j;
        cout << endl;

        printExit();
        exit(pixelReturnVal);
      }
    }
  }

  return 0;
}

int ImageClass::readImageFile(
  string &fileName)
{
  int endMarker = 0;
  ifstream inFile;
  
  inFile.open(fileName.c_str());
  if(inFile.fail())
  {
    cout << "Error: Reading entry from file" << endl;
    cout << "Error: Failed to open the file: ";
    cout << fileName << endl;
    cout << "Error: No access to the file or the file does not exist"; 
    cout << endl;
    printExit();
    exit(FILE_NO_ACCESS);
  }
  
  readImageHeader(inFile);
  readImageSize(inFile);
  readMaxColor(inFile);
  readPixelArray(inFile);

  inFile >> endMarker;
  if(inFile.eof())
  {
    inFile.close();
    cout << "Image read successful: Yes" << endl;
      
    return 0;
  }
  else
  {
    cout << "Error: Reading end of the file" << endl;
    cout << "Error: Extra long input from the file" << endl;
    printExit();
    exit(INFILE_EXTRA_LONG);
  } 
}

int ImageClass::readMessagePlacement()
{
  return messagePlacement.readRowCol();
}

bool ImageClass::isInBound(
  RowColumnClass &inLocation)
{
  RowColumnClass topLeft(ROW_TO_START, COLUMN_TO_START);
  RowColumnClass bottomRight(numRow - 1, numCol - 1);
  
  return inLocation.isInRange(topLeft, bottomRight);
}

int ImageClass::readString(
  string &outString)
{
  bool validInput = false;
  int numEnter = 0;
  
  while(!validInput && numEnter < NUM_ENTER_ALLOWED)
  {
    numEnter++;
    cin >> outString;
    if(!cin.fail())
    {
      validInput = true;
    }
    else if(numEnter < NUM_ENTER_ALLOWED)
    {
      cin.clear();
      cin.ignore(NUM_BYTES_IGNORED,'\n');
      cout << "cin fail state, please re-enter: ";
      cout << outString << endl;
    }  
  }

  if(validInput)
  {
    return 0;
  }
  else
  {
    return CIN_FAILED;
  }
}

int ImageClass::encodeArrays(
  string &textFileName)
{
  int i = 0;
  int j = 0;
  int messageReadReturnVal = 0;
  bool partOutOfBound = false;
  int rowRangeMessage = 0;
  int colRangeMessage = 0;
  int rowIndex = 0;
  int colIndex = 0;
  int oneDIndex = 0;
  MessageClass messageText;
  RowColumnClass encodingLocation;

  messageReadReturnVal = messageText.readMessageFile(textFileName);

  if(messageReadReturnVal != 0)
  {
    return messageReadReturnVal;
  }
  else
  {
    rowRangeMessage = messageText.getNumRow();
    colRangeMessage = messageText.getNumCol();

    encodingLocation.setRowCol(messagePlacement);
    
    for(i = 0; i < rowRangeMessage; i++)
    {
      for(j = 0; j < colRangeMessage; j++)
      {
        if(isInBound(encodingLocation))
        {
          rowIndex = encodingLocation.getRow();
          colIndex = encodingLocation.getCol();
          oneDIndex = rowIndex * numCol + colIndex;
          pixelArray2DAs1D[oneDIndex].encodePixel(
            messageText.getElement(i, j));            
        }
        else
        {
          partOutOfBound = true;
        }
        encodingLocation.incrementCol();
      }
      encodingLocation.setCol(messagePlacement);
      encodingLocation.incrementRow();
    }

    if(partOutOfBound)
    {
      cout << "Warning: All or part of the message "; 
      cout << "is out of bound of the image" << endl;
    }
    
    return 0;
  }     
}

int ImageClass::encodeMessage()
{
  int textFileNameReturnVal = 0;
  int messagePlacementReturnVal = 0;
  int encodeArraysReturnVal = 0;
  string textFileName = DEFAULT_STRING_VAL;

  cout << "Enter name of file containing message: ";
  textFileNameReturnVal = readString(textFileName);
  if(textFileNameReturnVal == 0)
  {
    cout << "Enter row and column for message placement: ";
    messagePlacementReturnVal = readMessagePlacement();
    if(messagePlacementReturnVal == 0)
    {
      encodeArraysReturnVal = encodeArrays(textFileName);
      if(encodeArraysReturnVal == 0)
      {
        cout << "Message encode successful: Yes" << endl;
        return 0;
      }
      else
      {
        cout << "Message encode successful: No" << endl;
        return encodeArraysReturnVal;
      }
    }
    else
    {
      cout << "Error: Reading message placement" << endl;
      cout << "Message encode successful: No" << endl;
      return messagePlacementReturnVal;
    }
  }
  else
  {
    cout << "Error: Reading name of the message file" << endl;
    cout << "Message encode successful: No" << endl;
    return textFileNameReturnVal;
  }
}

void ImageClass::decodeImage()
{
  int i = 0;
  int j = 0;
  int oneDIndex = 0;

  for(i = 0; i < numRow; i++)
  {
    for(j = 0; j < numCol; j++)
    {
      oneDIndex = i * numCol + j;
      pixelArray2DAs1D[oneDIndex].decodePixel();
    }
  }

  cout << "Image modified to decoded image contents" << endl;
}

int ImageClass::writeImageHeader(
  ofstream &outFile)
{
  outFile << imageHeader;

  if(outFile.fail())
  {
    cout << "Error: Failed while writing image header" << endl;
    return OUTFILE_STREAM_FAILED;
  }
  else
  {
    outFile << '\n';
    return 0;
  }
  
}

int ImageClass::writeImageSize(
  ofstream &outFile)
{
  int numColReturnVal = 0;
  int numRowReturnVal = 0;

  numColReturnVal = writeInt(outFile, numCol);
  if(numColReturnVal == 0)
  {
    numRowReturnVal = writeInt(outFile, numRow);
    if(numRowReturnVal == 0)
    {
      outFile << '\n';
      return 0;
    }
    else
    {
      cout << "Error: Failed while writing number of row" << endl;
      return OUTFILE_STREAM_FAILED;
    }
  }
  else
  {
    cout << "Error: Failed while writing number of column" << endl;
    return OUTFILE_STREAM_FAILED;
  }
}

int ImageClass::writeMaxColor(
  ofstream &outFile)
{
  int maxReturnVal = 0;

  maxReturnVal = writeInt(outFile, maxColorVal);
  if(maxReturnVal == 0)
  {
    outFile << '\n';
    return 0;
  }
  else
  {
    cout << "Error: Failed while writing maximum color" << endl;
    return maxReturnVal;
  }
}

int ImageClass::writePixelArray(
  ofstream &outFile)
{
  int i = 0;
  int j = 0;
  int oneDIndex = 0;
  int pixelReturnVal = 0;

  for(i = 0; i < numRow; i++)
  {
    for(j = 0; j < numCol; j++)
    {
      oneDIndex = i * numCol + j;
      pixelReturnVal = pixelArray2DAs1D[oneDIndex].writePixel(outFile);
      if(pixelReturnVal != 0)
      {
        cout << "Error: Failed while writing image pixel" << endl;
        cout << "Error: Reading image pixel at row: ";
        cout << i;
        cout << " col: ";
        cout << j;
        cout << endl;
        return OUTFILE_STREAM_FAILED;
      }
    }
  }
    
  return 0;
}

int ImageClass::writeImageFile()
{
  string outFileName;
  int outFileNameReturnVal = 0;
  int headerReturnVal = 0;
  int sizeReturnVal = 0;
  int maxReturnVal = 0;
  int pixelReturnVal = 0;
  ofstream outFile;

  cout << "Enter name of file to write image to: ";

  outFileNameReturnVal = readString(outFileName);
  if(outFileNameReturnVal != 0)
  {
    cout << "Error: Failed while reading name of file to write" << endl;
    cout << "Image write successful: No" << endl;
    return CIN_FAILED;
  }
  else
  {
    outFile.open(outFileName.c_str());
    if(outFile.fail())
    {
      cout << "Error: Failed to open the file: ";
      cout << outFileName << endl;
      return OUTFILE_STREAM_FAILED;
    }
    else
    {
      headerReturnVal = writeImageHeader(outFile);
      if(headerReturnVal == 0)
      {
        sizeReturnVal = writeImageSize(outFile);
        if(sizeReturnVal == 0)
        {
          maxReturnVal = writeMaxColor(outFile);
          if(maxReturnVal == 0)
          {
            pixelReturnVal = writePixelArray(outFile);
            if(pixelReturnVal == 0)
            {
              cout << "Image write successful: Yes" << endl;
              return 0;
            }
            else
            {
              cout << "Image write successful: No" << endl;
              return pixelReturnVal;
            }
          }
          else
          {
            cout << "Image write successful: No" << endl;
            return maxReturnVal;
          }
        }
        else
        {
          cout << "Image write successful: No" << endl;
          return sizeReturnVal;
        }  
      }
      else
      {
        cout << "Image write successful: No" << endl;
        return headerReturnVal;
      }
    } 
  }
}

