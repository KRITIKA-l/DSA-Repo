// QUESTION :- WAP to display array elements except first and last element. 

#include<stdio.h>
int main()
{
    int arr[10],i,n,j;
    printf("Enter the size of array:");
    scanf("%d",&n);
    printf("Enter the elements of array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=1;i<n-1;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}