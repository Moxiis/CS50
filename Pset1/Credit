#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long card = 0;
    int card_length = 0;
    long first_number = 0;
    long second_number = 0;
    long minus = 0;
    do
    {
        card = get_long("Put your credit card number\n");
        card_length = log10(card) + 1;
        long potega_pierwsza = pow(10, card_length - 1);
        long potega_druga = pow(10, card_length - 2);
        first_number = card / potega_pierwsza;
        second_number = card / potega_druga;
    }
    while (card <= 0);

    long test[16];
    int i = 0;
    while (i != card_length)
    {
        long potega = pow(10, i + 1);
        test[i] = card % potega;
        if (i == 0)
        {
            minus = 0;
        }
        else if (i == 1)
        {
            minus = test[i - 1];
        }
        else
        {
            minus += test[i - 1] * 10;
        }
        test[i] = test[i] - minus;
        if (i == 0)
        {
            test[i] = test[i];
        }
        else
        {
            test[i] /= pow(10, i);
        }
        //printf("liczba %i:%li\n",i,test[i]);
        i++;
    }
    int odd_numb = 0;
    int even_numb = 0;
    i = 0;
    while (i != card_length)
    {
        if (i % 2 == 0)
        {
            odd_numb += test[i];
            i++;
        }
        else
        {
            test[i] *= 2;
            if (test[i] > 9)
            {
                even_numb += test[i] % 10;
                even_numb += 1;
                i++;
            }
            else
            {
                even_numb += test[i];
                i++;
            }
        }
    }

    if ((even_numb + odd_numb) % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    if (first_number == 4 & card_length == 13 || first_number == 4 & card_length == 16 )
    {
        printf("VISA\n");
    }
    else if (second_number == 34 & card_length == 15 || second_number == 37 & card_length == 15)
    {
        printf("AMEX\n");
    }
    else if (second_number == 51 & card_length == 16 || second_number == 52 & card_length == 16
             || second_number == 53 & card_length == 16 || second_number == 54 & card_length == 16 || second_number == 55 & card_length == 16)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
