#include "../include/MinHeap.hh"

MinHeap::MinHeap(int capacity){
	heap_size = 0;
	this->capacity = capacity;
	h_array = new int[capacity];
	hpos = new int[capacity];
}

void MinHeap::insert_key(int k){
	if(heap_size == capacity){
		std::cout<< "\nOverflow: Could not insert_key\n";
		return;
	}

	heap_size++;
	int i = heap_size - 1;
	h_array[i] = k;
	hpos[i] = i;
	while(i != 0 && h_array[parent(i)] > h_array[i]){
		swap(i, parent(i));
		i = parent(i);
	}
}

void MinHeap::decrease_key(int i, int new_val){
	h_array[i] = new_val;
	while(i != 0 && h_array[parent(i)] > h_array[i]){
		swap(i, parent(i));
		i = parent(i);
	}
}

int *MinHeap::get_hpos(){
	return hpos;
}

int MinHeap::get_i_of_node(int vertex){
	for(int i=0; i<heap_size; i++){
		if(hpos[i] == vertex)
			return i;
	}
	return -1;
}

int MinHeap::extract_min(){
	if(heap_size <= 0)
		return INT_MAX;
	if(heap_size == 1){
		heap_size--;
		return hpos[0];
	}

	int root = hpos[0];
	h_array[0] = h_array[heap_size-1];
	heap_size--;
	min_heapify(0);

	return root;
}	

void MinHeap::delete_key(int i){
	decrease_key(i, INT_MIN);
	extract_min();
}

void MinHeap::min_heapify(int i){
	int l = left_child(i);
	int r = right_child(i);
	int smallest = i;
	if(l<heap_size && h_array[l] < h_array[i])
		smallest = l;
	if(r<heap_size && h_array[r] < h_array[smallest])
		smallest = r;
	if(smallest != i){
		swap(i, smallest);
		min_heapify(smallest);
	}
}

/*PRIVATE METHODS*/
void MinHeap::swap(int x, int y){
	int temp = h_array[x];
	h_array[x] = h_array[y];
	h_array[y] = temp;

	temp = hpos[x];
	hpos[x] = hpos[y];
	hpos[y] = temp;
}
