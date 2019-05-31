#ifndef TAB_MERGER_H
#define TAB_MERGER_H

#define PRECISION 18			//desired floating point precision in output
                          
#include <string>                         //Defines strings
#include <sstream>                        //Needed for file I/O
#include <time.h>                         //Used to get run time summary
#include <new>                            //For dynamic allocation
#include <cstdlib>                        //Defines exit() function
#include <fstream>  			  //File I/O
#include <iostream>		  	  //Terminal I/O
#include <iomanip>      		  // for setprecision
#include <vector>                         //Superior dynamic arrays

typedef std::vector<std::string> stringvec;  //input filename container
typedef std::vector<double> datavec;         //row data container

class FileMerger {
  public:

    FileMerger(stringvec s_in, std::string s_out="") :
                    fnames(s_in),output_fname(s_out) {}

    void run(std::string path="");

    //Member functions 
    void merge_input_files();
    void output_row(std::ofstream&,datavec&);
    void write_header(std::ofstream&);
    void write_output_log(clock_t);
    void set_output_path(std::string);

  private:
    int N_lines;                  //records # of lines of input_data
    std::string path,             //path of output; default is current dir.
                output_fname,     //output file
                outputlog_fname;  //output file log
    stringvec fnames;		  //vector of input files
};

template <class T>
inline std::string to_string (const T& t)
{
   std::stringstream ss;
   ss << t;
   return ss.str();
}

#endif //TAB_MERGER_H
