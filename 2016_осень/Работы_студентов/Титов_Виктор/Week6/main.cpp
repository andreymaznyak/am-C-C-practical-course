#include <iostream>

using namespace std;


class stck
{
	int arraySize;
	int lastIndex;
	int* data;

public:
	stck()
	{
		arraySize = 0;
		lastIndex = 0;
		data = new int[arraySize];
	}
	void push(int d)
	{
		arraySize++;
		int* tmp = new int[arraySize];
		for (int i = 0; i < arraySize - 1; ++i)
		{
			tmp[i] = data[i];
		}
		tmp[arraySize-1] = d;
		delete[] data;
		data = tmp;
	}

	int pop()
	{
		int r = data[lastIndex];
		if (lastIndex < arraySize-1) lastIndex++;
		return r;
	}

	void print()
	{
		for (int i = lastIndex; i < arraySize; ++i)
		{
			cout << data[i];
		}
	}

	void clear()
	{
		delete[] data;
	}
};

int main()
{
	stck s1, s2;
	int x = 1;
	while ((x == 1) || (x == 2))
	{
		cin >> x;
		if (x == 1)
			s1.push(x);
		else if (x == 2)
			s2.push(x);
	}
	s1.print();
	cout << endl;
	s2.print();
	s1.clear();
	s2.clear();
	cin.get();
	cin.get();
	return 0;
}