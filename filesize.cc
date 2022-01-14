#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
using namespace std;

// output format to use IDENTICALLY:
//BSH:Saru> ./filesize input.3lines input.1line 
//program: ./filesize
// input.3lines: 3
// input.1line: 1
//
int main( int argc, char* argv[] )
{
    std::cout << "program: " << argv[0] << '\n' ;
    for (int arg = 1; arg < argc; ++arg){ //for parsing the command line arguments 
        ifstream instream;
        string dataline;
        int lineCount = -1;
        instream.open(argv[arg], std::ifstream::in);
        if (!(instream.fail())){
            while(!instream.eof()){
                getline(instream, dataline); //getline of data and increment 
                lineCount++;
            }
        }
        else{ //if it is not a readable file that can't be opened then set line count to -1
            lineCount = -1;
        }
        instream.close();       
        std::cout << " " << argv[arg] << ": " << lineCount << '\n' ;
    }
    exit(0); // this means that the program executed correctly!
}
