#include <stdio.h>
#define N 10

void zamiana(int *x,int *y)
{
	int pom=*x;
	*x=*y;
	*y=pom;
}

void odwroc(int *tab,int roz)
{
	int i;
	for(i=0;i<roz;i++,roz--)
	{
		zamiana(tab+i,tab+roz-1);
	}

}

void wymien_tablice(int *tab_1,int *tab_2,int roz)
{
	int i;
	for(i=0;i<roz;i++)
		zamiana(tab_1+i,tab_2+i);

}

int main()
{

int i,x[N]={1,2,3,4,5,6,7,8,9,0},y[N]={5,5,5,5,5,5,5,5,5,5};


for(i=0;i<N;i++)
	printf("%d",*(x+i));

printf("\n");
odwroc(x,N);

for(i=0;i<N;i++)
	printf("%d",*(x+i));
printf("\n");
for(i=0;i<N;i++)
	printf("%d",*(y+i));

wymien_tablice(x,y,N);

printf("\n");
for(i=0;i<N;i++)
	printf("%d",*(x+i));
printf("\n");
for(i=0;i<N;i++)
	printf("%d",*(y+i));


return 0;
}
