#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
	int i,j,n,k;
	long rozTXT,rozBIN;
	double *TAB2,*TAB3;
	scanf("%d",&n);
	double *TAB=malloc(n*sizeof(double));
	for(i=0;i<n;i++)
		TAB[i]=(double)rand()/(RAND_MAX/50.f);

	FILE *ft,*fb,*ft2,*fb2;

	if(ft=fopen(argv[1],"w"))
	{
		for(i=0;i<n;i++)
			fprintf(ft,"%lf\n",TAB[i]);

		fseek(ft,0,SEEK_END);
		printf("Rozmiar pliku txt = %ld\n",rozTXT=ftell(ft));
		fclose(ft);
	}

	if(fb=fopen(argv[2],"wb"))
	{
		fwrite(TAB,sizeof(double),n,fb);
		fseek(fb,0,SEEK_END);
		printf("Rozmiar pliku bin = %ld\n",rozBIN=ftell(fb));
		fclose(fb);
	}

	if(ft2=fopen(argv[1],"r"))
	{
		int count=0;
		while(fscanf(ft2,"%lf",TAB)!=EOF)
			count++;
		TAB2=malloc(count*sizeof(double));
		j=0;
		double x;
		rewind(ft2);
		while(fscanf(ft2,"%lf",&x)!=EOF)
			TAB2[j++]=x;
		fclose(ft2);		
	}

	if(fb2=fopen(argv[2],"rb"))
	{
		TAB3=malloc(rozBIN);
		fread(TAB3,rozBIN,1,fb2);
		fclose(fb2);
	}

	printf("\nZawartosc pliku TXT\n");
	for(i=0;i<j;i++)
		printf("%.2lf\n",TAB2[i]);

	printf("\nZawartosc pliku BIN\n");
	for(i=0;i<rozBIN/sizeof(double);i++)
		printf("%.2lf\n",TAB3[i]);

	FILE *fb3;

	if(fb3=fopen(argv[2],"rb+"))
	{
		int k;
		double z=0;
		for(k=0;k<rozBIN/sizeof(double);k+=5)
		{
			fseek(fb3,k*sizeof(double),SEEK_SET);
			fwrite(&z,sizeof(double),1,fb3);
		}
		fclose(fb3);
	}	

	FILE *fb4;

	if(fb4=fopen(argv[2],"rb"))
	{
		fread(TAB3,rozBIN,1,fb4);
		fclose(fb4);
	}

	printf("\nZawartosc pliku BIN\n");
	for(i=0;i<rozBIN/sizeof(double);i++)
		printf("%.2lf\n",TAB3[i]);

	free(TAB);
	free(TAB2);
	free(TAB3);

	return 0;
}
