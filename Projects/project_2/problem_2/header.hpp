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

std::vector<arma::vec> solveEigVal(arma::mat M, int N);
// Solves A matrix times v vector = gamma times v vector
// Returning the eigenvalues.
// Arguments: M, N

std::vector<arma::vec> solveEigVec(arma::mat M, int N);
// Solves A matrix times v vector = gamma times v vector
// Returning the eigenvectors.
// Arguments: M, N

arma::vec solveEigValAna(int N, double h);
// Solves A matrix times v vector = gamma times v vector analytically.
// Returning the eigenvalues
// Arguments: N, h

arma::mat solveEigVecAna(int N, double h);
// Solves A matrix times v vector = gamma times v vector analytically.
// Returning the eigenvectors
// Arguments: N, h

//bool numAnaComp(std::vector<arma::vec> Num, std::vector<arma::vec> Ana);
// Checks if the numerical solution is the same as the analytical one
// Arguments: Num, Ana
