#include "gaussSeidel.h"
// Ax=b solve using gauss-seidel (A,B,x,row,col)
void gaussSeidel(double *A, double *B, double *x, int row, int col){

for(int itr=0;itr<100;++itr){
    
    for(int i=0;i<row;++i){
        double sum = 0;
        for(int j=0;j<col;++j){
            if(i!=j){
                sum += A[col*i+j]*x[j];
            }        
        }
    x[i] = -1/A[(col+1)*i] * (sum - B[i]);        
    }
}


}