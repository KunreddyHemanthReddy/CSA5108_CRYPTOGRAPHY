
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char plaintext[100], ciphertext[100];
    int key[100], i, n;

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter number of key values: ");
    scanf("%d", &n);

    printf("Enter key stream:\n");

    for(i = 0; i < n; i++)
        scanf("%d", &key[i]);

    printf("\nEncrypted ciphertext: ");

    int j = 0;

    for(i = 0; plaintext[i] != '\0'; i++)
    {
        if(isalpha((unsigned char)plaintext[i]))
        {
            int p = toupper((unsigned char)plaintext[i]) - 'A';
            int c = (p + key[j]) % 26;

            ciphertext[j] = c + 'A';

            printf("%c", ciphertext[j]);

            j++;
        }
    }

    ciphertext[j] = '\0';

    printf("\n\nDecrypted plaintext: ");

    // Decryption using the same key
    for(i = 0; i < j; i++)
    {
        int c = ciphertext[i] - 'A';
        int p = (c - key[i] + 26) % 26;

        printf("%c", p + 'A');
    }

    printf("\n");

    return 0;
}

