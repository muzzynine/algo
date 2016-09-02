#include <iostream>
#define PARENT(i) (i>>2)
#define LEFT(i) (i<<2)
#define RIGHT(i) LEFT(i)+1

#define HEAP_MAXIMUM(a) a[0]

struct Heap{
  int *A;
  int length;
  int (*heap_max_heapify)(struct Heap *this);
};

Heap heap_constructor(int i){
  Heap new_one;
  new_one.A = new int(i);
  new_one.heap_max_heapify = max_heapify
  
}

void max_heapify(Heap *this, int i){
  int l = LEFT(i);
  int r = RIGHT(i);
  int largest;

  if(l <= this->length && this->A[l] > this->A[i]){
    largest = l;
  } else {
    largest = i;
  }

  if(r <= this->length && this->A[r] > this->A[largest]){
    largest = r;
  }

  if(largest != i){
    int tmp = this->A[largest];
    this->A[largest] = this->A[i];
    this->A[i] = tmp;
    max_heapify(this, largest);
  }
}

void build_max_heap(int *array, int length){
  int size = length/2;
  while(size--){
    max_heapify(array, size);
  }
}

void heap_sort(int *array, int length){
  build_max_heap(array, length);
  while(length-- > 0){
    int tmp = array[length];
    array[length] = array[0];
    array[0] = tmp;
    max_heapify(a, 0);
  }
}

int heap_extract_max(int *array, int length){
  int max = a[0];
  a[0] = a[length];
  length -= 1;
  max_heapify(array, 0);
  return max
}

int heap_increase_key(int *array, int i, int key, int length){
  a[i] += key;
  while(i > 0 && a[i] > a[PARENT(i)]){
    int tmp = a[PARENT(i)];
    a[PARENT(i)] = a[i];
    a[i] = tmp;
    i = PARENT(i);
  }
}


