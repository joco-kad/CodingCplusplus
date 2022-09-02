

#include <iostream>
#include "matrix.hxx"
#include <string>
using namespace std;

int main(){
  matrix M(3,2,"M",true);
  matrix N(3,2,"N",true);
  M.set(1,1,1);
  N.set(1,1,2);
  N.set(1,2,5);
  M.plus(N);
  M.writetofile(2,2,2,3);
}
