#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  printf("Hello world (pid: %d)\n", (int) getpid());
  int rc = fork();

  if (rc < 0) {
    fprintf(stderr, "Fork failed\n");
  } else if (rc == 0) {
    printf("Hello, I am child (pid: %d)\n", (int) getpid());

    char *my_args[3];
    my_args[0] = strdup("wc");
    my_args[1] = strdup("exec.c");
    my_args[2] = NULL;

    execvp(my_args[0], my_args);
    printf("This shouldn't print out");
  } else {
    int wc = wait(NULL);
    printf("Hello, I am parent of %d (wc: %d) (pid: %d)\n", rc, wc, (int) getpid());
  }

  return 0;
}
