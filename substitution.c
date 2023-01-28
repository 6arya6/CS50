#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <strings.h>

int check_repeat(string input);
int check_alpha(string input);
int get_index(char letter);
string encipher(string text);

int main(int argc, string argv[])
{
    //Checking for valid format of command-line argument
    if (argc == 2)
    {
        //Checking for valid length of command-line argument
        if (strlen(argv[1]) == 26)
        {
            //Checking if command-line argument consists of alphabets only
            if (check_alpha(argv[1]) == 0)
            {
                //Checking if command-line argument doesn't have repeating characters
                if (check_repeat(argv[1]) == 1)
                {
                    //Printing error message on invalid input from user
                    printf("Key must not contain repeated characters\n");
                    return 1;
                }
                else
                {
                    //Making an array for substitution key
                    char key[26];
                    for (int a = 0; a < 26; a++)
                    {
                        key[a] = argv[1][a];
                    }

                    //Getting input from user
                    string plaintext = get_string("plaintext: ");


                    //Enciphering plaintext
                    for (int b = 0, n = strlen(plaintext); b < n; b++)
                    {
                        if (isalpha(plaintext[b]))
                        {
                            if (islower(plaintext[b]))
                            {
                                int index = get_index(plaintext[b]);
                                plaintext[b] = tolower(key[index]);
                            }
                            else
                            {
                                int index = get_index(plaintext[b]);
                                plaintext[b] = toupper(key[index]);
                            }
                        }

                    }
                    string ciphertext = plaintext;


                    //Printing ciphertext on screen
                    printf("ciphertext: %s\n", ciphertext);
                    return 0;
                }
            }
            //Printing error message on invalid input from user
            else
            {
                printf("Key must contain only alphabetical characters\n");
                return 1;
            }

        }
        //Printing error message on invalid input from user
        else
        {
            printf("Key must contain 26 characters\n");
            return 1;
        }

    }
    //Printing error message on invalid input from user
    else
    {
        printf("./substitution key\n");
        return 1;
    }
}

//Making a function for checking if input has repeating characters
int check_repeat(string input)
{
    int repeat = 0;
    for (int i = 0; i < 26; i++)
    {
        for (int j = (i + 1); j < 26; j++)
        {
            if (tolower(input[i]) == tolower(input[j]))
            {
                repeat = 1;
            }
        }
    }
    return repeat;
}

//Making a function for checking if input consists of alphabets
int check_alpha(string input)
{
    int alpha = 0;
    for (int k = 0; k < 26; k++)
    {
        if (!isalpha(input[k]))
        {
            alpha = 1;
        }
    }
    return alpha;
}

//Making a function to assign an index to each character of the key
int get_index(char letter)
{
    letter = tolower(letter);
    letter -= 'a';
    return letter;
}