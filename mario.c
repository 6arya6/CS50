#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Prompt user for height
    int h;
    //Keep prompting user for invalid heights
    do
    {
        h = get_int("Height:");
    }
    while (h < 1 || h > 8);

    //Make pyramid

    //Declaring all variables
    int i;
    int j;
    int k;
    int l;
    int m;

    //Loops for creating pattern
    for (i = 0; i < h ; i++)
    {
        j = i;
        j++;

        for (k = 0; k < (h - j); k++)
        {
            printf(" ");
        }

        for (l = 0; l < j; l++)
        {
            printf("#");
        }

        printf("  ");

        for (m = 0; m < j; m++)
        {
            printf("#");
        }

        printf("\n");

    }
}