#include <iostream>
#include <fstream>
#include <cmath>
#include <complex>

using namespace std;

void print(int* M, int Nx, int Ny, double xmin, double ymin, double dx, double dy);

int main(){
  
  const int Nx=1000;
  const int Ny=1000;
  const int n=1000;
  const double xmin=-2.0;
  const double ymin=-1.0;
  const double xmax=1.0;
  const double ymax=1.0;
  double dx,dy,abort;
  int counter;
  
  abort=4.0;
  dx=abs(xmax-xmin)/(Nx-1);
  dy=abs(ymax-ymin)/(Ny-1);
  //cout<<"dx"<<dx<<"dy"<<dy<<endl;
  
  int* M= new int[Nx*Ny];
  
  complex <double> c,z;
 /*
  for(int i=0; i<Nx; i++){
    for(int j=0; j<Ny; j++){
      counter=0;
      z=0.0;
      c=complex <double>(xmin+i*dx,ymin+j*dy);
      //cout<<c<<endl;
      while((norm(z)<=abort) && (counter<n)){
	 counter++;
	 z=z*z+c;
      }
      M[i*Nx+j]=counter;
    }
  }
  */
  
  z = 0.0;
  counter = 0;
  // interessantes c
  c = complex <double>(-0.509,0.6);
  ofstream stream("mandelbrot2.out");
  while((norm(z)<=abort) && (counter<n)){
      counter++;
      z=z*z+c;
      stream<<real(z)<<"\t"<<imag(z)<<"\t"<<abs(z)<<endl;
  }
  stream.close();
  
  
  //print(M,Nx,Ny,xmin,ymin,dx,dy);
 //delete[] M;
 
 return 0;
}


void print(int* M, int Nx, int Ny, double xmin, double ymin, double dx, double dy){
  ofstream stream("mandelbrot.out");
  for(int k=0; k<Nx; k++){
    for(int l=0; l<Ny; l++){
      stream<<(xmin+k*dx)<<"\t"<<(ymin+l*dy)<<"\t"<<M[k*Nx+l]<<endl;
    }
  }
  stream.close();
}











