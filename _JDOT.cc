#include "_JDOT.h"
void _JDOT(double *JDOT,double *v,int *ind, const int nRod, const int nCoord){

for(int i=0;i<nRod;++i){
    JDOT[nCoord*i+2*ind[2*i+0]]   = 2.0 * (v[2*ind[2*i]]   - v[2*ind[2*i+1]]);
    JDOT[nCoord*i+2*ind[2*i+0]+1] = 2.0 * (v[2*ind[2*i]+1] - v[2*ind[2*i+1]+1]);
        
    JDOT[nCoord*i+2*ind[2*i+1]]   = 2.0 * (v[2*ind[2*i+1]]   - v[2*ind[2*i]]);
    JDOT[nCoord*i+2*ind[2*i+1]+1] = 2.0 * (v[2*ind[2*i+1]+1] - v[2*ind[2*i]+1]);
}

}