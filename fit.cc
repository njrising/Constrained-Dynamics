#include "fit.h"

#include "mult.h"
#include <iostream>

void fit(double *A,double *B, double *x, int n){
double x1[n] = {};
mult(A,x,x1,n,1,n);

for(int i = 0;i<n;++i){
    std::cout<<x1[i]-B[i]<<"\n";
}
std::cout<<"\n";
}