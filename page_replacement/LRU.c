#include <stdio.h>

void display(int frsize, int fr[])
{
    printf("\n ");
    for (int i = 0; i < frsize; i++)
    {
        printf(" %d\t", fr[i]);
    }
}

int main()
{
    int i, j, page[20] = {7, 2, 3, 1, 2, 5, 3, 4, 6, 7, 7, 1, 0, 5, 4, 6, 2, 3, 0, 1};
    int flag1 = 0, flag2 = 0, pf = 0, frsize = 3;
    int fs[3], index, k, l;
    int fr[3];

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
            for (i = 0; i < frsize; i++)
            {
                fs[i] = 0;
            }

            for (k = j - 1, l = 1; l <= frsize - 1; l++, k--)
            {
                for (i = 0; i < frsize; i++)
                {
                    if (fr[i] == page[k])
                    {
                        fs[i] = 1;
                    }
                }
            }

            for (i = 0; i < 3; i++)
            {
                if (fs[i] == 0)
                {
                    index = i;
                    break;
                }
            }

            fr[index] = page[j];
            pf++;
        }

        display(frsize, fr);
    }

    return 0;
}
