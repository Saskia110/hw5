#include<iostream>
#include<cmath>
#include<fstream>
#include<string>
#include<cstdlib>

using namespace std;

void eulerfor(double* forw,const double dt, const int N);
void eulerback(double* back,const double dt, const int N);
void output(double* forw,double* back,const double dt,int N);


int main(){
    const double dt = M_PI/10;
    const int N = 20*M_PI/dt;
    double* forw= new double [2*N];
    double* back= new double [2*N];
 
    forw[0]=1;
    forw[N]=0;
    
    back[0]=1;
    back[N]=0;
    
    eulerfor(forw,dt,N);
    eulerback(back, dt, N);
    output(forw, back, dt, N);
    
    
    delete[] forw;
    delete[] back;
    
    return 0;
}
void eulerfor(double* forw,const double dt, const int N){
    for(int i=0; i<N; i++){
        forw[i+1]= forw[i] + dt*forw[N+i];
        forw[N+i+1]= forw[N+i] - dt*forw[i];
    }
}

void eulerback(double* back,const double dt, const int N){
const double c = dt * dt+1;
    for (int i=0; i<N; i++){
        back[i+1] = 1/c * back[i] + dt*back[N+i];
        back[N+i+1] = 1/c * back[N+i] - dt*back[i];
    }
}
void output(double* forw,double* back,const double dt,int N){
    ofstream out("Oszi.txt");
    
    for(int i=0; i<N; i++){
        out<< i+dt << "\t"<< forw[i]<< "\t"<< back[i]<< endl;
    }
    out.close();
    
}