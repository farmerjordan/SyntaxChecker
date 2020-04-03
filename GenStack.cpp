#include "Genstack.h"

//Default Constructor
template <class GS>
GenStack<GS>::GenStack(){
  myArray = new GS[128];
  size = 128;
  top = -1;
}

//Overloaded Constructor
template <class GS>
GenStack<GS>::GenStack(int maxSize){
  myArray = new GS[maxSize];
  size = maxSize;
  top = -1;
}

//Destructor
template <class GS>
GenStack<GS>::~GenStack(){
  delete myArray;
}

template <class GS>
void GenStack<GS>::push(GS data){
  //Check if the array is full
  if(isFull()){
    cout << "Stack is full. Cannot add element." << endl;
    exit(EXIT_FAILURE);
  }

  myArray[++top] = data;
}

template <class GS>
GS GenStack<GS>::pop(){
  //Check if the array is empty
  if(isEmpty()){
    cout << "Stack is empty. No element to pop." << endl;
    exit(EXIT_FAILURE);
  }

  return myArray[top--];
}

template <class GS>
GS GenStack<GS>::peek(){
  //Check to make sure the array has something in it
  if(!isEmpty()){
    return myArray[top];
  }else{
    cout << "Stack is empty. No element to return." << endl;
    exit(EXIT_FAILURE);
  }
}

template <class GS>
bool GenStack<GS>::isFull(){
  return (top == size - 1);
}

template <class GS>
bool GenStack<GS>::isEmpty(){
  return (top == -1);
}
