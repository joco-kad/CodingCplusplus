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
	void push(const double dt,const double h);
	void initialize();
private:
	int n;
	double x,y,z;
	double vx,vy,vz;
	double q,m;
};
//-------------------------------
double phi(double X, double Y, double Z);
//-------------------------------
int main(){
  
  particle p1;
  //initialize particle
  p1.initialize();
  p1.set_mass(1.0);
  p1.set_charge(1.0);
  p1.set_pos(-10.0,-1.0,0.0);
  p1.set_v(0.5,0.1,0.0);
  //decleration
  const double tend=50.0;
  const double dt=0.01;
  const double h=10e-5;
  double Lx,Ly,Lz;
  //getting values x,y,z
  double x,y,z,vx,vy,vz;
  //loop for calling push
  cout<<"# Ausgabe:______________________________________________________"<<endl;
  cout<<"# Zeit	X	Y	Z	VX	VY	VZ	L	E"<<endl;
  for(int i=1; i<int (tend/dt); i++){
   p1.push(dt,h);
   p1.get_pos(x,y,z);
   p1.get_v(vx,vy,vz);
  //calculate angular momentum
   Lx=y*p1.get_mass()*vz-z*p1.get_mass()*vy;
   Ly=z*p1.get_mass()*vx-x*p1.get_mass()*vz;
   Lz=x*p1.get_mass()*vy-y*p1.get_mass()*vx;
   cout<<dt*i<<"\t"<<x<<"\t"<<y<<"\t"<<z<<"\t"<<vx<<"\t"<<vy<<"\t"<<vz<<"\t"<<sqrt(Lx*Lx+Ly*Ly+Lz*Lz)<<"\t"<<(vx*vx+vy*vy+vz*vz)*0.5+phi(x,y,z)<<endl;
  }
}
//functions
//phi functions returning coulomb-potential
double phi(double X, double Y, double Z){
  const double Q=-1.0;
  return Q/sqrt(X*X+Y*Y+Z*Z);
}
//push function
void particle::push(const double dt,const double h){
//calculate v
  vx=-(q*dt)/m*(phi(x+h,y,z)-phi(x-h,y,z))/(2*h)+vx;
  vy=-(q*dt)/m*(phi(x,y+h,z)-phi(x,y-h,z))/(2*h)+vy;
  vz=-(q*dt)/m*(phi(x,y,z+h)-phi(x,y,z-h))/(2*h)+vz;
//calculate r
  x=dt*vx+x;
  y=dt*vy+y;
  z=dt*vz+z;
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
