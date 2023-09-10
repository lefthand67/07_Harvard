#include <stdio.h>
#include <string.h>
// #include <cs50.h>

int main(void)
{
	int Gx[3][3] = {
		{-1, 0, 1},
		{-2, 0, 2},
		{-1, 0, 1}
	};
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%i ", Gx[i][j]);
		}
	printf("\n");
	}
}

