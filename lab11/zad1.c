#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

char *skleja(int n,...)
{
	int i,suma=0;

	va_list lista;
	va_start(lista,n);

	for(i=0;i<n;i++)
		suma+=strlen(va_arg(lista,char*));
	va_end(lista);

	char *tab=calloc(suma,1);
	tab[0]='\0';

	va_list lista2;
	va_start(lista2,n);


	for(i=0;i<n;i++)
	{
		strcat(tab,va_arg(lista2,char*));
	}

	va_end(lista2);

	return tab;
}

int main()
{


char *tab=skleja(3,"Ala ","Ma ","Kota ");

printf("%s",tab);

free(tab);

char *tab2=skleja(4,"Ala"," nie"," ma"," Kota");

printf("\n%s\n",tab2);

free(tab2);

return 0;
}
