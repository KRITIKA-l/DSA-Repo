//QUESTION :- Print the Reverse of a number .

#include<stdio.h>

int main()
{
    int num,sign=1,rev=0,digit;

    printf("Enter a number : ");
    scanf("%d",&num);

    if (num<0)
    {
        sign = -1;
        num = -num;
    }
    while (num>0)
    {
        digit = num%10;
        rev=rev*10+digit;
        num=num/10;
    }

    rev = rev *sign;
    printf("Reversed Number : %d",rev);

    return 0;
}