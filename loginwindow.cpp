#include "loginwindow.h"
#include <iostream>

LoginWindow::LoginWindow(): m_VBox(Gtk::ORIENTATION_VERTICAL)
{
  set_size_request(200, 100);
  set_title("Webex Phone Control");
  add(m_VBox);
  uname_Entry.set_max_length(50);
  uname_Entry.set_text("Enter");
  uname_Entry.set_text(uname_Entry.get_text() + " Username");
  uname_Entry.select_region(0, uname_Entry.get_text_length());
  m_VBox.pack_start(uname_Entry);
  passwd_Entry.set_max_length(50);
  passwd_Entry.set_text("****");
  passwd_Entry.set_text(passwd_Entry.get_text() + "****");
  passwd_Entry.select_region(0, passwd_Entry.get_text_length());
  m_VBox.pack_start(passwd_Entry);
  string token = "YzM2OTAzNjItYjE1NS00ZWU4LTg2MGUtOWYyYzk0MTFiMGEyMDgzOGVmNDQtYjdk_PF84_43f0f16a-8814-4d73-905f-ef9df603ef61";
  MainWindow main_window(token);

  // Note that add() can also be used instead of pack_xxx()
  m_VBox.add(m_HBox);
  login_b.set_label("Login");
  login_b.signal_clicked().connect( sigc::mem_fun(*this, &LoginWindow::on_button_login) );
  m_VBox.pack_start(login_b);
  login_b.set_can_default();
  login_b.grab_default();
  show_all_children();
}

LoginWindow::~LoginWindow()
{
}

void LoginWindow::on_button_login()
{
cout << "attempting to login" << endl;
int login = 1;
	if (login == 1){
		cout << "Login Successful!" << endl;
		cout << "Showing Window!" << endl;
//		this->main_window(this->token).show();
	}else{
		cout << "Login Failed!" << endl;
	}
  //Shows the window and returns when it is closed.
}
