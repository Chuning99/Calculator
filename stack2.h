#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "include/LinkedList.h"
#include "include/node.h"
template <typename ITEM_TYPE>
class Stack{
public:
    Stack();
    Stack(node<ITEM_TYPE>* h);
    Stack(Stack<ITEM_TYPE>& copyme);
    ~Stack();
    Stack<ITEM_TYPE>& operator=(Stack<ITEM_TYPE>& assignthis);
    void clearStack();
    ITEM_TYPE Top();
    bool Empty();
    void Push(ITEM_TYPE pushthis);
    ITEM_TYPE Pop();
    void PrintStack();
    template <typename U> friend ostream& operator <<(ostream& outs, const Stack<U>& printthis);
private:
    node<ITEM_TYPE>* top;
};
template <typename ITEM_TYPE>
Stack<ITEM_TYPE>::Stack(){
    this->top = nullptr;
}
template <typename ITEM_TYPE>
Stack<ITEM_TYPE>::Stack(node<ITEM_TYPE>* h){
    this->top = CopyList(h);
}
template <typename ITEM_TYPE>
Stack<ITEM_TYPE>::Stack(Stack<ITEM_TYPE>& copyme){
    this->top = CopyList(copyme.top);
}
template <typename ITEM_TYPE>
Stack<ITEM_TYPE>::~Stack(){
     ClearList(top);
}
template <typename ITEM_TYPE>
Stack<ITEM_TYPE>& Stack<ITEM_TYPE>::operator=(Stack<ITEM_TYPE>& assignthis){
    this->top = CopyList(assignthis.top);
    return *this;
}
template <typename ITEM_TYPE>
void Stack<ITEM_TYPE>::clearStack(){
    ClearList(top);
}
template <typename ITEM_TYPE>
ITEM_TYPE Stack<ITEM_TYPE>::Top(){
    return top ? top->_item : ITEM_TYPE();
}
template <typename ITEM_TYPE>
bool Stack<ITEM_TYPE>::Empty(){
    return !top;
}
template <typename ITEM_TYPE>
void Stack<ITEM_TYPE>::Push(ITEM_TYPE pushthis){
    Insert_Head(top, pushthis);
}
template <typename ITEM_TYPE>
ITEM_TYPE Stack<ITEM_TYPE>::Pop(){
    return DeleteNode(top, top);
}
template <typename ITEM_TYPE>
void Stack<ITEM_TYPE>::PrintStack(){
    PrintList(top);
}

template <typename U>
ostream& operator <<(ostream& outs, const Stack<U>& printthis){
    node<U>* temp = printthis.top;
    while(temp){
        outs << *temp;
        temp = temp->_next;
    }
    outs << "|||";
    return outs;
}

#endif // STACK_H
