
#include <stdio.h>
#include <string.h>

int main()
{
    int key[56];
    int C[28], D[28];
    int subkey[16][48];

    int shift[16] = {
        1, 1, 2, 2, 2, 2, 2, 2,
        1, 2, 2, 2, 2, 2, 2, 1
    };

    int i, j, k, r;

    // Read the 56-bit key
    printf("Enter 56-bit key (0 or 1):\n");

    for(i = 0; i < 56; i++)
        scanf("%1d", &key[i]);

    // Divide key into two 28-bit halves
    for(i = 0; i < 28; i++)
    {
        C[i] = key[i];
        D[i] = key[i + 28];
    }

    // Generate 16 subkeys
    for(r = 0; r < 16; r++)
    {
        // Circular left shift of C and D
        for(j = 0; j < shift[r]; j++)
        {
            int tempC = C[0];
            int tempD = D[0];

            for(k = 0; k < 27; k++)
            {
                C[k] = C[k + 1];
                D[k] = D[k + 1];
            }

            C[27] = tempC;
            D[27] = tempD;
        }

        // First 24 bits from C
        for(i = 0; i < 24; i++)
            subkey[r][i] = C[i];

        // Second 24 bits from disjoint D
        for(i = 0; i < 24; i++)
            subkey[r][i + 24] = D[i];

    }

    // Display generated subkeys
    printf("\nDES Subkeys:\n");

    for(r = 0; r < 16; r++)
    {
        printf("\nRound %2d: ", r + 1);

        for(i = 0; i < 48; i++)
            printf("%d", subkey[r][i]);
    }

    printf("\n");

    return 0;
}

