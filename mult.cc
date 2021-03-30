#include "mult.h"

// Matrix Matrix multiplication Mult(A,B,R,d) 
void mult(double *A, double *B, double *R, int ra, int cb, int in){
    int i,j,k;
    for(i=0;i<ra;++i){
        for(j=0;j<cb;++j){
            R[i*cb+j]=0;
            for(k=0;k<in;++k){
                R[i*cb+j]+=A[i*in+k]*B[k*cb+j];
            }
        }
    }
}