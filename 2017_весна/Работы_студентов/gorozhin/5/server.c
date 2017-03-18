#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <time.h>

#include <sys/types.h>
#include <sys/stat.h>


void main(int argc, char** argv) { 
  int fifo = mkfifo("fifo", 0666);
  
  int fd = open("fifo", O_WRONLY);
  srand(time(NULL));
  for(char i = rand()%10;  ;i=(rand())%10){
    write(fd, &i, sizeof(char));
    //printf("writing :: %d\n", i);
    sleep(1);
  }
}
