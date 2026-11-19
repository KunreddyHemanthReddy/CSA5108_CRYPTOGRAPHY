
#include <stdio.h>
#include <ctype.h>

int main()
{
    char plaintext[100];
    int a, b, i, p, c;

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter value of a: ");
    scanf("%d", &a);

    printf("Enter value of b: ");
    scanf("%d", &b);

    // Check whether a is valid
    if (a % 2 == 0 || a % 13 == 0)
    {
        printf("Invalid value of a!\n");
        printf("a must be coprime with 26.\n");
        return 0;
    }

    printf("\nEncrypted text: ");

    for (i = 0; plaintext[i] != '\0'; i++)
    {
        if (isupper(plaintext[i]))
        {
            p = plaintext[i] - 'A';
            c = (a * p + b) % 26;
            printf("%c", c + 'A');
        }
        else if (islower(plaintext[i]))
        {
            p = plaintext[i] - 'a';
            c = (a * p + b) % 26;
            printf("%c", c + 'a');
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");

    return 0;
}

