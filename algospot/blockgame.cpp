#include <cstdio>
#define LEN_SQUARE 5
using namespace std;

int board[5][5] = {0};

int block[6][2][2] = {{{1, 0}, {1, 0}}, {{1, 1}, {0, 0}},
		      {{1, 1}, {1, 0}}, {{1, 1}, {0, 1}},
		      {{1, 0}, {1, 1}}, {{0, 1}, {1, 1}}};

int solve(int x, int y){

  int selected_x, selected_y;
  for(int i = x; i < LEN_SQUARE; i++){
    for(int j = y; j < LEN_SQUARE; j++){
      if(x == 0 && y == 0) {
	selected_y
      }
    }
  }
}


int main(){
  int cases;
  scanf("%d", &cases);

  while(cases--){
    for(int i = 0; i < LEN_SQUARE; i++){
      for(int j = 0; j < LEN_SQUARE; j++){
	char in;
	scanf("%c" &in);
	if(in == '.'){
	  board[i][j] = 0;
	} else {
	  board[i][j] = 1;
	}
      }
    }
  }
    
  return 0;
}

