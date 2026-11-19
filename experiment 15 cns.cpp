
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

// English letter frequency
double englishFreq[26] = {
    8.167, 1.492, 2.782, 4.253, 12.702,
    2.228, 2.015, 6.094, 6.966, 0.153,
    0.772, 4.025, 2.406, 6.749, 7.507,
    1.929, 0.095, 5.987, 6.327, 9.056,
    2.758, 0.978, 2.360, 0.150, 1.974, 0.074
};

struct Result {
    int key;
    double score;
    char text[MAX];
};

// Calculate frequency score
double calculateScore(char text[])
{
    int count[26] = {0};
    int total = 0;
    double score = 0;

    for(int i = 0; text[i] != '\0'; i++)
    {
        if(isalpha((unsigned char)text[i]))
        {
            count[toupper((unsigned char)text[i]) - 'A']++;
            total++;
        }
    }

    if(total == 0)
        return 0;

    for(int i = 0; i < 26; i++)
    {
        double actual = (double)count[i] / total * 100;
        double diff = actual - englishFreq[i];
        score += diff * diff;
    }

    return score;
}

int main()
{
    char cipher[MAX];
    struct Result results[26], temp;
    int n, top;

    printf("Enter ciphertext:\n");
    fgets(cipher, MAX, stdin);

    printf("Enter number of top plaintexts required: ");
    scanf("%d", &top);

    if(top < 1 || top > 26)
    {
        printf("Enter a value between 1 and 26.\n");
        return 0;
    }

    // Try all 26 possible keys
    for(int key = 0; key < 26; key++)
    {
        strcpy(results[key].text, cipher);
        results[key].key = key;

        for(int i = 0; cipher[i] != '\0'; i++)
        {
            if(isupper((unsigned char)cipher[i]))
                results[key].text[i] =
                    (cipher[i] - 'A' - key + 26) % 26 + 'A';

            else if(islower((unsigned char)cipher[i]))
                results[key].text[i] =
                    (cipher[i] - 'a' - key + 26) % 26 + 'a';
        }

        results[key].score =
            calculateScore(results[key].text);
    }

    // Sort by lowest frequency difference
    for(int i = 0; i < 25; i++)
    {
        for(int j = i + 1; j < 26; j++)
        {
            if(results[i].score > results[j].score)
            {
                temp = results[i];
                results[i] = results[j];
                results[j] = temp;
            }
        }
    }

    // Display top results
    printf("\nTop %d possible plaintexts:\n\n", top);

    for(int i = 0; i < top; i++)
    {
        printf("Rank %d\n", i + 1);
        printf("Key: %d\n", results[i].key);
        printf("Score: %.2f\n", results[i].score);
        printf("Plaintext: %s\n\n", results[i].text);
    }

    return 0;
}

