#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;


int valid(int argc);
char *filename;
FILE *jpg;


int main(int argc, char *argv[])
{
    valid(argc);
    FILE *file = fopen(argv[1], "r");
    int j = 0;
    BYTE *bufor = malloc(512);

    while (fread(bufor, 1, 512, file) != 0)
    {
        if (bufor[0] == 0xff && bufor[1] == 0xd8 && bufor[2] == 0xff && (bufor[3] & 0xf0) == 0xe0)
        {
            if (j != 0)
            {
                fclose(jpg);
                free(filename);
            }
            filename = malloc(8);
            sprintf(filename, "%03i.jpg", j);
            jpg = fopen(filename, "w");
            fwrite(bufor, 1, 512, jpg);
            free(bufor);
            bufor = malloc(512);
            j++;
        }
        else
        {
            if (j == 0)
            {
                continue;
            }
            fwrite(bufor, 1, 512, jpg);
            free(bufor);
            bufor = malloc(512);
        }


    }
    free(bufor);
    fclose(file);
    return 0;
}




int valid(int argc)
{
    if (argc != 2)
    {
        printf("Invalid name of the file\n");
        exit(1);
    }
    return 1;
}



