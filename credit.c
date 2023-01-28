#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //Get input from user
    //Keep prompting user if inputs are invalid
    long n;
    do
    {
        n = get_long("Number:");
    }
    while (n < 0);

    //Calculate number of digits in number
    long digits = 0;
    long n_1 = n;

    while (n_1 != 0)
    {
        n_1 = n_1 / 10;
        digits++;
    }

    //Declare all variables
    long i;
    long d;
    long p;
    long sum_even = 0;
    long sum_odd = 0;
    long checksum = 0;

    //Calculating check sum
    for (i = 1; i < digits; i += 2)
    {
        p = pow(10, i + 1);

        d = n % p;

        d = d / (p * 0.1);

        d = d * 2;

        sum_even = sum_even + (d / 10) + (d % 10);
    }

    for (i = 0; i < digits; i += 2)
    {
        p = pow(10, i + 1);

        d = n % p;

        d = d / (p * 0.1);

        sum_odd = sum_odd + d;
    }

    checksum = sum_even + sum_odd;

    //Checking if card is valid or invalid
    if (checksum % 10 == 0)
    {
        //Checking if it is american express card
        if (digits == 15)
        {
            long p_1 = pow(10, digits - 2);

            if (n / p_1 == 34 || n / p_1 == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }

        //Checking if it is mastercard or visa card
        else if (digits == 16)
        {
            long p_2 = pow(10, digits - 2);

            long z = n / p_2;

            //Checking if it is a mastercard
            if (z < 56 && z > 50)
            {
                printf("MASTERCARD\n");
            }
            //Checking if it is a visa card
            else if (z < 50 && z > 39)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }

        //Checking if it is visa card
        else if (digits == 13)
        {
            long p_3 = pow(10, digits - 1);

            if (n / p_3 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }

        else
        {
            printf("INVALID\n");
        }


    }

    else
    {
        printf("INVALID\n");
    }
}