#ifndef PNum_h_included
#define PNum_h_included

#include <iostream>
#include <string>
#include <vector>


class  Word{
    public:
        Word(std::string, int);
        bool checkChar(char);//check if the character is in the Word
        std::string fillIn(char);//fill in every instance of the character in the unknown string    


    private:

        int stringToInt(std::string sNum);


};
#endif
