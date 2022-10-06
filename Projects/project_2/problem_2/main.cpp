// Including the header file.
# include "header.hpp"

// Defining the main function.
int main() {

  // Setting up A matrix
  int N = 6;
  double n = N + 1;
  double x_min = 0.0;
  double x_max = 1.0;
  double h = (x_max - x_min) / (n);
  arma::mat A = tridiagMatGen(N, h);

  // Initializing relevant containers
  arma::vec eigenvaluesNum(N);
  arma::mat eigenvectorsNum(N, N);
  arma::vec eigenvaluesAna(N);
  arma::mat eigenvectorsAna(N, N);

  // Solve the matrix equation using eig_sym and analytically
  solveEig(A, N, eigenvaluesNum, eigenvectorsNum);
  computeEig(A, N, h, eigenvaluesAna, eigenvectorsAna);

  // Compare the results
  arma::mat eigenvectorsNumNorm = arma::normalise(eigenvectorsNum);
  arma::mat eigenvectorsAnaNorm = arma::normalise(eigenvectorsAna);

  arma::vec difEigenvalues = abs(eigenvaluesNum - eigenvaluesAna);
  // double compEigenvectors = abs(eigenvectorsNumNorm - eigenvectorsAnaNorm);

  // Output the result
  std::cout << "Comparison result: " << "Vector distance is " << difEigenvalues;
  std::cout << "Eigenvalues Ana: " << '\n' << eigenvaluesAna << '\n';
  std::cout << "Eigenvalues Num: " << '\n' << eigenvaluesNum << '\n';

  return 0;
}

//
// Defining the functions.
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

void solveEig(arma::mat M, int N, arma::vec& eigenvaluesNum, arma::mat& eigenvectorsNum) {
  // Solves A matrix times v vector = gamma times v vector
  // Rewriting the eigenvalues- and eigenvectors containers.

  arma::eig_sym(eigenvaluesNum, eigenvectorsNum, M);
}

void computeEig(arma::mat M, int N, double h, arma::vec& eigenvaluesAna, arma::mat& eigenvectorsAna){
  // Computes A matrix times v vector = gamma times v vector analytically
  // Rewriting the eigenvalues- and eigenvectors containers.

  double a = - (1 / (h*h));
  std::cout << a << '\n';
  double d = 2 / (h*h);
  std::cout << d << '\n';
  double pi = 3.1416;

  for(int i = 0; i <= N-1; i++) {
    eigenvaluesAna(i) = d + (2.0 * a * std::cos( ((i+1.0) * pi) / (N + 1.0) ));
    // Increasing
    for(int j = 0; j <= N-1; j++) {
      eigenvectorsAna(i, j) = std::sin( ((j+1)*(i+1) * pi) / (N + 1) );
    }
  }
}
