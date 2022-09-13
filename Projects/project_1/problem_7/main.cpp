// Including the header file
#include "header.hpp"

// Defining the main function
int main() {

  // Defining relevant variables
  int n = 1000;
  double x_min = 0.0;
  double x:max = 1.0;
  double h = (x_max - xmin) / n;

  // Defining relevant containers
  std::vector<double> x(n);
  std::vector<double> b_tilde(n);
  std::vector<double> g_tilde(n);

  // Defining matrix A
  // -> Defining matrix A by containers with the values
  //    of the different diagonals.
  //
  std::vector<int> a_diag(n, -1);
  std::vector<int> b_diag(n, 2);
  std::vector<int> c_diag(n, -1);

  // Initial values
  x[0] = h;
  b_tilde[0] = b_diag[0];
  g_tilde[0] = f(x[0]) * h*h;

  // Forward substitution
  //
  //


  // Backward substitution
  //
  //

  return 0;
}

//
// Defining the functions
//

std::vector<double> f(double x){
  //
  // Calculating a f(x)-value
  // Arguments: x (a single value)

  return 100 * exp( (-10) * x );
}

std::vector<double> calc_b_t(std::vector<int> a, std::vector<int> b, std::vector<int> c, int n){
  //
  // Calculating b-tilde
  // Arguments: a, b, c, n

  //std::vector<double> b_tilde(n);

  // Formulars from problem 6.
  for (int i = 1; i < n; i++) {
    if (i == 1) {
      b_tilde[i] = b[i];
    }
    else {
      b_tilde[i] = b[i] - ( ( a[i] / b_tilde[i-1] ) * c[i-1]);
    }
  }

  return b_tilde;
}

std::vector<double> calc_g() {
  //
  // Calculating g
  // Arguments: x, n, h


  return g;
}

std::vector<double> calc_g_t(std::vector<int> a, std::vector<int> b_t, int n, double h) {
  //
  // Calculating g-tilde
  // Arguments: a, b-tilde, n, h

  //std::vector<double> g_tilde(n);
  //std::double f_1 = 100 * exp( (-10) * h );

  // Formulars from problem 6.
  for (int i = 1; i < n; i++) {
    if (i == 1) {
      g_tilde[i] = (h**2) * f_1;
    }
    else {
      g_tilde[i] = b[i] - ( ( a[i] / b_tilde[i-1] ) * c[i-1]);
    }
  }

  return g_tilde;
}

std::vector<double> calc_v() {
  //
  // Calculating v
  // Arguments:


  return v;
}
