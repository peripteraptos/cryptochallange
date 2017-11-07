#include <stdlib.h>
#include <stdio.h>
#include "tools.h"
#define BUFSIZE 4096

int main (int argc, char *argv[]) {
	u_int8_t inputbuffer[BUFSIZE] = {0},outputbuffer[BUFSIZE] = {0},beststring[BUFSIZE] = {0};
	size_t size;
	FILE * keylist;
	
	u_int32_t best = 0xFFFFFFFF;
	u_int8_t bestkey[1], key[1];

	while(size = fread(inputbuffer, 1, BUFSIZE, stdin)){	
		for(u_int8_t  i = 0; i <= 254; i++){
			key[0] = i;
			xorstr(inputbuffer, key, outputbuffer, size, sizeof(1));
			u_int32_t off = not_readable_chars(outputbuffer, size );
			if(best > off){
				//printf("bestoff:%d bestkey:%s beststring:%s inputbuffer:%s\n", off, key, outputbuffer, inputbuffer);
				best = off;
				memcpy(bestkey,key,strlen(key));
				memcpy(beststring,outputbuffer,strlen(outputbuffer));
			}
		}
	}
//	printf("bestkey:%s\n", bestkey);
	printf("%s\n",beststring);

	return 0;
}
