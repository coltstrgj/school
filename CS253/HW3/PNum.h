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

        const std::string get_area_code() {return areaCode;}
        const std::string get_exchange() {return exchange;}
        const std::string get_subscriber() {return subscriber;}
        const std::string get_phone_number();


        bool operator>(const PNum&) const;
        
        PNum(const PNum &other );
        //PNum &operator<<

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
