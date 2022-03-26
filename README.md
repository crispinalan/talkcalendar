# Talk Calendar (Gtk4 Version)

## Preamble

Talk Calendar is a Linux personal desktop calendar with a tiny built-in speech synthesizer. This is the Gtk4 version of Talk Calendar and it will not compile against the Gtk3 libraries as there are many depreciations and other changes as outlined in the Gtk's migrating from 3 to 4 [article](https://docs.gtk.org/gtk4/migrating-3to4.html). My migration notes below outline the code changes that I had to make to use Gtk4.


![](talkcalendar.png)

 
## Deployment

### Binary Image

A 64 bit binary image is available and can be downloaded from [bin-image](https://github.com/crispinalan/talkcalendar/tree/main/bin-image) and can be used with Linux distributions that have Gtk4 in their repositories such as Fedora 35, Ubuntu 21.10 and Debian Bookworm (in testing) etc. 

Assuming that the Gtk4 base libraries are installed the Talk Calendar binary can be run from the terminal using: 

```
./talkcalendar
```

or double click on the talkcalendar file. Make sure it has executable permissions. Right click on it, then select permissions and ensure "Allow executing file as program" is selected. Audio output requires that the alsa-utils package is installed (this is usually installed by default).

Use a menu editor such as [MenuLibre](https://github.com/bluesabre/menulibre) to create a launcher for Talk Calendar. MenuLibre allows the working directory to be set as shown below. 

![](menueditor.png)

The database called "eventsdb.csv" is located in the working directory. With Talk Calendar you can use the following menu item
 
```
Help->Information
```
to show the current working directory where the events database should be located,

Using the binary image together with a menu editor is a universal approach for getting Talk Calendar installed on most Gtk4 distros.

### Working Directory 

Make sure that the **diphone** wav file directory (this stores the diphone sound files of short duration) is located in the working directory. The diphone directory can be found by downloading the binary image. If you do not set the a working directory it will most likely be your home directory. The database called "eventsdb.csv" will be located in the working directory.

Alternatively, Talk Calendar can be built from source using the code in this repository. See notes below which explain how to do this.

## Talk Calendar Usage

### Adding New Event

* Select event date using the calendar.
* Click the New button on the headerbar to invoke the "New Event" dialog.
* Enter the event title (words in speak directory can be read out).
* Enter the location.
* Enter start and end times. 
* Events are sorted by start time when displayed.
* A colour marker is placed on a day in the calendar which has an event.
* Navigate through the year using the calendar to add events.

![](talkcalendar-new-event.png)

## Event Title Speech 

Talk Calendar has a small dictionary of event orientated words which can be converted into speech for reading out the event title. The built-in speech synthesizer is used to create a spoken version of the title text. The current list of dictionary speech words is:


| Letter        | Dictionary Words  |
| ------------- | ------------- |
| A words:      | accounts, action, activity, agenda, agent, alert, allotment, ambulance, airport, and, anniversary, appointment, assessment, assets, assistant, award, away |
| B words:      | bank, banquet, barber, bill, birthday, book, builder, brother|
| C words:      | cancel, cancelled, car, calendar, caravan, card, celebrate, celebration, cermony, charity, check, christmas, clinic, code, computer,  cook, cooking, contact, credit, cricket, critical, cycle |
| D words:      | date, day, deadline, delivery, dentist, development, doctor |
| E words:      | easter, energy, entry, estate,  event, events |
| F words:      | family, father, fathers, film, food, football, friend, funeral |
| G words:      | garden, gas, go, good, grow |
| H words:      | hairdressers, health, heating, hello, high, house, holiday, home, hospital|
| I words:      | insurance, interview, investment, investments, invoice|
| J words:      | journey |
| L words:      | lecture, legal, letter, leisure, library, license, lift, linux, low, lunch|
| M words:      | many, match, meal, medical, meet, meeting, meetings, memo, memorandum,  milkman, mother, mothers, move, movie, music |
| N words:      | no, netflix |
| O words:      | online, occurrence, operation |
| P words:      | parcel, party, pay, payment, pension, personal, phone, picnic, plan, planning, plant, point, police, post, priority, project |
| Q words:      | quiz |
| R words:      | radio, red, remember, remembrance,  reminder, repair, restaurant |
| S words:      | seed, seeds, service, shares, shop, shopping, show, solicitor, sow, sowing, sister,  special, sport, station, stocks, supermarket, subscription, system|
| T words:      | tax, talk, tea, tearoom,  theatre, to, today, train, training, travel, television |
| U words:      | unknown, urgent|
| V words:      | vacation, vaccination, valentine, valentines, vehicle, virus, visa, visit, visitor, visitors |
| W words:      | walk, warning, weather, wedding, wibblewobble, wife, wind, work, workman,  world |
| Z words:      | zoo |

Combination of words from the dictionary are read out such as
```
birthday party
payment reminder
train station
house event
family visit
car tax payment
```
If a word is not recognised by the dictionary it is skipped over. For example, a title such as  "Tiki Birthday Party" would be read out as "birthday party". If none of the words in the event title are recognised then Talk Calendar reads outs "calendar entry". The speech dictionary will be expanded in future iterations of the project.


### Editing Existing Event

* Select the event in the list view and click the Edit button on the headerbar to edit.
* Change details as appropriate.

### Calendar Options

* Use the Calendar Options dialog in the hamburger menu to change calendar options 

![](calendar-options.png)

You can show public holidays on the calendar and event end-times in the list view. You can change the colours and borders of the current day (today), event days and public holidays. Days with high priority events can have a separate colour.

### Talk Options

* Use the Talk Options dialog in the hamburger menu to change talk options

![](talk-options.png)

Adjust the talk speaking rate to alter the delivery of the speech for best results.

### Talk

* Enable talking in Talk Options
* Enable "Talk At Startup" in Talk Options to read out the date and event details for the current day when the calendar is started
* Click on a calendar date with events
* Press the spacebar to speak or use the speak menu item  to read out selected event details.

### Help

* Use the Information dialog to display current application preferences including the current working directory in which the eventsdb.csv file is stored


* Use the About dialog to display current version.


### Keyboard Shortcuts
```
Speak		Spacebar
Today		Home Key
```

## Startup Applications

Add Talk Calendar to your start-up programs to read out events when the computer is switched on.

With the GNOME desktop use the GNOME "Tweak Tool" to add Talk Calendar to your startup applications.


## Build From Source

The C source code for Talk Calendar is provided in the src directory.

You need the Gtk4 development libraries and the gcc compiler. 

### Fedora

With Fedora you need to install the following packages.

```
sudo dnf install gtk4-devel
sudo dnf install gtk4-devel-docs
sudo dnf install glib-devel
sudo dnf install alsa-lib-devel
```

### Ubuntu (Debian Bookworm Testing) 


With both Ubuntu 21.10 and Debian Bookworm (in testing) and you need to install the following packages

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
are needed but should be installed by default. 

The base Gtk4 libraries are installed by default with Ubuntu 21.10. With other Ubuntu spins you may have to install the base Gtk libraries. These can be installed using the following command. 
```
sudo apt install libgtk-4-1
```

I used Geany as the IDE for developing the project as it has an integrated terminal. 

Use the MAKEFILE to compile.

### Font Note

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


## Wayland

Talk Calendar is being developed and tested using Fedora 35 GNOME using the Wayland display compositor and so far no problems have been detected with Wayland.


## Core Features

* built with Gtk4.0
* event title, location, type, start and end time can be entered and edited
* bespoke month calendar which allows days with events to be colour marked
* priority events can be separately colour marked
* integral speech synthesizer
* bespoke flat-file csv database with memory dynamically allocated for up to 5000 records
* binary for 64-bit Gtk4 distributions 

### How is speech generated?

Speech is generated using a diphone speech synthesizer. Words are formed as sequences of elementary speech units known as diphones (see history below).

## History

This is a hobby project under development. 

C++ and Qt were used to develop the original calendar project but when the Qt Company announced that the Qt LTS versions and the offline installer were to become commercial-only [Qt licensing changes](https://www.qt.io/blog/qt-offering-changes-2020) I decided to look for an alternative GUI toolkit. I found a good open source alternative to Qt called [CopperSpice](https://www.copperspice.com/). CopperSpice was derived from Qt 4.8 and is under the LGPL 2.1 license. It was considered but unfortuantely it is not widely available in Linux distribution repositories. For more details on the Qt license situation see the article entitled [The Qt Company Is Tomorrow Moving Qt 5.15 To Its Commercial-Only LTS Phase](https://www.phoronix.com/scan.php?page=news_item&px=Qt-5.15-LTS-Commercial-Phase). 


I decided to completely re-write the project code from scratch using the open source [Gtk](https://www.gtk.org/) toolkit as it is widely available in most Linux distribution repositories. It seemed to be very unlikely that the Gtk toolkit would change its license to become commercial-only. Moving from Qt to Gtk was a steep learning curve. 

The first iteration of the Talk Calendar project used Gtk3 but then migrated to the newer Gtk4 toolkit. See my migration notes below which may help if your are migrating a Gtk3 project to Gtk4. The Gtk4 Talk Calendar version uses a new bespoke flat-file csv database (rather than sqlite) with memory dynamically allocated for up to 5000 records. The database called "eventsdb.csv" should be located in the current working directory. 

Early versions of Talk Calendar used speech synthesizers available in Linux distributions (e.g. Flite and espeak) and installed using package managers. The big issue with using these external speech synthesizers was that different Linux distributions were using different versions. When you combine software to produce a larger work both licenses should be compatible. This is relevant with regard to combining Talk Calendar with an external speech synthesizer.  Open source licenses and their compatibility is discussed in this [article](https://janelia-flyem.github.io/licenses.html) and [here](https://www.gnu.org/licenses/gpl-faq.en.html).  Unbelievably, some open source licences are just not compatible with each other as discussed in this video [Compatibility in Open Source Licenses](https://www.youtube.com/watch?v=B0aMYeMv-8I) and so cannot be used together (e.g. the Apache 2.0 license is not compatible with the GPLv2 licenses). Talk Calendar now uses it own Gtk-based speech engine.

Talk Calendar version 1.2 used a built-in phoneme speech systhesis to create an artificial voice by means of concatenating phoneme wav files. A phoneme is the smallest unit of sound that distinguishes one word from another word and there are 44 phonemes in the English language.

With Talk Calendar 1.3 I experimented with a formant speech synthesiser but I could not get get statisfactory results in terms of audible speech. Consequently, I abandoned this whole approach. For anyone interested in formant speech synthesis I have put the development code on [github](https://github.com/crispinalan/formant-synthesizer).

Talk Calendar version 1.4 uses diphone speech synthesis vocalising speech by means of concatenating diphones. A diphone is a sound unit composed of two adjacent partial phonemes i.e. the second half of the first phoneme and the first half of the second phoneme.


## Gtk 4.0 Migration Notes

GTK 4 uses [list widgets](https://docs.gtk.org/gtk4/migrating-3to4.html#consider-porting-to-the-new-list-widgets) such as GtkListBox and porting the Gtk 3 version of Talk Calendar has involved replacing the display of events with a GtkListBox. A significant effort had to be invested into this aspect of the porting. There is an article on scalable lists in gtk4 [here](https://blog.gtk.org/2020/06/07/scalable-lists-in-gtk-4/). Gtk have said [publically](https://www.youtube.com/watch?v=qjF-VotgfeY&t=824s) that it is their intention to eventually replace GtkTreeView and GtkComboBox with [list widgets](https://blog.gtk.org/2020/06/08/more-on-lists-in-gtk-4/). The GtkListBox widget provides a vertical list and can be sorted (in this application events are sorted by start time and then displayed). The application workflow has had to be changed as headerbar buttons are now used to create a new event, edit and delete a selected event in the list. I have used buttons with text labels (New, Edit, Delete) but there is now an option for using Adwaita button icons. 

In Gtk4.0, the function 
```
gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
```
has been depreciated and so has had to be removed from the code. See this [discussion](https://discourse.gnome.org/t/how-to-center-gtkwindows-in-gtk4/3112).

In Gtk 4.0, the function
```
gtk_dialog_run() 
```

has been depreciated. This has been less of an issue as callback functions have been written for the “response” events. See this [discussion](https://discourse.gnome.org/t/how-should-i-replace-a-gtk-dialog-run-in-gtk-4/3501).

I could not place a visual marker on a particular GtkCalendar day using the "gtk_calendar_mark_day()" function. The [GtkInspector](https://wiki.gnome.org/action/show/Projects/GTK/Inspector?action=show&redirect=Projects%2FGTK%2B%2FInspector) debugging tool does not reveal any obvious CSS style theme option that should to be used to do this. Consequently, I have ended up writing a bespoke month calendar which allows days with events to be colour marked. 

The calendar has been developed using the Gtk4 grid layout [manager](https://docs.gtk.org/gtk4/class.Grid.html) which arranges child widgets in rows and columns. In this case the layout manager arranges buttons in a grid. Again a significant effort has had to be invested in this aspect of the porting.

The function "gtk_spin_button_set_text()" has gone. The documented approach for showing spin button [leading zeros](https://people.gnome.org/~ebassi/docs/_build/Gtk/4.0/signal.SpinButton.output.html) doesn't work with gtk4. Consequently, I have had to change the new and edit event dialogs. The spin boxes for the start and end times now accept floating point values which are now stored in the database as floating point values. I have also removed the priority combobox as comboboxes appear to be on the Gtk depreciation hit list (see list widget discussion above) and replaced it with a high prirority check button. 

Other depreciations include "gtk_application_set_app_menu()" as discussed [here](https://wiki.gnome.org/HowDoI/ApplicationMenu). The function "gtk_button_set_image()" has gone. In the context of menu development it can be replaced with "gtk_menu_button_set_icon_name()".


## Roadmap
```
rewrite dictionary mapping code
increase number of words in speech dictionary
feature enhancements
categories
code refactoring
upcoming events alert
```

## Versioning

[SemVer](http://semver.org/) is used for versioning. The version number has the form 0.0.0 representing major, minor and bug fix changes. 

## Author

* **Alan Crispin** [Github](https://github.com/crispinalan)

 
## License

GNU General Public Licence, Version 3. 

## License Note

The Gtk4.0 GUI toolkit is licensed using LGPLv2.1.  Consequently, Talk Calendar has been licensed using the GNU  General Public License.


## Acknowledgements

* [Gtk](https://www.gtk.org/)
* GTK is a free and open-source project maintained by GNOME and an active community of contributors. GTK is released under the terms of the [GNU Lesser General Public License version 2.1](https://www.gnu.org/licenses/old-licenses/lgpl-2.1.html).
* Gtk4 [manual](https://developer-old.gnome.org/gtk4/stable/).

* [Geany](https://www.geany.org/)
* Geany is a small and lightweight Integrated Development Environment which only requires the GTK+ runtime libraries. It has features including syntax highlighting, code completion, auto completion of often used constructs (e.g. if, for and while), code folding, embedded terminal emulation and extensibility through plugins. Geany uses the GPLv2 license.

* [Diphone Source and License](https://github.com/hypnaceae/DiphoneSynth/blob/master/diphones_license.txt)
* Diphone collection and synthesis Alan W. Black and Kevin Lenzo [2000](https://www.cs.cmu.edu/~awb/papers/ICSLP2000_diphone/index.html.)




