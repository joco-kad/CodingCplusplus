#include <iostream>
#include <cmath>
using namespace std;
//-------------------------------
struct particle{
public:
	void set_charge(const double Q){q = Q;}
	double get_mass(){return m;}
	void set_mass(const double M){m = M;}
	int get_number(){return n;}
	void set_number(const int N){n =N;}
	void set_pos(const double X, const double Y, const double Z);
	void get_pos(double& X, double& Y, double& Z);
	void set_v(const double VX, const double VY, const double VZ);
	void get_v(double& VX, double& VY, double& VZ);
	void initialize();
private:
	int n;
	double x,y,z;
	double vx,vy,vz;
	double q,m;
};
//-------------------------------

//-------------------------------
int main(){

}
//-------------------------------
// Set particle position
void particle::set_pos(const double X, const double Y,
		               const double Z){
 x = X; y = Y; z = Z;
}
//-------------------------------
// Get particle position
void particle::get_pos(double& X, double& Y,
		               double& Z){
 X = x; Y = y; Z = z;
}
//-------------------------------
// Set particle velocity
void particle::set_v(const double VX, const double VY,
		               const double VZ){
 vx = VX; vy = VY; vz = VZ;
}
//-------------------------------
// Get particle velocity
void particle::get_v(double& VX, double& VY,
		               double& VZ){
 VX = vx; VY = vy; VZ = vz;
}


//-------------------------------
// Put all member variables to 0
void particle::initialize(){
	m = 0; q = 0; n=0;
	vx = 0; vz = 0; vy = 0;
	x = 0; y = 0; z = 0;
}