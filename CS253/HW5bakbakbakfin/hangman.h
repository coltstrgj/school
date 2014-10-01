#ifndef GTKMM_EXAMPLE_HELLOWORLD_H
#define GTKMM_EXAMPLE_HELLOWORLD_H

#include <gtkmm.h>//what was I supposed to include

class Hangman : public Gtk::Window
{
public:
  Hangman(std::string, int);
  virtual ~Hangman();

protected:

  // Signal handlers:
  // Our new improved on_button_clicked(). (see below)
  void on_button_clicked(Glib::ustring data);
  void on_button_quit();
  bool on_key_press_event(GdkEventKey *event);
  // Child widgets:
  Gtk::Label w_label, u_label;  
  Gtk::Image deadman;
  Gtk::VBox v_box;
  Gtk::Entry m_entry;
  Gtk::Button m_button_quit;
  Gtk::MessageDialog d_box;
  // Gtk::Label m_label;
private:
    int randomNum();
    bool checkChar(char);//check if the character is in the Word
    bool cmpStrings(std::string, char); 
    void fillIn(char);//fill in every instance of the character in the unknown string    
    int wrongs;
    void change_image();
    void restart();
    std::string intToString(int);
    std::string progress, answer, wrongChars;
    std::vector<std::string> w_list;
    std::vector<std::string> createWordList(std::string, int);
};

#endif //GTKMM_EXAMPLE_HELLOWORLD_H
