#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // declare year and prompt start population
    int year = 0;
    int start_population = get_int("Start size ");
    
    // When the user put start population less than 9
    if (start_population < 9)
    {
        while (start_population < 9) 
        {
            start_population = get_int("Start size: ");
        }
    }

    // prompt the end size
    int end_population = get_int("End size: ");
    
    // the user must put bigger end population than start population
    if (end_population < start_population)
    {
        while (end_population < start_population)
        {    
            end_population = get_int("End size: ");
        }
             
    }
    
    // calculate the year
    while (start_population < end_population)
    {
        start_population = start_population + (int)(start_population / 3) - (int)(start_population / 4);
        year++; 
        
    }

    // print the calculated year
    printf("Years: %i\n", year);
}
