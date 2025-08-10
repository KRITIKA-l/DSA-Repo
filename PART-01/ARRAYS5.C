// Write a program that takes an array of integers as input and finds the majority element if it exists.
//  ~The majority element is the element that appears more than n/2 times in the array.
//  ~If no majority element exists, print the element with the highest frequency (most frequent element).
//  ~If multiple elements tie for highest frequency, print the one that appears last among them.

#include <stdio.h>
#include <stdbool.h> 

int majorityElement(int* nums, int numsSize) 
{
    int maxCount = 0;
    int element = -1;
    bool visited[numsSize];

    for (int i = 0; i < numsSize; i++)
        visited[i] = false;

    for (int i = 0; i < numsSize; i++) 
    {
        if (visited[i]) 
            continue;

        int count = 1;
        visited[i] = true;

        for (int j = i + 1; j < numsSize; j++) 
        {
            if (nums[i] == nums[j]) 
            {
                count++;
                visited[j] = true;
            }
        }

        if (count > numsSize / 2) 
        {
            return nums[i]; 
        }
        else if (count >= maxCount)
        {
            maxCount = count;
            element = nums[i];
        }
    }
    return element; 
}

int main() 
{
    int nums[100],size;
    printf("Enter no. of elements : ");
    scanf("%d",&size);
    printf("Enter elements : ");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&nums[i]);
    }
    int result = majorityElement(nums, size);
    if (result == -1)
        printf("No majority element exists.\n");
    else
        printf("Majority Element or Most Frequent Element: %d\n", result);

    return 0;
}

