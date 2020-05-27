#include <stdio.h>

#define N 100000

int main()
{
int A[N-2];
int i=0;
for(;i<N-2;i++)
	A[i]=i+2;

for(i=0;i<N-2;i++)
{
	int pier=A[i];
	if(A[i]!=0)
	{
		int j=i+1;
		for(;j<N-2;j++)
		{
			if(A[j]%pier==0) A[j]=0;
		}

	}
}

for(i=0;i<N-2;i++)
 if(A[i]!=0)
	printf("%d ",A[i]);


return 0;
}
