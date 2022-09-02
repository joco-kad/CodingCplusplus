#include "vector.hxx"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;
//-------------------------
void Vec::writeToFile(const string fname, const double dx, const bool norm) const{
	ofstream out(fname.c_str());
	if (norm==false)
		for(int i=0; i<dim; i++)
			out << i*dx << "\t" << p[i] << endl;
	else
		for(int i=0; i<dim; i++)
					out << i*dx << "\t" << abs(p[i]) << endl;
	out.close();
}
//-------------------------
void Vec::print() const{
	for(int i=0; i<dim; i++)
		cout << i << "\t" << p[i] << endl;
}
//-------------------------
double Vec::operator[](const int idx) const{
	return p[idx-1];
}
//-------------------------
double& Vec::operator[](const int idx){
	return p[idx-1];
}
//-------------------------
Vec operator+(const Vec& a, const Vec& b){
    if (a.dim == b.dim){
 	   Vec t(a);
 	   t += b;
 	   return t;
    }
    else
    	exit(1);
}
//-------------------------
void Vec::operator=(const Vec& rhs){
	if(dim==rhs.dim)
		for(int i=0; i<dim; i++) p[i] = rhs.p[i];
	else
		exit(1);
}
//-------------------------
void Vec::operator=(const double d){
	for(int i=0; i<dim; i++) p[i] = d;
}
//-------------------------
void Vec::operator+=(const Vec& rhs){
	if (dim==rhs.dim)
		for(int i=0; i<dim; i++) p[i] += rhs.p[i];
	else
		exit(1);
}
//-------------------------
void Vec::operator*=(const Vec& rhs){
	if (dim==rhs.dim)
			for(int i=0; i<dim; i++) p[i] *= rhs.p[i];
		else
			exit(1);
}
//-------------------------
void Vec::operator*=(const double d){
	for(int i=0; i<dim; i++) p[i] *= d;
}
//-------------------------
Vec::Vec(const int dim):dim(dim){
		p = new double[dim];
}
//-------------------------
Vec::Vec(const Vec& v):dim(v.dim){
	p = new double[dim];
	for(int i=0; i<dim; i++) p[i] = v.p[i];
}
//-------------------------
