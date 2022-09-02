#include <iostream>
#include "matrix.hxx"
#include "vector.hxx"

using namespace std;

int main(){
	matrix m(3,3,"M1");
	matrix m2(3,3,"M1");
	matrix m3(m);

	Vec v1(3);
	Vec v2(3);

	m(1,1) = 1;
	m(1,2) = 2;
	m(1,3) = 1;
	m(2,1) = 2;
	m(2,2) = 1;
	m(3,3) = 1;

	cout << "Element (2,1) = " << m(2,1) << endl;
	cout << "Element (2,2) = " << m(2,2) << endl;

	// Test of operators:
	m2  = m;
	m2 += m;
	m2  = m2 + m;

	// m2 should now hold 3*m
	m *= -3;
	m2 += m;
	// m2 should now be all 0

	m2.writeToFile("m2");

	v1 = 1;
	v1[3] = 2;
	v2 = m3*v1;

	v2.print();

	return 0;
}
