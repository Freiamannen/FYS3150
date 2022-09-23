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

//arma::vec solveEigVal(arma::mat M, int N);
// Solves A matrix times v vector = gamma times v vector
// Returning the eigenvalues.
// Arguments: M, N

//arma::mat solveEigVec(arma::mat M, int N);
// Solves A matrix times v vector = gamma times v vector
// Returning the eigenvectors.
// Arguments: M, N

void solveEigAna(arma::mat M, int N, double h, arma::vec& eigenvaluesAna, arma::mat& eigenvectorsAna);
// Solves A matrix times v vector = gamma times v vector analytically
// Rewriting the eigenvalues- and eigenvectors containers.
// Arguments: M, N, eigenvaluesAna, eigenvectorsAna

//arma::vec solveEigValAna(int N, double h);
// Solves A matrix times v vector = gamma times v vector analytically.
// Returning the eigenvalues
// Arguments: N, h

//arma::mat solveEigVecAna(int N, double h);
// Solves A matrix times v vector = gamma times v vector analytically.
// Returning the eigenvectors
// Arguments: N, h

//bool numAnaComp(std::vector<arma::vec> Num, std::vector<arma::vec> Ana);
// Checks if the numerical solution is the same as the analytical one
// Arguments: Num, Ana
