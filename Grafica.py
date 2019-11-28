import os
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import cm
from mpl_toolkits.mplot3d import Axes3D

data = np.loadtxt("Clase_32.dat")

l = np.linspace(0, 1,101) 
t = np.linspace(0.0, 6.0,600)

L, T = np.meshgrid(l,t)

fig = plt.figure(figsize=(17,6))
ax = fig.add_subplot(121, projection="3d")
surf = ax.plot_surface(L, T, data, cmap=cm.twilight)
ax.view_init(30, 40)
plt.xlabel("Position")
plt.ylabel("Time")
fig.colorbar(surf,aspect=3)

plt.subplot(1,2,2)
plt.plot(l, data[0,:],c='r', label="T. inicial")
plt.plot(l, data[-1,:],c='black', label="T. final")
plt.grid()
plt.xlabel("Position")
plt.ylabel("Displacement")
plt.legend()
plt.savefig("wav.png")