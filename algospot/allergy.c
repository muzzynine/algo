#include <stdio.h>
#include <string.h>

char tbl[51][51];
char flist[51];

int main(){
  int cases, pc, fc, fpc;
  char fp[11];
  char pn[11];
  scanf("%d", &cases);
  while(cases--){
    scanf("%d %d", &pc, &fc);
    char fnl[50][20];
    for(int i = 0; i < pc ; i++){
      scanf("%s", fnl[i]);
    }
    for(int i = 0; i < fc ; i++){
      scanf("%d", &fpc);
      while(fpc--){
	scanf("%s", fp);
	for(int j = 0; j < pc; j++){
	  if(!strcmp(fp, fnl[j])){
	    tbl[i][i] |= 1<<j;
	    break;
	  }
	}
      }
    }
  }
  return 0;
}

void compute(    


