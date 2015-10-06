#!/bin/bash 
MIN_CPU_CYCLES=1000000000000
loc=0
SIMULATION_FOLDER=./Problem2_RAYTRACE
for FILE in $SIMULATION_FOLDER/L1*.txt ; do
  CPU_CYCLES=$(cat $FILE | grep system.cpu.numCycles | sed 's/[^0-9]//g') #get the exec time
# echo "" 
# echo $loc
# echo $FILE
# echo "CPU_CYCLES $CPU_CYCLES"
# echo "MIN $MIN_CPU_CYCLES"
# dif=$(($CPU_CYCLES - $MIN_CPU_CYCLES))
# echo $dif
  FILE_LIST[$loc]="$FILE"
  CYCLE_LIST[$loc]="$CPU_CYCLES"
  loc=$(($loc + 1))
  if [ $(($CPU_CYCLES - $MIN_CPU_CYCLES)) -lt 0 ]; then
    MIN_CPU_CYCLES=$CPU_CYCLES
    MIN_FILE=$FILE
  fi
done
echo "$MIN_FILE is the fastest at $MIN_CPU_CYCLES cycles" > $SIMULATION_FOLDER/results.txt

loc=0
for num_cycles in ${CYCLE_LIST[@]}; do
  dif=$((${CYCLE_LIST[$loc]} - $MIN_CPU_CYCLES))
  echo "${FILE_LIST[loc]} is $dif cycles slower than fastest" >> $SIMULATION_FOLDER/results.txt
  loc=$(($loc + 1))
  
done
#echo ${FILE_LIST[@]}
