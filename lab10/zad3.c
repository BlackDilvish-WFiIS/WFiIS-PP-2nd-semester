#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define EPS 0.5

struct wektor
{
	int x;
	int y;
	int z;
};

struct abc
{
	struct wektor vect;
	double dlugosc;
};

double wekt_len(struct wektor ww)
{
	return sqrt(ww.x*ww.x+ww.y*ww.y+ww.z*ww.z);
}

void f_d(struct abc *TAB, int i)
{
	(TAB+i)->dlugosc=wekt_len(TAB[i].vect);
}

int dlugoscCMP(const void *x,const void *y)
{
	struct abc *a=(struct abc*)x;
	struct abc *b=(struct abc*)y;
	double d1=a->dlugosc;
	double d2=b->dlugosc;

	return (d1>d2)-(d1<d2);
}

int nowaDlugoscCMP(const void *x,const void *y)
{
	double a=*(double*)x;
	struct abc *b=(struct abc*)y;
	double d2=b->dlugosc;

	if(d2<a-EPS)
		return -1;
	if(d2>a+EPS)
		return 1;
	else
		return 0;
}

void wekt_find(struct abc *TAB, int count, double len)
{
	double x=len;
	struct abc *wsk=(struct abc*) bsearch(&x,TAB,count,sizeof(struct abc),nowaDlugoscCMP);

	if(wsk)
	{
		printf("Wektory o zadanej dlugosci '%.2lf' i epsilon %.2lf: x:%-3dy:%-3dz:%-3dDlugosc:%.2lf\n\n",
len,EPS,wsk->vect.x,wsk->vect.y,wsk->vect.z,wsk->dlugosc);
		wekt_find(TAB,wsk-TAB-1,len);
		wekt_find(wsk,count-(wsk-TAB)+1,len);
	}
}

int main(int argc, char **argv)
{
srand(time(0));

struct abc *TAB=malloc(atoi(argv[1])*sizeof(struct abc));
int i;

for(i=0;i<atoi(argv[1]);i++)
{
	TAB[i].vect.x=rand()%10;
	TAB[i].vect.y=rand()%10;
	TAB[i].vect.z=rand()%10;

	f_d(TAB,i);

	printf("Wektor[%d] x:%-3dy:%-3dz:%-3dDlugosc:%.2lf\n",i,TAB[i].vect.x,TAB[i].vect.y,TAB[i].vect.z,TAB[i].dlugosc);
}

qsort(TAB,atoi(argv[1]),sizeof(struct abc),dlugoscCMP);
printf("\n");

for(i=0;i<atoi(argv[1]);i++)
	printf("Wektor[%d] x:%-3dy:%-3dz:%-3dDlugosc:%.2lf\n",i,TAB[i].vect.x,TAB[i].vect.y,TAB[i].vect.z,TAB[i].dlugosc);

double szukanaDlugosc=9.0;
wekt_find(TAB,atoi(argv[1]),szukanaDlugosc);

free(TAB);

return 0;
}
