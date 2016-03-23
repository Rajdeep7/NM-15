/*
  Jacobi's Method
  
  The Jacobian Formula is:
  
  X(k+1) = -(Inverse diagonal matrix)*(Lower triangular matrix+Upper triangular matrix)*X(k)+(Inverse diagonal matrix)*(RHS coefficient matrix)
*/
#include<stdio.h>

float coeff[10][10], Di[10][10], approx[10][1] ; //Defining the variables globally
float R[10][10];
float matr[10][1];
float b[10][1];
float temp[10][1];
int row, column, size, t, iter;

void enter_coeff()   //Takes the cofficients of the ystem of equations
{
printf("Enter the coefficient matrix\n"); 
for(row=0;row<size;row++)
    for(column=0;column<size;column++)
        scanf("%f",&coeff[row][column]);
}

void enter_ap()   //Takes the first approximation
{
 printf("Enter the first approximation\n");
 for(row=0;row<size;row++)
 scanf("%f",&approx[row][0]);
}

void enter_rhs()   //Takes the RHS coefficients of the system of equations
{
 printf("Enter the RHS coefficient\n");
 for(row=0;row<size;row++)
 scanf("%f",&b[row][0]);
}

void multiply(float matrixA[][10],float matrixB[][1])  //Mutiplies two matrices
{
    int ctr, ictr;
for(ctr=0;ctr<size;ctr++)
{
    matr[ctr][0]=0;
        for(t=0;t<size;t++)
            matr[ctr][0]=matr[ctr][0]+matrixA[ctr][t]*matrixB[t][0];
}
}

void sol()   //Gives the final solution to the system of equations using the Jacobian Formula
{
 for(row=0;row<size;row++)                   //Gives the diagonal matrix and then its inverse
    for(column=0;column<size;column++)
    {    if(row==column)
        Di[row][column]=1/coeff[row][column];
        else
        Di[row][column]=0;
    }
for(row=0;row<size;row++)                 //Gives the remainder matrix which is (L+U)
    for(column=0;column<size;column++)
    {    if(row==column)
        R[row][column]=0;
        else
        if(row!=column)
        R[row][column]=coeff[row][column];
    }


printf("Enter the number of iterations:\n");  //Takes the number of iterations required to form the solution
scanf("%d",&iter);
int ctr=1;
int octr;
while(ctr<=iter)
{
multiply(R,approx);   //Multiplies the first approx matrix with (L+U) 
   for(row=0;row<size;row++)
temp[row][0]=b[row][0]-matr[row][0];

multiply(Di,temp);   ////Multiplies the inverse diagonal matrix with temp matrix 

   for(octr=0;octr<size;octr++)
approx[octr][0]=matr[octr][0];

printf("The Value after iteration %d is\n\n",ctr);
   
   for(row=0;row<size;row++)
printf("%.3f\n",approx[row][0]);
ctr++;
}

printf("\n\nThe final solution is:\n");
   for(row=0;row<size;row++)
printf("%.3f\n",approx[row][0]);
}

int main()
{
printf("Enter the size of the matrix\n"); //Takes the number of unknowns
scanf("%d",&size);

enter_coeff();

enter_ap();

enter_rhs();

sol();
}

