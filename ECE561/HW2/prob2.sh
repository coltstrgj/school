##This is what will be created or done to your computer
##Thank you for helping me out
cd ~/School/ECE561/gem5/ #change this to wherever you have the gem5 directory
mkdir -p /home/$USER/ColtsHW/Problem2/ #creates a directory for all of my stuff


#dont need one for I and D but it makes code more readable
L1_D_SIZE_LIST=(16 8 4)
L1_I_SIZE_LIST=(16 8 4)
#I suppose that we are supposed to use the same associativity rules as last problem (2 or 4)
L1_D_ASSOC_LIST=(4 2)
L1_I_ASSOC_LIST=(4 2)
L1_D_SIZE=4
L1_D_ASSOC=2
L1_I_SIZE=4
L1_I_ASSOC=2

#HWDIR="/home/cjohnson/School/ECE561/HW2/problem1/"
HWDIR="/home/$USER/ColtsHW/Problem2/"
MIN_SIM_CYCLES=10000000000
for L1_D_SIZE in ${L1_D_SIZE_LIST[@]}; do
  for L1_D_ASSOC in ${L1_D_ASSOC_LIST[@]}; do
    SIMULATE="build/ARM/gem5.opt configs/example/se.py --cpu-type="detailed" --sys-clock=2GHz --cpu-clock=2GHz --caches--l1d_size="$L1_D_SIZE"kB --l1i_size="$L1_I_SIZE"kB --l1d_assoc="$L1_D_ASSOC" --l1i_assoc="$L1_I_ASSOC" --cmd=splash2-orig/codes/kernels/fft/FFT -o “-m8 -o” -I 10000000"
    FILE_NAME=$HWDIR"L1_D."$L1_D_SIZE"kB."$L1_D_ASSOC"--L1_I."$L1_I_SIZE"kB."$L1_I_ASSOC
    echo
    echo
    echo "Working on $FILE_NAME"
    touch $FILE_NAME".txt"
    echo "$SIMULATE"
    cat m5out/config.ini > $FILE_NAME".ini"
    cat m5out/stats.txt > $FILE_NAME".txt"
    SIM_CYCLES=$(cat m5out/stats.txt | grep system.cpu.numCycles | sed 's/[^0-9]//g') #get the exec time
    echo -e "\e[33m This simulation took $SIM_CYCLES cycles\e[39m"
    if [ "$(($SIM_CYCLES - $MIN_SIM_CYCLES))" -lt 0 ]; then
      echo -e "Prev min: \e[41m$MIN_SIM_CYCLES\e[49m cycles"
      echo "------------------------------------------------------"
      echo -e "\e[32mNEW minimum\e[39m \e[42m$SIM_CYCLES\e[49m"
      echo "------------------------------------------------------"
      L1_D_SIZE_MIN=$L1_D_SIZE
      L1_D_ASSOSC_MIN=$L1_D_ASSOC
      MIN_SIM_CYCLES=$SIM_CYCLES
    fi
  done
done
#set the variables to the minimum speed values
L1_D_SIZE=$L1_D_SIZE_MIN
L1_D_ASSOC=$L1_D_ASSOSC_MIN
#set the MIN_SIM_CYCLES so that it is always going to be reset on first run in loop
MIN_SIM_CYCLES=10000000000

echo
echo
echo
echo "--------------------------------------------------------------------------"
echo -e "-----------------------\e[34mChecking Instruction cache now\e[39m---------------------"
echo "--------------------------------------------------------------------------"



for L1_I_SIZE in ${L1_I_SIZE_LIST[@]}; do
  for L1_I_ASSOC in ${L1_I_ASSOC_LIST[@]}; do
    SIMULATE="build/ARM/gem5.opt configs/example/se.py --cpu-type="detailed" --sys-clock=2GHz --cpu-clock=2GHz --caches--l1d_size="$L1_D_SIZE"kB --l1i_size="$L1_I_SIZE"kB --l1d_assoc="$L1_D_ASSOC" --l1i_assoc="$L1_I_ASSOC" --cmd=splash2-orig/codes/kernels/fft/FFT -o “-m8 -o” -I 10000000"
    FILE_NAME=$HWDIR"L1_D."$L1_D_SIZE"kB."$L1_D_ASSOC"--L1_I."$L1_I_SIZE"kB."$L1_I_ASSOC
    echo
    echo
    echo "Working on $FILE_NAME"
    touch $FILE_NAME".txt"
    echo "$SIMULATE"
    cat m5out/config.ini > $FILE_NAME".ini"
    cat m5out/stats.txt > $FILE_NAME".txt"
    SIM_CYCLES=$(cat m5out/stats.txt | grep system.cpu.numCycles | sed 's/[^0-9]//g') #get the exec time
    echo -e "\e[33m This simulation took $SIM_CYCLES cycles\e[39m"
    if [ "$(($SIM_CYCLES - $MIN_SIM_CYCLES))" -lt 0 ]; then
      echo -e "Prev min: \e[41m$MIN_SIM_CYCLES\e[49m cycles"
      echo "------------------------------------------------------"
      echo -e "\e[32mNEW minimum\e[39m \e[42m$SIM_CYCLES\e[49m"
      echo "------------------------------------------------------"
      L1_I_SIZE_MIN=$L1_I_SIZE
      L1_I_ASSOSC_MIN=$L1_I_ASSOC
      MIN_SIM_CYCLES=$SIM_CYCLES
    fi
  done
done
#set the minimums again

L1_I_SIZE=$L1_I_SIZE_MIN
L1_I_ASSOC=$L1_I_ASSOSC_MIN

touch $HWDIR"ANS.txt"
echo -e "\e[104mFastest Running setup\e[49m"
echo -e "\e[104mL1_D_SIZE: $L1_D_SIZE   L1_D_ASSOC: $L1_D_ASSOC\e[49m"
echo -e "\e[104mL1_D_SIZE: $L1_D_SIZE   L1_D_ASSOC: $L1_D_ASSOC\e[49m"

echo -e "\e[104mFastest Running setup\e[49m" > $HWDIR"ANS.txt"
echo -e "\e[104mL1_D_SIZE: $L1_D_SIZE   L1_D_ASSOC: $L1_D_ASSOC\e[49m" >> $HWDIR"ANS.txt"
echo -e "\e[104mL1_D_SIZE: $L1_D_SIZE   L1_D_ASSOC: $L1_D_ASSOC\e[49m" >> $HWDIR"ANS.txt"

cd $HWDIR\.. #up a directory and tar 
pwd
tar czvf Problem2.tgz Problem2
mv Problem2.tgz /home/$USER/COLTSHW.tgz
cd /home/$USER/
rm -rf ColtsHW/
