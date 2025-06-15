#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
// Global array for Fibonacci numbers
int sequence[50]; 

void generate_fibonacci(int count) {
    sequence[0] = 0;
    if (count > 1)
        sequence[1] = 1;
    
    for (int i = 2; i < count; ++i) {
        sequence[i] = sequence[i - 1] + sequence[i - 2];
    }
}

void display_fibonacci(int count) {
    for (int i = 0; i < count; ++i) {
        printf("%d ", sequence[i]);
    }
    printf("\n");
}

int main() {
    int terms;
    pid_t child_pid;

    printf("Enter the number of Fibonacci terms: ");
    scanf("%d", &terms);

    if (terms < 1 || terms > 50) {
        fprintf(stderr, "Please enter a number between 1 and 50.\n");
        return 1;
    }

    child_pid = fork();

    if (child_pid < 0) {
        perror("Process creation failed");
        return 1;
    } else if (child_pid == 0) {
        // Child process
        generate_fibonacci(terms);
        printf("\n[Child Process] PID: %d\n", getpid());
        printf("Fibonacci Sequence: ");
        display_fibonacci(terms);
        printf("[Child Process] Computation complete. Exiting...\n");
        exit(0);
    } else {
        // Parent process
        wait(NULL);
        printf("\n[Parent Process] PID: %d\n", getpid());
        printf("Child process has completed execution.\n");
    }

    return 0;
}

