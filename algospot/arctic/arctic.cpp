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
 * 최소 신장 트리(minimum sparse tree)의 가장 긴 간선을 구하는 문제이다.
 * 우선순위 큐는 이진힙으로 구현한다.
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

#define LEFT_CHILD(n) n*2
#define RIGHT_CHILD(n) n*2+1
#define PARENT(n) n/2

using namespace std;


struct Vertex{
  int id;
  int adj;
  double x;
  double y;
  double key_distance;
};

int heap_size;
int v_size;

void min_heapify(Vertex* heap, int index){
  int smallest;
  int l = LEFT_CHILD(index);
  int r = RIGHT_CHILD(index);

  if(l < heap_size && heap[l].key_distance < heap[index].key_distance){
    smallest = l;
  }
  else smallest = index;

  if(r < heap_size && heap[r].key_distance < heap[index].key_distance){
    smallest = r;
  }

  if(smallest != index){
    Vertex tmp = heap[index];
    heap[index] = heap[smallest];
    heap[smallest] = tmp;
    min_heapify(heap, smallest);
  }
}

void min_heap_build(Vertex* heap){
  heap_size = v_size;
  //heap의 루트에 대해서 상위로 올라가면서 힙으로 만든다.
  for(int i = heap_size/2-1; i > -1; i--){
    min_heapify(heap, i);
  }
}

Vertex min_extract(Vertex* heap){
  Vertex max = heap[0];
  heap[0] = heap[heap_size];
  min_heapify(heap, 0);
  heap_size = heap_size-1;

  return max;
}

void decrease_key(Vertex* heap, double key, int index){
  if(key > heap[index].key_distance){
    return;
  }
  heap[index].key_distance = key;
  while(index > -1 && heap[PARENT(index)].key_distance > heap[index].key_distance){
    Vertex tmp;
    tmp = heap[PARENT(index)];
    heap[PARENT(index)] = heap[index];
    heap[index] = tmp;
    index = PARENT(index);
  }
}


Vertex v_list[50];
//u -> v distance[u][v]
double distances[100][100];

void initialize(){
  //Initialize the vertex set 
  v_list[0].key_distance = 0;
  v_list[0].adj = -1;
  for(int i = 1; i < v_size; i++){
    v_list[i].key_distance = 1001;
    v_list[i].adj = -1;
  }

  min_heap_build(v_list);
  
  
  //Initialize the distance info
  for(int i = 0; i < v_size; i++){
    for(int j = i+1; j < v_size; j++){
      double x_distance = (v_list[j].x - v_list[i].x) * (v_list[j].x - v_list[i].x);
      double y_distance = (v_list[j].y - v_list[i].y) * (v_list[j].y - v_list[i].y);
      distances[i][j] = distances[j][i] = x_distance + y_distance;
    }
  }
}

void print_out(){
  for(int i = 0 ; i < heap_size; i++){
    printf("%f ", v_list[i].key_distance);
  }
  printf("\n");

  for(int i = 0; i < v_size; i++){
    for(int j = 0; j < v_size; j++){
      printf("%f ", distances[i][j]);
    }
    printf("\n");
  }
}

double solve(){
  initialize();

  double max = -1;

  while(heap_size > 0){
    Vertex u = min_extract(v_list);
    Vertex *v;
    
    if(u.id != 0 && max < u.key_distance) max = u.key_distance;

    for(int i = 0; i < heap_size; i++){
      v = &v_list[i];
      if(distances[u.id][v->id] < v->key_distance){
	v->adj = u.id;
	decrease_key(v_list, distances[u.id][v->id], i);
      }
    }
  }

  return sqrt(max);
}



int main(){
  int cases;
  cin >> cases;
  while(cases--){
    cin >> v_size;
    for(int i = 0; i < v_size; i++){
      Vertex v;

      cin >> v.x >> v.y;
      v.id = i;
      v_list[i] = v;
    }
    double solution = solve();

    printf("%.2f\n", solution);
  }
  return 0;
}

