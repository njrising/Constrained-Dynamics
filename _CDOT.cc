#include "_CDOT.h"

void _CDOT(double *CDOT,double *J, double *v,const int row, const int col){

for(int i=0;i<row;++i){
    for(int j=0;j<col;++j){
        CDOT[i] += J[col*i+j] * v[j]; 
    }
}
    
}