#!/bin/sh
s="to be or not to be"
#replace first occurence
echo ${s[@]/be/eat}
#replace all occurences
echo ${s[@]//be/eat}
#delete all ocurrence--replace with empty string
echo ${s[@]//not/}
# replace ocuurence of substring if at begining
echo ${s[@]/#to be/eat now}
## replace ocuurence of substring if at end
echo ${s[@]/%to be/eat now}
#replace all substrings
echo ${s[@]//to be/eat now}
#replace ocuurence of string with shell cmd output
echo ${s[@]/%be/be on $(date +'%Y-%m-%d')}
