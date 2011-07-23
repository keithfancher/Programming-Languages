//****************************************************************************
// File  : Triangle.h
// Author: Keith T. Fancher
// Date  : 1-22-04
// Class : CS3490
//
// Description: The header file for the Triangle class... it's ever-so-neat!
//****************************************************************************


#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__


class Triangle
{
  public:
    Triangle();                 // default constructor!
    Triangle(unsigned int);     // constructor, takes triangle size
    Triangle(const Triangle &); // copy constructor!
    ~Triangle();                // destructor!

    Triangle & operator=(const Triangle &); // equals operator, off course

    void resizeTriangle(unsigned int);  // resizes triangle, takes new size
    void print();                       // guess... just guess (it prints!)
    
  private:
    char ** allocate(unsigned int);  // returns the 2D char array for tri
    void    emptyTriangle();         // kills the array and tri
    
    unsigned int height;             // height of the tri
    char ** triangle;                // the actual tri array (heightxheight)
};


#endif

