#include <cstdio>

using namespace std;

int a[] = {2, 3, 4, 5, 6, 7, 8, 9};
int b[] = {0, 1, 2, 3, 4, 5};
int c[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int d[] = {0, 1, 2, 3, 4, 5};
int e[] = {1, 2, 10, 11, 12};
int f[] = {11, 22};

int re[] = {10, 20, 1, 11, 21};
  
void solve(int n){
  int v = n-1;
  int *pa = a;
  int *pb = b;
  int *pc = c;
  int *pd = d;
  int *pe = e;
  int *pf = f;
  int *pre = re;
  pf += v%2;
  v = v/2;
  pe += v%5;
  pre += v%5;
  v = v/5;
  pd += v%6; 
  v = v/6;
  pc += v%10;
  v = v/10;
  pb += v%6;
  v = v/6;
  pa += v%8;

  printf("%d%d%d%d-%02d-%02d %02d:%d%d:%d%d\n", *pa, *pb, *pc, *pd, *pe, *pf, *pre, *pd, *pc, *pb, *pa);
  
}

int main(){
  int cases;
  scanf("%d", &cases);
  while(cases--){
    int input;
    scanf("%d", &input);
    solve(input);
  }
  return 0;
}

