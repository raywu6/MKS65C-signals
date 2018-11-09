#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void sighandler (int signo) {
  if (signo == SIGUSR1)
    printf("My parent pid is %d <3\n", getppid() );

  else if (signo == SIGINT) {
    printf("Booyah! Exiting due to SIGINT. :)\n");
    exit(EXIT_SUCCESS);
  }
}

int main() {
  signal( SIGUSR1 , sighandler  );
  signal( SIGINT  , sighandler  );

  while (1) {
    printf("Hello, I'm %d\n", getpid() );
    sleep(1);
  }

  return 0;
}
