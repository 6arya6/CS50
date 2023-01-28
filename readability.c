#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text1);
int count_words(string text2);
int count_sentences(string text3);

int main(void)
{
    //Get input from user
    string text = get_string("Text: ");

    //find number of letters, words and sentences in input
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    //Calculating Coleman-Liau index
    double L = ((double)letters / words) * 100;
    double S = ((double)sentences / words) * 100;

    double index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);

    //Print grade level on screen
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

//Making function to find letters
int count_letters(string text1)
{
    int lettercount = 0;
    for (int i = 0, n = strlen(text1) ; i < n ; i++)
    {
        char letter = text1[i] ;
        if (isalpha(letter))
        {
            lettercount++;
        }
    }
    return lettercount;
}

//Making function to find words
int count_words(string text2)
{
    int wordcount = 0;
    for (int i = 0, n = strlen(text2); i < n; i++)
    {
        if (isspace(text2[i]))
        {
            wordcount++;
        }
    }
    wordcount++;
    return wordcount;
}

//Making function to find sentences
int count_sentences(string text3)
{
    int sentencecount = 0;
    for (int i = 0, n = strlen(text3); i < n; i++)
    {
        if (text3[i] == 33 || text3[i] == 46 || text3[i] == 63) //ASCHII numbers for "!", "." and "?"
        {
            sentencecount++;
        }
    }
    return sentencecount;
}