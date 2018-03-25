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
//	"unicode/utf8"
	"encoding/hex"
//	b64 "encoding/base64"
)

func main() {
	keylistAttack := flag.Bool("k", false, "keylist attack - use with -keylist=keylist (format \"key\\n\")");
	keylistFilename := flag.String("keylist", "keylist", "a file")

	flag.Parse()

	var keys string

	if *keylistAttack {
		keylist, err := ioutil.ReadFile(*keylistFilename);

		if err != nil {
			log.Fatal(err)
		}

		keys := strings.Split(string(keylist),"\n")
		fmt.Println(keys)
	}else{
		for i := 0; i < 256; i++{
			keys += string(i)
		}
	}

	stdinLine := bufio.NewScanner(os.Stdin)

	for stdinLine.Scan() {
		hexdecoded, err := hex.DecodeString(stdinLine.Text())
		if err != nil {
			log.Fatal(err)
		}

		for _,key := range keys {
			xordecrypted := xor.EncryptDecrypt(string(hexdecoded),string(key))
			if isReadableASCII(xordecrypted) {
				fmt.Println(xordecrypted)
			}
		}
	}

	if err := stdinLine.Err(); err != nil {
		fmt.Fprintln(os.Stderr, "reading standard input:", err)
	}
}

func isReadableASCII(input string) (output bool){
	for _, currentByte := range []byte(input) {
		if int(currentByte) < ' ' || int(currentByte) > '~' && int(currentByte) != '\n' {
			return false
		}
	}
	return true
}
