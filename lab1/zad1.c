#include <stdio.h>
#include <stdlib.h>
#define N 10

int suma(const int *tab,const int *ost);

int main()
{
int i,*p=NULL,tab[N];


for(p=tab;p<tab+N;p++)
{
	*p=7+rand()%28;
	printf("tab[%d] = %d\n",p-tab,*p);
}

printf("\n");

int su=suma(tab,tab+N);

printf("su=%d\n",su);
return 0;
}


int suma(const int *tab,const int *ost)
{
	if(tab<ost)
		return *tab + suma(tab+1,ost);
	else
		return 0; 

}
