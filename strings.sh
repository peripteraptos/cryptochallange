#!/bin/bash
while IFS='' read -r line || [[ -n "$line" ]]; do
#    echo "Text read from file: $line"
#	printf "line:$line " &&
 printf "$line" | ./hex2byte | ./keylistattack keylist #| base64 # && printf "\n" 
	#printf "line:$line " && printf "$line" | ./hex2byte | ./single_byte_attack keylist #| base64 # && printf "\n" 
#| ./keylistattack keylist #| ./base64 && printf "\n" 
done < "$1"
