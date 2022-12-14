// Code taken from problem 4 and modified.

// Including the header file.
# include "header.hpp"

// Defining the main function.
int main() {

  // Opening a file where data is being appended.
  std::ofstream outfile;
  outfile.open("N_Iteration_comparison.txt");

  // Defining N
  arma::vec N_matrix = {5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};

  for (int i = 0; i < N_matrix.size(); i++) {

    double n = N_matrix(i) + 1;
    double x_min = 0.0;
    double x_max = 1.0;
    double h = (x_max - x_min) / (n);

    // Dense matrix
    // arma::mat A = arma::mat(N_matrix(i), N_matrix(i)).randn();
    // A = arma::symmatu(A);

    // tridiagonal matrix
    arma::mat A = tridiagMatGen(N_matrix(i), h);

    double epsilon = 1e-5;
    arma::vec eigenvalues(N_matrix(i));
    arma::mat eigenvectors(N_matrix(i), N_matrix(i));
    int maxIter = 100000;
    int iterations = 0;
    bool converged = false;

    jacobi_eigensolver_p5(A, epsilon, maxIter, iterations, converged, outfile);

    std::cout << "N = " << N_matrix(i) << '\n';
    std::cout << "--> Iterations: " << iterations << '\n' << '\n';
  }

  // Closing file
  outfile.close();

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
  tau = ( A(l, l) -  A(k, k) ) / ( 2 * A(k, l) );

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
    if (i != k && i != l){
      // m:
      double a_ik_m = A(i, k);
      double a_il_m = A(i, l);
      // m+1:
      A(i, k) = ( a_ik_m * cosi ) - ( a_il_m * sinu );
      A(k, i) = A(i, k);
      A(i, l) = ( a_il_m * cosi ) + ( a_ik_m * sinu );
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

void jacobi_eigensolver_p5(arma::mat& A, double eps, const int maxIter, int& iterations, bool& converged, std::ofstream& outfile) {
  // Converging the eigenvalues and eigenvectors using the jacobi_rotate-function and writing number of iterations to a file

  // Finding the largest off-diagonal element initially
  int k;
  int l;
  int N = A.n_rows;

  // making the R-matrix
  arma::mat R = arma::mat(N, N, arma::fill::eye);

  // Preforming Jacobi rotations while counting the number of iterations
  // until the tolerance is met.
  double maxVal;
  while(!converged) {
    maxVal = max_offdiag_symmetric(A, k, l);

    jacobi_rotate(A, R, k, l);
    iterations++;

    if (maxVal < eps || maxIter < iterations) {
      converged = true;
    }
  }
  std::cout << "Maxval" << maxVal << '\n';

  // Writing data to file
  outfile // N
          << std::setw(10) << std::scientific << N
          // No. iterations
          << std::setw(10) << std::scientific << iterations
          // end of line
          << std::endl;
}
