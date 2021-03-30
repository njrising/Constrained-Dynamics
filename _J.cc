#include "_J.h"

void _J(double *J, std::vector<double> q, int *ind, const int nRod, const int nCoord){

for(int i=0;i<nRod;++i){
    J[nCoord*i+2*ind[2*i+0]]   = 2.0 * (q[2*ind[2*i]]   - q[2*ind[2*i+1]]);
    J[nCoord*i+2*ind[2*i+0]+1] = 2.0 * (q[2*ind[2*i]+1] - q[2*ind[2*i+1]+1]);
        
    J[nCoord*i+2*ind[2*i+1]]   = 2.0 * (q[2*ind[2*i+1]]   - q[2*ind[2*i]]);
    J[nCoord*i+2*ind[2*i+1]+1] = 2.0 * (q[2*ind[2*i+1]+1] - q[2*ind[2*i]+1]);
}

}