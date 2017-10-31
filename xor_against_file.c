#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tools.h"
#define BUFSIZE 50
#define MAX_KEYSIZE 50


int main(int argc, char* argv[]) {
	
  u_int8_t inputbuffer[BUFSIZE],outputbuffer[BUFSIZE];
  size_t size;
  u_int8_t key[MAX_KEYSIZE] = {0};

  if (strcmp( argv[1], "-d")) {
	  if(argv[1] == 0) {
		fprintf(stderr, "no keyfile nor key\n");

		return 1;
	  }
	  FILE * keyfile = fopen(argv[1],"r");
	  fread(key, 1, MAX_KEYSIZE, keyfile);
  } else {
	  memcpy(key, argv[2], strlen(argv[2])+1);
  }
		
  u_int8_t keysize, realbufsize;
  keysize = strlen(key);
  realbufsize = BUFSIZE - (BUFSIZE % keysize);

  while(size = fread(inputbuffer, 1, realbufsize, stdin)){
		xorstr(inputbuffer,key,outputbuffer);
	fwrite(outputbuffer, sizeof(u_int8_t), size, stdout);
  }

  return 0;
}
