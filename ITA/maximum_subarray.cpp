#include <stdio.h>

struct sub_array_info{
  int low;
  int high;
  int sum;
};


sub_array_info max_crossing_subarray(int *a, int p, int q, int r){
  int left_sum = -99;
  int sum = 0;
  int max_left = q;
  for(int i = q ; i > p-1 ; i--){
    sum += a[i];
    if(left_sum < sum){
      left_sum = sum;
      max_left = i;
    }
  }
  int right_sum = -99;
  sum = 0;
  int max_right = q+1;
  for(int i = q+1 ; i < r+1 ; i++){
    sum += a[i];
    if(right_sum < sum){
      right_sum = sum;
      max_right = i;
    }
  }

  return (struct sub_array_info){max_left, max_right, left_sum+right_sum};
}

sub_array_info maximum_subarray(int *a, int p, int r){
  if(p==r){
    return (struct sub_array_info){p, r, a[p]};
  } else {
    int q = (p+r)/2;
    sub_array_info left = maximum_subarray(a, p, q);
    sub_array_info right = maximum_subarray(a, q+1, r);
    sub_array_info mid = max_crossing_subarray(a, p, q, r);

    if(left.sum >= right.sum && left.sum >= mid.sum){
      return left;
    } else if(right.sum >= left.sum && right.sum >= mid.sum){
      return right;
    } else return mid;
  }
}

int main(){
  int array[16] = {13, -3, -25, 20, -3,
		   -16, -23, 18, 20, -7,
		   12, -5, -22, 15, -4, 7};

  sub_array_info result = maximum_subarray(array, 0, 15);

  printf("%d %d %d\n", result.low, result.high, result.sum);
  
  return 0;
}

