/***************************************************************************
 GPL v2.0 license (see license document distributed with this software)
 Author: crispinalan@gmail.com
 ***************************************************************************/


#ifndef EVENT_H
#define EVENT_H

//Event structure

struct _Event {
	int id;
	char title[31]; //title strings can have up to 30 characters (plus one for null terminator)
	int priority;
	char description[1001]; //description strings can be up to 1000 chars
	int year;
	int month;
	int day;
	int startHour;
	int startMin;
	int endHour;
	int endMin;
	int isYearly;
	int isAllday;
	
};

typedef struct _Event Event; //nickname

#endif
