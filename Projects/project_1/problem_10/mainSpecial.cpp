// Code taken directly from problem 9 and modified

// Including the header file
#include "header.hpp"

// Defining the main function
int main() {

  // Start measuring time
  auto t1 = std::chrono::high_resolution_clock::now();

  // Defining relevant variables
  int n = 100;    // Initialized for testing.
  double x_min = 0.0;
  double x_max = 1.0;
  double v_min = 0.0;
  double v_max = 0.0;
  double h = (x_max - x_min) / n;

  // Defining relevant containers
  std::vector<double> x(n);
  std::vector<double> g(n);

  // Defining matrix A
  // -> Defining matrix A by containers with the values
  //    of the different diagonals.
  //
  std::vector<int> a_diag(n, -1);
  std::vector<int> b_diag(n, 2);
  std::vector<int> c_diag(n, -1);

  // Initial values
  x[0] = h;
  double h_sq = h * h;

  // Calculate x and g
  for (int i = 1; i < n; i++) {
    x[i] = x[i-1] + h;
  }

  for (int i = 0; i < n; i++) {
    g[i] = f(x[i]) * h_sq;
  }

  // Forward substitution
  //
  std::vector<double> b_t = calc_b_t(2, n);

  std::vector<double> g_t = calc_g_t(g, b_t, n, h, f(1));
  //

  // Backward substitution
  //
  std::vector<double> v = calc_v(g_t, b_t, c_diag, n);
  //

  // Write the results in files.
  writeToFile("problem10Data.txt", v, x, n, x_min, x_max, v_min, v_max);

  // Stop measuring time
  auto t2 = std::chrono::high_resolution_clock::now();

  // Calculate the elapsed time
  double duration_seconds = std::chrono::duration<double>(t2 - t1).count();

  // Creating and opening a file
  std::ofstream ofile;
  ofile.open("timeCalcSpecial100.txt", std::ios_base::app);

  // Formating
  int width = 15;
  int prec = 7;

  ofile << std::setw(width) << std::setprecision(prec) << std::scientific << duration_seconds << std::endl;

  return 0;
}

//
// Defining the functions
//

double f(double x){
  //
  // Calculating a f(x)-value
  // Arguments: x (a single value)

  return 100 * exp( (-10) * x );
}

std::vector<double> calc_b_t(int b, int n){
  //
  // Calculating b-tilde
  // Arguments: b, n

  std::vector<double> b_tilde(n);

  // Formulars from problem 9.
  for (int i = 1; i < n; i++) {
    if (i == 1) {
      b_tilde[i] = b;
    }
    else {
      b_tilde[i] = b - ( ( 1 / b_tilde[i-1] ) );
    }
  }

  return b_tilde;
}

std::vector<double> calc_g_t(std::vector<double> g, std::vector<double> b_tilde, int n, double h, double f_1) {
  //
  // Calculating g-tilde
  // Arguments: g, b-tilde, n, h, f_1

  std::vector<double> g_tilde(n);
  double h_sqr = h * h;

  // Formulars from problem 9.
  for (int i = 0; i < n; i++) {
    if (i == 1) {
      g_tilde[i] = (h_sqr) * f_1;
    }
    else {
      g_tilde[i] = g[i] + ( ( g_tilde[i-1] / b_tilde[i-1] ) );
    }
  }

  return g_tilde;
}

std::vector<double> calc_v(std::vector<double> g_tilde, std::vector<double> b_tilde, std::vector<int> c, int n) {
  //
  // Calculating v
  // Arguments: g_tilde, b_tilde, c, n

  std::vector<double> v(n);

  // Formulars from problem 6.
  for (int i = n-1; i >= 0; i--) {
    if (i == n-1) {
      v[i] = g_tilde[n-1] / b_tilde[n-1];
    }
    else {
      v[i] = ( g_tilde[i] - ( c[i] * v[i+1] ) ) / b_tilde[i];
    }
  }

  return v;
}

void writeToFile(std::string fileName, std::vector<double> v_vec, std::vector<double> x_vec, int n, double x_mn, double x_mx, double v_mn, double v_mx){
  // Adding the boundary points and writing v* and x*
  // (containers with the boundary points) in twp
  // different columns to a specified file name

  // Produce the marked vectors
  std::vector<double> v_mark(n);
  std::vector<double> x_mark(n);

  v_mark[0] = v_mn;
  x_mark[0] = x_mn;

  for (int i = 1; i < n - 1; i++) {
    v_mark[i] = v_vec[i];
    x_mark[i] = x_vec[i];
  }

  v_mark[n-1] = v_mx;
  x_mark[n-1] = x_mx;

  // Creating and opening a file
  std::ofstream ofile;
  ofile.open(fileName);

  // Formating
  int width = 15;
  int prec = 7;

  // Writing the values
  for (int i = 0; i < n+2; i++){
            // x
    ofile << std::setw(width) << std::setprecision(prec) << std::scientific << v_mark[i]
            // u(x)
          << std::setw(width) << std::setprecision(prec) << std::scientific << x_mark[i]
            // end of line
          << std::endl;
  }

  // Closing file
  ofile.close();

}
