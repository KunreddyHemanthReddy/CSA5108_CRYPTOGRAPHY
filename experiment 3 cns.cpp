
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5];

void generateMatrix(char key[])
{
    int used[26] = {0};
    int i, j, k = 0;
    char ch;

    used['J' - 'A'] = 1;

    for (i = 0; key[i] != '\0'; i++)
    {
        ch = toupper(key[i]);

        if (ch >= 'A' && ch <= 'Z')
        {
            if (ch == 'J')
                ch = 'I';

            if (!used[ch - 'A'])
            {
                matrix[k / 5][k % 5] = ch;
                used[ch - 'A'] = 1;
                k++;
            }
        }
    }

    for (ch = 'A'; ch <= 'Z'; ch++)
    {
        if (!used[ch - 'A'])
        {
            matrix[k / 5][k % 5] = ch;
            k++;
        }
    }
}

void encrypt(char text[])
{
    int i, r1, c1, r2, c2, j;
    char a, b;

    char result[200];
    j = 0;

    for (i = 0; text[i] != '\0'; i++)
    {
        a = toupper(text[i]);

        if (a < 'A' || a > 'Z')
            continue;

        if (a == 'J')
            a = 'I';

        if (j > 0 && result[j - 1] == a)
            result[j++] = 'X';

        result[j++] = a;
    }

    if (j % 2 != 0)
        result[j++] = 'X';

    result[j] = '\0';

    printf("\nEncrypted text: ");

    for (i = 0; i < j; i += 2)
    {
        a = result[i];
        b = result[i + 1];

        for (r1 = 0; r1 < 5; r1++)
            for (c1 = 0; c1 < 5; c1++)
            {
                if (matrix[r1][c1] == a)
                    goto found1;
            }

        found1:

        for (r2 = 0; r2 < 5; r2++)
            for (c2 = 0; c2 < 5; c2++)
            {
                if (matrix[r2][c2] == b)
                    goto found2;
            }

        found2:

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
}

int main()
{
    char key[100], text[200];
    int i, j;

    printf("Enter keyword: ");
    scanf("%99s", key);

    printf("Enter plaintext: ");
    scanf(" %199[^\n]", text);

    generateMatrix(key);

    printf("\n5 x 5 Playfair Matrix:\n");

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
            printf("%c ", matrix[i][j]);

        printf("\n");
    }

    encrypt(text);

    return 0;
}

