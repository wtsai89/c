#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

bool only_digits(string text);
char rotate(char c, int key);

int main(int argc, string argv[])
{
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string message = get_string("plaintext: ");
    int key = atoi(argv[1]);
    for (int i = 0; i < strlen(message); i++)
    {
        message[i] = rotate(message[i], key);
    }
    printf("ciphertext: %s\n", message);
}

bool only_digits(string text)
{
    for (int i = 0; i < strlen(text); i++)
    {
        if (isdigit(text[i]) == 0)
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int key)
{
    int num;
    if (islower(c))
    {
        num = (int)c - 96;
        num = (num + key) % 26;
        c = (char)(num + 96);
    }
    else if (isupper(c))
    {
        num = (int)c - 64;
        num = (num + key) % 26;
        c = (char)(num + 64);
    }
    return c;
}