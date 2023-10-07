#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./read infile\n");
        return 1;
    }

    // Create buffer to read into
    char *buffer = malloc(7);

    // Create array to store plate numbers
    char *plates[8];  // 8 arrays of 7 chars
   
    FILE *infile = fopen(argv[1], "r");

    int idx = 0;

    while (fread(buffer, 1, 7, infile) == 7)
    {
        // Replace '\n' with '\0'
        buffer[6] = '\0';

		// check what the buffer contains
//		printf("%s\n", buffer);

		// Save plate number in array
		plates[idx] = malloc(7);
		strcpy(plates[idx], buffer);
        idx++;

		// check the plates array at each iteration
//		for (int j = 0; j < 8; j++)
//		{
//			printf("%s ", plates[j]);
//		}
//		printf("\n");
    }

//	printf("\n");

    for (int i = 0; i < 8; i++)
    {
        printf("%s\n", plates[i]);
    }

	free(buffer);
	for (int i = 0; i < 8; i ++)
	{
		free(plates[i]);
	}
	fclose(infile);
}
