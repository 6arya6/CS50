#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //Iterating through each pixel
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int avg_colour = (int) round(((image[h][w].rgbtRed + image[h][w].rgbtGreen + image[h][w].rgbtBlue) / 3.0));
            image[h][w].rgbtRed = avg_colour;
            image[h][w].rgbtGreen = avg_colour;
            image[h][w].rgbtBlue = avg_colour;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //Iterating through each pixel
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int sepiaRed = (int) round(.393 * image[h][w].rgbtRed + .769 * image[h][w].rgbtGreen + .189 * image[h][w].rgbtBlue);
            int sepiaGreen = (int) round(.349 * image[h][w].rgbtRed + .686 * image[h][w].rgbtGreen + .168 * image[h][w].rgbtBlue);
            int sepiaBlue = (int) round(.272 * image[h][w].rgbtRed + .534 * image[h][w].rgbtGreen + .131 * image[h][w].rgbtBlue);

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[h][w].rgbtRed = sepiaRed;
            image[h][w].rgbtGreen = sepiaGreen;
            image[h][w].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //Iterating through each pixel
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < (width / 2); w++)
        {
            //Swapping pixels of a row horizontally
            int tempRed;
            int tempGreen;
            int tempBlue;

            tempRed = image[h][w].rgbtRed;
            tempGreen = image[h][w].rgbtGreen;
            tempBlue = image[h][w].rgbtBlue;

            image[h][w].rgbtRed = image[h][(width - w - 1)].rgbtRed;
            image[h][w].rgbtGreen = image[h][(width - w - 1)].rgbtGreen;
            image[h][w].rgbtBlue = image[h][(width - w - 1)].rgbtBlue;

            image[h][(width - w - 1)].rgbtRed = tempRed;
            image[h][(width - w - 1)].rgbtGreen = tempGreen;
            image[h][(width - w - 1)].rgbtBlue = tempBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //Creating a copy of the image
    RGBTRIPLE original_image[height][width];
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            original_image[h][w] = image[h][w];
        }
    }

    //Iterating through each pixel
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            //initialising varibales for box blur
            int a = -1;
            int b = -1;
            int max_row = 2;
            int max_column = 2;
            double total = 9.0;

            //Checking for corner or edge pixels
            //Checking if pixel is at bottom or top row
            if (h == 0)
            {
                a = 0;
                total -= 3;
            }
            else if (h == (height - 1))
            {
                max_row = 1;
                total -= 3;
            }
            //Checking if pixel is at rightmost or leftmost column
            if (w == 0)
            {
                b = 0;
                total -= 3;
            }
            else if (w == (width - 1))
            {
                max_column = 1;
                total -= 3;
            }
            //Checking if pixel is at corner
            if ((h == 0 && w == 0) || (h == 0 && w == (width - 1)) || (h == (height - 1) && w == 0) || (h == (height - 1) && w == (width - 1)))
            {
                total ++;
            }

            int sum_red = 0;
            int sum_green = 0;
            int sum_blue = 0;

            //Creatiing a box and adding rgb values
            for (int i = a; i < max_row; i++)
            {
                for (int j = b; j < max_column; j++)
                {
                    sum_red += original_image[(h + i)][(w + j)].rgbtRed;
                    sum_green += original_image[(h + i)][(w + j)].rgbtGreen;
                    sum_blue += original_image[(h + i)][(w + j)].rgbtBlue;
                }
            }

            //Calculating average rgb values
            double avg_red = (sum_red / total);
            double avg_green = (sum_green / total);
            double avg_blue = (sum_blue / total);

            //Setting new pixel values
            image[h][w].rgbtRed = (int) round(avg_red);
            image[h][w].rgbtGreen = (int) round(avg_green);
            image[h][w].rgbtBlue = (int) round(avg_blue);

        }
    }
    return;
}
