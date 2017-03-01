#include <cstdio>

void insertion_sort(int* arr, int n){
  for(int i = 1; i < n; i++){
    int tmp_index = i;
    int tmp_value = arr[i];
    while(arr[tmp_index-1] > tmp_value && tmp_index > 0){
      arr[tmp_index] = arr[tmp_index-1];
      tmp_index--;
    }
    arr[tmp_index] = tmp_value;

    for(int i = 0; i < n; i++){
      printf("%d ", arr[i]);
    }
    printf("\n");
  }
}


int main(){
  int n;
  scanf("%d", &n);

  int buf[1000];

  for(int i = 0; i < n; i++){
    int e;
    scanf("%d", &e);
    buf[i] = e;
  }

  insertion_sort(buf, n);
}
