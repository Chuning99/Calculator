#ifndef STACK_H
#define STACK_H
//#include"linked_list.h"
#include "include/LinkedList.h"
#include"cassert"
template <typename T>
class Stack
{
public:
    class Iterator{
    public:
    friend class Stack;                              //give access to list to access _ptr
    Iterator(){_ptr = NULL;}                        //default ctor
    Iterator(node <T>* p)                   //Point Iterator to where p is pointing to
    {
      _ptr = p;
    }
    T operator *()                         //dereference operator
    {
      assert(_ptr);
      return _ptr->_item;  //return item
    }
    node<T>* operator ->()                     //member access operator
    {
        //assert(_ptr);
        return _ptr;
    }
    operator bool()                                //casting operator: true if _ptr not NULL
    {
       //return _ptr;
       if ( _ptr == nullptr ){
           return (false);
       }
       return (true);
    }                                               //      this turned out to be a pain!
    bool is_null()
       {
        if ( _ptr == nullptr ){
            return (true);
        }
        return (false);
        //return _ptr == nullptr;
        }       //true if _ptr is NULL
    friend bool operator !=(const Iterator& left,
                            const Iterator& right) //true if left != right
    {
        if(left._ptr != right._ptr)    // return left._ptr != right._ptr
            return true;
        else
            return false;
    }

    friend bool operator ==(const Iterator& left,
                            const Iterator& right) //true if left == right
    {
        if(left._ptr == right._ptr) //return left._ptr == right._ptr
            return true;
        else
            return false;
    }

    Iterator& operator++()                         //member operator: ++it; or ++it = new_value
    {
        //assert(_ptr);
        _ptr = _ptr->next;
        return *this;
    }

    friend Iterator operator++(Iterator& it,
                               int unused)         //friend operator: it++
    {
        Iterator hold;
        hold = it;
        it._ptr = it._ptr->next;
        return hold;
    }

    private:
    node<T> *_ptr;
    };
    T Pop();
    Stack();
    Stack(const Stack<T>& aStack);
    ~Stack();
    Iterator top();
    //T top();
    void push(const T& item);
    void pop();
    bool empty();
    void PrintStack();
    void ClearList();
     int StackSize();
     template <class U>
     friend ostream& operator <<(ostream& outs,          //insertion operator for list
                                 const Stack<U>& s);
private:
node<T> *_top;


};

template <typename T>
int Stack<T>::StackSize(){        //check size, use walker to check size
    node<T>*walker = _top;
    int counter = 0;
  while(walker!= nullptr){
      counter++;
     walker = walker->next;

  }
    return counter;

}
template <typename T >
T Stack<T>::Pop(){
   return  remove_head(_top);
}
template <typename T>
void Stack<T>::ClearList(){ //use clean node to check
    ::ClearList(_top);
}
template <typename T>
Stack<T>::Stack(){    //CTOR
    _top = nullptr;

}
template <typename T>
Stack<T>::Stack(const Stack<T>& aStack){     //copy CTOR
    _top = CopyList(aStack._top);
}
template <typename T>
Stack<T>::~Stack(){       //DEOR
   ClearList();
}
template <typename T>
void Stack<T>::push(const T& item){    //stack add a node
    node<T>* temp = new node<T>();
    temp->_item = item;
    temp ->_next = _top;
    _top = temp;

}

template <typename T>
void Stack<T>::pop(){   //remove a node
    if(empty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        node<T>* temp = _top;
        _top = _top ->_next;
//        delete temp;
  }
}

template <typename T>
bool Stack<T>::empty(){     //check if stack is empty
    if(_top == nullptr)
        return true;
    else
        return false;
}
template <typename T>
void Stack<T>::PrintStack(){   // Print node
  PrintList(_top);
}
template <typename T>
typename Stack<T>::Iterator Stack<T>:: top(){   //top Iterator
    return Iterator(_top);
}
//template <typename T>
//T Stack<T>::top(){
//    return _top;
//}
template <class U>
ostream& operator <<(ostream& outs,          //insertion operator for list
                            const Stack<U>& s){
    node<U>* walker =s._top;   //s's top

    while(walker != NULL){      //same as node << operator

        outs<<*walker;


        walker = walker-> _next;
    }
    outs<<"|||"<<endl;
    return outs;
}

#endif // STACK_H
