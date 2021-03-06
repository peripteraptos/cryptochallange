package xor

// EncryptDecrypt runs a XOR encryption on the input string, encrypting it if it hasn't already been,
// and decrypting it if it has, using the key provided.
func EncryptDecrypt(input, key string) (output string) {

		if len(key) < 1 {
			return input
		}

        for i := 0; i < len(input); i++ {
                output += string(input[i] ^ key[i % len(key)])
        }

        return output
}
/*
func BreakXor(input []byte, keylen int) (output string) {
	var key [keylen]byte

	for a := 0; a < keylen; a++ {
		for b := 0; b < 255; b++ {
			for c := 0; c < len(input); c++ {
				result = string(input[i] ^ key[i % len(key)])
			}
			key[a]++;
		}
	}
}

func generateKeys(keylen int) (output [][]byte){
	for a := 0; a < keylen; a++{
}
}

*/
