// QUESTION :- Removes duplicate elements from the array and also print position of duplicates

#include<stdio.h>

int main()
{
    int arr[100],s[100],n,flag,m=0;

    printf("Enter no. of elements : ");
    scanf("%d",&n);
    printf("Enter elements : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        flag=0;
        for(int j=i+1;j<n;j++)
        {
            if (arr[i]==arr[j])
            {
                printf("Duplicate of element %d found at %d .\n",arr[i],j+1);
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            s[m]=arr[i];
            m++;
        }
    }
    printf("ARRAY : ");
    for(int i=0;i<m;i++)
    {
        printf("%d ",s[i]);
    }
    return 0;
}