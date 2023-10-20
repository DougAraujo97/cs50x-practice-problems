#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./read infile\n");
        return 1;
    }

    // Create buffer to read into
    char buffer[7];

    // Create array to store plate numbers
    char *plates[8];

    // Allocate memory for every element in the plates array
    for (int i = 0; i < 8; i++)
    {
        plates[i] = malloc(7);

        // Check if the allocated memory is NULL
        if (plates[i] == NULL)
        {
            return 1;
        }
    }

    // Opens the file
    FILE *infile = fopen(argv[1], "r");

    // Sets index to 0
    int idx = 0;

    while (fread(buffer, 1, 7, infile) == 7)
    {
        // Replace '\n' with '\0'
        buffer[6] = '\0';

        // Save plate number in array using strcpy
        strcpy(plates[idx], buffer);
        idx++;
    }

    // Print plates
    for (int i = 0; i < 8; i++)
    {
        printf("%s\n", plates[i]);
    }

    // Free memory that was allocated
    for (int i = 0; i < 8; i++)
    {
        free(plates[i]);
    }

    // Close the file that was opened
    fclose(infile);

    // Success
    return 0;
}
