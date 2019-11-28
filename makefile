wav.png : Clase_32.dat Grafica.py
	python Grafica.py
	

Clase_32.dat : Clase_32.x
	./Clase_32.x 

Clase_32.x : Clase_32.cpp
	c++ Clase_32.cpp -o Clase_32.x
	
clean : 
	rm Clase_32.x Clase_32.dat wav.png