/*****************************************************************
	Filename:       LinkedList.h - Class Specification File for 
				    LinkedList Template Class
	Date Created:   3/3/2021
	Author:         Austin Ring
	Purpose:        LAB 5 - A Singly-Linked List implemented in a
				    LinkedList template class that contains a ListNode
				    structure variable
******************************************************************/

#ifndef LinkedList_H
#define LinkedList_H

#include "Pickle.h"
#include <iostream>
using namespace std;


template <typename T>
class LinkedList
{
	private:
		struct ListNode
		{
			T value;
			int position;
			struct ListNode* next;
		}; 

		ListNode *head;	
		ListNode *tail;		

	public:
		LinkedList()
		{ 
			head = NULL; 
			tail = NULL;
		}
		~LinkedList();
		void appendNode(T value);
		void deleteNode(int position);
		void displayList() const;
};

//DEFINE ALL OTHER LinkedList class FUNCTIONS BELOW THIS LINE--------------------------------
template <typename T>
void LinkedList<T>::appendNode(T a){
	ListNode *newNode = new ListNode;

	newNode->value = a;
	newNode->next = NULL;

	if(!head){
		head = newNode;
		tail = newNode;
	}
	else{
		tail->next = newNode;
		tail = newNode;
	}
}

template <typename T>
void LinkedList<T>::deleteNode(int b){
	ListNode *node, *previous, *next;

	if (!head)
		return;

	struct ListNode* temp = head;
	if(b==0){
		head=temp->next;
		delete temp;
		return;
	}
	for(int i=0; temp!=NULL && i<b-1; i++)
		temp = temp->next;
	if(temp==NULL || temp->next==NULL)
		return;
		
	next = temp->next->next;
	delete temp->next;
	temp->next = next;
}

template <typename T>
void LinkedList<T>::displayList() const{
	ListNode *node;
	int count = 1;

	if(head!=NULL){
		node = head;
		while(node){
			cout << "-----Node " << count << " with the memory address " << &node;
			cout << node->value;
			node = node->next;
			++count;
		}
	}
	else
		cout << "\nThere are no nodes in the list.\n";
}

template <typename T>
LinkedList<T>::~LinkedList(){
	ListNode *node, *next;

	node = head;
	while(node!=NULL){
		cout << "*****DELETING the node with the address:	" << &node << endl;
		next = node->next;
		delete node;
		node = next;
	}
}
#endif