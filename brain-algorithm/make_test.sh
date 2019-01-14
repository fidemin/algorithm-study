#!/usr/local/bin/bash

directory=$1
filename=$2

if [ -z "$directory" ]; then
	echo "directory should be given" 1>&2
	echo "[Usage] ./make_test.sh {directory} {filename}" 1>&2
	exit 1
fi

if [ -z "$filename" ]; then
	echo "filename should be given" 1>&2
	echo "[Usage] ./make_test.sh {directory} {filename}" 1>&2
	exit 1
fi

if [ ! -f $directory/TestRunner.h ]; then
	cp ./test_template/TestRunner.h $directory/
else
	echo "[WARNING]	$directory/TestRunner.h already exists"
fi

if [ ! -f $directory/$filename ]; then
	cp ./test_template/Test.c $directory/$filename
else
	echo "[WARNING] $directory/$filename already exists"
fi

echo "Completed test file creation"
