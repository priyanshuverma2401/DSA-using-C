#include<stdio.h>

void display(int*,int);//display function prototype

//swapping two values
void swap(int *a,int*b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

//i is the node at which heapify function is called
heapify(int arr[],int n,int i)
{
int largest =i;//assume ith node largest
int l=(2*i)+1;//left child of ith node
int r=(2*i)+2;//right child of ith node

//compare node value with it's left child value
while((l<n) && (arr[l]>arr[largest]))
{
//if left value is greater 
    largest=l;//assign it's left value to largest
}
//compare node value with it's right child value
while((r<n) && (arr[r]>arr[largest]))
{
//if right value is greater 
    largest=r;//assign it's right value to largest
}

//if value of largest altered 
if(largest !=i)
{
 //swap value of largest child with node
    swap(&arr[largest],&arr[i]);
 //again recursively call heapify to it's node which is altered
    heapify(arr,n,largest);
}
}

//main heapSort function 
void heapSort(int arr[],int n)
{
int i=(floor(n/2))-1;//start loop with last internal node

//building Max heap
for(;i>=0;i--)
{
//call heapify for every internal node
heapify(arr,n,i);
}

//deleting root node every time from max heap
for(i=n-1;i>0;i--)
{
    swap(&arr[0],&arr[i]);
 //call heapify at root node after every deletion
    heapify(arr,i,0);
}
}

//function for displaying array
void display(int arr[],int n)
{
    int i=0;
    for(;i<n;i++)
    {
        printf("%d ",*(arr+i));
    }
}

//deriver function 
int main()
{
    int n,i;
    printf("\nenter the total no.of elements: ");
    scanf("%d",&n);
    int*arr=(int*)malloc(n*sizeof(int));//dynamically allocating array
    printf("\nenter elements: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",arr+i);
    }
    printf("\n array before sorting:\n");
    display(arr,n);
    heapSort(arr,n);
    printf("\n array after sorting:\n");
    display(arr,n);
    
    return 0;
}