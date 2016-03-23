#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void answer(float **a,float **b,int n,int c);
float **swap(float **a,int i,int pos,int n);
int main(){
	
	float **a,**b;
	int m,n,i,j,k,l,c;
	printf("\nEnter the dimension of the square matrix: ");
	scanf("%d",&n);
	printf("\nEnter the matrix:\n"); 
	a=(float**)malloc(n * sizeof(float*));
	b=(float**)malloc(n * sizeof(float*));
	for(i=0;i<n;i++){
		printf("\nEnter row %d :",i+1);
		*(a + i) = (float*)malloc(sizeof(float) *(2* n));
		*(b + i) = (float*)malloc(sizeof(float) * n);
		for(j=0;j<n;j++){
				scanf("%f",&a[i][j]);
				b[i][j]=a[i][j];
				if(i==j)
				    a[i][j+n]=1;
				else    
				    a[i][j+n]=0;
		}
	}
	printf("\nAugumented matrix\n");
	for(i=0;i<n;i++){
	    printf("\n");
	    for(j=0;j<(2*n);j++){
	        printf("%f ",a[i][j]);
	    }  
	}          
	printf("\n1.Without pivoting\n2. With pivoting\n");
	scanf("%d",&c);
	if(c==1){
	    printf("\nWithout pivoting\n");
	    answer(a,b,n,0);
	}
	else{    
	    printf("\nWith pivoting\n");
	    answer(a,b,n,1);
	} 
	return 0;
}					
void answer(float **a,float **b,int n,int c){ //c=0,then without pivot  c=1,then pivot

    int i,j,k,pos,i1,j1;
    float sum,divide,max,ans;
    for(i=0;i<n;i++){		//elimination
        
               
        if(c==1){
            max=fabs(a[i][i]);
            for(k=i+1;k<n;k++){ //finding the max coefficient
                if(fabs(a[k][i])>max){
                    pos=k;
                    max=a[k][i];
                }
            }
            if(pos!=i)
                a=swap(a,i,pos,n);   
        }           
	    for(j=0;j<n;j++){ //eliminating
	        printf("\nCurrent augumented matrix\n");
            for(i1=0;i1<n;i1++){
	            printf("\n");
	            for(j1=0;j1<(2*n);j1++){
	                printf("%f ",a[i1][j1]);
	            }  
	        } 
	        printf("\n"); 
	        if(i!=j){
		        divide=a[j][i]/a[i][i];
		        for(k=i;k<(2*n);k++){
			        a[j][k]=a[j][k]-(divide*a[i][k]);
		        }
		    }
		    else{    
		        divide=1/a[i][i];
		        for(k=i;k<(2*n);k++){
			        a[j][k]*=divide;
		        }
	        }
	    }    
	}	
	printf("\nAfter row operations\n");
    for(i=0;i<n;i++){
        for(j=0;j<n+1;j++)
            printf("%f ",a[i][j]);
        printf("\n");    
    }
	printf("\nInverted matrix\n");
	for(i=0;i<n;i++){
	    printf("\n");
	    for(j=n;j<(2*n);j++)
	        printf("%f ",a[i][j]);
	}        
	printf("\n");	
	printf("\nMultiplying A and inverse(A)\n\n");
	for (i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            ans=0;
            for(k=0;k<n;k++) {
                ans=ans+(a[i][k+n]*b[k][j]);
            }
            printf("%f ",ans);
        }
        printf("\n");
    }
} 
float **swap(float **a,int i,int pos,int n){ //swapping 

    int j;
    float temp;
    for(j=i;j<(2*n);j++){

        temp=a[i][j];
        a[i][j]=a[pos][j];
        a[pos][j]=temp;
    }
    return a;
}	
