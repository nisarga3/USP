#!/bin/sh
echo "Enter string: "
read s
#string length
echo "String length: "${#s}
#index 
echo "Enter the substring: "
read ss
expr index "$s" "$ss"
#substring eample----2a quees
echo "Enter position: "
read pos
echo "Enter length"
read len
echo ${s:$pos:$len} 
#if len is omitted then extratct frm that position to end letter
echo ${s:$pos}
