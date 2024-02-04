#include <stdio.h>

int main()
{
    int i, n;
    int sum, wt, twt, ttat, tat;
    int bt[10];
    float avgwt, avgtat;

    printf("enter the number of processes\n");
    scanf("%d", &n);
    printf("enter the burst time of the processes\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }
    printf("\nFCFS Scheduling\n");
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

    printf("1 \t\t\t 0 \t\t\t %d\n", bt[0]);

    sum = 0;
    twt = 0;
    ttat = bt[0];
    for (i = 1; i < n; i++)
    {
        sum = sum + bt[i - 1];
        wt = sum;
        twt = twt + wt;
        tat = sum + bt[i];
        ttat = ttat + tat;

        printf("\n Process = %d \t\t Waiting Time = %d \t\t Turn Around Time = %d", i + 1, wt, tat);
        printf("\n\n");
    }
    avgwt = (float)twt / n;
    avgtat = (float)ttat / n;
    printf("\n Average Waiting Time = %4.2f", avgwt);
    printf("\n Average Turn Around Time = %4.2f", avgtat);
    return 0;
}
