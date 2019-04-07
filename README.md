# Cholesky Matrix Decomposition

## Description
This is a program that reads in matrices from a Microsoft CSV file 
and outputs the Cholesky Decomposition of those matrices into a CSV file.
 If a matrix does not fulfill
 the properties of a positive definite matrix a "-1" will be placed in the first
 row and column of the corresponding "decomposed" matrix.
 All matrices are assumed square, n by n, for this algorithm.

The purpose of this decomposition is to compute the equation Ax = b to find x
 in O(n<sup>2</sup>) instead of O(n<sup>3</sup>) time. To put that into perspective this decrease in
 computation time for an input matrix of size 1000 by 1000 would take 12 days 
 instead of 32 years.
 
## Uses
* Linear Least Squares
* Non-Linear Optimization
* Monte Carlo Simulation
* Kalman Filters

## Decomposition Time Complexity
O(n<sup>3</sup>)

## How to use in Linux Terminal
./main inputFile.csv outputFile.csv

## Reference
Fundamentals of Matrix Computations,
Third Edition,
David S. Watkins
