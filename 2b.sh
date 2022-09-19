#!/bin/sh
echo "Enter the file name: "
read name
if [ -f $name ]  #-f does if a provided path exists and its a regular file
then 
lines=` wc -l < $name `
echo "Numer of lines= " $lines
else
echo "invalid file" 
fi
