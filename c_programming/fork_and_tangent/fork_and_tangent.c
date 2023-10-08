// File: tangent_and_fork.c

#include <stdio.h>
#include <math.h>
#include <unistd.h>

int main() {
    // Fork the process
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        printf("Child process: PID=%d\n", getpid());
    } else if (pid > 0) {
        // Parent process
        printf("Parent process: PID=%d\n", getpid());
    } else {
        // Fork failed
        fprintf(stderr, "Fork failed!\n");
        return 1;
    }

    // Calculate tangent
    double angle = 1.0;  // Angle in radians
    double tangent_value = tan(angle);

    printf("Tangent of %f radians is %f\n", angle, tangent_value);

    return 0;
}
