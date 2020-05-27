#include <stdio.h>
#include <stdlib.h>

void wypisz(int *tab,int n)
{
int i;
for(i=0;i<n;i++)
	printf("%d ",tab[i]);
printf("\n");
}

int main()
{
int *tab,n,i,j;
tab=malloc(sizeof(int));

if(tab==NULL)
	return 0;

scanf("%d",&n);

for(i=0;i<n+1;i++)
{
tab=realloc(tab,(i+1)*sizeof(int));
if(tab==NULL)
	return 0;
tab[0]=1;
tab[i]=1;

if(i>1)
{
for(j=i-1;j>0;j--)
 tab[j]+=tab[j-1];
}



wypisz(tab,i+1);

}

free(tab);

return 0;
}
