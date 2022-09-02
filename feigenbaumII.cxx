/*
 * FeigenbaumII now with arrays!
 * @author Jan Hansen
 * 23.04.2013 
 * 
 * Attention! Potentially existing files "output.dat" will be deleted.
 * 
 */

#include <iostream>
#include <fstream>

using namespace std;

void series(double* x, int xlength, double r);
void tofile(double* x, int xlength, double r);

int main(){
	const double x0=0.5;
	const int Nskip = 100; //Number of iterations to skip
	const int Nend = 200; //Number of total iterations
	
	double x[Nend];
	x[0]  = x0;  	// x[0] will be used as starting element in series
	
	ofstream file("output.dat", ios::out | ios::trunc); // Empty existing file
	file.close();

	for(double r=0; r <= 4; r += 0.001){
		series(x, Nend, r);
		tofile(&x[Nskip-1], Nend-Nskip,r); // Skip first iterations when writing to file
	}
	return 0;
}

// fills array x according to feigenbaum formula
void series(double* x, int xlength, double r){
	for(int i = 1; i<xlength;i++){
		x[i] = r*x[i-1]*(1-x[i-1]);
	}
}

// writes x to file "output.dat"
void tofile(double* x, int xlength, double r){
	ofstream file("output.dat", ios::out | ios::app); // append to loop over different r
	for(int i = 0; i<xlength;i++){
			file << r << "\t" << x[i] << endl;
	}
	file.close();
}