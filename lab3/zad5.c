#include <stdio.h>
#include <stdlib.h>

double losuj(double min, double max){
	double r = (double) rand()/RAND_MAX;
	return r*(max-min) + min;
}


int main()
{
double *tab;
int n,i;

scanf("%d",&n);
tab=malloc(n*sizeof(double));

for(i=0;i<n;i++)
	tab[i]=losuj(-1.5,1.5);


for(i=0;i<n;i++)
	printf("%lf ",tab[i]);


double *tab_dod=malloc(sizeof(double));
double *tab_min=malloc(sizeof(double));

if(tab_dod==NULL || tab_min==NULL)
	return 0;

int d=0,u=0;

for(i=0;i<n;i++)
{

if(tab[i]>0)
{
	tab_dod=realloc(tab_dod,(d+1)*sizeof(double));
	tab_dod[d++]=tab[i];

}
else
{
	tab_min=realloc(tab_min,(u+1)*sizeof(double));
	tab_min[u++]=tab[i];

}

}

printf("\n");

for(i=0;i<d;i++)
	printf("%lf ",tab_dod[i]);

printf("\n");

for(i=0;i<u;i++)
	printf("%lf ",tab_min[i]);

printf("\n");

free(tab_dod);
free(tab_min);

return 0;
}
