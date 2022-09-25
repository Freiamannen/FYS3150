// Including the header file.
# include "header.hpp"

// Defining the main function.
int main() {

  // Initialize k and l
  int k;
  int l;

  // Defining matrix A
  arma::mat A(4, 4, arma::fill::zeros);
  A(0, 0) = 1.0;
  A(1, 1) = 1.0;
  A(2, 2) = 1.0;
  A(3, 3) = 1.0;
  A(0, 3) = 0.5;
  A(1, 2) = -0.7;
  A(2, 1) = -0.7;
  A(3, 0) = 0.5;

  // Print the matrix for reference
  A.print();

  // Finding the maximum value on the off-diagonal and printing it
  double maxOffDiag = max_offdiag_symmetric(A, k, l);
  std::cout << "The maximum value (absolute) on the off diagonal: " << maxOffDiag << '\n' << '\n';

  return 0;
}

//
// Defining the functions
//

double max_offdiag_symmetric(const arma::mat A, int& k, int &l) {
  // Identifying the largest off-diagonal element of A matrix
  // Assuming A is a square, symmetric and not a single value matrix.

  // Get size of the matrix A
  int rows = A.n_rows;

  // Initialize a double variable maxval to A(k,l)
  k = 1;
  l = 0;
  double maxval = A(k, l);

  // Increased structure in the terminal
  std::cout << '\n';

  // searching through the "upper side" of the matrix, and possibly change the k- and l-values
  for (int i = 1; i <= rows - 1; i++) {
    std::cout << "~~" << '\n';
    for (int j = 0; j <= i - 1; j++) {
      std::cout << "Checking k = " << i << ", l = " << j;
      std::cout << " ~~ This makes |A(k, l)| = " << std::abs(A(i, j)) << '\n';
      if (std::abs(A(i, j)) > maxval) {
        maxval = std::abs(A(i, j));
        k = i;
        l = j;
      }
    }
  }

  // Increased structure in the terminal
  std::cout << "~~" << '\n' << "\n";

  return maxval;
}
