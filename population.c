#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int ss;
    do
    {
        ss = get_int("start size:");
    }
    while (ss < 9);

    // TODO: Prompt for end size
    int es;
    do
    {
        es = get_int("end size:");
    }
    while (es < ss);

    // TODO: Calculate number of years until we reach threshold
    int n;
    for (n = 0; ss < es; n++)
    {
        ss = ss + (ss / 3) - (ss / 4);

    }
    // TODO: Print number of years
    printf("Years: %i\n", n);
}