#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tools.h"
#define BUFSIZE 4096

int main() {
	
  u_int8_t inputbuffer[BUFSIZE],outputbuffer[BUFSIZE/2];
  size_t size;

  while(size = fread(inputbuffer, 1, BUFSIZE, stdin)){
	hex2byte(inputbuffer, outputbuffer, size);
	fwrite(outputbuffer, sizeof(u_int8_t), size/2, stdout);
  }

  return 0;
}
