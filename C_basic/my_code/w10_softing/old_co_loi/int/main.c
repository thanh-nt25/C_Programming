#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utils.h"

#include "sortInt.h"
#define MAX (50000)
#define MAX_DISP (20)

int main() {
    printf("rand_max: %d\n size: %ld\n", RAND_MAX, sizeof(RAND_MAX));

    uint64_t t1, t2, t3, t4;
    T a[MAX], b[MAX];

    srand(time(NULL));
    for (int i = 0; i < MAX; i++) a[i] = rand()%10000;
    for (int i = 0; i < MAX; i++) b[i] = a[i];



    printf("\n--- Insertion Sort ---\n");

    for (int i = 0; i < MAX_DISP; i++) printf("%d ", a[i]);
    printf("\n");

    t1 = GetTimeStamp();
    insertion_sort(a, MAX);
    t2 = GetTimeStamp();

    for (int i = 0; i < MAX_DISP; i++) printf("%d ", a[i]);
    printf("\n");
    printf("Duration in seconds: %d\n", (int)(t2 - t1));




    printf("\n--- Heap Sort ---\n");
    for (int i = 0; i < MAX_DISP; i++) printf("%d ", b[i]);
    printf("\n");

    t1 = GetTimeStamp();
    sortHeap(b, MAX);
    t2 = GetTimeStamp();
    for (int i = 0; i < MAX_DISP; i++) printf("%d ", b[i]);
    printf("\n");

    return EXIT_SUCCESS;
}