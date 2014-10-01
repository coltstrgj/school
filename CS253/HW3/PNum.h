#ifndef PNum_h_included
#define PNum_h_included

#include <iostream>
#include <string>



class PNum {

    public:
        PNum(int, int, int);
        PNum(std::string, std::string, std::string); 
        PNum(std::string); 
        void set_area_code(std::string);
        void set_exchange(std::string);
        void set_subscriber(std::string);
        void set_area_code(int);
        void set_exchange(int);
        void set_subscriber(int);

        std::string get_area_code()const;      
        std::string get_exchange()const;
        std::string get_subscriber()const;
        std::string get_phone_number()const;

        bool operator<(const PNum&) const;
        bool operator>(const PNum&) const;
        PNum &operator=(const PNum&) const;
        //std::ostream &operator<<(std::ostream &stream, const PNum &val) {

        PNum(const PNum &other );
        



    private:
        std::string areaCode;
        std::string exchange;
        std::string subscriber;
        std::string intToString(int);
        int stringToInt(std::string);
        bool checkNum(std::string);
        bool softCheck(std::string);
        bool checkNumR(int);
        bool checkNum11(int);
};
std::ostream & operator<<(std::ostream &, const PNum &);
#endif
