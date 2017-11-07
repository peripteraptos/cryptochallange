package main

import (
	"bufio"
	"fmt"
	"os"
	"log"
	"strings"
	"io/ioutil"
	"flag"
	"./xor"
	"unicode/utf8"
	"encoding/hex"
//	b64 "encoding/base64"
)
const (
	MaxScanTokenSize = 64* 1024
)

func main() {

	keylistFilename := flag.String("keylist", "keylist", "a file")
	flag.Parse()

	//fmt.Printf("%s", *keyfile)
	keylist, err := ioutil.ReadFile(*keylistFilename);
	if err != nil {
		log.Fatal(err)
	}


//	fmt.Printf("%s\n",keylist)
	keys := strings.Split(string(keylist),"\n")	
	fmt.Println(keys)



	stdinLine := bufio.NewScanner(os.Stdin)
	for stdinLine.Scan() {
		hexdecoded, err := hex.DecodeString(stdinLine.Text())
		if err != nil {
			log.Fatal(err)
		}



		for index, _ := range keys {
			xordecrypted := xor.EncryptDecrypt(string(hexdecoded),string(keys[index]))
			if isReadableASCII(xordecrypted) {
//				fmt.Println(xordecrypted)
				fmt.Println(utf8.ValidString(xordecrypted))
			}
		}

//		fmt.Println(decoded) // Println will add back the final '\n'
	}

	if err := stdinLine.Err(); err != nil {
		fmt.Fprintln(os.Stderr, "reading standard input:", err)
	}
}


func isReadableASCII(input string) (output bool){
	for _, currentByte := range []byte(input) {
		if currentByte < ' ' || currentByte > '~' && currentByte != '\n' {
			return false
		}
	}
	return true
}
