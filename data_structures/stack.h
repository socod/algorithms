#ifndef DATA_STRUCTURES_STACK_H_
#define DATA_STRUCTURES_STACK_H_

#include<cassert>
#include<iostream>

// Definition of the node as a linked-list
template <class Type>
struct node {
    Type data;
    node<Type>* next;
};

// Definition of the stack class
template <class Type>
class stack{
public:
    void display(){
        node<Type>* current = stackTop;
        std::cout << "Top --> ";
        while (current != nullptr){
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
        std::cout << "Size of stack: " << size << std::endl;
    }

    // Default constructor
    stack(){
        stackTop = nullptr;
        size = 0;
    }

    // Copy constructor
    explicit stack(const stack<Type>& otherStack){
        node<Type> *newNode, *current, *last;

        if (stackTop != nullptr){
            stackTop = nullptr;
        }
        if (otherStack.stackTop == nullptr){
            stackTop == nullptr;
        }
        else {
            current = otherStack.stackTop;
            stackTop = new node<Type>;
            stackTop->data = current->data;
            stackTop->next = nullptr;
            last = stackTop;
            current = current->next;
            while (current != nullptr){
                newNode = new node<Type>;
                newNode->data = current->data;
                newNode->next = nullptr;
                last->next = newNode;
                last = newNode;
                current = current->next; 
            }
        }
        size = otherStack.size;
    }

    // Destructor
    ~stack(){}

    // Determine whether the stack is empty.
    bool isEmptyStack(){ return (stackTop == nullptr); }

    // Add new item to the stack
    void push(Type item){
        node<Type> *newNode = new node<Type>;
        newNode->data = item;
        newNode->next = stackTop;
        stackTop = newNode;
        size++;
    }

    // Return th top element of the stack
    Type top(){
        assert(stackTop != nullptr);
        return stackTop->data;
    }

    // Remove the top element of the stack
    void pop(){
        node<Type> *temp;
        if (!isEmptyStack()){
            temp = stackTop;
            stackTop = stackTop->next;
            delete temp;
            size--;
        } else {
            std::cout << "Stack is empty!" << std::endl;
        }
    }

    // Clear stack
    void clear() { stackTop = nullptr; }

    // Overload "=" the assignment operator
    stack<Type> &operator=(const stack<Type> &otherStack){
        node<Type> *newNode, *current, *last;

        if (stackTop != nullptr){
            stackTop = nullptr;
        }
        if (otherStack.stackTop == nullptr){
            stackTop == nullptr;
        }
        else {
            current = otherStack.stackTop;
            stackTop = new node<Type>;
            stackTop->data = current->data;
            stackTop->next = nullptr;
            last = stackTop;
            current = current->next;
            while (current != nullptr){
                newNode = new node<Type>;
                newNode->data = current->data;
                newNode->next = nullptr;
                last->next = newNode;
                last = newNode;
                current = current->next; 
            }
        }
        size = otherStack.size;
        return *this;
    }

    //Overload operator "=="
    bool operator==(const stack<Type> &otherStack){
        if (this->size != otherStack.size) return false;
        else{
            node<Type> *current = new node<Type>;
            current = stackTop;
            node<Type> *otherStackTop = new node<Type>;
            otherStackTop = otherStack.stackTop;
            while (current != nullptr && otherStackTop != nullptr){
                if (current->data == otherStackTop->data){
                    current = current->next;
                    otherStackTop = otherStackTop->next;
                }
                else {
                    return false;
                }
            }
            return true;
        }
    }
private:
    node<Type>* stackTop;   // Pointer to the stack
    int size;               // size of stack
};

#endif