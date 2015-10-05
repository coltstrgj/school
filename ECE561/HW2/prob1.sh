#!/bin/bash 
: 'In this problem you will explore the cache hierarchy in the ALPHA processor using gem5. Consider
a baseline 2 GHz ALPHA processor subsystem running the RADIX benchmark, with an L1 data cache size of 4 kB
and associativity of 2, L1 instruction cache size of 4 kB and associativity of 2, and a unified L2 cache size of 128 kB
with associativity of 4. The following command would simulate such a system for 5 million instructions (refer to
Options.py to see other possible options you can use during gem5 simulation; many parameters take default values if
not specified during simulation – e.g., clock frequency by default is 1 GHz): 
'
: ' clock speed = 2GHz

    L1_D size: 4kB
    L1_I size: 4kB
    
    L1_D assosc: 2
    L1_I assosc: 2

    L2 size: 128 kB
    L2 assosc: 4
'

: '
(a) Suppose you are allowed to increase the total L1 cache size (instruction+data cache size) to a maximum of 64kB
and L2 cache size to a maximum of 4MB. You are also allowed to increase maximum L1 associativity to 4 and
maximum L2 associativity to 8. Find the cache configuration that gives the best performance results (i.e., smallest
execution time represented by system.cpu.numCycles in the stats.txt file) with the minimum overall cache size and
associativity. Mention the cache size and associativity values (for L1 data, L1 instruction, and L2) of your best
configuration and improvement in execution time over the baseline case configuration shown in the example for this
question.
'

#   clock speed = 2GHz

#   L1_D size: 4kB
#   L1_I size: 4kB
#   max: 64 kB between instruction and Data
# both same size for first run through, find fastest, then change them from there
L1_D_SIZE=(32 16 8 4)
#L1_D_SIZE=(4)
L1_I_SIZE=(32 16 8 4)

#   L1_D assosc: 2
#   L1_I assosc: 2
#   max assosciativity 4
# leave these alone for first run
L1_D_ASSOSC=(2 4)
L1_I_ASSOSC=(2 4)

#   L2 size: 128 kB
#   max size 4 MB
# try these values first. test between two max
L2_SIZE=(4096 2048 1024 512 256 128)

#   L2 assosc: 4
#   max assosc: 8
# leave this alone for first run
L2_ASSOSC=(8 4)

#Problem 1 code, Only modifying L1_D_SIZE. Take best run from here and further modifying  
cd ~/School/ECE561/gem5/
HWDIR="/home/cjohnson/School/ECE561/HW2/problem1/"
L1_D_SIZE_MIN=4
L1_D_ASSOSC_MIN=2
L1_I_SIZE_MIN=4
L1_I_ASSOSC_MIN=2
L2Size=128
L2Assosc=4
MIN_SIM_SECONDS=10000000000
for L1DSize in ${L1_D_SIZE[@]}; do
  for L1DAssosc in ${L1_D_ASSOSC[@]}; do
    SIM="build/ALPHA/gem5.opt configs/example/se.py -I 5000000 --cpu-type="detailed" --sys-clock=2GHz --cpu-clock=2GHz --caches --l2cache --l1d_size="$L1DSize"kB --l1i_size=4kB --l2_size=128kB --l1d_assoc="$L1DAssosc" --l1i_assoc=2 --l2_assoc=4 --cmd=splash2/codes/kernels/radix/RADIX"
    FILE_NAME=$HWDIR"L1_D."$L1DSize"kB."$L1DAssosc"--L1_I."$L1_I_SIZE_MIN"kB."$L1_I_ASSOSC_MIN"--L2."$L2Size"kB."$L2Assosc
    echo "Working on $FILE_NAME"
    touch $FILE_NAME".txt"
    $SIM
    cat m5out/config.ini > $FILE_NAME".ini"
    cat m5out/stats.txt > $FILE_NAME".txt"
    SIM_SECONDS=$(cat m5out/stats.txt | grep system.cpu.numCycles | sed 's/[^0-9]//g') #get the exec time
    #SIM_SECONDS=$(cat m5out/stats.txt | grep sim_seconds | sed 's/[^0-9^.]//g') #get the exec time
    echo "$SIM_SECONDS cycles"
    if [ "$(($SIM_SECONDS - $MIN_SIM_SECONDS))" -lt 0 ]; then
      echo "Prev min: $MIN_SIM_SECONDS cycles"
      echo "------------------------------------------------------"
      echo NEW minimum
      echo "------------------------------------------------------"
      #echo "$FILE_NAME" >> /home/cjohnson/School/ECE561/HW2/shortest.txt
      L1_D_SIZE_MIN=$L1DSize
      L1_D_ASSOSC_MIN=$L1DAssosc
      MIN_SIM_SECONDS=$SIM_SECONDS
    fi

  done
done
#echo "L1D $L1_D_SIZE_MIN $L1_D_ASSOSC_MIN" >> $HWDIR"min_so_far.txt"

