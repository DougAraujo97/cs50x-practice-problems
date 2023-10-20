// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

// I included the ctype and string header files so i could convert the input word to lowercase letters and check the length of the input word
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string replace(string word);

int main(int argc, string argv[])
{

    // I realize this could just be if argc != 2, but this way you get more specific error messages
    if (argc == 1)
    {
        printf("ERROR: NOT ENOUGH COMMAND LINE ARGUMENTS!\n");
        return 1;
    }
    else if (argc > 2)
    {
        printf("ERROR: TOO MANY COMMAND LINE ARGUMENTS\n");
        return 1;
    }

    // Storing my leetspeech word in the "replacement" variable and printing it
    string replacement = replace(argv[1]);
    printf("%s\n", replacement);
}

string replace(string word)
{

    // declaring my output variable as of equal length to my input word
    string output = word;

    // checking input word length so I know how many iterations of my "for" loop I need
    int length = strlen(word);

    // checking every letter of the input word and swapping the vowels for numbers
    for (int i = 0; i < length; i++)
    {
        char a = tolower(word[i]);
        switch (a)
        {
        case 'a':
            output[i] = '6';
            break;

        case 'e':
            output[i] = '3';
            break;

        case 'i':
            output[i] = '1';
            break;

        case 'o':
            output[i] = '0';
            break;

        default:
            output[i] = word[i];
            break;
        }
    }
    return output;
}
