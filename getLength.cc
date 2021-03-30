#include "getLength.h"

void getLength(std::vector<double> &L,std::vector<double> q, int *ind, int nRod){
double x1,y1,x2,y2;
for(int i = 0;i<nRod;++i){
    x1 = q[2*ind[2*i]]; 
    y1 = q[2*ind[2*i]+1];
    x2 = q[2*ind[2*i+1]];
    y2 = q[2*ind[2*i+1]+1];
    double l = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
    L.push_back(l);
}
}
