# =========================================================================== #
# Makefile for use with OSX, LINUX, and WINDOWS (10)
#
# 'O_FILES' should be an array of object files created from any file with a cpp
# This means that in a program with a driver.cpp and a class.cpp anc class.h
# you would only list driver.o and class.o.
#
# This makefile benefits from the object files being compiled separately from
# the executable. As the files get larger and the project gets more complicated
# the project can take a long time to compile. The idea with compiling each
# header file and associated cpp file as well as the driver.cpp file is that it
# will only re-compile your code if there is actually a change. If not, no
# unnecessary compiling occurs.
#
# EXAMPLE 1) Compiling object files from the individual cpp (and h) files:
# 	driver.o: driver.cpp
#		$(CC) -c driver.cpp
#
# This is necessary should you use this file as an example.
#
# Windows has special needs and the compiler needs to include arguments to
# reflect those needs. Generally, you want to leave it as is.
#
# The 'debug' build includes the '-g' argument which will build everything
# necessary to be able to walkthrough the code debugging it. It is nearly the
# same as the 'build' command, but I left it there for simplicity
#
#============================================================================ #

O_FILES=driver.o mystring.o
CC=g++ -std=c++17
OUT=program
ifeq ($(OS),Windows_NT)
	CC += -static-libgcc -static-libstdc++
	OUT=program.exe
endif

build: $(O_FILES)
	$(CC) -o $(OUT) $(O_FILES)
debug: $(O_FILES)
	$(CC) -g -o $(OUT) $(O_FILES)
driver.o: driver.cpp
	$(CC) -c driver.cpp
polynomial.o: polynomial.cpp polynomial.h
	$(CC) -c polynomial.cpp
clean:
	rm -rf *.o program*
cleaner:
	DEL .\program.exe
