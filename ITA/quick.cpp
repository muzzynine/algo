#include <iostream>

int partition(int *a, int p, int r){
  int q = a[r];
  int i = p-1;
  for(int j = p ; j < r; j++){
    if(a[j] < q){
      i += 1;
      int tmp = a[j];
      a[j] = a[i];
      a[i] = tmp;
    }
  }
  int tmp = a[i+1];
  a[i+1] = q;
  a[r] = tmp;
  return i+1;
}

void quicksort(int *array, int p, int r){
  if(p<r){
    int q = partition(array, p, r);
    quicksort(array, p, q-1);
    quicksort(array, q+1, r);
  }
}

int main(){
  int array[8] = {2, 8, 7, 1, 3, 4, 6, 4};
  quicksort(array, 0, 7);

  for(int i = 0; i < 8; i++){
    std::cout << array[i];
  }
  return 0;
}

