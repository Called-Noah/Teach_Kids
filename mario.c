#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height, hashNumber, blankNumber = 0;
    
    //Get height from the user
    height = get_int("Height: ");
    
    // Check that height is between 1 and 8
    if (height < 1 || height > 8)
    {
        while (height < 1 || height > 8)
        {
            height = get_int("Height: ");
        }
    }
    
    // Draw the hash block to the right
    int j = 1;
    
    while (j <= height)
    {
        // Draw the blank
        for (blankNumber = height; blankNumber > j; blankNumber--)
        {
            printf(" ");
        }
        
        // Draw the hashes
        for (hashNumber = 1; hashNumber <= j; hashNumber++)
        {
            printf("#");
        }
        
        j++;
        printf("\n");
    }
    
}