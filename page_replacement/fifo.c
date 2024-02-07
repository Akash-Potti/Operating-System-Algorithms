#include <stdio.h>

void display(int fr[], int frsize);

int main()
{
    int i, j, page[20] = {7, 2, 3, 1, 2, 5, 3, 4, 6, 7, 7, 1, 0, 5, 4, 6, 2, 3, 0, 1};
    int fr[3], flag1 = 0, flag2 = 0, frsize = 3, pf = 0, top = 0;

    for (i = 0; i < frsize; i++)
    {
        fr[i] = -1;
    }

    for (j = 0; j < 20; j++)
    {
        flag1 = 0;
        flag2 = 0;

        for (i = 0; i < frsize; i++)
        {
            if (fr[i] == page[j])
            {
                flag1 = 1;
                flag2 = 1;
                break;
            }
        }
        if (flag1 == 0)
        {
            for (i = 0; i < frsize; i++)
            {
                if (fr[i] == -1)
                {
                    fr[i] = page[j];
                    flag2 = 1;
                    break;
                }
            }
        }
        if (flag2 == 0)
        {
            fr[top] = page[j];
            top++;
            pf++;
        }
        display(fr, frsize);
    }
    printf("\n The number of page faults is %d", pf);
    return 0;
}

void display(int fr[], int frsize)
{
    int i;
    printf("\n");
    for (i = 0; i < frsize; i++)
    {
        printf("%d\t", fr[i]);
    }
}
