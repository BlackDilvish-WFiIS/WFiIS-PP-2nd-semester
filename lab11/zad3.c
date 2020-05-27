#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct Liczba
{
	char typ;
	union
	{
		int C;
		double R;
	};
};

void wypiszTab(struct Liczba *tab,int n)
{
	int i;

	for(i=0;i<n;i++)
	{
		if(tab[i].typ=='i')
			printf("typ: %c\twartosc: %d\n",tab[i].typ,tab[i].C);
		else
			printf("typ: %c\twartosc: %.2lf\n",tab[i].typ,tab[i].R);

	}

}

int liczbyCmp(const void *x,const void *y)
{
struct Liczba a=*(struct Liczba*)x;
struct Liczba b=*(struct Liczba*)y;

if(a.typ=='i' && b.typ=='i')
	return a.C-b.C;
if(a.typ=='i' && b.typ=='d')
	return a.C-(b.R+101.0);
if(a.typ=='d' && b.typ=='i')
	return (a.R+101.0)-b.C;
if(a.typ=='d' && b.typ=='d')
	return ((a.R+100.0>b.R+100.0)-(a.R+100.0<b.R+100.0));

}

int main()
{
struct Liczba *TAB=malloc(20*sizeof(struct Liczba));
int i;

for(i=0;i<20;i++)
{
	if(rand()%2)
	{
		TAB[i].typ='i';
		TAB[i].C=rand()%100;
	}
	else
	{
		TAB[i].typ='d';
		TAB[i].R=(double) rand()/(RAND_MAX/100.f);
	}

}

wypiszTab(TAB,20);

qsort(TAB,20,sizeof(struct Liczba),liczbyCmp);

printf("\n");

wypiszTab(TAB,20);

return 0;
}
