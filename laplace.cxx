#include <iostream>
#include "matrix.hxx"
#include <string>
#include <cmath>
using namespace std;

double f(const double x,const double y);
void laplacian(matrix &N,const matrix& M, const int Nx, const int Ny,const double dx, const double dy);

int main() {
		// initialize grid
		const int Nx = 1000, Ny = 800;
		const double xmin = -10, xmax = 10, ymin  = -8, ymax = 8;
		const double dx = (xmax -xmin) /(Nx-1);
		const double dy = (ymax -ymin) /(Ny-1);
		
		matrix M(Nx,Ny,"F",false);
		
		// fill matrix according to:
		// f(x,y) = cos(5*sqrt(x²+y²))*exp(-x²-1/10y²)
		for(int i = 1; i <= Nx; i++){
			for(int j = 1; j <= Ny; j++){
					M.set(i,j,f(xmin+i*dx,ymin+j*dy));
			}
		}
		M.writetofile(xmin,dx,ymin,dy);
		matrix N(Nx,Ny,"LaplaceF",false);
		laplacian(N,M,Nx,Ny,dx,dy);
		N.writetofile();
		
}

// calculates f(x,y) = cos(5*sqrt(x²+y²))*exp(-x²-1/10y²)
double f(const double x,const double y){
	return cos(5.0*sqrt(x*x+y*y))* exp(-x*x-y*y/10.0);
}

// calculates the 2D laplacian of a matrix with diriclet boundary conditions
// writes to N reads from N
void laplacian(matrix &N,const matrix& M, const int Nx, const int Ny,const double dx, const double dy){
	double dxx,dyy;
	for(int i = 2; i < Nx; i++){
		for(int j = 2; j < Ny; j++){
				dxx = (M.get(i+1,j)-2*M.get(i,j)+M.get(i-1,j))/(dx*dx);
				dyy = (M.get(i,j+1)-2*M.get(i,j)+M.get(i,j-1))/(dy*dy);
				N.set(i,j,dxx+dyy);
				
				// left boundary
				dxx = (M.get(2,j)-2*M.get(1,j))/(dx*dx);
				dyy = (M.get(1,j+1)-2*M.get(1,j)+M.get(1,j-1))/(dy*dy);
				N.set(1,j,dxx+dyy);
				
				// right boundary
				dxx = (M.get(Nx-1,j)-2*M.get(Nx,j))/(dx*dx);
				dyy = (M.get(Nx,j+1)-2*M.get(Nx,j)+M.get(Nx,j-1))/(dy*dy);
				N.set(Nx,j,dxx+dyy);
		}
		
		// upper boundary
		dxx = (M.get(i+1,1)-2*M.get(i,1)+M.get(i-1,1))/(dx*dx);
		dyy = (M.get(i,2)-2*M.get(i,2))/(dy*dy);
		N.set(i,1,dxx+dyy);
		
		// lower boundary
		dxx = (M.get(i+1,Ny)-2*M.get(i,Ny)+M.get(i-1,Ny))/(dx*dx);
		dyy = (M.get(i,Ny-1)-2*M.get(i,Ny))/(dy*dy);
		N.set(i,Ny,dxx+dyy);
	}
	// corner boundaries
	dxx = (M.get(2,1)-2*M.get(1,1))/(dx*dx);
	dyy = (M.get(1,2)-2*M.get(1,1))/(dy*dy);
	N.set(1,1,dxx+dyy);
	
	dxx = (M.get(Nx-1,1)-2*M.get(Nx,1))/(dx*dx);
	dyy = (M.get(Nx,2)-2*M.get(Nx,1))/(dy*dy);	
	N.set(Nx,1,dxx+dyy);
	
	dxx = (M.get(2,Ny)-2*M.get(1,Ny))/(dx*dx);
	dyy = (M.get(1,Ny-1)-2*M.get(1,Ny))/(dy*dy);	
	N.set(1,Ny,dxx+dyy);
	
	dxx = (M.get(Nx-1,Ny)-2*M.get(Nx,Ny))/(dx*dx);
	dyy = (M.get(Nx,Ny-1)-2*M.get(Nx,Ny))/(dy*dy);		
	N.set(Nx,Ny,dxx+dyy);	
}
