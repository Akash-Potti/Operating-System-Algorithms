#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    printf("Process id of ex1.c: %d\n", getpid());
    char *args[] = {"computer", "science", "hub", NULL}; // Rename argv to args
    execv("ex2", args);
    printf("back to ex1.c\n");
    return 0;
}
