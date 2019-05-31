# join_tabs
Merge scripts for Athena++ tab dumps, analogous to join_vtk++ included in vis folder of public Athena++ repo

USAGE INSTRUCTIONS -
First compile join_tab++.cpp to generate the executable join_tab++ by doing
> g++ join_tab++.cpp mergetabs.cpp -o join_tab++

This bash script calls join_tab++ to merge all dumps
INPUT:
put join_tabs.sh and join_tab++ in same folder as the dir containing a folder with Athena++ tab dumps and then do
> ./join_tabs.sh 0 500 dir_name problem_id

where problem_id is the variable from the input file
OUTPUT:
the merged tab dumps will appear in dir_name/merged

# Example
Included is a dir containing sample output run on 16 procs with 10 dump files named "TI.block0.out1.00000.tab ... TI.block15.out1.00000.tab" (initial conditions) 
through "TI.block0.out1.00009.tab ... TI.block15.out1.00009.tab" (final dump),
put join_tab++ in the folder containing this dir (call it TI1d). To merge all dumps in TI1d, do
> ./join_tabs.sh 0 9 TI1d TI

To merge just the 1st dump in TI1d, do
> ./join_tabs.sh 0 0 TI1d TI

The dir TI1d/merged contains the merged output files
