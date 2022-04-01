/*
*Can a member function have the object of same class?
Yes.

*Why operator is returning the object of same class?
It is returning the result object. If 2 Complex numbers are added
then it is returning their sum.

*c3=c1+c2. Assignment operators should be overloaded?
    No need. C++ provides assignment on object.
    Assignment operator must be overloaded if object are having memory in heap.

* ”this” keyword.
When a operator function for + is defined like
Complex operator+(Complex c2)
Then it is called like
c3=c1+c2;
Here function is called upon c1 and c2 is passed as parameter.
Members of c2 can be accessed using c2.real etc.
Members of c1 can be accessed using this->real etc.

*Complex operator+(Complex &x) using reference.Using reference (Complex &x) is better, it will not create a new object.
If call by value is used (Complex x) then object x will be created and
its constructor is called. We may have to define copy constructor also.

* How operator+(…..) works as +?
It is a syntax given in C++. Compiler will understands operator + means +.

*Can we define friend function for +?
Yes. Its prototype should look like this
Complex operator+(Complex &c1,Complex &c2);
c3=c1+c2; both objects will be passed as parameter.

*:: for friend function.
We don’t use scope resolution for friend functions. They are global functions.

* Friend function
if are using two or more objects in the parameter. Then we have to
make use of friend.
when both are of same class then we have 2 options.
1. make operator as a member of class
2. make it as friend
when 2 arguments are from different classes then there is only 1
option that is friend function
*/

#include <iostream>
using namespace std;

class complex
{
public:
    int real;
    int img;
    complex add(complex c)
    {
        complex temp;
        temp.real = real + c.real;
        temp.img = img + c.img;
        return temp;
    }
    /*
    int main()
    {
            complex c1, c2, c3;
             c1.real = 5;
            c1.img = 3;
            c2.real = 10;
            c2.img = 5;
            c3 = c1.add(c2);
        cout << c3.real << "+i" << c3.img << endl;
    }
    */
};

class Complex
{
private:
    int real;
    int img;

public:
    Complex(int r = 0, int i = 0)
    {
        real = r;
        img = i;
    }

    void display()
    {
        cout << real << "+i" << img << endl;
    }

    Complex operator+(Complex c)
    {
        Complex temp;
        temp.real = real + c.real;
        temp.img = img + c.img;
        return temp;
    }
    /*
    int main()
    {
        Complex c1(5,3),c2(10,5),c3;
        c3=c1+c2;
        c3.display();

    }
    */
};

// Friend Operator ================================================
class Complex
{
private:
    int real;
    int img;

public:
    Complex(int r = 0, int i = 0)
    {
        real = r;
        img = i;
    }

    void display()
    {
        cout << real << "+i" << img;
    }

    friend Complex operator+(Complex c1, Complex c2); // Hast to return Outside Class

    /*
    int main()
    {
        Complex c1(5, 3), c2(10, 5), c3;
        c3 = c1 + c2;
        c3.display();
    }
    */
};

Complex operator+(Complex c1, Complex c2)
{
    Complex temp;
    temp.real = c1.real + c2.real;
    temp.img = c1.img + c2.img;
    return temp;
}
