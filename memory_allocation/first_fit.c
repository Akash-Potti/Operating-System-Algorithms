#include <stdio.h>
int main()
{
    int i, j;
    int nb, b[10];
    int np, p[10];

    printf("enter the number of free blocks\n");
    scanf("%d", &nb);

    printf("enter the size of the blocks\n");
    for (i = 0; i < nb; i++)
    {
        scanf("%d", &b[i]);
    }
    printf("enter the number of processes\n");
    scanf("%d", &np);
    for (i = 0; i < np; i++)
    {
        printf("enter the size of the process %d\n", i + 1);
        scanf("%d", &p[i]);
    }

    printf("First Fit\n");
    printf("Process\tBlock\tBlock Size\tRemaining Block Size\n");

    i = 0;
    while (i < np)
    {
        for (j = 0; j < nb; j++)
        {
            if (p[i] <= b[j])
            {
                b[j] -= p[i];
                printf("%d\t%d\t%d\t\t%d\n", i + 1, j + 1, p[i], b[j]);
                break;
            }
        }
        i++;
    }
    return 0;
}