# 
# Filename: Makefile
# Author: Imraan Iqbal
# Date: 3/29/19
# Description: A simple Makefile to build the Cholesky function
#


# COMPILER OPTIONS
#================================================================================
CC=g++ 

CXXFLAGS= -c

# BUILD TARGETS
#==============================================================================
default: Cholesky run

#------------------------------------------------------------------------------

Cholesky: 
	$(CC) $(CXXFLAGS) Cholesky.cpp main.cpp
	

run: Cholesky
	$(CC) -o main main.o Cholesky.o

clean:
	rm -f main main.o Cholesky.o 

