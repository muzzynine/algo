#include <cstdio>
#include <algorithm>
#include <vector>

#define LIMIT 50

int do_works(std::vector<int> bag){
  std::sort(bag.begin(), bag.end());

  int cnt = 0;
  int start = 0;
  
  while(bag.back() * (bag.size() - start) >= LIMIT){
    int biggest = bag.back();
    bag.pop_back();

    int incr = LIMIT == biggest ? 0 :
      LIMIT % biggest == 0 ? LIMIT/biggest-1 :
      LIMIT/biggest;
    
    start += incr;
    cnt++;
  }

  return cnt;
}

int main(){
  int cases;
  scanf("%d", &cases);
  for(int i = 1; i <= cases; i++){
    std::vector<int> bag;
    int numOfItem;
    scanf("%d", &numOfItem);
    while(numOfItem--){
      int weight;
      scanf("%d", &weight);
      bag.push_back(weight);
    }

    int cnt = do_works(bag);

    printf("Case #%d: %d\n", i, cnt);
  }
}
