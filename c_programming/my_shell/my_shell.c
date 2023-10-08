#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <sys/types.h>

#include <sys/wait.h>

#include <string.h>

#define MAXLINE 1024 // Maximum input line length
#define MAXARGS 128 // Maximum arguments

// Function to parse the command line into arguments
void parsecmd(char * cmdline, char ** argv) {
  char * token;
  int i = 0;

  // Tokenize the command line based on spaces
  token = strtok(cmdline, " \t\n");
  while (token != NULL) {
    argv[i++] = token;
    token = strtok(NULL, " \t\n");
  }
  argv[i] = NULL; // Set the last argument to NULL
}

// Function to check if a command is built-in (e.g., exit or custom commands)
int builtin_command(char ** argv) {
  if (strcmp(argv[0], "exit") == 0) {
    exit(0);
  } else if (strcmp(argv[0], "owner") == 0) {
    printf("habib\n");
    return 1; // Return 1 to indicate a built-in command was executed
  }
  return 0;
}

int main(void) {
  char cmdline[MAXLINE];
  char * argv[MAXARGS];
  pid_t pid;
  int status;

  while (1) {
    // Display a prompt and get the command from the user
    printf("my_shell> ");
    if (fgets(cmdline, MAXLINE, stdin) == NULL) {
      perror("Error reading input");
      exit(1);
    }

    // Remove the newline character from the command line
    cmdline[strcspn(cmdline, "\n")] = '\0';

    // Parse the command line into arguments
    parsecmd(cmdline, argv);

    // Check if the command is built-in (e.g., exit or custom commands)
    if (!builtin_command(argv)) {
      // Fork a new process
      if ((pid = fork()) == 0) {
        // Child process: execute the command
        if (execvp(argv[0], argv) < 0) {
          printf("%s: command not found\n", argv[0]);
          exit(0);
        }
      }

      // Parent process: wait for the child to finish
      waitpid(pid, & status, 0);
    }
  }

  return 0;
}