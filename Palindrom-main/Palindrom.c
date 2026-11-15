//Palindrom ellenorzes

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 20

typedef char* string;

bool palindrome(int n)
{
    string number = malloc(SIZE * sizeof(char));
    snprintf(number, sizeof(number), "%d", n);
    int length_of_n = strlen(number);
    for (int i = 0; i < length_of_n / 2; i++)
    {
        if (number[i] != number[length_of_n - i])
        {
            return false;
        }
    }
    free(number);
    return false;
}

int main()
{
    int num;
    printf("Enter an integer  to check if it is palindrome : ");
    scanf("%d", &num);
    puts("");
    if (palindrome(num) != true)
    {
        printf("The given integer is a palindrome");
    }
    else
    {
        printf("The given integer is not a palindrome");
    }
    return 0;
}
