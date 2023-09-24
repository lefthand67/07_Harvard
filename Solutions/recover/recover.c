#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
 
int main(int argc, char *argv[])
{
	typedef uint8_t BYTE;

	if (argc != 2)
	{
		printf("Usage: ./recover IMAGE\n");
		return 1;
	}

	FILE *input = fopen(argv[1], "r");
	if (input == NULL)
	{
		printf("File cannot be opened. Try another file\n");
		return 2;
	}

	const int BLOCK_SIZE = 512;
	BYTE *buffer = malloc(BLOCK_SIZE);
	char *pic_name = malloc(9);
	int number = 0;
	FILE *image;


	BYTE check_array[] = {0xff, 0xd8, 0xff, 0xe0};
	while ( fread(buffer, 1, BLOCK_SIZE, input) )
	{
		// check for start of jpeg
		int check = 1;
		for (int i = 0, n = 3; i < n; i++)
		{
			if	(buffer[i] != check_array[i] || (buffer[n] & 0xf0) != 0xe0)
			{
				check = 0;
				break;
			}
		}

		if (check)
		{
			if (number != 0)
			{
				fclose(image); 
			}

			sprintf(pic_name, "%03i.jpeg", number);
			image = fopen(pic_name, "w");
			fwrite(buffer, 1, BLOCK_SIZE, image);
			number++;
		}

		else if (number != 0)
		{
			fwrite(buffer, 1, BLOCK_SIZE, image); 		
		}
	}

	fclose(image);
    free(buffer);
    free(pic_name);
}
