#include <iostream>

using namespace std;

/*
 * i  | 1 2 3 4  5  6  7  8  9 10
 * -------------------------------
 * pi | 1 5 8 9 10 17 17 20 24 30 
 */

int rod[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
int cache[11] = {-1, };


int cut_rod(int n){
  if (n == 0) {
    return 0;
  }

  if (cache[n] > 0) {
      return cache[n];
  }
  int max = -1;
  for(int i = 1; i < n+1; i++){
    int value = rod[i] + cut_rod(n-i);
    if(max < value) max = value;
  }

  return cache[n] = max;
}

int main(){
  int len;
  cin >> len;

  int sol = cut_rod(len);
  cout << sol << endl;

  return 0;
}
