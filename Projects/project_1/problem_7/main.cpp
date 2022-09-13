// Including the header file
#include "header.hpp"

// Defining the main function
int main() {

  return 0;
}

//
// Defining the functions
//

std::vector<double> calc_b_t(std::vector<int> a, std::vector<int> b, std::vector<int> c, int n){
  //
  // Calculating b-tilde
  // Arguments: a, b, c, n
  std::vector<double> b_tilde(n);

  // Formulars from problem 6.
  for (int i = 1; i < n; i++) {
    if (i == 1) {
      b_tilde[i] = b[i];
    }
    else {
      b_tilde[i] = b[i] - ( ( a[i] / b_tilde[i-1] ) * c[i-1]);
    }
  }

  return b_tilde
}

std::vector<double> calc_g() {
  //
  // Calculating g
  // Arguments: x, n, h
  int g = 1

  return g
}


std::vector<double> calc_g_t(std::vector<int> a, std::vector<int> b_t, int n, double h) {
  //
  // Calculating g-tilde
  // Arguments: a, b-tilde, n, h
  std::vector<double> g_tilde(n);
  std::double f_1 = 100 * exp( (-10) * h );

  // Formulars from problem 6.
  for (int i = 1; i < n; i++) {
    if (i == 1) {
      g_tilde[i] = (h**2) * f_1;
    }
    else {
      g_tilde[i] = b[i] - ( ( a[i] / b_tilde[i-1] ) * c[i-1]);
    }
  }

  return g_tilde
}
