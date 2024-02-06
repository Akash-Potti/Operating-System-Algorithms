#include <stdio.h>

int main()
{
    int p, r;
    int count = 0;
    int i, j;
    int aloc[10][10], max[10][10], need[10][10];
    int safe[10];
    int avail[5];
    int done[5];
    int finish = 0;

    printf("Enter the number of process and resources\n");
    scanf("%d%d", &p, &r);

    printf("Enter the allocation of resources of all processes %dx%d matrix\n", p, r);
    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            scanf("%d", &aloc[i][j]);

    printf("Enter the max of resources of all processes %dx%d matrix\n", p, r);
    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            scanf("%d", &max[i][j]);

    printf("Enter the available resources \n");
    for (i = 0; i < r; i++)
        scanf("%d", &avail[i]);

    printf("need matrix\n");
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < r; j++)
        {
            need[i][j] = max[i][j] - aloc[i][j];
            printf("%d\t", need[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < p; i++)
        done[i] = 0;

    while (count < p)
    {
        for (i = 0; i < p; i++)
        {
            if (done[i] == 0)
            {
                for (j = 0; j < r; j++)
                {
                    if (need[i][j] > avail[j])
                        break;
                }
                if (j == r)
                {
                    safe[count] = i;
                    done[i] = 1;
                    for (j = 0; j < r; j++)
                    {
                        avail[j] += aloc[i][j];
                    }
                    count++;
                }
                else
                {
                    finish++;
                }
            }
        }
        if (finish == (p - 1))
        {
            printf("Safe sequence does not exist");
            break;
        }
    }

    if (finish != (p - 1))
    {
        printf("\nAvailable resource after completion\n");
        for (i = 0; i < r; i++)
        {
            printf("%d\t", avail[i]);
        }
        printf("\nSafe Sequence are\n");
        for (i = 0; i < p; i++)
        {
            printf("%d\t", safe[i]);
        }
    }

    return 0;
}
