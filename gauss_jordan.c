//Gauss-Jordan


#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i, j, l, n, k=0, temp;
	float m, var, max, s;

	printf("Please input the order of the matrix: ");
	scanf("%d",&n);
	
	float x[n], a[n][n+1]; 
		
	printf("Please input the coefficient matrix: \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<=n;j++)
			scanf("%f",&a[i][j]);
	}
	n--;
	while(k<=n)
	{		 
		l=k;
		max=a[k][k];
		temp=0;
		for(; k<=n-1; ++k)
		{
			if(a[k+1][k]>max)
			{
				max=a[k+1][k];
				temp=k+1;
			}
		}
		k=l;
		if(temp!=0)
		{
			for(i=0;i<=n+1;i++)
			{
				var=a[temp][i];
				a[temp][i]=a[k][i];
				a[k][i]=var;
			}
			printf("The coefficient matrix: \n", k);
			for(i=0;i<=n;i++)
			{
				for(j=0;j<=n+1;j++)
				printf("%.2f ",a[i][j]);
				printf("\n");
			}
			printf("\n\n");
		}
		i=0;
		while (i<=n)
		{
			if (i!=k)
			{
				m=a[i][k]/a[k][k];
				j=0;
				while(j<=n+1)
				{
			        
					a[i][j]=a[i][j]-m*a[k][j];
					j++;
				}
			}
			i++;
		}
		k++;
		
		printf("After %d steps, the coefficient matrix will become: \n", k);
			for(i=0;i<=n;i++)
			{
				for(j=0;j<=n+1;j++)
				printf("%0.2f ",a[i][j]);
				printf("\n");
			}
			printf("\n\n");
	}
	k=0;
	while(k<=n)
	{
		x[k]=a[k][n+1]/a[k][k];
		k++;
	}
	printf("The solution is: \n");
	for(i=0;i<=n;i++)
		printf("\tx%d=%0.2f \n",i+1,x[i]);
		printf("\n\n");
	return 0;
}
