#include <stdio.h>
#include <stdlib.h>

int main()
{
    int total_head_movement = 0;
    int initial_head_position;
    int i, n;
    printf("enter the no of cylinders in req queue: \n");
    scanf("%d", &n);
    int *req_queue = (int *)malloc(n * sizeof(int));

    printf("enter the cylinder no in req queue: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &req_queue[i]);
    }
    printf("enter the initial head position: \n");
    scanf("%d", &initial_head_position);

    for (i = 0; i < n; i++)
    {
        total_head_movement += abs(initial_head_position - req_queue[i]);
        initial_head_position = req_queue[i];
    }

    printf("total head movement is %d\n", total_head_movement);
    printf("average head movement is %f\n", (float)total_head_movement / n);
    free(req_queue);
    return 0;
}