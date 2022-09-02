

#include "matrix.hxx"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
// constructor may initialize the matrix or not
matrix::matrix(const int n, const int m,const std:: string name, const bool init){
  this->n = n;
  this->m = m;
  p=new double[n*m];
  this->name = name;
  if(init){
    for(int i = 0; i <= n*m; i++){
      p[i] = 0;
    }
  }
}

// deconstructor
matrix::~matrix(){
  delete[] this->p;
}

// get element of matrix
double matrix::get(const int i, const int j) const{
  if((i <= this->n) && (j <=this->m) && (i >0) && (j >0))
    return p[(i-1)*m+(j-1)];
  else{
	// throw exception if matrix index out of bounds
    cout<<"Error matrix index of matrix "<< name<< " out of bounds"<<endl;
    // throw essentially calls terminate() since it is not catched
    throw("Error matrix index out of bounds.");
  }
}

// set element of matrix
void matrix::set(const int i, const int j, const double v){
  if((i <= n) && (j <=m) && (i >0) && (j >0))
    p[(i-1)*m+(j-1)] = v;
  else{
	// throw exception if matrix index out of bounds
    cout<<"Error matrix index of matrix "<< name<< " out of bounds"<<endl;
    // throw essentially calls terminate() since it is not catched
    throw("Error matrix index out of bounds.");
  }
}

// write the matrix to a file
// modiefied to optionally give position xmin+dx*i 
// and ymin+dy*j instead of i and j
void matrix::writetofile(const double xmin,const double dx,const double ymin,const double dy){
  ofstream out(this->name.c_str());
  for(int i=1; i<=n;i++){
    for(int j=1; j<=m;j++){
      out<<xmin+((double)i-1.0)*dx<<"\t"<<ymin+((double)j-1.0)*dy<<"\t"<<p[(i-1)*m+(j-1)]<<endl;
    }
    out<<endl; //important for gnuplot isosamples
  }
  out.close();
}

// multiplicate the matrix with a skalar
void matrix::mult(const double f){
   for(int i=1; i<=n;i++){
    for(int j=1; j<=m;j++){
      p[(i-1)*m+(j-1)] *= f;
    }
  } 
}

// add two matrices
void matrix::plus(const matrix& M){
   if((this->n == M.n) && (this->m == M.m)){
     for(int i=1; i<=n;i++){
       for(int j=1; j<=m;j++){
 	this->p[(i-1)*m+(j-1)] += M.p[(i-1)*m+(j-1)];
       }
     }
   }
   else { 
		// throw exception if dimensions do not match.
		cout<<"Matrix dimensions do not match."<<endl; 
		// throw essentially calls terminate() since it is not catched  
		throw("Matrix dimensions do not match."); 
	}
}


