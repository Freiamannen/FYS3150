#
# Plotting script
#

# Importing relevant libraries
import numpy as np
import matplotlib.pyplot as plt

# Getting the data
# The data files are arranged:
# Col1: x_hat, Col2: "lowest" eigenvector, Col3: "2. lowest" eigenvector, Col4: "3. lowest" eigenvector
data_A_10 = np.loadtxt("analytical_n_10.txt")
data_A_100 = np.loadtxt("analytical_n_100.txt")
data_N_10 = np.loadtxt("numerical_n_10.txt")
data_N_100 = np.loadtxt("numerical_n_100.txt")

# Store the data
x_10 = data_A_10[:, 0]
x_100 = data_A_100[:, 0]
# Analytical and numerical solution, n = 10
A_10_1 = data_A_10[:, 1]
A_10_2 = data_A_10[:, 2]
A_10_3 = data_A_10[:, 3]
N_10_1 = data_N_10[:, 1]
N_10_2 = data_N_10[:, 2]
N_10_3 = data_N_10[:, 3]
# Analytical and numerical solution, n = 100
A_100_1 = data_A_100[:, 1]
A_100_2 = data_A_100[:, 2]
A_100_3 = data_A_100[:, 3]
N_100_1 = data_N_100[:, 1]
N_100_2 = data_N_100[:, 2]
N_100_3 = data_N_100[:, 3]


# Plotting the data for n = 10
plt.plot(A_10_1, x_10, label = "A - 1")
plt.plot(A_10_2, x_10, label = "A - 2")
plt.plot(A_10_3, x_10, label = "A - 3")
plt.plot(N_10_1, x_10, label = "N - 1")
plt.plot(N_10_2, x_10, label = "N - 2")
plt.plot(N_10_3, x_10, label = "N - 3")
plt.title("Problem 6 - n = 10")
plt.xlabel("x_hat")
plt.ylabel("v")
plt.legend()
plt.savefig("problem6Plot_10.pdf")
plt.savefig("problem6Plot_10.jpg")
plt.clf()

# Plotting the data for n = 100
plt.plot(A_100_1, x_100, label = "A - 1")
plt.plot(A_100_2, x_100, label = "A - 2")
plt.plot(A_100_3, x_100, label = "A - 3")
plt.plot(N_100_1, x_100, label = "N - 1")
plt.plot(N_100_2, x_100, label = "N - 2")
plt.plot(N_100_3, x_100, label = "N - 3")
plt.title("Problem 6 - n = 100")
plt.xlabel("x_hat")
plt.ylabel("v")
plt.legend()
plt.savefig("problem6Plot_100.pdf")
plt.savefig("problem6Plot_100.jpg")
