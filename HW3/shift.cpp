#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <vector>
#include <complex>
#define _USE_MATH_DEFINES


using namespace std;

float ca = 37558.0;
float ne = 939.6;       //collision n + n
float h = 197.3;

double shift(int L, float K);
double func(int L,  double K, double r);

int main(){
	double mu = (ne*ne)/(ne+ne);
	double shi;
	//float k = 31.0;                          //1760
	//shi= (-(1/k)*(2*mu/(pow(h,2)))* shift(2,k) );
	//int nume=0;
		for (int i=50; i<=200; i++){
			float k = sqrt((2*mu*i))/h;  
			shi= asin(-(1/k)*(2*mu/(pow(h,2)))* shift(1,k)) * 180.0/M_PI;
			std::cout<<i<<" "<<shi<<'\n';		
		}


return 0;
}

double func(int L, double K, double r){
	double Vo = 80.0; double mu = (ne*ne)/(ne+ne); double al = 0.8;
	//return pow(sph_bessel(L, K*r),2)*pow(K*r,2) * (- pow(Vo, 1) *(1/(4*M_PI))* (exp(-(mu*r)/h))/(r));
	return pow(sph_bessel(L, K*r),2)*pow(K*r,2) * (- pow(Vo, 1) * (exp(-(al*r)))/(r));
}

double shift(int L,float K){
	double integral = 0.0; double integral1 = 0.0; double fi = 10.0; double ini = 0.001; double n = 1000.0; double in, integral2;
	double pasos = (fi - ini)/n;
	for (int i = 0; i<=n-1; i ++){
		integral += func(L, K,(ini + i* pasos));
		//cout<<integral<<endl;
		//in +=  (ini + i* pasos);
		//std::cout<<in<<std::endl;
	}
	integral1 = pasos*( (func(L,K,ini) + func(L,K,fi))/2   + integral);
	//integral2 = pasos*((ini + fi)/2 + in);
	//std::cout<<integral2<<std::endl;
	return integral1;
}
