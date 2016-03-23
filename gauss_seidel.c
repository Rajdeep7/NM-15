/*
  Gauss-Siedel Method
*/
#include<stdio.h>
#include<math.h>
#define e 0.0001
void main()
{
	int i, j, k, n;
    float a[10][10],x[10];
    float sum,temp,error,ex; 
    printf("Enter the number of equations: ");
    scanf("%d",&n) ;
    printf("Enter the co-efficients as well as the RHS contants: \n");
 	for(i=1;i<=n;i++)
 	{
 		for(j=1;j<=n+1;j++)
 		{
 			scanf("%f",&a[i][j]);
		}
 	}
 	for(i=1;i<=n;i++)
 		x[i]=0;
 	do
 	{
 		ex=0;
 		for(i=1;i<=n;i++)
 		{
 			sum=0;
 			for(j=1;j<=n;j++)
			{
			 	if(j!=i)
 					sum=sum+a[i][j]*x[j];
			}
 			temp=(a[i][n+1]-sum)/a[i][i];
 			error=fabs(x[i]-temp);
 			if(error>ex)
 				ex=error;
 			x[i]=temp;
 			printf("\n%f",x[i]);
 		}
 		printf("\n");
	} while(ex>=e);
 	printf("\n\nconverges to solution");
 	for(i=1;i<=n;i++)
 		printf("\nx[%d]=%f",i,x[i]);
}
