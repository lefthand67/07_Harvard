#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE [height][width])
{
	// Change all black image[i][j]s to a color of your choosing
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (image[i][j].rgbtRed == 0x00 && image[i][j].rgbtGreen == 0x00 && image[i][j].rgbtBlue == 0x00)
			{
				image[i][j].rgbtBlue = 0xff;
				// image[i][j].rgbtRed = 0x88;
				// image[i][j].rgbtGreen = 0xa4;
			}
		}	
	}	
}


