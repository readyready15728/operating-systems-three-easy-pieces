#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
  int rc = fork();

  if (rc < 0) {
    fprintf(stderr, "Fork failed\n");
    exit(1);
  } else if (rc == 0) {
    close(STDOUT_FILENO);
    // open("redirection.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    int f = open("redirection.txt", O_CREAT | O_WRONLY | O_TRUNC);
    fchmod(f, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    char *my_args[3];
    my_args[0] = strdup("wc");
    my_args[1] = strdup("redirection.c");
    my_args[2] = NULL;
    execvp(my_args[0], my_args);
  } else {
    int wc = wait(NULL);
  }

  return 0;
}
