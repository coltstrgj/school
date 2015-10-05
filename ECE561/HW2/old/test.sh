#!/bin/bash
MIN_SIM_SECONDS=100
SIM_SECONDS=$(cat ../gem5/m5out/stats.txt | grep system.cpu.numCycles | sed 's/[^0-9]//g') #get the exec time
echo $SIM_SECONDS
if [ "$(($SIM_SECONDS - $MIN_SIM_SECONDS))" -lt 0 ]; then
  echo NEW minimum
fi
