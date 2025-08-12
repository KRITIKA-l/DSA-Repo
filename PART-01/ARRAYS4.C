// QUESTION :- Implement Quicksort Algorithm .

#include<stdio.h>

int n;

int position(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low - 1;
    int j = high + 1;

    while (1) 
    {
        do 
        {
            i++;
        } while (a[i] < pivot);

        do 
        {
            j--;
        } while (a[j] > pivot);

        if (i >= j)
            return j;

        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}

void printArray(int a[])
{
    for (int i = 0; i < n; i++)
    {   
        printf("%d ", a[i]);
    }
    printf("\n");
}

void Quicksort(int a[], int low, int high)
{
    if (low < high)
    {
        int p = position(a, low, high);

        printf("After partition: ");
        printArray(a);

        Quicksort(a, low, p);
        Quicksort(a, p + 1, high);
    }
}

int main()
{
    int a[50];
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    Quicksort(a, 0, n - 1);

    printf("Sorted array: ");
    printArray(a);

    return 0; 
}
