// Including the header file.
# include "header.hpp"

// Defining the main function.
int main() {

  // Setting up A matrix
  int N = 6;
  double n = N + 1;
  double x_min = 0.0;
  double x_max = 1.0;
  double h = (x_max - x_min) / n;
  arma::mat A = tridiagMatGen(N, h);

  // Solve the matrix equation using eig_sym
  std::vector Numerical = solveEig(A);

  // Solve the matrix equation analytically
  std::vector Analytical = solveEigAnalytical(N, h);

  // Compare the two solutions
  //bool comp = numAnaComp(Numerical, Analytical);


  //
  // DOING IT THE NUM FUNCTIONAL WAY (With the comp-function commented)
  //

  arma::vec numEigVal = Numerical[0];
  arma::vec numEigVec = Numerical[1];
  arma::vec anaEigVal = Analytical[0];
  arma::vec anaEigVec = Analytical[1];

  // Checks if the numerical solution is the same as the analytical one
  if(numEigVal == anaEigVal) {
    if(numEigVec == anaEigVec) {
      std::cout << "The numerical and the analytical solution are the same" << '\n';
    }
  }
  else {
    std::cout << "The numerical and the analytical solution are *not* the same" << '\n';
    std::cout << '\n';
  }

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

std::vector<arma::vec> solveEig(arma::mat M) {
  // Solves A matrix times v vector = gamma times v vector
  // Returning the eigenvalues and the eigenvectors in a container

  arma::vec eigenvalues;
  arma::vec eigenvectors;
  std::vector<arma::vec> returnVal(2);

  arma::eig_sym(eigenvalues, eigenvectors, M);
  returnVal[0] = eigenvalues;
  returnVal[1] = eigenvectors;

  return returnVal;
}

std::vector<arma::vec> solveEigAnalytical(int N, double h){
  // Solves A matrix times v vector = gamma times v vector analytically

  arma::vec eigenvalues(N-1);
  arma::vec eigenvectors(N-1);
  std::vector<arma::vec> returnVal(2);

  double a = - (1 / (h*h));
  double d = 2 / (h*h);
  double pi = 3.1416;

  for(int i = 1; i <= N; i++) {
    eigenvalues[i] = d + (2 * a * cos( (i * pi) / (N + 1) ));
    eigenvectors[i] = sin( (i*i * pi) / (N + 1) );
  }

  returnVal[0] = eigenvalues;
  returnVal[1] = eigenvectors;

  return returnVal;
}


/*
bool numAnaComp(std::vector<arma::vec> Num, std::vector<arma::vec> Ana) {
  // Checks if the numerical solution is the same as the analytical one
  if(Num[0] == Ana[0] && Num[1] == Ana[1]) {
    std::cout << "The numerical and the analytical solution are the same" << '\n';
    return true;
  }
  else {
    std::cout << "The numerical and the analytical solution are *not* the same" << '\n';
    std::cout << '\n';
    return false;
  }
  return false;
}
*/
