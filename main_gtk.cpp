#include "loginwindow.h"
#include "mainwindow.h"

void on_quit_clicked(void) 
{
    g_print("Quitting!\n");
	Gtk::Main::quit();	
}

int main(int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

  // Create a new AppIndicator
  AppIndicator *indicator = app_indicator_new("webex_phc-icon", "org.webex.WEBEX_PHC-status", APP_INDICATOR_CATEGORY_APPLICATION_STATUS);
  app_indicator_set_status(indicator, APP_INDICATOR_STATUS_ACTIVE);
  app_indicator_set_title(indicator,"Webex Phone Control");
  app_indicator_set_icon(indicator, "org.webex.WEBEX_PHC-status");

  // Set up a menu
  auto menu = Gtk::manage(new Gtk::Menu());

  // Add menu items
  auto menu_item_quit = Gtk::manage(new Gtk::MenuItem("Quit Webex Phone Control"));

  // Set the size request of the scale widget
  menu_item_quit->set_size_request(50, 0);  // Set the width to 50 pixels, and let GTK determine the height automatically
  menu->append(*menu_item_quit); // Append the menu item to the menu
  menu_item_quit->signal_activate().connect(sigc::ptr_fun(on_quit_clicked));
  menu->show_all();
  // Set the menu for the indicator
  app_indicator_set_menu(indicator, menu->gobj());

  LoginWindow login_window;
  string token = "YzM2OTAzNjItYjE1NS00ZWU4LTg2MGUtOWYyYzk0MTFiMGEyMDgzOGVmNDQtYjdk_PF84_43f0f16a-8814-4d73-905f-ef9df603ef61";
  MainWindow main_window(token);

  //Shows the window and returns when it is closed.
  return app->run(main_window);
//  return app->run(login_window);
}
