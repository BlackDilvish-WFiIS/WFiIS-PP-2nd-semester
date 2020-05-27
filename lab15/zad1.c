#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct tnode {
  int value;
  struct tnode *next;
};

void wypisz_cycle(struct tnode * list)
{
		if (list == NULL)
		{	
		  printf ("PUSTA \n");
		  return;
		}

	struct tnode * wsk = list;

	  do{
		printf ("[%d]  ", list->value);
		list = list->next;
	  }while (list != wsk);

	printf("\n");
	return;
}

struct tnode *add_cycle(struct tnode *list, struct tnode *elem)
{
	elem->value=rand()%9+1;

	if(list)
    {
        elem->next=list->next;
        list->next=elem;
    }
    else
        elem->next=elem;

	return elem;
}



struct tnode *concern_cycle(struct tnode *list1,struct tnode *list2)
{
	if(!list2)
		return list1;
	if(!list1)
		return list2;

	struct tnode *wsk=list1->next;
	list1->next=list2->next;
	list2->next=wsk;
	
	return list1;
}

struct tnode *zwolnij_cycle(struct tnode *head)
{
    struct tnode *temp;
    if(head)
    {
        while(head)
        {
            temp=head->next;
            head->next=temp->next;
            if(temp->next==temp)
                head=NULL;
            free(temp);
        }
    }
    return NULL;
}

int main()
{
srand(time(0));

struct tnode *head=NULL,*list2=NULL;
struct tnode *el[5],*el2[6];
int i;
for(i=0;i<5;i++)
{
	el[i]=malloc(sizeof(struct tnode));
	head=add_cycle(head,el[i]);
}

for(i=0;i<6;i++)
{
	el2[i]=malloc(sizeof(struct tnode));
	list2=add_cycle(list2,el2[i]);
}

wypisz_cycle(head);
wypisz_cycle(list2);

head=concern_cycle(head,list2);

wypisz_cycle(head);

head=zwolnij_cycle(head);
list2=zwolnij_cycle(list2);

wypisz_cycle(head);

return 0;
}
