#include <stdio.h>
#include <stdlib.h>


int main()
{
float arg_1[] = {1.0, 1.2, 1.2, 1.5, 1.5, 1.5, 1.6, 1.6, 1.8, 1.9};
float arg_2[] = {1.0, 1.1, 1.1, 1.2, 1.4, 1.5, 1.6, 1.6, 1.8, 1.8, 1.8, 1.9, 1.9, 2.0, 2.0}; 
float *tab=malloc(sizeof(float));
int i=0,j=0,k=0;

printf("float arg_1[] = {");
for(i=0;i<sizeof(arg_1)/sizeof(float);i++)
	printf("%.1f ",arg_1[i]);
printf("}\n");

printf("float arg_2[] = {");
for(i=0;i<sizeof(arg_2)/sizeof(float);i++)
	printf("%.1f ",arg_2[i]);
printf("}\n");

i=0;

while(i<sizeof(arg_1)/sizeof(float) && j<sizeof(arg_2)/sizeof(float))
{
if(arg_1[i]==arg_2[j] && arg_1[i]!=tab[k])
{
	tab[k]=arg_1[i];
	i++; j++; k++;
	tab=realloc(tab,(k+1)*sizeof(float));
}
else if(arg_1[i]==arg_2[j] && arg_1[i]==tab[k])
{
	i++; k++;
	tab=realloc(tab,(k+1)*sizeof(float));
}
else if(arg_1[i]==arg_2[j] && arg_2[j]==tab[k])
{
	j++; k++;
	tab=realloc(tab,(k+1)*sizeof(float));
}
else if(arg_1[i]<arg_2[j])
{
	tab[k]=arg_1[i];
	i++; k++;
	tab=realloc(tab,(k+1)*sizeof(float));	
}
else
{
	tab[k]=arg_2[j];
	j++; k++;
	tab=realloc(tab,(k+1)*sizeof(float));	
}

}

while(i<sizeof(arg_1)/sizeof(float))
{
	if(arg_1[i]!=tab[k-1])
	{tab[k++]=arg_1[i];
	tab=realloc(tab,(k+1)*sizeof(float)); k--;}
	i++; k++;	
}

while(j<sizeof(arg_2)/sizeof(float))
{
	if(arg_2[j]!=tab[k-1]){
	tab[k++]=arg_2[j++];
	tab=realloc(tab,(k+1)*sizeof(float)); k--;}
	j++; k++;	
}

printf("\nWynik: {");
for(i=0;i<k;i++)
	printf("%.1f ",tab[i]);
printf("}\n");


free(tab);


return 0;
}

