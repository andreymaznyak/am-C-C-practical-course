#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#define EXTEND "����� ���"
#define STOP "��������� ������"

#define parent "����"
#define child "����"

/* ���� 21'
	���� � ������� ��������� ������.
	������ ����� �� ������� � ������� �����.
	���� ���� ��� �� ������� ����� ��������� ��� � �������� � ���������� ����� 31.
	���� ����� ����� ������ 21' �� �� ������������. ������ ����� ���-�� ����� ���� �����.
	����� ������������ � �� ������� �����. ���������� ��� � ���� ����� ����� ������.
	2 �������� ����� ������ � ��� ����.
*/
int main(int argc, char* argv[], char* env[]) {
	printf("\n �������� ������ � 21'. \n");
	
	srand(time(NULL));
	
	int fdp[2],fdc[2], p_id;
	size_t size;
	int i = 0;
	int chat = 1;
	
	int dice = 0;
	int dice1 = 1;
	
	char* msg_list[] = {EXTEND,
						STOP};
	char msg[64];
	
	if(pipe(fdc) < 0){
		printf("Can\'t �� ���������� ������� ����� :(\n");
		exit(-1); 
	} 
	if(pipe(fdp) < 0){
		printf("Can\'t �� ���������� ������� ����� :(\n");
		exit(-1); 
	} 
	printf("%s ������� ������� %s ������ � 21 ���������� ������� \n", parent, child);
	p_id = fork(); 

	if(p_id < 0){ 
		printf("� %s �� ���������� ������� %s.\n", parent, child);
		exit(-1);
	}
	
	if (p_id > 0) {
		/*parent*/
		close(fdc[0]);
		close(fdp[1]);	
		int parent_count = 0;
		int extend = 0;
		
		while (chat > 0){
			
			
		
			size = write(fdc[1], msg_list[extend], 64);
			
			// �������� ������� ������� ����� � ��������� ��� ��� ��� ���
			if(rand()%2 == 1){
			printf("%s : %s \n", parent, EXTEND);
			extend = 0;
			} else {
			printf("%s : %s \n", parent , STOP);
			extend = 1;
			}
			
			while (size = read(fdp[0], msg, 64) < 0);
		
			printf( "%s ��� ������: %s\n" , child , msg );
			
			printf( "%s: ������ ����� \n" , parent );
			dice1 = (rand()%6)+7;
			parent_count = parent_count + dice1;
			printf("%s: � ���� ������ %d !\n", parent ,dice1 );
			
			if (strcmp(msg, msg_list[1]) == 0){
				chat = -1;
				printf("%s: ����� � ���� %d �����", parent , parent_count);
				}
			i++;
		}
		
		close(fdc[1]);
		close(fdp[0]);
		printf("\n %s ������ ����� \n", parent);
	} else {
		printf( "\n %s ������ ����� %s \n" , child , parent );
		/*child*/
		close(fdc[1]);
		close(fdp[0]);
		
		int child_count = 0;
		int extend = 0;
		while (chat > 0){
			while (size = read(fdc[0], msg, 64) < 0);
			
			printf( "%s ��� ������: %s\n" , parent , msg );
			
			
			
			size = write(fdp[1], msg_list[extend], 64);
			
			if(rand()%2 == 1){
			printf("%s : %s \n", child, EXTEND);
			extend = 0;
			} else {
			printf("%s : %s \n", child , STOP);
			extend = 1;
			}
			
			printf( "%s: ������ ����� \n" , child );
			dice = (rand()%6)+1;
			child_count = child_count + dice;
			printf("%s: � ���� ������ %d !\n", child ,dice );
			
			if (strcmp(msg, msg_list[1]) == 0){
				chat = -1;
				printf("%s: ����� � ���� %d �����", child,child_count);
				}
			i++;
		}
		
		close(fdp[1]);	
		close(fdc[0]);
		printf("\n %s ������ ����� \n", child);
	}
	exit(0);
}
