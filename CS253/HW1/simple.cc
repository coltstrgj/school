#include <iostream>
#include <string>

using namespace std;
string compareTo = "Barack";

int lb_to_kg (int lbs){
        return lbs*0.45359237;
}

string nLength(string n){
	if(n.length()<compareTo.length()){
		return "shorter than";
	}
	if(n.length()>compareTo.length()){
		return "longer than";
	}
	return "the same length as";
}


int main() {
	int weight;
	string name;
	string comparison;
	
	cout<<"Your name? ";
	getline (cin,name);
	comparison = nLength(name);
	cout<<"Your name, \""<< name << "\", is "<< comparison << " \""<< compareTo <<"\".\n";
	
	
	cout<<"Your weight in pounds? ";
	cin>>weight;
	int kg = lb_to_kg (weight);
	cout<<"That's "<<kg<<" kilograms.\n";
	
	
	return 0;				    // technically optional
}
