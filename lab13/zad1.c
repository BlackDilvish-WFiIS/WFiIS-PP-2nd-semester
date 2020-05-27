#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Klient
{
char f_name[10];
char l_name[10];
char code[10];
int age;
};

int main()
{
struct Klient klienci[6];
int i;
FILE *fp;

if(fp=fopen("dane.txt","r"))
{
	for(i=0;i<6;i++)
	{
		fscanf(fp,"%s %s %s %d",klienci[i].f_name,klienci[i].l_name,klienci[i].code,&(klienci[i].age));
	}
	fclose(fp);
}

FILE *fb;

if(fb=fopen("binarny.bin","wb")){
	fwrite(klienci,sizeof(struct Klient),6,fb);
	fclose(fb);}

FILE *fb2;

if(fb2=fopen("binarny.bin","rb"))
{
	for(i=0;i<6;i++)
	{
		struct Klient *temp=malloc(sizeof(struct Klient));
		fseek(fb2,i*sizeof(struct Klient),SEEK_SET);
		fread(temp,sizeof(struct Klient),1,fb2);
		if(temp->age>=18)
			printf("%s %s %s %d\n",temp->f_name,temp->l_name,temp->code,temp->age);
		free(temp);
	}

	fclose(fb2);
}

return 0;
}
