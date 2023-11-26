// not done
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if (!atoi(argv[1]) || atoi(argv[1]) < 1)
	{
		printf("Usage: ./mario2 positive integer\n");
		return 1;
	}
	int number = atoi(argv[1]);
	
	char *empty_line = malloc(sizeof(char)*number); 
	if (empty_line == NULL)
	{
		printf("Cannot allocate memory\n");
		return 1;
	}

	char *stars = malloc(sizeof(char) + 1);
	if (empty_line == NULL)
	{
		printf("Cannot allocate memory\n");
		return 1;
	}

	for (int i = 0; i < number; i++)
	{
		char *tmp_empty = realloc(empty_line, sizeof(char)*(number-i)); 
		if (tmp_empty == NULL)
		{
			printf("Cannot allocate memory\n");
			free(empty_line);
			free(stars);
			return 2;
		}
		int cnt = 0;
		while (cnt < number - i - 1)
		{
			tmp_empty[cnt] = ' ';
			cnt++;
		}
		empty_line = tmp_empty;

		char *tmp_stars = realloc(stars, sizeof(char)*(i+2));
		if (tmp_stars == NULL)
		{
			printf("Cannot allocate memory\n");
			free(empty_line);
			free(stars);
			return 2;
		}
		for (int j = 0; j < i+1; j++)
		{
			tmp_stars[j] = '*';
		}

		printf("%s", empty_line);
		printf("%s", stars);
		printf(" ");
		printf("%s", stars);
		printf("%s", empty_line);
		
		printf("\n");

	}
    free(empty_line);
    free(stars);

	return 0;
}
