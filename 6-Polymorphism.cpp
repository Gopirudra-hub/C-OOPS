/*
    *Function Overriding
        • Redefining a function of base class in derived class
        • Function overriding is used for achieving runtime polymorphism
        • Prototype of a overrides function must be exactly same as base class function
*/

#include <iostream>
using namespace std;

class Base
{
public:
    void fun()
    {
        cout << "fun of Base " << endl;
    }
};
class Derived : public Base
{
public:
    void fun() // Over-riding
    {
        cout << "fun of Derived " << endl;
    }
};
int main()
{
    Derived d;
    d.fun();
}

/*
   * Virtual Functions
        • Virtual functions are used for achieving polymorphism
        • Base class can have virtual functions
        • Virtual functions can be overrides in derived class
        • Pure virtual functions must be overrides by derived class
*/
class base
{
public:
    virtual void fun()
    {
        cout << "fun of base" << endl;
    }
};
class derived : public base
{
public:
    void fun()
    {
        cout << "fun of derived" << endl;
    }
    /*
        int main()
        {
            derived d;
            d.fun();
            base *ptr=&d;
            ptr->fun();
        }
    */
};

// --------------------------------------------------------------------------
class BasicCar
{
public:
    virtual void start()
    {
        cout << "BasicCar started" << endl;
    }
};
class AdvanceCar : public BasicCar
{
public:
    void start()
    {
        cout << "AdvanceCar Started" << endl;
    }
};

int main()
{
    BasicCar *p = new AdvanceCar();
    // Without "Virtual" function called on Basis of "Pointer Not Object"

    p->start(); // Output - AdvanceCar Started
}
