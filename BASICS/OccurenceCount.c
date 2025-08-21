//QUESTION :- Count the occurences of each element of the given element.

#include<stdio.h>

int main()
{
    int arr[100], n, count;

    printf("Enter number of elements : ");
    scanf("%d",&n);
    printf("Enter Elements : ");
    for (int i= 0; i<n ; i++)
    {
        scanf("%d",&arr[i]);
    }

    for(int i =0; i<n; i++)
    {
        int flag =0;
        for (int k =0 ; k<i;k++)
        {
            if(arr[i]==arr[k])
            {
                flag = 1;
                break;
            }
        }

        if (flag)
        {
            continue;
        }

        count = 1;
        for(int j =i+1; j<n; j++)
        {
            if(arr[i]==arr[j])
            {
                count++;
            }
        }

        printf("%d is appearing %d times.\n",arr[i],count);
    }

    return 0;
}