The hdf5 dumps in Athena++ are great for 2D and 3D simulations, but often in setting up such simulations I rely on 1D simulations, in which case it is helpful to use tab dumps which can be easily looked at.  Often it suffices to just run 1D simulations in serial.  However, in the course of my PhD I needed to run very high-resolution 1D simulations quite often, and so I ended up needing to run these on a cluster, in which case I'm returned a bunch of unmerged tab dumps.  This is a simple code designed to live on the cluster to quickly merge 1D tab dumps.  

# join_tabs
Merge scripts for Athena++ tab dumps, analogous to join_vtk++ included in vis folder of public Athena++ repo

USAGE INSTRUCTIONS -
First compile join_tab++.cpp to generate the executable join_tab++ by doing
> g++ join_tab++.cpp mergetabs.cpp -o join_tab++

This bash script calls join_tab++ to merge all dumps

INPUT:
put join_tabs.sh and join_tab++ in same folder as the dir containing a folder with Athena++ tab dumps and then do
> ./join_tabs.sh 0 N dir_name problem_id

where 0 N denote the range of files to merge and problem_id is the variable from the input file.

OUTPUT:
the merged tab dumps will appear in dir_name/merged

# Example
Included is a dir containing sample output run on 4 procs with 10 dump files named "TI.block0.out1.00000.tab ... TI.block3.out1.00000.tab" (initial conditions) 
through "TI.block0.out1.00009.tab ... TI.block3.out1.00009.tab" (final dump),
put join_tab++ in the folder containing this dir (call it TI1d). To merge all dumps in TI1d, do
> ./join_tabs.sh 0 9 TI1d TI

To merge just the 1st dump in TI1d, do
> ./join_tabs.sh 0 0 TI1d TI

The dir TI1d/merged contains the merged output files
