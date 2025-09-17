#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompts the user for their name
    string name = get_string("What's your name? ");

    // Says hello to the user with the name they entered
    printf("Hello, %s\n", name);
}