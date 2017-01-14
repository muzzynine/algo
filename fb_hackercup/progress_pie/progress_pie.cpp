#include <cstdio>
#include <cmath>

#define PI 3.14159265

bool progress_pie(int percent, int x, int y){
  y = y-50;
  x = x-50;

  double degrees = std::fmod(std::atan2(x, y) * 180 / PI, 360);
  while(degrees < 0) degrees += 360;

  if(degrees != 0 && degrees <= double(percent)/100 * 360){
    double distance = std::sqrt(std::pow(x,2) + std::pow(y,2));
    if (distance <= 50){
      return true;
    }
  }
  return false;
}

int main(){
  int cases;
  scanf("%d", &cases);
  for(int i = 1; i <= cases; i++){
    int percent, x, y;
    scanf("%d %d %d", &percent, &x, &y);

    if(progress_pie(percent, x, y)){
      printf("Case #%d: black\n", i);
    } else {
      printf("Case #%d: white\n", i);
    }
  }
}
