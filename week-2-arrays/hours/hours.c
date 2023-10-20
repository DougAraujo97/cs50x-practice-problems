#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

// declaring the calc_hours function
float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    // prompting user for number of weeks
    int weeks = get_int("Number of weeks taking CS50: ");

    // allocating "weeks" amount of slots for the hours array
    int hours[weeks];

    // allocating user prompted values into each array slot
    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    // promtping user for either a 'T' or an 'A' and making the letters uppercase if needed
    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    } while (output != 'T' && output != 'A');

    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// TODO: complete the calc_hours function
float calc_hours(int hours[], int weeks, char output)
{
    // initializing my sum variable to 0
    int sum = 0;

    // cycling through every array slot and adding that value to the sum
    for (int x = 0; x < weeks; x++)
    {
        sum += hours[x];
    }

    // returning the sum if the user typed 'T'
    if (output == 'T')
    {
        return sum;
    }

    // returning the average hours as a float if the user typed 'A'
    else
    {
        return (float)sum / weeks;
    }
}