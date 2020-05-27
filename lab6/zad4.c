#include <stdio.h>

int add2(int *x, int *y){return *x+*y;} 
int comp2(int *x, int *y){return *x-*y;}


int add2_or_comp2 (int *x,int *y,int (*fun)(int*,int*))
{
	return fun(x,y);
}

int main()
{
int x=5,y=6;

printf("%d - %d = %d\n",x,y,add2_or_comp2(&x,&y,comp2));
printf("%d + %d = %d\n",x,y,add2_or_comp2(&x,&y,add2));

return 0;
}
