//****************************************************************************
// File  : main.cpp
// Author: Keith T. Fancher
// Date  : 1-22-04
// Class : CS3490
//
// Description: It is here and here alone that we can see the results of
//   the Triangle class on which I worked so diligently.  Rejoice, for it
//   seems to work aight.
//****************************************************************************


#include <iostream>
#include "Triangle.h"

using namespace std;


int main()
{
  Triangle t1(10);  // constructor called!
  cout << "Triangle t1 with height/width 10: \n";
  t1.print();

  Triangle t2(20); // constructor called!
  cout << "Triangle t2 with height/width 20: \n";
  t2.print();

  t2 = t1;  // assignment operator called!
  cout << "Triangle t2 with height/width 10: \n";
  t2.print();

  Triangle t3;  // default constructor called!
  t1.resizeTriangle(5);
  t3 = t1;  // assignment operator called!
  cout << "Triangle t3 with height/width 5: \n";
  t3.print();
  
  Triangle t4 = t3;  // I'm pretty sure this actually uses the copy constructor
  cout << "Triangle t4 with height/width 5: \n";
  t4.print();

  t4.resizeTriangle(4);
  Triangle t5(t4);  // copy constructor called!
  cout << "Triangle t5 with height/width 4: \n";
  t5.print();

  cout << "Triangle t3 with height/width 5: \n";
  t3.print();

  return 0;
}

