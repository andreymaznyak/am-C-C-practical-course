#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main(int argc, char* argv[], char* env[]) {
	
	//argc ��� ���������� ��������� � ������� argv
	printf("������� ��������� ��������� � main \n � ������� argv %d ���������:\n" , argc);
	int i = 0;
	while(i < argc){
		printf("%d. %s \n " , i, argv[i]);
		i++;
	}
	
	//�.�. �� �� ����� ���-�� ��������� � env ���� �� ������� ���� ��������� �� ����� ����� 0.
	printf("������ env: \n");
	int j = 0;
	while( env[j] != NULL ){
		printf("%d. %s\n" ,j ,env[j]);
		j++;
	}

	exit(0);
}
