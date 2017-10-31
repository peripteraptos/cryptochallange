#include <stdlib.h>
#include <stdio.h>
#include "tools.h"
#define BUFSIZE 4096

int main (int argc, char *argv[]) {
	u_int8_t inputbuffer[BUFSIZE] = {0},beststring[BUFSIZE] = {0};
	size_t size;
	FILE * inputfile;
	inputfile = stdin;

	if(argv[1] != 0)
		inputfile = fopen(argv[1], "r");

	u_int32_t best = 0xFFFFFFFF;

	while(fgets(inputbuffer, BUFSIZE, inputfile)){
		size = strlen(inputbuffer);
		strtok(inputbuffer, "\n");
		u_int32_t off = not_readable_chars(inputbuffer, size);
		if(best > off){
			best = off;
			memcpy(beststring,inputbuffer,size);
		}
	}
	//printf("count:%d\n",best);
	printf("%s\n",beststring);

	return 0;
}
