#include <cstdio>
#include <map>

using namespace std;

map<int, int> cache;

int polynomio(int before, int remaining){
  if(remaining < 1){
    return 1;
  }
  
  map<int, int>::iterator iter = cache.find(remaining*1000 + before);
  if (iter != cache.end()){
    return iter->second;
  }

  int solution = 0;
  for (int i=1; i<=remaining; i++){
    int partial = polynomio(i, remaining-i);
    solution += (before+i-1)*partial;
    solution %= 10000000;
  }
  cache[remaining*1000 + before] = solution;
  
  return solution;
}

int solve(int remaining){
  int solution = 0;
  
  for(int i=1; i <= remaining; i++){
    solution += polynomio(i, remaining-i);
  }
  solution %= 10000000;
  
  return solution;
}

int main(){
  int cases;
  scanf("%d", &cases);
  while (cases--){
    int num;
    scanf("%d", &num);
    int solution = solve(num);
    printf("%d\n", solution);
  }
}


