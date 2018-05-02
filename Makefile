output: main.o Validate.o Ant.o Board.o Critter.o 
	g++ main.o Validate.o Ant.o Board.o Critter.o -o output

CXX = g++
CXXFLAGS = -std=c++0x


clean: 
	rm *.o output

zip:
	zip Group_Project main.cpp Validate.cpp Validate.hpp Ant.cpp Ant.hpp Board.cpp Board.hpp Critter.cpp Critter.hpp  Makefile

