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

std::vector<arma::vec> solveEig(arma::mat M);
// Solves A matrix times v vector = gamma times v vector
// Returning the eigenvalues and the eigenvectors.
// Arguments: M

std::vector<arma::vec> solveEigAnalytical(int N, double h);
// Solves A matrix times v vector = gamma times v vector analytically
// Arguments: N, h

bool numAnaComp(std::vector<arma::vec> Num, std::vector<arma::vec> Ana);
// Checks if the numerical solution is the same as the analytical one
// Arguments: Num, Ana
