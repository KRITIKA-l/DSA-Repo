//QUESTION :- Find the second and third largest number in a array.

#include<stdio.h>
#include<limits.h>

int main()
{
 int n,arr[100];
 int i,fmax,smax,tmax;

 printf("Enter no. of elements :");
 scanf("%d",&n);
 printf("Enter %d elements :",n);
 for(i=0;i<n;i++)
 {
  scanf("%d",&arr[i]);
 }

 fmax=smax=tmax=INT_MIN;
 for(i=0;i<n;i++)
 {

  if (fmax<arr[i])
  {
    tmax = smax;
    smax = fmax;
    fmax = arr[i];
  }

  else if (smax<arr[i] && arr[i]<fmax)
  {
    tmax = smax;
    smax = arr[i];
  }

  else if(tmax<arr[i] && arr[i]<smax)
  {
    tmax=arr[i];
  }
 }

 printf("Largest no. in Array :%d\n",fmax);
 printf("Second Largest no. in Array :%d\n",smax);
 printf("Third Largest no. in Array:%d\n",tmax);

 return 0;
}