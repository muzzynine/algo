#include <iostream>
#include <vector>
#include <tuple>

unsigned long long int analysis(std::vector<int>& arr, int start, int end){
  if(end - start <= 1){
    return 0;
  }

  unsigned long long int ls = analysis(arr, start, (start + end)/2);
  unsigned long long int rs = analysis(arr, (start + end)/2, end);
  unsigned long long int shiftedCnt = ls + rs;

  std::vector<int> tmp;
  tmp.reserve(end - start);

  int lcur = start;
  int rcur = (start + end)/2;
    
  while(lcur < (start + end)/2 && rcur < end){
    if(arr[lcur] > arr[rcur]){
      tmp.push_back(arr[rcur++]);
      unsigned int tmp = shiftedCnt;
      shiftedCnt += (start + end)/2 - lcur;

    } else {
      tmp.push_back(arr[lcur++]);
    }
  }

  if(lcur >= (start + end)/2){
    while(rcur < end){
      tmp.push_back(arr[rcur++]);
    }
  } else {
    while(lcur < (start + end)/2){
      tmp.push_back(arr[lcur++]);
    }
  }
  
  for(int i = start; i < end; i++){
    arr[i] = tmp[i-start];
  }

  return shiftedCnt;
}


int main(){
  int t;
  std::cin >> t;
  while(t--){
    std::vector<int> arr;
    int n;
    std::cin >> n;
    while(n--){
      int e;
      std::cin >> e;
      arr.push_back(e);
    }
    
    std::cout << analysis(arr, 0, arr.size()) << std::endl;
  }
}
