#!/bin/sh
echo -n "Ente the folder name"
read folname
if [ -d $folname ]
then
ls -lR $folname
echo "Enter the permission of the file in rwxrwxrwx format"
read fileperm
ls -lR >> sample.txt
#echo $fileperm
grep -h $fileperm sample.txt
else
echo "Foler not found"
fis
