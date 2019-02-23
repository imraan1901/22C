/*
 * Filename: Cholesky.cpp
 * Author: Imraan Iqbal
 * Date: 3/29/19
 * Description: This file has the code for the 
 *               functions in the Cholesky program.
 */

#ifndef Cholesky_cpp
#define Cholesky_cpp

#include "Cholesky.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

// Constructor
Cholesky::Cholesky(void) {

    matrix = new vector<vector<double> >();
}

// Destructor
Cholesky::~Cholesky(void) {

    delete matrix;
}

// This function takes in multiple matrices from a csv
// file and outputs their Cholesky decomposition to an 
// output csv file, Usage in Cholesky.hpp
void Cholesky::inputOutputCSV(const char *in_filename1, const char *in_filename2) {

    // Initialize the file stream
    ifstream inFile(in_filename1);

    ofstream outFile(in_filename2, ofstream::out);

    int matrixSize = 0;
    int nextMatrix = 0;

    // Keep reading lines until the end of file is reached
    while (inFile) {

        string s;
        // Get the next line
        if (!getline(inFile, s)) break;
        
        istringstream ss(s);
        vector<double> row;
       
        while (ss) {
           
            string next;
            // Get the next string before hitting a tab character and put it in 'next'
            if (!getline(ss, next, '\t')) break;
        
            int number = 0;
            int i = 0;

            // Go through the string
            while(i < next.size()) {

                // Store a single digit as a string
                string insert = "";

                // Keep loop running until a ',' or a return
                while(next[i] != ',' && next[i] != '\r') {

                    insert += next[i];
                    i++;
                }

                // This i++ skips the ','
                i++;

                // Convert the string number into an integer and store it
                number = stoi(insert);
                row.push_back(number);
            }
        }
       
        // The row length indicates the column length
        matrixSize = row.size();
        
        nextMatrix++;

        // insert that row into matrix
        matrix->push_back(row);

        // When the rows equal the columns compute the Choleksy
        if(nextMatrix == matrixSize) {
           
            computeCholesky();
            printMatrix(outFile);
            // Indicate the start of a new matrix
            nextMatrix = 0;
            // Remove the previous matrix
            delete matrix;
            // Allocate space for the new matrix
            matrix = new vector<vector<double> >();  
        }
        
        
    }
    
    // Indicate an error in reading in the inFile
    if (!inFile.eof()) {

        cerr << "Failed to read " << in_filename1 << "!\n";
        return;
    }

    // close files
    inFile.close();
    outFile.close();

}

// Write over matrix to save space 
// while computing the decomposition
void Cholesky::computeCholesky(void) {

    int matrixSize = matrix->size();

    for(int i = 0; i < matrixSize; i++) {

        for(int k = 0; k < i; k++) {

            (*matrix)[i][i] -= ( (*matrix)[k][i] * (*matrix)[k][i] );
        }
       
        // if matrix is not positive definite insert
        // -1 as the upper left element and return
        if((*matrix)[i][i] <= 0) {

            (*matrix)[0][0] = -1;
            return;
        }
        
        (*matrix)[i][i] = sqrt( (*matrix)[i][i] );
        
        for(int j = i+1; j < matrixSize; j++) {

            for(int k = 0; k < i; k++) {

               (*matrix)[i][j] -= ( (*matrix)[k][i] * (*matrix)[k][j] );
            }
        
        (*matrix)[i][j] = (*matrix)[i][j] / (*matrix)[i][i];

        }
       
    }


}

//This function prints the matrix that the Cholesky
//function computed to the outFile
void Cholesky::printMatrix(ofstream& outFile) {

    int size = matrix->size();

    // Rows
    for(int i = 0; i < size; i++) {
 
        // Columns
        for(int j = 0 ; j < size; j++) {
            
            // Fill the upper triangular portion of the matrix with values
            if(i <= j) {

                    // Put a comma after each value
                    if(i != size - 1) {
                        outFile << (*matrix)[i][j] << "," ;
                    }

                    // Leave out a comma after the last entry in each row
                    else {
                        outFile << (*matrix)[i][j];
                    }
            }

            // Fill the lower triangular portion of the matrix with 0's 
            else {

                outFile << 0 << ",";
            }

        }
    // Write to the next line in the matrix
    outFile << endl;

    }

}

#endif // Cholesky.cpp
