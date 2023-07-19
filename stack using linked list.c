//implementation of stack using Linked list
#include<stdio.h>

struct node
{
    int data;
    struct node* link;
}*top=0;
void push(int x)
{
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->link=top;
    top=newnode;
}
void display()
{
    struct node*temp;
    temp=top;
    if(top==0)
        printf("\nstack underflow!!\n");
    else
    {
        while(temp!=0)
        {
            printf("%d ",temp->data);
            temp=temp->link;
        }
    }
}
void topvalue()
{
    if(top==0)
    {
        printf("\nstack is empty.\n");
    }
    else
        printf("\nthe top element is %d",top->data);
}
void pop()
{
    struct node * temp;
    temp=top;
    if(top==0)
        printf("\nstack is empty.\n");
    else
    {
        top=top->link;
        free(temp);
    }
}
int main()
{
    int ch;
    int data;
    int choice;
    do {
tryagain:
        printf("\nenter your choice:\n");
        printf("\n1-->push");
        printf("\n2-->pop");
        printf("\n3-->display");
        printf("\n4-->display top value");

        printf("\n0-->exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\nenter data: ");
            scanf("%d",&data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            topvalue();
            break;
        case 0:
            exit(0);
            break;
        default :
            printf("\ninvalid choice!!! try again\n");
            goto tryagain;
        }
        printf("\ndo you want to continue<1/0>");
        scanf("%d",&choice);
    }
    while(choice);

    return 0;
}