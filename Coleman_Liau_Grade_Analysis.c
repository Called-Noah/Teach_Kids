#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");
    
    int get_total_Letters(string txt);
    int get_total_Sentences(string txt);
    int get_total_Blank(string txt);

    int intIndex = 0;
    float L = 0.0;
    float S = 0.0;
    
    int numSentence = get_total_Sentences(text);
    int totalWords = get_total_Blank(text) + 1;
    int totalLetter = get_total_Letters(text);
    
    // Print the number of letter(s), word(s), sentence(s)    
    printf("%i letter(s)\n", totalLetter);
    printf("%i word(s)\n", totalWords);
    printf("%i sentence(s)\n", numSentence);
    
    
    // Method to count L and S variable
    L = (float) totalLetter * (float)(100 / (float) totalWords);
    S = (float) numSentence * (float)(100 / (float) totalWords);
    
    // Apply to Coleman-Liau index formula. if there is a mistake, the problem is conversion. float -> int
    float index = (0.0588 * L) - (0.296 * S) - 15.8;    
    
    // round to the nearest number
    intIndex = round(index);
    
    // If the index is or higher than 16 grade or lower than 1 grade. Display the assessment.
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", intIndex);
    }
}

// Count the number of letter(s)
int get_total_Letters(string txt)
{
    int totalLetter = 0;
    int numLetter = strlen(txt);
    
    for (int m = 0; m < numLetter; m++)
    {
        if (txt[m] >= 'A' && txt[m] <= 'Z')
        {
            totalLetter++;
        }
        else if (txt[m] >= 'a' && txt[m] <= 'z')
        {
            totalLetter++;
        }
    }
    
    return totalLetter;
}

// Count the number of sentence(s)
int get_total_Sentences(string txt)
{
    int numSentence = 0;
    int numLetter = strlen(txt);
    
    for (int i = 0; i < numLetter; i++)
    {
        if (txt[i] == '!')
        {
            numSentence++;
        }
        else if (txt[i] == '.')
        {
            numSentence++;
        }
        else if (txt[i] == '?')
        {
            numSentence++;
        }
    }
    
    return numSentence;
}

// Count the number of total word
int get_total_Blank(string txt)
{
    int numBlank = 0;
    int numLetter = strlen(txt);
    
    for (int j = 0; j < numLetter; j++)
    {
        if (txt[j] == ' ')
        {
            numBlank++;
        }
    }
    
    return numBlank;
}
