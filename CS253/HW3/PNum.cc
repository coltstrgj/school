#include <iostream>
#include <string>
#include "PNum.h"


using namespace std;


//converts a string to an int     
int PNum::stringToInt(string sNum) {
   int number=0; 
   for(unsigned int i=0; i<sNum.size(); i++){
           number*=10;
           number+=sNum.at(i)-48;//ascii to int
   }
   return number;

}
//convert int to string number
string PNum::intToString(int iNum){
    string number = "";
    while(iNum>0){
        number.insert(number.begin(),static_cast<char>(iNum%10+48));
        iNum/=10; 
    }
    while(number.size()<4){
        number.insert(number.begin(),'0');
    }
    return number;
}

//check if the number has - and digits only
bool PNum::checkNum(string number){
    for(unsigned int i=0; i<number.size(); i++){
        if((number.at(i)>'9' || number.at(i)<'0') && number.at(i)!='-')
            return false;
    }
    if(number.length()!=12){
        return false;
    }
    return true;
}
//check if the number is in range(greater than 200 less than 999) this is for the area and exchange
bool PNum::checkNumR(int number){
    if(number<200||number>999){
        return false;
    }
    return true;
}
//check for the *11 to be sure that it doesnt confuse people
bool PNum::checkNum11(int number){
    if(number%10==1 && (number/10)%10==1){
        return false;
    }
    return true;
}
//check and be sure that number contains no hyphens
bool PNum::softCheck(string number){
    for(unsigned int i=0; i<number.size(); i++){
        if((number.at(i)>'9' || number.at(i)<'0')){
            string errors = "Non-digit '";
            errors+=number.at(i);
            errors+="' encountered!!";
            throw errors.c_str();
            return false;
        }
    }
    return true;


}


//sets the area code from a string
void PNum::set_area_code(string aCode) {
    int area;
    area = stringToInt(aCode);
    if(!(checkNumR(area))){
        throw "Area code must be ≥200 and ≤999!";
        return; 
    }
    if(!(checkNum11(area))){
        throw "Area code must not be x11!";
        return;
    }
    if(!softCheck(aCode))
        return;
    this->areaCode=aCode;
    return;
}


//this is meant as string exchange, not sexchange. It avoids the shadow something error I am getting I thik
void PNum::set_exchange(string sexchange) {
    int exch;
    exch = stringToInt(sexchange);
    if(!(checkNumR(exch))){
        throw "Exchange code must be ≥200 and ≤999!";
        return; 
    }
    if(!(checkNum11(exch))){
        throw "Exchange code must not be x11!";
        return;
    }
    if(!softCheck(subscriber))
        return;
    
    this->exchange = sexchange;
    return;
}

//sets the subscriber number
void PNum::set_subscriber(string ssubscriber) {
    if(ssubscriber.length()<4){
        return;
    }
    if(!softCheck(ssubscriber))
        return;
    
    this->subscriber=ssubscriber;
    return;
}
//set areaCode based off of an int
void PNum::set_area_code(int aCode) {
    string number;
     if(!(checkNumR(aCode))){
        throw "Exchange code must be ≥200 and ≤999!";
        return; 
    }
    if(!(checkNum11(aCode))){
        throw "Exchange code must not be x11!";
        return;
    }
    number=intToString(aCode);
    this->areaCode=number;
    return;
}

//see... it wasnt sexchange in the way you thought
void PNum::set_exchange(int iexchange) { 
    string number;
    if(!(checkNumR(iexchange))){
        throw "Exchange code must be ≥200 and ≤999!";
        return; 
    }
    if(!(checkNum11(iexchange))){
        throw "Exchange code must not be x11!";
        return;
    }
    number=intToString(iexchange);
    this->exchange=number;
    return;
}
//sets the subscriber based on an int
void PNum::set_subscriber(int isubscriber) { 
    string number;
    number=intToString(isubscriber);
    if(isubscriber>9999){
        throw "Error. The subscriber number is too big!";
    }
    this->subscriber=number;
    return;
}



//constructor for a full phone number string
PNum::PNum(string pNumber){
    if(!checkNum(pNumber)){
        throw "Phone number must be DDD-DDD-DDDD!";
        return;
    }
    string sTemp = pNumber.substr(0,2);
    set_area_code(sTemp);
    
    sTemp = pNumber.substr(4,6);
    set_exchange(sTemp); 

    sTemp = pNumber.substr(8,11);
    set_subscriber(sTemp);
}
//constructor for string inputs
PNum::PNum(string pAreaCode, string pExch, string pSub){
    set_area_code(pAreaCode);
    set_exchange(pExch);
    set_subscriber(pSub);
}
//constructor for integer inputs
PNum::PNum(int pAreaCode, int pExch, int pSub){
    set_area_code(pAreaCode);
    set_exchange(pExch);
    set_subscriber(pSub);
}

//these are the accessors
string PNum::get_area_code()const {
    return areaCode;
}
string PNum::get_exchange()const {
    return exchange;
}
string PNum::get_subscriber()const {
    return subscriber;
}
//this one gets the whole thing with dashes
string PNum::get_phone_number()const{
    return areaCode+"-"+exchange+"-"+subscriber;
}



//constructors and stuff


PNum::PNum(const PNum &rhs) : areaCode(rhs.areaCode), exchange(rhs.exchange),subscriber(rhs.subscriber) {}
//9701237654
//9876543210
bool PNum::operator<(const PNum &other) const {
    if(get_area_code().compare(other.get_area_code())!=0){
       return get_area_code()<other.get_area_code();     
    }else if(get_exchange().compare(other.get_exchange())!=0){
        return get_exchange()<other.get_exchange();
    }
    return get_subscriber()<other.get_subscriber();
}
//this is the opposite of above
bool PNum::operator>(const PNum &other) const {
    if(get_area_code().compare(other.get_area_code())!=0){
       return get_area_code()>other.get_area_code();     
    }else if(get_exchange().compare(other.get_exchange())!=0){
        return get_exchange()>other.get_exchange();
    }
    return get_subscriber()>other.get_subscriber();
    
}
/*//whi is this thing not working????? I think everything else is
PNum PNum::&operator=(const PNum &other) {
    area_code = other.get_area_code();
    exchange = other.get_exchange();
    subscriber = other.get_subscriber();
    return this;
}
*/

ostream &operator<<(ostream &stream, const PNum &val) {
    return stream << val.get_area_code() << '-' << val.get_exchange() << '-'<<val.get_subscriber();
}

int main(){
    PNum p = PNum("345","787","9999");
    cout<<p;


return 0;
}
