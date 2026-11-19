
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char plaintext[100], key[100];
    int i, j = 0, shift;

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter key: ");
    scanf("%99s", key);

    printf("\nEncrypted text: ");

    for (i = 0; plaintext[i] != '\0'; i++)
    {
        if (isalpha(plaintext[i]))
        {
            shift = toupper(key[j % strlen(key)]) - 'A';

            if (isupper(plaintext[i]))
                printf("%c", ((plaintext[i] - 'A' + shift) % 26) + 'A');
            else
                printf("%c", ((plaintext[i] - 'a' + shift) % 26) + 'a');

            j++;
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");

    return 0;
}

