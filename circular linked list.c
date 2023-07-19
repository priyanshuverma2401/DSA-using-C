//c code to implement circular linked list

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data ;
    struct node *next;
}*temp,*tail;

int getlength()
{
    int count=0;
    temp=tail->next;
    while(temp->next!=tail->next)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
void createCLL()
{
    printf("\ncreating initial list(press -1 to step out)");
    struct node*newnode;
    int x;
    printf("\nenter data: \n");
    while(1)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&x);
        if(x==-1)
            break;
        newnode->data=x;
        newnode->next=0;
        if(tail==0)
        {
            tail=newnode;
            tail->next=newnode;
        }
        else
        {
            newnode->next=tail->next;
            tail->next=newnode;
            tail=newnode;
        }
        
    }
}
void display()
{
    if(tail==0)
        printf("\nlist is empty.");
    else
    {
        temp=tail->next;
        while(temp->next!=tail->next)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
    }
}
void insertbeg()
{
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nenter data.");
    scanf("%d",&newnode->data);
    newnode->next=0;
    if(tail==0)
    {
        tail=newnode;
        tail->next=newnode;
    }
    else
    {
        newnode->next=tail->next;
        tail->next=newnode;
    }
}
void insertend()
{
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nenter data");
    scanf("%d",&newnode->data);
    newnode->next=0;
    if(tail==0)
    {
        tail=newnode;
        tail->next=newnode;
    }
    else
    {
        newnode->next=tail->next;
        tail->next=newnode;
        tail=newnode;
    }
}
void insertpos()
{
    int pos,len,i;
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nenter data ");
    scanf("%d",&newnode->data);
    newnode->next=0;
    if(tail==0)
    {
        tail=newnode;
        tail->next=newnode;
    }
    printf("\nenter position at which you want to insert\n");
    scanf("%d",&pos);
    len=getlength();
    if(pos<=0||pos>len)
        printf("\ninvalid position.");
    else if(pos==1)
        insertbeg();
    else
    {
        temp=tail->next;
        while(i<pos-2)
        {
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}
void deletebeg()
{
    temp=tail->next;
    if(tail==0)
        printf("\nlist is empty.");
    else if(temp->next==temp)
    {
        temp=tail;
        tail=0;
        free(temp);
    }
    else
    {
        temp=tail->next;
        tail->next=tail->next->next;
        free(temp);
    }
}
void deleteend()
{
    struct node *current,*previous;
    current=tail->next;
    if(tail==0)
    {
        printf("\nthe list is empty.");
    }
    else if(current->next=current)
    {
        tail=0;
        free(current);
    }
    else
    {
        while(current->next!=tail->next)
        {
            previous=current;
            current=current->next;
        }
        previous->next=tail->next;
        tail=previous;
        free(current);
    }
}
void deletepos()
{
    struct node*current,*nextnode;
    int pos,i=1,len;
    current=tail->next;
    len=getlength();
    printf("\nenter position:\n");
    scanf("%d",&pos);
    if(pos<=0||pos>len)
        printf("\ninvalid position");
    else if(pos==1)
        deletebeg();
    else
    {
        while(i<pos-1)
        {
            current=current->next;
            i++;
        }
        nextnode=current->next;
        current->next=nextnode->next;
        free(nextnode);
    }
}
int main()
{
    int ch,choice;
    createCLL();
    do {
tryagain:
        printf("\nenter choice: ");
        printf("\n1->insert at beginning");
        printf("\n2->insert at end ");
        printf("\n3->insert at position ");
        printf("\n4->delete from beginning ");
        printf("\n5->delete from end ");
        printf("\n6->delete from postion ");
        printf("\n7->display");
        printf("\n0->exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            insertbeg();
            break;
        case 2:
            insertend();
            break;
        case 3:
            insertpos();
            break;
        case 4:
            deletebeg();
            break;
        case 5:
            deleteend();
            break;
        case 6:
            deletepos();
            break;
        case 7:
            display();
            break;
        case 0:
            exit(0);
            break;
        default :
            printf("\ninvalid choice!!try again");
            goto tryagain;
        }
        printf("\ndo you want to continue<1/0>");
        scanf("%d",&choice);
    }
    while(choice);
    return 0;
}