#ifndef ROWCOLUMNCLASS_H_
#define ROWCOLUMNCLASS_H_

#include <iostream>

#include "constants.h"

using namespace std;

//Created by: Shiyao Wang
//Date: March 3, 2020
//Class  object: Row and column index of certain pixel in an image
//with functionality on the indices

class RowColumnClass
{
  private:
    int rowIndex;
    int colIndex;
    
  public:
    //Default ctor of RowColumnClass: Initialize the object to -99999
    RowColumnClass(); 
    //Value ctor of RowColumnClass: Initialize Class with parameters
    RowColumnClass(
      int inRowIndex, 
      int inColIndex);
    //Member function of RowColumnClass: Read row and column from cin
    //and return error if the cin fail
    int readRowCol();
    //Member function of RowColumnClass: Set row and column from another
    //RowColumnClass object
    void setRowCol(
      RowColumnClass &inRowCol);
    //Member function of RowColumnClass: Set column from another
    //RowColumnClass object
    void setCol(
      RowColumnClass &inRowCol);
    //Member function of RowColumnClass: Get row index
    int getRow();
    //Member function of RowColumnClass: Get column index
    int getCol();
    //Member function of RowColumnClass: Increment row by 1
    void incrementRow();
    //Member function of RowColumnClass: Increment column by 1
    void incrementCol();
    //Member function of RowColumnClass: Judge if this object 
    //is in between of two RowColumnClass objects
    bool isInRange(
      RowColumnClass &topLeft,
      RowColumnClass &bottomRight);
    //Member function of RowColumnClass: print the object in one bracket
    void printRowCol();
};

#endif
