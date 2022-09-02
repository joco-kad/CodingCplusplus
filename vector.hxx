/*
 * vector.hxx
 *
 *  Created on: 24.05.2013
 *      Author: goetz
 */

#ifndef VECTOR_HXX_
#define VECTOR_HXX_

#include <string>

class Vec{
public:
	Vec(const int dim); // Standard constructor
	Vec(const Vec& v);  // Copy constructor
	~Vec(){ delete[] p;} // Destructor

	// Members
	int getDim() const{return dim;}
	void print() const;
	void writeToFile(const std::string fname, const double dx=1,
			         const bool norm=false) const;

	// Assignment operator
	void operator=(const double d);
	void operator=(const Vec& rhs);
	// Unitary operators
	void operator+=(const Vec& rhs);
	void operator*=(const Vec& rhs);
	void operator*=(const double d);
	// index operator
	double operator[](const int idx) const;
	double& operator[](const int idx);
	// Binary operators
	friend Vec operator+(const Vec& a, const Vec& b);
private:
	const int dim;
	double* p;
};

#endif /* VECTOR_HXX_ */
