#include <iostream>

using namespace std;

class ComplexNumber 
{
	private:
		int a, b;
	public:
		ComplexNumber(int re, int im)
		{
			setNum(re, im);
		}
	
		void setNum(int re, int im)
		{
			a = re;
			b = im;
		}
	
		void getNum()
		{
			cout << a << "+" << b << "*i" << endl;
		}
	
		friend ComplexNumber operator + (ComplexNumber& X1, ComplexNumber& X2);
		friend ComplexNumber operator - (ComplexNumber& X1, ComplexNumber& X2);
		friend ComplexNumber operator * (ComplexNumber& X1, ComplexNumber& X2);
};

ComplexNumber operator + (ComplexNumber& X1, ComplexNumber& X2) 
{
  ComplexNumber sum(0, 0);
  sum.a = X1.a + X2.a;
  sum.b = X1.b + X2.b;
  return sum;
}

ComplexNumber operator - (ComplexNumber& X1, ComplexNumber& X2) 
{
  ComplexNumber raz(0, 0);
  raz.a = X1.a - X2.a;
  raz.b = X1.b - X2.b;
  return raz;
}

ComplexNumber operator * (ComplexNumber& X1, ComplexNumber& X2) 
{
  ComplexNumber mul(0, 0);
  mul.a = X1.a * X2.a;
  mul.b = X1.b * X2.b;
  return mul;
}

int main () 
{
	int a, b;
	ComplexNumber result(0, 0);
	cout<< "Enter A and B of first complex number"<<endl;
	cin>>a;
	cin>>b;	
	ComplexNumber number1(a, b);
	number1.getNum();
	
	cout<< "Enter A and B of second complex number"<<endl;
	cin>>a;
	cin>>b;	
    ComplexNumber number2(a, b);
    number2.getNum();
    
    cout << "Sum" << endl;
	result = number1 + number2;
	result.getNum();
	
	cout << "Razn" << endl;
	result = number1 - number2;
	result.getNum();
	
	cout << "Umn" << endl;
	result = number1 * number2;
	result.getNum();
    return 0;
}
