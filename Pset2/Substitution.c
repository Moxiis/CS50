#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool unique(string);
string change(string, string);

int main(int argc, string argv[])
{
    string text;
    int len;
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }
    len = strlen(argv[1]);
    if (len != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
    if (unique(argv[1]) != true)
    {
        printf("Key need to be unique\n");
        return 1;
    }

    text = get_string("type your text:");
    printf("ciphertext: %s\n", change(text, argv[1]));

}

bool unique(string x)
{
    int i = 0;
    int j = 0;
    bool check = true;
    while (i < strlen(x))
    {
        while (j < strlen(x))
        {
            if (i == j)
            {
                j++;
            }
            if (tolower(x[i]) == tolower(x[j]) || isalpha(x[i]) == 0)
            {
                check = false;
                return check;
            }
            else
            {
                j++;
            }

        }
        i++;
        j = i;
    }
    return check;
}

string change(string x, string y)
{
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    int i = 0;
    int j = 0;
    while (i != strlen(x))
    {
        if (tolower(x[i]) == alphabet[j])
        {    
            if (tolower(x[i]) == x[i])
            {
                x[i] = tolower(y[j]);
                i++;
                j = 0;
            }
            else
            {
                x[i] = toupper(y[j]);
                i++;
                j = 0;
            }
        }
        else if (isalpha(x[i]) == 0)
        {
            i++;   
        }
        else
        {
            j++;
        }
    }
    return x;
}
