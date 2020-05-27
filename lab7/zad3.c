#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
  
int double_cmp(const void *a,const void *b)
{
double x=*(double*)a;
double y=*(double*)b;

return (x>y)-(x<y);
} 


int cstring_cmp(const void *a,const void *b)
{
const char **x=(const char*)a;
const char **y=(const char*)b;

return strcmp(*x,*y);
}

void print_double_array(double* tab,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%lf ",*(tab+i));
	printf("\n");
}

void print_cstring_array(char** tab,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%s ",*(tab+i));
	printf("\n");
}

void sort_double_example()
{ 
    double numbers[] = { 7.4, 1.3, 14.5, 0.1, -1.0, 2.3, 1,2, 43.0, 2.0, -4.7, 5.8 };
    size_t numbers_len = sizeof(numbers)/sizeof(*numbers);
  
    puts("*** Double sorting..."); 
  
    print_double_array(numbers,numbers_len);     
    qsort(numbers,numbers_len,sizeof(double),double_cmp); 
    print_double_array(numbers,numbers_len);  
} 

 
void sort_cstrings_example() 
{ 
    char *strings[] = { "Zorro", "Alex", "Celine", "Bill", "Forest", "Dexter"};
    size_t strings_len = sizeof(strings)/sizeof(*strings); 
  
    
    puts("*** String sorting..."); 
 
    print_cstring_array(strings,strings_len);    
    qsort(strings,strings_len,sizeof(char*),cstring_cmp);    
    print_cstring_array(strings,strings_len); 
} 
 
int main() 
{ 
    
    sort_double_example();
    sort_cstrings_example(); 
    
    return 0; 
}
