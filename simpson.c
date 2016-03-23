#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float f(float x) { return 1/(1+x); }

float integral(float upper, float lower) {
	int i = 0, n = 2, iter = 0, t=0;
	float I_Old = 0, I_New = 100;
	printf("  Iter.   I_New    I_Old     Error\n-------------------------------------\n");
	while(fabs(I_New - I_Old) >= 0.00005) {
		iter += 1;
		I_Old = I_New;
		float h = (upper - lower)/n;
		float y0 = f(lower), yn = f(upper);
		float s1 = 0, s2 = 0;
		for(i = 0; i < n/2; i++)
			s1 += f(lower + 2 * i * h + h);
		for(i = 0; i < n/2 - 1; i++)
			s2 += f(lower + 2 * i * h + 2 * h);
		I_New = h * (y0 + 4 * s1 + 2 * s2 + yn) / 3;
		printf("%4d%10.4f%10.4f%10.4f\n", t, I_New, I_Old, fabs(I_Old - I_New));
		n *= 2;
		t++;
	}
	return I_New;
}

int main(void) {
	float a, b;
	printf("Enter the lower and upper limits of integral: ");
	scanf("%f %f", &a, &b);
	printf("\nThe result is %f.\n", integral(b, a));
	return 0;
}
