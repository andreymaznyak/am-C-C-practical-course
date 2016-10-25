#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <malloc.h>

#define N 3

struct Student
{
	char* name;
	int groupNumber;
	int progress[5];
	float middleMark;
};


int main()
{
	FILE* fin = fopen("input.txt", "rt");
	FILE* fout = fopen("output.txt", "wt");

	Student* s[N];
	for (int i = 0; i<N; ++i)
	{
		s[i] = (Student*)malloc(sizeof(Student));
		printf("Enter full name: ");
		s[i]->name = (char*)malloc(256);
		fscanf(fin, "%s", &s[i]->name);
		printf("Enter group number: ");
		fscanf(fin, "%d", &s[i]->groupNumber);
		printf("Enter 5 marks: ");
		s[i]->middleMark = 0;
		for (int j = 0; j < 5; ++j)
		{
			fscanf(fin, "%d", &s[i]->progress[j]);
			s[i]->middleMark += s[i]->progress[j];
		}
		s[i]->middleMark = s[i]->middleMark / 5;
	}

	int tmp;

	for (int i = 0; i<N; ++i)
		for (int j = 0; j<N - i - 1; ++j)
			if (s[j]->groupNumber > s[j + 1]->groupNumber)
			{
				int tmp = s[j]->groupNumber;
				s[j]->groupNumber = s[j + 1]->groupNumber;
				s[j + 1]->groupNumber = tmp;
			}

	for (int i = 0; i<N; ++i)
	{
		if (s[i]->middleMark >= 4)
			printf("%s %d\n", s[i]->name, s[i]->groupNumber);
		free(s[i]->name);
		free(s[i]);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}