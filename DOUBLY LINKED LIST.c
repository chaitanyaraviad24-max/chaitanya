#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *rlink;
    struct node *llink;
};
typedef struct node *NODE;

NODE insertRear(NODE first);
NODE insertFront(NODE first);
NODE deleteFront(NODE first);
NODE deleteRear(NODE first);
void display(NODE first);
int main()
{
    NODE first=NULL;
    int choice;
    for(;;)
    {
        printf("\n1.Insert at front\n2.Insert at rear\n3.Delete from front\n4.Delete from rear\n5.Display\n6.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:first=insertFront(first);
                   break;
            case 2:first=insertRear(first);
                   break;
            case 3:first=deleteFront(first);
                   break;
            case 4:first=deleteRear(first);
                   break;
            case 5:display(first);
                   break;
            case 6:exit(0);
            default:printf("Invalid choice\n");
        }
    }
    return 0;
}
NODE insertFront(NODE first)
{
    NODE newnode;
    int item;
    newnode=(NODE)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Memory not available\n");
        return first;
    }
    printf("Enter the item to be inserted : ");
    scanf("%d",&item);
    newnode->info=item;
    newnode->llink=NULL;
    newnode->rlink=NULL;
    if(first==NULL)
    {
        return newnode;
    }
    newnode->rlink=first;
    first->llink=newnode;
    return newnode;
}
NODE insertRear(NODE first)
{
    NODE newnode,cur;
    int item;
    newnode=(NODE)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Memory not available\n");
        return first;
    }
    printf("Enter the item to be inserted : ");
    scanf("%d",&item);
    newnode->info=item;
    newnode->llink=NULL;
    newnode->rlink=NULL;
    if(first==NULL)
    {
        return newnode;
    }
    cur=first;
    while(cur->rlink!=NULL)
    {
        cur=cur->rlink;
    }
    cur->rlink=newnode;
    newnode->llink=cur;
    return first;
}
NODE deleteFront(NODE first)
{
    NODE temp;
    if(first==NULL)
    {
        printf("List is empty\n");
        return first;
    }
    temp=first;
    first=first->rlink;
    if(first!=NULL)
        first->llink=NULL;
    printf("Deleted item is %d\n",temp->info);
    free(temp);
    return first;
}
NODE deleteRear(NODE first)
{
    NODE cur,temp;
    if(first==NULL)
    {
        printf("List is empty\n");
        return first;
    }
    if(first->rlink==NULL)
    {
        printf("Deleted item is %d\n",first->info);
        free(first);
        return NULL;
    }
    cur=first;
    while(cur->rlink!=NULL)
    {
        cur=cur->rlink;
    }
    temp=cur;
    cur->llink->rlink=NULL;
    printf("Deleted item is %d\n",temp->info);
    free(temp);
    return first;
}
void display(NODE first)
{
    NODE cur;
    if(first==NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("The elements in the list are : \n");
    cur=first;
    while(cur!=NULL)
    {
        printf("%d ",cur->info);
        cur=cur->rlink;
    }
    printf("\n");
}

