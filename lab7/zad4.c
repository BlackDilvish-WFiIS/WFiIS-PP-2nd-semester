#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

double fun0(double x) { return log(x); }
double fun1(double x) { return x*x;    }
double fun2(double x) { return sin(x); }
double fun3(double x) { return cos(x); }

typedef double(*FUNretWSK)(double);

FUNretWSK *find_max(double(*tab[])(double) , double x)
{
	double min=tab[0](x),y;
	int i,j,r=0;
	for(i=1;i<4;i++)
	{
		y=tab[i](x);
		if(y>min)
		{
			min=y;
			r=i;
		}
	}
	return tab+r;
}

int main()
{
	char *nazwy[]={"log", "pow","sin","cos"};
	double (*TAB_FUN[5])(double);

	TAB_FUN[0] = fun0; 
	TAB_FUN[1] = fun1; 
	TAB_FUN[2] = fun2; 
	TAB_FUN[3] = fun3;
	TAB_FUN[4] = NULL;

	double (*(*wsk_fun))(double);
	wsk_fun = TAB_FUN;

	double data[8] = { 0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0 };

	char **s=nazwy;
	int i,j=0;

	while(*(wsk_fun+j)!=NULL){
		for(i=0;i<8;i++)
			printf(" %s %f %.4f\n",*(s+j),data[i],(*(wsk_fun+j))(data[i]));
		j++;
	}

	FUNretWSK *wsk_max=find_max(TAB_FUN,0.05);
	i=wsk_max-wsk_fun;

	printf("\nNajwieksza wartosc dla x=%.2f ma funkcja %s. Wartosc wynosi %.4lf\n"
	,0.05,nazwy[i],(*wsk_max)(0.05));


return 0;
}
