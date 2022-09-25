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

double max_offdiag_symmetric(const arma::mat A, int& k, int &l);
// Identifying the largest off-diagonal element of  a matrix
// Arguments: A, k, l
// Assuming A is a square and not a single value matrix.
