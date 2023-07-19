#include<stdio.h>
#include<stdlib.h>

int itr=0;
void insert(int arr[],int n)
{

    int element;
    printf("\nenter elements of an array\n");
    while(itr<n)
    {
        scanf("%d",&element);
        if(element==-1)
        {
            break;
        }
        arr[itr]=element;
        itr++;
    }
}
int linearSearch(int arr[],int size)
{
    int element;
    printf("\nenter element to be searched:  ");
    scanf("%d",&element);
    int i=0;
    int pos=0;
    for(; i<size; i++)
    {
        if(arr[i]==element)
        {
            printf("\nelement found successfully");
            pos=i+1;
            return pos;
        }
    }

    return pos;
}
int binarySearch(int brr[],int beg,int end,int val)
{
    int mid;
    if(end>=beg)
    {
        mid=(beg+end)/2;
        //if item to be searched is present at the middle of the array
        if(brr[mid]==val)
        {
            return mid+1;
        }
        else if(brr[mid]>val)
        {
            return binarySearch(brr,beg,mid-1,val);
        }
        else
        {
            return binarySearch(brr,beg,mid-1,val);
        }
    }
    return -1;
}
int main()
{
    printf("\nenter total number of element of an array that you are are going to store:\n");
    int n;
    int findPos;
    scanf("%d",&n);
    int *arr=(int*)malloc(n*sizeof(int));
    int xy=1;
    insert(arr,n);
    do
    {

        printf("\nwhich operation do you want to perform:");
retry:
        
        printf("\n1-->linear search");
        printf("\n2-->binary search");
        printf("\n0-->exit\n");
        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
        
            
            break;
        case 1:
            findPos=linearSearch(arr,n);
            if(findPos)

                printf("\nelement found at position :%d",findPos);
            else
                printf("\n element not found");

            break;

        case 2:
            printf("\nenter element to be searched: ");
            int ele;
            scanf("%d",&ele);
            findPos=binarySearch(arr,0,n-1,ele);
            if(findPos)
                printf("\nelement found at position :%d",findPos);
            else
                printf("\n element not found");
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("\ninvalid choice !! try again\n");
            goto retry;

        }
        printf("\ndo you want to continue:");
        scanf("%d",&xy);

    }
    while(xy==1);
    return 0;
}
