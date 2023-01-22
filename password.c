// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}


bool valid(string password)
{
    bool lower = false;
    bool upper = false;
    bool number = false;
    bool symbol = false;

    char c;
    for (int i = 0; i < strlen(password); i++)
    {
        c = password[i];
        if (!lower && islower(c) != 0)
        {
            lower = true;
        }
        else if (!upper && isupper(c) != 0)
        {
            upper = true;
        }
        else if (!number && isdigit(c) != 0)
        {
            number = true;
        }
        else if (!symbol && isalnum(c) == 0)
        {
            symbol = true;
        }
    }

    if(lower && upper && number && symbol)
    {
        return true;
    }
    return false;
}
