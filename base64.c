#include <stdlib.h>
#include <stdio.h>
#include "base64.h"
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define BUFSIZE 28671
#if BUFSIZE % 3 != 0
  #error BUFSIZE must be divisible by 3
#endif


int main(int argc, char* argv[]) {
	u_int8_t input[BUFSIZE + 2] = {0};
	u_int8_t output[BUFSIZE / 3*4+1] = {0};
	size_t size, outputsize;

	if (argv[2] == 0) {
		while ((size = fread(output, 1, BUFSIZE/3*4, stdin))){
			int i;
			outputsize = 0;
			for(i = 0; i < size; i+= 4){
				outputsize += base64_decode(&output[i], &input[i/4*3]);
			}
			fwrite(input, sizeof(u_int8_t), outputsize, stdout);
		}
  } else {
		while ((size = fread(input, 1, BUFSIZE, stdin))) {
    	    input[size] = input[size + 1] = 0;
			int i;	
			for (i = 0; i < size; i += 3) {
				base64_encode(&input[i], &output[i/3 * 4], MIN(3, size-i));
			}
			printf("%s",output);
		}
  }
  return 0;
}
