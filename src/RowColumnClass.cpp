#include <iostream>

#include "constants.h"

#include "RowColumnClass.h"

using namespace std;

//Created by: Shiyao Wang
//Date: March 3, 2020
//Class object: Row and column index of certain pixel in an image
//with functionality on the indices

RowColumnClass::RowColumnClass():
  rowIndex(DEFAULT_ROW_COL),
  colIndex(DEFAULT_ROW_COL)
{}

RowColumnClass::RowColumnClass(
  int inRowIndex,
  int inColIndex):
  rowIndex(inRowIndex),
  colIndex(inColIndex)
{}

int RowColumnClass::readRowCol()
{
  bool validInput = false;
  int numEnter = 0;
    
  while(!validInput && numEnter < NUM_ENTER_ALLOWED)
  {
    numEnter++;
    cin >> rowIndex;
    cin >> colIndex;
    if(!cin.fail())
    {
      validInput = true;
    } 
    else if(cin.fail() && numEnter < NUM_ENTER_ALLOWED)
    //cin fail, but still the first try
    {
      cin.clear();
      cin.ignore(NUM_BYTES_IGNORED, '\n');
      cout << "cin fail state, please re-enter row and column index:";
      cout << endl;
    }
    else
    //cin fail, and already the second chance
    {
      cin.clear();
      cin.ignore(NUM_BYTES_IGNORED, '\n');
      return CIN_FAILED;
    }
  }
    
  return 0;
}

void RowColumnClass::setRowCol(
  RowColumnClass &inRowCol)
{
  rowIndex = inRowCol.getRow();
  colIndex = inRowCol.getCol();
}

void RowColumnClass::setCol(
  RowColumnClass &inRowCol)
{
  colIndex = inRowCol.getCol();
}

int RowColumnClass::getRow()
{
  return rowIndex;
}

int RowColumnClass::getCol()
{
  return colIndex;
}

void RowColumnClass::incrementRow()
{
  rowIndex++;
}

void RowColumnClass::incrementCol()
{
  colIndex++;
}

bool RowColumnClass::isInRange(
  RowColumnClass &topLeft,
  RowColumnClass &bottomRight)
{
  if(
      (
        (
          rowIndex <= bottomRight.getRow() 
          && rowIndex >= topLeft.getRow()
        )
        ||
        (
          rowIndex >= bottomRight.getRow() 
          && rowIndex <= topLeft.getRow()
        )
      )
      &&
      (
        (
          colIndex <= bottomRight.getCol() 
          && colIndex >= topLeft.getCol()
        )
        ||
        (
          colIndex >= bottomRight.getCol() 
          && colIndex <= topLeft.getCol()
        )
      )
    )
  {
    return true;
  }
  else
  {
    return false;
  }
}

void RowColumnClass::printRowCol()
{
  cout << getRow() << "," << getCol() << endl;
}

