#include<time.h>
#include<iostream>
#include<cstdlib>
using namespace std;

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[],int low,int high)
{
    int i=low-1;
    int pivot=arr[high];
    
    for(int j=low;j<=high-1;j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}

int partition_r(int arr[],int low,int high)
{
    srand(time(NULL));
    int random=low+ rand() % (high-low);
    swap(&arr[random],&arr[high]);
    
    return partition(arr,low,high);
}
void quicksort(int arr[],int low,int high)
{
    if(low<high)
    {
        int p=partition_r(arr,low,high);
        quicksort(arr,low,p-1);
        quicksort(arr,p+1,high);
    }
}
int main()
{
    int n;
    cout<<"\nEnter size of array= ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter elements of array= ";
        cin>>arr[i];
    }
    quicksort(arr,0,n-1);
    cout<<"\nAfter sorting= ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
