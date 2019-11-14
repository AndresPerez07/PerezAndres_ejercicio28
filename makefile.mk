Proyectil_rk4.png : rk4.dat plot_rk4.py
						python plot_rk4.py
rk4.dat : proyectil_rk4.x
   ./proyectil_rk4.x
proyectil_rk4.x : proyectil_rk4.cpp
	         c++ proyectil_rk4.cpp o- proyectil_rk4.x

clean :
	  rm rk4.dat proyectil_rk4.x proyectil_rk4.png
