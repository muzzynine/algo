#include <iostream>
#include <string>

using namespace std;

int solution;
int least;
int fc, pc;
int *fl, *el;

void allergy_fast(int dep, int sol){
  if(dep >= least) return;

  if(sol == solution){
    least = dep;
    return;
  }

  //안먹은 사람들을 대상으로 먹을 수 있는 모든 음식을 먹일것임
  int i = 0;
  while(i < pc && (sol>>i)%2 == 1) ++i;

  int edible_for_i = el[i]; //i번째 사람이 먹을 수 있는 음식

  for(int j = 0; j < fc; j++){
    if((edible_for_i>>j)%2 == 1){
      int tmp = sol;
      sol |= fl[j];
      allergy_fast(dep+1, sol);
      sol = tmp;
    }
  }
}

int main(){
  int cases;
  cin >> cases;
  while(cases--){
    int flist[51] = {0, };
    int eatable[51] = {0, };
    string fnl[51];

    cin >> pc >> fc;
    solution = (1<<pc)-1;
    least = fc;

    for(int i = 0; i < pc ; i++){
      cin >> fnl[i];
    }

    // i : 음식, j : 사람
    for(int i = 0; i < fc ; i++){
      int fpc;
      cin >> fpc;
      while(fpc--){
	string fp;
	cin >> fp;
	for(int j = 0; j < pc; j++){
	  //fp의 사람이 fnl[j]에 저장된 사람과 같다면
	  if(!fp.compare(fnl[j])){
	    flist[i] |= 1<<j; //i번째 음식은 flist[i]의 사람이 먹을 수 있음
	    eatable[j] |= 1<<i; //j번째 사람은 eatable[j]의 음식을 먹을 수 있음
	    break;
	  }
	}
      }
    }
    fl = flist;
    el = eatable;
    allergy_fast(0, 0);
    cout << least << endl;
  }
  return 0;
}

  
void allergy_slow(int *a, int start, int dep, int sol){
  if(dep >= least){
    return;
  }
  for(int i = start; i < fc ; i++){
    sol |= a[i];
    if((sol & ~solution) == 0){
      least = dep;
      sol &= ~a[i];
      return;
    }
    allergy_slow(a, i+1, dep+1, sol);
    sol &= ~a[i];
  }
}
