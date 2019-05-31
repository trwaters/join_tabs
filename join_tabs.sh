#!/bin/bash

# USAGE INSTRUCTIONS -
# First compile join_tab++.cpp to generate the executable
# join_tab++ by doing
# >> g++ join_tab++.cpp mergetabs.cpp -o join_tab++

# This bash script calls join_tab++ to merge all dumps
# INPUT:
# put join_tabs.sh and join_tab++ in same folder as the dir
# containing a folder with Athena++ tab dumps and then do
# >> ./join_tabs.sh 0 500 dir_name problem_id
# where problem_id is the variable from the input file
# OUTPUT:
# the merged tab dumps will appear in dir_name/merged

# Example
# Included is sample dir containing output run on 4 procs with 10 dumps 
# named "TI.block0.out1.00000.tab"..."TI.block3.out1.00000.tab",
# put join_tab++ in the folder containing this dir (call it TI1d)
# To merge all dumps in TI1d, do 
# >> ./join_tabs.sh 0 9 TI1d TI
# To merge just the 1st dump in TI1d, do 
# >> ./join_tabs.sh 0 0 TI1d TI
# The dir TI1d/merged contains the merged output files

Ni=$1 #starting time dump to merge
Nf=$2 #final time dump to merge
folder=$3 #run dir
tag=$4 #problem_id

mkdir $folder/merged

# function that calls join_tab++ for all the id files for one time dump
# note - order matters so the ?, ??, ???, ???? orders the id folders
# sequentially from 0-9, 10-99, 100-999, and 1000-9999
merge_files() {
  local num=$1
  number=$(echo $num)
  printf -v filename "%05i" $number
  ./join_tab++ "$tag.$filename.tab" \
  ./$folder/*block?.*".$filename.tab" \
  ./$folder/*block??.*".$filename.tab" \
  ./$folder/*block???.*".$filename.tab" \
  ./$folder/*block????.*".$filename.tab"
  echo $filename
  mv $tag.$filename.tab $folder/merged
}

echo "Ni=$Ni, Nf=$Nf"
#loop over all time dumps in the specified range
for((num=$Ni;num<=$Nf;num++)) do 
  merge_files "$num" &
done
