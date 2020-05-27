#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdarg.h>

struct tnode
{
    char slowo[10];
    int licznik;
    struct tnode *next;
};

struct tnode *dodajNapis(struct tnode *head,char *napis)
{
    struct tnode *temp=malloc(sizeof(struct tnode));
    temp->slowo[0]='\0';
    temp->licznik=1;
    strcat(temp->slowo,napis);
    temp->next=NULL;
    if(head)
    {
        if(strcmp(head->slowo,napis)>0)
        {
            temp->next=head;
            head=temp;
        }
        else
        {
            struct tnode *another=head;
            for(;another->next && strcmp(another->next->slowo,napis)<0;another=another->next);
            temp->next=another->next;
            another->next=temp;
        }
    }
    else
        head=temp;

    return head;
}

struct tnode *zwolnijListe(struct tnode *head)
{
    struct tnode *temp=head;
    while(temp)
    {
        head=temp->next;
        free(temp);
        temp=head;
    }

    return NULL;
}

void wypiszListe(struct tnode *head)
{
    while(head)
    {
        printf("%20s: %d\n",head->slowo,head->licznik);
        head=head->next;
    }
}

struct tnode *wyszukajListe(struct tnode *head,char *napis)
{
    for(;head && strcmp(head->slowo,napis);head=head->next);
    return head;
}

int main(int argc,char **argv)
{
	struct tnode *head=NULL;
    FILE *fp;

    if(fp=fopen(argv[1],"r"))
    {
        char buffor[10];
        while(fscanf(fp,"%s",buffor)!=EOF)
        {
            struct tnode *search=wyszukajListe(head,buffor);

            if(search)
                search->licznik+=1;
            else
                head=dodajNapis(head,buffor);

            buffor[0]='\0';
        }
        fclose(fp);
 
		wypiszListe(head);

		FILE *fp2;
		if(fp2=fopen("solution.txt","w"))
		{
		    struct tnode *temp=head;
		    char buffor[30];
		    for(;temp;temp=temp->next)
		    {
		        sprintf(buffor,"%20s: %d\n",temp->slowo,temp->licznik);
		        fprintf(fp2,buffor);
		        buffor[0]='\0';
		    }
		    fclose(fp2);
		}

		head=zwolnijListe(head);
	}

return 0;
}
