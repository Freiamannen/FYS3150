// Including relevant libraries.
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

// Forward declaration of relevant functions
std::vector<double> calc_b_t();
std::vector<double> calc_g();
std::vector<double> calc_g_t();
std::vector<double> calc_v();

// Defining matrix A
// -> Defining matrix A by containers with the values
//    of the different diagonals.
//
int n = 1000;
double x_min = 0.0;
double x:max = 1.0;
double h = (x_max - xmin) / n;
// std::vector<double> x(n);
// for (int i = 0; i < xSteps; i++) {
//  x[i] = xStartingPoint + i * xStepSize;
// }
std::vector<int> a_diag(n, -1);
std::vector<int> b_diag(n, 2);
std::vector<int> c_diag(n, -1);
