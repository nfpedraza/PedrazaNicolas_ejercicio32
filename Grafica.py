import os
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import cm
from mpl_toolkits.mplot3d import Axes3D

data = np.loadtxt("Clase_32.dat")
lim=(np.shape(data))
print(lim)

l = np.linspace(0, 1,lim[1] )
t = np.linspace(0.0, 40.0,lim[0])

plt.figure(1,figsize=(17,5))
plt.subplot(1,3,1)
plt.imshow(data,extent=[-1,1,1,0],aspect=2.0)
plt.colorbar()
plt.xlabel('X (m)')
plt.ylabel('Time (s)')
plt.title("$\Psi$ ($m^2/s$)")

plt.subplot(1,3,2)
plt.plot(l, data[0,:],c='k', label=("T 0"))
plt.plot(l, data[10,:],c='b', label=("T 0.001"))
plt.plot(l, data[50,:],c='r', label=("T 0.005"))
plt.plot(l, data[100,:],c='g', label=("T 0.01"))
plt.plot(l, data[150,:],c='y', label=("T 0.015"))
plt.plot(l, data[250,:],c='magenta', label=("T 0.025"))
plt.plot(l, data[400,:],c='k', label=("T 0.04"))
plt.plot(l, data[500,:],c='g', label=("T 0.05"))
plt.plot(l, data[600,:],c='gold', label=("T 0.06"))
plt.plot(l, data[800,:],c='k', label=("T 0.08"))
plt.xlabel("Position")
plt.ylabel("Displacement")
plt.legend()

plt.subplot(1,3,3)
plt.plot(l, data[0,:]//4,c='r', label="L/4")
plt.legend()
plt.savefig("wav.png")