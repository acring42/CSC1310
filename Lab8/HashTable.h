/*
	Title:    Lab8.cpp
	Author:   Austin Ring
	Date:     4/9/2021
	Purpose:  Implementation of HashTable Class
*/
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <iomanip>
#include "HashEntry.h"
using namespace std;

class HashTable
{
	private:
		int tableSize;
		HashEntry** hashArray;
		
	public:
		HashTable(int size){
			tableSize = size;
			hashArray = new HashEntry*[tableSize];
			for(int i=0; i<tableSize; i++)
				hashArray[i] = NULL;
		}

		~HashTable(){
			for(int i=0; i<tableSize; i++){
				if(hashArray[i] != NULL){
					HashEntry *prevEntry = NULL;
					HashEntry *entry = hashArray[i];
					while(entry != NULL){
						prevEntry = entry;
						entry = entry->getNext();
						delete prevEntry;
					}
				}
			}
			delete [] hashArray;
		}
		
		Costume* getValue(int key){
			int bucketIndex = key % tableSize;
			HashEntry *entry = hashArray[bucketIndex];
			while(entry != NULL && entry->getKey() != key)
				entry = entry->getNext();
			return entry->getValue();
		}
		
		void putValue(int key, Costume* value){
			int bucketIndex = key % tableSize;
			cout << "BUCKET " << bucketIndex << endl;
			
			if(hashArray[bucketIndex] == NULL){
				hashArray[bucketIndex] = new HashEntry(key, value);
			}
			else{
				HashEntry* entry = hashArray[bucketIndex];
				while(entry->getNext() != NULL)
					entry = entry->getNext();
				if(entry->getKey() == key)
					entry->setValue(value);
				else
					entry->setNext(new HashEntry(key, value));
			}
		}
		
		void removeValue(int key){
			HashEntry *entry;
			HashEntry *prevEntry;
			int bucketIndex = key% tableSize;
			if(hashArray[bucketIndex] != NULL){
				prevEntry = NULL;
				entry = hashArray[bucketIndex];
				while(entry->getNext() != NULL & entry->getKey() != key){
					prevEntry = entry;
					entry = entry->getNext();
				}

				if(entry->getKey() == key){
					if(prevEntry == NULL){
						HashEntry *nextEntry = entry->getNext();
						delete entry;
						hashArray[bucketIndex] = nextEntry; //re-link list 
					}
					else{
						HashEntry *next = entry->getNext();
						delete entry;
						prevEntry->setNext(next);
					}
				}
			}		
		}
		
		void printHashTable(){
			cout << "----------\n";
			for(int i=0; i<tableSize; i++){
				if(hashArray[i] != NULL){
					HashEntry* entry = hashArray[i];
					while(entry->getNext() != NULL){
						cout << "---->" << setw(8) << *entry->getValue();
						entry = entry->getNext();
					}
					cout << "---->" << setw(8) << *entry->getValue();
					cout << "\n";
				}
				else
					cout << setw(8) << -1 << "\n";
			}
			cout << "----------\n\n";
		}
	
};
#endif