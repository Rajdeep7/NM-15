#include<stdio.h>
#include<math.h>
#define e 2.718
#define f(x,y) 2*x*x+2*y
#define h 0.1
#define g(x) (1.5*pow(e,2*x)- x*x - x -.5)
int main()
{
	float x[100],y[100],s[100];
	int i;
	x[0]=0;
	y[0]=1;
	s[0]=y[0];
	for(i=0;i<11;i++){
		float error=100;
		x[i+1]=x[i]+h;
		int c=0;
		float m1=f(x[i],y[i]);
		while(error>=0.0001){
			s[c+1]=y[i]+(h/2)*(m1+f(x[i+1],s[c]));
			error=fabs(s[c+1]-s[c]);
			c++;
		}
		y[i+1]=s[c];
	}
	printf("  i  | x       | y comp   | y act   | abs  error|\n");
	for(i=0;i<11;i++){
	printf("%2d     | %f| %f  |%f | %f      |\n",i,x[i],y[i],g(x[i]),fabs(y[i]-g(x[i])));
	}
	return 0;
}

