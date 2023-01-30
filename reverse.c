#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }

    // Open input file for reading
    FILE *input = fopen(argv[1], "r");

    // Read header into an array
    WAVHEADER header;
    fread(&header, sizeof(WAVHEADER), 1, input);

    // Use check_format to ensure WAV format
    if (check_format(header) == 0)
    {
        printf("Input is not a WAV file.\n");
        return 2;
    }

    // Open output file for writing
    FILE *output = fopen(argv[2], "w");

    // Write header to file
    fwrite(&header, sizeof(WAVHEADER), 1, output);

    // Use get_block_size to calculate size of block
    int block_size = get_block_size(header);

    // Write reversed audio to file
    int start = ftell(input);
    fseek(input, block_size * -1, SEEK_END);
    BYTE block[block_size];
    while (ftell(input) >= start)
    {
        fread(block, 1, sizeof(block_size), input);
        fwrite(block, 1, sizeof(block_size), output);
        fseek(input, block_size * -2, SEEK_CUR);
    }

    fclose(input);
    fclose(output);
}

int check_format(WAVHEADER header)
{
    if ((char)(header.format[0]) == 'W' && (char)(header.format[1]) == 'A' && (char)(header.format[2]) == 'V' && (char)(header.format[3]) == 'E')
    {
        return 1;
    }
    return 0;
}

int get_block_size(WAVHEADER header)
{
    return header.numChannels * header.bitsPerSample / 8;
}