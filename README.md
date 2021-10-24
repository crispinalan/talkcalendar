# Talk Calendar (Gtk4 Version)

Talk Calendar is a Linux desktop calendar with speech capability. 

![](talkcalendar-gtk4.png)

Talk Calendar is free and open source and built with [Gtk](https://www.gtk.org/). This is the Gtk4 version. It will NOT compile against the Gtk3 libraries as there are many depreciations and other changes as outlined in the migrating from 3 to 4 [article](https://docs.gtk.org/gtk4/migrating-3to4.html). A older gtk3 version of Talk Calendar can be found [here](https://gitlab.com/crispinalan/talkcalendar).

## Deployment

A binary package developed using 64-bit Fedora 34 Mate spin can be downloaded from [bin-packages](https://github.com/crispinalan/talkcalendar/tree/main/bin-packages).  Alternatively, Talk Calendar can be built from source using the instructions below. Check that gtk4 is installed (use dnf list installed). If not then install using

```
sudo dnf install gtk4-devel
```

To run Talk Calendar from the terminal use: 

```
./talkcalendar
```
You need to install the eSpeak speech synthesizer for audio output. 

With Fedora use

```
sudo dnf install espeak
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


## Build From Source

The gtk4 source code for Talk Calendar is provided in the src directory.

You need the gtk4 development libraries and the gcc compiler.

```
sudo dnf install gtk4-devel
sudo dnf install gtk4-devel-docs
sudo dnf install glib-devel
sudo dnf install espeak
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
binary for 64-bit Fedora 34 Mate
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



