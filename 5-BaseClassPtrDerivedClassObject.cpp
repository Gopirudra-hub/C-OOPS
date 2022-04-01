#include <iostream>
using namespace std;

class base
{
public:
    void fun1()
    {
        cout << "fun1 of base" << endl;
    }
};

class derived : public base
{
public:
    void fun2()
    {
        cout << "fun2 of derived" << endl;
    }
};

int main()
{
    /*
        Base Class pointer & Derived Class Object - only Base Class Function can be "Called"
    */
    base *b;
    b = new derived();
    b->fun1();
    b->fun2(); // Derived Class fumction can't be called even though object is Derived Class

    derived *d;
    d = new base(); // Not possible

    derived d;
    base *ptr = &d;
    ptr->fun1();
    ptr->fun2(); // Can't be Called object Base
    return 0;
}