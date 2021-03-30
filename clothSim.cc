#include "OpenGL.h"
#include "genCoord.h"
#include "getLength.h"
#include "_C.h"
#include "_J.h"
#include "_JDOT.h"
#include "_CDOT.h"
#include "setM.h"
#include "mult.h"
#include "multT.h"
#include "Tmult.h"
#include "gaussSeidel.h"
#include "conjGradient.h"
#include "printMatrix.h"
#include "fit.h"

#include "data.cc"

int main(){
//--- Do once 
OpenGL program;
glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);

//genCoord(q);

getLength(L,q,ind,nRod);             // generate length of each rod
setM(M,nC);
// set external forces Q 
for(int h=0;h<nPoints;++h){
    Q[2*h+1] = -0.1;
}
//---RUN SIMULATION
while(!program.close()){

_J(J,q,ind,nRod,nC);            // jacobian 
_JDOT(JDOT,v,ind,nRod,nC);      // jacobian time derivative
_C(C,L,q,ind,nRod);                  // constraint	
_CDOT(CDOT,J,v,nRod,nC);        // constraint time derivative

// A = J * W * J'
double A[nRod*nRod] = {};
mult(J,M,r,nRod,nC,nC);
multT(r,J,A,nRod,nRod,nC);

// B = -JDOT*v - J*W*Q - ks * C - kd * CDOT	
double B[nRod] = {};
for(int i=0;i<nRod;++i){
    B[i] += -C[i] * ks - CDOT[i] * kd;
    for(int j=0;j<nC;++j){
        B[i] += -JDOT[nC*i+j] * v[j];
        B[i] += -J[nC*i+j] * Q[j];		
    }
}

// solve Ax = b
double x[nRod] = {};
for(int i=0;i<nRod;++i){x[i]=1.0;}

//gaussSeidel(A,B,x,nRod,nRod);
conjGradient(A,B,x,nRod);
//
//fit(A,B,x,nRod);
//

// constraint force
double cstrF[nC] = {};
Tmult(J,x,cstrF,nRod,nC,nRod,1);

for(int i=2;i<nC;++i){
    a[i]  = Q[i] + cstrF[i]; 
    v[i] += a[i] * dt;
    q[i] += v[i] * dt;
}

program.poll();
// render
//usleep(1000);

//for(int ii = 0;ii<32;++ii){
//program.render({(float)q[2*m[3*ii]],(float)q[2*m[3*ii]+1],(float)q[2*m[3*ii+1]],(float)q[2*m[3*ii+1]+1],(float)q[2*m[3*ii+2]],(float)q[2*m[3*ii+2]+1]});
//}

program.render({q[0],q[1], q[2],q[3], q[4],q[5], q[6],q[7]});

program.post();
}
// END SIMUALATION

glfwTerminate();
return 0;
}