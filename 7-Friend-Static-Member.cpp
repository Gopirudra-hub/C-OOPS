/*
    *Friend functions and classes
        • Friend functions are global functions
        • They can access member of a class upon their objects
        • A class can be declared as friend on another class
        • All the functions of friend class can access private and protected members of other class
*/
class your; // Definitation
class my
{
private:
    int a;

protected:
    int b;

public:
    int c;
    friend your; // Friend Function allow access of all members Upon "Objects"
};

class your
{
public:
    my m;
    void fun()
    {
        m.a = 10;
        m.b = 10;
        m.c = 10;
    }
};

/*
   * Static Members
        • Static data members are members of a class
        • Only one instance of static members is created and shared by all objects
        • They can be accessed directly using class name
        •Static members functions are functions of a class, they can be called using class name, without creating object of a class.

        • They can access only static data members of a class, they cannot access non-static members of a class.
*/

#include <bits/stdc++.h>
using namespace std;

class Test
{
public:
    int a;
    static int count; // Static has to "Defined Outside" Class
    Test()
    {
        a = 10;
        count++;
    }

    static int getCount() // Static Function Can only access "Static Member"
    {
        return count;
    }
};
int Test::count = 0;
int main()
{
    Test t1, t2;
    cout << Test::getCount() << endl; // Call Static Function using Scope resolution Upon Class
    cout << t1.getCount() << endl;    // Using Object
}