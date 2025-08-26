// QUESTION :- Find the Powerset of the elements of the array. 

#include <stdio.h>

void printPowerset(int arr[], int n) 
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

    
    for (int i = 0; i < count; i++) 
    {
        printf("{ ");
        for (int j = 0; j < subsetSize[i]; j++) 
        {
            printf("%d ", subset[i][j]);
        }
        printf("}\n");
    }
}

int main() 
{
    int arr[100], n;

    printf("Enter number of elements : ");
    scanf("%d",&n);
    printf("Enter Elements : ");
    for (int i= 0; i<n ; i++)
    {
        scanf("%d",&arr[i]);
    }

    printPowerset(arr, n);
    return 0;
}
