#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Klient
{
char *f_name;
char *l_name;
char *code;
int age;
};

int nazwiskoCMP(const void *x,const void *y)
{
struct Klient *a=(struct Klient*)x;
struct Klient *b=(struct Klient*)y;

return (strcmp(a->f_name,b->f_name));
}

int imieCMP(const void *x,const void *y)
{
struct Klient *a=(struct Klient*)x;
struct Klient *b=(struct Klient*)y;

return (strcmp(a->l_name,b->l_name));
}

int main()
{
struct Klient klienci[6];
char *nazwiska[6]={"Abacki","Abacka","Dadacki","Edacki","Abacka","Zazacki"};
char *imiona[6]={"Jan","Ewa","Tomasz","Jan","Anna","Janek"};
char *kod[6]={"30-103","30-203","30-153","34-104","30-143","30-203"};
int wiek[6]={12,15,42,14,22,12},i;

for(i=0;i<6;i++)
{
	klienci[i].f_name=nazwiska[i];
	klienci[i].l_name=imiona[i];
	klienci[i].code=kod[i];
	klienci[i].age=wiek[i];
	printf("%-10s %-10s %-10s %d\n",klienci[i].f_name,klienci[i].l_name,klienci[i].code,klienci[i].age);
}

qsort(klienci,sizeof(klienci)/sizeof(struct Klient),sizeof(struct Klient),nazwiskoCMP);

for(i=0;i<6;i++)
{
	printf("\n%-10s %-10s %-10s %d",klienci[i].f_name,klienci[i].l_name,klienci[i].code,klienci[i].age);
}

qsort(klienci,sizeof(klienci)/sizeof(struct Klient),sizeof(struct Klient),imieCMP);

printf("\n\n");
for(i=0;i<6;i++)
{
	printf("%-10s %-10s %-10s %d\n",klienci[i].f_name,klienci[i].l_name,klienci[i].code,klienci[i].age);
}

return 0;
}
