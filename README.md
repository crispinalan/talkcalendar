# Talk Calendar (Gtk4 Version)

Talk Calendar is a Linux personal desktop calendar with some integral speech capability.

## Important Note

**This is the Gtk4 version of Talk Calendar which uses an integral self contained speech generator licensed with the GNU Lesser General Public License version 2 or later. The license was chosen so as to be compatible with the [Gtk](https://www.gtk.org/) project. It will not compile against the Gtk3 libraries and does not use an external speech synthesiser to avoid any license compatibility issues.**

![](talkcalendar.png)

 
## Deployment

### Binary Image

A 64 bit binary image is available and can be downloaded from [bin-packages](https://github.com/crispinalan/talkcalendar/tree/main/bin-packages) and can be used with Linux distributions that have Gtk4 in their repositories such as Fedora 35, Debian Bookworm (in testing) and Ubuntu 21.10* etc. 

Assuming that the Gtk4 base libraries are installed the Talk Calendar binary can be run from the terminal using: 

```
./talkcalendar
```

Use a menu editor such as [MenuLibre](https://github.com/bluesabre/menulibre) to create a launcher for Talk Calendar. MenuLibre allows the working directory to be set as shown below.

![](menueditor.png)

Using the binary image with a menu editor is a universal approach for getting Talk Calendar installed on most Gtk4 distros.

*With Ubuntu 21.10 the base Gtk4 libraries can be installed using
```
sudo apt install libgtk-4-1
```
Alternatively, Talk Calendar can be built from source using the code in this repository. See notes below which explain how to do this.

### Working Directory 

Make sure that the <ins>talk</ins> directory containing the speech waveform files is located in working directory. If you do not set the a working directory it will most likely default to your home directory. The database called "eventsdb.csv" and the talk directory should be located in the working directory.

With Talk Calendar you can use the following menu item
 
```
Help->Information
```
to show the current working directory where both the speech engine and the events database should be located.

## Talk Calendar Usage

### Adding New Event

* Select event date using the calendar.
* Click the New button on the headerbar to invoke the "New Event" dialog.
* Enter the event title.
* Enter the location.
* Enter the **Event Type** such as "Birthday" which is used for speech.
* Enter start and end times. 
* Events are sorted by start time when displayed.
* A visual marker is placed on a day in the calendar which has an event.
* Navigate through the year using the calendar to add events.

![](new-event-dialog.png)


## Event Type Input

Entering an **Event Type** word or phrase is important as it is used by Talk Calendar for speech. Example single word event types include anniversary, birthday, dentist, doctor, sport, social etc.

The current list of event type words is:

allotment, anniversary, appointment, bank, bill, birthday; book, boxing, breakfast, business, car, Christmas ,church ,code, company, club, conference, database, day, dentist, development, diary, dinner, do, doctor, Easter, engagement, event, family, father's, film, friend's, funeral, garden, gala, general, go, graduation, gym, Halloween, hello, holiday, hospital, interview, leisure, lecture, Linux, lunch, meal, medical, meeting, mother's, music, party, payment, picnic, priority, project, pub, radio, religious, reminder, repeat, restaurant, school, seminar, service, shopping, social, software, sport, spring, subscription, teacher, team, theatre, to, travel, tutor, tv, university, valentine, walk, wedding, with, work, year plus days of week.

You can have any combination of words from the event type list such as:

```
Birthday Party
Sport Event
Company Meeting
```
More words will be added to the event type list over time as the project is developed further.

### Editing Existing Event

* Select the event in the list view and click the Edit button on the headerbar to edit.
* Change details as appropriate.

### Preferences

* Use the Preferences section in the hamburger menu to change options. 


### Font

With GNOME you change the desktop 'font-name' and 'document-font-name' using gsettings.

Cantarell is the default font supplied with GNOME since version 3.0. Fedora ships with 'Cantarell 11' as the default font. This can be checked using the following commands.

```
gsettings get org.gnome.desktop.interface font-name 
gsettings get org.gnome.desktop.interface document-font-name
```
Talk Calendar uses the default GNOME desktop font-name.

To change the desktop font to say 'Sans 11' you would use the following commands.
```
gsettings set org.gnome.desktop.interface document-font-name 'Sans 11'
gsettings set org.gnome.desktop.interface font-name 'Sans 11'
```

Talk Calendar allows the calendar font size to be changed using the Preferences Dialog. The actual size of the calendar font depends on the GNOME text scaling factor which can found using the following command.

```
gsettings get org.gnome.desktop.interface text-scaling-factor
```
For a larger font size, the text-scaling factor is typically set to 1.3 using the following command.
```
gsettings set org.gnome.desktop.interface text-scaling-factor 1.3
```

To reset the text scaling factor use.
```
gsettings reset org.gnome.desktop.interface text-scaling-factor
```

The current system desktop font, the GNOME text scaling factor and the Talk Calendar font size chosen by the user are shown in the information panel in the Help menu section.


### Help

* Use the Information dialog to display current application preferences.

![](information-dialog.png)

* Use the About dialog to display current version.


### Keyboard Shortcuts
```
Speak		Spacebar
Today		Home Key
About		<Ctrl>A
Version		<Ctrl>V
Quit		<Ctrl>Q
```

### Talk

* Enable talking in options (use the preferences menu item in the hamburger menu)
* Enable "Talk At Startup" in preferences to read out the date and event types for the current day when the calendar is started
* Click on a calendar date with events
* Press the spacebar to speak or use the speak menu item


### Calendar Settings

* Use the Calendar Settings item in the hamburger menu to change colour and border options for the current day (today), event days and holidays

![](calendar-colour-options.png)

![](colour-selector.png)

## Startup Applications

Add Talk Calendar to your start-up programs to read out events when the computer is switched on.

With the Gnome desktop use the Gnome "Tweak Tool" to add Talk Calendar to your startup applications.



## Build From Source

The C source code for Talk Calendar is provided in the src directory.

You need the Gtk4 development libraries and the gcc compiler. 

With Debian Bookworm you need to install the following packages

```
apt install build-essential
apt install libgtk-4-dev
apt install gtk-4-examples
apt install libglib2.0-dev
apt install alsa-utils
```
The packages:
```
apt install libglib2.0-dev
apt install alsa-utils
```
are needed but should be installed by default

With Fedora you need to install the following packages.

```
sudo dnf install gtk4-devel
sudo dnf install gtk4-devel-docs
sudo dnf install glib-devel
sudo dnf install alsa-lib-devel
```

I used Geany as the IDE for developing the project as it has an integrated terminal. 

Use the MAKEFILE to compile.


## Wayland

Talk Calendar has been tested with Fedora 35 GNOME using the Wayland display compositor.


## Core Features

* built with Gtk4.0
* event title, location, type, start and end time can be entered and edited
* bespoke month calendar which allows days with events to be colour marked
* priority events can be separately colour marked
* integral self contained speech generator
* bespoke flat-file csv database with memory dynamically allocated for up to 5000 records
* binary for 64-bit Gtk4 distributions 

### How is speech generated?

Speech is generated using a simple concatenation text-to-speech (TTS) system which is based on the concatenation of pre-recorded words stored as wav files. It has two main components. The first is a text scanner which reads the "event type"  input text string and extracts words found in the pre-recorded dictionary of keywords and stores these in an array list. The second is the audio player which plays the sequence of event type words stored in the array list using the pre-recordings.

With this approach, speech is limited by the number of words found in the dictionary of known words for event types. More words will be added to the dictionary as the project develops.

## Roadmap
```
code refactoring and enhancements 
improve audio latency and lock
improve concatenation and audio player code
add more event type words
add repeating yearly events
speak times
scan for upcoming events
```


## Versioning

[SemVer](http://semver.org/) is used for versioning. The version number has the form 0.0.0 representing major, minor and bug fix changes. 

## Author

* **Alan Crispin** [Github](https://github.com/crispinalan)

 
## License

GNU General Public Licence, version 2 or later (GPLv2+). 

## License Note

The Gtk4.0 GUI toolkit is licensed using LGPLv2.1.  Consequently, Talk Calendar has been licensed using the GNU Lesser General Public License version 2 or later to be compatible with Gtk.

When you combine software to produce a larger work both licenses should be compatible. This is relevant with regard to combining this software with an external speech synthesiser.  Open source licenses and their compatibility is disussed in this [article](https://janelia-flyem.github.io/licenses.html) and [here](https://www.gnu.org/licenses/gpl-faq.en.html). Some open source licences are not compatible with each other as discussed in this video [Compatibility in Open Source Licenses](https://www.youtube.com/watch?v=B0aMYeMv-8I) and so cannot be used together. This version of Talk Calendar does **not** use an external speech engine to avoid license incompatibility issues and uses it own voice, concatenation and audio player code.


## Acknowledgements

* [Gtk](https://www.gtk.org/)
* GTK is a free and open-source project maintained by GNOME and an active community of contributors. GTK is released under the terms of the [GNU Lesser General Public License version 2.1](https://www.gnu.org/licenses/old-licenses/lgpl-2.1.html).
* Gtk4 [manual](https://developer-old.gnome.org/gtk4/stable/).

* [Geany](https://www.geany.org/)
* Geany is a small and lightweight Integrated Development Environment which only requires the GTK+ runtime libraries. It has features including syntax highlighting, code completion, auto completion of often used constructs (e.g. if, for and while), code folding, embedded terminal emulation and extensibility through plugins. Geany uses the GPLv2 license. 


