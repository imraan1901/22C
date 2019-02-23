/*
 * Filename: Cholesky.hpp
 * Author: Imraan Iqbal
 * Date: 3/29/19
 * Decsription: This file defines all the functions
 *               to run the Cholesky program.
 */

#ifndef Cholesky_hpp
#define Cholesky_hpp

#include<vector>
using namespace std;

// Usage ./main inputFile.csv outputFile.csv

// All matrices are assumed square
// with the Cholesky Algorithm
class Cholesky{

    public:
    // Constructor
    Cholesky(void);

    // Destructor
    ~Cholesky(void);

    // Opens the files, calls the algorithm, and calls printMatrix
    void inputOutputCSV(const char *in_filename1, const char *in_filename2);

    private:

    // Matrix to store values
    vector<vector<double> > * matrix;
   
    // Runs the algorithm on the matrix
    void computeCholesky(void);

    // Prints the matrix to the outFile.csv
    void printMatrix(ofstream& outFile);
    
};

#endif //Cholesky.hpp