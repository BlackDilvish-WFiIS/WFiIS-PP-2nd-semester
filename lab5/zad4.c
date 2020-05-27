#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int main()
{
srand(time(0));
char losujWyraz[20];
int i;

for(i=0;i<19;i++)
	losujWyraz[i]=rand()%('z'-'a'+1)+'a';
losujWyraz[19]='\0';

printf("%s",losujWyraz);

char losuj=rand()%('z'-'a'+1)+'a';
printf("\n%c\n",losuj);

char *wsk=strchr(losujWyraz,losuj);

if(wsk) printf("Pierwsze wystapienie: %d",wsk-losujWyraz+1);

int licz=0;
while(wsk!=NULL)
{
	licz++;
	wsk=strchr(wsk+1,losuj);
}

printf("\nIlosc w slowie: %d\n",licz);

return 0;
}
