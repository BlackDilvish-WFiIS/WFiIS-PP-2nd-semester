#include <stdio.h>
#define N 5

int count=0;

void show(int *tab,int *count)
{
	int i;
	if(*count==0) 
		printf("Brak liczb na stosie\n");
	else
		for(i=0;i<*count;i++)
			printf("%d ",*(tab+i));
	printf("\n");
}

void push(int *tab,int wartosc,int *count)
{
	if(*count==N) 
			printf("Stos pelny\n");
	tab[*count]=wartosc;
	(*count)++;
}

int pop(int *tab,int *count)
{
	if(*count==0) 
	{
		printf("Brak liczb na stosie\n");
		return 0;
	}
	else
	{
		(*count)--;
		return *(tab+*count);
	}	
}

int main()
{
int tab[N];

show(tab,&count);
push(tab,5,&count);
push(tab,6,&count);
printf("%d\n",count);
show(tab,&count);
printf("%d\n",pop(tab,&count));
show(tab,&count);
printf("%d\n",pop(tab,&count));
show(tab,&count);
printf("%d\n",pop(tab,&count));
push(tab,1,&count);
show(tab,&count);


return 0;
}
