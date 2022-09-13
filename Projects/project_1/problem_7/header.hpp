// Including relevant libraries.
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

// Forward declaration of relevant functions
  // Arguments:
  // x (double)
std::vector<double> f(double x);

  // a, b, c, n
std::vector<double> calc_b_t(std::vector<int> a, std::vector<int> b, std::vector<int> c, int n);

  // a, b_tilde, n, h
std::vector<double> calc_g_t(std::vector<int> a, std::vector<int> b_t, int n, double h);

  // g_tilde, b_tilde, n
std::vector<double> calc_v(std::vector<double> g_tilde, std::vector<double> b_tilde, int n);

  // fileName, v_vec, x_vec, n, x_mn, x_mx
void writeToFile(std::string fileName,
                std::vector<double> v_vec,
                std::vector<double> x_vec,
                int n,
                std::double x_mn,
                std::double x_mx,
                std::double v_mn,
                std::double v_mx);
