/*
 * ITA dp pratice 2
 * 한 행의 최대길이 M이 주어지고 들어갈 n개의 단어가 주어질 때  마지막 행을 제외한 나머지 행에서 최소한의 끝 공백문자를 구하는 문제
 
 */

#include <iostream>
#define MAX_NUM_OF_SENTENCE 100

using namespace std;


const int MAX_COLUMN_LENGTH = 10;

int cache[MAX_NUM_OF_SENTENCE] = {0, };

int sentence[MAX_NUM_OF_SENTENCE] = {0, };
int num_of_keyword;

int partial_sum(int i, int j){
  int sum = 0;
  for(int s = i; s < j+1; s++){
    sum += sentence[s];
  }
  return sum;
}

int solve(int i){
  if(partial_sum(i, num_of_keyword-1) <= MAX_COLUMN_LENGTH) return 0;
  if(cache[i] != 0){
    return cache[i];
  }
  int min = MAX_COLUMN_LENGTH;
  int j = i;
  int whitespace = MAX_COLUMN_LENGTH - sentence[i];
  while(whitespace >= 0 && j < num_of_keyword){
    int mid_solution = solve(j+1);
    if(mid_solution+whitespace < min) min = mid_solution + whitespace; 
    j++;
    whitespace = MAX_COLUMN_LENGTH - (j-i) - partial_sum(i, j);
  }
  return cache[i] = min;
}

int main(){
  int cases;
  cin >> cases;
  while(cases--){
    cin >> num_of_keyword;

    for(int i = 0; i < num_of_keyword; i++){
      string s;
      cin >> s;

      sentence[i] = s.length();
    }

    int solution = solve(0);
    printf("%d", solution);
  }
}
