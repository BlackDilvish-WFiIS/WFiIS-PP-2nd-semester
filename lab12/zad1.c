#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

double fun0(double x) { return log(x); }
double fun1(double x) { return x*x;    }
double fun2(double x) { return sin(x); }
double fun3(double x) { return cos(x); }

typedef double(*FUNretWSK)(double);

struct fun
{
	double (*wsk_f)(double);
	char *nazwa;
};

struct fun *fun_tab(double(*TAB_FUN[])(double),char **nazwy,int var)
{
	struct fun *STR_FUN=malloc(var*sizeof(struct fun));
	int i;
	for(i=0;i<var;i++)
	{
		STR_FUN[i].wsk_f=TAB_FUN[i];
		STR_FUN[i].nazwa=nazwy[i];
	}

	return STR_FUN;
}

void fun_prn(struct fun *STR_TAB,int len_fun,double *data,int len_data)
{
	int i,j;
	for(i=0;i<len_fun;i++)
		for(j=0;j<len_data;j++)
			printf(" %s(%lf) = %.4lf\n",STR_TAB[i].nazwa,data[j],STR_TAB[i].wsk_f(data[j]));

}

char *fun_find(struct fun *STR_TAB,int len_fun, double x)
{
	double min=STR_TAB[0].wsk_f(x),y;
	int i,j,r=0;
	for(i=1;i<len_fun;i++)
	{
		y=STR_TAB[i].wsk_f(x);
		if(y>min)
		{
			min=y;
			r=i;
		}
	}
	return STR_TAB[r].nazwa;
}

int structCMP(const void *x,const void *y)
{
struct fun a=*(struct fun*)x;
struct fun b=*(struct fun*)y;

double c=a.wsk_f(1.5);
double d=b.wsk_f(1.5);

return	(c>d)-(c<d);
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

	double data[8] = { 0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0 };

	struct fun *STR_TAB=fun_tab(TAB_FUN,nazwy,4);

	fun_prn(STR_TAB,4,data,8);

	printf("\n\tNajwieksza wartosc dla (1) = %s\n\n",fun_find(STR_TAB,4,1));

	qsort(STR_TAB,4,sizeof(struct fun),structCMP);

	fun_prn(STR_TAB,4,data+2,1);

	free(STR_TAB);

	return 0;
}
