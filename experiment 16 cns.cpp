
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

// English letter frequency order
char english[] = "ETAOINSHRDLCUMWFGYPBVKJXQZ";

struct Letter
{
    char ch;
    int count;
};

int main()
{
    char cipher[MAX], result[MAX];
    char map[26];
    struct Letter freq[26], temp;

    int i, j, top;

    printf("Enter ciphertext:\n");
    fgets(cipher, MAX, stdin);

    printf("Enter number of possible plaintexts: ");
    scanf("%d", &top);

    if(top < 1)
    {
        printf("Invalid number.\n");
        return 0;
    }

    // Initialize frequency array
    for(i = 0; i < 26; i++)
    {
        freq[i].ch = 'A' + i;
        freq[i].count = 0;
    }

    // Count ciphertext letters
    for(i = 0; cipher[i] != '\0'; i++)
    {
        if(isalpha((unsigned char)cipher[i]))
        {
            char ch = toupper((unsigned char)cipher[i]);
            freq[ch - 'A'].count++;
        }
    }

    // Sort letters by frequency
    for(i = 0; i < 25; i++)
    {
        for(j = i + 1; j < 26; j++)
        {
            if(freq[i].count < freq[j].count)
            {
                temp = freq[i];
                freq[i] = freq[j];
                freq[j] = temp;
            }
        }
    }

    // Create substitution mapping
    for(i = 0; i < 26; i++)
        map[i] = '?';

    for(i = 0; i < 26; i++)
        map[freq[i].ch - 'A'] = english[i];

    // Generate plaintext
    for(i = 0; cipher[i] != '\0'; i++)
    {
        if(isupper((unsigned char)cipher[i]))
            result[i] = map[cipher[i] - 'A'];

        else if(islower((unsigned char)cipher[i]))
            result[i] = tolower(map[cipher[i] - 'a']);

        else
            result[i] = cipher[i];
    }

    result[i] = '\0';

    printf("\nFrequency Analysis Result:\n");
    printf("Possible plaintext: %s\n", result);

    printf("\nCiphertext frequency:\n");

    for(i = 0; i < 26; i++)
    {
        printf("%c = %d\n",
               freq[i].ch, freq[i].count);
    }

    printf("\nRequested top %d plaintexts:\n", top);

    printf("1. %s\n", result);

    for(i = 2; i <= top; i++)
    {
        printf("%d. Alternative substitution required\n", i);
    }

    return 0;
}

