//QUESTION -: Design a function that removes duplicate elements from the array of n integers c language.

#include<stdio.h>

int removeduplicate(int arr[],int n)
{
  for(int i=0;i<n;i++)
  {
   for(int j=i+1;j<n;j++)
   {
    if(arr[i]==arr[j])
    {
     for(int k=j;k<n-1;k++)
     {
      arr[k]=arr[k+1];
     }
     n--;
     j--;
    }
   }
  }
  return n;
}

int main()
{
 int arr[100],n,i;

 printf("Enter no. of elements:");
 scanf("%d",&n);

 printf("Enter %d elements:",n);
 for(i=0;i<n;i++)
 {
  scanf("%d",&arr[i]);
 }

 n=removeduplicate(arr,n);

 printf("Array after removing duplicates:\n");
 for(i=0;i<n;i++)
 {
  printf("%d ",arr[i]);
 }
 
 return 0;
//QUESTION -: Design a function that removes duplicate elements from the array of n integers c language.

#include<stdio.h>

int removeduplicate(int arr[],int n)
{
  for(int i=0;i<n;i++)
  {
   for(int j=i+1;j<n;j++)
   {
    if(arr[i]==arr[j])
    {
     for(int k=j;k<n-1;k++)
     {
      arr[k]=arr[k+1];
     }
     n--;
     j--;
    }
   }
  }
  return n;
}

int main()
{
 int arr[100],n,i;

 printf("Enter no. of elements:");
 scanf("%d",&n);

 printf("Enter %d elements:",n);
 for(i=0;i<n;i++)
 {
  scanf("%d",&arr[i]);
 }

 n=removeduplicate(arr,n);

 printf("Array after removing duplicates:\n");
 for(i=0;i<n;i++)
 {
  printf("%d ",arr[i]);
 }
 
 return 0;
}