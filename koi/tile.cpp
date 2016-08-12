#include <iostream>

using namespace std;

long long cache[81] = {-1, };

long long compute(int n){
  if(n == 1){
    return 1;
  } else if(n==2){
    return 1;
  }

  if(cache[n-1] > 0){
    return cache[n-1];
  }

  return cache[n-1] = compute(n-1) + compute(n-2);
}

long long compute2(int n){
  if(n == 1){
    return 4;
  } else if(n== 2){
    return 6;
  }
  return ((compute(n) + compute(n-1)) * 2) + ((compute(n-1) + compute(n-2)) * 2);
}

int main(){
  int n;

  cin >> n;

  cout << compute2(n)<< endl;

  return 0;
}

