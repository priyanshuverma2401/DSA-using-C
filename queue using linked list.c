//implementation of queue using linked list
#include<stdio.h>

struct node
{
    int data;
    struct node* link;
}*rear=0,*front=0;

void enqueue(int x)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->link=0;
    if(front==0&&rear==0)
    {
        front=rear=newnode;
    }
    else
    {
        rear->link=newnode;
        rear=newnode;
    }
}
void display()
{
    struct node* temp;
    if(front==0&&rear==0)
    {
        printf("\nqueue is empty.\n");
    }
    else
    {
        temp=front;
        while(temp!=0)
        {
            printf("%d ",temp->data);
            temp=temp->link ;
        }
    }
}
void dequeue()
{
    if(front==rear==0)
        printf("\nqueue is empty.\n");
    else
    {
        struct node* temp=front;
        front=front->link;
        free(temp);
    }
}
void peak()
{
    if(front==0&&rear==0)
    {
        printf("\nqueue is empty.\n");
    }
    else
    {
        printf("\nthe peak value is: %d",front->data);
    }
}
int main()
{
    int ch,choice,data;
    do {
tryagain:
        printf("\nenter your choice.\n");
        printf("\n1-->enqueue");
        printf("\n2-->dequeue");
        printf("\n3-->display");
        printf("\n4-->display peak value");
        printf("\n0-->exit");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\nenter data: ");
            scanf("%d",&data);
            enqueue(data);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            peak();
            break;
        case 5:
            exit(0);
        default :
            printf("\ninvalid choice!!try again.");
            goto tryagain;
        }
        printf("\ndo you to continue: (1/0)");
        scanf("%d",&choice);
    }
    while(choice);
    return 0;
}