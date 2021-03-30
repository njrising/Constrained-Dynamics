#include "setM.h"

void setM(double *M, int nC){
    for(int i=0;i<nC;++i){
        M[(nC+1)*i] = 1;
    }
}