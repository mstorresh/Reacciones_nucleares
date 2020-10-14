#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#define _USE_MATH_DEFINES

using namespace std;

float mp = 9.0;  //U
float mt = 64.0; //U
float Elab = 19.0;     //Mev
vector<float> te={30.0, 60.0, 90.0, 120.0, 150.0};
vector<float> Nt={32983.0, 2296.0, 545.0, 181.0, 82.0};
vector<float> tecm={34.032, 66.99, 98.084, 126.99, 154.032};
vector<float> error={181.0, 50.0, 10.0, 7.0, 3.0};

float a = cos(M_PI);
float Jn = 29.0; 
float Ecm;
double seno(float N);
double ruth(float N, float A);
double lab(float N, float O);
double croscm(double N, float L, float A);

int main(){

	float Ecm;
	float lam = mp/mt;
	Ecm = Elab*(mt/(mt+mp));
	float E = 16.657;
	float a1 = 0.5*(1.44 * 4 * 30)/E;
	double r1,r2,r3,r4;
	//cout<<pow(cos(M_PI),2)<<endl;
	
	cout<<"angulocm" << " "<< "rutherfordcm"<<" "<<"Lab"<<" "<<"CM"<<" "<<"tetha"<<" "<<"razon"<<endl;
	
	for (int i=0; i<te.size(); i++){
		r1 = ruth(tecm[i], a1);
		r2 = lab(Nt[i],Jn);
		r3 = croscm(r2, lam, tecm[i]); 
		r4 = ruth(te[i],a1);
		cout<<tecm[i] <<" "<<r1<<" "<<r2<<" "<<r3<<" "<<te[i]<<" "<<r3/r1<<endl;
	
	}
	
return 0;
}

double seno(float N){
	
	return sin((N * M_PI/180)/2);
}

double ruth(float N, float A){
	return ((A*A)/4)*(1/pow(seno(N),4));	
}

double lab(float N, float O){
	return N/O;
}
double croscm(double N, float L, float A){
	return N*(abs(L*cos(A*M_PI/180) + 1)/ pow(sqrt(1 + L*L + 2*L*cos(A*M_PI/180)),3));
}
