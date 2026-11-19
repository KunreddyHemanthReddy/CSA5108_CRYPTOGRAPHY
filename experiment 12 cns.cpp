
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char text[200], plain[200];
    char cipher[200], decrypted[200];

    int key[2][2] = {
        {9, 4},
        {5, 7}
    };

    int inv[2][2] = {
        {5, 12},
        {15, 25}
    };

    int i, j, a, b, c, d, n;

    printf("Enter plaintext:\n");
    fgets(text, sizeof(text), stdin);

    // Remove spaces and convert to uppercase
    n = 0;

    for (i = 0; text[i] != '\0'; i++)
    {
        if (isalpha((unsigned char)text[i]))
            plain[n++] = toupper((unsigned char)text[i]);
    }

    // Add X if length is odd
    if (n % 2 != 0)
        plain[n++] = 'X';

    plain[n] = '\0';

    // Encryption
    for (i = 0; i < n; i += 2)
    {
        a = plain[i] - 'A';
        b = plain[i + 1] - 'A';

        c = (key[0][0] * a + key[0][1] * b) % 26;
        d = (key[1][0] * a + key[1][1] * b) % 26;

        cipher[i] = c + 'A';
        cipher[i + 1] = d + 'A';
    }

    cipher[n] = '\0';

    printf("\nEncrypted Ciphertext:\n");

    for (i = 0; i < n; i++)
    {
        printf("%c", cipher[i]);

        if (i % 2 == 1)
            printf(" ");
    }

    // Decryption
    for (i = 0; i < n; i += 2)
    {
        a = cipher[i] - 'A';
        b = cipher[i + 1] - 'A';

        c = (inv[0][0] * a + inv[0][1] * b) % 26;
        d = (inv[1][0] * a + inv[1][1] * b) % 26;

        decrypted[i] = c + 'A';
        decrypted[i + 1] = d + 'A';
    }

    decrypted[n] = '\0';

    printf("\n\nDecrypted Plaintext:\n");

    for (i = 0; i < n; i++)
    {
        printf("%c", decrypted[i]);
    }

    printf("\n");

    return 0;
}

