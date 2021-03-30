#include "conjGradient.h"
#include "mult.h"

double dot(double *r, double *b, int n){
double t = 0;
for(int i=0;i<n;++i){
	t+=r[i]*b[i];
}
return t;
}

// [A], b, x, iterations, n
void conjGradient(double *A, double *b, double *x, int n){
double t[n]={}; 
double r[n]={};
double p[n]={};

mult(A,x,r,n,1,n);
for(int i=0;i<n;++i){
    r[i] = b[i] - r[i];   // r = b - A*x
    p[i] = r[i];          // p = r    
}

double ro = dot(r,r,n);

for(int j = 0;j < n;++j){
    mult(A,p,t,n,1,n);
    double t1 = ro/dot(t,p, n);    // t1 = dot(r0,r0)/dot(A*p,p)
   
    for(int k = 0;k<n;++k){
        x[k] = x[k] + t1 * p[k];   // x = x + t1 * p
        r[k] = r[k] - t1 * t[k];   // r = r0 - t1 * A*p     
    }
    
    double rn = dot(r,r,n);
    if (rn<1.0e-10){break;}
    double nu = rn/ro;             // nu = dot(r,r)/dot(r0,r0)
   
    for(int m=0;m<n;++m){
        p[m] = r[m] + nu * p[m];   // p = r + nu * p
    }
    ro = rn;                       // r0 = r
}
}
