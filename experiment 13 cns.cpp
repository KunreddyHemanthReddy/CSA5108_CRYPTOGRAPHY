
#include <stdio.h>

int main()
{
    int P[2][2], C[2][2];
    int K[2][2];
    int det, inv, i, j;

    printf("Enter plaintext matrix (2x2):\n");

    for(i = 0; i < 2; i++)
        for(j = 0; j < 2; j++)
            scanf("%d", &P[i][j]);

    printf("Enter ciphertext matrix (2x2):\n");

    for(i = 0; i < 2; i++)
        for(j = 0; j < 2; j++)
            scanf("%d", &C[i][j]);

    // Calculate determinant of plaintext matrix
    det = (P[0][0] * P[1][1] -
           P[0][1] * P[1][0]) % 26;

    if(det < 0)
        det += 26;

    // Find modular inverse of determinant
    inv = -1;

    for(i = 1; i < 26; i++)
    {
        if((det * i) % 26 == 1)
        {
            inv = i;
            break;
        }
    }

    if(inv == -1)
    {
        printf("Cannot recover key: "
               "plaintext matrix has no inverse.\n");
        return 0;
    }

    // Calculate inverse of plaintext matrix
    int PI[2][2];

    PI[0][0] = (P[1][1] * inv) % 26;
    PI[0][1] = (-P[0][1] * inv % 26 + 26) % 26;
    PI[1][0] = (-P[1][0] * inv % 26 + 26) % 26;
    PI[1][1] = (P[0][0] * inv) % 26;

    // Calculate key matrix K = C * P inverse
    printf("\nRecovered Key Matrix:\n");

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            K[i][j] = 0;

            for(int k = 0; k < 2; k++)
                K[i][j] += C[i][k] * PI[k][j];

            K[i][j] %= 26;

            printf("%d ", K[i][j]);
        }

        printf("\n");
    }

    return 0;
}

