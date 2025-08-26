// QUESTION :- Find the majority element of the array.

#include <stdio.h>

int main() 
{
    int n, arr[100];
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) 
        scanf("%d", &arr[i]);

    int maxCount = 0, element = arr[0];

    for (int i = 0; i < n; i++) 
    {
        int count = 0;
        for (int j = 0; j < n; j++) 
        {
            if (arr[j] == arr[i]) 
                count++;
        }
        if (count > maxCount) 
        {
            maxCount = count;
            element = arr[i];
        }
    }

    printf("Element occurring maximum times = %d\n", element);
    printf("It occurs %d times\n", maxCount);

    return 0;
}
