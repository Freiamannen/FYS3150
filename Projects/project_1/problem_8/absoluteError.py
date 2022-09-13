#
# Plotting script for absolute error
#

# Importing relevant libraries
import numpy as np
import matplotlib.pyplot as plt

# Getting the data from data files
data_u = np.loadtxt("problem1Data.txt")
data_v = np.loadtxt("problem7Data.txt")

# Store the data in arrays
x = data_u[:, 0]
u = data_u[:, 1]

v = data_v[:, 0]

# Exclude the boundary values
x = x[1: -1]
v = v[1: -1]
u = u[1: -1]

# Calculating the error
abs_err = np.zeros(len(u))
for i in range(len(u)):
    abs_err[i] = np.log(np.abs(u[i] - v[i]))

# Plotting the results
plt.plot(x, abs_err)
plt.title("Absolute error")
plt.xlabel("x")
plt.ylabel("\Delta")
plt.savefig("absError.pdf")
plt.savefig("absError.jpg")
