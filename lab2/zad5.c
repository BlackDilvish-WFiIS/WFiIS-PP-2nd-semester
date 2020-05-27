#include <stdio.h>
#include <stdlib.h>

double d_rand(double min, double max){
	double r = (double) rand()/RAND_MAX;
	return r*(max-min) + min;
}

void swap(double *a,double *b){
int temp;
temp = *a;
*a = *b;
*b = temp;
return;
}

int Partition(double *A,int p,int r){
    int x = A[p];
    int i = p - 1;
    int j = r + 1;
    while (1)
	{

		while(A[i]<x)
			i++;

		while(A[j]>x)
			j--;

	if(i < j)
	    swap(A+i,A+j);
	else 
		return j;
	}
}

void Quicksort(double *A,int p,int r){
if(p < r)
{
    int q = Partition(A, p, r);
    Quicksort(A,p,q);
    Quicksort(A,q+1,r);
}
}



int main()
{
double tab[10];
int i;
for(i=0;i<10;i++)
{
	tab[i]=d_rand(1.5,5.5);
	printf("%.2f ",tab[i]);
}

Quicksort(tab,0,9);
printf("\n");

for(i=0;i<10;i++)
{
	printf("%.2f ",tab[i]);
}

return 0;
}


