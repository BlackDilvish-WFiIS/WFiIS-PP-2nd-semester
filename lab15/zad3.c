#include <stdio.h>
#include <stdlib.h>

struct stos
{
int value;
struct stos *next;
};

struct stos *push(struct stos *head)
{
    struct stos *newEl=malloc(sizeof(struct stos));
	int var;
	scanf("%d",&var);
    newEl->value=var;
    newEl->next=head;

    return newEl;
}

void read(struct stos *first)
{
	struct stos *wsk=first;
	struct stos *p=NULL;
	while(wsk->next!=NULL)
		wsk=wsk->next;

	do
	{
		p=first;
		while(p->next!=wsk)
			p=p->next;

		printf("%d ",wsk->value);
		wsk=p;
		
	}while(wsk!=first);
	printf("\n");	
}

struct stos *pop(struct stos **head)
{
	if(*head==NULL)
	{
		printf("Stos pusty!\n");
		return NULL;
	}

	struct stos *temp=*head;
	(*head)=(*head)->next;

	return temp;
}

struct stos *clear(struct stos *head)
{
	if(head!=NULL)
	{
		struct stos *temp=head->next;
		free(head);
		clear(temp);
	}
	
	return NULL;
}

int main()
{
struct stos *head=NULL;

head=push(head);head=push(head);head=push(head);head=push(head);
read(head);
struct stos *neww=pop(&head);
printf("%d\n",neww->value);
read(head);

return 0;
}
