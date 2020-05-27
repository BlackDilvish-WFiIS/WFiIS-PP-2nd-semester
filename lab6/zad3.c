#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char** podziel(char *, int *);
void sort(char **, int);
char* sklej(char **, int);

int main()
{
char **tab;
char napis[]="The sun did not shine. It was too wet to play. So we sat in the house - All that cold, cold, wet day.";
int rozmiar=0,i;

tab=podziel(napis,&rozmiar);

for(i=0;i<rozmiar;i++)
	printf("%s ",*(tab+i));

sort(tab,rozmiar);
printf("\n");

for(i=0;i<rozmiar;i++)
	printf("%s ",*(tab+i));

printf("\n%s\n",sklej(tab,rozmiar));

return 0;
}

char** podziel(char *napis, int *rozmiar)
{
	char *temp;
	char **tab=malloc(40*sizeof(char*));
	temp=strtok(napis,", ;.:-");

	while(temp)
	{
		int i,err=0;
		for(i=0;i<*rozmiar;i++)
			if(strcmp(*(tab+i),temp)==0)
				err=1;

		if(err==1)
			{
				temp=strtok(0,", ;.:-");
				continue;
			}

		*(tab+*rozmiar)=temp;
		(*rozmiar)++;
		temp=strtok(0,", ;.:-");
	}

		return tab;
}

void sort(char **tab, int rozmiar)
{
	int i,j;
	for(i=0;i<rozmiar;i++)
	{
		int min=i;
		for(j=i+1;j<rozmiar;j++)
			if(strcmp(*(tab+min),*(tab+j))>0)
				min=j;
		
		char *temp=*(tab+i);
		*(tab+i)=*(tab+min);
		*(tab+min)=temp;
	}
}

char* sklej(char **tab, int rozmiar)
{
	int i;
	char *napis2=malloc(sizeof(char));

	for(i=0;i<rozmiar;i++)
	{
		strcat(napis2,*(tab+i));
		strcat(napis2," ");
	}

	return napis2;
}
