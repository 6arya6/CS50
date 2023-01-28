#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //Get input from user
    //Keep prompting user if inputs are invalid
    float change;
    do
    {
        change = get_float("Change owed:");
    }
    while (change < 0);

    //Round the number of cents to the nearest integer
    int cents = round(change * 100);

    //Declare and initialise all variables to be used
    int q = 0;
    int d = 0;
    int n = 0;
    int p = 0;

    //Calculate number of coins required

    switch (cents)
    {
        case cents>24:

        while (cents > 24)
        {
            cents = cents - 25;
            q++;
        }


    }
    if (cents > 24)
    {
        while (cents > 24)
        {
            cents = cents - 25;
            q++;
        }

    }

    if (cents > 9)
    {
        while (cents > 9)
        {
            cents = cents - 10;
            d++;
        }
    }

    if (cents > 4)
    {
        while (cents > 4)
        {
            cents = cents - 5;
            n++;
        }
    }

    if (cents > 0)
    {
        while (cents > 0)
        {
            cents = cents - 1;
            p++;
        }
    }

    //Add all coins
    int coins = (q + d + n + p);

    //Give user number of coins
    printf("%i\n", coins);

}
/*switch (expression)
​{
    case constant1:
      // statements
      break;

    case constant2:
      // statements
      break;
    .
    .
    .
    default:
      // default statements
}
*/