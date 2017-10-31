#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int rate (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}



int main(int argc, char *argv[]) {
	
  u_int8_t inputbuffer[MAX_LINESIZE];
 // size_t size;
 // FILE * file = fopen(argv[1],"r");

  u_int8_t chars[] = "abcdefghijklmnopqrstuvwxyz.";
  u_int8_t stat[255];
 

  while(fgets(inputbuffer, MAX_LINESIZE, stdin)){
	memset(stat, 0, sizeof(stat));
	int linesize = strlen(inputbuffer);
	for(int i = 0; i < linesize; i++){
		stat[inputbuffer[i]]++;
	}
	for(int i = 65; i < 123; i++){
		printf("#%c:%d ",i,stat[i]);
	}q
	printf("\n");
  }
  return 0;
}
