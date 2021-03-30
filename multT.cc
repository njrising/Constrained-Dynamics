#include "multT.h"

// Matrix Matrix transpose multiplication Mult(A,B',R,ra,rb,cb) 
void multT(double *A, double *B, double *R, int ra, int rb, int cb){
    int i,j,k;
    for(i=0;i<ra;++i){
        for(j=0;j<rb;++j){
            R[i*rb+j]=0;
            for(k=0;k<cb;++k){
                R[i*rb+j]+=A[i*cb+k]*B[j*cb+k];
            }
        }
    }
}