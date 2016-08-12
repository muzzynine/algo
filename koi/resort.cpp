#include <iostream>

using namespace std;

int calendar[100] = {0, };
int least;
int entrie, block;
int tickets[] = {10, 25, 37, 0};

void compute(int fee){
  if(fee >= least){
    return;
  }

  int i = 0;
  while(i < entrie && calendar[i] > 0) i++;

  if(i == entrie){
    least = fee;
    return;
  }

  for(int j = 0; j < 4; j++){
    if(j==0){
      calendar[i]++;
      fee += tickets[j];
      compute(fee);
      calendar[i]--;
      fee -= tickets[j];
    } else if(j==1 && (entrie-i)+1 >= 3){
      for(int k = i; k < i+3; k++){
	calendar[k]++;
      }
      fee += tickets[j];
      tickets[3] += 1;
      compute(fee);
      for(int k = i; k < i+3; k++){
	calendar[k]--;
      }
      fee -= tickets[j];
      tickets[3] -= 1;
    } else if(j==2 && (entrie-i)+1 >= 5){
      for(int k = i; k < i+5; k++){
	calendar[k]++;
      }
      fee += tickets[j];
      tickets[3] += 2;
      compute(fee);
      for(int k = i; k < i+5; k++){
	calendar[k]--;
      }
      fee -= tickets[j];
      tickets[3] -= 2;
    } else if(j == 3&& tickets[j]/3 > 0){
      calendar[i]++;
      tickets[3] -= 3;
      compute(fee);
      calendar[i]--;
      tickets[3] += 3;
    }
  }
}

int main(){
  cin >> entrie >> block;

  least = (entrie - block) * 10;

  while(block--){
    int available;
    cin >> available;

    calendar[available-1] = 1;
  }
  compute(0);

  cout << least * 1000 << endl;

  return 0;
}


