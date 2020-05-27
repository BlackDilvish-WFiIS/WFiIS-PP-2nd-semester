#include <stdio.h>

#include <stdlib.h> 
#include <string.h> 
  


  
void print_string_array(char **tab, int n)
{
int i;
for(i=0;i<n;i++)
	printf("%s\n",tab[i]);

}

char *min_string (char **tab,int n)
{
int i,j;

	int min=0;
	for(j=1;j<n;j++)
	{
		if(strcmp(tab[min],tab[j])>0)
			min=j;
	}
	
return tab[min];
}


int main() 

{ 
    char *strings[] = { "Zorro", "Alex", "Celine", "Bill", "Forest", "Dexter"};
    
	  char *wsk_string;
		
		size_t strings_len =sizeof(strings)/sizeof(*strings);
  
    
    
 
    print_string_array(strings, strings_len);
 

    
    wsk_string = min_string(strings,strings_len); 
  
    
    printf("\n%s\n", wsk_string); 
  
	return 0; 
} 
