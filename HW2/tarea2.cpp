#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#define _USE_MATH_DEFINES

int main(){

float a, b,c ;	
	
for (float i=0.00; i<=M_PI; i+=0.0001  ){
	
	c = sin(2*M_PI/180);
	b = atan(45)*180/M_PI;
	a = atan((sin(i))/(2 + cos(i)))*180/M_PI;
	std::cout<<i*180/M_PI<<" "<<a<<std::endl;
}	
	
}
