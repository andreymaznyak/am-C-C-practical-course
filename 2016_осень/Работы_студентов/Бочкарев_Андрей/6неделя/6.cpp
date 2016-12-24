#include <iostream>
#include <stdlib.h>
using namespace std;

class Polynomial{
    int a[100], n;
public:
    void enter();
    void calculate();
    void sum(Polynomial mA, Polynomial mB);
    void sub(Polynomial mA, Polynomial mB);
    void multiply(Polynomial mA, Polynomial mB);
    void print();
};

int main(){
    Polynomial a,b,c;
    cout<<"1st polynomial, ";
    a.enter();
    a.print();
    a.calculate();
    
    cout<<"2nd polynomial, ";
    b.enter();
    b.print();
    b.calculate();
    
    c.multiply(a,b);
    cout<<"Multiply = ";
    c.print();
    
    c.sum(a,b);
    cout<<"Sum = ";
    c.print();
    
    c.sub(a,b);
    cout<<"Sub = ";
    c.print();
}

void Polynomial::enter(){
    cout<<"enter polynomial degree: ";
    cin>>n;
    //cout<<endl;
    cout<<"Enter coefficients:\n";
    for (int k=0; k<=99; k++) {
        a[k]=0;
    }
    for (int i=0; i<=n; i++) {
        cout<<" a"<<i<<" = ";
        cin>>a[i];
    }
    //cout<<endl;
}

void Polynomial::print(){
    int f;
    f=0;
    //cout<<endl;
    for (int i=n; i>=0; i--)
        if (a[i]!=0)
        {   if(f==0) {
                if(i!=0)cout<<a[i]<<"x^"<<i;
                else cout<<a[i];
                f++;
            }
            else {
                if(i!=0)
                    if(a[i]>0) cout<<" + "<<a[i]<<"x^"<<i;
                    else cout<<a[i]<<"x^"<<i;
                else if(a[i]>0) cout<<" + "<<a[i];
                else cout<<a[i];
                f++;
            }
        }
    if (f==0) {
        cout<<0;
    }
    cout<<endl;
}

void Polynomial::calculate(){
    cout<<endl;
    int x,v,vx;
    v=0;
    cout<<"enter X: ";
    cin>>x;
    vx=1;
    for (int i=0; i<=n; i++) {
        v = v + a[i];// * vx;
        vx = vx * x;
    }
    cout<<"f("<<x<<") = "<<v<<endl;
    cout<<endl;
}

void Polynomial::sum(Polynomial mA, Polynomial mB){
    for (int k = 0; k <= 99; k++) {
        a[k] = 0;
    }
    if (mA.n>mB.n) n=mA.n;
    else n=mB.n;
    for (int i=0; i<=n; i++) {
        a[i]=mA.a[i]+mB.a[i];
    }
}

void Polynomial::sub(Polynomial mA, Polynomial mB){
    for (int k=0; k<=99; k++) {
        a[k]=0;
    }
    if (mA.n>mB.n) n = mA.n;
    else n = mB.n;
    for (int i=0; i<=n; i++) {
        a[i] = mA.a[i] - mB.a[i];
    }
}

void Polynomial::multiply(Polynomial mA, Polynomial mB){
    for (int k=0; k<=99; k++) {
        a[k]=0;
    }
    n = mA.n + mB.n;
    for (int i=0; i<=mA.n; i++) for (int j=0; j<=mB.n; j++) {
            a[i+j] = a[i+j] + mA.a[i] * mB.a[j];
        }
}
