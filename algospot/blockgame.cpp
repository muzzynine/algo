#include <iostream>
#include <cstdio>
#define LEN_SQUARE 5
#define KIND_BLOCK2 2
#define KIND_BLOCK3 4
using namespace std;

int board[LEN_SQUARE][LEN_SQUARE] = {0};

int block2[KIND_BLOCK2][2][2] = {
  {{0, 0}, {1, 0}}, {{0, 0}, {0,1}}
};

int block3[KIND_BLOCK3][3][2] = {
  {{-1, 0}, {0, 0}, {0, 1}},
  {{0, 1}, {0, 0}, {1, 0}},
  {{1, 0}, {0, 0}, {0, -1}},
  {{0, 0}, {1, 0}, {0, -1}}
};



bool test_cover2(int x, int y, int kind){
  for(int i = 0; i < 2; i++){
    int* mask = block2[kind][i];
    if(y+*(mask+1) > 4 || x+*(mask) > 4 || board[y+*(mask+1)][x+*(mask)]) return false;
  }
  return true;
}

bool test_cover3(int x, int y, int kind){
  for(int i = 0; i < 3; i++){
    int* mask = block3[kind][i];
    if(y+*(mask+1) > 4 || x+*(mask) > 4 || board[y+*(mask+1)][x+*(mask)]) return false;
  }
  return true;
}

void cover2(int x, int y, int kind){
  for(int i = 0; i < 2; i++){
    int *mask = block2[kind][i];
    board[y+*(mask+1)][x+*(mask)] = 1;
  }
}

void uncover2(int x, int y, int kind){
  for(int i = 0; i < 2; i++){
    int *mask = block2[kind][i];
    board[y+*(mask+1)][x+*(mask)] = 0;
  }
}


void cover3(int x, int y, int kind){
  for(int i = 0; i < 3; i++){
    int *mask = block3[kind][i];
    board[y+*(mask+1)][x+*(mask)] = 1;
  }
}

void uncover3(int x, int y, int kind){
  for(int i = 0; i < 3; i++){
    int *mask = block3[kind][i];
    board[y+*(mask+1)][x+*(mask)] = 0;
  }
}

void board_print(){
  printf("board print\n");
  for(int i = 0 ; i < LEN_SQUARE; i++){
    for(int j = 0; j < LEN_SQUARE; j++){
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
}

bool solve(bool turn){
  bool covered = false;
  for(int y = 0; y < LEN_SQUARE; y++){
    for(int x = 0; x < LEN_SQUARE; x++){
      if(board[y][x] == 0) {
	for(int i = 0; i < KIND_BLOCK2; i++){
	  if(test_cover2(x, y, i)){
	    covered = true;
	    bool result;
	    cover2(x, y, i);
	    result = solve(!turn);
	    uncover2(x, y, i);
	    if(!result) return false;
	  }
	}
	for(int i = 0; i < KIND_BLOCK3; i++){
	  if(test_cover3(x, y, i)){
	    covered = true;
	    bool result;
	    cover3(x, y, i);
	    result = solve(!turn);
	    uncover3(x, y, i);
	    if(!result) return false;
	  }
	}
      }
    }
  }

  //여기까지 내려왔다는 것은 모두 승리하거나 기저문제에서 더이상 놓을 곳이 없을 경우
  if(!covered){
    if(turn) return false;
  }
  return true;
}

bool slow_boardgame(){
  for(int y = 0; y < LEN_SQUARE; y++){
    for(int x = 0; x < LEN_SQUARE; x++){
      if(board[y][x] == 0){
	for(int i = 0; i < KIND_BLOCK2; i++){
	  if(test_cover2(x, y, i)){
	    bool result;
	    cover2(x, y, i);
	    result = solve(false);
	    uncover2(x, y, i);
	    if(result) return true;
	  }
	}
	for(int i = 0; i < KIND_BLOCK3; i++){
	  if(test_cover3(x, y, i)){
	    bool result;
	    cover3(x, y, i);
	    result = solve(false);
	    uncover3(x, y, i);
	    if(result) return true;
	  }
	}
      }
    }
  }
  return false;
}


int main(){
  int cases;
  scanf("%d", &cases);

  while(cases--){
    for(int i = 0; i < LEN_SQUARE; i++){
      for(int j = 0; j < LEN_SQUARE; j++){
	char in;
	cin >> in;
	if(in == '.'){
	  board[i][j] = 0;
	} else {
	  board[i][j] = 1;
	}
      }
    }
    bool solution = slow_boardgame();
    if(solution) printf("WINNING\n");
    else printf("LOSING\n");
  }
    
  return 0;
}

