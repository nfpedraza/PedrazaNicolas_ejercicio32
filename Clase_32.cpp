#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

//Para la resolucion del ejericico tome en cuenta la indicciones del libro,https://people.sc.fsu.edu/~jburkardt/cpp_src/fd1d_wave/fd1d_wave.html, mis ejericios 29 y 25 para guiarme en el orden para declarar arreglos, matrices e imprimir datos y tambien de la resolucion del ejericio 29 el cual el profesor dio permiso de usar como plantilla del ejericio 31 para entender la forma de realizar matrices viejas y nuevas.

const double MaxT=40.0, MaxL=1.0, rho=0.01;
const double dT =0.0001, dL= 0.01; 
const double c = sqrt(MaxT/rho), cp=dL/dT; //Courant condition
const int L_n = (MaxL/dL);
void wave(int L_n);

int main (){
    wave(L_n);
    return 0;
}

void wave(int L_n){
	
    ofstream fout("Clase_32.dat");
	
    double t=0;    
    double *C = new double [L_n];
    double *CP = new double [L_n];
    double *CF = new double [L_n];
    
    for(int i=0;i<(L_n+1);i++){
    C[i] = pow(10,-4)*sin(2*M_PI * ((i*dL)/MaxL)); //condicion inicial 
    }
    CP[0]=0;
    CP[L_n]=0;
    for(int i = 1; i <L_n; i++){           
            CP[i] = C[i] +(0.5*pow((c/cp),2)*(C[i+1]- 2*C[i] + C[i-1])); //aqui se define la priemra ecuacion del primer recorrido del ejericio del libro  
        }
    t+=dT;
	
    while (t<0.1){
        
        for(int i =0;i<(L_n+1);i++){
            fout<<CP[i]<<"\t";
        } 
        fout<<"\n";
        
        for(int i=1;i<L_n;i++){   
        CF[i]= (2*CP[i] - C[i])+((pow((c/cp),2)*(CP[i+1] - 2*CP[i] + CP[i-1]))); //aqui se define la segunda ecuacion del segundo recorrido del ejericio del libro
        }
        
        for(int i=1;i<L_n;i++){
             C[i]=CP[i]; //ultimo cambio del ejercicio del libro para actualizar areglos.
            CP[i]=CF[i];
        }
        t+=dT;  
    }
    fout.close();	                                    
}
