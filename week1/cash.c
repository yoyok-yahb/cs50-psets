#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Create integer by prompting user on how much change is owed by creating a loop to discard invalid inputs
    int money;
    do
    {
        money = get_int("Change owed: ");
    }
    while (money < 0);

    // Create integer to count the number of 25c coins owed
    int quarters = money / 25;
    // Create integer to carry forward remaining cash
    int rem_q = money % 25;

    // Do the same for 10c coins
    int dimes = rem_q / 10;
    int rem_d = rem_q % 10;

    // Do the same for 5c coins
    int nickles = rem_d / 5;
    int rem_n = rem_d % 5;

    int pennies = rem_n / 1;

    // Add the created integers to find the sum of number of coins owed
    int coins = quarters + dimes + nickles + pennies;
    printf("%i\n", coins);
}
