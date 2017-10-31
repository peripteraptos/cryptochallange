#!/bin/bash

set -e -o pipefail

prog="${1:-base64 -w0}"

echo "testing $prog against base64"

tmpi=$(mktemp XXXX.input)
tmpo1=$(mktemp XXXX.base64)
tmpo2=$(mktemp XXXX.testprog)
fail() {
  echo "FAILED!"
  cleanup
  exit 1
}
testcase() {
  cat > $tmpi
  echo "testing $1"
  cat $tmpi | base64 -w0 | hexdump -C > $tmpo1
  cat $tmpi | $prog | hexdump -C > $tmpo2
  if ! diff -u $tmpo1 $tmpo2; then
    fail
  else
    echo "ok."
  fi
}
cleanup() {
  rm $tmpi
  rm $tmpo1
  rm $tmpo2
}

printf "" | testcase "empty"
printf "hello" | testcase "prinfhello"
echo "hello" | testcase "echohello"
printf "hellohellohello" | testcase "hellohellohello"
dd if=/dev/urandom bs=100 count=1 status=none | testcase "random bs=100 count=1"
dd if=/dev/urandom bs=4096 count=50 status=none | testcase "ramdom bs=4096 count=1000"

cleanup
echo "SUCCESS!"

