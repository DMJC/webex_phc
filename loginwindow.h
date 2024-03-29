#ifndef GTKMM_LOGINWINDOW_H
#define GTKMM_LOGINWINDOW_H
#include "mainwindow.h"
#include <gtkmm.h>
using namespace std;
class LoginWindow : public Gtk::Window
{
public:
  LoginWindow();
  virtual ~LoginWindow();

protected:
  //Signal handlers:
  void on_checkbox_editable_toggled();
  void on_checkbox_visibility_toggled();
  void on_button_login();

  string token;
  //Child widgets:
  Gtk::Box m_HBox;
  Gtk::Box m_VBox;
  Gtk::Entry uname_Entry;
  Gtk::Entry passwd_Entry;
  Gtk::Button login_b;
  MainWindow main_window(string token);
};

#endif //GTKMM_LOGINWINDOW_H
