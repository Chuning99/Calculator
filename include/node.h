#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

template <typename ITEM_TYPE>
struct node{

    node();
    node(ITEM_TYPE item);

    template <typename T>
    friend std::ostream& operator <<(std::ostream& outs, const node<T> &printMe);
    ITEM_TYPE _item;
    node* _next;
};


//default constructor
template <typename ITEM_TYPE>
node<ITEM_TYPE>::node()
{
    _item = ITEM_TYPE();
    _next = NULL;
}

//consturctor
template <typename ITEM_TYPE>
node<ITEM_TYPE>::node(ITEM_TYPE item)
{
    _item = item;
    _next = NULL;
}

template <typename T>
ostream& operator <<(std::ostream& outs, const node<T> &printthis)
{
    outs << "[" << printthis._item << "]-> ";
    return outs;
}

#endif // NODE_H
