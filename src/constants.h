#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

#include <string>

using namespace std;

//Created by: Shiyao Wang
//Date: March 3, 2020
//Constants: Used in the steganography program that
//encodes text messages into a ppm image file and decodes
//the image as required by the user

const int NUM_MAIN_INPUT = 1;
const int COMMAND_PROMPT = 0;

const int OPTION_ENCODE = 1;
const int OPTION_DECODE = 2;
const int OPTION_WRITE = 3;
const int OPTION_EXIT = 4;

const int DEFAULT_ROW_COL = -99999;

const int NUM_ENTER_ALLOWED = 2;
const int NUM_BYTES_IGNORED = 200;

const int NULL_COLOR_VAL = 0;
const int FULL_COLOR_VAL = 255;

const int DEFAULT_MESSAGE_NUM_ROW = 0;
const int DEFAULT_MESSAGE_NUM_COL = 0;
const string DEFAULT_STRING_VAL = "";

const string PPM_HEADER = "P3";
const int ROW_TO_START = 0;
const int COLUMN_TO_START = 0;
const int MIN_IMAGE_ROW_COL = 1;
const int MAX_IMAGE_ROW_COL = 2000;

const int FILE_NO_ACCESS = 1;
const int EOF_BEFORE_EXPECTED = 2;
const int INFILE_STREAM_FAILED = 3;
const int INVALID_COLOR_VAL = 4;
const int INVALID_MESSAGE_SIZE = 5;
const int CODE_VAL_OUT_OF_BOUND = 6;
const int IMAGE_HEADER_NOT_PPM = 7;
const int INVALID_IMAGE_SIZE = 8;
const int INVALID_MAX_COLOR_VAL = 9;
const int INFILE_EXTRA_LONG = 10;
const int CIN_FAILED = 11;
const int OUTFILE_STREAM_FAILED = 12;

const int CODE_BLACK = 0;
const int CODE_RED = 1;
const int CODE_GREEN = 2;
const int CODE_BLUE = 3;
const int CODE_WHITE = 4;
const int CODE_YELLOW = 5;
const int CODE_MAGENTA = 6;
const int CODE_CYAN = 7;

#endif
