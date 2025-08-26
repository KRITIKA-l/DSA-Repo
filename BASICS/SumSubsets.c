// QUESTION :- Find the sum of all the subsets of the array.

#include <stdio.h>

void sumOfSubsets(int arr[], int n) 
{
    int subset[100][100];
    int subsetSize[100];
    int count = 1;
    subsetSize[0] = 0;

    for (int i = 0; i < n; i++) 
    {
        int currCount = count;
        for (int j = 0; j < currCount; j++) 
        {
            for (int k = 0; k < subsetSize[j]; k++) 
            {
                subset[count][k] = subset[j][k];
            }
            subset[count][subsetSize[j]] = arr[i];
            subsetSize[count] = subsetSize[j] + 1;
            count++;
        }
    }

    int totalSum = 0;
    for (int i = 0; i < count; i++) 
    {
        int sum = 0;
        printf("{ ");
        for (int j = 0; j < subsetSize[i]; j++) 
        {
            printf("%d ", subset[i][j]);
            sum += subset[i][j];
        }
        printf("} : Sum = %d\n", sum);
        totalSum += sum;
    }
    printf("Total sum of all subsets = %d\n", totalSum);
}

int main() 
{
    int arr[100], n;
    printf("Enter number of elements : ");
    scanf("%d", &n);
    printf("Enter Elements : ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    sumOfSubsets(arr, n);
    return 0;
}
