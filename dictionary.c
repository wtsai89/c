// Implements a dictionary's functionality
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

void ul(node *n);

// Choose number of buckets in hash table
const unsigned int N = 516;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int bucket = hash(word);
    node *itr = table[bucket];
    while (itr != NULL)
    {
        if (strcasecmp(itr->word, word) == 0)
        {
            return true;
        }
        itr = itr->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int sum = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if isalpha(word[i])
            sum += tolower(word[i]) - 'a';
        else
            sum += 26;
    }
    return sum;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    char word[LENGTH + 1];
    char c;
    int index = 0;
    while (fread(&c, sizeof(char), 1, file))
    {
        // Allow only alphabetical characters and apostrophes
        if (isalpha(c) || c == '\'')
        {
            // Append character to word
            word[index] = c;
            index++;
        }
        else
        {
            word[index] = '\0';
            int bucket = hash(word);
            if (table[bucket] == NULL)
            {
                table[bucket] = calloc(1,sizeof(node));
                for (int i = 0; i < index; i++)
                {
                    table[bucket]->word[i] = word[i];
                }
                table[bucket]->next = NULL;
            }
            else
            {
                node *itr = table[bucket];
                while (itr->next != NULL)
                {
                    itr = itr->next;
                }
                node *n = calloc(1,sizeof(node));
                for (int i = 0; i < index; i++)
                {
                    n->word[i] = word[i];
                }
                n->next = NULL;
                itr->next = n;
            }
            index = 0;
        }
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        node *itr = table[i];
        while (itr != NULL)
        {
            count++;
            itr = itr->next;
        }
    }
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *n = table[i];
        if (n != NULL)
        {
            ul(n);
        }
    }
    return true;
}

void ul(node *n)
{
    if (n->next != NULL)
    {
        ul(n->next);
    }
    free(n);
}