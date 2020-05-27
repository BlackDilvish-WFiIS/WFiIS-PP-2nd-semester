#include <stdio.h>
#include <stdlib.h>

void file_copy(FILE *fp,FILE *fpp)
{
fseek(fp,0,SEEK_END);
long roz=ftell(fp);
rewind(fp);

void *ptr=malloc(roz);
fread(ptr,roz,1,fp);
fwrite(ptr,roz,1,fpp);
}

int main()
{
	FILE *f1,*f2;
	f1=fopen("testy.txt","r");
	f2=fopen("nowy.txt","w");

	file_copy(f1,f2);

	fclose(f1);
	fclose(f2);


	return 0;
}
