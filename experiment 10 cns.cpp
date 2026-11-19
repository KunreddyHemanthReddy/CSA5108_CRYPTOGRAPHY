
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5] = {
    {'M','F','H','I','K'},
    {'U','N','O','P','Q'},
    {'Z','V','W','X','Y'},
    {'E','L','A','R','G'},
    {'D','S','T','B','C'}
};

void findPosition(char ch, int *row, int *col)
{
    int i, j;

    if (ch == 'J')
        ch = 'I';

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (matrix[i][j] == ch)
            {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

int main()
{
    char plaintext[200], text[200];
    int i, j = 0;
    int r1, c1, r2, c2;

    printf("Enter plaintext:\n");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Remove spaces and special characters
    for (i = 0; plaintext[i] != '\0'; i++)
    {
        if (isalpha((unsigned char)plaintext[i]))
        {
            char ch = toupper((unsigned char)plaintext[i]);

            if (ch == 'J')
                ch = 'I';

            text[j++] = ch;
        }
    }

    text[j] = '\0';

    // Prepare pairs of letters
    char prepared[200];
    int k = 0;

    for (i = 0; i < j; )
    {
        prepared[k++] = text[i++];

        if (i < j && text[i] == prepared[k - 1])
        {
            prepared[k++] = 'X';
        }
        else if (i < j)
        {
            prepared[k++] = text[i++];
        }
        else
        {
            prepared[k++] = 'X';
        }
    }

    prepared[k] = '\0';

    printf("\nEncrypted message: ");

    // Encryption
    for (i = 0; i < k; i += 2)
    {
        findPosition(prepared[i], &r1, &c1);
        findPosition(prepared[i + 1], &r2, &c2);

        if (r1 == r2)
        {
            printf("%c%c",
                matrix[r1][(c1 + 1) % 5],
                matrix[r2][(c2 + 1) % 5]);
        }
        else if (c1 == c2)
        {
            printf("%c%c",
                matrix[(r1 + 1) % 5][c1],
                matrix[(r2 + 1) % 5][c2]);
        }
        else
        {
            printf("%c%c",
                matrix[r1][c2],
                matrix[r2][c1]);
        }
    }

    printf("\n");

    return 0;
}

