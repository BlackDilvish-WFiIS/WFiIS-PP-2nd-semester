#include <stdio.h>
#include <string.h>

int main()
{

char temp[100];
char separ[] = ")(,; ";
gets(temp);

int licz=0;

while(licz<72)
{
	if(strstr(temp," tak "))
		puts(temp);
	gets(temp);
	licz++;
}

return 0;
}



