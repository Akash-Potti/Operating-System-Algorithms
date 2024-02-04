#include <stdio.h>

int main()
{
    int b[20], p[20], nb, np, i, j;

    printf("Enter the number of blocks: ");
    scanf("%d", &nb);
    for (i = 0; i < nb; i++)
    {
        printf("Enter the size of block %d: ", i + 1);
        scanf("%d", &b[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &np);
    for (i = 0; i < np; i++)
    {
        printf("Enter the size of process %d: ", i + 1);
        scanf("%d", &p[i]);
    }

    for (i = 0; i < np; i++)
    {
        int bestfitblock = -1;
        for (j = 0; j < nb; j++)
        {
            if (p[i] <= b[j])
            {
                if (bestfitblock == -1 || b[j] < b[bestfitblock])
                {
                    bestfitblock = j;
                }
            }
        }

        if (bestfitblock != -1)
        {
            printf("Process %d allocated to Block %d\n", i, bestfitblock);
            b[bestfitblock] -= p[i];
        }
        else
        {
            printf("Process %d cannot be allocated\n", i);
        }
    }
}