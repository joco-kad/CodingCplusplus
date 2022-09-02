// RungeKutta.cxx
// Runge Kutta 4th order
// GL, 25.4.2012
//--------------------
#include <cmath>
#include <iostream>
#include <fstream>
//--------------------

void f(double* const y0, const double x);
void RKstep(double* const yn, const double* const y0, const double x, const double dx);


//--------------------
using namespace std;
//--------------------

int main(void)
{
	ofstream out("solution");

	double x=0;
	const double PI = 3.14159265359;
	const double L = 2*PI;
    double y0[2] = {1.0, 0.0};
	double yn[2];
    double dx;

	cout << "dx = "; cin >> dx;

    out << x << "\t" << y0[0] << "\t" << y0[1] << endl;
	while(x<=L)
	{
		x += dx;
		RKstep(yn, y0, x, dx);
		y0[0] = yn[0];
		y0[1] = yn[1];
		out << x << "\t" << y0[0] << "\t" << y0[1] << endl;
	}


	out.close();
	return(0);
}
//-------------------
//-------------------

void RKstep(double* const yn, const double* const y0, const double x, const double dx)
{
	double k1[2], k2[2], k3[2], k4[2];

	k1[0] = y0[0];
	k1[1] = y0[1];
	f(k1, x);

	k2[0] = y0[0] + 0.5 * dx * k1[0];
    k2[1] = y0[1] + 0.5 * dx * k1[1];
	f(k2, x+0.5*dx);

	k3[0] = y0[0] + 0.5 * dx * k2[0];
	k3[1] = y0[1] + 0.5 * dx * k2[1];
	f(k3, x+0.5*dx);

	k4[0] = y0[0] + dx * k3[0];
	k4[1] = y0[1] + dx * k3[1];
	f(k4,  x+dx);

	yn[0] = y0[0] + 1./6.*dx*(k1[0] + 2*k2[0] + 2*k3[0] + k4[0]);
	yn[1] = y0[1] + 1./6.*dx*(k1[1] + 2*k2[1] + 2*k3[1] + k4[1]);
}

//-------------------
//-------------------
// d^2y/dx^2 + y = 0
void f(double* const y0, const double x)
{
	double y[2] = { y0[0], y0[1] };

	y0[0] =  y[1];
	y0[1] = -y[0];
}