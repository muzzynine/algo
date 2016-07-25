#include <stdio.h>

int fees[1001] = {0, };

double compute(int max, int min){
  int i, j, k;
  double smallest = 101;
  for(i = min; i < max+1; i++){
    for(j = 0; j < max-i+1; j++){
      int sum = 0;
      for(k = j; k < j+i ; k++){
	sum += fees[k];
      }
      double average = (double)sum / (double)i;
      if(smallest > average) smallest = average;
    }
  }
  return smallest;
}

int main(){
  int cases, max, min, fee;
  scanf("%d", &cases);
  while(cases--){
    scanf("%d %d", &max, &min);
    for(int i = 0; i < max; i++){
      scanf("%d", &fee);
      fees[i] = fee;
    }
    double sol = compute(max, min);
    printf("%.8f\n", sol);
  }
  return 0;
}

