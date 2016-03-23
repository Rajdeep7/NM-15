
//Program to print sin, cosine, e**x, 1/(1-x) series

#include <stdio.h>
#define PI 3.1415926
#define E 0.0000005

float sine(float angle){
	int n = 2;
	float x = angle;
	float term = x, sum = term;
	do{
	term *= (-1)*x*x/((2*n-2)*(2*n-1));
	sum += term;
	n++;
	} while (term > E || term < -E );
	return sum;	
}

float cosine( float angle) {
	int n = 1;
	float x = angle;
	float term = 1, sum = term;
	do{
	term *= (-1)*x*x/(2*n-1)/(2*n);
	sum += term;
	n++;
	} while (term > E || term < -E );
	return sum;	
}

float e (float x){
	int n = 2;
	float sum = 1, term = x;
	sum += term;
	while( term > E || term < -E ){
		term *= x/n;
		sum += term;
		n++;
	}
	return sum;
}	

float series( float x){
	float term = 1, sum = term;
	while( term > E || term < -E){
		term *= x;
		sum += term;
	}
	return sum;
}

int main(void){
	float x, angle;
	printf("To find: sin(x); Enter a value of x in between 0 and 360.\t");
	scanf("%f", &x);
	angle = x*PI/180;
	printf("sin(%.2f) = %f\n\n", x, sine(angle));
	
	printf("To find: cos(x); Enter a value of x in between 0 and 360.\t");
	scanf("%f", &x);
	angle = x*PI/180;
	printf("cos(%.2f) = %f\n\n", x, cosine(angle));

	printf("To find: e**x; Enter a value of x.\t");
	scanf("%f", &x);
	printf("e**%.2f = %f\n\n", x, e(x));

	do{
		printf("To find: 1/(1-x); Enter a value of x in between 1 and -1.\t");
		scanf("%f", &x);
	} while( x >= 1 || x <= -1 );			//Input  value check
	printf("1/(1-%.2f) = %f\n", x, series(x));

	
	return 0;
}
