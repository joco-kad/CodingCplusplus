#include <iostream>
#include <fstream>
//====================================
using namespace std;
//====================================
void write_to_file(double x[], const double r, const int Nend,
		           const int Nskip, ofstream& out);
void iterate(double x[], const double r, const double x0, const int N);
//====================================
int main(){
	double x0=0.5;
	ofstream out("data.txt");

	const int Nskip = 100; //Number of iterations to skip
	const int Nend = 200; //Number of total iterations

	double x[Nend];

	for(double r=0; r <= 4; r += 0.001){
		iterate(x, r, x0, Nend);
		write_to_file(x,r, Nend, Nskip, out);
	}

	out.close();

	return 0;
}
//====================================
void write_to_file(double x[], const double r, const int Nend,
		           const int Nskip, ofstream& out){
	for(int i=Nskip; i<Nend; i++)
		out << r << "\t" << x[i] << endl;
}
//====================================
void iterate(double x[], const double r, const double x0, const int N){
    x[0]=0.5;
	for(int i=1; i<=N; i++)
	  x[i] = r * x[i-1] * (1-x[i-1]);
}
//====================================
//====================================
