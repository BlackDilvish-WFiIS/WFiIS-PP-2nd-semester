#include <stdio.h>
#include <math.h>

int zero(double(*fun)(double), double a, double b, double* m_z, double eps)
{
	if(fun(a)*fun(b)>0) 
		return 0;

	double p=a;
	double r=b;
	*m_z=(p+r)/2.f;

		while(fabs(p-r)>=2*eps)
		{
			*m_z=(p+r)/2.f;
			if(fabs(fun(*m_z))<=eps)
			{
				return 1;
			}
			if(fun(p)*fun(*m_z)<0)
			{
				r=*m_z;
			}
			else
			{
				p=*m_z;
			}
		}
	

}

double sinus(double x){return sin(x);}
double fun1(double x){return -x*x+3*x+11;}

int main()
{
double mz=11;

if(zero(sinus,-1,1,&mz,0.001))
	printf("%lf",mz);
else
	printf("\nBrak miejsca zerowego w tym przedziale\n");

if(zero(fun1,0,8,&mz,0.001))
	printf("\n%lf",mz);
else
	printf("\nBrak miejsca zerowego w tym przedziale\n");

if(zero(fun1,-1,1,&mz,0.001))
	printf("\n%lf",mz);
else
	printf("\nBrak miejsca zerowego w tym przedziale\n");

return 0;
}
