//loop invariant - linear search

#include <cstdio.h>
#include <vector>

int linear(std::vector<int> list, int target){
}

int main(){
  std::vector<int> list;
  
  int list_size;
  std::scanf("%d", &list_size);

  nums.reserve(list_size)

  while(list_size--){
    int element;
    std::scanf("%d", &element);

    list.push_back(element);
  }
  int what;
  std::scanf("%d", &what);

  int solution = null;

  /*
    loop invarient : 매 루프시작마다 iterator가 기리키는곳 전까지 탐색된 상태이며, solution에는 타당한 값을 업데이트한다.
 
    initial condition : 루프를 시작하기 전에는 iterator가 begin을 가리키며 이 전은 없으므로 관계없다.
    maintain condition : 값을 찾을 때 까지 iterator의 값을 보며, iterator는 매 루프마다 증가한다. 만약 찾게 된다면 브레이크, 찾지 못한다면 루프가 계속된다.
    따라서 루프 불변성이 유지된다.
    termination condition : 루프가 종료되는 시점은 iterator가 list의 끝에 다다랐을 때이다. 즉 리스트의 begin부터 end-1까지 탐색된 상태이며, 값을 찾았을 경우는 값,
    찾지 못했을 경우는 null이 존재한다. 따라서 이 알고리즘은 타당하다.
  */

  for(std::vector<int>::iterator it = list.begin(); it != list.end(); ++it){
    if (*it == target){
      solution = target;
      break
    }
  }
}

