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
  arma::vec numEigVal = solveEigVal(A, N);    // The core of the problem starts here, apparently (Trying to convert std::vector to arma::vec)
  arma::mat numEigVec = solveEigVec(A, N);

  // Solve the matrix equation analytically
  arma::vec anaEigVal = solveEigValAna(N, h);
  arma::mat anaEigVec = solveEigVecAna(N, h);

  //
  // Doing it the "non-functional" way (With the comp-function commented)
  //

  // Checks if the numerical solution is the same as the analytical one
  //

  /*

  if(numEigVal == anaEigVal) {    // This seems also to generate problems.
    if(numEigVec == anaEigVec) {
      std::cout << "The numerical and the analytical solution are the same" << '\n';
    }
  }
  else {
    std::cout << "The numerical and the analytical solution are *not* the same" << '\n';
    std::cout << '\n';
  }
  */

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

arma::vec solveEigVal(arma::mat M, int N) {
  // Solves A matrix times v vector = gamma times v vector
  // Returning the eigenvalues.

  arma::vec eigenvalues = arma::vec(N);
  arma::mat eigenvectors = arma::vec(N, N);

  arma::eig_sym(eigenvalues, eigenvectors, M);

  return eigenvalues;
}

arma::mat solveEigVec(arma::mat M, int N) {
  // Solves A matrix times v vector = gamma times v vector
  // Returning the eigenvectors.

  arma::vec eigenvalues = arma::vec(N);
  arma::mat eigenvectors = arma::vec(N, N);

  arma::eig_sym(eigenvalues, eigenvectors, M);

  return eigenvectors;
}

arma::vec solveEigValAna(int N, double h){
  // Solves A matrix times v vector = gamma times v vector analytically.
  // Returning the eigenvalues

  arma::vec eigenvalues(N-1);

  double a = - (1 / (h*h));
  double d = 2 / (h*h);
  double pi = 3.1416;

  for(int i = 1; i <= N; i++) {
    eigenvalues[i] = d + (2 * a * cos( (i * pi) / (N + 1) ));
  }

  return eigenvalues;
}

arma::mat solveEigVecAna(int N, double h){
  // Solves A matrix times v vector = gamma times v vector analytically.
  // Returning the eigenvectors

  //
  // DET JEG MÅ GJØRE: Regne ut egenvektorene og legge disse inn i en matrise
  // ELLER: Lage liste, man da må de numeriske også det.
  //

  arma::mat eigenvectors = arma::mat(N, N);

  double a = - (1 / (h*h));
  double d = 2 / (h*h);
  double pi = 3.1416;

  for(int i = 1; i <= N; i++) {
    std::vector<double> eigenvectorI(N); // Lager kolonnen, må nå fylle den inn og legge den til i selve matrisen.
    for(int j = 1; j <= N; j++) {
      eigenvectorI[j] = sin( (j*i * pi) / (N + 1) );
    }
    eigenvectors.col(i) = eigenvectorI;
  }

  return eigenvectors;
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
