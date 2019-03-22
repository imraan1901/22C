# Cholesky Matrix Decomposition

## Description
This is a program that reads in matrices from a Microsoft CSV file 
and outputs the Cholesky Decomposition of those matrices into a CSV file.
 If a matrix is not decomposable with this algorithm, it does not fulfill
 the properties of a positive definite matrix, a -1 will be places in the first
 row and column of the corresponding "decomposed" matrix.
 All matrices are assumed square for this algorithm.
 
## Uses
* Linear Least Squares
* Non-Linear Optimization
* Monte Carlo Simulation
* Kalman Filters

## Time Complexity
O(n^3)

## How to use
./main inputFile.csv outputFile.csv

## Reference
Fundamentals of Matrix Computations,
Third Edition,
David S. Watkins
