//****************************************************************************
// File  : Triangle.cpp
// Author: Keith T. Fancher
// Date  : 1-22-04
// Class : CS3490
//
// Description: The implementation of the Triangle class... it's ever-so-neat!
//****************************************************************************


#include <iostream>
#include "Triangle.h"

using namespace std;


Triangle::Triangle()
{
  height = 0;
  triangle = NULL;
}

Triangle::Triangle(unsigned int h)
{
  height = h;
  triangle = allocate(h);  // allocates the space

  // fills the array
  for(int i = 0; i < height; i++)
  {
    memset(triangle[i], ' ', sizeof(char) * height);  // init to spaces
    for(int j = 0; j < i+1; j++)                      // put in the *'s
      triangle[i][j] = '*';
  }
}

Triangle::Triangle(const Triangle & t)
{
  height = t.height;
  triangle = allocate(t.height);  // allocates the space

  // fills the array
  for(int i = 0; i < height; i++)
  {
    for(int j = 0; j < height; j++)
      triangle[i][j] = t.triangle[i][j];
  }
}

Triangle::~Triangle()
{
  emptyTriangle();
}

Triangle & Triangle::operator=(const Triangle & t)
{
  resizeTriangle(t.height);

  // fills the array
  for(int i = 0; i < height; i++)
  {
    for(int j = 0; j < height; j++)
      triangle[i][j] = t.triangle[i][j];
  }

  return *this;
}

void Triangle::resizeTriangle(unsigned int h)
{
  emptyTriangle();
  triangle = allocate(h);
  height = h;

  // fills the array
  for(int i = 0; i < height; i++)
  {
    memset(triangle[i], ' ', sizeof(char) * height);  // init to spaces
    for(int j = 0; j < i+1; j++)                      // put in the *'s
      triangle[i][j] = '*';
  }
}

void Triangle::print()
{
  for(int i = 0; i < height; i++)
  {
    for(int j = 0; j < height; j++)
      cout << triangle[i][j]; 
    cout << endl;
  }
  cout << endl;
}

char ** Triangle::allocate(unsigned int h)
{
  // good ol' dynamic 2D arrays
  char ** t = new char *[h];

  for(int i = 0; i < h; i++)
    t[i] = new char[h];

  return t;
}

void Triangle::emptyTriangle()
{
  // deleting these things is just so... satisfactory
  if(triangle)
  {
    for(int i = 0; i < height; i++)
    {
      if(triangle[i])
        delete [] triangle[i];
      triangle[i] = NULL;
    }

    delete [] triangle;
    triangle = NULL;
    height = 0;
  }
}



