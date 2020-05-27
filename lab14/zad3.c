#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

struct tnode *searchList(struct tnode *head,int var)
{
    for(;head&&head->value!=var;head=head->next);
    return head;
}

struct tnode *usunJeden(struct tnode *head,int var)
{
    struct tnode *curr=head,*prev=NULL;
    for(;curr&&curr->value!=var;prev=curr,curr=curr->next);

    if(!curr)
        return head;
    if(!prev)
        head=head->next;
    else
        prev->next=curr->next;
    free(curr);
    return head;
}

struct tnode *usun(struct tnode **wsk,int var)
{
    struct tnode *deletedElements=NULL;
    struct tnode *tempHead=*wsk;
    struct tnode *found=NULL;

    while((found=searchList(tempHead,tolower(var)))|| (found=searchList(tempHead,toupper(var))))
    {
        deletedElements=dodaj_na_poczatek(deletedElements,found->value);
        *wsk=usunJeden(tempHead,found->value);
        tempHead=*wsk;
    }

    return deletedElements;
}

int main()
{
struct tnode *head=NULL,*left=NULL;
head=dodaj_na_poczatek(head,'A');
head=dodaj_na_poczatek(head,'l');
head=dodaj_na_poczatek(head,'a');
head=dodaj_na_poczatek(head,' ');
head=dodaj_na_poczatek(head,'m');
head=dodaj_na_poczatek(head,'a');
head=dodaj_na_poczatek(head,' ');
head=dodaj_na_poczatek(head,'k');
head=dodaj_na_poczatek(head,'o');
head=dodaj_na_poczatek(head,'t');
head=dodaj_na_poczatek(head,'a');

printf("head -> ");WypiszListe(head);
left=usun(&head,'a');
printf("head -> ");WypiszListe(head);
printf("left -> ");WypiszListe(left);

head=deleteList(head);
left=deleteList(head);
printf("head -> ");WypiszListe(head);
printf("left -> ");WypiszListe(left);

return 0;
}
