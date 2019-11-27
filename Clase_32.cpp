#include <iostream>
#include <cmath>
#include <fstream>

//Codigo extraido y modificado de : https://www.dreamincode.net/forums/topic/125770-simulating-diffusion-equation/

using namespace std;
const double rho= 0.01;
const double Tension=40;
const int MaxT=1;
const double dT =0.01;
const int MaxL=1;
const double dL= 0.01;
void wave(int T_n,int L_n);

int main ()
{
    wave(T_n,L_n);
    return 0;
}

void wave(int T_n, int L_n){
    
    int  T_n = MaxT/dT;
	int  L_n = MaxL/dL;
    double paso;
	
    ofstream fout("Clase_32.dat");
    
    double **C = new double *[T_n+1];
    for (int i=0;i<=T_n;i++)
    {
        C[i] =new double[L_n+1];
    }
    
    
    for(int i = 0; i <T_n; i++){
        for(int j=1; j<L_n; j++){
            
            C[i+1][j] = C[i][j] +((D*dt/(pow(dx,2)))*(C[i][j+1] - 2*C[i][j] + C[i][j-1]))+(dt*S); //aqui se define la ecuacion de difusion del libro
            C[0][j+1]=0.0;                             //boundary condition i)      
   
        C[x_n-1][j+1]=0.0;                        //boundary condition ii)   
        }
    }
    
    
    double time =0;
    for (int i = 0; i<=t_n; i++)
    {
        fout<<time<<"\t";
        time+=dt;
        
        for (int j = 0; j <=x_n; j++)
        {
            fout<<C[i][j]<<"\t";
        }
        fout<<"\n";
    }
    
    fout<<0<<"\t"; 
    for(int j=0; j<=x_n;j++){
        
        fout<<x<<"\t";
        x+= dx;
    }

    fout.close();
	                                    
}
