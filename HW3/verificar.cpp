#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>
#define _USE_MATH_DEFINES


using namespace std;

//float ca = 37558.0;
float ne = 939.6;
float h = 197.3;
float E = 50.0;
double func(int L,  double K, float r);


int main(){
	double mu = (ne*ne)/(ne+ne);
	//double mu = 931.5;
	double shi;
		for (float i=0.001; i<=11.0; i+= 0.001){
			double k = sqrt((2*mu*E))/h;  
			shi = func(1, k, i);
			//shi= asin(-(1/k)*(2*mu/(pow(h,2)))* shift(3,k)) * 180.0/M_PI;
			std::cout<<i<<" "<<shi<<'\n';		
		}

return 0;
}

double func(int L, double K, float r){
	double Vo = 80.0; double mu = (ne*ne)/(ne+ne); double al = 0.8;
	//return pow(sph_bessel(L, K*r),2)*pow(K*r,2) * (- pow(Vo, 1) *(1/(4*M_PI))* (exp(-(mu*r)/h))/(r));
	return pow(sph_bessel(L, K*r),2)*pow(K*r,2) * (- pow(Vo, 1) * (exp(-(al*r)))/(r));
	//return pow(sin(K*r),2) * (- pow(Vo, 1) * (exp(-(al*r)))/(r));
}

