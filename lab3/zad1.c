#include <stdio.h>
#include <stdlib.h>

double losuj(double min, double max){
	double r = (double) rand()/RAND_MAX;
	return r*(max-min) + min;
}


int main()
{
int n,i,m;
double *tab,*iter;
scanf("%d",&n);
tab=malloc(n*sizeof(double));

if(tab==NULL)
	return 0;

for(i=0;i<n;i++)
	tab[i]=losuj(23.0,34.0);


for(iter=tab;iter<tab+n;iter++)
	printf("%f ",*iter);

printf("\nPodaj nowy rozmiar: ");
scanf("%d",&m);

if(m>n)
{
tab=realloc(tab,m*sizeof(double));
for(;i<m;i++)
	tab[i]=losuj(-20.0,-5.0);
}

for(iter=tab;iter<tab+m;iter++)
	printf("%f ",*iter);

free(tab);

return 0;
}
