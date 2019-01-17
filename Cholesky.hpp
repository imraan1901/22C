#ifndef Cholesky_hpp
#define Cholesky_hpp

#include<vector>
using namespace std;

// Usage ./main inputFile.csv outputFile.csv

// All matrices are assumed square
// with the Cholesky algorithm
class Cholesky{

    public:
    vector<vector<double> > * matrix;

    Cholesky(void);

    ~Cholesky(void);
   
    void inputOutputCSV(const char *in_filename1, const char *in_filename2);

    void computeCholesky(void);

    void printMatrix(ofstream& outFile);
    
};

#endif //Cholesky.hpp