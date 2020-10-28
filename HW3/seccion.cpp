#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <complex>
#define _USE_MATH_DEFINES
#include <type_traits>

template< typename T, typename SCALAR > inline
typename std::enable_if< !std::is_same<T,SCALAR>::value, std::complex<T> >::type
operator* ( const std::complex<T>& c, SCALAR n ) { return c * T(n) ; }

template< typename T, typename SCALAR > inline
typename std::enable_if< !std::is_same<T,SCALAR>::value, std::complex<T> >::type
operator* ( SCALAR n, const std::complex<T>& c ) { return T(n) * c ; }

using namespace std;

float ca = 37558.0;
float ne = 939.6;
float h = 197.3;
float E = 220.0;
vector<double>  err={};

double shift(int L, float K);
double func(int L,  double K, double r);

int main(){
	double mu = 916.667;
	double shi;
	float k = sqrt((2*mu*E)/h);                       
	complex<double> p1;
	complex<double> p2;
	int j1 = 0;
	
	for (float i = 0.0; i<= M_PI; i +=0.001){
		for (int j=0; j<=131; j++){
			complex<double> z1 = exp(1i * shift(j, k) );
			p1 += (2*j + 1)* legendre(j, cos((i+0.0 )))*(2.0*1i*z1*sin(shift(j,k)) );
			//cout<<p1<<" "<<abs(p1)<<endl;
			j1 += 1;
			/*if (abs(abs((2*(j+1) + 1)* legendre((j+1), cos((i+0.0 )))*(2.0*1i*z1*sin(shift((j+1),k)) ))  - abs((2*j + 1)* legendre(j, cos((i+0.0 )))*(2.0*1i*z1*sin(shift(j,k)) ) ) ) <= pow(10,-5)){
				cout<<j<<" "<<abs(abs((2*(j+1) + 1)* legendre((j+1), cos((i+0.0 )))*(2.0*1i*z1*sin(shift((j+1),k)) ))  - abs((2*j + 1)* legendre(j, cos((i+0.0 )))*(2.0*1i*z1*sin(shift(j,k)) ) ) )<<endl;
				}*/
		
		}
	cout<<i*180.0/M_PI<<" "<<abs(p1)<<" "<<j1<<'\n';
	j1 = 0;
	}


return 0;
}


double func(int L, double K, double r){
	double Vo = 40.0; double mu = 916.667;
	return pow(sph_bessel(L, K*r),2)*pow(K*r,2) * (- pow(Vo, 2) *(1/(4*M_PI))* (exp(-(mu*r)/h))/(r));
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


/*
double func(int L, double K){
	double Vo = 40.0;
	return pow(sph_bessel(L, K),2)*pow(K,2) * (- pow(Vo, 2) * (exp(-K))/(K));
}

double shift(int L,float K){
	double integral = 0.0; double integral1 = 0.0; double fi = 10.0; double ini = 0.001; double n = 100.0; double in, integral2;
	double pasos = (fi - ini)/n;
	for (int i = 0; i<=n-1; i ++){
		integral += func(L, K*(ini + i* pasos));
		//cout<<integral<<endl;
		//in +=  (ini + i* pasos);
		//std::cout<<in<<std::endl;
	}
	integral1 = pasos*( (func(L,K*ini) + func(L,K*fi))/2   + integral);
	//integral2 = pasos*((ini + fi)/2 + in);
	
	return integral1;
}
*/
