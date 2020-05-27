#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROZMIAR 81      
#define GRAN 20  

         
void sortlan(char *lan[], int num);
 
int main(void)
{
  char dane[GRAN][ROZMIAR];    
  char **wsklan;               
  int licz = 0;                 
  int k;                       
  printf("Podaj maksymalnie %d wierszy \n",GRAN);
  printf("Aby zakonczyc, wcisnij Enter na poczatku wiersza.\n");
 
	wsklan=malloc(GRAN*sizeof(char*));

 while (licz < GRAN && gets(dane[licz]) != NULL && dane[licz][0] != '\0')
  {
     *(wsklan+licz)=dane[licz]; 
     licz++;
  }

	wsklan=realloc(wsklan,licz*sizeof(char*));

  puts("\n Wczytano:\n");
  for (k = 0; k < licz; k++)
     puts(wsklan[k]) ;

sortlan(wsklan,licz); 

 puts("\n Oto uporzadkowana lista:\n"); 
   for (k = 0; k < licz; k++) 
		puts(wsklan[k]);

return 0; 
} 

  
void sortlan(char *lan[], int num) 
{       
int i,j;                              
 for (i=0;i<num;i++) 
	{
		int min=i;
		for(j=i+1;j<num;j++)
			if(strcmp(lan[min],lan[j])>0)
				min=j;
		char *temp=lan[i];
		lan[i]=lan[min];
		lan[min]=temp;
	}
} 
