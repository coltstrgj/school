#ifndef GTKMM_EXAMPLE_HELLOWORLD_H
#define GTKMM_EXAMPLE_HELLOWORLD_H

#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/grid.h>

class HelloWorld : public Gtk::Window
{
public:
  HelloWorld();
  virtual ~HelloWorld();

protected:

  // Signal handlers:
  // Our new improved on_button_clicked(). (see below)
  void on_button_clicked(Glib::ustring data);
  void on_button_quit();
  // Child widgets:
  Gtk::Grid m_grid;
  Gtk::Box m_box1;
  Gtk::Button m_button_1, m_button_2, m_button_quit;
};

#endif // GTKMM_EXAMPLE_HELLOWORLD_H
