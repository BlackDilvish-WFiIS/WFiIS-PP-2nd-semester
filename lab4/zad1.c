#include <stdio.h>
#include <stdlib.h>

void wypisz_d (double *poczatek, double *koniec) { 
  while (poczatek < koniec) 
    printf ("%6.2f", *poczatek++); 
  printf ("\n");    
  return;}

void wypisz_i (int *poczatek, int *koniec) { 
  while (poczatek < koniec) 
    printf ("%4d", *poczatek++);   
  printf ("\n");    
  return;}

int suma (int *tab, int ile)
{
int i,suma=0;

for(i=0;i<ile;i++)
	suma+=*(tab+i);

return suma;
}

void swap(int *x,int *y)
{
int z=*x;
*x=*y;
*y=z;

}

int main()
{
int tab[5][5],i,j,suma_abc[5];

for(i=0;i<5;i++)
	for(j=0;j<5;j++)
		tab[i][j]=rand()%20-10;


for(i=0;i<5;i++)
	wypisz_i(*(tab+i),*(tab+i)+5);

printf("\n");

for(i=0;i<5;i++)
	suma_abc[i]=suma(*(tab+i),5);

wypisz_i(suma_abc,suma_abc+5);

int suma_all=0;

printf("\nsuma_all: %d\n\n",suma_all=suma(*tab,sizeof(tab)/sizeof(int)));

int suma_po_wierszach=0;
for(i=0;i<5;i++)
{
	printf("\nSuma w %d wierszu: %d",i+1,suma(*(tab+i),5));
	suma_po_wierszach+=suma(*(tab+i),5);
}

printf("\n\nSuma po wierszach: %d\n",suma_po_wierszach);

for(i=0;i<5;i++)
	for(j=0;j<5;j++)
		if(i>=j)
			swap(tab[i]+j,tab[j]+i);

for(i=0;i<5;i++)
	wypisz_i(*(tab+i),*(tab+i)+5);


int suma_po_kolumnach=0;
for(i=0;i<5;i++)
{
	printf("\nSuma w %d kolumnie: %d",i+1,suma(*(tab+i),5));
	suma_po_kolumnach+=suma(*(tab+i),5);
}

printf("\n\nSuma po kolumnach: %d\n",suma_po_kolumnach);

printf("\n\nNa przekatnej: ");

for(i=0;i<5;i++)
	for(j=0;j<5;j++)
		if(i==j)
			printf("%d ",tab[i][j]);

printf("\nPod przekatna: ");

for(i=0;i<5;i++)
	for(j=0;j<5;j++)
		if(i>j)
			printf("%d ",tab[i][j]);

return 0;
}
