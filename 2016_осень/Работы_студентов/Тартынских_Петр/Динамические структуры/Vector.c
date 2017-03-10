#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	int elemSize;
	int size;
	void* data;
	void (*freefn)(void*);
	void (*printfn)(void*);
} vector;

void newVector(vector* v, int elemSize, void (*freefn)(void*), void (*printfn)(void*)) //Инициализация вектора
{
	v->elemSize = elemSize;
	v->size = 0;
	v->freefn = freefn;
	v->printfn = printfn;
	v->data = NULL;
}

void appendElement(vector* v, void* src) //Добавать элемент в конец вектора
{
	v->size++;
	v->data = realloc(v->data, v->size * v->elemSize);
	char* dest = (char*)v->data + (v->size - 1) * v->elemSize;
	memcpy(dest, src, v->elemSize);
}

void getElementAtIndex(vector* v, void* dest, int index) //Вывести элемент по индексу
{
	if ((index >= 0) && (index < v->size))
	{
		char* src = ((char*)v->data + v->elemSize * index);
		memcpy(dest, src, v->elemSize);			
	}
}

void insertSubvectorAtIndex(vector* v1, vector* v2, int index) //Вставить вестор 2 в вектор 1 с позиции индекс
{
	if (index < 0) index = 0;
	if (index > v1->size) index = v1->size;
	v1->size = v1->size + v2->size;
	v1->data = realloc(v1->data, v1->size * v1->elemSize);
	char* src = ((char*)v1->data + v1->elemSize * index);
	memmove(src + v1->elemSize * v2->size, src, (v1->size - v2->size - index) * v1->elemSize);	
	memcpy(src, v2->data, v2->elemSize * v2->size);		
}

void insertElementAtIndex(vector* v, void* element, int index) //Вставить элемент в вектор 1 в позицию индекс
{
	if (index < 0) index = 0;
	if (index > v->size) index = v->size;
	v->size++;
	v->data = realloc(v->data, v->size * v->elemSize);
	char* src = ((char*)v->data + v->elemSize * index);
	memmove(src + v->elemSize, src, (v->size - index) * v->elemSize);	
	memcpy(src, element, v->elemSize);
}

void updateElementAtIndex(vector* v, void* element, int index) //Заменить элемент в векторе 1 в позиции индекс
{
	if ((index >= 0) && (index < v->size))
	{
		char* src = ((char*)v->data + v->elemSize * index);	
		memcpy(src, element, v->elemSize);
	}
}

void strfree(void* p)
{
	free(*(char**)p);
}

void printstr(void* p)
{
	printf("%s ", *(char**)p);
}

void disposeVector(vector* v)
{
	if (v->data != NULL) 
	{
		if (v->freefn != NULL )
		{
			for (int i = 0; i < v->size; i++)
			{
				v->freefn((char*)v->data + v->elemSize * i);
			}
		}
		free(v->data);
	}
}

void printVector(vector* v)
{
	if ((v->data != NULL) || (v->printfn != NULL))
	{
		for (int i = 0; i < v->size; i++)
		{
			v->printfn((char*)v->data + v->elemSize * i);
		}
		printf("\n");	
	}
}

void printint(void* p)
{
	printf("%d\t", *(int*)p);
}

void saveDispose(vector* v)
{
	free(v->data);
}

int main()
{
	vector v, v1;
	newVector(&v, sizeof(char*), &strfree, &printstr);
	newVector(&v1, sizeof(char*), &strfree, &printstr);
	char* str = strdup("ABCD");
	char* str2 = strdup("MAMKA");
	char* str3 = strdup("Lalal");
	appendElement(&v, &str2);
	appendElement(&v, &str);
	insertElementAtIndex(&v, &str3, 1000);
	str2 = strdup("MAMKADVA");
	updateElementAtIndex(&v, &str2, 0);
	printVector(&v);
	char* str4 = strdup("Something");
	char* str5 = strdup("NEW");
	appendElement(&v1, &str4);
	appendElement(&v1, &str5);
	printVector(&v1);
	insertSubvectorAtIndex(&v, &v1, 1);
	printVector(&v);
	disposeVector(&v);
	saveDispose(&v1);
	return 0;
}
