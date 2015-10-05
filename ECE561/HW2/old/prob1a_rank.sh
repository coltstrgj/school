#!/bin/bash 
HW_DIR=/home/cjohnson/School/ECE561/HW2 
MIN_CPU_CYCLES=10000000
loc=0
for FILE in $HW_DIR/problem1/L1*; do
  CPU_CYCLES=$(cat $FILE | grep system.cpu.numCycles | sed 's/[^0-9]//g') #get the exec time
  #echo $(($CPU_CYCLES - $MIN_CPU_CYCLES))
  FILE_LIST[$loc]="$FILE"
  CYCLE_LIST[$loc]="$CPU_CYCLES"
  loc=$(($loc + 1))
  if [ "$(($CPU_CYCLES - $MIN_CPU_CYCLES))" -lt 0 ]; then
    MIN_CPU_CYCLES=$CPU_CYCLES
    MIN_FILE=$FILE
  fi
done
echo "$MIN_FILE is the fastest at $MIN_CPU_CYCLES cycles" > $HW_DIR/results.txt

loc=0
for num_cycles in ${CYCLE_LIST[@]}; do
  dif=$((${CYCLE_LIST[$loc]} - $MIN_CPU_CYCLES))
  echo "${FILE_LIST[loc]} is $dif cycles slower than fastest" >> $HW_DIR/results.txt
  loc=$(($loc + 1))
  
done
#echo ${FILE_LIST[@]}
