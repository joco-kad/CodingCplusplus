
#include <string>

#ifndef MATRIX_HXX_
#define MATRIX_HXX_

class matrix{
  private:
    int n,m;
    std::string name;
    double *p;
  
  public:
     matrix(const int n, const int m,const  std::string name, const bool init);
     //destructor
     ~matrix();
     double get(const int i, const int j) const;
     void set(const int i, const int j, const double v);
     void writetofile(const double xmin = 1,const double dx = 1,const double ymin = 1,const double dy = 1);
     void mult(const double f);
     void plus(const matrix& M);
};


#endif
