#include <stdlib.h>
#include <stdio.h>
#include "tools.h"
#define BUFSIZE 1337

int main(){
	u_int8_t inputbuffer[BUFSIZE];
	int32_t c = 0;
	size_t size;
	while(size = fread(inputbuffer, 1, BUFSIZE, stdin)){
		c += not_readable_chars(inputbuffer,size);
	}
	printf("%d",c);
}
