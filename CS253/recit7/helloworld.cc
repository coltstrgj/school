#include "helloworld.h"
#include <iostream>
#include <string>

using namespace std;

HelloWorld::HelloWorld()
: m_button_1("Pirate thing that we are supposed to make this say"),
  m_button_2("Button 2"),
  m_button_quit("Big Shot #0")
{
set_title("Gtk::Grid");
  set_border_width(12);

  add(m_grid);

  m_grid.add(m_button_1);
  m_grid.add(m_button_2);
  m_grid.attach_next_to(m_button_quit, m_button_1, Gtk::POS_BOTTOM, 2, 1);

  m_button_1.signal_clicked().connect(
    sigc::bind<Glib::ustring>( sigc::mem_fun(*this,
      &HelloWorld::on_button_clicked), "button 1") );
  m_button_2.signal_clicked().connect(
    sigc::bind<Glib::ustring>( sigc::mem_fun(*this,
      &HelloWorld::on_button_clicked), "button 2") );

  m_button_quit.signal_clicked().connect(sigc::mem_fun(*this,
    &HelloWorld::on_button_quit) );

  show_all_children();
}

HelloWorld::~HelloWorld(){

}
void HelloWorld::on_button_quit()
{
//    static int clicks=0;
//   clicks++;
//   string tmp = "Big shot #" + clicks;
//   HelloWorld().m_button_quit(tmp.c_str());
  //hide();
  //I stole this code from the website because it looked cool, but its broken and I dont care why
}
// Our new improved signal handler.  The data passed to this method is
// printed to stdout.
void HelloWorld::on_button_clicked(Glib::ustring data)
{
    if(data.compare("button 2")==0){
        set_border_width(get_border_width() - 2);
    }else{
        set_border_width(get_border_width() + 2);
    
    
    }
    
    //the size thing later
}
