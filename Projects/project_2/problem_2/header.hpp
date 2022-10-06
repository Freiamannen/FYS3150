// Including relevant libraries.
# include <iostream>
# include <string>
# include <vector>
# include <armadillo>

//
// Forward declaration of relevant functions.
//

arma::mat tridiagMatGen(int N, double h);
// Generates/sets up a tridiagonal matrix.
// Arguments: N, h

void solveEig(arma::mat M, int N, arma::vec& eigenvaluesNum, arma::mat& eigenvectorsNum);
// Solves A matrix times v vector = gamma times v vector
// Rewriting the eigenvalues- and eigenvectors containers.
// Arguments: M, N, eigenvaluesNum, eigenvectorsNum

void computeEig(arma::mat M, int N, double h, arma::vec& eigenvaluesAna, arma::mat& eigenvectorsAna);
// Computes A matrix times v vector = gamma times v vector analytically
// Rewriting the eigenvalues- and eigenvectors containers.
// Arguments: M, N, eigenvaluesAna, eigenvectorsAna
