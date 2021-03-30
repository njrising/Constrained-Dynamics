#include "Tmult.h"
// Matrix transpose Matrix  multiplication Mult(A,B',R,ra,ca,rb,cb) 
void Tmult(double *A, double *B, double *R, int ra, int ca, int rb, int cb){
    unsigned i,j,k;
    for(i=0;i<ca;++i){
        for(j=0;j<cb;++j){
            R[i*cb+j]=0;
            for(k=0;k<ra;++k){
                R[i*cb+j] += A[k*ca+i]*B[k*cb+j];
            }
        }
    }
}