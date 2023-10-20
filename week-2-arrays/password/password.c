// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{

    // declaring my booleans and setting them to false
    bool upper = false;
    bool lower = false;
    bool number = false;
    bool symbol = false;

    // iterating through the password "length" number of times
    for (int i = 0; i < strlen(password); i++)
    {
        char x = password[i];

        // checking if the character at that spot in the password is either uppercase, lowercase, a number or a symbol
        if (isupper(x))
        {
            upper = true;
        }
        else if (islower(x))
        {
            lower = true;
        }
        else if (isdigit(x))
        {
            number = true;
        }
        else if (ispunct(x))
        {
            symbol = true;
        }
    }

    // if the password contains all of the requirements, the function returns a true value
    if (upper == true && lower == true && number == true && symbol == true)
    {
        return true;
    }

    // otherwise the password is invalid
    else
    {
        return false;
    }
}
