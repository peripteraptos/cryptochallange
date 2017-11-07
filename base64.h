#define BASE64SET "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

static const u_int8_t decodetable[] = {62,-1,-1,-1,63,52,53,54,55,56,57,58,59,60,61,-1,-1,-1,-2,-1,-1,-1,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,-1,-1,-1,-1,-1,-1,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51};
static const u_int8_t offset = '+';


void base64_encode(u_int8_t *input, u_int8_t *output, size_t size) {
	output[0] = BASE64SET[input[0] >> 2];
	output[1] = BASE64SET[(input[0] & 0x3) << 4 | input[1] >> 4];
	output[2] = BASE64SET[(input[1] & 0xf) << 2 | input[2] >> 6];
	output[3] = BASE64SET[input[2] & 0x3f];

	if (size < 3) {
		if (size == 1)
			output[2] = '=';
		output[3] = '=';	
		output[4] = '\0';	
	}
}

size_t base64_decode(u_int8_t *input, u_int8_t *output) {
	u_int8_t temp[4];

	temp[0] = decodetable[input[0]-offset];
	temp[1] = decodetable[input[1]-offset];
	temp[2] = decodetable[input[2]-offset];
	temp[3] = decodetable[input[3]-offset];

	output[0] = temp[0] << 2 | temp[1] >> 4;
	output[1] = temp[1] << 4 | temp[2] >> 2;
	output[2] = temp[2] << 6 | temp[3];
	if(input[3] == '='){
		if(input[2] == '=')
			return 1;
		return 2;
	}
	return 3;
}

u_int8_t * base64_decode_direct(u_int8_t * input, u_int8_t * output, size_t size){
	//static u_int8_t output[sizeof(input)/4*3];
	//size_t size;
	for(int i = 0; i < strlen(input);i+=4){
		size = base64_decode(&input[i], &output[i/4*3]);
	}
	//int endsize = sizeof(output)-3+size;
//	memcpy(output,output,endsize);
	return output;
}


