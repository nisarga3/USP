#!/bin/sh
echo "Enter the filename\n"
read n
if [ -d $n ]
then
	echo "Directory File"
elif [ -f $n ]
then
	echo "Regular File"
elif [ -c $n ]
then 
	echo "Character Device File"
elif [ -s $n ]
then
	echo "Local Socket File"
elif [ -b $n ]
then
	echo "Block Device File"
elif [ -L $n ]
then 
	echo "Symbolic Link File"
else
	echo "Invalid File"
fi
