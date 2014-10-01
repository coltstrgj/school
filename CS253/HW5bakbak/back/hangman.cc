#include "hangman.h"
#include <iostream>
#include <string>

using namespace std;

Hangman::Hangman()
: m_button_1("Button 1"),
  m_button_2("Button 2"),
  m_button_quit("Quit")
{
set_title("Hangman");
  set_border_width(12);
//i think that this is the screen
  add(m_grid);
//this is the buttons
  m_grid.add(m_button_1);
  m_grid.add(m_button_2);
  m_grid.attach_next_to(m_button_quit, m_button_1, Gtk::POS_BOTTOM, 2, 1);
//button use definitions
  m_button_1.signal_clicked().connect(sigc::bind<Glib::ustring>( sigc::mem_fun(*this,&Hangman::on_button_clicked), "button 1") );
  m_button_2.signal_clicked().connect(sigc::bind<Glib::ustring>( sigc::mem_fun(*this,&Hangman::on_button_clicked), "button 2") );
  m_button_quit.signal_clicked().connect(sigc::mem_fun(*this,&Hangman::on_button_quit) );

  
//this detects the keypress
////   add_events(Gdk::KEY_PRESS_MASK);
////   signal_key_press_event().connect(sigc::mem_fun(*this,
////                   &Hangman::on_key_press_event));  




  show_all_children();
}

Hangman::~Hangman(){

}
/*
bool Hangman::on_key_press_event(GdkEventKey *event){
   event=event; 
    exit(0);
    //GDK_MOD1_MASK -> the 'alt' key(mask)
  //GDK_KEY_1 -> the '1' key
  //GDK_KEY_2 -> the '2' key

  //select the first radio button, when we press alt + 1
/*  if((event->keyval == GDK_KEY_1) &&
    (event->state &(GDK_SHIFT_MASK | GDK_CONTROL_MASK | GDK_MOD1_MASK)) == GDK_MOD1_MASK)
  {
    m_first.set_active();
  }
  else if((event->keyval == GDK_KEY_2) &&
    (event->state & (GDK_SHIFT_MASK | GDK_CONTROL_MASK | GDK_MOD1_MASK)) == GDK_MOD1_MASK)
  {
    //and the second radio button, when we press alt + 2
    m_second.set_active();
  }
  else if(event->keyval == GDK_KEY_Escape)
  {
    //close the window, when the 'esc' key is pressed
    hide();
  }
/
  //returning true, cancels the propagation of the event
  return true;
}
*/


void Hangman::on_button_quit()
{
    exit(0);        
}
// Our new improved signal handler.  The data passed to this method is
// printed to stdout.
void Hangman::on_button_clicked(Glib::ustring data)
{
    if(data.compare("button 2")==0){
        set_border_width(get_border_width() - 2);
    }else{
        set_border_width(get_border_width() + 2);
    
    
    }
    
    //the size thing later
}
