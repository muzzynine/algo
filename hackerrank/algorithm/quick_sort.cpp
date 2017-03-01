#include <cstdio>

int size;

int partition(int *arr, int start, int end){
  int pivot = start;
  int v = arr[start];
  int origin = start;
  //loop invariant : 매 루프 시작때, [start, pivot)은 v보다 작은 값의 모임, [pivot, end)는 v보다 크거나 같은 값들의 모임
  for(int i = start+1; i < end; i++){
    if (arr[i] < v){
      int tmp = arr[i];
      arr[i] = arr[pivot];
      arr[pivot] = tmp;
      origin = i;
      pivot++;
    }
  }

  int tmp = arr[pivot];
  arr[pivot] = arr[origin];
  arr[origin] = tmp;

  return pivot;
}

int lumoto_partition(int *arr, int start, int end){
  int pivot = arr[end-1];
  int i = start;
  for(int j = start; j < end-1; j++){
    if (arr[j] <= pivot){
      int tmp = arr[j];
      arr[j] = arr[i];
      arr[i] = tmp;
      i++;
    }
  }

  int tmp = arr[i];
  arr[i] = arr[end-1];
  arr[end-1] = tmp;

  return i;
}

void quicksort(int *arr, int start, int end){
  //basis : start가 end와 같거나 크면 부분문제의 밑바닥이다.
  if(end-start < 2) return;
  int pivot = lumoto_partition(arr, start, end);

  for(int i = 0 ; i < size; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");

  quicksort(arr, start, pivot);
  quicksort(arr, pivot+1, end);

}

int main(){
  int n;
  scanf("%d", &n);
  size = n;

  int arr[1000];
  for(int i = 0; i < n; i++){
    int e;
    scanf("%d", &e);
    arr[i] = e;
  }

  quicksort(arr, 0, n);

  return 0;
}
