#include <stdio.h>
/*
void sort(char *A,int n)
{
int i;
int il_duzych=0;
int aktMala=0;
for(i=0;i<n;i++)
	{
		if(A[i]>='A'&&A[i]<='Z')
			il_duzych++;
	}

for(i=0;i<n&&il_duzych!=0;i++)
	{
		if(A[i]>='A'&&A[i]<='Z')
			{
				int x=A[i];
				A[i]=A[aktMala];
				A[aktMala]=x;
				aktMala++;
				il_duzych--;
			}
	}

}
*/

void Sort(char *tab,int n)
{
char *p=tab,*q=tab+n-1;

for(;p<=q;p++)
	{
		if(*p>='a'&&*p<='z')
		{
			char x=*p;
			*p=*q;
			*q=x;
			q--;
		}
	}
}

int main()
{
char tab[9]={'a','A','B','C','b','c','d','D','P'};
int i;
for(i=0;i<9;i++)
	printf("%c",tab[i]);

Sort(tab,9);
printf("\n");

for(i=0;i<9;i++)
	printf("%c",tab[i]);


return 0;
}
