#include "printMatrix.h"

#include<iomanip>
void printMatrix(double *A,int row, int col){
for(int i=0;i<row;++i){
    for(int j=0;j<col;++j){
        std::cout<<A[col*i+j]<<" ";
    }
    std::cout<<"\n";
}
std::cout<<"\n";
}


