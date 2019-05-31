/*=====================================================================================
                                  Program join_tab
                    Please report any bugs to waters@lanl.gov
History:
First created March 2014 by Tim Waters for use with C-version Athena
This version was updated in 2018 to work with Athena++ tab output.
=======================================================================================
Command Line Usage:
 * compile using g++ join_tab++.cpp mergetabs.cpp -o join_tab++
 * execute using ./join_tab++ output.tab file1.tab file2.tab file3.tab ...
*/

#include "mergetabs.h"

using namespace std;

int main( int argc, char *argv[] )
{

  stringvec inputfiles;
  for (int n=2; n < argc; n++)
  {
    string filename = argv[n];
    inputfiles.push_back(filename);
  }
  
  string output = argv[1];
  
  FileMerger instance(inputfiles,output); 
  instance.run(); //this will dump output in the current workspace

  return 0;
}
