// Code taken from problem 2 and 3 and built upon.

// Including relevant libraries.
# include <iostream>
# include <string>
# include <vector>
# include <armadillo>
# include <cmath>
# include <cstdlib>

//
// Forward declaration of relevant functions.
//

arma::mat tridiagMatGen(int N, double h);
// Generates/sets up a tridiagonal matrix.
// Arguments: N, h

double max_offdiag_symmetric(arma::mat A, int& k, int &l);
// Identifying the largest off-diagonal element of  a matrix
// Arguments: A, k, l
// Assuming A is a square and not a single value matrix.

void jacobi_rotate(arma::mat& A, arma::mat& R, int k, int l);
// Preforms a Jacobi rotation at A(k, l) to rotate away the off-diagonal element.
// Arguments: A, R, k, l

void jacobi_eigensolver(arma::mat& A, double eps, arma::vec& eigenvalues, arma::mat& eigenvectors, const int maxIter, int& iterations, bool& converged);
// Converging the eigenvalues and eigenvectors using the jacobi_rotate-function.
// Arguments: A, R, eps, eigenvalues, eigenvectors, maxIter, iterations, converged
