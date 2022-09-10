// Including the header file
#include "header.hpp"

// Defining the main function
int main() {

  // Defining the x-vector
  double xStartingPoint = 0.0;
  double xEndPoint = 1.0;
  int xSteps = 100;
  double xStepSize = (xEndPoint-xStartingPoint) / xSteps;

  std::vector<double> x(xSteps);
  for (int i = 0; i < xSteps; i++) {
    x[i] = xStartingPoint + i * xStepSize;
  }

  // Calculating the u(x)-values
  std::vector<double> u_x_vec = calc_u_x(x);

  // Writing the data to a file
  std::string fileName = "problem1Data.txt";
  writeToFile(fileName, x, u_x_vec);

  // Return value 0 to indicate success
  return 0;
}

//
// Defining the functions
//

std::vector<double> calc_u_x(std::vector<double> x){
  // Calculating u(x) and returning a vector of the values
  int xSteps = x.size();
  std::vector<double> u_x(xSteps);
  for (int i = 0; i < xSteps; i++){
    u_x[i] = 1 - (1-exp(-10)) * x[i] - exp((-10)*x[i]);
  }
  // Returning a double-value vector
  return u_x;
}

void writeToFile(std::string fileName, std::vector<double> x, std::vector<double> u_x){
  // Writing x and u(x) in two different columns to a specified file name

  // Creating and opening a file
  std::ofstream ofile;
  ofile.open(fileName);

  // Formating
  int width = 12;
  int prec = 4;

  // Writing the values
  int xSteps = x.size();
  for (int i = 0; i < xSteps; i++){
            // x
    ofile << std::setw(width) << std::setprecision(prec) << std::scientific << x[i]
            // u(x)
          << std::setw(width) << std::setprecision(prec) << std::scientific << u_x[i]
            // end of line
          << std::endl;
  }

  // Closing file
  ofile.close();

}
