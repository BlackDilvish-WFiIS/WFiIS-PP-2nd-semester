#include <stdio.h>
#include <stdlib.h>

void print_tab(int a[][4], int x){
  int i, j;
  for (i = 0; i < x; i++){
    for (j = 0; j < 4; j++)
      printf ("%3d", a[i][j]);
    printf ("\n");
   }
return;
}

void wypisz_i (int *poczatek, int *koniec) { 
  while (poczatek < koniec)  
    printf ("%4d", *poczatek++);    
  printf ("\n");     
  return;
}


int (*mn_tab(int (*A)[3],int (*B)[4],int l))[4]
{
int i,j,k;

int (*C)[4]=calloc(4*l,sizeof(int));

for(i=0;i<l;i++)
	for(j=0;j<4;j++)
		for(k=0;k<3;k++)
			*(*(C+i)+j)+=*(*(A+i)+k) * *(*(B+k)+j);

return C;

}

int (*mn_tab_all(int l,int m,int n,int A[l][m],int B[m][n]))
{
int i,j,k;

int (*C)[n]=calloc(n*l,sizeof(int));

for(i=0;i<l;i++)
	for(j=0;j<n;j++)
		for(k=0;k<m;k++)
			*(*(C+i)+j)+=*(*(A+i)+k) * *(*(B+k)+j);

return (int*) C;

}


int main()
{
int t_A [2][3] = {1,2,3,4,5,6};
int t_B [3][4] = {1,1,1,1,1,1,1,1,1,1,1,1};

int (*C)[4]=mn_tab(t_A,t_B,2);
print_tab(C,2);

int i;
for(i=0;i<2;i++)
	wypisz_i(C[i],C[i]+4);


return 0;
}
