#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE");
        return 1;
    }

    FILE *raw_file = fopen(argv[1], "r");
    FILE *picture;

    BYTE buffer[512];
    char pname[8];
    int count = 0;
    while (fread(buffer, 1, BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    {
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (count > 0)
            {
                fclose(picture);
            }
            sprintf(pname, "%03i.jpg", count);
            picture = fopen(pname, "w");
            count++;
        }
        if (count > 0)
            fwrite(buffer, 1, BLOCK_SIZE, picture);
    }
    fclose(picture);
    fclose(raw_file);
}