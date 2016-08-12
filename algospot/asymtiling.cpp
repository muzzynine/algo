#include <iostream>

using namespace std;

#define MOD 1000000007
#define MAX 101;
int cost[101] = {-1, };

int tiling(int n){
  if(n==2 || n==1){
    cost[1] = 1;
    cost[2] = 2;
    return cost[n];
  }
  
  int &v = cost[n];
  if(v != -1){
    return v;
  }
  return cost[n] = (tiling(n-1) + tiling(n-2))%MOD;
}

int asymtiling(int n){
  if(n==2 || n==1){
    return 0;
  }
  if(n%2){
    return (tiling(n) - tiling((n-1)/2) + MOD)%MOD;
  } else {
    return (tiling(n) - ((tiling(n/2) + tiling((n/2)-1))%MOD) + MOD)%MOD;
  }
}


int main(){
  int l = MAX;
  while(l--){
    cost[l] = -1;
  }
  int cases;
  int width;
  cin >> cases;
  while(cases--){
    cin >> width;
    cout << asymtiling(width) << endl;
  }
}

