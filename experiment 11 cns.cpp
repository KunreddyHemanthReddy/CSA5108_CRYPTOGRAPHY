
#include <stdio.h>
#include <math.h>

int main()
{
    double keys = 1;
    double power;
    int i;

    // Calculate 25 factorial
    for (i = 1; i <= 25; i++)
    {
        keys = keys * i;
    }

    // Calculate log base 2
    power = log(keys) / log(2);

    printf("Total number of possible keys = %.0f\n", keys);

    printf("Number of keys as power of 2 = 2^%.2f\n", power);

    printf("Approximate answer = 2^84\n");

    return 0;
}

