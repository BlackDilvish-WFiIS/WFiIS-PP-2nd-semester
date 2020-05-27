#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct tab_tab
{
int n;
int tab[];
};

int suma (int *t, int count) 
{ 
int i, s = 0;

   for (i = 0; i < count; i++)
        s += t[i];

return s;
}  

int main()
{
int num[]={3,6,4,2};
int count=sizeof(num)/sizeof(int);
int min=0;

struct tab_tab **TAB=malloc(sizeof(struct tab_tab*)*count);
int i;

for(i=0;i<count;i++)
{
	TAB[i]=(struct tab_tab*)malloc(sizeof(struct tab_tab)+num[i]*sizeof(int));	
	TAB[i]->n=num[i];
	int j;	
	for(j=0;j<TAB[i]->n;j++)
	{
		TAB[i]->tab[j]=rand()%5+2;
		printf("i=%d\tj=%d\twartosc=%d\n",i,j,TAB[i]->tab[j]);
	}
	
}

for(i=1;i<count;i++)
{
	if(suma(TAB[min]->tab,TAB[min]->n)>suma(TAB[i]->tab,TAB[i]->n))
		min=i;
}

printf("\nStruktura o najmniejszej sumie elementow: (struktura nr. %d)\n",min);

for(i=0;i<TAB[min]->n;i++)
	printf("i=%d\twartosc=%d\n",i,TAB[min]->tab[i]);

free(TAB);
return 0;
}
