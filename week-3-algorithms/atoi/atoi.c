#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // Defining a variable n for the length of the input
    int n = strlen(input);

    // base case returns the int value of whatever single character
    // left in the input
    if (n == 1)
    {
        return input[0] - 48;
    }

    // defining a variable for the last character in the string
    char last_char = input[n - 1];

    // Defining a variable for the converted last character
    int new_last_char = last_char - 48;

    // shifting the \0 over to the left
    input[n - 1] = '\0';

    // returning the converted int value of the initial string
    return new_last_char + (10 * convert(input));
}