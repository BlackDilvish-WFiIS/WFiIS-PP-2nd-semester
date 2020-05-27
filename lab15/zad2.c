#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int value;
    struct tree *left;
    struct tree *right;
    struct tree *parent;
};

struct tree *createleaf(int var, struct tree *parent)
{
    struct tree *newTree=malloc(sizeof(struct tree));
    newTree->value=var;
    newTree->right=NULL;
    newTree->left=NULL;
    newTree->parent=parent;
    return newTree;
}

void Addleaf(int var,struct tree **root, struct tree *parent)
{
    if ((*root)==NULL)
    {
        (*root)=createleaf(var,parent);
    }
    else
    {
        if ((*root)->value<var)
        {
            Addleaf(var,&((*root)->right), (*root));
        }
        else
        {
            Addleaf(var,&((*root)->left), (*root));
        }
    }
}

void  in_order(struct tree *root)
{
    if(root->left != NULL)
        in_order(root->left);

    printf(" %d ",root->value);

    if(root->right != NULL)
        in_order(root->right);
}

void  pre_order(struct tree *root)
{
    printf(" %d ",root->value);
    if (root->left != NULL)
        pre_order(root->left);
    if (root->right != NULL)
        pre_order(root->right);

}


void deleteTree(struct tree *root)
{
    struct tree *temp;

    if (root!=NULL)
    {
        temp = root;
        deleteTree(root->left);
        deleteTree(root->right);
        free(temp);
    }

}

int main()
{
	int tab[]={15,5,16,20,3,12,18,23,10,13,6,7},i;
    struct tree *head=NULL;

    for(i=0;i<sizeof(tab)/sizeof(int);i++)
        Addleaf(tab[i],&head,head);

    in_order(head);
    printf("\n");
    pre_order(head);
	printf("\n");

	deleteTree(head);

	return 0;
}
