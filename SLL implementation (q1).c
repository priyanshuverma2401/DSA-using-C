//implementaton if singly LinkedIn list

#include<stdio.h>

struct node
{
    int data;
    struct node*next;
} *head,*tail,*temp;

int getlength()
{
    int count=0;
    temp=head;
    while(temp!=0)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

void createList()
{

    printf("\ncreating initial list:\n");
    struct node *newNode;
    head=0;
    int x;
    printf("enter data:(enter -1 to end the list)\n");
    while(1) {
        newNode=(struct node*)malloc(sizeof(struct node));

        scanf("%d",&x);
        if(x==-1)
            break;
        newNode->data=x;
        newNode->next=0;
        if(head==0)
        {
            head=tail=newNode;
        }
        else
        {
            tail->next=newNode;
            tail=newNode;
        }


    }

    printf("\nintial list created successfully.");

}

void display()
{
    printf("\n displaying list\n");
    temp=head;

    while (temp!=0)
    {

        printf("%d ",(*temp).data);
        printf("--->");
        temp=temp->next;
    }
    printf("null\n");
}

void insertBeg()
{
    struct node *newnode;
    printf("\ninserting data at begnning.\n");
    newnode =(struct node*) malloc(sizeof(struct node));
    printf("\nenter the data you want to enter:");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
    printf ("\n data inserted successfully at the beg. of the list\n");
}

void insertEnd()
{
    struct node *newnode;
    int x;
    printf("\ninserting data at the end \n");
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nenter the value you want to insert\n");
    scanf("%d",&x);
    newnode->data=x;
    newnode->next=0;
    temp=head;
    if(head==0)
        head=tail=newnode;
    else {
        while(temp->next!=0)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        printf("\n data inserted successfully at the end of the list\n");
    }
}

void insertPos()
{
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    int len=getlength();
    printf("\nenter position: ");
    int pos,i=1;
    scanf("%d",&pos);
    if(pos>len)
    {
        printf("\n invalid position:");
    }
    else
    {
        temp=head;
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        printf("\nenter data: ");
        scanf("%d",&newnode->data);
        newnode->next=temp->next;
        temp->next=newnode;
    }
}

void deleteBeg()
{
    temp=head;
    head=head->next;
    free(temp);
}

void deleteEnd()
{
    struct node * prevnode;
    temp=head;
    while(temp->next!=0)
    {
        prevnode=temp;
        temp=temp->next;
    }
    if(temp==head)
    {
        head=0;
    }
    else
    {
        prevnode->next=0;
    }
    free(temp);
}

void deletePos()
{
    struct node * nextnode;
    int pos,i=1;
    temp=head;
    printf("\nenter position :\n");
    scanf("%d",&pos);
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    nextnode=temp->next;
    temp->next=nextnode->next;
    free(nextnode);
}

int main()
{

    createList();
again:
    printf("\n enter your choice :\n");
    printf("1-> insert at begning\n"
           "2-> insert at end\n"
           "3->insert at position\n"
           "4->delete from beg\n"
           "5->delete from end\n"
           "6->delete from pos\n"
           "7-> display list\n"
           "0->exit\n");
    int ch;
tryAgain:
    scanf("%d",&ch);

    switch(ch)
    {
    case 1:
        insertBeg();
        break;
    case 2:
        insertEnd();
        break;
    case 3:
        insertPos();
        break;
    case 4:
        deleteBeg();
        break;
    case 5:
        deleteEnd();
        break;
    case 6:
        deletePos();
        break;
    case 7:
        display();
        break;
    case 0:
        exit(0);
        break;
    default :
        printf("\ninvalid choice: try again:\n");
        goto tryAgain;
    }

    printf("\n do you want to continue<0/1>\n");
    int c;
    scanf("%d",&c);

    switch(c)
    {
    case 1 :
        goto again;
        break;
    case 0:
        exit(0);
    default:
        printf("\n programme ended succesfully\n");
        exit(0);
    }

    return 0;
}
