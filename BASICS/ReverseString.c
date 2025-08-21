//QUESTION :- Print the String in Reversed order .

#include<stdio.h>
#include<string.h>

int main()
{
    char arr[100];

    printf("Enter String : ");
    gets(arr);

    printf("Reversed String : ");
    for ( int i =strlen(arr)-1 ;i>=0 ;i--)
    {
        printf("%c ",arr[i]);
    }

    return 0;
}