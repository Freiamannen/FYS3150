#
# Plotting script
#

# Importing relevant libraries
import numpy as np
import matplotlib.pyplot as plt

# Getting the data from data file
# The data file is arranged with the first column for x-values, and
# the second column for the u(x)-values
data = np.loadtxt("problem7Data.txt")

# Store the data in arrays
v = data[:, 0]
x = data[:, 1]

# Plotting the data
plt.plot(x, v)
plt.title("Plot of problem 7")
plt.xlabel("x")
plt.ylabel("v")
plt.savefig("problem7Plot.pdf")
