//Bisection Method

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define f(x) ((x*sin(x))+cos(x))
#define E 0.000001

void main(){
   float a, b;
   
   printf("Enter the range in which root may lie:\n");
   scanf("%f %f", &a, &b);
        
         while(f(a)*f(b)>0){
             printf("Enter again\n");
             printf("Enter the range in which root may lie:\n");
             scanf("%f %f", &a, &b);  
         }
   float m = (a+b)/2;
   int flag = 0;
         printf("\n a\t        f(a)\t  b\t           f(b)\t     m\t        f(m)");
         while(fabs(a-b)>E){  
             m = (a+b)/2; 
         printf("\n %f    %f    %f    %f    %f    %f", a, f(a), b, f(b), m, f(m));  
                          
             if(f(m)==0){
              flag = 1;
              printf("The root is %f\n", m);
                  break;
             }
             else if(f(m)*f(a)>0)
              a=m;
             else
              b=m;
         }
         if(flag ==0 ){
          m = (a+b)/2;
          printf("\nThe root is %f\n", m);
         }
}
    
            
              
