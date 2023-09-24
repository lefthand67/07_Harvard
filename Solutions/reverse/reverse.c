#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
	if (argc != 3)
	{
		printf("Usage: ./reverse input.wav output.wav\n");
		return 1;
	}

    // Open input file for reading
    // TODO #2
	FILE *input = fopen(argv[1], "r");
	if (input == NULL)
	{
		printf("Could not open a file\n");
		return 2;
	}

    // Read header
    // TODO #3
	WAVHEADER buffer;
	fread(&buffer, sizeof(WAVHEADER), 1, input);

    // Use check_format to ensure WAV format
    // TODO #4
	check_format(buffer);

    // Open output file for writing
    // TODO #5
	FILE *output = fopen(argv[2], "w");
	if (output == NULL)
	{
		printf("Could not open a file\n");
		return 5;
	}

    // Write header to file
    // TODO #6
	fwrite(&buffer, sizeof(WAVHEADER), 1, output);

    // Use get_block_size to calculate size of block
    // TODO #7;
	int block_size = get_block_size(buffer);	

    // Write reversed audio to file
    // TODO #8
	
	// find the size without header to count blocks
	fseek(input, 0, SEEK_END);
	int inp_file_size = ftell(input) - sizeof(WAVHEADER);



	int blocks_qty = inp_file_size / block_size;
	
	// buffer for each block
	int one_block;
	// starting carret position
	int seek_position = block_size;
	// main loop for all blocks
	while (blocks_qty > 0)
	{
		// set carret to the end and count back blocks
		fseek(input, -seek_position, SEEK_END);
		// read and write each block backwards
		fread(&one_block, block_size, 1, input);
		fwrite(&one_block, block_size, 1, output);
		// update carret position
		seek_position += block_size;
		// one block away
		blocks_qty--;
	}

	fclose(input);
	fclose(output);

}

int check_format(WAVHEADER header)
{
    // TODO #4
	char *check = "WAVE";
	for (int i = 0; i < 4; i++)	
	{
		int letter = check[i];
		if (header.format[i] != letter)
		{
			printf("This is not a WAV file.")
			return 4;
		}	
	}	
    return 0;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
	int block_size;
	block_size = header.numChannels * header.bitsPerSample / 8;
    return block_size;
}
