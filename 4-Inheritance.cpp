/*
    *Inheritance
        • It is a process of acquiring features of an existing class into a new class
        • It is used for achieving reusability
        • features of base class will be available in derived class
*/

#include <iostream>
using namespace std;
class Base
{
public:
    int a;
    void display()
    {
        cout << "Display of Base " << a << endl;
    }
};
class Derived : public Base
{
public:
    void show()
    {
        cout << "Show of Derived" << endl;
    }
};
int main()
{
    Derived d;
    d.a = 100;
    d.display();
    d.show();
}

/*
    *Constructor in Inheritance

*Default constructor of Base class
• Default Constructor of Base class will be called when object of Derived class is created.
• If Base class is having nay user-defined constructor then it must also have user-defined default constructor

*Calling Parametrised constructor of Base class
It should be called from constructor of Derived class

*Example:
class Cuboid : public Rectangle
{
    private :
        int height;
    public:
        Cuboid(int lint b, int h);          // Base class constructor should not be called from prototype
};

Cuboid::Cuboid(int lint b, int h) : Rectangle(l , b) // calling base class constructor
{
    height=h;
}

*Private member of Base in Derived class Constructor
No. Private members of Base class are not accessible in derived class. Private members of Base class are inherited to Derived class, but not accessible.

*Copy Constructor by reference
• Copy constructor must take parameter by reference. If it is taking parameter
by value then it has to create an object and it will class constructor again.
• It may become recursive call to the constructor. Constructor calling
constructor.

*Private Constructor
Yes constructor can be declared as private, but we cannot create the
object directly. It can be done using static functions

*Example:
class Test
{
    int x,y;
    Test(int a, int b)
    {
        x=a;
        y=b;
    }

    public:
        static Test * CreateObject() // this function will create an object.
        {
            Test t=new Test(10,10);
            return t;
        }
};

int main()
{
    Test *t=Test::CeateObject();
}

*Virtual Base class
I multiple-path inheritance, a derived class may get the duplicate features via multiple parent classes. To avoid duplicacy we make parent class as virtual

*/

class base
{
public:
    base()
    {
        cout << "Default base" << endl;
    }
    base(int x)
    {
        cout << "param of base " << x << endl;
    }
};

class derived : public base
{
public:
    derived()
    {
        cout << "Default derived" << endl;
    }
    derived(int y)
    {
        cout << "One param of derived " << y << endl;
    }
    derived(int x, int y) : base(x) // Call Parameterized constructor of "Base" when Derived Para Object is created
    {
        cout << "param of derived" << y << endl;
    }
};

int main()
{
    derived d;
    /*
        * Output
            Default base
            Default derived
    */

    derived(10);
    /*
        * Output
            Default base
            One param of derived
    */

    derived(20, 10);
    /*
        * Output
            param of base 20
            param of derived 10
    */
}

/* ------------------------------------------------------------

*Access Specifiers
    • Private - Accessible only inside a class
    • Protected - Accessible inside a "class" and "inside derived classes"
    • Public - accessible inside class, inside derived class and upon object

*/
class Base
{
private:
    int a;

protected:
    int b;

public:
    int c;
    void funBase()
    {
        a = 10;
        b = 5;
        c = 15;
    }
};
class Derived : public Base
{
public:
    void funDerived()
    {
        a = 10; // Can't Access
        b = 5;  // Access
        c = 15; // Access
    }
};
int main()
{
    Base b;
    b.a = 10; // Can't Access
    b.b = 5;  // Can't Access
    b.c = 20; // Access
}

/* ------------------------------------------------------------------
    * Types of Inheritance
        * Simple / Single
        * Hierarchical
        * Multi-Level
        * Multiple
        *

*/

/*
   * Ways of inheritance
        A class can be inherited in flowing ways
            Publicly - All members of base will have same accessibility in derived class
            Protectedly - All members of base will become protected in derived class
            Privately - All members of base will become private in derived class
*/

class Parent
{
private:
    int a;

protected:
    int b;

public:
    int c;
    void funParent()
    {
        a = 10;
        b = 5;
        c = 15;
    }
};

class Child : private Parent
{
private:
protected:
public:
    void funChild()
    {
        // a=10;
        b = 5;
        c = 15;
    }
};

class GrandChild : public Child
{
public:
    void funGrandChild()
    {
        // a=10;
        // b=5;
        // c=20;
    }
};
int main()
{
    // Child c;
    // c.a=10;
    // c.b=5;
    // c.c=20;
}
