# Talk Calendar (Gtk4 Version)

Talk Calendar is a Linux desktop calendar with speech capability. 

![](talkcalendar-gtk4.png)

Talk Calendar is free and open source and built with [Gtk](https://www.gtk.org/). This is the Gtk4 version. It will NOT compile against the Gtk3 libraries as there are many depreciations and other changes as outlined in the migrating from 3 to 4 [article](https://docs.gtk.org/gtk4/migrating-3to4.html). A older gtk3 version of Talk Calendar can be found [here](https://gitlab.com/crispinalan/talkcalendar).

## Deployment

A 64 bit binary package developed and can be downloaded from [bin-packages](https://github.com/crispinalan/talkcalendar/tree/main/bin-packages). This has been tested using Fedora 34 and Debian Bookworm (testing) as these distributions have Gtk4 in their repositories. Alternatively, Talk Calendar can be built from source using the instructions below. 


Assuming Gtk 4 is installed the Talk Calendar binary can be run from the terminal using: 

```
./talkcalendar
```
You need to install the eSpeak speech synthesizer for audio output. 

With Fedora use

```
sudo dnf install espeak
```
With Debian (as superuser) use

```
apt install espeak
```

Check that the Talk Calendar binary has executable permissions. If not use 
```
chmod +x talkcalendar
```

Create a launcher (Mate desktop) to launch Talk Calendar and add Talk Calendar to your start-up programs to read out events when the computer is switched on.

## Usage

### Adding New Event

* Click the New button on the headerbar to invoke the "New Event" dialog.
* Enter the event title, description notes, start and end times etc.
* Events are sorted by start time when displayed.
* A visual marker is placed on a day in the calendar which has an event.
* Navigate through the year using the calendar to add events.

![](new-event-dialog.png)

### Editing Existing Event

* Select the event in the list view and click the Edit button on the headerbar to edit.
* Change details as appropriate.

### Preferences

* Use the Preferences section in the hamburger menu to change options. 

![](preferences-dialog.png)

* Use the Font dialog to change the application font size

![](font-dialog.png)

### Help

* Use the Information dialog to display app preferences

![](information-dialog.png)

* Use the About dialog to display current version

![](about-dialog.png)

### Keyboard Shortcuts
```
Speak		Spacebar
Today		Home Key
About		<Ctrl>A
Version     <Ctrl>V
Quit		<Ctrl>Q
```

### Talk

* Enable talking in options (use hamburger menu)
* Click on a calendar date with events
* Press the spacebar to speak 

## Debian Testing (Bookworm)

Talk Calendar has been tested with Debian Bookworm (testing) which has gtk4 in the respositories. A screenshot of Talk  Calendar running with Debian is shown below.

![](talkcalendar-gtk4-debian-bookworm.png)

You need to install the following packages.

```
apt install build-essential
apt install libgtk-4-dev
apt install gtk-4-examples
apt install espeak
```

The packages:
```
apt install libglib2.0-dev
apt install alsa-utils
```
are needed but should be installed by default



## Build From Source

The gtk4 source code for Talk Calendar is provided in the src directory.

You need the gtk4 development libraries and the gcc compiler. With Fedora you need to install the following packages.

```
sudo dnf install gtk4-devel
sudo dnf install gtk4-devel-docs
sudo dnf install glib-devel
sudo dnf install alsa-lib-devel
sudo dnf install espeak
```

With Debian Bookworm you need to install the following packages

```
apt install build-essential
apt install libgtk-4-dev
apt install gtk-4-examples
apt install espeak
apt install libglib2.0-dev
apt install alsa-utils
```

Compile with

```
gcc $(pkg-config --cflags gtk4) -o talkcalendar main.c $(pkg-config --libs gtk4) -lm

```

I used Geany as the IDE for developing the project as it has an integrated terminal. 


## Versioning

[SemVer](http://semver.org/) is used for versioning. The version number has the form 0.0.0 representing major, minor and bug fix changes. 

## Author

* **Alan Crispin** [Github](https://github.com/crispinalan)



## License

GNU General Public Licence, [Version 3](https://www.gnu.org/licenses/gpl-3.0.en.html). 


## Releases

Talk Calendar Gtk 4 Version 1.0.0
```
built with Gtk4.0
bespoke month calendar which allows days with events to be colour marked
gtk4 new listview used for displaying events
speak at startup option
font change option
flat-file csv database
binary for 64-bit distributions (tested with Fedora 34 Mate and Debian Bookworm Mate)
```

This is the first gtk4 version. Any bugs that arise will be fixed.

The database called events.csv has memory dynamically allocated for up to 5000 records. The database is located in the run directory and can be backed up by copying to another location.

Speech requires espeak to be install independently.



## Roadmap
```
more features and enhancements to be added
speech engine options
package installers (deb, rpm)
```

## Acknowledgements

* [Gtk](https://www.gtk.org/)
* GTK is a free and open-source project maintained by GNOME and an active community of contributors. GTK is released under the terms of the [GNU Lesser General Public License version 2.1](https://www.gnu.org/licenses/old-licenses/lgpl-2.1.html).

* [Geany](https://www.geany.org/)
* Geany is a small and lightweight Integrated Development Environment which only requires the GTK+ runtime libraries. It has features including syntax highlighting, code completion, auto completion of often used constructs (e.g. if, for and while), code folding, embedded terminal emulation and extensibility through plugins. Geany uses the GPLv2 license. 

* [eSpeak](http://espeak.sourceforge.net/)
* eSpeak is a software speech synthesizer for English, and some other languages. eSpeak uses a "formant synthesis" method. eSpeak uses the GPLv3 [license](https://www.gnu.org/licenses/gpl-3.0.en.html).



