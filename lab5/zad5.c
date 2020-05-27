#include <stdio.h>
#include <stdlib.h>

void wypisz_i (int *poczatek, int *koniec) { 
  while (poczatek < koniec)  
    printf ("%4d", *poczatek++);    
  printf ("\n");     
  return;
}


int** create_table(int *y)
{
int **tab=calloc(*y+1,sizeof(int*));
*tab=calloc((*y+1)*4,sizeof(int));
int x;
scanf("%d",&x);

int kolumna=0;
*(*(tab+*y)+kolumna)=x;
kolumna++;
scanf("%d",&x);

while(x)
{
	
	if(kolumna%4==0)
	{
		*y+=1;
		kolumna=0;
		tab=realloc(tab,(*y+1)*sizeof(int*));
		*tab=realloc(tab,(*y+1)*4*sizeof(int));
		*(tab+*y)=*tab + (*y+1)*4;
		int i;
		for(i=0;i<4;i++)
			*(*(tab+*y)+i)=0;
	}
	*(*(tab+*y)+kolumna)=x;
	kolumna++;
	scanf("%d",&x);
	
}

return tab;
}

int main()
{
int length=0;
int **tab=create_table(&length);

int i=0;
for(;i<length;i++)
	wypisz_i(tab[i],tab[i]+4);

return 0;
}
