#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: ./mario3 integer between 1 and 8\n");
		return 1;
	}

	int number = atoi(argv[1]);

	if (number < 1 || number > 8)
	{
		printf("Usage: ./mario3	integer between 1 and 8\n");
		return 1;
	}

	for (int i = 0; i < number; i++)
	{

		// large arrays will be cut with '\0' when needed
		// also they will disappear after the loop is done
		char empty_line[number + 1], bricks[number + 1];

		int counter = 0;
		while (counter < (number - i - 1))
		{
			empty_line[counter] = ' ';
			counter++;
		}
		// if you do not end the string you will get garbage values after the [counter] position
		empty_line[counter] = '\0';

		for (int j = 0; j < (i+1); j++)
		{
			bricks[j] = '#';
		}
		// end the string
		bricks[i+1] = '\0';

		printf("%s", empty_line);
		printf("%s", bricks);
        printf("  ");
		printf("%s", bricks);
        printf("\n");

	}

	return 0;

}
