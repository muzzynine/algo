#include <iostream>
#include <string>
#include <vector>

using namespace std;

int least;
int fc, pc;
//int *fl, *el;
vector<int> *fl, *el;

void allergy_fast(int dep, vector<int> sol){
  if(dep >= least) return;

  //안먹은 사람들을 대상으로 먹을 수 있는 모든 음식을 먹일것임
  int i = 0;
  while(i < pc && sol[i] > 0) ++i;

  if(i == pc){
    least = dep;
    return;
  }
  
  //el[i]는 i가 먹을 수 있는 음식 리스트
  for(int j = 0; j < el[i].size(); j++){
    //i가 먹을 수 있는 음식 리스트중 j번째 음식
    int food = el[i][j]; 
    for(int k = 0; k < fl[food].size(); k++) sol[fl[food][k]]++;
    allergy_fast(dep+1, sol);
    for(int k = 0; k < fl[food].size(); k++) sol[fl[food][k]]--;
  }
}


int main(){
  int cases;
  cin >> cases;
  while(cases--){
    string fnl[51];
    vector<int> flist[50];
    vector<int> elist[50];

    cin >> pc >> fc;
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
	    flist[i].push_back(j); //i번째 음식은 flist[i]의 사람이 먹을 수 있음
	    elist[j].push_back(i); //j번째 사람은 eatable[j]의 음식을 먹을 수 있음
	    break;
	  }
	}
      }
    }
    vector<int> sol(pc, 0);
    fl = flist;
    el = elist;
    allergy_fast(0, sol);
    cout << least << endl;
  }
  return 0;
}

/*  
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
*/
