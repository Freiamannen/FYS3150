#
# Plotting script
#

# Importing relevant libraries
import numpy as np
import matplotlib.pyplot as plt

# Getting the data
# The data files are arranged:
# Col1: N,  Col2: Iterations
data = np.loadtxt("N_Iteration_comparison.txt")

# Store the data
N = data[:, 0]
Iterations = data[:, 1]

# Plotting the data
plt.scatter(np.log(N), np.log(Iterations))
plt.title("Log-plot of problem 5")
plt.xlabel("Logarithm of N")
plt.ylabel("Logarithm of Iterations")
plt.savefig("problem5Plot.pdf")
plt.savefig("problem5Plot.jpg")
