#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

#define NUM_ITERATIONS 1000000

int main() {
    struct timeval start, end;
    double elapsed_time;
    int i;

    // Start measuring time
    gettimeofday(&start, NULL);

    for (i = 0; i < NUM_ITERATIONS; i++) {
        // Perform a 0-byte read as a simple system call
        read(0, NULL, 0);
    }

    // End measuring time
    gettimeofday(&end, NULL);

    // Calculate elapsed time in microseconds
    elapsed_time = (end.tv_sec - start.tv_sec) * 1000000.0;  // seconds to microseconds
    elapsed_time += (end.tv_usec - start.tv_usec);

    // Calculate average time per iteration
    double average_time_per_iteration = elapsed_time / NUM_ITERATIONS;

    printf("Total elapsed time: %.2f microseconds\n", elapsed_time);
    printf("Average time per iteration: %.2f microseconds\n", average_time_per_iteration);

    return 0;
}
