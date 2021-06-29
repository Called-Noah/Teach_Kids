#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //Receive value from the user
    float dollars = get_float("Change owed: "); 
    
    //Check that dollar is negtive
    while (dollars <= 0)
    {
        dollars = get_float("Change owed: ");
    }
    
    //convert dollars to cents
    int cents = round(dollars * 100);
    
    //Greedy Algorithms
    int coinCounts = 0;
    
    //Count until cents are zero
    while (cents > 0)
    {
        //25 cents case
        if (cents >= 25)
        {
            coinCounts++;
            cents = cents - 25;
        }
        
        //10 cents case
        if (cents >= 10 && cents < 25)
        {
            coinCounts++;
            cents = cents - 10;
        }
        
        //5 cents case
        if (cents >= 5 && cents < 10)
        {
            coinCounts++;
            cents = cents - 5;
        }
        
        //1 cent case
        if (cents >= 1 && cents < 5)
        {
            coinCounts++;
            cents = cents - 1;
        }
        
    }
    
    printf("%i\n", coinCounts);
    
}