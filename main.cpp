/*
 * Filename: main.cpp
 * Author: Imraan Iqbal
 * Date: 3/29/19
 * Description: This file runs the Cholesky program.
 */

#include "Cholesky.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {

    Cholesky ch;
    
    ch.inputOutputCSV(argv[1],argv[2]);
  
}