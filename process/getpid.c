#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
    printf("Process id: %d\n", getpid());
    return 0;
}