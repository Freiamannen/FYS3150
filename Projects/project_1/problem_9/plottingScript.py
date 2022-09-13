#
# Plotting script
#

# Importing relevant libraries
import numpy as np
import matplotlib.pyplot as plt

# Getting the data from data files
# The data files are arranged with the first column for v-values, and
# the second column for the x-values
data = np.loadtxt("problem9Data.txt")

# Store the data in arrays
v = data[:, 0]
x = data[:, 1]

# Plotting the data
plt.plot(x, v)
plt.title("Plot of problem 9")
plt.xlabel("x")
plt.ylabel("v")
plt.savefig("problem9Plot.pdf")
plt.savefig("problem9Plot.jpg")
