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

void dodaj_na_koniec(struct tnode **head,char var)
{
	struct tnode *temp;
	for(;temp;temp=temp->next);
	

}

int main()
{
	struct tnode *head=NULL;
	head=dodaj_na_poczatek(head,'a');
	head=dodaj_na_poczatek(head,'c');
	head=dodaj_na_poczatek(head,'v');
	head=dodaj_na_poczatek(head,'f');
	head=dodaj_na_poczatek(head,'t');
	WypiszListe(head);
	head=deleteList(head);	
	WypiszListe(head);
	return 0;
}
