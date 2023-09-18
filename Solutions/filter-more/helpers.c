#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			int gray_color;
			gray_color = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3;
			image[i][j].rgbtRed = gray_color;
			image[i][j].rgbtGreen = gray_color;
			image[i][j].rgbtBlue = gray_color;
		}
	}
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
	for (int i = 0, n = width / 2; i < height; i++)
	{
		for (int j = 0; j < n; j++)
		{
			RGBTRIPLE tmp;
			tmp = image[i][j];
			image[i][j] = image[i][width-1 - j];
			image[i][width-1 - j] = tmp;			
		}
	}
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

	RGBTRIPLE tmp[height][width];

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			int new_red = 0;
			int new_green = 0;
			int new_blue = 0;
			// indexers for neighboring pixels 
			int m = -1;
			int n = -1;
			int upper_m = 2;
			int upper_n = 2;

			// neighboring pixels counter
			int counter = 0;

		    if (i == 0 && j == 0)
		    {
		    	m = 0;
		    	n = 0;
		    }
		    else if (i == 0 && j == width-1)
		    {
		    	m = -1;
		    	n = 0;
				upper_m = 1;
		    }
			else if (i == height-1 && j == 0)
		    {
		    	m = -1;
		    	n = 0;
				upper_m = 1;
		    }
		    else if (i == height-1 && j == width-1)
		    {
		    	m = -1;
		    	n = -1;
				upper_m = 1;
				upper_n = 1;
		    }
			else if (i == 0)
			{
				m = 0;	
			}
			else if (i == height-1)
			{
				upper_m = 1;
			}
			else if (j == 0)
			{
				n = 0;	
			}
			else if (j == width-1)
			{
				upper_n = 1;
			}

			
			// main loop
		    for (int h = m; h < upper_m; h++)
		    {
			   	for (int w = n; w < upper_n; w++)
		    	{
		    	    new_red += image[i+h][j+w].rgbtRed;
		    	    new_green += image[i+h][j+w].rgbtGreen;
		    	    new_blue += image[i+h][j+w].rgbtBlue;
		    	    counter++;
		    	}
		    }

		    tmp[i][j].rgbtRed = new_red / counter;	
		    tmp[i][j].rgbtGreen = new_green / counter;	
		    tmp[i][j].rgbtBlue = new_blue / counter;		
		}
	}
	
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			image[i][j] = tmp[i][j];
		}
	}
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{

    // kernels
 	int Gx[3][3] = {
 		{-1, 0, 1},
 		{-2, 0, 2},
 		{-1, 0, 1}
 	};
 	int Gy[3][3] = {
 		{-1, -2, -1},
 		{0, 0, 0},
 		{1, 2, 1}
 	};
 
	RGBTRIPLE tmp[height][width];

    for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			int redx = 0;
			int greenx = 0;
			int bluex = 0;
			int redy = 0;
			int greeny = 0;
			int bluey = 0;
			

			// indexers for neighboring pixels 
			int m = -1;
			int n = -1;
			int upper_m = 2;
			int upper_n = 2;

		    if (i == 0 && j == 0)
		    {
		    	m = 0;
		    	n = 0;
		    }
		    else if (i == 0 && j == width-1)
		    {
		    	m = -1;
		    	n = 0;
				upper_m = 1;
		    }
			else if (i == height-1 && j == 0)
		    {
		    	m = -1;
		    	n = 0;
				upper_m = 1;
		    }
		    else if (i == height-1 && j == width-1)
		    {
		    	m = -1;
		    	n = -1;
				upper_m = 1;
				upper_n = 1;
		    }
			else if (i == 0)
			{
				m = 0;	
			}
			else if (i == height-1)
			{
				upper_m = 1;
			}
			else if (j == 0)
			{
				n = 0;	
			}
			else if (j == width-1)
			{
				upper_n = 1;
			}

			// loop
		    for (int h = m; h < upper_m; h++)
		    {
		    	for (int w = n; w < upper_n; w++)
		    	{
					int gx = Gx[1+h][1+w];
		    	    redx += image[i+h][j+w].rgbtRed * gx;
		    	    greenx += image[i+h][j+w].rgbtGreen * gx;
		    	    bluex += image[i+h][j+w].rgbtBlue * gx;
		    	    
					int gy = Gy[1+h][1+w];
		    	    redy += image[i+h][j+w].rgbtRed * gy;
		    	    greeny += image[i+h][j+w].rgbtGreen * gy;
		    	    bluey += image[i+h][j+w].rgbtBlue * gy;

				}
		    }

			int resultr = sqrt(redx*redx + redy*redy);
			int resultg	= sqrt(greenx*greenx + greeny*greeny);
			int resultb = sqrt(bluex*bluex + bluey*bluey);

			if (resultr > 255)
			{
				resultr = 255;
			}

			if (resultg > 255)
			{
				resultg = 255;
			}

			if (resultb > 255)
			{
				resultb = 255;
			}

			tmp[i][j].rgbtRed = resultr;
		    tmp[i][j].rgbtGreen = resultg;
		    tmp[i][j].rgbtBlue = resultb;

		}
	}	

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			image[i][j] = tmp[i][j];
		}
	}
}
