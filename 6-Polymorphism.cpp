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

/*
    *Abstract Function
    If a member function is not having a body then it is an abstract function.

Example:
class Test
{
    public:
        void fun(); // body is not defined outside
};

*Abstract Class
    If a class is having an abstract function then class becomes abstract.
    If a class is having pure virtual function then it becomes abstract.
    We can declare pointer of abstract class
    We can create object of abstract class but cannot call undefined functions.
    Abstract classes are useful for achieving polymorphism.

*Can we overriding private function?
    you can override but can't achieve polymorphism because private members cannot be called on object.

*If a base class has both concrete functions and pure virtual functions then can we create an object of that base class?
Yes you can create the object of a class but cannot call undefined functions.

*/

class car
{
public:
    virtual void start()
    {
        cout << "car started" << endl;
    }
    /*
        virtual void start()=0;
        "PURE Virtual Function"
    */
};

class innova : public car
{
public:
    void start()
    {
        cout << "innova started" << endl;
    }
};

class swift : public car
{
public:
    void start()
    {
        cout << "swift started" << endl;
    }
};
int main()
{
    car *ptr = new innova();
    ptr->start();
    p = new swift();
    ptr->start();
}