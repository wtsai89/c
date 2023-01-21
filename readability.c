#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    int lcount = count_letters(text);
    //printf("%i letters\n", lcount);
    int wcount = count_words(text);
    //printf("%i words\n", wcount);
    int scount = count_sentences(text);
    //printf("%i sentences\n", scount);
    int index = round(0.0588 * ((float)lcount / wcount * 100.0) - 0.296 * ((float)scount / wcount * 100.0) - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text)
{
    int sum = 0;
    char c;
    for (int i = 0; i < strlen(text); i++)
    {
        c = tolower(text[i]) - 97;
        if (c >= 0 && c <= 25)
        {
            sum++;
        }
    }
    return sum;
}

int count_words(string text)
{
    int sum = 0;
    char c;
    bool inWord = false;
    for (int i = 0; i < strlen(text); i++)
    {
        c = text[i];
        if (c == ' ' && inWord)
        {
            inWord = false;
        }
        else if (c != ' ' && !inWord)
        {
            sum++;
            inWord = true;
        }
    }
    return sum;
}

int count_sentences(string text)
{
    int sum = 0;
    int length = strlen(text);
    char c;
    for (int i = 0; i < length; i++)
    {
        c = text[i];
        if ((c == '.' || c == '?' || c == '!') && (i == length - 1 || text[i + 1] == ' '))
        {
            sum++;
        }
    }
    return sum;
}