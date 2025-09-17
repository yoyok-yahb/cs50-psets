#include <cs50.h>
#include <stdio.h>

// Create the function row that takes h and i as parameters
void row(int h, int i);

int main(void)
{
    // Declare the variable for height
    int height;

    // Create a do-while loop to only accept input between 1 and 8 and prompt user for height
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Create integers h and i
    int h = height - 1;
    int i = 0;

    // Create a loop which runs until given height is reached
    while (h >= 0 && i < height)
    {
        row(h, i);

        // h decreases and i increases every time the loop runs
        h--;
        i++;

        // Move to the next line to create a new row
        printf("\n");
    }
}

// Define the function row
void row(int h, int i)
{
    // Make a loop to keep printing space until the value of h is reached for that row
    for (int s = 1; s <= h; s++)
    {
        printf(" ");
    }

    // Make a loop to keep printing # until the value of i is reached for that row
    for (int a = 0; a <= i; a++)
    {
        printf("#");
    }

    // Print double space between the pyramid
    printf("  ");

    // Make the loop to print second set of #s
    for (int b = 0; b <= i; b++)
    {
        printf("#");
    }
}
