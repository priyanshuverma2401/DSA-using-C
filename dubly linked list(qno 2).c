
//implementation of doubly linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node*next;
 struct node*prev;
};
struct node*head,*newnode;
struct node *tail;
void create()
{
 head=0;
 printf("\ncreating initial list\n");
 int data;
 printf("\nenter data\n");
 while(1)
 {
 newnode=(struct node*)malloc(sizeof(struct node));
 
 scanf("%d",&data);
 if(data==-1)
 break;
 else
 newnode->data =data;
 newnode->prev=0;
 newnode->next=0;
 if(head==0)
 {
 head=tail=newnode;
 }
 else
 {
 tail->next=newnode;
 newnode->prev=tail;
 tail=newnode;
 }
 }
 int l=getlength();
 printf("\nlist of %d element created successfully ",l);
}
void begdel()
{
 struct node *temp;
 if(head==0)
 {
 printf("\nlist is empty\n");
 }
 else
 {
 temp=head;
 head=head->next;
 head->prev=0;
 free(temp);
 }
 printf("\nelement deleted successfully\n");
}
void endel()
{
 struct node *temp;
 if(tail==0)
 {
 printf("\nlist is empty\n");
 }
 else
 {
 temp=tail;
 tail->prev->next=0;
 tail=tail->prev;
 free(temp);
 printf("\ndeleted from end successfully\n");
 }
 printf("\nelement deleted successfully\n");
}
void delpos()
{
 int pos,i=1;
 struct node*temp;
 temp=head;
 printf("enter position;\n");
 retry:
 scanf("%d",&pos);
 int l=getlength();
 if(pos>l || pos<1)
 {
 printf("\ninvalid position\n");
 printf("available range is 1 to %d",l);
 goto retry;
 }
 while(i<pos)
 {
 temp=temp->next;
 i++;
 }
 temp->prev->next=temp->next;
 temp->next->prev=temp->prev;
 free(temp);
 printf("\nelenlment deleted from pos %d",pos);
}
void beginsert()
{ 
 printf("\nEnter data:(to insert at beginning)\n");
 
 newnode=(struct node*)malloc(sizeof(struct node));
 int x;
 scanf("%d",&newnode->data);
 
 
 head->prev=newnode;
 newnode->next=head;
 head=newnode;
 printf("\nelement %d inserted successfully at beg\n",head->data);
}
void endinsert()
{ printf("\nenter data : (to insert at end of list)\n");
 
 newnode=(struct node*)malloc(sizeof(struct node));
 int y;
 scanf("%d",&y);
 
 newnode->data=y;
 tail->next=newnode;
 newnode->prev=tail;
 tail=newnode;
 printf("\nelement inserted successfully at end\n");
}
int getlength()
{
 struct node*trans;
 int length=1;
 trans=head;
 while(trans->next!=NULL)
 {
 trans=trans->next;
 length++;
 }
 return length;
}
void posinsert()
{
 int pos;
 printf("\nenter position\n");
re:
 scanf("%d",&pos);
 int l=getlength();
 if(pos>l || pos<1)
 {
 printf("\ninvalid position\n");
 printf("available range is 1 to %d",l);
 goto re;
 }
 else if(pos==1)
 {
 beginsert ();
 }
 else
 {
 int i=1;
 struct node*temp;
 temp=head;
 newnode=(struct node*)malloc(sizeof (struct node));
 printf("\nenter data to insert at pos %d",pos);
 scanf("%d",&newnode->data);
 while(i<pos-1)
 {
 temp=temp->next;
 i++;
 }
 newnode->prev=temp;
 newnode->next=temp->next;
 temp->next=newnode;
 newnode->next->prev=newnode;
 }
printf("element successfully inserted at pos %d",pos);
}
void display()
{
 printf("\n");
 struct node*temp;
 temp=head;
 while(temp!=NULL)
 {
 printf("%d ",temp->data);
 printf("--->");
 temp=temp->next;
 }
 printf("NULL");
}
int main()
{
 create();
again:
 printf("\nenter choice:\n"
 "1. insert beg\n"
 "2. insert end\n"
 "3. insert at position\n"
 "4. display\n"
 "5. delete from beginning\n"
 "6. delete from end\n"
 "7. delete from position\n"
 "0. exit\n");
 int ch;
 trygain:
 scanf("%d",&ch);
 switch(ch)
 {
 case 1:
 beginsert();
 break;
 case 2:
 endinsert();
 break;
 case 3:
 posinsert();
 break;
 case 4:
 display();
 break;
 case 5:
 begdel();
 break;
 case 6:
 endel();
 break;
 case 7:
 delpos();
 break;
 case 0:
 exit(0);
 break;
 default :
 printf("\nsomething went wrong tryagain:\n");
 goto trygain;
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
