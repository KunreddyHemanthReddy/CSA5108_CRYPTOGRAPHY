
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char plaintext[100], ciphertext[100];
    char key[27] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    int i;

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Encryption
    for (i = 0; plaintext[i] != '\0'; i++)
    {
        if (isupper(plaintext[i]))
            ciphertext[i] = key[plaintext[i] - 'A'];

        else if (islower(plaintext[i]))
            ciphertext[i] = tolower(key[plaintext[i] - 'a']);

        else
            ciphertext[i] = plaintext[i];
    }

    ciphertext[i] = '\0';

    printf("\nPlaintext  : %s", plaintext);
    printf("Ciphertext : %s", ciphertext);

    return 0;
}

