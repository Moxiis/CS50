#include <cs50.h>
#include<stdio.h>

int main(void)
{
    int height = 0;
    do
    {
        height = get_int("Pyramide of what height do you want to create? \n");
    }
    while (height < 1 || height > 8);
    
    int j = 0;
    while (j < height)
    {
        int k = height - 1;
        for (int i = 0; i <= j;)
        {
            if (i + j < k)
            {
                printf(" ");
                k--;
            }
            else
            {
                printf("#");
                i++;
            }
        }         
        printf("  ");
        for (int i = 0; i <= j; i++)
        {
            printf("#");
        }
        printf("\n");
        j ++;
    }
}
