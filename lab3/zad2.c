#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *podloga(double *x,double *y)
{
int *a=malloc(sizeof(double));

if(a==NULL)
	return 0;

*a=(int) floor(*x * *y);
return a;

}

int main()
{
double x,y;

scanf("%lf",&x);
scanf("%lf",&y);

printf("%.1d",*podloga(&x,&y));



return 0;
}
