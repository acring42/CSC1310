#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

class Queue{
    private:
        struct QueueNode{
            string name;
            QueueNode *next;
        };
        int numNodes;
        QueueNode *head, *tail;
        
    public:
        Queue(){
            head = NULL;
            tail = NULL;
        }
        ////////////////////////////////////////////////////////////////////////////////////////////
        void enqueue(string name){
            QueueNode *newNode;
            newNode = new QueueNode;
            newNode->name = name;
            
            if(!head){
            	newNode->next = NULL;
            	head = newNode;
            	tail = newNode;
            }

            else{
            	tail->next = newNode;
            	tail = newNode;
            	tail->next = NULL;
            }
        }
        ////////////////////////////////////////////////////////////////////////////////////////////
        string dequeue(){
        	QueueNode *node;
        	string a, temp;

        	if(!head){
                cout << "There is no one in line!" << endl;
                return a;
            }
        	else{
        		node = head;
        		head = head->next;

        		temp = node->name;
        		delete node;

        		return temp;
        	}
        }
        ////////////////////////////////////////////////////////////////////////////////////////////
        bool isEmpty(){
        	if(!head)
        		return true;
        	else
        		return false;
        }
        ////////////////////////////////////////////////////////////////////////////////////////////
        ~Queue(){
            QueueNode *node;
	        QueueNode *next;

	        node = head;
	        while (node){
                cout << "\n\nOh shoot, I am sorry, our park is closed so " << node->name << " will not get to ride today.";
	        	next = node->next;
	        	delete node;
	        	node = next;
	        }
        }
        ////////////////////////////////////////////////////////////////////////////////////////////
};
#endif
