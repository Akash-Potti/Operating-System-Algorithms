#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, n;
    int bt[10], p[10], compt[10], wt[10], tat[10];
    int temp1, temp2;
    float sumwt = 0.0, sumtat = 0.0;

    printf("enter the number of processes \n");
    scanf("%d", &n);

    printf("enter the burst time of the processes \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }
    printf("enter the priority of the processes \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (p[i] > p[j])
            {
                temp1 = bt[i];
                bt[i] = bt[j];
                bt[j] = temp1;
                temp2 = p[i];
                p[i] = p[j];
                p[j] = temp2;
            }
        }
        compt[0] = bt[0];
        wt[0] = 0;

        for (i = 0; i < n; i++)
        {
            compt[i] = compt[i - 1] + bt[i];
        }

        for (i = 0; i < n; i++)
        {
            tat[i] = compt[i];
            wt[i] = tat[i] - bt[i];
            sumtat = sumtat + tat[i];
            sumwt = sumwt + wt[i];
        }
        printf("TOTAL WAITING TIME = %.2f\n", sumwt);
        printf("AVERAGE WAITING TIME = %.2f\n", sumwt / n);
        printf("TOTAL TURNAROUND TIME = %.2f\n", sumtat);
        printf("AVERAGE TURNAROUND TIME = %.2f\n", sumtat / n);
    }
}