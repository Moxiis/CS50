// Implements a dictionary's functionality
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "dictionary.h"

// Number of words in dictionary
int count;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// node creation funciton
node *node_creation(char *);

// Number of buckets in hash table
const unsigned int N = 65536;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    node *cursor = table[hash(word)];
    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int hash_value = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        hash_value = (hash_value << 2) ^ tolower(word[i]);
    }
    return hash_value % N; //N is size of hashtable
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // #1 OPEN FILE
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Not able to open file\n");
        return false;
    }

    // #2 "SCAN THE FILE"
    char word_File[LENGTH + 1];
    while (fscanf(file, "%s", word_File) != EOF)
    {
        //counter for size()
        count++;
        // #3 CREATING NEW NODE
        node *new_node = node_creation(word_File);

        // #4 WORD HASH AND #5 ADDING NEW_NODE TO HASH TABLE
        new_node->next = table[hash(word_File)];
        table[hash(word_File)] = new_node;

    }

    // CLOSE FILE
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (count != 0)
    {
        return count;
    }
    else
    {
        return 0;
    }
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *pointer = table[i];
        node *tmp = pointer;
        while (pointer != NULL)
        {
            pointer = pointer->next;
            free(tmp);
            tmp = pointer;
        }
    }
    return true;
    //return false;
}


node *node_creation(char *word_File)
{
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        printf("Malloc error\n");
        unload();
        exit(2);
    }
    strcpy(new_node -> word, word_File);
    new_node -> next = NULL;
    return new_node;
}
