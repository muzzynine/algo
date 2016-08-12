#include <iostream>

int speed[30000][2];
int position[30000][2];


int main(){
  int num_of_star, last_day;
  cin >> num_of_star >> last_day;

  while(num_of_star--){
    int x, y, dx, dy;
    cin >> x >> y >> dx >> dy;

    position[num_of_star][0] = x;
    position[num_of_star][1] = y;

    speed[num_of_star][0] = dx;
    speed[num_of_star][1] = dy;
  }

  int best_day;
  int best_distance = 10000000;

  for(int i = 0 ; i < last_day+1 ; i++){
    for(int j = 1; j < num_of_star ; j++){
      int star1_x = position[j][0] + i*speed[j][0];
      int star1_y = position[j][1] + i*speed[j][1];

      for(int k = j+1; k < num_of_star+1 ; k++){
	int star2_x = position[k][0] + i*speed[k][0];
	int star2_y = position[k][1] + i*speed[k][1];

	int distance_x = (star2_x - star1_x) > 0 ? (star2_x - star1_x) : (star1_x - star2_x);
	int distance_y = (star2_y - star1_y) > 0 ? (star2_y - star1_y) : (star1_y - star2_y);

	if(distance_x + distance_y < best_distance){
	  best_distance = distance_x + distance_y;
	  best_day = i;
	}
      } 
    }
  }

  cout >> best_day >> endl >> best_distance >> endl;

  return 0;
}
