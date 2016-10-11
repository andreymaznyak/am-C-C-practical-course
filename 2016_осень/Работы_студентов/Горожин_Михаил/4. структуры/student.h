#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_STUDENTS 10
#define NUMBER_OF_MARKS 5

typedef struct student {
  char* fullname;
  int group;
  char marks[NUMBER_OF_MARKS];
} student;

/*
  Prompts for a student struct field by field.
  Insert it into arr at offset.
*/
void addStudent(student* arr, int offset);

/*
  Just a predicate to filter output.
*/
char predicate(student s);

/*
  Return an average mark for a student.
*/
float average(student s);

/*
  Prints a student struct.
*/
void print(student arr);

/*
  Swap positions i and j in an arr. Used in sort.
*/
void swap(student* arr, int i, int j);

/*
  Sorts an arr from `from` to `to`.
*/
void sort(student* arr, int from, int to);


#endif
