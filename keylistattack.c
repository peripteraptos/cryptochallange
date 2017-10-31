#include <stdlib.h>
#include <stdio.h>
#include "tools.h"
#define BUFSIZE 4096
#define MAX_KEYLENGTH 4096

int main (int argc, char *argv[]) {
	u_int8_t inputbuffer[BUFSIZE] = {0},outputbuffer[BUFSIZE] = {0},beststring[BUFSIZE] = {0};
	u_int8_t key[MAX_KEYLENGTH] = {0};
	size_t size;
	FILE * keylist;
	if(argv[1] == 0)
		return 1;

	keylist = fopen(argv[1], "r");
	

	u_int32_t best = 0xFFFFFFFF;
	u_int8_t bestkey[MAX_KEYLENGTH];

	while(size = fread(inputbuffer, 1, BUFSIZE, stdin)){	
		while(fgets(key, MAX_KEYLENGTH, keylist)){
			strtok(key, "\n");
			xorstr(inputbuffer, key, outputbuffer);
			u_int32_t off = not_readable_chars(outputbuffer, size );
			if(best > off){
				//printf("bestoff:%d bestkey:%s beststring:%s inputbuffer:%s\n", off, key, outputbuffer, inputbuffer);
				best = off;
				memcpy(bestkey,key,strlen(key));
				memcpy(beststring,outputbuffer,strlen(outputbuffer));
			}
		}
	}
	printf("bestkey:%s\n", bestkey);
	printf("%s",beststring);

	return 0;
}
