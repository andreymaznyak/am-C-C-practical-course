#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main(int argc, char** argv) { 
  pid_t pid = fork();
  if (pid == 0){
    execl("./l2", "1", "2",  "3", "4", (char*)0);
    exit(0);
  }

  wait(NULL);
  exit(0);
}
