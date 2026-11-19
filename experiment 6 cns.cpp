
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int modInverse(int a)
{
    int i;

    for (i = 0; i < 26; i++)
    {
        if ((a * i) % 26 == 1)
            return i;
    }

    return -1;
}

int main()
{
    char cipher[1000];
    int a, b, i, p;
    int inv;

    printf("Enter ciphertext: ");
    fgets(cipher, sizeof(cipher), stdin);

    // Frequency analysis assumptions:
    // B represents E
    // U represents T

    int C1 = 'B' - 'A';  // 1
    int C2 = 'U' - 'A';  // 20

    int P1 = 'E' - 'A';  // 4
    int P2 = 'T' - 'A';  // 19

    printf("\nPossible affine cipher keys:\n");

    for (a = 1; a < 26; a++)
    {
        if (a % 2 == 0 || a % 13 == 0)
            continue;

        b = (C1 - a * P1) % 26;

        if (b < 0)
            b += 26;

        if ((a * P2 + b) % 26 == C2)
        {
            printf("\na = %d, b = %d\n", a, b);

            inv = modInverse(a);

            printf("Decrypted text: ");

            for (i = 0; cipher[i] != '\0'; i++)
            {
                if (isupper(cipher[i]))
                {
                    int c = cipher[i] - 'A';
                    p = (inv * (c - b + 26)) % 26;
                    printf("%c", p + 'A');
                }
                else if (islower(cipher[i]))
                {
                    int c = cipher[i] - 'a';
                    p = (inv * (c - b + 26)) % 26;
                    printf("%c", p + 'a');
                }
                else
                {
                    printf("%c", cipher[i]);
                }
            }

            printf("\n");
        }
    }

    return 0;
}

