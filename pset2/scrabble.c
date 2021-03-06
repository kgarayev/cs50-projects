#include <cs50.h>
#include <stdio.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // Compute and return score for string

    int length;

    // Find length of the word and capitalise everything
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (word[i] >= 'a' && word[i] <= 'z')
        {
            word[i] = word [i] - 32;
        }
        else
        {
            word[i] = word [i];
        }

        length = i + 1;
    }

    int x;
    int sum = 0;

    // Check ASCII numbers and compute the score
    for (int j = 0; j < length; j++)
    {
        x = word[j] - 65;

        if (x < 0 || x > 25)
        {
            sum = sum + 0;
        }
        else
        {
            sum = sum + POINTS[x];
        }

    }

    return sum;
}