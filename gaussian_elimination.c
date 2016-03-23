//Gaussian Elimination

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void pivot(float **array,int k,int n){
	
	int p,l;
	float max,temp;

	max=fabs(array[k][k]);
	p=k;
	for (l=k+1;l<n;l++){
		if (fabs(array[l][k])>max){
			max=fabs(array[l][k]);
			p=l;
		}	
	}
		
	if (p!=k){
		for (l=0;l<n+1;l++){
			temp=array[p][l];
			array[p][l]=array[k][l];
			array[k][l]=temp;
		}
		
	}


}

int main(){
					
	float **a;
	int i,j,n,choice;
	printf("Enter no. of variables to be solved: ");
	scanf("%d",&n);
	a=(float **)malloc(n*sizeof(float *));
	for (i=0;i<n;i++)
		a[i]=malloc((n+1)*sizeof(float));


	for (i=0;i<n;i++){
		printf("Enter the co-efficient of variables and constant term of eqn. %d one by one: \n",i+1);
		for (j=0;j<(n+1);j++)
			scanf("%f",&a[i][j]);
	}
	
	int k,l,p,flag;
	float m,y,max,temp;
	float x[n];
	for (k=0;k<n;k++){
		if (flag) 
			pivot(a,k,n) ;
		
		
		for (i=0;i<n;i++){
			if (i==k)
				continue;
			m=a[i][k]/a[k][k];
			for (j=0;j<=n;j++)
				a[i][j]-=m*a[k][j];
		}
		/*printf("So the coefficient matrix will become: \n");
			for(i=0;i<=n;i++)
			{
				for(j=0;j<=n+1;j++)
				printf("%f ",a[i][j]);
				printf("\n");
			}
			printf("\n\n");
			*/
	
	printf("Solutions are :-\n");
	for (i=0;i<n;i++){
		x[i]=a[i][n]/a[i][i];
		
	}
	
	for (i=0;i<n;i++)
		printf("x%d = %f\n",i,x[i]);

 }
}
	//printf("Enter 0 for without pivoting else enter 1:");
	//scanf("%d",&choice);

	//if (choice)
		
	//else 
		//solve(arr,n,0);


