#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    string message = get_string("Message: ");
    int c;
    int bindex;
    char byte[BITS_IN_BYTE];
    for (int i = 0; i < strlen(message); i++)
    {
        c = (int)message[i];
        bindex = 7;
        //Convert character to byte format
        while (c > 0)
        {
            if (c % 2 == 0)
            {
                byte[bindex] = '0';
            }
            else
            {
                byte[bindex] = '1';
            }
            c = c / 2;
            bindex--;
        }
        while (bindex >= 0)
        {
            byte[bindex] = '0';
            bindex--;
        }

        //convert byte format to bulbs
        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            if (byte[j] == '0')
            {
                print_bulb(0);
            }
            else
            {
                print_bulb(1);
            }
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
