#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Functions
void eulerforward(int n, double dt, double* y1, double* y2);
void eulerbackward(int n, double dt, double* y1, double* y2);
void output(int n, double dt, double* y1, double* y2, string name);
void crank(int n, double dt, double* y1, double* y2);

int main(){	
  //Declerationen
  const double x0=1;
  const double dx0=1;
  double tend,dt;
  int n;
  

  
  //Input
  cout<<"Bitte t_end eingeben!"<<endl;
  cin>>tend;
  cout<<"Bitte dt eingeben!"<<endl;
  cin>>dt;
  cout<<"t_end="<<"\t"<<tend<<endl;
  cout<<"dt="<<"\t"<<dt<<endl;
  //Begin of Main
  n=int(tend/dt+0.5);
  dt = tend/n;
  //Decleration of arrays
  double* y1=new double [n];
  double* y2=new double [n];
  //Starting points
  y1[0]=x0;
  y2[0]=dx0;
  //call functions
  eulerforward(n,dt,y1,y2);
  output(n,dt,y1,y2,"dummy1");
  eulerbackward(n,dt,y1,y2);
  output(n,dt,y1,y2,"dummy2");
  crank(n,dt,y1,y2);
  output(n,dt,y1,y2,"dummy3");
  
  
  return 0;

}

void eulerforward(int n, double dt, double* y1, double* y2){
  for(int i=1; i<n; i++){
    y1[i]=y1[i-1]+dt*y2[i-1];
    y2[i]=-dt*y1[i-1]+y2[i-1];
  }
}
void eulerbackward(int n, double dt, double* y1, double* y2){
  for(int i=1; i<n; i++){
    y1[i]=(1/(1+dt*dt))*y1[i-1]+dt*y2[i-1];
    y2[i]=(1/(1+dt*dt))*-dt*y1[i-1]+y2[i-1];
  }
}
void crank(int n, double dt, double* y1, double* y2){
  for(int i=1; i<n; i++){
    y1[i]=(1/(1+dt*dt/4))*(1-dt*dt/4)*y1[i-1]+dt*y2[i-1];
    y2[i]=(1/(1+dt*dt/4))*-dt*y1[i-1]+(1-dt*dt/4)*y2[i-1];
  }
}

void output(int n, double dt, double* y1, double* y2, string name){
      ofstream dummy(name.c_str());
  for(int i=1; i<n; i++){

   dummy<<dt*double(i)<<"\t"<<y1[i]<<"\t"<<y2[i]<<endl;
  }
  dummy.close();
}









