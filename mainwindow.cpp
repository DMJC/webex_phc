#include "mainwindow.h"
#include "answer/answer.h"
#include "dial/dial.h"
#include "hangup/hangup.h"
#include <chrono>
#include <thread>
#include <iostream>
#include <fstream>

bool MainWindow::on_delete_event(GdkEventAny* event) {
	cout << "Hiding Window" << endl;
	hide(); // Hide the window instead of destroying it   
	cout << "Hidden Window" << endl;     
	return true; // Prevent the default destruction of the 
}

MainWindow::MainWindow(string token)
{
  token = "INSERT TOKEN HERE";
  set_size_request(200, 0);
  set_title("Webex Phone Control");
  add(m_VBox);
  m_VBox.set_orientation(Gtk::ORIENTATION_VERTICAL);
  m_VBox.add(m_HBox_authtoken);
  m_VBox.set_vexpand(TRUE);
  m_HBox_authtoken.pack_start(auth_Label);
  m_VBox.add(m_HBox);
  m_HBox.pack_start(number_Label);
  auth_Label.set_label("Enter Webex Auth Token: ");
  auth_Entry.set_max_length(108);
  auth_Entry.set_text("Zjc2NjQ0ODEtNzAxYi00ZGYwLWJkNTktNDA1ZWM4MGU2MDBiNzJjM2VkODktZWI4_PF84_43f0f16a-8814-4d73-905f-ef9df603ef61");
  m_HBox_authtoken.add(auth_Entry);
  number_Label.set_label("Enter Number to Dial: ");
  number_Entry.set_max_length(12);
  number_Entry.set_text("0400278993");
  number_Entry.select_region(0, number_Entry.get_text_length());
  m_HBox.add(number_Entry);
  dial_Button.set_label("Dial");
  dial_Button.signal_clicked().connect( sigc::mem_fun(*this, &MainWindow::on_button_dial) );
  m_VBox.add(dial_Button);
  dial_Button.set_can_default();
  dial_Button.grab_default();
  m_VBox.add(history_frame);
  history_frame.set_label("Call History:");
  history_frame.add(history_scrolled);
  m_VPBox.set_orientation(Gtk::ORIENTATION_VERTICAL);
  m_VPBox.set_vexpand(TRUE);
  history_scrolled.add(m_VPBox);
  signal_delete_event().connect(sigc::mem_fun(*this, &MainWindow::on_delete_event));
  show_all_children();
}

MainWindow::~MainWindow()
{

}

bool MainWindow::on_label_clicked(GdkEventButton* event, Gtk::Label* label) {
//X11    if (event->type == GDK_BUTTON_PRESS && event->button == 1)
    if (event->button == GDK_BUTTON_PRIMARY) {
        // Left mouse button clicked
	cout << "Label clicked!" << endl;
        // Call your new function here
        number_to_redial();
        return true;
    }
    cout << "Label clicked!" << endl;
    number_to_redial();
    return false;
}

// Define your new function here
void MainWindow::number_to_redial() {
     cout << "New function called!" << endl;
}

void MainWindow::on_button_dial()
{
 cout << "Dialing: " << number_Entry.get_text() << endl;
 this->token = auth_Entry.get_text();
 cout << "Reading text file" << endl;
 ifstream dial_file;
 string line;
 dial_file.open ("dial.txt");
     if(dial_file.is_open()){
        while(!dial_file.eof()){
            getline(dial_file,line);
            if(line != ""){
            	cout<< line << endl;
				string call_id = dial(this->token, line);
		 		answer(this->token, call_id);
		 		this_thread::sleep_until(chrono::system_clock::now() + chrono::seconds(3));
		 		hangup(this->token, call_id);
            }
        }
        dial_file.close();
    }
   time_t t = time(nullptr);
   tm* now = localtime(&t);
   char buffer[80];
   strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", now);
/*   Glib::RefPtr<Gtk::GestureClick> refGesture = Gtk::GestureClick::create();
   refGesture->signal_pressed().connect(sigc::ptr_fun(&on_label_clicked));
   label_call_info.add_controller(refGesture);*/
   // Update call information label
   Gtk::Label* label_call_info = new Gtk::Label("Call to " + number_Entry.get_text() + " at " + buffer);
   this->m_VPBox.pack_start(*label_call_info, Gtk::PACK_SHRINK);
   (*label_call_info).signal_button_press_event().connect([this, label_call_info](GdkEventButton* event){return on_label_clicked(event, label_call_info);});
//   label_call_info->signal_button_press_event().connect([this, label_call_info](GdkEventButton* event);
   label_call_info->show();
}
