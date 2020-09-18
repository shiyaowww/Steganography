all: proj3.exe

main.o: main.cpp RowColumnClass.o ColorClass.o MessageClass.o ImageClass.o processImage.o constants.h
	g++ -std=c++98 -Wall -c main.cpp -o main.o

RowColumnClass.o: RowColumnClass.cpp RowColumnClass.h constants.h
	g++ -std=c++98 -Wall -c RowColumnClass.cpp -o RowColumnClass.o

ColorClass.o: ColorClass.cpp ColorClass.h constants.h
	g++ -std=c++98 -Wall -c ColorClass.cpp -o ColorClass.o

MessageClass.o: MessageClass.cpp MessageClass.h constants.h
	g++ -std=c++98 -Wall -c MessageClass.cpp -o MessageClass.o

ImageClass.o: ImageClass.cpp ImageClass.h RowColumnClass.h ColorClass.h MessageClass.h constants.h
	g++ -std=c++98 -Wall -c ImageClass.cpp -o ImageClass.o

processImage.o: processImage.cpp processImage.h RowColumnClass.h ColorClass.h MessageClass.h ImageClass.h constants.h
	g++ -std=c++98 -Wall -c processImage.cpp -o processImage.o

proj3.exe: main.o RowColumnClass.o ColorClass.o MessageClass.o ImageClass.o processImage.o constants.h
	g++ main.o RowColumnClass.o ColorClass.o MessageClass.o ImageClass.o processImage.o -o proj3.exe

clean:
	rm -f *.o *.exe
