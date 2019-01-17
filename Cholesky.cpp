#ifndef Cholesky_cpp
#define Cholesky_cpp

#include "Cholesky.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

Cholesky::Cholesky(void) {

    matrix = new vector<vector<double> >();
}

Cholesky::~Cholesky(void) {

    delete matrix;
}

// This function takes in multiple matrices from a csv
// file and outputs their Cholesky decomposition to an 
// output csv file, Usage in Cholesky.hpp
void Cholesky::inputOutputCSV(const char *in_filename1, const char *in_filename2) {

    // Initialize the file stream
    ifstream infile(in_filename1);

    ofstream outFile(in_filename2, ofstream::out);

    int matrixSize = 0;
    int nextMatrix = 0;

	// keep reading lines until the end of file is reached
	while (infile) {

		string s;
		// get the next line
		if (!getline(infile, s)) break;
		
		istringstream ss(s);
		vector<double> row;
       
		while (ss) {
           
			string next;
			// get the next string before hitting a tab character and put it in 'next'
			if (!getline(ss, next, '\t')) break;
        
            int number = 0;
            int i = 0;

            while(i < next.size()) {

                string insert = "";

                while(next[i] != ',' && next[i] != '\r') {

                    insert += next[i];
                    i++;
                }

                i++;
                int number = stoi(insert);
                row.push_back(number);
            }
		}
       
        matrixSize = row.size();
        
        nextMatrix++;

        // insert that row into matrix
        matrix->push_back(row);

        if(nextMatrix == matrixSize) {
           
            computeCholesky();
            printMatrix(outFile);
            nextMatrix = 0;
            delete matrix;
            matrix = new vector<vector<double> >();  
        }
        
        
    }

    if (!infile.eof()) {

		cerr << "Failed to read " << in_filename1 << "!\n";
        return;
	}

    // close files
    infile.close();
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
//Function computed to the outFile
void Cholesky::printMatrix(ofstream& outFile) {

    int size = matrix->size();

    for(int j = 0; j < size; j++) {

        for(int i = 0 ; i < size; i++) {
            
            if(j <= i) {

                    if(i != size - 1) {
                        outFile << (*matrix)[j][i] << "," ;
                    }
                    else {
                        outFile << (*matrix)[j][i] ;
                    }
            }

            else {

                outFile << 0 << ",";
            }

        }
    
    outFile << endl;

    }

}

#endif // Cholesky.cpp