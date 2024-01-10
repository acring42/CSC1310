#ifndef ARRAYMINHEAP_H
#define ARRAYMINHEAP_H

#include "Creature.h"
#include <iostream>
#include<cmath>
using namespace std;

class ArrayMinHeap{
	private:
		Creature *heapArray;
		int capacity;
		int heap_size;
		
		void swap(Creature *x, Creature *y){
			Creature temp = *x;
			*x = *y;
			*y = temp;
		}			
		
		int parent(int i){ 
			return (i-1)/2; 
		}

		int left(int i){ 
			return (2*i + 1); 
		}

		int right(int i){ 
			return (2*i + 2); 
		}
		
	public:
		ArrayMinHeap(int cap){
			heap_size = 0;
			capacity = cap;
			heapArray = new Creature[cap];
		}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		~ArrayMinHeap(){
			delete [] heapArray;
		}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		void minHeapify(int i){
		    int l = left(i);
		    int r = right(i);
		    int smallest = i;
		    if (l < heap_size && &heapArray[l] < &heapArray[i])
		        smallest = l;

		    if (r < heap_size && &heapArray[r] < &heapArray[smallest])
		        smallest = r;

		    if (smallest != i){
		        swap(&heapArray[i], &heapArray[smallest]);
		        minHeapify(smallest);
		    }
		}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	 	Creature peek(){
			if(!isEmpty())
				return heapArray[0]; 
		}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		Creature remove(){
		    if (heap_size == 0){
				cout << "Error:  there is no nodes in the heap.\n";
			}
		    else if (heap_size == 1){
		        heap_size--;
		        return heapArray[0];
		    }

		    Creature root = heapArray[0];
		    heapArray[0] = heapArray[heap_size-1];
		    heap_size--;
		    minHeapify(0);
		    return root;
		}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		void insert(Creature newValue){
			if (heap_size == capacity){
				resizeArray();
			}

			heapArray[heap_size] = newValue;
			heap_size++;
			int i = heap_size - 1;

			while (i != 0 && &heapArray[parent(i)] > &heapArray[i]){
				swap(&heapArray[i], &heapArray[parent(i)]);
				i = parent(i);
			}
		}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		void resizeArray(){
			int cap = capacity * 2; 
			Creature *newHeapArray = new Creature[cap];

			for(int x = 0; x < capacity; x++){
				newHeapArray[x] = heapArray[x];
			}
			delete [] heapArray;
			heapArray = newHeapArray;
			capacity = cap;
		}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		bool isEmpty(){
			if(heap_size == 0)
				return true;
			else
				return false;
		}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		int getNumberOfNodes(){
			return heap_size;
		}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		int getHeight(){
			return ceil(log2(heap_size + 1));
		}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		void display(){
			for(int i=0; i<heap_size; i++){
				cout << heapArray[0].getName() << endl;
			}

		}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		void saveToFile(){
			
		}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
};
#endif
 
























 