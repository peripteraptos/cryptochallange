#include <stdlib.h>
#include <stdio.h>
#include "tools.h"
#include "base64.h"
#define BUFSIZE 4096

int main (int argc, char *argv[]) {
	u_int8_t inputbuffer[BUFSIZE] = {0}, outputbuffer[BUFSIZE/4*3] = {0}, beststring[BUFSIZE] = {0};
	size_t size;
	FILE * inputfile;
	inputfile = stdin;

	if(argv[1] != 0)
		inputfile = fopen(argv[1], "r");

	u_int32_t best = 0xFFFFFFFF;

	while(fgets(inputbuffer, BUFSIZE, inputfile)){
		size = strlen(inputbuffer);
		strtok(inputbuffer, "\n");
	
			
		printf("size:%d\n",size);
		base64_decode_direct(inputbuffer,outputbuffer,sizeof(outputbuffer));
		u_int32_t off = not_readable_chars(outputbuffer,size);
		if(best > off){
			best = off;
		//	memset(beststring, 0, sizeof(beststring));
			memcpy(beststring,outputbuffer,size/4*3);
		}
	}
	fwrite(beststring,sizeof(u_int8_t),sizeof(beststring),stdout);

	return 0;
}
