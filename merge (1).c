//implementing merge sort
#include<stdio.h>
#include<stdlib.h>

void merge(int arr[],int beg,int mid,int end)
{
    int i,j,k;
    int n1=mid-beg+1;
    int n2=end-mid;
    int leftarr[n1];//temp array
    int rightarr[n2];//temp array
    for(i=0; i<n1; i++)//coping data to temp array
        leftarr[i]=arr[beg+i];
    for(j=0; j<n2; j++) //coping data to temp array
        rightarr[j]=arr[mid+1+j];
    i=0;
    j=0;
    k=beg;
    while(i<n1 && j<n2)
    {
        if(leftarr[i]<=rightarr[j])
        {
            arr[k]=leftarr[i];
            i++;
        }
        else
        {
            arr[k]=rightarr[j];
            j++;
        }
        k++; 
    }
    
    while(i<n1)
        {
            arr[k]=leftarr[i];
            i++;
            k++;
        }
    
        while(j<n2)
        {

            arr[k]=rightarr[j];
            j++;
            k++;
        }
     
}
void mergeSort(int arr[],int beg,int end)
    {
    
        if(beg<end)
        {
            int mid=(beg+end)/2;
            mergeSort(arr,beg,mid);
            mergeSort(arr,mid+1,end);
            merge(arr,beg,mid,end);
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
printf("\nenter the total number of element you want to sort\n");
int n;
scanf("%d",&n);
int arr[n];
//int*arr=(int*)malloc(sizeof(int));
printf("\nenter %d element: ",n);
int i;
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
printf("\n before sorting: \n");
printarr(arr,n);
mergeSort(arr,0,n-1);
printf("\n after sorting: \n");
printarr(arr,n);
return 0;
}
