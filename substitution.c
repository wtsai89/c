#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool valid_key(string key);
char sub(char c, string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string key = argv[1];
    if (!valid_key(key))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    string message = get_string("plaintext: ");
    for (int i = 0; i < strlen(message); i++)
    {
        message[i] = sub(message[i], key);
    }
    printf("ciphertext: %s\n", message);
}

bool valid_key(string key)
{
    char alpha[26];
    for (int i = 0; i < 26; i++)
    {
        alpha[i] = 0;
    }
    int length = strlen(key);
    if (length != 26)
    {
        return false;
    }
    char c;
    int index;
    for (int i = 0; i < length; i++)
    {
        c = key[i];
        if (isalpha(c))
        {
            c = tolower(c);
            index = (int)c - 97;
            if (alpha[index] == 1)
            {
                return false;
            }
            else
            {
                alpha[index] = 1;
            }
        }
        else
        {
            return false;
        }
    }
    return true;
}

char sub(char c, string key)
{
    int index;
    if (islower(c))
    {
        index = (int)c - 97;
        return tolower(key[index]);
    }
    if (isupper(c))
    {
        index = (int)c - 65;
        return toupper(key[index]);
    }
    return c;
}