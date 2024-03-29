# Webex Phone Control
A tool for remotely dialling/controlling Cisco Webex Phones on Linux. Similar to Jabber CTI Control of Cisco IP Phones.
-- How to Use --
Currently you need to login to the Cisco Webex Developer website and generate a token which is valid for 24 hours. The token gets pasted into the application and you can then dial calls. A call log is generated and displayed when the program is run.
-- Caveats --
- Manual Token Generation is a bit annoying.
- The Call Log isn't saved.

## Building
Compile using g++, requires libcurl, gtkmm-3.0, ayatana-appindicator3-0.1, dbusmenu-gtk3-0.4
