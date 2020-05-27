#include <stdio.h>

#define SKLEJ(x)    printf(#x" = %d\n",x)
#define IS_EVEN(x)  x%2==0?1:0

int main()
{
	SKLEJ(5*9);
	printf("%d\n",IS_EVEN(2));
	printf("%d\n",IS_EVEN(3));

	return 0;
}
