// QUESTION :- Implement Quick Sort Algorithm .

#include<stdio.h>

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

void Quicksort(int a[], int low, int high)
{
    if(low < high)
    {
        int p = position(a, low, high);
        Quicksort(a, low, p);
        Quicksort(a, p+1, high);
    }
}

int main()
{
    int a[50], n;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    Quicksort(a, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0; 
}