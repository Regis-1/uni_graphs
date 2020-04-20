#ifndef MINHEAP_HH
#define MINHEAP_HH

#include <iostream>
#include <climits>

class MinHeap{
	private:
		int *h_array;
		int *hpos;
		int capacity;
		int heap_size;
		void swap(int x, int y);
	public:
		MinHeap(){}
		MinHeap(int capacity);
		void min_heapify(int);
		int parent(int i){return (i-1)/2;}
		int left_child(int i){return (2*i+1);}
		int right_child(int i){return (2*i+2);}
		int extract_min();
		void decrease_key(int i, int new_val);
		int get_min(){return h_array[0];}
		int *get_hpos();
		int get_i_of_node(int vertex);
		void delete_key(int i);
		void insert_key(int k);
};

#endif
