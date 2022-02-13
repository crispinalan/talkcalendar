# Talk Calendar (Gtk4 Version)

Talk Calendar is a Linux personal desktop calendar with some integral speech capability.

## Preamble

**This is the Gtk4 version of Talk Calendar which uses an integral self contained speech generator licensed with the GNU Lesser General Public License version 2 or later. The license was chosen so as to be compatible with the [Gtk](https://www.gtk.org/) project. It will not compile against the Gtk3 libraries and does not use an external speech synthesiser to avoid any license compatibility issues. See license note below.**

![](talkcalendar.png)

 
## Deployment

### Binary Image

A 64 bit binary image is available and can be downloaded from [bin-packages](https://github.com/crispinalan/talkcalendar/tree/main/bin-packages) and can be used with Linux distributions that have Gtk4 in their repositories such as Fedora 35, Debian Bookworm (in testing) and Ubuntu 21.10* etc. 

Assuming that the Gtk4 base libraries are installed the Talk Calendar binary can be run from the terminal using: 

```
./talkcalendar
```

Audio output requires that the alsa-utils package is installed. This is usually installed by default.


Use a menu editor such as [MenuLibre](https://github.com/bluesabre/menulibre) to create a launcher for Talk Calendar. MenuLibre allows the working directory to be set as shown below.

![](menueditor.png)

Using the binary image together with a menu editor is a universal approach for getting Talk Calendar installed on most Gtk4 distros.

*With Ubuntu 21.10 the base Gtk4 libraries can be installed using
```
sudo apt install libgtk-4-1
```
Alternatively, Talk Calendar can be built from source using the code in this repository. See notes below which explain how to do this.

### Working Directory 

Make sure that the <ins>talk</ins> directory containing the speech waveform files is located in the working directory. If you do not set the a working directory it will most likely default to your home directory. The database called "eventsdb.csv" and the talk directory should be located in the working directory.

With Talk Calendar you can use the following menu item
 
```
Help->Information
```
to show the current working directory where both the speech engine and the events database should be located with the correct permissions.

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


## Event Type Speech 

Entering an **Event Type** or category word is important as it is used by Talk Calendar for speech. Example single word event types include anniversary, birthday, dentist, doctor, sport, social etc.

The current list of event type words in the voice dictionary  is:


| Letter        | Words         |
| ------------- | ------------- |
| A words:      | allotment, anniversary, appointment, |
| B words:      | bank, bill, birthday; book, boxing, breakfast, business, |
| C words:      | car, Christmas ,church ,code, company, club, conference, |
| D words:      | database, daugther, day, dentist, development, diary, dinner, do, doctor, |
| E words:      | Easter, engagement, event, |
| F words:      | family, father's, film, food, friend's, funeral, |
| G words:      | garden, gala, general, go, graduation, gym, |
| H words:      | Halloween, hello, high, holiday, hospital, house |
| I words:      | interview, |
| L words:      | leisure, lecture, Linux, lunch, |
| M words:      | meal, medical, meeting, mother's, music, |
| P words:      | party, payment, personal, picnic, priority, project, pub, |
| R words:      | radio, religious, reminder, repeat, restaurant, |
| S words:      | school, seminar, service, shopping, social, software, son, special, sport, spring, station, subscription, |
| T words:      | teacher, team, theatre, to, train, travel, tutor, tv, |
| U words:      | university, |
| V words:      | valentine, version, visit, |
| W words:      | walk, wedding, with, work, |
| Y words:      | year |


You can have a combination of words from the event type list such as:

```
Birthday party
Personal event
Family visit
Sport meeting
Train station
Online Shopping
Bill Payment
```

Although the word voice dictionary is small it covers many personal event types. More voice words will be added  as the project is developed further.

### Editing Existing Event

* Select the event in the list view and click the Edit button on the headerbar to edit.
* Change details as appropriate.

### Preferences

* Use the Preferences section in the hamburger menu to change options such as talk, talk at startup, show public holidays, use adwaita icons etc.


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

Talk Calendar is being developed and tested using Fedora 35 GNOME using the Wayland display compositor and no problems have been detected with Wayland.


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

With this approach, speech is limited by the number of words found in the voice dictionary of known words for event types. More words will be added to the dictionary as the project develops.


## Issues

### Check Audio Playback (PipeWire ALSA)

Fedora 35 and other distros are now using a PipeWire ALSA backend. Pipewire is a multimedia routing layer which sits on top of the drivers that applications use. Talk Calendar uses the ALSA aplay command. Check that ALSA connects to Pipewire.

1. First check that PipeWire is enabled using 

```
systemctl --user enable --now wireplumber
```

2. Make sure the alsa-utils package is installed. For Fedora systems install the alsa-utils package using

```
sudo dnf install alsa-utils

```
For Gtk4 Debian based systems use

``` 
apt install alasa-utils
```
3. Finally test ALSA using the following

```
aplay -l
aplay -D sysdefault <your_test_audio_file.wav>
aplay -D pipewire <your_test_audio_file.wav>
```

The first command line lists all the sound devices known to ALSA. The second plays the audio test wav file (e.g. hello.wav) over the default device. The third line plays the audio file (wav) over the pipewire device. If all tests are successful then audio can be played using the aplay command and Talk Calendar.

### Corrupted Audio Files

Check that none of the audio wav files in the talk dictionary are corrupted.

## Roadmap
```
code refactoring and enhancements 
improve audio latency and lock
improve concatenator
add more event type words
event type auto-completion
event overlap alert
scan for upcoming events
repeating yearly events
```

## Versioning

[SemVer](http://semver.org/) is used for versioning. The version number has the form 0.0.0 representing major, minor and bug fix changes. 

## Author

* **Alan Crispin** [Github](https://github.com/crispinalan)

 
## License

GNU General Public Licence, version 2 or later (GPLv2+). 

## License Note

The Gtk4.0 GUI toolkit is licensed using LGPLv2.1.  Consequently, Talk Calendar has been licensed using the GNU Lesser General Public License version 2 or later to be compatible with Gtk.

When you combine software to produce a larger work both licenses should be compatible. This is relevant with regard to combining this software with an external speech synthesiser.  Open source licenses and their compatibility is discussed in this [article](https://janelia-flyem.github.io/licenses.html) and [here](https://www.gnu.org/licenses/gpl-faq.en.html).  Surprisingly some open source licences are just not compatible with each other as discussed in this video [Compatibility in Open Source Licenses](https://www.youtube.com/watch?v=B0aMYeMv-8I) and so cannot be used together. This version of Talk Calendar does **not** use an external speech engine to avoid license incompatibility issues and uses it own voice and audio concatenation code.

This is a hobby project. C++ and Qt were used to develop the original calendar project but when the Qt Company announced that the Qt LTS versions and the offline installer were to become commercial-only [Qt licensing changes](https://www.qt.io/blog/qt-offering-changes-2020) I decided to completely re-write the project code from scratch using the [Gtk](https://www.gtk.org/) toolkit. This was a steep learning curve. A good open source alternative to Qt for C++ GUI development is [CopperSpice](https://www.copperspice.com/). CopperSpice was derived from Qt 4.8 and is under the LGPL 2.1 license. For more details on the Qt license situation see the article entitled [The Qt Company Is Tomorrow Moving Qt 5.15 To Its Commercial-Only LTS Phase](https://www.phoronix.com/scan.php?page=news_item&px=Qt-5.15-LTS-Commercial-Phase).


## Acknowledgements

* [Gtk](https://www.gtk.org/)
* GTK is a free and open-source project maintained by GNOME and an active community of contributors. GTK is released under the terms of the [GNU Lesser General Public License version 2.1](https://www.gnu.org/licenses/old-licenses/lgpl-2.1.html).
* Gtk4 [manual](https://developer-old.gnome.org/gtk4/stable/).

* [Geany](https://www.geany.org/)
* Geany is a small and lightweight Integrated Development Environment which only requires the GTK+ runtime libraries. It has features including syntax highlighting, code completion, auto completion of often used constructs (e.g. if, for and while), code folding, embedded terminal emulation and extensibility through plugins. Geany uses the GPLv2 license.



