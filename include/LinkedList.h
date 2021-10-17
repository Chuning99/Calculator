#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"
#include <iostream>
using namespace std;

//Linked List General Functions:
template <typename ITEM_TYPE>
void PrintList(node<ITEM_TYPE>* head){
    while(head){
        cout << *head;
        head = head->_next;
    }
    //cout << "|||" << endl;
}

template <typename ITEM_TYPE>   //not done
void PrintList_backwards(node<ITEM_TYPE> *head){
    helper(head);
    //cout << "|||" << endl;
}

template <typename ITEM_TYPE>
void helper(node<ITEM_TYPE>* head){
    if(!head) return;
    helper(head->_next);
    //cout << *head;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* SearchList(node<ITEM_TYPE>* head, ITEM_TYPE key){
    while(head){
        if(head->_item == key) return head;
        head = head->_next;
    }
    return nullptr;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* Insert_Head(node<ITEM_TYPE> *&head, ITEM_TYPE insertThis){
    node<ITEM_TYPE>* newHead = new node<ITEM_TYPE>(insertThis);
    newHead->_next = head;
    head = newHead;
    return head;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* Insert_After(node<ITEM_TYPE>*& head, node<ITEM_TYPE> *afterThis, ITEM_TYPE insertThis){
    node<ITEM_TYPE>* newNode = new node<ITEM_TYPE>(insertThis);
//    node<ITEM_TYPE>* temp = afterThis->_next;
//    afterThis->_next = newNode;
//    newNode->_next = temp;
    newNode->_next = afterThis->_next;
    afterThis->_next = newNode;
    return head;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* Insert_Before(node<ITEM_TYPE>*& head,
                              node<ITEM_TYPE>* beforeThis,
                              ITEM_TYPE insertThis){
    if(beforeThis == nullptr) return head;
    node<ITEM_TYPE>* p = PreviousNode(head, beforeThis);
    if(p) head = Insert_After(head, p, insertThis);
    else head = Insert_Head(head, insertThis);
    return head;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* PreviousNode(node<ITEM_TYPE>* head, node<ITEM_TYPE>* prevToThis){
    if(head == prevToThis) return nullptr; // check if head is our target
    while(head && head->_next){
        if(head->_next == prevToThis) return head;
        head = head->_next;
    }
    return head;
}

template <typename ITEM_TYPE>
ITEM_TYPE DeleteNode(node<ITEM_TYPE>*&head, node<ITEM_TYPE>* deleteThis){
    node<ITEM_TYPE>* prev = PreviousNode(head, deleteThis);
    if(!prev) head = head->_next;
    else{
        prev->_next = deleteThis->_next;
        deleteThis->_next = nullptr;
    }
    ITEM_TYPE item = deleteThis->_item;
    delete [] deleteThis;
    return item;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* CopyList(node<ITEM_TYPE>* head){
    node<ITEM_TYPE>* dummy = new node<ITEM_TYPE>(ITEM_TYPE());
    node<ITEM_TYPE>* walker = dummy;
    while(head){
        node<ITEM_TYPE>* newNode = new node<ITEM_TYPE>(head->_item);
        walker->_next = newNode;
        walker = walker->_next;
        head = head->_next;
    }
    return dummy->_next;
}

template <typename ITEM_TYPE>
void ClearList(node<ITEM_TYPE>*& head){
    node<ITEM_TYPE>* temp;
    while(head){
        temp = head->_next;
        delete head;
        head = temp;
    }
}

template <typename ITEM_TYPE>
ITEM_TYPE& At(node<ITEM_TYPE>* head, int pos){
    for(int i = 0; i < pos; i++){
        if(head) head = head->_next;
    }
    if(head) return head->_item;
    else{
        ITEM_TYPE t = ITEM_TYPE();
        return t;
    }
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* InsertSorted(node<ITEM_TYPE>* &head, ITEM_TYPE item, bool ascending=true){
    node<ITEM_TYPE>* wtg = WhereThisGoes(head, item, ascending);
    if(wtg) head = InsertAfter(head, wtg, item);
    else head = InsertHead(head, item);
    return head;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* InsertSorted_and_add(node<ITEM_TYPE>* &head, ITEM_TYPE item, bool ascending=true);

template <typename ITEM_TYPE>
node<ITEM_TYPE>* WhereThisGoes(node<ITEM_TYPE>* head, ITEM_TYPE item, bool ascending=true){
    if(item <= head->_item) return nullptr;
    node<ITEM_TYPE>* walker = head;
    if(ascending){
        while(walker && walker->_next){
            if(item <= walker->_next->_item){
                return walker;
            }
            walker = walker->_next;
        }
    }
    else{
        while(walker && walker->_next){
            if(item >= walker->_next->_item){
                return walker;
            }
            walker = walker->_next;
        }
    }
    return walker;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* LastNode(node<ITEM_TYPE>* head){
    while(head && head->_next){
        head = head->_next;
    }
    return head;
}

template <typename ITEM_TYPE>
ITEM_TYPE remove_head(node<ITEM_TYPE>*& head_ptr){
    //assert ( head_ptr != nullptr );
    node<ITEM_TYPE>* walker = head_ptr;
    head_ptr = walker ->_next;
    ITEM_TYPE item = (*walker)._item;
    delete walker;
    return item;
}

#endif // LINKEDLIST_H
