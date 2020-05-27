#include <stdio.h>
#include <stdlib.h>

void wypisz_d (double *poczatek, double *koniec) { 
  while (poczatek < koniec) 
    printf ("%6.2f", *poczatek++); 
  printf ("\n");    
  return;}

double suma(double **tab,int nr,int dl)
{
int i;
double suma=0;
for(i=0;i<dl;i++)
	suma+=*(*(tab+nr)+i);

return suma;
}

double *find_tab(double **tab,int dl)
{
int i,minimum=0;
for(i=1;i<dl;i++)
	if(suma(tab,i,4)<suma(tab,minimum,4))
		minimum=i;

return tab[minimum];

}

void swap_tab(double **tab1,double **tab2)
{
	double *x=*tab1;
	*tab1=*tab2;
	*tab2=x;
}

double *find_tab_1(double **tab,int dl,int *min,int przes)
{
int i,minimum=przes;
for(i=przes+1;i<dl;i++)
	if(suma(tab+przes,i,4)<suma(tab+przes,minimum,4))
		minimum=i;

*min=minimum;
return tab[minimum];

}

int main()
{
double T_1[4] = {1.0,3.0, 2.0,1.5};
double T_2[4] = {1.8, 2.0, 1.2, 3.8};
double T_3[4] = {5.6, 1.0, 3.3, 3.3};
double T_4[4] = {1.1, 2.1, 6.5, 1.7};
double T_5[4] = {6.7, 7.8, 9.1, 1.0};
double *TAB[5];
int i,j;

TAB[0]=T_1;
TAB[1]=T_2;
TAB[2]=T_3;
TAB[3]=T_4;
TAB[4]=T_5;

for (i = 0; i<sizeof(TAB)/sizeof(*TAB); i++){
       for (j = 0; j<4; j++)
	    printf("%.2lf ", TAB[i][j]);
        printf ("\n");
    }

double **TABLICA;
TABLICA=TAB;

for(i=0;i<5;i++)
	wypisz_d(*(TABLICA+i),*(TABLICA+i)+4);

printf("\n");
for(i=0;i<5;i++)	
	printf("Suma w %d wierszu: %.2lf\n",i+1,suma(TAB,i,4));

printf("\nWiersz z najmniejsza suma: ");
wypisz_d(find_tab(TAB,5),find_tab(TAB,5)+4);

printf("\n");


int min=0;
for(i=0;i<5;i++)
{
	find_tab_1(TAB,5-i,&min,i);
	swap_tab(TAB+2,TAB+3);
}

for(i=0;i<5;i++)
	wypisz_d(*(TABLICA+i),*(TABLICA+i)+4);

printf("\n");
for(i=0;i<5;i++)	
	printf("Suma w %d wierszu: %.2lf\n",i+1,suma(TAB,i,4));

return 0;
}
