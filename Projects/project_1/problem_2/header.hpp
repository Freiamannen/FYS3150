// Including relevant libraries.
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cmath>

// Forward declaration of relevant functions
std::vector<double> calc_u_x(std::vector<double> x);

void writeToFile(std::string fileName,
                std::vector<double> x,
                std::vector<double> u_x);
