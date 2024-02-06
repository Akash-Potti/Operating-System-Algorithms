#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t[20], d[20], h, i, j, n, temp, k, atr[20], tot, p, sum = 0;

    printf("Enter the number of tracks: ");
    scanf("%d", &n);

    printf("Enter the position of the head: ");
    scanf("%d", &h);

    t[0] = 0;
    t[1] = h;

    printf("Enter the total number of tracks: ");
    scanf("%d", &tot);

    t[2] = tot - 1;

    printf("Enter the tracks:\n");
    for (i = 3; i < n + 3; i++)
    {
        scanf("%d", &t[i]);
    }

    // Sorting tracks in ascending order
    for (i = 0; i < n + 3; i++)
    {
        for (j = 0; j < n + 3 - i - 1; j++)
        {
            if (t[j] > t[j + 1])
            {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }

    // Finding head position index
    for (i = 0; i < n + 3; i++)
    {
        if (t[i] == h)
        {
            k = i;
            break;
        }
    }

    // Storing tracks in atr[] in order
    p = 0;
    while (t[k] != tot - 1)
    {
        atr[p] = t[k];
        p++;
        k++;
    }
    atr[p] = t[k];
    p++;
    i = 0;
    while (p != n + 2 && t[i] != h)
    {
        atr[p] = t[i];
        p++;
        i++;
    }

    // Calculating head movements
    for (i = 0; i < n + 2; i++)
    {
        if (atr[i] > atr[i + 1])
        {
            d[i] = atr[i] - atr[i + 1];
        }
        else
        {
            d[i] = atr[i + 1] - atr[i];
        }
        sum = sum + d[i];
    }

    // Printing results
    printf("Total head movement: %d\n", sum);
    printf("Average head movement: %.2f\n", (float)sum / n);

    return 0;
}
