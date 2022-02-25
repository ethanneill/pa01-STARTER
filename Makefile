# Makefile

all: game

game: main.o cards.o utility.o
	g++ --std=c++11 -Wall -g -o game main.cpp cards.o utility.o 

main.o: main.cpp
	g++ -c -g --std=c++11 -Wall main.cpp

cards.o: cards.cpp
	g++ -c -g --std=c++11 -Wall cards.cpp

utility.o: utility.cpp
	g++ -c -g --std=c++11 -Wall utility.cpp

clean:
	rm -f game *.o
