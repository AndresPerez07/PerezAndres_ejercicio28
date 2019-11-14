import numpy as np
import matplotlib.pyplot as plt

#%%
data = np.loadtxt("rk4.dat")

plt.plot(data[:,1], data[:,3])
#plt.xlim(0,20)
#plt.ylim(0,20)
plt.savefig("Proyectil_rk4.png")
