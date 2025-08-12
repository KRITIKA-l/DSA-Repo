// QUESTION :- Search the given element in the arrray and print the location/position of the element.

#include<stdio.h>

int main()
{
    int arr[100],n,target;

    printf("Enter no. of elements : ");
    scanf("%d",&n);
    printf("Enter elements : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter Element to search : ");
    scanf("%d",&target);

    for(int i=0;i<n;i++)
    {
        if (arr[i]==target)
        {
            printf("Target %d found at %d.\n",target,i+1);
        }
    }
    return 0;
}