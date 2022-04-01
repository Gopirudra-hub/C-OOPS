/* Object-Oriented Programming
  Features of OOPS
  • Abstraction
  • Data Hiding
  • Inheritance
  • Polymorphism

*/

/* Objects ------------------------------------
    * Object is a real world entity, for example, chair, car, pen, mobile, laptop etc.

    * In other words, object is an entity that has state and behavior.
       Here, state means data and behavior means functionality.

    * Object is a runtime entity, it is created at runtime.

    * Object is an instance of a class. All the members of the class can be accessed through object.

    * Many object can be created from same class
      • Object consumes memory equal to sum of sizes of all data members
      • Member functions don’t occupy memory
      • Member functions are called depending on object
      • . Dot operator is used for accessing members of object
      • Memory allocated for object is also called as instance
*/

/* Class -----------------------------------

    * class is a group of similar objects. It is a template from which objects are created. It can have fields,
      methods,constructors etc.

    * Class is a blue print of an object
*/

/*
  Structure vs Class
  * C++ supports both structure and class
  * structure in C++ can have data members and member functions.

  * All members of a structure are public by default.
  * class can contain data members and member functions

  * All members of a class are private by default.

*/
/*
  *Where the class in stored?
    •In C++, class is not stored in main memory
    •All member functions of a class are stored in Code section at loading time.
    •If an object of a class is created inside a function then memory for all data members will be created in a stack of a function.

*/

#include <iostream>
using namespace std;

class Rectangle
{
public:
  int length;
  int breadth;

  int area()
  {
    return length * breadth;
  }

  int perimeter()
  {
    return 2 * (length + breadth);
  }
};

int main()
{
  // Object in Stack --------------------------------------
  Rectangle r1; // Object
  r1.length = 10;
  r1.breadth = 5;
  cout << "Perimeter is " << r1.perimeter() << endl;

  // pointer to an object -----------------------------------
  Rectangle r1;
  Rectangle *ptr;
  ptr = &r1;
  ptr->length = 10;
  cout << ptr->perimeter() << endl;

  // Create Object in Heap ----------------------------------
  Rectangle *p = new Rectangle();
  p->length = 15;

  return 0;
}

/*
*Create object in Stack or Heap -----------------------------------

*Stack:
  Rectangle r1;     // Valid
  Rectangle r1( ); // invalid, don’t give empty brackets.

*Heap:
  Rectangle *p;       // pointer, it is created in stack.
  p=new Rectangle(); // object is created in heap. Empty () can be given.
*/

/*
  * What is the purpose of Data Hiding?
      •Data hiding is mistaken as data security.
      •By hiding data a programmer can avoid mishandling of data by the code outside the class.
      •Data is accessible only within a class.
      •Only the functions of a class, knows what processing should be done on that data

  * Encapsulation vs Abstraction
      •A Class is used for Encapsulation as well as Abstraction
  * Encapsulation means combining related data members and functions together.
      •Encapsulation is achieved using a class.
 *Abstraction means hiding data and showing required functions.
      •Abstraction is achieved using encapsulation and data hiding. Private and public

*/

class Rectangle1
{
private:
  int length;
  int breadth;

public:
  // Setter / Mutator ---------------------------------------
  void setLength(int l)
  {
    length = l;
  }
  void setBreadth(int b)
  {
    breadth = b;
  }

  // Getter / Accessors --------------------------------------
  int getLength()
  {
    return length;
  }
  int getBreadth()
  {
    return breadth;
  }

  int area()
  {
    return length * breadth;
  }

  /* int main()
  {
    Rectangle r1;
    r1.setLength(10);
    r1.setBreadth(5);

    cout<<r1.area()<<endl;
    cout<<r1.getLength()<<endl;
  }

  */
};
