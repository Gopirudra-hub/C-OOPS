/*
* What is a default constructor?
    •A constructor which dent take any parameters is called as default constructor.

* There are 2 Types of default constructors
    1.Compiler provided
    2.User-defined

* Compiler provided default constructor
    •If we don’t write any constructor, compiler will provide a default constructor.
    •It will create the object, but doesn’t initialise data members.
    •If we define our own contractor, then compiler will not provide default constructor.

* Why we write constructor?
    •We can initialise the data members of an object.
    •If data members are initialised then we can use the object.

* Type of Constructors
    There are 3 type of constructors.
        1.Non-parametrised (also called as default)
        2.Parameterised
        3.Copy constructor

* Do we have to write all constructors ?
    •It is better to write all constructors.
    •I am not writing it in every lecture because I have to focus on actual topic.

* Why copy constructor should take reference?
    •If parameter is call by value then it will create new object for parameter.
    •Constructor will call constructor again to create the object of parameter.
    •It will be become a recursive call to constructor.

* Can we initialise the variables directly?
    •Yes you can initialise. But values will always be same.
    •Constructor will allow us to initialise with desired values.

*Can we read values inside the constructor using cin?
    •If main() is creating object then, it is better to read values inside main and pass values to constructor.
    •Using cin means, interacting with user. If user interaction is done in main() then it is a good design.

* Copy constructor vs Assignment operator
    their working is same but usage is different.
        Rectangle r1(10,5);
        Rectangle r2(r1); // copy constructor is calledRectangle r3=r1; // assignment operator is called
*/

/*
*Deep Copy vs Shallow Copy Constructors

*Deep Copy:
    • deep copy constructor is useful for making a copy of dynamic structures which are in heap. like Dynamic Array ,Linked List, Trees etc.

    • if member of a class is a pointer 'p' and it is pointing to array or object in heap.

    • if object A is having its member 'p' pointing on an array or object in heap and you are making a copy of A as B then 'p' of B will also point on same array or object of A.

    • to have separate copy of B another array or object should be created and make 'p' point on it.

    • if a copy constructor is doing it, we say Deep copy constructor.

*Shallow Copy:
    • Copy constructor will copy only the members of an object.
    • If an object is holding any memory in heap, it will not be copied.

*/

#include <iostream>
using namespace std;

class Rectangle
{
private:
    int length;
    int breadth;

public:
    Rectangle()
    {

        length = 1;
        breadth = 1;
    }
    inline int area(); // Inline Function
};
int Rectangle::area()
{
    return length * breadth;
}
int main()
{
    Rectangle r1;
    cout << r1.area() << endl;

    return 0;
}

/*
*Good practise to write functions outside the class using?
    • Class definition should be separation and function body should be separate. It will be easy to read and share.

    • Class will contain definitions of functions, that can be shared as header file and implementation of functions outside class using scope resolution can be kept in library file.

    • If we are sharing code with others then they can’t see the code in functions

    • If they are implemented inside then they will become inline by default. One more thing, Functions should not be inline. But when you were writing a function for single line also then it’s better to make inline to avoid function call.
*/

/*
*inline functions
    • simple single line functions can be made as inline.

    • inline functions will save time. call will not be made and activation record will not be created.

    • if we define a function inside a class and if we call it multiple times in our main function. Then the code will be copied at all places wherever it is called in the code section of the memory.

    • inline functions will be copied in place of function call. they will not work like normal functions. they dont require function call, this will save little time

    • we should write property function get/set as inline. functions with loops should be avoided.

    • copying of code is decided by compiler. writing inline is a hint to compiler.
*/

/*
*What is “this” pointer?
    • It represents current object.
    • It is useful in avoiding variable name conflict.
*/

class Test
{
private:
    int value;

public:
    void fun(int x)
    {
        this->value = x;
    }
};
int main()
{
    Test t1, t2; // both t1 and t2 are having “value”
    t1.fun(10);  // “this” inside fun means “value” of t1.
    t2.fun(20);  // “this” inside fun means “value” of t2.
}

// Example for variable name conflict.
class Test
{
private:
    int value;

public:
    void fun(int value)
    {
        // here parameter name and data member name is same “value” to access data member “this” is used.
        this->value = value;
    }
};
