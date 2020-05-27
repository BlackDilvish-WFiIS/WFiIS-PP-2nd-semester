#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
char *tab=calloc(strlen("----------x----------")+1,1);
strcat(tab,"----------x----------");
char *tab_p=calloc(strlen("---------------------")+1,1);
strcat(tab_p,"---------------------");

char czarne='x';
char biale='-';
int i,j,roz=strlen(tab);

printf("%s\n",tab);

for(j=0;j<100;j++)
{
for(i=1;i<roz-1;i++)
	{
		if(!memcmp(tab+i-1,&czarne,1) && !memcmp(tab+i,&czarne,1) && !memcmp(tab+1+i,&czarne,1))
			memset(tab_p+i,biale,1);
		if(!memcmp(tab+i-1,&czarne,1) && !memcmp(tab+i,&czarne,1) && !memcmp(tab+1+i,&biale,1))
			memset(tab_p+i,biale,1);
		if(!memcmp(tab+i-1,&czarne,1) && !memcmp(tab+i,&biale,1) && !memcmp(tab+1+i,&czarne,1))
			memset(tab_p+i,biale,1);
		if(!memcmp(tab+i-1,&czarne,1) && !memcmp(tab+i,&biale,1) && !memcmp(tab+1+i,&biale,1))
			memset(tab_p+i,czarne,1);
		if(!memcmp(tab+i-1,&biale,1) && !memcmp(tab+i,&czarne,1) && !memcmp(tab+1+i,&czarne,1))
			memset(tab_p+i,czarne,1);
		if(!memcmp(tab+i-1,&biale,1) && !memcmp(tab+i,&czarne,1) && !memcmp(tab+1+i,&biale,1))
			memset(tab_p+i,czarne,1);
		if(!memcmp(tab+i-1,&biale,1) && !memcmp(tab+i,&biale,1) && !memcmp(tab+1+i,&czarne,1))
			memset(tab_p+i,czarne,1);
		if(!memcmp(tab+i-1,&biale,1) && !memcmp(tab+i,&biale,1) && !memcmp(tab+1+i,&biale,1))
			memset(tab_p+i,biale,1);
	}

	if(!memcmp(tab,tab_p,roz))
		break;

	memcpy(tab,tab_p,roz);

	printf("%s\n",tab);
}

free(tab);
free(tab_p);
return 0;
}
