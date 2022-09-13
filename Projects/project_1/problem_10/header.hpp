// Code taken from problem 7 and modified

// Including relevant libraries.
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cmath>

#include <chrono>

// Forward declaration of relevant functions
  // Arguments:
  // x (double)
double f(double x);

  // a, b, c, n
std::vector<double> calc_b_t(std::vector<int> a, std::vector<int> b, std::vector<int> c, int n);

  // a, g, b_tilde, c, n, h, f_1
std::vector<double> calc_g_t(std::vector<int> a, std::vector<double> g, std::vector<double> b_tilde, std::vector<int> c, int n, double h, double f_1);

  // g_tilde, b_tilde, n
std::vector<double> calc_v(std::vector<double> g_tilde, std::vector<double> b_tilde, std::vector<int> c, int n);

  // fileName, v_vec, x_vec, n, x_mn, x_mx
void writeToFile(std::string fileName,
                std::vector<double> v_vec,
                std::vector<double> x_vec,
                int n,
                double x_mn,
                double x_mx,
                double v_mn,
                double v_mx);
