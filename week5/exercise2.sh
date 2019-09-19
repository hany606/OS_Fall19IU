#!/bin/sh

# Command to run one in foregorund and another one in the backgroun:
#  ./exercise2.sh  & ./exercise2.sh
# The race condition happens when they run exactly and access the same source togther but it may not happen on the laptop because it is fast enough to run two of them
# ciritcal region is the file region and the data exists in it.

# Two working solutions

# First
file_name=exercise2_file.txt
# awk -v last="$last" 'END { printf "%s\n",$0=$0+1 }' $file_name >> $file_name

# The solution:
lockfile=$file_name.lock
# lockfile $lockfile
if ln $file_name $lockfile; then
    awk -v last="$last" 'END { printf "%s\n",$0=$0+1 }' $file_name >> $file_name
    rm -f $lockfile
else
    exit 1
fi
# Second
# file_name="./exercise2_file.txt"
# if [ -f "$file_name" ]
# then
#     OUT=$(tail -c -2 $file_name)
#     # echo $($OUT+$1)
#     var=$((OUT+1))
#     echo $var >> $file_name
#     # while read line; do
#     # echo "Line No. $n : $line"
#     # n=$((n+1))
#     # done < $file_name
# else
#     touch $file_name
#     echo 1 > $file_name
#     exit 0
# fi
