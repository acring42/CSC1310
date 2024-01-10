/**********************************************************************
	Title:        LinkedList.h
	Author:       Austin Ring
	Date Created: 3/3/2021
***********************************************************************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <fstream>
#include <string>
//#include <cstring>
#include <limits>
#include <ctime>
using namespace std;

template <typename T>
class LinkedList{
    private:
        struct ListNode{
            T value;
            struct ListNode* next;
        };
        ListNode* head;
        ListNode* tail;
        int numNodes;

    public:
        LinkedList();
        ~LinkedList();
        int getLength();
        T getNodeValue(int);
        void insertNode(T);
        void display(T) const;
};

#endif