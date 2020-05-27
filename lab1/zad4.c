//notacja wskaznikowa

#include <stdio.h>
#define N 10

float suma(float *t,int n,float *min,float *max,float *srednia,float *maxOdch,float *minOdch)
{
	int i;
	float sum=0;
	for(i=0;i<n;i++) sum+=*(t+i);

	*min=*t;
	for(i=1;i<n;i++)
		if(*min>*(t+i)) 
			*min=*(t+i);

	*max=*t;
	for(i=1;i<n;i++)
		if(*max<*(t+i)) 
			*max=*(t+i);

	*srednia=sum/n;

	*maxOdch=*srednia-*min;	

	*minOdch=*srednia-*max;	

	return sum;
}


int main()
{
float t[N]={1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,0};
float min=0,max=0,srednia=0,maxOdch=0,minOdch=0;

printf("suma=%f",suma(t,N,&min,&max,&srednia,&maxOdch,&minOdch));
printf("\nmin= %f\nmax=%f\nsrednia=%f\nmaxOdch=%f\nminOdch=%f\n",min,max,srednia,maxOdch,minOdch);


return 0;
}


// ponizej notacja indeksowa

/*
#include <stdio.h>
#define N 10

float suma(float *t,int n,float *min,float *max,float *srednia,float *maxOdch,float *minOdch)
{
	int i;
	float sum=0;
	for(i=0;i<n;i++) sum+=t[i];

	*min=t[0];
	for(i=1;i<n;i++)
		if(*min>t[i]) 
			*min=t[i];

	*max=t[0];
	for(i=1;i<n;i++)
		if(*max<t[i]) 
			*max=t[i];

	*srednia=sum/n;

	*maxOdch=*srednia-*min;	

	*minOdch=*srednia-*max;	

	return sum;
}


int main()
{
float t[N]={1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,0};
float min=0,max=0,srednia=0,maxOdch=0,minOdch=0;

printf("suma=%f",suma(t,N,&min,&max,&srednia,&maxOdch,&minOdch));
printf("\nmin= %f\nmax=%f\nsrednia=%f\nmaxOdch=%f\nminOdch=%f\n",min,max,srednia,maxOdch,minOdch);


return 0;
}
*/
