// Including the header file
#include "header.hpp"

// Defining the main function
int main() {

  // Defining relevant variables
  std::int n = 1000;
  std::double x_min = 0.0;
  std::double x_max = 1.0;
  std::double v_min = 0.0;
  std::double v_max = 0.0;
  std::double h = (x_max - xmin) / n;

  // Defining relevant containers
  std::vector<double> x(n);
  //std::vector<double> b_tilde(n);
  std::vector<double> g(n);
  //std::vector<double> g_tilde(n);

  // Defining matrix A
  // -> Defining matrix A by containers with the values
  //    of the different diagonals.
  //
  std::vector<int> a_diag(n, -1);
  std::vector<int> b_diag(n, 2);
  std::vector<int> c_diag(n, -1);

  // Initial values
  x[0] = h;
  std::double h_sq = h * h;
  //b_tilde[0] = b_diag[0];
  //g_tilde[0] = f(x[0]) * h_sq;

  // Calculate x and g
  for (int i = 1; i < n; i++) {
    x[i] = x[i-1] + h;
  }

  for (int i = 0; i < n; i++) {
    g[i] = f( x[i] ) * h_sq;
  }

  // Forward substitution
  //
  std::vector<double> b_t = calc_b_t(a_diag, b_diag, c_diag, n);

  std::vector<double> g_t = calc_g_t(a_diag, b_t, n, h);
  //

  // Backward substitution
  //
  std::vector<double> v = calc_v(g_t, b_t, n);
  //

  // Write the results in a file.
  void writeToFile("problem7Data.txt", v, x, n, x_min, x_max, )

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

  return b_tilde;
}

std::vector<double> calc_g_t(std::vector<int> a, std::vector<int> b_t, int n, double h) {
  //
  // Calculating g-tilde
  // Arguments: a, b-tilde, n, h

  std::vector<double> g_tilde(n);

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

std::vector<double> calc_v(std::vector<double> g_tilde, std::vector<double> b_tilde, int n) {
  //
  // Calculating v
  // Arguments: g_tilde, b_tilde, n

  std::vector<double> v(n);

  // Formulars from problem 6.
  for (int i = n-1; i >= 0; i--) {
    if (i == n-1) {
      v[i] = g_tilde[n-1] / b_tilde[n-1];
    }
    else {
      v[i] = ( g_tilde[i] - ( c * v[i+1] ) ) / b_tilde[i];
    }
  }

  return v;
}

void writeToFile(std::string fileName, std::vector<double> v_vec, std::vector<double> x_vec, int n){
  // Adding the boundary points and writing v* and x*
  // (containers with the boundary points) in twp
  // different columns to a specified file name

  // Produce the marked vectors
  std::vector<double> v_mark(n+2);
  std::vector<double> x_mark(n+2);

  v_mark[0] = v_mn;
  x_mark[0] = x_mn;

  for (int i = 1; i < n - 1; i++) {
    v_mark[i] = v_vec[i];
    x_mark[i] = x_vec[i];
  }

  v_mark[n+2] = v_mx;
  x_mark[n+2] = x_mx;

  // Creating and opening a file
  std::ofstream ofile;
  ofile.open(fileName);

  // Formating
  int width = 12;
  int prec = 4;

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
