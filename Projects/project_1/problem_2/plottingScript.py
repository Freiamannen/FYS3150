#
# Plotting script
#

# Importing relevant libraries
import numpy as np
import matplotlib.pyplot as plt

# Getting the data from data file
# The data file is arranged with the first column for x-values, and
# the second column for the u(x)-values
data = np.loadtxt("problem1Data.txt")

# Store the data in arrays
x = data[:, 0]
u_x = data[:, 1]

plt.plot(x, u_x)
plt.title("Plot of problem 2")
plt.xlabel("x")
plt.ylabel("u(x)")
plt.savefig("problem2Plot.pdf")
