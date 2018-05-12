output: main.o util.o Validate.o Ant.o Board.o Critter.o Doodlebug.o 
	g++ main.o util.o Validate.o Ant.o Board.o Critter.o Doodlebug.o -o output

CXX = g++
CXXFLAGS = -std=c++0x
VARGS = --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes


clean: 
	rm *.o output
	
debug:
	@valgrind $(VARGS) ./output

zip:
	zip Group_4_Project main.cpp util.cpp util.hpp Validate.cpp Validate.hpp Ant.cpp Ant.hpp Board.cpp Board.hpp Critter.cpp Critter.hpp Doodlebug.hpp Doodlebug.cpp Makefile reflection.pdf
