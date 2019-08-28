#!/bin/bash
# This is used just to ease the process of compilation of exercises and checks

all(){

  for (( c=1; c<=$1; c++ ))  
  do
    file_name="exercise$c"
    file_name_c="$file_name.c"
    echo "gcc -o $file_name $file_name_c is being done" 
    gcc -o $file_name $file_name_c
  done
}


if [ "$1" == "--all" ]
then
	all $2
fi



