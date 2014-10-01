/////////////////////////////////
//Colt Darien
//CS253
//HW5
//03/25/2014
//////////////////////////////////
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "word.h"

using namespace std;

Word::Word(string filename, int length){
    string line;
    ifstream infile(filename);
    while (std::getline(infile, line)){
        cout<<line;
    }

}

bool Word::checkChar(char character){
    

}

string Word::fillIn(char character){
    

}  


int Word::stringToInt(string sNum) {
   int number=0; 
   for(unsigned int i=0; i<sNum.size(); i++){
           number*=10;
           number+=sNum.at(i)-48;//ascii to int
   }
   return number;

}





