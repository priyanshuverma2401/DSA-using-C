//implementing circlar queue using array
#include<stdio.h>
#define max 6
int queue[max];
int front =-1;
int rear =-1;
void enqueue(int ele)
{
	if((front==-1)&&(rear==-1))
	{
		front=rear=0;
		queue[rear]	= ele;
		
	}	
	else if((rear+1)%max==front){
		printf("\nqueue is full!!!\n");
		}
		else 
		{
			rear=(rear+1)%max;
			queue[rear]=ele;
		}
		printf("%d is enqueued into the queue at position a[%d].\n",ele,rear);
}
int dequeue()
{
	if((front==-1)&&(rear==-1))
	{
		printf("\nqueue is empty!!!\n");
		
	}
	else if(front==rear)
	{
		printf("\ndequeued element is %d",queue[front]);
		front=-1;
		rear=-1;
	}
	else
	{
		printf("\ndequeued element is %d",queue[front]);
		front = (front+1)%max;
	}
}
void display()
{
	int i=front;
	if((front==-1)&&(rear==-1))
	{
		printf("\nqueue is empty!!!\n");
		return ;
	}
	printf("\nelements present in queue are as :\n");
	while(i<=rear)
	{
		printf("%d\t",queue[i]);
		i=(i+1)%max;
	}

}
int main()
{
int ch;
int data;
int choice;
do{
tryagain:
printf("\nneter choice: ");
printf("\n1->enqueue ");
printf("\n2->dequeue");
printf("\n3->display\n ");
printf("\n0->exit\n ");
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
    case 0:
    exit(0);
    default :
    printf("\ninvalid choice!!try again. ");
    goto tryagain;
    
}
printf("\ndo you want to continue:<1/0>");
scanf("%d",&choice);
}
while(choice);

	return 0;

}
