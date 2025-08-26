// QUESTION :- Find the subset whose sum is equal to the given element.

#include <stdio.h>

void printSubsetsWithSum(int arr[], int n, int target) 
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

    printf("Subsets with sum = %d\n", target);
    for (int i = 0; i < count; i++) 
    {
        int sum = 0;
        for (int j = 0; j < subsetSize[i]; j++) 
        {
            sum += subset[i][j];
        }

        if (sum == target) 
        {
            printf("{ ");
            for (int j = 0; j < subsetSize[i]; j++) 
            {
                printf("%d ", subset[i][j]);
            }
            printf("}\n");
        }
    }
}

int main() 
{
    int arr[100], n, target;

    printf("Enter number of elements : ");
    scanf("%d", &n);

    printf("Enter Elements : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter target sum : ");
    scanf("%d", &target);

    printSubsetsWithSum(arr, n, target);

    return 0;
}
