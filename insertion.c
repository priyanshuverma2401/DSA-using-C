#include<stdio.h>
#include<stdlib.h>

void insertionSort(int arr[],int n)
{
     int i,j,temp;
     for(i=1;i<n;i++)
     {
          temp=arr[i];
          j=i-1;
          while(j>=0&&temp<=arr[j])
          {
               arr[j+1]=arr[j];
               j--;
          }
          arr[j+1]=temp;
     }
     
}
void printarr(int arr[],int n)
{
     int i;
     for(i=0;i<n;i++)
     {
          printf("%d ",arr[i]);
     }
}
int main()
{
     printf("\neneter total number of element to be sorted\n");
     int n,i;
     scanf("%d",&n);
     int *arr=(int *)malloc(sizeof(int));
     printf("\n enter %d element",n);
     for(i=0;i<n;i++)
     {
          scanf("%d",&arr[i]);
     }
     printf("\nelements before sorting\n");
     printarr(arr,n);
     insertionSort(arr,n);
     printf("\nelements after sorting\n");
      printarr(arr,n);
      return 0;
}
