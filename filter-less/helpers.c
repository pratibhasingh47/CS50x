#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int row = 0; row < height; row++)
    {
        for(int col = 0; col<width; col++)
        {
            int avg = round((image[row][col].rgbtRed + image[row][col].rgbtGreen + image[row][col].rgbtBlue) / 3.0 );
            image[row][col].rgbtRed = image[row][col].rgbtGreen = image[row][col].rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i<height ; i++)
    {
        for(int j = 0 ;j<width ; j++)
        {
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            image[i][j].rgbtRed = fmin(255,(int)(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue + 0.5));
            image[i][j].rgbtGreen = fmin(255,(int)(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue + 0.5));
            image[i][j].rgbtBlue = fmin(255,(int)(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue + 0.5));
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
        for(int i = 0; i<height ; i++)
    {
        for(int j = 0 ;j < width/2 ; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width -1 -j];
            image[i][width -1 -j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE original[height][width];
    for(int row = 0; row < height; row++)
    {
        for(int col = 0; col<width; col++)
        {
            original[row][col] = image[row][col];
        }
    }

    float totalr,totalg,totalb;
    int count = 0;
    totalr = totalg = totalb =0;
    for(int row = 0; row < height; row++)
    {
        for(int col = 0; col<width; col++)
        {
            for(int arrow = row -1; arrow <= row+1;arrow ++)
            {
                for(int arcol = col-1; arcol<= col+1;arcol++)
                {
                    if(arcol<width && arrow <height && arcol>=0 && arrow>= 0)
                    {
                        totalr += original[arrow][arcol].rgbtRed;
                        totalg += original[arrow][arcol].rgbtGreen;
                        totalb += original[arrow][arcol].rgbtBlue;
                        count++;
                    }
                }
            }
                image[row][col].rgbtRed = round(totalr / count);
                image[row][col].rgbtGreen = round(totalg / count);
                image[row][col].rgbtBlue = round(totalb / count);
                count = 0;
                totalr = totalg = totalb =0;
        }
    }
    return;
}
