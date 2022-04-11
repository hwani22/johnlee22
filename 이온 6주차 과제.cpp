#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int div(int n) 
{
    int result = 1;
    while (n > 0) 
    {
        result = result * n;
        n--;
    }
    return result;
}

int main() 
{
    int n;
    int count = 0;
    int first_count;
    int second_count = 1;

    scanf("%d", &n);

    count++;
    while (second_count * 2 <= n) 
    {
        first_count = n - second_count * 2;
        count += div(n - second_count) / ((div(first_count)) * div(second_count));
        second_count++;
    }
    printf("%d\n", count);
}