#Above found best for Data cache
#this will find best for instruction
for L1ISize in ${L1_I_SIZE[@]}; do
  for L1IAssosc in ${L1_I_ASSOSC[@]}; do
    SIM="build/ALPHA/gem5.opt configs/example/se.py -I 5000000 --cpu-type="detailed" --sys-clock=2GHz --cpu-clock=2GHz --caches --l2cache --l1d_size="$L1_D_SIZE_MIN"kB --l1i_size="$L1ISize"kB --l2_size=128kB --l1d_assoc="$L1_D_ASSOSC_MIN" --l1i_assoc="$L1IAssosc" --l2_assoc=4 --cmd=splash2/codes/kernels/radix/RADIX"
    FILE_NAME=$HWDIR"L1_D."$L1_D_SIZE_MIN"kB."$L1_D_ASSOSC_MIN"--L1_I."$L1ISize"kB."$L1IAssosc"--L2."$L2Size"kB."$L2Assosc
    echo "Working on $FILE_NAME"
    touch $FILE_NAME".txt"
    $SIM
    cat m5out/config.ini > $FILE_NAME".ini"
    cat m5out/stats.txt > $FILE_NAME".txt"
    SIM_SECONDS=$(cat m5out/stats.txt | grep system.cpu.numCycles | sed 's/[^0-9]//g') #get the exec time
    #SIM_SECONDS=$(cat m5out/stats.txt | grep sim_seconds | sed 's/[^0-9^.]//g') #get the exec time
    #if [ $(bc <<< "$SIM_SECONDS < $MIN_SIM_SECONDS") -gt 0 ]; then
    echo "$SIM_SECONDS cycles"
    if [ "$(($SIM_SECONDS - $MIN_SIM_SECONDS))" -lt 0 ]; then
      echo "Prev min: $MIN_SIM_SECONDS cycles"
      echo "------------------------------------------------------"
      echo NEW minimum
      echo "------------------------------------------------------"
      #echo "$FILE_NAME" >> /home/cjohnson/School/ECE561/HW2/shortest.txt
      L1_I_SIZE_MIN=$L1ISize
      L1_I_ASSOSC_MIN=$L1IAssosc
      MIN_SIM_SECONDS=$SIM_SECONDS
    fi

  done
done
#echo "L1I $L1_I_SIZE_MIN $L1_I_ASSOSC_MIN" >> $HWDIR"min_so_far.txt"

#Above found best for Data cache and instruction caches
#this will find best for L2 caches
L2_SIZE_MIN=128
L2_ASSOSC_MIN=4
MIN_SIM_SECONDS=10000000000
for L2Size in ${L2_SIZE[@]}; do
  for L2Assosc in ${L2_ASSOSC[@]}; do
    SIM="build/ALPHA/gem5.opt configs/example/se.py -I 5000000 --cpu-type="detailed" --sys-clock=2GHz --cpu-clock=2GHz --caches --l2cache --l1d_size="$L1_D_SIZE_MIN"kB --l1i_size="$L1_I_SIZE_MIN"kB --l2_size="$L2Size"kB --l1d_assoc="$L1_D_ASSOSC_MIN" --l1i_assoc="$L1_I_ASSOSC_MIN" --l2_assoc="$L2Assosc" --cmd=splash2/codes/kernels/radix/RADIX"
    FILE_NAME=$HWDIR"L1_D."$L1_D_SIZE_MIN"kB."$L1_D_ASSOSC_MIN"--L1_I."$L1_I_SIZE_MIN"kB."$L1_I_ASSOSC_MIN"--L2."$L2Size"kB."$L2Assosc
    echo "Working on $FILE_NAME"
    touch $FILE_NAME".txt"
    $SIM
    cat m5out/config.ini > $FILE_NAME".ini"
    cat m5out/stats.txt > $FILE_NAME".txt"
    SIM_SECONDS=$(cat m5out/stats.txt | grep system.cpu.numCycles | sed 's/[^0-9]//g') #get the exec time
    #SIM_SECONDS=$(cat m5out/stats.txt | grep sim_seconds | sed 's/[^0-9^.]//g') #get the exec time
    echo "$SIM_SECONDS cycles"
    if [ "$(($SIM_SECONDS - $MIN_SIM_SECONDS))" -lt 0 ]; then
      echo "Prev min: $MIN_SIM_SECONDS cycles"
      echo "------------------------------------------------------"
      echo NEW minimum
      echo "------------------------------------------------------"
      #echo "$FILE_NAME" >> $HWDIR"shortest.txt"
      L2_SIZE_MIN=$L2Size
      L2_ASSOSC_MIN=$L2Assosc
      MIN_SIM_SECONDS=$SIM_SECONDS
    fi

  done
done
#echo "L1I $L2_SIZE_MIN $L2_ASSOSC_MIN" >> $HWDIR"min_so_far.txt"

: '
(b) Find the area and power dissipation (total leakage + runtime dynamic power) of the processor core (core + L1
caches) and L2 cache for your best configuration and compare it with the baseline configuration. The power data you
obtain from mcpat is for the 65nm library. How does this power change for 45nm and 32nm technology nodes?
Mention any trends you notice for leakage and dynamic power, and area (Hint: you need to change technology node
parameter in the xml template file to recalculate results for different technology nodes).
'
