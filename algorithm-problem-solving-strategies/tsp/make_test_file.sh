#!/usr/local/bin/bash

num_point=$1

if [ -z $num_point ]
then
	python3 make_points.py > tsp_testcase.txt
else
	python3 make_points.py $num_point > tsp_testcase.txt
fi
