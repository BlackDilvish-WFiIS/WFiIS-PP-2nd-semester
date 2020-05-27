#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct cycle *dodajNowy(struct cycle *head,char var)
{
    struct cycle *nowy=malloc(sizeof(struct cycle));
    nowy->value=var;

    if(head)
    {
        nowy->next=head->next;
        head->next=nowy;
    }
    else
        nowy->next=nowy;

    return nowy;
}

void wypiszCycle(struct cycle *head)
{
    struct cycle *temp=head;

    printf("Head ->");
    if(temp)
        do
        {
           printf(" %c ->",temp->value);
           temp=temp->next;
        }while(temp!=head);
    printf(" Head\n");
}

struct cycle *zwolnijCycle(struct cycle *head)
{
    struct cycle *temp;
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

struct cycle *usunzCycle(struct cycle *head,char var)
{
    struct cycle *akt,*pop=NULL;
	
	if(head && head->next==head && head->value==var)
	{
		free(head);
		return NULL;
	}
	else if(head && head->value==var)
	{
		akt=head->next;
		for(;akt!=head;pop=akt,akt=akt->next);
		pop->next=head->next;
		akt=head;
		head=head->next;
		free(akt);
	}
	else if(head && head->next->value==var)
	{
		akt=head->next;
		head->next=head->next->next;
		free(akt);
	}	
    else if(head && head->value!=var)
    {
        akt=head->next;
        for(;akt!=head && akt->value!=var;pop=akt,akt=akt->next);

        if(akt!=head)
        {
		    pop->next=akt->next;
		    free(akt);
        }
    }

	return head;
}
