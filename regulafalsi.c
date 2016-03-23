//RegulaFalsi Method
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define f(x) ((x*sin(x))+cos(x))
#define E 0.0000005
void main()
{
	printf("Enter your first 2 guesses of x0 and x1: ");
	float x0, x1, x;
	scanf("%f %f", &x0, &x1);
	while(f(x0)*f(x1)>0)
	{
		printf("The root doesnt lie between them. re-enter the roots! \n");
		printf("Enter x0 and x1: ");
		scanf("%f %f", &x0, &x1);
	}
	printf("\n x0\t        x1\t  f(x0)\t        f(x1)\t       x\t   f(x)\t");
	x=(x0*f(x1)-x1*f(x0))/(f(x1)-f(x0));
	while(fabs(f(x))>E)
	{
		printf("\n %f    %f    %f    %f    %f    %f",x0,x1,f(x0),f(x1),x,f(x));
		if(f(x)*f(x1)>0)
			x1=x;
		else
			x0=x;
		x=(x0*f(x1)-x1*f(x0))/(f(x1)-f(x0));
		if((fabs(x-x0))<E || (fabs(x1-x))<E)
			break;
	}
	printf("\n The root = %f",x);
}



			
		
	

