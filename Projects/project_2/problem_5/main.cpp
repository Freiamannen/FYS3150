// Code taken from problem 4 and modified.

// Including the header file.
# include "header.hpp"

// Defining the main function.
int main() {

  std::vector N = {10, 100, 1000, 10000};

  for (int i = 0; i < N.size() - 1; i++); {

    double n = N(i) + 1;    // Problem with compiling in this file. error: i is not defined
    double x_min = 0.0;
    double x_max = 1.0;
    double h = (x_max - x_min) / (n);
    arma::mat A = tridiagMatGen(N(i), h);

    //arma::mat A(N, N, arma::fill::randu);

    double epsilon = 1e-8;
    arma::vec eigenvalues(N(i));
    arma::mat eigenvectors(N(i), N(i));
    int maxIter = 100000;
    int iterations;
    bool converged = false;


    jacobi_eigensolver(A, epsilon, eigenvalues, eigenvectors, maxIter, iterations, converged);

    std::cout << "N = " << N(i) << '\n';
    std::cout << "--> Iterations: " << iterations << '\n' << '\n';


    //std::cout << "Eigenvalues: " << '\n';
    //eigenvalues.print(std::cout);
    //std::cout << "Eigenvectors: " << '\n';
    //eigenvectors.print(std::cout);

    //std::cout << "R matrix (I): " << '\n';
    //R.print();
    //std::cout << '\n';

  }


  return 0;
}

//
// Defining the functions
//

arma::mat tridiagMatGen(int N, double h) {
  // Generates/sets up the tridiagonal matrix.

  double a = - (1 / (h*h));
  double d = 2 / (h*h);

  arma::mat A = arma::mat(N, N);
  A.diag(1).fill(a);
  A.diag(0).fill(d);
  A.diag(-1).fill(a);

  return A;
}

double max_offdiag_symmetric(const arma::mat A, int& k, int &l) {
  // Identifying the largest off-diagonal element of A matrix
  // Assuming A is a square, symmetric and not a single value matrix.

  // Get size of the matrix A
  int rows = A.n_rows;

  // Initialize a double variable maxval to A(k,l)
  k = 1;
  l = 0;
  double maxval = A(k, l);

  // searching through the "upper side" of the matrix, and possibly change the k- and l-values
  for (int i = 1; i <= rows - 1; i++) {
    //std::cout << "~~" << '\n';
    for (int j = 0; j <= i - 1; j++) {
      //std::cout << "Checking k = " << i << ", l = " << j;
      //std::cout << " ~~ This makes |A(k, l)| = " << std::abs(A(i, j)) << '\n';
      if (std::abs(A(i, j)) > maxval) {
        maxval = std::abs(A(i, j));
        k = i;
        l = j;
      }
    }
  }

  return maxval;
}

void jacobi_rotate(arma::mat& A, arma::mat& R, int k, int l) {
  // Preforms a Jacobi rotation at A(k, l) to rotate away the off-diagonal element.

  // - Assumes symmetric matrix, so we only consider k < l
  // - Modifies the input matrices A and R

  // Initialize variables
  double tau;
  double tang;
  double cosi;
  double sinu;

  double N = A.n_rows;

  // Define the variables
  tau = ( A(1, 1) -  A(k, k) ) / ( 2 * A(k, l) );

  if (tau > 0) {
    tang = 1.0 / ( tau + std::sqrt(1 + tau*tau) );
  }
  else {
    tang = -1.0 / ( -tau + std::sqrt(1 + tau*tau) );
  }
  cosi = 1.0 / std::sqrt(1 + tang*tang);
  sinu = cosi * tang;

  // Transforming A-matrix
  // m:
  double a_kk_m = A(k, k);
  double a_ll_m = A(l, l);
  double a_kl_m = A(k, l);
  // m+1:
  A(k, k) = ( a_kk_m * cosi*cosi ) - ( 2 * a_kl_m * cosi * sinu ) + ( a_ll_m * sinu*sinu );
  A(l, l) = ( a_ll_m * cosi*cosi ) + ( 2 * a_kl_m * cosi * sinu ) + ( a_kk_m * sinu*sinu );
  A(k, l) = 0.;
  A(l, k) = 0.;
  // Rest of the row and column
  for (int i = 0; i <= N - 1; i++) {
    if (i != k && i != 1){
      // m:
      double a_ik_m = A(i, k);
      double a_il_m = A(i, l);
      // m+1:
      A(i, k) = ( a_ik_m * cosi ) - ( a_il_m * sinu );
      A(k, i) = A(i, k);
      A(i, l) = ( a_il_m * cosi ) - ( a_ik_m * sinu );
      A(l, i) = A(i, l);
    }
  }

  for (int i = 0; i <= N - 1; i++) {
  // Update the rotation matrix R
    // m
    double r_ik_m = R(i, k);
    double r_il_m = R(i, l);
    // m+1
    R(i, k) = ( r_ik_m * cosi ) - ( r_il_m * sinu );
    R(i, l) = ( r_il_m * cosi ) + ( r_ik_m * sinu );
  }
}

void jacobi_eigensolver(arma::mat& A, double eps, arma::vec& eigenvalues, arma::mat eigenvectors, const int maxIter, int& iterations, bool& converged) {
  // Converging the eigenvalues and eigenvectors using the jacobi_rotate-function.

  // Finding the largest off-diagonal element initially
  int k;
  int l;

  // making the R-matrix
  arma::mat R = arma::mat(A.n_rows, A.n_cols, arma::fill::eye);
  std::cout << "Initial R matrix (I): " << '\n';
  R.print();
  std::cout << '\n';

  // Preforming Jacobi rotations while counting the number of iterations
  // until the tolerance is met.
  while(!converged) {
    double maxVal = max_offdiag_symmetric(A, k, l);

    jacobi_rotate(A, R, k, l);
    iterations++;

    if (maxVal < eps || maxIter < iterations) {
      converged = true;
    }
  }

  std::cout << "\n" << "~~" << "\n" << "No. iterations: " << iterations << "\n" << "~~" << "\n";

  // Gathering data
  eigenvalues = A.diag();
  eigenvectors = R;

}
