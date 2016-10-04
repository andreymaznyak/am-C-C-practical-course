#include <iostream>
#include <string>
#define N 5
using namespace std;

class STUDENT
{
	private:
	string *name;
	int *number;
	int *usp;
	
	public:
	static bool t;
	
	bool Check (int *a)
	{
		int i;
		for(i=0; i<N; i++) if(a[i]==2)  {t=true; return true; }
		return false;
	}
	
	STUDENT()
	{
		name = new string;
		number = new int;
		usp = new int[N];	
		cin >> *name;
		cin >> *number;
		for(int i=0; i<N; i++) cin >> usp[i];
	}
	
	~STUDENT()
	{
		if(Check(usp)) cout<<*name<<" "<<*number<<endl;
		delete name;
		delete number;
		delete [] usp;
	}
};

bool STUDENT::t=false;

int main()
{
	STUDENT *spisok = new STUDENT[10];
	delete [] spisok;
	if(!STUDENT::t) cout<<"Takih studentov net"<<endl;
	return 0;
}
