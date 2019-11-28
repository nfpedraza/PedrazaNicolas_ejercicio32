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
plt.plot(l, data[0,:],c='r', label="T"+str(data[0,0]))
plt.plot(l, data[2,:],c='black', label="T. final")
plt.plot(l, data[4,:],c='r', label="T. inicial")
plt.plot(l, data[5,:],c='black', label="T. final")
plt.xlabel("Position")
plt.ylabel("Displacement")
plt.legend()

plt.subplot(1,3,3)
plt.plot(l//4, data[0,:],c='r', label="T. inicial")
plt.legend()
plt.savefig("wav.png")