#ifndef MONOSTACK_H
#define MONOSTACK_H

#include<iostream>
#include<exception>

template<typename T>
class MonoStack{

    public:
        MonoStack(); //default contructor
        MonoStack(int maxSize, char o); //overloaded constructor
        ~MonoStack(); //destructor

        //core function
        void push(T data);
        T pop(); //return and remove
        T peek(); //aka top

        //aux function //aka extra or helper fuctions
        bool isEmpty();
        bool isFull();
        int getSize();

    private:
        int top;
        int mSize;
        T *myArray; // T, is now the array, so it can hold anything 
        char o;
};

template<class T>
MonoStack<T>::MonoStack(){
    mSize = 64; // default size of our stack
    top = -1;
    myArray = new T[mSize]; // exists on the heap, as the memory is allocated dynamically
    char o = 'i';
}

template<class T>
MonoStack<T>::MonoStack(int maxSize, char o){
    mSize = maxSize;
    top = -1;
    myArray = new T[mSize];
    this->o = o; 
}

template<class T>
MonoStack<T>::~MonoStack(){
    std::cout << "Stack destroyed, garbage taken out!" << std::endl;
    delete [] myArray; // dynamic arrays require [] to delete 
}

template<class T>
void MonoStack<T>::push(T data){
    if(isFull()){
        std::cout << "resizing the stack... " << std::endl;
        T *temp = new T[2*mSize];

        for(int i = 0; i < mSize; ++i){
            temp[i] = myArray[i]; // copy data from an old array into new larger array
        }
        mSize *= 2;
        delete [] myArray;
        myArray = temp;
    }

    // o=='i'
    // all nums larger then X get popped off
    if(o == 'i'){
        if(!isEmpty()){
            while(!isEmpty() && data < myArray[top]){
                pop();
            }
            myArray[++top] = data;
        }
        //add data if emplty
        if(isEmpty()){
            myArray[++top] = data;
        }
    }


    // o=='d'
    // all nums smaller then X get popped off
    if(o == 'd'){
        if(!isEmpty()){
            while(!isEmpty() && data > myArray[top]){
                pop();
            }
            myArray[++top] = data;
        }
        //add data if emplty
        if(isEmpty()){
            myArray[++top] = data;
        }
    }
}

template<class T>
T MonoStack<T>::pop(){
    if(isEmpty()){
        throw std::runtime_error("stack is empty");
    }
    return myArray[top--]; // top-- evaluates it first then decrements it, we don't need to delete with a Stack, we just overwrite
}

template<class T>
T MonoStack<T>::peek(){
    if(isEmpty()){
        throw std::runtime_error("stack is empty");
    }
    return myArray[top];
}

template<class T>
bool MonoStack<T>::isEmpty(){
    return (top == -1);
}

template<class T>
bool MonoStack<T>::isFull(){
    return (top == mSize - 1);
}

template<class T>
int MonoStack<T>::getSize(){
    return top + 1;
}

#endif