
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char plaintext[100];
    char key[] = "CIPHER";
    char cipher[27];
    int used[26] = {0};
    int i, j = 0;

    // Generate cipher alphabet using keyword
    for (i = 0; key[i] != '\0'; i++)
    {
        char ch = toupper(key[i]);

        if (!used[ch - 'A'])
        {
            cipher[j++] = ch;
            used[ch - 'A'] = 1;
        }
    }

    // Add remaining unused letters
    for (i = 0; i < 26; i++)
    {
        if (!used[i])
        {
            cipher[j++] = 'A' + i;
        }
    }

    cipher[j] = '\0';

    printf("Plain alphabet : ");
    for (i = 0; i < 26; i++)
        printf("%c ", 'A' + i);

    printf("\nCipher alphabet: ");
    for (i = 0; i < 26; i++)
        printf("%c ", cipher[i]);

    // Read plaintext
    printf("\n\nEnter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Encryption
    printf("\nEncrypted text: ");

    for (i = 0; plaintext[i] != '\0'; i++)
    {
        if (isupper(plaintext[i]))
            printf("%c", cipher[plaintext[i] - 'A']);

        else if (islower(plaintext[i]))
            printf("%c", tolower(cipher[plaintext[i] - 'a']));

        else
            printf("%c", plaintext[i]);
    }

    printf("\n");

    return 0;
}

