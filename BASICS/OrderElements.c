// QUESTION :- Move all the zeros and -ve numbers to the end of the array and maintain the order of other elements.

#include <stdio.h>

int main() 
{
    int n, arr[100], temp[100], idx = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) 
        scanf("%d", &arr[i]);

    for (int i = 0; i < n; i++) 
        if (arr[i] > 0) 
            temp[idx++] = arr[i];

    for (int i = 0; i < n; i++) 
        if (arr[i] <= 0) 
            temp[idx++] = arr[i];

    for (int i = 0; i < n; i++) 
        arr[i] = temp[i];

    printf("Modified array: ");
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]);

    return 0;
}
