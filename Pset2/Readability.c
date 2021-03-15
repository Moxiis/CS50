#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int letters(int, string);
int words(int, string);
int sentences(int, string);
int grade(float, float, float);

int main(void)
{
    string text = get_string("Text:");
    int length = strlen(text);
    if (grade(letters(length, text), sentences(length, text), words(length, text)) > 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade(letters(length, text), sentences(length, text), words(length, text)) < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", grade(letters(length, text), sentences(length, text), words(length, text)));
    }
}

int letters(int x, string y)
{
    int i = 0, letter = 0;
    while (i != x)
    {
        if (isalpha(y[i]) != 0)
        {
            letter++;
            i++;
        }
        else
        {
            i++;
        }
    }
    return letter;
}

int words(int x, string y)
{
    int i = 0, word = 0;
    while (i != x)
    {
        if (isspace(y[i]) != 0)
        {
            word++;
            i++;
        }
        else
        {
            i++;
        }
    }
    word++;
    return word;
}

int sentences(int x, string y)
{
    int i = 0, sentence = 0;
    while (i != x)
    {
        if (y[i] == '.' || y[i] == '!' || y[i] == '?')
        {
            sentence++;
            i++;
        }
        else
        {
           i++;
        }
    }
    return sentence;
}

int grade(float x, float y, float z)
{
    float l = (x * 100) / z;
    float s = (y * 100) / z;
    float rate  = (0.0588 * l) - (0.296 * s) - 15.8;
    rate =  round(rate);
    return rate;
}
