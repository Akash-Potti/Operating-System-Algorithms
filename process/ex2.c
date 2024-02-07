#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    printf("executing ex2.c\n");
    printf("Process id of ex2.c: %d\n", getpid());
    return 0;
}
