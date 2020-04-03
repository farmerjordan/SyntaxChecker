#ifndef STACK
#define STACK

#include <iostream>
using namespace std;

template <class GS>

class GenStack{

public:
  GenStack();//default constructor
  GenStack(int maxSize); //overload constructor
  ~GenStack(); //destructor

  //Core functions
  void push (GS x);
  GS pop();

  //Helper functions
  GS peek();
  bool isEmpty();
  bool isFull();

  int top;
  int size;

  GS *myArray;

};

#endif
