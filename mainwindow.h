#ifndef GTKMM_MAINWINDOW_H
#define GTKMM_MAINWINDOW_H
#include <gtkmm.h>
#include <libayatana-appindicator/app-indicator.h>
#include <libdbusmenu-gtk/dbusmenu-gtk.h>

using namespace std;

class MainWindow : public Gtk::Window
{
public:
  MainWindow(string token);
  virtual ~MainWindow();
  bool on_delete_event(GdkEventAny* event);
protected:
  //Signal handlers:
  void on_checkbox_editable_toggled();
  void on_checkbox_visibility_toggled();
  void on_button_dial();
  bool on_label_clicked(GdkEventButton* event, Gtk::Label* label);
  void number_to_redial();
  //Child widgets:
  Gtk::Box m_HBox;
  Gtk::Box m_HBox_authtoken;
  Gtk::Box m_VBox;
  Gtk::Box m_VPBox;
  Gtk::Label auth_Label;
  Gtk::Entry auth_Entry;
  Gtk::Label number_Label;
  Gtk::Entry number_Entry;
  Gtk::Button dial_Button;
  Gtk::Frame history_frame;
  Gtk::ScrolledWindow history_scrolled;
  string token;
};

#endif //GTKMM_MAINWINDOW_H
