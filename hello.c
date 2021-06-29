#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // get string input from a user
    string name = get_string("What is your name? ");
    
    // Display the name
    printf("Your name is: %s\n", name);
}
