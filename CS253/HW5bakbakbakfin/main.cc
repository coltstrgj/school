#include "hangman.h"
#include <gtkmm/main.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
/*
std::string line;
while (std::getline(infile, line))
{
    std::istringstream iss(line);
        int a, b;
            if (!(iss >> a >> b)) { break; } // error
            
                // process pair (a,b)
                // }
*/
using namespace std;

int stringToInt(string sNum) {
   int number=0; 
   for(unsigned int i=0; i<sNum.size(); i++){
           number*=10;
           number+=sNum.at(i)-48;//ascii to int
   }
   return number;

}

int main (int argc, char *argv[])
{
    if(argc<3){
        cout <<argv[0]<< ": Not enough arguments specified"<<endl;
    }
    Gtk::Main kit(argc, argv);
    string tmp = argv[1];
    Hangman hangman(tmp, stringToInt(argv[2]));
    Gtk::Main::run(hangman);

    return 0;
}
