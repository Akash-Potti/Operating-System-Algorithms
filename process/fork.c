#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    fork();
    fork();
    printf("process id: %d\n", getpid());
    return 0;
}
