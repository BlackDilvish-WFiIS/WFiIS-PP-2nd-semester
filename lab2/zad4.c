#include <stdio.h>
#include <string.h>

void do_binar(int n, char * wsk)
{
    int i;
    static int liczba = 8 * sizeof(int);
    for (i = liczba - 1; i >= 0; i--, n >>= 1)
        wsk[i] = (01 & n) + '0';
    wsk[liczba] = '\0';
    return ;
}

char* zwroc(char *tab,int n,int p)
{
	tab[n-p]='\0';

	return tab;

}

int main()
{
char tab[32];

do_binar(24,tab);
printf("%s",tab);

printf("\n%s",zwroc(tab,32,1));

return 0;
}
