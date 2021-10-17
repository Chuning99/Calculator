#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "include/LinkedList.h"
#include "include/node.h"

template <typename ITEM_TYPE>
class Queue
{
public:
    Queue(); //CTOR

    Queue(const Queue<ITEM_TYPE>& copyme);  // copy CTOR
    ~Queue();    //DEOR
    Queue<ITEM_TYPE>& operator=(Queue<ITEM_TYPE>& assignthis); //= operator

    void ClearQueue(); //to clean queue.
    ITEM_TYPE Front();
    ITEM_TYPE Rear();
    bool Empty();
    void Push_back(ITEM_TYPE pushthis); //add
    ITEM_TYPE Pop_front();
    ITEM_TYPE Pop_rear();
    void PrintQueue();      //print function
    template <typename U>
    friend ostream& operator <<(ostream& outs, const Queue<U>& printthis);
private:
    node<ITEM_TYPE>* front;
    node<ITEM_TYPE>* rear;
};
template <typename ITEM_TYPE>
Queue<ITEM_TYPE>::Queue(){      //CTOR
    front = rear = nullptr;
}
template <typename ITEM_TYPE>
Queue<ITEM_TYPE>::Queue(const Queue<ITEM_TYPE>& copyme){  //Copy CTOR
    this->rear = CopyList(copyme.rear);
    this->front = LastNode(this->rear);
}
template <typename ITEM_TYPE>
Queue<ITEM_TYPE>::~Queue(){  //DTOR
    ClearList(this->rear);
    front = rear = nullptr;
}

template <typename ITEM_TYPE>
void Queue<ITEM_TYPE> :: ClearQueue(){
    ClearList(this->rear);
    front = rear = nullptr;
}
template <typename ITEM_TYPE>
Queue<ITEM_TYPE>& Queue<ITEM_TYPE>::operator=(Queue<ITEM_TYPE>& assignthis){
    this->rear = CopyList(assignthis.rear);
    this->front = LastNode(this->rear);
    return *this;
}
template <typename ITEM_TYPE>
ITEM_TYPE Queue<ITEM_TYPE>::Front(){
    return front->_item;
}
template <typename ITEM_TYPE>
ITEM_TYPE Queue<ITEM_TYPE>::Rear(){
    return rear->_item;
}
template <typename ITEM_TYPE>
bool Queue<ITEM_TYPE>::Empty(){   //empty
    return !front;
}
template <typename ITEM_TYPE>
void Queue<ITEM_TYPE>::Push_back(ITEM_TYPE pushthis){  //add function
    Insert_Head(this->rear, pushthis);
    this->front = LastNode(this->rear);
}
template <typename ITEM_TYPE>
ITEM_TYPE Queue<ITEM_TYPE>::Pop_front(){ //front pop
    ITEM_TYPE t = DeleteNode(rear, front); //rear = head, and delete front
    front = LastNode(rear);
    return t;
}
template <typename ITEM_TYPE>
ITEM_TYPE Queue<ITEM_TYPE>::Pop_rear(){     //delete
    return DeleteNode(rear, rear);
}
template <typename ITEM_TYPE>
void Queue<ITEM_TYPE>::PrintQueue(){    //print function
    PrintList(this->rear);
}

template <typename U>
ostream& operator <<(ostream& outs, const Queue<U>& printthis){
    node<U>* temp = printthis.rear;
    while(temp != NULL){
        outs << "[" << temp->_item << "]->";
        temp = temp->_next;
    }
    outs << "|||" << endl;
    return outs;
}

#endif // QUEUE_H
