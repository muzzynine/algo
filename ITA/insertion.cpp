#include <iostream>

/* loop invariant 
 * array[0..i-1]은 내림차순 정렬되어있다.
 * initialization : 루프 시작전 array[0..i] = array[0]이므로 내림차순 정렬되어있다.
 * maintain : 매 루프마다 i의 범위가 증가하고, array[0..i]사이가 정렬되기 때문에 다음 루프 array[0..i-1]은 내림차순 정렬되어있다.
 * termination : 루프는 배열의 크기인 0..9까지 진행되고 따라서 마지막 루프 종료시 array[0..9]가 내림차순 정렬되므로 이 알고리즘은 유의미하다.
 */

void my_insertion_sort(int* array){
  for(i = 1; i<10; i++){
    int k = array[i];
    int j = i-1;
    while(j > -1 && k>array[j]){
      array[j+1] = array[j];
      j = j-1;
    }
    array[j+1] = k;
  }
}


int main(){
  int a[10] = {5,4,3,2,1,9,8,7,6,0};

  insertion_sort(a);

  for(int i = 0; i < 10; i++){
    std::cout << a[i];
  }

  return 0;
  
}
