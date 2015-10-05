#!/bin/bash 
cd /home/cjohnson/School/ECE561/gem5/McPAT08release/ 
HW_DIR=/home/cjohnson/School/ECE561/HW2/problem1 
FILE_NAMES=(
   'L1_D.32kB.4--L1_I.32kB.4--L2.1024kB.4'
   'L1_D.16kB.2--L1_I.4kB.2--L2.128kB.4'   
   'L1_D.16kB.4--L1_I.4kB.2--L2.128kB.4' 
   'L1_D.32kB.2--L1_I.4kB.2--L2.128kB.4' 
   'L1_D.32kB.4--L1_I.16kB.2--L2.128kB.4' 
   'L1_D.32kB.4--L1_I.16kB.4--L2.128kB.4' 
   'L1_D.32kB.4--L1_I.32kB.2--L2.128kB.4' 
   'L1_D.32kB.4--L1_I.32kB.4--L2.1024kB.4' 
   'L1_D.32kB.4--L1_I.32kB.4--L2.1024kB.8' 
   'L1_D.32kB.4--L1_I.32kB.4--L2.128kB.4' 
   'L1_D.32kB.4--L1_I.32kB.4--L2.128kB.8' 
   'L1_D.32kB.4--L1_I.32kB.4--L2.2048kB.4' 
   'L1_D.32kB.4--L1_I.32kB.4--L2.2048kB.8'
   'L1_D.32kB.4--L1_I.32kB.4--L2.256kB.4' 
   'L1_D.32kB.4--L1_I.32kB.4--L2.256kB.8' 
   'L1_D.32kB.4--L1_I.32kB.4--L2.4096kB.4' 
   'L1_D.32kB.4--L1_I.32kB.4--L2.4096kB.8' 
   'L1_D.32kB.4--L1_I.32kB.4--L2.512kB.4' 
   'L1_D.32kB.4--L1_I.32kB.4--L2.512kB.8' 
   'L1_D.32kB.4--L1_I.4kB.2--L2.128kB.4' 
   'L1_D.32kB.4--L1_I.4kB.4--L2.128kB.4' 
   'L1_D.32kB.4--L1_I.8kB.2--L2.128kB.4' 
   'L1_D.32kB.4--L1_I.8kB.4--L2.128kB.4' 
   'L1_D.4kB.2--L1_I.4kB.2--L2.128kB.4' 
   'L1_D.4kB.4--L1_I.4kB.2--L2.128kB.4' 
   'L1_D.8kB.2--L1_I.4kB.2--L2.128kB.4' 
   'L1_D.8kB.4--L1_I.4kB.2--L2.128kB.4' 
)
#might as well create a sim file for all of them
for FILE in ${FILE_NAMES[*]}; do
  echo $FILE
  exec perl m5-mcpat.pl $HW_DIR/$FILE".txt" $HW_DIR/$FILE".ini" mcpat-template-alpha.xml > $HW_DIR/$FILE".xml"&
  #exec perl mcpat-exec.pl $HW_DIR/$FILE".xml"
done

