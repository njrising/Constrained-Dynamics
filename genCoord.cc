#include "genCoord.h"

void genCoord(std::vector<double> &q){

double xx,yy;
for(int i = -2;i <= 2;++i){
	for(int j = -2;j <= 2;++j){
		xx = i * 1.0 + j * 0.0;
		yy = i * 0.0 + j * 1.0;
		q.push_back(xx);
		q.push_back(yy);
	}
}

}