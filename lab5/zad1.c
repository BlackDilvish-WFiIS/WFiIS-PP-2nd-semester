#include <stdio.h>
#include <stdlib.h>
#define rows 5
#define columns 5


void wypisz_i (int *poczatek, int *koniec) { 
  while (poczatek < koniec)  
    printf ("%4d", *poczatek++);    
  printf ("\n");     
  return;
}


int main()
{


int **array_1=calloc(6,sizeof(int*));
int i;
for(i=0;i<6;i++)
	*(array_1+i)=calloc(7,sizeof(int));

for(i=0;i<6;i++){
	wypisz_i(*(array_1+i),*(array_1+i)+7);
	printf("\n");
	}

for(i=5;i>=0;i--)
	free(*(array_1+i));
free(array_1);




int **array_2=calloc(4,sizeof(int*));
*(array_2)=calloc(24,sizeof(int));


*(array_2+1)=*(array_2)+6;
*(array_2+2)=*(array_2)+12;
*(array_2+3)=*(array_2)+18;

for(i=0;i<4;i++){
	wypisz_i(*(array_2+i),*(array_2+i)+6);
	printf("\n");
	}

free(array_2);



int (*array_3)[columns]=calloc(rows*columns,sizeof(int));

for(i=0;i<rows;i++)
wypisz_i(array_3[i],array_3[i]+columns);

free(array_3);


return 0;
}
