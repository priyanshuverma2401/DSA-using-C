// c programme to implement bubble sort
#include<stdio.h>
#include<stdlib.h>
void swap(int*x,int *y)
{
     int temp=*x;
     *x=*y;
     *y=temp;
}
void Bsort(int arr[],int n)
{
     int i,j;
     for(i=0;i<n-1;i++)
     {
          for(j=0;j<n-i-1;j++)
          {
               if(arr[j]>arr[j+1])
               {
                    swap(&arr[j],&arr[j+1]);
               }
          }
     }
     
}
void getdata(int*arr,int n)
{
     int i=0;
     printf("\n enter element of an array:");
     
     while(i<n)
     {
          scanf("%d",arr+i);
          i++;
     }
     
}
void display(int *ptr,int n)
{
     int i=0;
     printf("elements of the array are:\n");
     while(i<n)
     {
          printf("%d ",*(ptr+i));
          i++;
     }
     
}
int main()
{
     printf("\nenter the total number of element: ");
     int n;
     scanf("%d",&n);
     int *arr=(int*)malloc(n*sizeof(int));
     getdata(arr,n);
     printf("\nbefore sorting: ");
     display(arr,n);
     Bsort(arr,n);
     printf("\nafter sorting:\n");
     display(arr,n);
     return 0;
     
}
