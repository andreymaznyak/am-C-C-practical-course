#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
main()
{
  pid_t pid;
  int rv;
  switch(pid=fork()) {
  case -1:
          perror("fork"); /* ��������� ������ */
          exit(1); /*����� �� ������������� ��������*/
  case 0:
          printf(" CHILD: ��� �������-�������!\n");
          printf(" CHILD: ��� PID -- %d\n", getpid());
          printf(" CHILD: PID ����� �������� -- %d\n",
              getppid());
          printf(" CHILD: ������� ��� ��� �������� 
                         (��� ����� ������):");
          scanf(" %d");
          printf(" CHILD: �����!\n");
          exit(rv);
  default:
          printf("PARENT: ��� �������-��������!\n");
          printf("PARENT: ��� PID -- %d\n", getpid());
          printf("PARENT: PID ����� ������� %d\n",pid);
          printf("PARENT: � ���, ���� �������
                          �� ������� exit()...\n");
          wait();
          printf("PARENT: ��� �������� �������:%d\n",
                   WEXITSTATUS(rv));
          printf("PARENT: �����!\n");
  }
}
