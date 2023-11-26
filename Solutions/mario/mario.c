#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
	{
		printf("Usage: ./mario integer between 1 and 8\n");
		return 1;
	}

    int number = atoi(argv[1]);

	if (number < 1 || number > 8)
    {
        printf("Usage: ./mario	integer between 1 and 8\n");
		return 1;
    }

    for (int i = 0; i < number; i++)
    {

		for (int j = number-i; j > 1; j--)
		{
			printf(" ");
		}

		for (int j = 0; j < i+1; j++)
		{
			printf("#");
		}

		printf("  ");

		for (int j = 0; j < i+1; j++)
		{
			printf("*");
		}

		printf("\n");

	}

	return 0;

}
