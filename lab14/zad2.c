#include <stdio.h>
#include <stdlib.h>

struct tnode
{
	char value;
	struct tnode *next;
};

struct tnode *dodaj_na_poczatek(struct tnode *head,char var)
{
    struct tnode *newEl=malloc(sizeof(struct tnode));
    newEl->value=var;
    newEl->next=head;

    return newEl;
}

void WypiszListe(struct tnode *head)
{
    printf("Head -> ");
    if(!head)
    {
        printf("NULL\n");
        return;
    }
    for(;head;head=head->next)
        printf("%c -> ",head->value);
    printf("Null\n");
}

struct tnode *deleteList(struct tnode *head)
{
    while(head)
    {
        struct tnode *nast=head->next;
        free(head);
        head=nast;
    }
    return NULL;
}

void dodajRosnaco(struct tnode **head,int var)
{
    if(!(*head))
        return;

    struct tnode *newElement=malloc(sizeof(struct tnode));
    newElement->value=var;
    struct tnode *temp=*head;

    while(temp->next && temp->next->value<var)
        temp=temp->next;

    if(temp->next)
        newElement->next=temp->next;
    else
        newElement->next=NULL;

    temp->next=newElement;
}

int main()
{
struct tnode *head=NULL;

head=dodaj_na_poczatek(head,'z');
head=dodaj_na_poczatek(head,'k');
head=dodaj_na_poczatek(head,'j');
head=dodaj_na_poczatek(head,'a');
WypiszListe(head);

dodajRosnaco(&head,'w');
WypiszListe(head);

head=deleteList(head);
WypiszListe(head);

return 0;
}
