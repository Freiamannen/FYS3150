// Including relevant libraries.
#include <iostream>
#include <string>
#include <vector>

// Forward declaration of relevant functions
std::vector<double> calc_b();
std::vector<double> calc_g();
std::vector<double> calc_v();

// Defining matrix A
// -> Defining matrix A by containers with the values
//    of the different diagonals.
//
int n = 1000;
std::vector<int> a_diag(n, -1);
std::vector<int> b_diag(n, 2);
std::vector<int> c_diag(n, -1);
