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

struct tnode *odwrocListe(struct tnode *head)
{
    struct tnode *akt=head,*nast=NULL,*pop=NULL;

    while(akt)
    {
        nast=akt->next;
        akt->next=pop;
        pop=akt;
        akt=nast;
    }

    return pop;
}

int main(){
	
struct tnode *head = NULL;

WypiszListe(head);

head = 	dodaj_na_poczatek (head, 'f');
head = 	dodaj_na_poczatek (head, 'd');
head = 	dodaj_na_poczatek (head, 'u');
head = 	dodaj_na_poczatek (head, 'i');	

WypiszListe(head);

head=odwrocListe(head);

WypiszListe(head);

deleteList(head);	

return 0;
}
