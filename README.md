# Talk Calendar

Talk Calendar is a Linux desktop calendar with speech capability. 

![](talkcalendar.png)

Talk Calendar is free and open source and built with [Gtk](https://www.gtk.org/). It can be run by using the Debian binary  provided. Talk Calendar has been designed with assistive technologies in mind. This not only includes providing speech capability but also allowing the system font size to be overridden to enlarge text when needed.

## Deployment

A binary package for 64-bit Debian based distributions can be downloaded from [bin-packages](https://github.com/crispinalan/talkcalendar/tree/main/bin-packages).  Alternatively, Talk Calendar can be built from source using the instructions below. 

To run Talk Calendar from the terminal use: 

```
./talkcalendar
```

Create a launcher (Mate desktop) or use a menu editor (Cinnamon desktop) to launch Talk Calendar and add Talk Calendaer to your start-up programs to read out events when the computer is switched on.

Talk Calendar has been tested using the following 64-bit distributions.
```
Debian 11 (Bullseye) Mate Edition
Ubuntu Mate (Focal Fossa 20.04.3 LTS)
Linux Mint 20.2 Cinnamon Edition  
```

<ins>Note: </ins> If ./talkcalendar fails to run check that the Talk Calendar binary has read, write and executable permissions and if necessary change permissions using chmod (e.g. chmod +rwx filename). Speech requires the libraries libflite1 and libasound2 which should be installed by default on a fresh Debian 11 install. If not install these libraries.


## Usage

### Adding New Event

* Double click on a date in the calendar to invoke the "New Event" dialog.
* Enter the event title, description notes, start and end times, repeat etc.
* Events are sorted by start time when displayed in the side day page view.
* A visual marker is placed on a day in the calendar which has an event.
* Navigate through the year using the calendar to add events.

![](talkcalendar-new-event.png)

### Editing Existing Event

* Double click the event in the title list below the calendar to edit.
* Change details as appropriate.

### Preferences

* The options dialog can be accessed from the Edit menu.

### Keyboard Bindings

* key_spacebar = speak
* key_home = return to today (current date)

### Talk

* Enable talking in options 
* Click on a calendar date
* Select Menu->Tools->Talk Selected Date 
* Alternatively just press the spacebar to speak 

### Set Alarm
* Select Menu->Tools->Set Alarm

## Build From Source

The Talk Calendar source code is provided in the src directory.

You need the following dependencies:

```
sudo apt install build-essential
sudo apt install libgtk-3-dev
sudo apt install libsqlite3-dev
sudo apt install meson
sudo apt install ninja-build
sudo apt install flite1-dev
sudo apt install libasound2-dev
sudo apt install libnotify-dev 
```
The [meson](https://mesonbuild.com/Quick-guide.html) build system is used. At the top level directory the build steps are:
```
meson build  (run once only)
ninja -C build
```


I used Geany as the IDE for developing the project as it has an integrated terminal and other features helpful for coding a Gtk3.0 project (see below). 

The Gtk3.0 reference manual can be viewed locally on a Linux computer using a program called Devhelp. Devhelp is a tool for browsing and searching Gtk API documentation. Having a local copy of the Gtk help documentation is very helpful when developing an application.

```
sudo apt install devhelp
```
## Versioning

[SemVer](http://semver.org/) is used for versioning. The version number has the form 0.0.0 representing major, minor and bug fix changes. 

## Author

* **Alan Crispin** [Github](https://github.com/crispinalan)



## License

GNU General Public Licence, version 2 or later. [License](https://www.gnu.org/licenses/old-licenses/gpl-2.0.html).

## License Note

As I am using the Gtk 3.0 GUI toolkit which is licensed using LGPLv2.1 then this license (or the equivalent GPLv2) should be used for the project (like the Geany project). Consequently, the project has been licensed using the same GNU Lesser General Public License version 2 or later to be compatible with Gtk.  

When you combine software to produce a larger work both licenses should be compatible. This is relevant with regard to combining this software with an external speech synthesiser library.  Open source licenses and their compatibility is disussed in this [article](https://janelia-flyem.github.io/licenses.html).

The Pico speech synthesizer uses the Apache 2.0 license and this is not compatible with the GPLv2 licenses as discussed in this video [Compatibility in Open Source Licenses](https://www.youtube.com/watch?v=B0aMYeMv-8I). It explains that the Apache 2.0 license is compatible with just about everything except GPLv2 and LGPLv2.1 because it contains certain patent provisions that are inconsistent with these licenses. In fact the SVOX Pico speech synthesizer (libttspico-utils package) is in the Debian non-free archive which is not installed by default.  Debian say "The non-free archive area contains supplemental packages intended to work with the Debian distribution that do not comply with the DFSG* or have other problems that make their distribution problematic". 

The eSpeak speech synthesiser is licensed under GPLv3 which is not compatible with GPLv2. 

The flite speech sythesiser has a BSD-like [license](https://github.com/festvox/flite/blob/master/COPYING) and is an official Debian package and labeled [DFGS free](https://blends.debian.org/accessibility/tasks/speechsynthesis). The BSD license is compatible with just about everything [Compatibility in Open Source Licenses](https://www.youtube.com/watch?v=B0aMYeMv-8I).

DFGS = Debian Free Software Guidelines 

## Releases

Talk Calendar Version 1.1
```
built with Gtk3.0
uses own internal word concatenation speech synthesiser
sqlite used to store events locally
speaks date, event title keywords and priority 
options to change speak preferences
speak at startup option
keyboard bindings key_spacebar (speak) and key_home (today)
export events as csv file
import events from csv file
meson build system
binary for 64-bit Debian based distributions
```

Talk Calendar Version 1.2
```
built with Gtk3.0
option to change font family and font size
option to talk event start-time
clock
clock talk alarm
clock alarm notification 
binary for 64-bit Debian based distributions
```
Talk Calendar Version 1.3
```
built with Gtk3.0
replaced internal speech generator with Flite
internal code changes
binary for 64-bit Debian based distributions
```

## Roadmap
```
review user interface
deb package installer
migrate to using Gtk4 (longer term goal)
```
## Project History

C++ and Qt were used to develop the original calendar diary project but when the Qt Company announced that Qt LTS versions and the offline installer were to become commercial-only [Qt licensing changes](https://www.qt.io/blog/qt-offering-changes-2020) I decided to completely re-write the project code from scratch by researching and using alternative GUI tool kits  such as [Gtk](https://docs.gtk.org/gtk3/). The Gtk3 package contains libraries used for creating graphical user interfaces for applications and is available in most Linux distributions (Debian, Ubuntu etc.)  It seemed to be the best alternative to Qt for open source Linux development and so the old Qt Diary project has been removed and replaced with this new Gtk project called Talk Calendar.

The internal word concatenation based speech engine which had limited scope has been replaced with the Flite speech synthesis system since version 1.3. 


## Acknowledgements

* [Gtk](https://www.gtk.org/)
* GTK is a free and open-source project maintained by GNOME and an active community of contributors. GTK is released under the terms of the [GNU Lesser General Public License version 2.1](https://www.gnu.org/licenses/old-licenses/lgpl-2.1.html).

* [Geany](https://www.geany.org/)
* Geany is a small and lightweight Integrated Development Environment which only requires the GTK+ runtime libraries. With most Linux distrbutions Geany can be installed via the package manager. Alternatively it can be installed from source using the autotools based build system [Geany autotools build](https://www.geany.org/manual/current/#source-compilation). 
* It has features including syntax highlighting, code completion, auto completion of often used constructs (e.g. if, for and while), code folding, embedded terminal emulation and extensibility through plugins. The Geany IDE uses "tags" files for its autocompletion [tags](https://wiki.geany.org/tags/start). With Linux, these tag files (e.g. the gtk tag file) are copied to the config directory (./config/geany/tags/) to enable code completion. Geany uses the GPLv2 license. 

* [Sqlite](https://www.sqlite.org/index.html)
* SQLite is an in-process library that implements a self-contained, serverless, zero-configuration, transactional SQL database engine. SQLite.org say that: "SQLite is in the public domain and does not require a [license](https://www.sqlite.org/copyright.html)".

* [Alsa](https://www.alsa-project.org/wiki/Main_Page) 
* The Advanced Linux Sound Architecture (ALSA) provides audio and MIDI functionality to the Linux operating system. ALSA is  released under GPL-2.0-or-later and LGPL-2.1-or-later.  ALSA driver code is included in the  Linux kernel since 2.6.

* [Flite](http://www.festvox.org/flite/)
* Flite (festival-lite) is a small fast portable speech synthesis system developed from research at the Carnegie Mellon Univerity and the University of Edinburgh. Details of the latest Debian packages can be found on the Bullseye package [page](https://packages.debian.org/source/bullseye/flite).  The latest C source code is on [github](https://github.com/festvox/flite). Flite is free software and the core code has a BSD-like [license](https://github.com/festvox/flite/blob/master/COPYING). It is an official Debian package and labeled [DFGS free](https://blends.debian.org/accessibility/tasks/speechsynthesis).




