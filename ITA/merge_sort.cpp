#include <stdio.h>

void merge(int *a, int p, int q, int r){
  int n1_arr[6];
  int n2_arr[6];

  int n1 = q-p;
  int n2 = r-q+1;

  int i;
  int j;

  for(i = 0; i < n1; i++){
    n1_arr[i] = a[p+i];
  }

  for(j = 0; j < n2; j++){
    n2_arr[j] = a[q+j];
  }

  n1_arr[i] = 99;
  n2_arr[j] = 99;

  i = 0;
  j = 0;
  
  for(int k = p; k < r+1; k++){
    if(n1_arr[i] < n2_arr[j]){
      a[k] = n1_arr[i];
      i+=1;
    } else {
      a[k] = n2_arr[j];
      j+=1;
    }
  }
}


void merge_sort(int *a, int p, int r){
  if(p<r){
    int q = (r-p+1)/2;
    merge_sort(a, p, p+q-1);
    merge_sort(a, p+q, r);
    merge(a, p, p+q, r);
  }
}

int main(){
  int test[10] = {10,9,8,7,6,5,4,3,2,1};

  merge_sort(test, 0, 9);

  for(int i = 0; i < 10; i++){
    printf("%d", test[i]);
  }
}


		  
