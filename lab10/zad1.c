#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int doubleCMP(const void *x,const void *y)
{
double a=*(double*)x;
double b=*(double*)y;

return (a>b)-(a<b);
}

int stringCMP(const void *x,const void *y)
{
char *a=(char*)x;
char **b=(char**)y;

return strcmp(a,*b);
}

int main(int argc, char **argv)
{
char *strings[] = { "Alex", "Bill","Celine", "Dexter", "Forest","Garcia", "Pedro","Zorro"};
double numbers[] = {1.34, 4.34, 5.55, 5.67, 7.76, 8.1, 9.12, 11.23};
double x=atof(argv[2]);
double *findDouble=(double*) bsearch(&x,numbers,sizeof(numbers)/sizeof(*numbers),sizeof(double),doubleCMP);
char **findString=(char**) bsearch(argv[1],strings,sizeof(strings)/sizeof(*strings),sizeof(char*),stringCMP);

if(findDouble)
	printf("Pozycja '%.2lf' w tablicy numbers: %d\n",x,findDouble-numbers);
if(findString)
	printf("Pozycja '%s' w tablicy strings: %d\n",argv[1],findString-strings);

return 0;
}
