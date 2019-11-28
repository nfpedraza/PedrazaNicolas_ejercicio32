import os
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import cm
from mpl_toolkits.mplot3d import Axes3D

data = np.loadtxt("Clase_32.dat")

x = np.linspace(0, 1,101) 
t = np.linspace(0.0, 6.0,600)

X, T = np.meshgrid(x,t)

fig = plt.figure(figsize=(13,5))
ax = fig.add_subplot(121, projection="3d")
surf = ax.plot_surface(X, T, data, cmap=cm.twilight)
plt.xlabel("Position")
plt.ylabel("Time")
fig.colorbar(surf,aspect=3)

plt.subplot(1,2,2)
plt.plot(x, data[0,:],c='r', label="T. inicial")
plt.plot(x, -data[-1,:],c='black', label="T. final")
plt.grid()
plt.xlabel("Position")
plt.ylabel("Displacement")
plt.legend()
plt.savefig("wav.png")