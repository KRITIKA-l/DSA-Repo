#include<stdio.h>
int main()
{
   int arr[100],n;
   printf("Enter number of elements : ");
   scanf("%d",&n);
   printf("Enter Elements : ");
   for (int i= 0; i<n ; i++)
   {
    scanf("%d",&arr[i]);
   }
   printf("REVERSED ARRAY : ");
   for(int i = n-1;i>=0;i--)
   {
    printf("%d ",arr[i]);
   }
   return 0;
}