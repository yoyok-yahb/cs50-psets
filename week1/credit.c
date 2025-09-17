#include <cs50.h>
#include <math.h>
#include <stdio.h>

// Declare max card number limit as a constant integer
const int N = 16;

// Prototype functions
void check_bank(int digit[]);
int check_sum(int n, int digits[]);

int main(void)
{
    // Prompt the user for credit card number
    long credit = get_long("Number: ");

    // Give out numbers to the right of every place
    long place_right[17];
    for (int i = 0; i <= N; i++)
    {
        place_right[i] = credit % (long) pow(10, i);
    }

    // Use the previous value to give out digits for each place of the number
    int place[N];
    for (int i = 1; i <= N; i++)
    {
        place[i] = (place_right[i] - place_right[i - 1]) / pow(10, i - 1);
    }

    int sum = check_sum(N, place);

    // Check the validity of number
    if (sum % 10 == 0)
    {
        // For valid number check type of bank it belongs to
        check_bank(place);
    }
    else
    {
        printf("INVALID\n");
    }
}

void check_bank(int digit[])
{
    if (digit[16] == 4)
    {
        printf("VISA\n");
    }
    else if (digit[16] == 0 && digit[15] == 0 && digit[14] == 0 && digit[13] == 4)
    {
        printf("VISA\n");
    }
    else if (digit[16] == 0 && digit[15] == 3 && digit[14] == 4)
    {
        printf("AMEX\n");
    }
    else if (digit[16] == 0 && digit[15] == 3 && digit[14] == 7)
    {
        printf("AMEX\n");
    }
    else if (digit[16] == 5 && digit[15] >= 1 && digit[15] <= 5)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

int check_sum(int n, int digit[])
{
    int evenx2[n], evenx2_p1[n], evenx2_p2[n];
    for (int i = 1; i <= n; i++)
    {
        // Multiply the digits by 2
        evenx2[i] = digit[i] * 2;

        // Find out first place digit of the 2x number
        evenx2_p1[i] = evenx2[i] % 10;

        // Find out second place digit of the 2x number
        evenx2_p2[i] = (evenx2[i] - evenx2_p1[i]) / 10;
    }

    // Find out the sum of digits of 2x even place digits
    int sum_p1 = 0;
    int sum_p2 = 0;
    for (int i = 2; i <= n; i += 2)
    {
        sum_p1 += evenx2_p1[i];
        sum_p2 += evenx2_p2[i];
    }
    int sum_even = sum_p1 + sum_p2;

    // Find out the sum of odd place digits
    int sum_odd = 0;
    for (int i = 1; i < n; i += 2)
    {
        sum_odd += digit[i];
    }

    // Add even and odd place sums-
    int sum = sum_odd + sum_even;

    // return the sum to main function
    return sum;
}
