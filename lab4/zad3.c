#include <stdio.h>
#include <stdlib.h>

void wypelnij(double A_1[][6],int ileW)
{
	double losowaWartosc=(double) rand()/RAND_MAX;
	int i,j;	
	for(i=0;i<ileW;i++)
		for(j=0;j<6;j++)
			A_1[i][j]=(losowaWartosc+=0.4);
			
}

int main()
{
double A_1[8][6];
double A_2[10][6];

int i,j;

wypelnij(A_1,8);

for(i=0;i<8;i++){
	for(j=0;j<6;j++)
		printf("%.2lf ",A_1[i][j]);
printf("\n");}

wypelnij(A_2,10);

printf("\n\n");

for(i=0;i<10;i++){
	for(j=0;j<6;j++)
		printf("%.2lf ",A_2[i][j]);
printf("\n");}		

return 0;
}
