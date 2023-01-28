#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char change_index(char letter, int key);

int main(int argc, string argv[])
{
    //Checking for valid command-line argument
    if (argc == 2)
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            //Checking if command-line arguments are digits
            if (isdigit(argv[1][i]))
            {
                int key = atoi(argv[1]);
                //Getting input from user
                string plaintext = get_string("plain text: ");
                printf("ciphertext: ");

                //Changing plaintext to ciphertext and printing ciphertext
                for (int j = 0, n2 = strlen(plaintext); j < n2; j++)
                {
                    char letter = plaintext[j];
                    printf("%c", change_index(letter, key));
                }
                printf("\n");
                return 0;

            }
            //Printing error message on invalid input from user
            else
            {
                printf("Usage: ./caeser key\n");
                return 2;
            }

        }
    }
    //Printing error message on invalid input from user
    else
    {
        printf("Usage: ./caeser key\n");
        return 1;
    }
}

//Making a function to encrypt text
char change_index(char letter, int key)
{
    //for lowercase alphabets
    if (islower(letter))
    {
        letter -= 'a';
        letter = (letter + key) % 26;
        letter += 'a';
        return letter;
    }
    //for uppercase alphabets
    else if (isupper(letter))
    {
        letter -= 'A';
        letter = (letter + key) % 26;
        letter += 'A';
        return letter;
    }
    //for special characters
    else
    {
        return letter;
    }

}