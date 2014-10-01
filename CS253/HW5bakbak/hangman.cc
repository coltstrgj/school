/////////////////////////////////
//Colt Darien
//CS253
//HW5
//03/25/2014
//////////////////////////////////
#include <vector>
#include <fstream>
#include <sstream>
#include <cerrno>
#include <cstring>
#include <ctime>
#include <locale>
#include <algorithm>
#include "hangman.h"
#include <iostream>
#include <string>

using namespace std;

Hangman::Hangman(string filename, int length): deadman("hang0.png"),  m_button_1("Button 1"), m_button_2("Button 2"), m_button_quit("Quit"), d_box("Status"){

this->w_list = createWordList(filename, length);
//get randomNum
answer =w_list[(randomNum()%(w_list.size()-1))];
//to check the answer
for(unsigned int i=0;i<answer.size();i++){
    char c=answer.at(i);
    if(!(isalpha(c) || isdigit(c) || (c == ' '))){
        progress.push_back(c);
    }else{
        progress.push_back('-');
    }

}
wrongChars="Used Letters: ";
wrongs=0;

m_button_2.set_label(answer);
w_label.set_text(progress);
u_label.set_text(wrongChars);
//this->wrongChars="";


set_title("Hangman");
  set_border_width(12);
    

//    m_label.set_text("this");
  // m_label.set_label("A label");

//i think that this is the screen
 add(v_box); 
 //this is the buttons
 v_box.pack_start(deadman); 

 v_box.pack_start(w_label);
 v_box.pack_start(u_label);
 v_box.pack_start(m_button_1);
 v_box.pack_start(m_button_2);
//  v_box.pack_start(m_label);
  v_box.pack_start(m_button_quit);
//  m_grid.add(m_label);
///////////////////////////event definitions
  m_button_1.signal_clicked().connect(sigc::bind<Glib::ustring>( sigc::mem_fun(*this,&Hangman::on_button_clicked), "button 1") );
  m_button_2.signal_clicked().connect(sigc::bind<Glib::ustring>( sigc::mem_fun(*this,&Hangman::on_button_clicked), "button 2") );
  m_button_quit.signal_clicked().connect(sigc::mem_fun(*this,&Hangman::on_button_quit) );

  
//this detects the keypress
   add_events(Gdk::KEY_PRESS_MASK);
   signal_key_press_event().connect(sigc::mem_fun(*this,
                   &Hangman::on_key_press_event));  




  show_all_children();
}

Hangman::~Hangman(){

}

int Hangman::randomNum(){
    srand(time(0));
    return rand();
}
bool Hangman::cmpStrings(string a, char b){
    for(unsigned int i=0; i<a.size();i++){
        if(tolower(a[i])==b)
            return true;
    }
    return false;

}
bool Hangman::checkChar(char check){//check if the character is in the Word
    //check if it is in the answer

    if(cmpStrings(wrongChars, check))
        return false;
    //if(tolower(answer).find(tolower(check))!=string::npos){
    if(cmpStrings(answer, check)){
        //if so then fill in the correct places
        fillIn(check);
        if(progress.compare(answer)==0){
            string tmp = "You have won! The goal was : ";
            tmp += answer;
            d_box.set_message(tmp);
            d_box.run();
            restart();
        }
        return true;
    }
    wrongChars.push_back(check);
    wrongChars.push_back(',');
    u_label.set_text(wrongChars);
    //change the picture
    ++wrongs;
    change_image();
    if(wrongs==6){
        //end the game
        string tmp = "You have lost. The goal was: ";
        tmp+= answer;
        d_box.set_message(tmp);
        d_box.run();
        restart(); 
    }
    return false;
}
void Hangman::restart(){
    deadman.set("hang0.png");

    answer =w_list[(randomNum()%(w_list.size()-1))];
    //to check the answer
    progress="";
    for(unsigned int i=0;i<answer.size();i++)
        progress.push_back('-');
    
    wrongChars="Used Letters: ";
    wrongs=0;

    m_button_2.set_label(answer);
    w_label.set_text(progress);
    u_label.set_text(wrongChars);

}
//convert int to string number
string Hangman::intToString(int iNum){
    string number = "";
    while(iNum>0){
        number.insert(number.begin(),static_cast<char>(iNum%10+48));
        iNum/=10; 
    }
    return number;
}


void Hangman::change_image(){
    string tmp = "hang";
    tmp+=intToString(wrongs); 
    tmp+=".png";
    deadman.set(tmp);
}
void Hangman::fillIn(char check){//fill in every instance of the character in the unknown string    
    for(unsigned int i=0; i<answer.size();i++){
        if(tolower(answer.at(i))==tolower(check)){
            progress.at(i)=answer.at(i);
        }
     } 
        w_label.set_text(progress); 
}




vector<string> Hangman::createWordList(string filename, int length){
    vector<string> wordList;
    ifstream in(filename.c_str());
    if (!in) {
           //Couldn.t open the file.  Why?
        ostringstream oss;
        oss << "can't open " << filename << ": " << strerror(errno);
        throw oss.str();
    }
    string line;
    while(getline(in, line)){
        if(line.size()<(unsigned)length){
            wordList.push_back(line);
        }
    
    }
    return wordList;
}








bool Hangman::on_key_press_event(GdkEventKey *event){
  return checkChar(gdk_keyval_to_lower(event->keyval)); 
}



void Hangman::on_button_quit()
{
    exit(0);        
}
// Our new improved signal handler.  The data passed to this method is
// printed to stdout.
void Hangman::on_button_clicked(Glib::ustring data)
{
    if(data.compare("button 2")==0){
        m_button_2.set_label(intToString(randomNum()));
    }else{
        set_border_width(get_border_width() + 2);
    
    
    }
    
    //the size thing later
}
