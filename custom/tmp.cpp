#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct A{
    int a = 10;
    virtual void print(){
        cout<< "A" <<endl;
    }
};
struct B:public A{
    int a = 12;
    int b = 20;
    virtual void print(){
        cout<< "B"<<endl;
    }
};
class CA{
public:
    virtual void cprint(){
        cout<< "CA"<<endl;
    }
};
class CB: public CA{
public:
    virtual void cprint(){
        cout<< "CB"<<endl;
    }
};
int main(){
    A a = B();
    cout<<a.a<<endl;
    a.print();
    CA ca = CB();
    ca.cprint();
    return 0;
}