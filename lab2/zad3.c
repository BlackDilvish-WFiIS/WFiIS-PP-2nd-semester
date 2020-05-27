#include <stdio.h>

void swap(int *a, int *b){
int temp;
temp = *a;
*a = *b;
*b = temp;
return;
}

int* find_max_wsk(int *A,int *n)
{
	int i;
	int max=0;
	for(i=1;i<*n;i++)
	{
		if(A[i]>A[max]) max=i;
	}

	return &A[max];	
}

void sort(int *tab,int n)
{
int i,j=0;

for(i=n-1;i>0;i--)
{
	int max=n-j;
	swap(&tab[i],find_max_wsk(tab,&max));
	j++;
}
}

int main()
{
int tab_A[] = {3,5,33,1,7,9,55,1,11,22,12,6,8,4,44,6,42,2,8,26,64,80,16};

int roz=sizeof(tab_A)/sizeof(int);

int i;
for(i=0;i<roz;i++)
	printf("%d ",tab_A[i]);

printf("\n");

sort(tab_A+9,roz-9);

for(i=0;i<roz;i++)
	printf("%d ",tab_A[i]);

sort(tab_A,9);
printf("\n");

for(i=0;i<roz;i++)
	printf("%d ",tab_A[i]);


return 0;
}
