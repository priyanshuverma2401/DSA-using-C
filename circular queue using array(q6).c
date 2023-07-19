//write a c programme to implement circular array using array

#include<stdio.h>
#define size 10
int queue[size];//array declared
int front =-1;
int rear=-1;
void enqueue()
{
     printf("\nenter element to be inserted: ");
     while(1)
     {
     
     int element;
     scanf("%d",&element);
     if(element==-1)
     {
          break;
     }
     else if(front==-1&&rear==-1)
     {
          front=0;
          rear=0;
          queue[rear]=element;
     }
     else if((rear+1)%size==front)
     {
          printf("\nqueue is full\n");
     }
     else
     {
          rear=(rear+1)%size;
          queue[rear]=element;
     }
 }
}
int dequeue()
{
     if((front==-1)&&(rear==-1))
     {
          printf("\nqueue is in underflow condition\n");
          
     }
     else if(front==rear)
     {
          printf("\ndequeued element is %d",queue[front]);
          front=-1;
          rear=-1;
     }
     else
     {
          printf("\nthe dequeued element is %d",queue[front]);
          front=(front+1)%size;
     }
}
void display()
{
     int i=front;
     if(front==rear==-1)
     {
          printf("\nqueue is empty\n");
     }
     else
     {
          printf("\nelements in the queue are:");
          while(i<=rear)
          {
               printf("%d ",queue[i]);
               i=(i+1)%size;
          }
     }
}
int main()
{
     while(1)
     {
 printf("\nWhich operation do you want to perform:\n");
 retry:
 printf("\n1-->enqueue");
 printf("\n2-->dequeue");
 printf("\n3-->display");
 printf("\n0-->exit");
 int choice;
 scanf("%d",&choice);
 switch(choice)
 {
      case 1:
             enqueue();
             break;
      case 2:
           dequeue();
           break;
      case 3:
           display();
           break;
      case 0:
           exit(0);
           break;
      default:
           printf("\ninvalid choice !! try again\n");
           goto retry;
           
 }
}
return 0;
}

