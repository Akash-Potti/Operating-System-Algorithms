#include <stdio.h>
#include <stdlib.h>

int mutex = 1, full = 0, empty = 3, x = 0, i = 1;

int wait(int s)
{
    return (--s);
}

int signal(int s)
{
    return (++s);
}

void producer()
{
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    x++;
    printf("producer produces the item %d\n", x);
    mutex = signal(mutex);
}
void consumer()
{
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("\n Consumer consumes item = %d", x);
    while (i <= x)
    {
        printf("\n Consumer consumes item %d", i);
        i++;
        full = wait(full);
        empty = signal(empty);
    }
    mutex = signal(mutex);
}

int main()
{
    int n;
    printf("\n 1) Producer\n 2) Consumer\n 3) Exit");
    while (1)
    {
        printf("enter your choice");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            if ((mutex == 1) && (empty != 0))
                producer();
            else
                printf("Buffer is full");
            break;
        case 2:
            if ((mutex == 1) && (full != 0))
                consumer();
            else
                printf("Buffer is empty");
            break;

        default:
            break;
        }
    }
    return 0;
}