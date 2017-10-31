#include <string.h>
#define HEXMAP "0123456789abcdef"

//not used
#define CHARS "ABCDEFGHIJKLMNOPQRSTUVWXYZ.;'()"

u_int8_t xorstr(u_int8_t* input, u_int8_t* key, u_int8_t* output) {
	unsigned int i,o;
	size_t keysize = strlen(key), size = strlen(input);
	for(i = 0; i < size; i+=keysize){
		for(o = 0; o < keysize; o++){	
			if(i+o < size-1)
				output[i+o] = input[i+o] ^ key[o];
		}
	}
}

int not_readable_chars(u_int8_t stringc[], size_t size){
	unsigned int c = 0;
	for(int i = 0; i < size; i++){
		if(stringc[i] < ' ' || stringc[i] > '~')
			c++;
	}
	return c;
}

void hex2byte(u_int8_t* inputbuffer, u_int8_t* outputbuffer, size_t size) {
	int i;
	for(i = 0; i < size; i+=2){
		outputbuffer[i/2] = 0;
		u_int8_t s;
		for(s = 0; s < sizeof(HEXMAP)-1; s++){
		//printf("#############\n");
			if(inputbuffer[i] == HEXMAP[s])
				outputbuffer[i/2] = outputbuffer[i/2] | s << 4;
			//	printf("bufferc:%x\n",outputbuffer[i/2]);
			if(inputbuffer[i+1] == HEXMAP[s])
				outputbuffer[i/2] = outputbuffer[i/2] | s &0xf;
				//	printf("bufferc:%x\n",outputbuffer[i/2]);	
			}
	}
}
