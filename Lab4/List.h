#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;

class LinkedList{
    private:
        struct ListNode{
            string word;
            struct ListNode *next;
        };
        ListNode *head, *tail;

    public:
        LinkedList(){
            head = NULL;
            tail = NULL;
        }
        ////////////////////////////////////////////////////////////////////////
        ~LinkedList(){
            ListNode *node, *next;
            node = head;

            while(node!= NULL){
                next = node->next;
                delete node;
                node = next;
            }
        }
        ////////////////////////////////////////////////////////////////////////
        void appendNode(string a){
            ListNode *newNode = new ListNode;;

            newNode->word = a;
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
        ////////////////////////////////////////////////////////////////////////
        void insertNode(string b){
            ListNode *newNode = new ListNode, *temp, *previous = NULL;

            newNode->word = b;

            if(!head){
                head = newNode;
                newNode->next = NULL;
            }
            else{
                temp = head;
                previous = NULL;

                while(temp != NULL && temp->word < b){
                    previous = temp;
                    temp = temp->next;
                }
                if(previous == NULL){
                    head = newNode;
                    newNode->next = temp;
                }
                else{
                    previous->next = newNode;
                    newNode->next = temp;
                }
            }
        }
        ////////////////////////////////////////////////////////////////////////
        void deleteNode(string c){
            ListNode *temp, *previous;

            if(!head)
                return;
            if(head->word == c){
                temp = head->next;
                delete head;
                head = temp;
            }
            else{
                temp = head;

                while(temp != NULL && temp->word != c){
                    previous = temp;
                    temp = temp->next;
                }
                if(temp){
                    if(temp == tail)
                        tail = previous;
                    previous->next = temp->next;
                    delete temp;
                }
            }
        }
        ////////////////////////////////////////////////////////////////////////
        void displayList() const{
            ListNode *temp;
            if(head != NULL){
                temp = head;
                while(temp){
                    cout << temp->word << endl;
                    temp = temp->next;
                }
            }
            else   
                cout << "\nAll list nodes have been removed.\n\n";
        }
};

#endif