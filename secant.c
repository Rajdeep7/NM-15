//program to find the solution of f(x) by secant method
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define f(x) (exp(x) - 2*x - 1)

int main()
{
	float r0,r1,r2,r,n,n_i;
	int i=1;
	printf("Enter the initial approximations: ");
	scanf("%f %f",&r0,&r1);
	printf("----------------------------------------------------------------------------\n");
    	printf("Iteration     X0      X1	  f(X0)	  f(X1)	    X2	   |X1-X0|   O(c)\n");
    	printf("---------------------------------------------------------------------------\n");
	
	do
	{
		r2=(r0*(f(r1))-r1*(f(r0)))/((f(r1))-(f(r0)));
		n_i=fabs(r1-r0);
		n=fabs(r2-r1);
		r=log(n)/log(n_i);
		printf("  %d       %0.4f    %0.4f    %0.4f    %0.4f    %0.4f    %0.4f    %.4f\n",i,r0,r1,(f(r0)),(f(r1)),r2,fabs(r2-r1),r);
		r0=r1;
		r1=r2;
		i++;
	}while(fabs(r0-r1)>0.0005);
	printf("------------------------------------------------------------------------------\n");
	
	printf("\n\nThe root is: %f\n\n",r1);
	return 0;
	
}
	
	
