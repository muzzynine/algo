/* ARCTIC 
 * 남극에는 N개의 탐사기지가 있다.
 * 남극의 겨울은 혹독하기 때문에, 남극의 겨울이 찾아오면 각 탐사기지간의 왕래가 중단된다.
 * 겨울에도 연구를 지속하기 위해 N개의 무전기를 구입해 각 탐사기지에 배치하려 한다.
 * 이 때, 두 탐사기지 사이의 거리가 D이고, 무전기의 출력이 D 이상이어야만 통신이 가능하다.
 * 모든 탐사기지에는 똑같은 무전기가 지급된다.
 * 탐사 본부가 다른 모든 기지에 연락을 할 수 있기 위해 필요한 최소 출력은 얼마일까?
 * 탐사 본부는 다른 기지를 통해 간접적으로 연락할 수 있다.
 */

/* 
 * 각 탐사기지가 모두 이어지되 최소의 거리를 구하는 문제이다. 
 * 즉 최소 신장 트리(minimum sparse tree)의 가장 긴 간선을 구하는 문제이다.
*/

#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

typedef struct vertex{
  double x;
  double y;
  int id;
  int adj;
  double key_distance;
}Vertex;

vector<Vertex> v_list;
//u -> v distance[u][v]
double distances[100][100];

void initialize(){
  //Initialize the distance info
  for(int i = 0; i < v_list.size(); i++){
    for(int j = i+1; j < v_list.size(); j++){
      double x_distance = (v_list[j].x - v_list[i].x) * (v_list[j].x - v_list[i].x);
      double y_distance = (v_list[j].y - v_list[i].y) * (v_list[j].y - v_list[i].y);
      distances[i][j] = distances[j][i] = x_distance + y_distance;
    }
  }

  //Initialize the vertex set 
  v_list[0].key_distance = 0;
  v_list[0].adj = -1;
  for(int i = 1; i < v_list.size(); i++){
    v_list[i].key_distance = 1001;
    v_list[i].adj = -1;
  }
}

double solve(){
  initialize();

  double max = -1;

  while(v_list.size() > 0){
    Vertex u;
    Vertex *v;
    int cut_i;
    u.key_distance = 1001;

    //v_list에서 가장 낮은 key_distance 값을 갖는 정점을 선택하고 v_list에서 제거
    for(int i = 0; i < v_list.size(); i++){
      if(u.key_distance > v_list[i].key_distance) {
	u = v_list[i];
	cut_i = i;
      }
    }
    v_list.erase(v_list.begin() + cut_i);

    if(u.id != 0 && max < u.key_distance) max = u.key_distance;

    for(int i = 0; i < v_list.size(); i++){
      v = &v_list[i];
      if(distances[u.id][v->id] < v->key_distance){
	v->adj = u.id;
	v->key_distance = distances[u.id][v->id];
      }
    }
  }

  return sqrt(max);
}


int main(){
  int cases;
  scanf("%d", &cases);
  while(cases--){
    int v_size;
    scanf("%d", &v_size);
    for(int i = 0; i < v_size; i++){
      Vertex v;
      scanf("%lf", &v.x);
      scanf("%lf", &v.y);
      v.id = i;
      v_list.push_back(v);
    }
    double solution = solve();

    printf("%.2f", solution);
  }
  return 0;
}

