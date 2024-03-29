build:
	g++ -g main_gtk.cpp hangup/hangup.cpp dial/dial.cpp answer/answer.cpp loginwindow.cpp mainwindow.cpp `pkg-config --libs --cflags libcurl gtkmm-3.0 ayatana-appindicator3-0.1 dbusmenu-gtk3-0.4` -o webex_phc

debug:
	g++ -g main.cpp hangup/hangup.cpp dial/dial.cpp answer/answer.cpp `pkg-config --libs --cflags libcurl` -o test

windows:
	i686-w64-mingw32-g++ -fPIC -static -static-libgcc -static-libstdc++ main.cpp hangup/hangup.cpp dial/dial.cpp answer/answer.cpp `pkg-config --static --libs --cflags libcurl` -o webex_auto_dialer.exe

clean:
	rm test webex_phc
