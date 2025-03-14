#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_SIZE (512*1024*1024)

int main()
{
    clock_t start, end;
    double cpu_time;
    int i = 0;
    int j = 0;

    int *arr = (int*)malloc(MAX_SIZE * sizeof(int));

    if (arr == NULL) {
      printf("Asignacion de memoria a la variable 'arr' fallo");
      return 1;
    }

    printf("\nLoop 2\n");
    for (j = 1 ; j <= 1024 ; j <<= 1)
    {
        start = clock();

        /* Loop 2 */
        for (i = 0; i < MAX_SIZE; i += j)
            arr[i] += 3;

        end = clock();

        cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("\tCPU time for (j = %d) %.6f secs.\n", j, cpu_time);
    }

    free(arr);
    return 0;
}
