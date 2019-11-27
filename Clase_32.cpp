#include <iostream>
#include <cmath>
#include <fstream>

//Para la resolucion del ejericico tome en cuenta la indicciones del libro, mis ejericios 29 y 25 para guiarme en el orden para declarar arreglos, matrices e imprimir datos.

using namespace std;
const double rho= 0.01;
const double MaxT=6.0, MaxL=1.0;
const double dT =0.01, dL= 0.01; 
int L_n = (MaxL/dL);
const double c = 0.5;
double cp=dL/dT;
void wave(int L_n);

int main ()
{
    wave(L_n);
    return 0;
}

void wave(int L_n){
        
    double paso, x, t;
	
    ofstream fout("Clase_32.dat");
    
    double *C = new double [L_n];
    double *CP = new double [L_n];
    double *CF = new double [L_n];
    
    for(int i=0;i<L_n+1;i++){
    paso = i * dL;
    C[i] = sin(M_PI * paso/MaxL); //condicion inicial
        CP[i]=C[i];
        CF[i]=C[i];
    }
    
    for(int i = 1; i <L_n; i++){           
            CP[i] = C[i] +(0.5*pow((c/cp),2)*(C[i+1]- 2*C[i] + C[i-1])); //aqui se define la ecuacion de difusion del libro  
        }
    t+=dT;
    while (t<MaxT){
        
        for(int i =0;i<L_n+1;i++){
            fout<<CP[i]<<"\t";
        } fout<<"\n";
        
        for(int i=1;i<L_n;i++){
            
        CF[i]= (2*CP[i] - C[i])+(C[i+1] - 2*C[i] + C[i-1]);
        }
        
        for(int i=1;i<L_n;i++){
             C[i]=CP[i];
        CP[i]=CF[i];
        }
        t+=dT;
        
    }
   

    fout.close();
	                                    
}
