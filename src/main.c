/*
 * main.c
 * 
 * Copyright 2022 Alan Crispin <crispinalan@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3 of the License.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

/*
 * Use MAKEFILE to compile 
 * 
*/

#include <gtk/gtk.h>
#include <glib/gstdio.h>  //needed for g_mkdir
#include <math.h>  //compile with -lm

#include "diphone.h"
#include "wavcat.h"
#include "dictionary.h"



#define CONFIG_DIRNAME "talkcal-gtk"
#define CONFIG_FILENAME "talkcal-gtk-config-1-4"

static GMutex lock;

//declarations
static void update_calendar(GtkWindow *window);
static void update_header (GtkWindow *window);
static GtkWidget *create_widget (gpointer item, gpointer user_data);
static void update_store(int m_year,int m_month,int m_day);
static void update_marked_dates(int month, int year);
static void reset_marked_dates();
static void update_priority_dates(int month, int year);
static void reset_priority_dates();
int compare (const void * a, const void * b);
gboolean check_day_events_for_overlap();

void load_csv_file();
gchar* get_css_string();
GDate* calculate_easter(gint year);
gboolean check_day_events_for_overlap();

//speaking

static gpointer thread_playwav(gpointer user_data);
GList* convert_date_to_weekday_diphone_list(int day, int month, int year);
GList* convert_day_number_to_diphone_list(int day_number);
GList* convert_month_to_diphone_list(int month);
GList* get_event_number_diphone_list(int event_number);

GList* convert_month_to_phoneme_list(int month);
GList* convert_date_to_weekday_phoneme_list(int day, int month, int year);


//Event Dialogs
static void callbk_check_button_allday_toggled (GtkCheckButton *check_button, gpointer user_data);
static void callbk_new_event_response(GtkDialog *dialog, gint response_id,  gpointer  user_data);
static void callbk_new_event(GtkButton *button, gpointer  user_data);
void callbk_edit_event_response(GtkDialog *dialog, gint response_id,  gpointer  user_data);
static void callbk_edit_event(GtkButton *button, gpointer  user_data);

//Actions

static void speak_events();
static void callbk_speak(GSimpleAction* action, GVariant *parameter,gpointer user_data);
static void callbk_speak_version(GSimpleAction* action,G_GNUC_UNUSED  GVariant *parameter,gpointer user_data);
static void callbk_about(GSimpleAction* action, GVariant *parameter, gpointer user_data);
static void callbk_home(GSimpleAction* action, GVariant *parameter, gpointer user_data);
static void callbk_info(GSimpleAction *action, GVariant *parameter,  gpointer user_data);
static void callbk_shortcuts(GSimpleAction * action, GVariant *parameter, gpointer user_data);
static void callbk_quit(GSimpleAction* action,G_GNUC_UNUSED GVariant *parameter, gpointer user_data);
static void callbk_delete_selected(GtkButton *button, gpointer  user_data);

static void set_today_button_colour(GtkButton *button);
static void set_event_button_colour(GtkButton *button);
static void set_holiday_button_colour(GtkButton *button);


//notifications
static void show_notification(gchar *message); 

//config
static char * m_config_file = NULL;

static int m_font_size=20;
static int m_holidays=0; //show holidays
static int m_show_end_time=0; //show end_time
static int m_startup_notification=0;
static int m_use_adwaita_icons=0;

static int m_talk =1;
static int m_talk_at_startup =1;
static int m_talk_event_number=1;
static int m_talk_title=1;
static int m_talk_notes=0;
static int m_talk_time=0;
static int m_talk_overlap=0;
static int m_talk_reset=0;

static int m_talk_sample_rate=16000; //sample speed

static int m_frame =0; //force buttons to have no frame

//calendar config
static float m_today_red =0.0;
static float m_today_green =0.0;
static float m_today_blue =0.0;
static float m_today_bg_red =0.59;
static float m_today_bg_green =0.98;
static float m_today_bg_blue =0.59;
static int m_today_frame =1;

static float m_event_red =0.0;
static float m_event_green =0.0;
static float m_event_blue =0.0;
static float m_event_bg_red =1.0;
static float m_event_bg_green =0.8;
static float m_event_bg_blue =0.8;
static int m_event_frame =1;

static float m_holiday_red =0.0;
static float m_holiday_green =0.0;
static float m_holiday_blue =0.0;
static float m_holiday_bg_red =1.0;
static float m_holiday_bg_green =1.0;
static float m_holiday_bg_blue =0.7;
static int m_holiday_frame =1;


static float m_priority_red =0.0;
static float m_priority_green =0.0;
static float m_priority_blue =0.0;
static float m_priority_bg_red =1.0;
static float m_priority_bg_green =0.0;
static float m_priority_bg_blue =0.4;
static int m_priority_frame =1;

static int m_colour_reset =0;

static int m_today_year=0;
static int m_today_month=0;
static int m_today_day=0;

static int m_row_index=-1; //selection index

static char * m_error ="";
static int m_error_flag=0;
//event variables
static const char* m_title ="title";
static const char* m_notes ="";
static int m_year=0;
static int m_month=0;
static int m_day=0;
static float m_start_time=0.0;
static float m_end_time=0.0;

static GListStore *m_store;

static int m_id_selection=-1;

typedef struct {
	int id;	
	char title[101];
	char notes[201];	
	int year;
	int month;
	int day;
	float start_time;
	float end_time;	
	int priority;
	int is_yearly;
	int is_allday;
} Event;

int max_records=5000;
Event *db_store=NULL; 

int m_db_size=0;
int marked_date[31]; //month days with events
int priority_date[31]; //month days with high priority
int num_marked_dates = 0;
int num_priority_dates = 0;

//---------------------------------------------------------------------
// map  actions to callbacks

const GActionEntry app_actions[] = { 
  { "speak", callbk_speak },  
  { "home", callbk_home} ,
  { "f1", callbk_shortcuts},
  { "f12", callbk_info}   
};

//--------------------------------------------------------------------
// DisplayObject functions
//--------------------------------------------------------------------
enum
{
  
  PROP_LABEL = 1, //Prop label must start with 1
  PROP_ID,  
  PROP_STARTTIME, //for sorting
  LAST_PROPERTY //the size of the GParamSpec properties array
};

static GParamSpec *properties[LAST_PROPERTY] = { NULL, };

typedef struct
{
  GObject parent; //inheritance i.e. parent is a GObject 
  //fields
  char *label; //label to be displayed in listview
  int id; //id  
  int starttime;  //for sorting
  
} DisplayObject;


typedef struct
{
  GObjectClass parent_class;
} DisplayObjectClass;

//declaring a GType
static GType display_object_get_type (void);
//------------------------------------------------------------------
static void config_load_default()
{		
	
	m_talk=1;
	m_talk_at_startup=1;
	m_talk_event_number=1;
	m_talk_title=1;	
	m_talk_time=0;
	m_talk_notes=0;		
	m_talk_overlap=0;
	
	m_talk_sample_rate=16000;
	
	
	m_startup_notification=0;
	m_font_size=20; 	
	m_holidays=0;
	m_show_end_time=0;	
	m_use_adwaita_icons=0;	
	
	m_today_red =0.0;
	m_today_green =0.0;
	m_today_blue =0.0;
	m_today_bg_red =0.59;
	m_today_bg_green =0.98;
	m_today_bg_blue =0.59;
	m_today_frame =1;
	
	m_event_red =0.0;
	m_event_green =0.0;
	m_event_blue =0.0;
	m_event_bg_red =1.0;
	m_event_bg_green =0.8;
	m_event_bg_blue =0.8;
	m_event_frame =1;
	
	m_holiday_red =0.0;
	m_holiday_green =0.0;
	m_holiday_blue =0.0;
	m_holiday_bg_red =1.0;
	m_holiday_bg_green =1.0;
	m_holiday_bg_blue =0.7;
	m_holiday_frame =1;
	
	m_priority_red =0.0;
	m_priority_green =0.0;
	m_priority_blue =0.0;
	m_priority_bg_red =1.0;
	m_priority_bg_green =0.0;
	m_priority_bg_blue =0.4;
	m_priority_frame =1;
	
	m_colour_reset =0; 
}

static void config_read()
{
	// Clean up previously loaded configuration values	
	m_talk=1;
	m_talk_at_startup=1;
	m_talk_event_number=1;
	m_talk_title=1;	
	m_talk_time=0;
	m_talk_notes=0;		
	m_talk_overlap=0;
	m_talk_sample_rate=16000;
		
	m_startup_notification=0;
	m_font_size=20; 	
	m_holidays=0;
	m_show_end_time=0;	
	m_use_adwaita_icons=0;		
	
	m_today_red =0.0;
	m_today_green =0.0;
	m_today_blue =0.0;
	m_today_bg_red =0.59;
	m_today_bg_green =0.98;
	m_today_bg_blue =0.59;
	m_today_frame =1;
	
	m_event_red =0.0;
	m_event_green =0.0;
	m_event_blue =0.0;
	m_event_bg_red =1.0;
	m_event_bg_green =0.8;
	m_event_bg_blue =0.8;
	m_event_frame =1;
	
	m_holiday_red =0.0;
	m_holiday_green =0.0;
	m_holiday_blue =0.0;
	m_holiday_bg_red =1.0;
	m_holiday_bg_green =1.0;
	m_holiday_bg_blue =0.7;
	m_holiday_frame =1;
	
	m_priority_red =0.0;
	m_priority_green =0.0;
	m_priority_blue =0.0;
	m_priority_bg_red =1.0;
	m_priority_bg_green =0.0;
	m_priority_bg_blue =0.4;
	m_priority_frame =1;
	
	m_colour_reset =0; 
	
	// Load keys from keyfile
	GKeyFile * kf = g_key_file_new();
	g_key_file_load_from_file(kf, m_config_file, G_KEY_FILE_NONE, NULL);
	//talk
	m_talk = g_key_file_get_integer(kf, "calendar_settings", "talk", NULL);
	m_talk_at_startup=g_key_file_get_integer(kf, "calendar_settings", "talk_startup", NULL);
	m_talk_event_number=g_key_file_get_integer(kf, "calendar_settings", "talk_event_number", NULL);	
	m_talk_title=g_key_file_get_integer(kf, "calendar_settings", "talk_title", NULL);	
	m_talk_notes=g_key_file_get_integer(kf, "calendar_settings", "talk_notes", NULL);
	m_talk_time=g_key_file_get_integer(kf, "calendar_settings", "talk_time", NULL);	
	m_talk_overlap = g_key_file_get_integer(kf, "calendar_settings", "talk_overlap", NULL);
	m_talk_sample_rate = g_key_file_get_integer(kf, "calendar_settings", "talk_sample_rate", NULL);
			
	
	//calendar
	m_holidays = g_key_file_get_integer(kf, "calendar_settings", "holidays", NULL);	
	m_show_end_time = g_key_file_get_integer(kf, "calendar_settings", "show_end_time", NULL);				
	m_startup_notification=g_key_file_get_integer(kf, "calendar_settings", "startup_notification", NULL);	
	m_font_size=g_key_file_get_integer(kf, "calendar_settings", "font_size", NULL);
	m_use_adwaita_icons=g_key_file_get_integer(kf, "calendar_settings", "adwaita_icons", NULL);	
	//colours
	m_today_red =g_key_file_get_double (kf, "calendar_settings", "today_red", NULL);
	m_today_green =g_key_file_get_double (kf, "calendar_settings", "today_green", NULL);
	m_today_blue =g_key_file_get_double (kf, "calendar_settings", "today_blue", NULL);   
	m_today_bg_red =g_key_file_get_double (kf, "calendar_settings", "today_bg_red", NULL);
	m_today_bg_green =g_key_file_get_double (kf, "calendar_settings", "today_bg_green", NULL);
	m_today_bg_blue =g_key_file_get_double (kf, "calendar_settings", "today_bg_blue", NULL);   
	
	m_today_frame =g_key_file_get_integer(kf, "calendar_settings", "today_frame", NULL); 
	
	m_event_red =g_key_file_get_double (kf, "calendar_settings", "event_red", NULL);
	m_event_green =g_key_file_get_double (kf, "calendar_settings", "event_green", NULL);
	m_event_blue =g_key_file_get_double (kf, "calendar_settings", "event_blue", NULL);  
	m_event_bg_red =g_key_file_get_double (kf, "calendar_settings", "event_bg_red", NULL);
	m_event_bg_green =g_key_file_get_double (kf, "calendar_settings", "event_bg_green", NULL);
	m_event_bg_blue =g_key_file_get_double (kf, "calendar_settings", "event_bg_blue", NULL);   
	
	m_event_frame =g_key_file_get_integer(kf, "calendar_settings", "event_frame", NULL);
	
	m_holiday_red =g_key_file_get_double (kf, "calendar_settings", "holiday_red", NULL);
	m_holiday_green =g_key_file_get_double (kf, "calendar_settings", "holiday_green", NULL);
	m_holiday_blue =g_key_file_get_double (kf, "calendar_settings", "holiday_blue", NULL);
	m_holiday_bg_red =g_key_file_get_double (kf, "calendar_settings", "holiday_bg_red", NULL);
	m_holiday_bg_green =g_key_file_get_double (kf, "calendar_settings", "holiday_bg_green", NULL);
	m_holiday_bg_blue =g_key_file_get_double (kf, "calendar_settings", "holiday_bg_blue", NULL);
	
	m_holiday_frame =g_key_file_get_integer(kf, "calendar_settings", "holiday_frame", NULL);  
	
	m_priority_red =g_key_file_get_double (kf, "calendar_settings", "priority_red", NULL);
	m_priority_green =g_key_file_get_double (kf, "calendar_settings", "priority_green", NULL);
	m_priority_blue =g_key_file_get_double (kf, "calendar_settings", "priority_blue", NULL);
	m_priority_bg_red =g_key_file_get_double (kf, "calendar_settings", "priority_bg_red", NULL);
	m_priority_bg_green =g_key_file_get_double (kf, "calendar_settings", "priority_bg_green", NULL);
	m_priority_bg_blue =g_key_file_get_double (kf, "calendar_settings", "priority_bg_blue", NULL);
	
	m_priority_frame =g_key_file_get_integer(kf, "calendar_settings", "priority_frame", NULL);  
		
	g_key_file_free(kf);	
	
}

void config_write()
{
	
	GKeyFile * kf = g_key_file_new();
	
	//talk	
	g_key_file_set_integer(kf, "calendar_settings", "talk", m_talk);
	g_key_file_set_integer(kf, "calendar_settings", "talk_startup", m_talk_at_startup);
	g_key_file_set_integer(kf, "calendar_settings", "talk_event_number", m_talk_event_number);	
	g_key_file_set_integer(kf, "calendar_settings", "talk_title", m_talk_title);
	g_key_file_set_integer(kf, "calendar_settings", "talk_time", m_talk_time);
	g_key_file_set_integer(kf, "calendar_settings", "talk_notes", m_talk_notes);		
	g_key_file_set_integer(kf, "calendar_settings", "talk_overlap", m_talk_overlap);
	g_key_file_set_integer(kf, "calendar_settings", "talk_sample_rate", m_talk_sample_rate);
		
	//calendar
	g_key_file_set_integer(kf, "calendar_settings", "holidays", m_holidays);
	g_key_file_set_integer(kf, "calendar_settings", "show_end_time", m_show_end_time);	
	g_key_file_set_integer(kf, "calendar_settings", "startup_notification", m_startup_notification);
	g_key_file_set_integer(kf, "calendar_settings", "font_size", m_font_size);
	g_key_file_set_integer(kf, "calendar_settings", "adwaita_icons", m_use_adwaita_icons);		
	//colours
	g_key_file_set_double(kf, "calendar_settings", "today_red", m_today_red);	
	g_key_file_set_double(kf, "calendar_settings", "today_green", m_today_green);
	g_key_file_set_double(kf, "calendar_settings", "today_blue", m_today_blue); 	
	g_key_file_set_double(kf, "calendar_settings", "today_bg_red", m_today_bg_red);  
	g_key_file_set_double(kf, "calendar_settings", "today_bg_green", m_today_bg_green); 
	g_key_file_set_double(kf, "calendar_settings", "today_bg_blue", m_today_bg_blue); 
	
	g_key_file_set_integer(kf, "calendar_settings", "today_frame", m_today_frame);    
	
	g_key_file_set_double(kf, "calendar_settings", "event_red", m_event_red);
	g_key_file_set_double(kf, "calendar_settings", "event_green", m_event_green);
	g_key_file_set_double(kf, "calendar_settings", "event_blue", m_event_blue); 	
	g_key_file_set_double(kf, "calendar_settings", "event_bg_red", m_event_bg_red);  
	g_key_file_set_double(kf, "calendar_settings", "event_bg_green", m_event_bg_green); 
	g_key_file_set_double(kf, "calendar_settings", "event_bg_blue", m_event_bg_blue); 
	
	g_key_file_set_integer(kf, "calendar_settings", "event_frame", m_event_frame);    
	
		
	g_key_file_set_double(kf, "calendar_settings", "holiday_red", m_holiday_red);
	g_key_file_set_double(kf, "calendar_settings", "holiday_green", m_holiday_green);
	g_key_file_set_double(kf, "calendar_settings", "holiday_blue", m_holiday_blue); 	
	g_key_file_set_double(kf, "calendar_settings", "holiday_bg_red", m_holiday_bg_red);  
	g_key_file_set_double(kf, "calendar_settings", "holiday_bg_green", m_holiday_bg_green); 
	g_key_file_set_double(kf, "calendar_settings", "holiday_bg_blue", m_holiday_bg_blue); 
	
	g_key_file_set_integer(kf, "calendar_settings", "holiday_frame", m_holiday_frame);  
	
	
	g_key_file_set_double(kf, "calendar_settings", "priority_red", m_priority_red);
	g_key_file_set_double(kf, "calendar_settings", "priority_green", m_priority_green);
	g_key_file_set_double(kf, "calendar_settings", "priority_blue", m_priority_blue); 	
	g_key_file_set_double(kf, "calendar_settings", "priority_bg_red", m_priority_bg_red);  
	g_key_file_set_double(kf, "calendar_settings", "priority_bg_green", m_priority_bg_green); 
	g_key_file_set_double(kf, "calendar_settings", "priority_bg_blue", m_priority_bg_blue); 
	
	g_key_file_set_integer(kf, "calendar_settings", "priority_frame", m_priority_frame);    
	 	
	
	gsize length;
	gchar * data = g_key_file_to_data(kf, &length, NULL);
	g_file_set_contents(m_config_file, data, -1, NULL);
	g_free(data);
	g_key_file_free(kf);
	
}

void config_initialize() {
	
	gchar * config_dir = g_build_filename(g_get_user_config_dir(), CONFIG_DIRNAME, NULL);
	m_config_file = g_build_filename(config_dir, CONFIG_FILENAME, NULL);

	// Make sure config directory exists
	if(!g_file_test(config_dir, G_FILE_TEST_IS_DIR))
		g_mkdir(config_dir, 0777);
	// If a config file doesn't exist, create one with defaults otherwise
	
	// read the existing one
	if(!g_file_test(m_config_file, G_FILE_TEST_EXISTS))
	{
		config_load_default();
		config_write();
	}
	else
	{
		config_read();
	}

	g_free(config_dir);
	
}

//---------------------------------------------------------------------

G_DEFINE_TYPE (DisplayObject, display_object, G_TYPE_OBJECT)

static void display_object_init (DisplayObject *obj)
{
}

static void display_object_get_property (GObject    *object,
                        guint       property_id,
                        GValue     *value,
                        GParamSpec *pspec){
							
							
  DisplayObject *obj = (DisplayObject *)object;
  //property_id has to map to property enumeration
  switch (property_id)
    {
    case PROP_LABEL:
    g_value_set_string (value, obj->label);
    break;
    case PROP_ID:
    g_value_set_int (value, obj->id);
    break; 
    case PROP_STARTTIME: //for sorting
    g_value_set_int (value, obj->starttime);
    break;    
    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
    break;
    }
}

static void display_object_set_property (GObject      *object,
                        guint         property_id,
                        const GValue *value,
                        GParamSpec   *pspec){
							
  DisplayObject *obj = (DisplayObject *)object;  
 
  //setting the display object properties
  switch (property_id)
    {
    case PROP_LABEL:
      g_free (obj->label);
      obj->label = g_value_dup_string (value); //label defines what is displayed
      break;
    case PROP_ID:
      obj->id = g_value_get_int (value); //get the int from the GValue
      break;     
     case PROP_STARTTIME:
      obj->starttime = g_value_get_int (value);
      break;       
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
      break;
    }
}

static void display_object_finalize (GObject *obj)
{
  DisplayObject *object = (DisplayObject *)obj;

  g_free (object->label);

  G_OBJECT_CLASS (display_object_parent_class)->finalize (obj);
}

static void display_object_class_init (DisplayObjectClass *class)
{
  
  
  GObjectClass *object_class = G_OBJECT_CLASS (class);
   
   //the object_class has virtual functions called get_property and set_property
   //so you override these to provide your own getter and setter implementations
   
   //override the get_property of the object_class
   object_class->get_property = display_object_get_property;
   //override the set property of the object_class
   object_class->set_property = display_object_set_property;
   object_class->finalize = display_object_finalize;

 //property label used for listview display  and make it read writable
  properties[PROP_LABEL] = g_param_spec_string ("label", "label", "used for list view display",
                                                NULL, G_PARAM_READWRITE);
  properties[PROP_ID] = g_param_spec_int ("id", "id", "id",
                                          0, G_MAXINT, 0, G_PARAM_READWRITE);
     
  properties[PROP_STARTTIME] = g_param_spec_int ("starttime", "starttime", "starttime",
                                          0, G_MAXINT, 0, G_PARAM_READWRITE);
                                          
     
  //install the properties using the object_class, the number of proerties and the properties
  g_object_class_install_properties (object_class, LAST_PROPERTY, properties);
}


//---------------------------------------------------------------------
// create widget
//---------------------------------------------------------------------

static GtkWidget *create_widget (gpointer item, gpointer user_data)
{
  DisplayObject *obj = (DisplayObject *)item;
  GtkWidget *label;

  label = gtk_label_new ("");
  g_object_bind_property (obj, "label", label, "label", G_BINDING_SYNC_CREATE);

  return label;
}

//--------------------------------------------------------------------
// Remove unwanted characters
//--------------------------------------------------------------------

static char* remove_semicolons (const char *text)
{
	GString *str;
	const char *p;	
	str = g_string_new ("");	
	p = text;
	while (*p)
	{
	gunichar cp = g_utf8_get_char(p);	
	if ( cp != ';' ){ //do not allow semicolons into database
	g_string_append_unichar (str, *p);           
	}//if
	
	++p;
	}
	
	return g_string_free (str, FALSE);
}

static char* remove_fullstops(const char *text)
{
	GString *str;
	const char *p;	
	str = g_string_new ("");	
	p = text;
	while (*p)
	{
	gunichar cp = g_utf8_get_char(p);	
	if ( cp != '.' ){ //do not allow semicolons into database
	g_string_append_unichar (str, *p);           
	}//if
	
	++p;
	}
	
	return g_string_free (str, FALSE);
}
static char* remove_commas(const char *text)
{
	GString *str;
	const char *p;	
	str = g_string_new ("");	
	p = text;
	while (*p)
	{
	gunichar cp = g_utf8_get_char(p);	
	if ( cp != ',' ){ //csv separated so remove 
	g_string_append_unichar (str, *p);           
	}//if
	
	++p;
	}
	
	return g_string_free (str, FALSE);
}


static char* remove_newline(const char *text)
{
	GString *str;
	const char *p;	
	str = g_string_new ("");	
	p = text;
	while (*p)
	{
	gunichar cp = g_utf8_get_char(p);	
	if ( cp != '\n' ){ //remove new line
	g_string_append_unichar (str, *p);           
	}//if
	
	++p;
	}
	
	return g_string_free (str, FALSE);
}

//--------------------------------------------------------------------
// Compare
//---------------------------------------------------------------------

static int compare_items (gconstpointer a, gconstpointer b, gpointer data)
{
  int starttime_a, starttime_b;
  g_object_get ((gpointer)a, "starttime", &starttime_a, NULL);
  g_object_get ((gpointer)b, "starttime", &starttime_b, NULL);
  return starttime_a - starttime_b;
}

//--------------------------------------------------------------------
// calendar functions
//---------------------------------------------------------------------
static int first_day_of_month(int month, int year)
{
    if (month < 3) {
        month += 12;
        year--;
    }
    int century = year / 100;
    year = year % 100;
    return (((13 * (month + 1)) / 5) +
            (century / 4) + (5 * century) +
            year + (year / 4)) % 7;
}

//---------------------------------------------------------------------
// calculate easter
//---------------------------------------------------------------------

GDate* calculate_easter(gint year) {

	GDate *edate;
	
	gint Yr = year;
    gint a = Yr % 19;
    gint b = Yr / 100;
    gint c = Yr % 100;
    gint d = b / 4;
    gint e = b % 4;
    gint f = (b + 8) / 25;
    gint g = (b - f + 1) / 3;
    gint h = (19 * a + b - d - g + 15) % 30;
    gint i = c / 4;
    gint k = c % 4;
    gint L = (32 + 2 * e + 2 * i - h - k) % 7;
    gint m = (a + 11 * h + 22 * L) / 451;
    gint month = (h + L - 7 * m + 114) / 31;
    gint day = ((h + L - 7 * m + 114) % 31) + 1;	
	edate = g_date_new_dmy(day, month, year);

	return edate;
}

//---------------------------------------------------------------------
// Notifications
//---------------------------------------------------------------------

static int get_number_of_events()
{
	//repeat events to do
	
	int event_count=0;
	Event e;  
	for (int i=0; i<m_db_size; i++)
	{  
	e=db_store[i];
	if(m_year==e.year && m_month ==e.month && m_day==e.day)
	{		
	event_count++;
	}//if		
	}//for
  
 return event_count;
}


static void show_notification(gchar *message)
{ 
 gchar* command_str ="notify-send ";
 command_str= g_strconcat(command_str," \"Talk Calendar\"" ," \"",message," \"", NULL);
 system(command_str);
}

//------------------------------------------------------------------
//font style
//--------------------------------------------------------------------
gchar* get_css_string() {
	
	char *size_str = g_strdup_printf("%i", m_font_size); 
	size_str =g_strconcat(size_str,"px;", NULL);
	gchar* css_str = g_strdup_printf ("#cssView {font-size: %s }", size_str);	
	return css_str;	
}



static void set_widget_font_size(GtkWidget* widget) {
	
	GtkStyleContext *context;
	GtkCssProvider *cssProvider;	
	gtk_widget_set_name(GTK_WIDGET(widget), "cssView"); 		
	cssProvider = gtk_css_provider_new();
	gtk_css_provider_load_from_data(cssProvider, get_css_string(),-1); 
	context = gtk_widget_get_style_context(GTK_WIDGET(widget));		 
	gtk_style_context_add_provider(context,    
	GTK_STYLE_PROVIDER(cssProvider), 
	GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
}

static void set_today_button_colour(GtkButton *button){
	
  GtkStyleContext *context_button;
  GtkCssProvider *cssProvider;
  gtk_widget_set_name (GTK_WIDGET(button), "cssView"); 	
  cssProvider = gtk_css_provider_new();	
  
  
  gchar* css_str=""; 
  
  int red=(int)(m_today_red*255);
  int green=(int)(m_today_green*255);
  int blue =(int)(m_today_blue*255);
  int bg_red=(int)(m_today_bg_red*255);
  int bg_green=(int)(m_today_bg_green*255);
  int bg_blue =(int)(m_today_bg_blue*255);
    
  if(m_today_frame) {
  css_str = g_strdup_printf (
  "#cssView {"
  "color: rgba(%i,%i,%i,1);"  
  "background-color: rgba(%i,%i,%i,1);"
  "font-weight: bold;"
  "border-width: 2px 2px 2px 2px;" 
  "border-color: black;"
  "}", red, green, blue, bg_red, bg_green, bg_blue );
  }
  else {
  css_str = g_strdup_printf (
  "#cssView {"
  "color: rgba(%i,%i,%i,1);"
  "background-color: rgba(%i,%i,%i,1);"
  "font-weight: bold;"
  "border-width: 0px 0px 0px 0px;" 
  "}", red, green, blue, bg_red, bg_green, bg_blue );
  }
  
  gtk_css_provider_load_from_data(cssProvider, css_str,-1);   
  context_button= gtk_widget_get_style_context(GTK_WIDGET(button));		 
  gtk_style_context_add_provider(context_button, GTK_STYLE_PROVIDER(cssProvider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);	
}


static void set_event_button_colour(GtkButton *button){
	
  GtkStyleContext *context_button;
  GtkCssProvider *cssProvider; 
  gtk_widget_set_name (GTK_WIDGET(button), "cssView");	
  cssProvider = gtk_css_provider_new();	
  
  gchar* css_str=""; 
  
  int red=(int)(m_event_red*255);
  int green=(int)(m_event_green*255);
  int blue =(int)(m_event_blue*255);
  int bg_red=(int)(m_event_bg_red*255);
  int bg_green=(int)(m_event_bg_green*255);
  int bg_blue =(int)(m_event_bg_blue*255);
  
//border  
if  (m_event_frame) {
css_str = g_strdup_printf (
   "#cssView {"
  "color: rgba(%i,%i,%i,1);"  
  "background-color: rgba(%i,%i,%i,1);"
  "font-weight: bold;"
  "border-width: 2px 2px 2px 2px;" 
  "border-color: black;"
  "}", red, green, blue,bg_red, bg_green, bg_blue );
}
else {
css_str = g_strdup_printf (
  "#cssView {"
  "color: rgba(%i,%i,%i,1);"
  "background-color: rgba(%i,%i,%i,1);"
  "font-weight: bold;"
  "border-width: 0px 0px 0px 0px;" 
  "}",red, green, blue, bg_red, bg_green, bg_blue );
  
}
  gtk_css_provider_load_from_data(cssProvider, css_str,-1);   
  context_button= gtk_widget_get_style_context(GTK_WIDGET(button));		 
  gtk_style_context_add_provider(context_button, GTK_STYLE_PROVIDER(cssProvider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);	
}

static void set_holiday_button_colour(GtkButton *button){
	
  GtkStyleContext *context_button;
  GtkCssProvider *cssProvider; 	
  cssProvider = gtk_css_provider_new();	
  gtk_widget_set_name (GTK_WIDGET(button), "cssView");
  gchar* css_str=""; 
  
   int red=(int)(m_holiday_red*255);
  int green=(int)(m_holiday_green*255);
  int blue =(int)(m_holiday_blue*255);
  int bg_red=(int)(m_holiday_bg_red*255);
  int bg_green=(int)(m_holiday_bg_green*255);
  int bg_blue =(int)(m_holiday_bg_blue*255);
     
  //border  
if  (m_holiday_frame) {
css_str = g_strdup_printf (
   "#cssView {"
  "color: rgba(%i,%i,%i,1);"  
  "background-color: rgba(%i,%i,%i,1);"
  "font-weight: bold;"
  "border-width: 2px 2px 2px 2px;" 
  "border-color: black;"
  "}", red, green, blue,bg_red, bg_green, bg_blue );
} 
else {
css_str = g_strdup_printf (
 "#cssView {"
  "color: rgba(%i,%i,%i,1);"
  "background-color: rgba(%i,%i,%i,1);"
  "font-weight: bold;"
  "border-width: 0px 0px 0px 0px;" 
  "}", red, green, blue, bg_red, bg_green, bg_blue );
  
}
  
  gtk_css_provider_load_from_data(cssProvider, css_str,-1);   
  context_button= gtk_widget_get_style_context(GTK_WIDGET(button));		 
  gtk_style_context_add_provider(context_button, GTK_STYLE_PROVIDER(cssProvider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);	
}

static void set_priority_button_colour(GtkButton *button){
	
  GtkStyleContext *context_button;
  GtkCssProvider *cssProvider; 	
  cssProvider = gtk_css_provider_new();	
  gtk_widget_set_name (GTK_WIDGET(button), "cssView");
  
  gchar* css_str=""; 
  
  int red=(int)(m_priority_red*255);
  int green=(int)(m_priority_green*255);
  int blue =(int)(m_priority_blue*255);
  int bg_red=(int)(m_priority_bg_red*255);
  int bg_green=(int)(m_priority_bg_green*255);
  int bg_blue =(int)(m_priority_bg_blue*255);
   
  if(m_priority_frame) {
  css_str = g_strdup_printf (
    "#cssView {"
  "color: rgba(%i,%i,%i,1);"  
  "background-color: rgba(%i,%i,%i,1);"
  "font-weight: bold;"
  "border-width: 2px 2px 2px 2px;" 
  "border-color: black;"
  "}", red, green, blue, bg_red, bg_green, bg_blue );
  }
  else {
  css_str = g_strdup_printf (
  "#cssView {"
  "color: rgba(%i,%i,%i,1);"
  "background-color: rgba(%i,%i,%i,1);"
  "font-weight: bold;"
  "border-width: 0px 0px 0px 0px;" 
  "}", red, green, blue, bg_red, bg_green, bg_blue );
  }
  
  gtk_css_provider_load_from_data(cssProvider, css_str,-1);   
  context_button= gtk_widget_get_style_context(GTK_WIDGET(button));		 
  gtk_style_context_add_provider(context_button, GTK_STYLE_PROVIDER(cssProvider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);	
}

//--------------------------------------------------------------------
// new event
//---------------------------------------------------------------------

static void callbk_check_button_allday_toggled (GtkCheckButton *check_button, gpointer user_data)
{
 	
 	GtkWidget *spin_button_start_time; 	
 	GtkWidget *spin_button_end_time;
 	
 	spin_button_start_time =g_object_get_data(G_OBJECT(user_data), "cb_allday_spin_start_time_key");	
	spin_button_end_time= g_object_get_data(G_OBJECT(user_data), "cb_allday_spin_end_time_key");
	
 	if (gtk_check_button_get_active(GTK_CHECK_BUTTON(check_button))){
	gtk_widget_set_sensitive(spin_button_start_time,FALSE);	
	gtk_widget_set_sensitive(spin_button_end_time,FALSE);
	}     
	else{
	gtk_widget_set_sensitive(spin_button_start_time,TRUE);	
	gtk_widget_set_sensitive(spin_button_end_time,TRUE);
	
	}
  
}

//---------------------------------------------------------------------
// Speaking
//---------------------------------------------------------------------

//---------------------------------------------------------------------
// Convert date to week day
//---------------------------------------------------------------------

GList* convert_date_to_weekday_diphone_list(int day, int month, int year) {
	
	//char* weekday_str="";
	GList* result =NULL;
	
	GDate* day_date;
	day_date = g_date_new_dmy(day, month, year);
	GDateWeekday weekday =g_date_get_weekday(day_date);
	
	 switch (weekday) {
		case G_DATE_MONDAY:		
		result =word_to_diphones("monday");	
		break;
		case G_DATE_TUESDAY:		
		result =word_to_diphones("tuesday");	
		break;
		case G_DATE_WEDNESDAY:		
		result =word_to_diphones("wednesday");	
		break;
		case G_DATE_THURSDAY:		
		result =word_to_diphones("thursday");	
		break;
		case G_DATE_FRIDAY:		
		result =word_to_diphones("friday");	
		break;
		case G_DATE_SATURDAY:	
		result =word_to_diphones("saturday");	
		break;
		case G_DATE_SUNDAY:	
		result =word_to_diphones("sunday");	
		break;
		default:
		//Unknown day of week		
		result =word_to_diphones("day");	
		break;
	    }//switch dow
	
	return result;
}

//---------------------------------------------------------------------
// Convert day number to diphone list
//---------------------------------------------------------------------
GList* convert_day_number_to_diphone_list(int day_number) {
	
	GList* result =NULL;
	
	switch (day_number) {
		case 1:
		result =word_to_diphones("first");
		break;		
		case 2:
		result =word_to_diphones("second");
		break;
		case 3:
		result =word_to_diphones("third");
		break;
		case 4:
		result =word_to_diphones("fourth");
		break;
		case 5:
		result =word_to_diphones("fifth");
		break;
		case 6:
		result =word_to_diphones("sixth");
		break;
		case 7:
		result =word_to_diphones("seventh");
		break;
		case 8:
		result =word_to_diphones("eighth");
		break;
		case 9:
		result =word_to_diphones("ninth");
		break;
		case 10:
		result =word_to_diphones("tenth");
		break;
		case 11:
		result =word_to_diphones("eleventh");
		break;
		case 12:		
		result =word_to_diphones("twelfth");	
		break;
		case 13:		
		result =word_to_diphones("thirteenth");
		break;
		case 14:			
		result =word_to_diphones("fourteenth");	
		break;
		case 15:		
		result =word_to_diphones("fifteenth");
		break;
		case 16:		
		result =word_to_diphones("sixteenth");
		break;
		case 17:		
		result =word_to_diphones("seventieth");
		break;
		case 18:		
		result =word_to_diphones("eighteenth");
		break;
		case 19:		
		result =word_to_diphones("nineteenth");
		break;
		case 20:		
		result =word_to_diphones("twentieth");
		break;
		case 21:		
		result =g_list_concat(word_to_diphones("twenty"),word_to_diphones("first"));				
		break;
		case 22:		
		result =g_list_concat(word_to_diphones("twenty"),word_to_diphones("second"));		
		break;
		case 23:
		result =g_list_concat(word_to_diphones("twenty"),word_to_diphones("third"));	
		break;
		case 24:		
		result =g_list_concat(word_to_diphones("twenty"),word_to_diphones("fourth"));
		break;
		case 25:		
		result =g_list_concat(word_to_diphones("twenty"),word_to_diphones("fifth"));
		break;
		case 26:		
		result =g_list_concat(word_to_diphones("twenty"),word_to_diphones("sixth"));
		break;
		case 27:		
		result =g_list_concat(word_to_diphones("twenty"),word_to_diphones("seventh"));
		break;
		case 28:		
		result =g_list_concat(word_to_diphones("twenty"),word_to_diphones("eighth"));
		break;
		case 29:		
		result =g_list_concat(word_to_diphones("twenty"),word_to_diphones("ninth"));
		break;
		case 30:		
		result =word_to_diphones("thirtieth");
		break;
		case 31:
		result =g_list_concat(word_to_diphones("thirty"),word_to_diphones("first"));		
		break;
		default:
		//Unknown ordinal
		result =word_to_diphones("zero");
		break;		
	  } //day switch      
		
	return result;	
}

//---------------------------------------------------------------------
// Convert month to diphone list
//---------------------------------------------------------------------
GList* convert_month_to_diphone_list(int month) {
	
	GList* result =NULL;
	
	switch(month) {
	case 1:		
		result =word_to_diphones("january");
		break;
	case 2:			
		result =word_to_diphones("february");	
		break;
	case 3:		
		result =word_to_diphones("march");
		break; 
	case 4:
		result =word_to_diphones("april");
		break; 
	case 5:		
		result =word_to_diphones("may");
		break;
	case 6:		
		result =word_to_diphones("june");
		break; 
	case 7:		
		result =word_to_diphones("july");
		break;
	case 8:		
		result =word_to_diphones("august");
		break;
	case 9:		
		result =word_to_diphones("september");
		break;
	case 10:		
		result =word_to_diphones("october");
		break;
	case 11:		
		result =word_to_diphones("november");
		break; 
	case 12:		
		result =word_to_diphones("december");
		break; 
	default:
		result =word_to_diphones("month");
	}

	return result;
}

//---------------------------------------------------------------------
// Convert event number to diphone list
//---------------------------------------------------------------------
GList* get_event_number_diphone_list(int event_number) {
	
	GList* result =NULL;
	
	if (event_number ==0) {	
	GList *noevents_list=NULL;    
	noevents_list = word_to_diphones("no");   
	noevents_list = g_list_concat(noevents_list,word_to_diphones("events")); 
	noevents_list = g_list_concat(noevents_list,word_to_diphones("today")); 
	result =noevents_list;	
	} //if
	
	else if(event_number ==1){		
		result =g_list_concat(word_to_diphones("one"),word_to_diphones("event"));
	}
	else if(event_number ==2){		
		result =g_list_concat(word_to_diphones("two"),word_to_diphones("events"));
	}
	else if(event_number ==3){
		 result =g_list_concat(word_to_diphones("three"),word_to_diphones("events")); 
	}
	else if(event_number ==4){
		result =g_list_concat(word_to_diphones("four"),word_to_diphones("events")); 
	}
	else if(event_number ==5){ 
		result =g_list_concat(word_to_diphones("five"),word_to_diphones("events"));
	
	}		
	else {
	result =g_list_concat(word_to_diphones("many"),word_to_diphones("events"));
	}
	
	return result;
}

//---------------------------------------------------------------------
// convert number to diphone list
//---------------------------------------------------------------------
GList* convert_number_to_diphone_list(int number) {
	
	GList* result =NULL;
	
	switch (number) {		
		case 1:
		result =word_to_diphones("one");
		break;		
		case 2:
		result =word_to_diphones("two");
		break;
		case 3:
		result =word_to_diphones("three");
		break;
		case 4:
		result =word_to_diphones("four");
		break;
		case 5:
		result =word_to_diphones("five");
		break;
		case 6:
		result =word_to_diphones("six");
		break;
		case 7:
		result =word_to_diphones("seven");
		break;
		case 8:
		result =word_to_diphones("eight");
		break;
		case 9:
		result =word_to_diphones("nine");
		break;
		case 10:
		result =word_to_diphones("ten");
		break;
		case 11:
		result =word_to_diphones("eleven");
		break;
		case 12:
		result =word_to_diphones("twelve");
		break;
		case 13:
		result =word_to_diphones("thirteen");
		break;
		case 14:
		result =word_to_diphones("fourteen");
		break;
		case 15:
		result =word_to_diphones("fifteen");
		break;
		case 16:
		result =word_to_diphones("sixteen");
		break;
		case 17:
		result =word_to_diphones("seventeen");
		break;
		case 18:
		result =word_to_diphones("eighteen");
		break;
		case 19:
		result =word_to_diphones("nineteen");
		break;
		case 20:
		result =word_to_diphones("twenty");
		break;
		case 21:
		result =g_list_concat(word_to_diphones("twenty"),word_to_diphones("one"));
		break;
		case 22:
		result =g_list_concat(word_to_diphones("twenty"),word_to_diphones("two"));
		break;
		case 23:
		result =g_list_concat(word_to_diphones("twenty"),word_to_diphones("three"));
		break;
		case 24:
		result =g_list_concat(word_to_diphones("twenty"),word_to_diphones("four"));
		break;
		case 25:
		result =g_list_concat(word_to_diphones("twenty"),word_to_diphones("five"));
		break;
		case 26:
		result =g_list_concat(word_to_diphones("twenty"),word_to_diphones("six"));
		break;
		case 27:
		result =g_list_concat(word_to_diphones("twenty"),word_to_diphones("seven"));
		break;
		case 28:
		result =g_list_concat(word_to_diphones("twenty"),word_to_diphones("eight"));
		break;
		case 29:
		result =g_list_concat(word_to_diphones("twenty"),word_to_diphones("nine"));
		break;
		case 30:
		result =word_to_diphones("thirty");
		break;
		case 31:
		result =g_list_concat(word_to_diphones("thirty"),word_to_diphones("one"));
		break;
		case 32:
		result =g_list_concat(word_to_diphones("thirty"),word_to_diphones("two"));
		break;
		case 33:
		result =g_list_concat(word_to_diphones("thirty"),word_to_diphones("three"));
		break;
		case 34:
		result =g_list_concat(word_to_diphones("thirty"),word_to_diphones("four"));
		break;
		case 35:
		result =g_list_concat(word_to_diphones("thirty"),word_to_diphones("five"));
		break;
		case 36:
		result =g_list_concat(word_to_diphones("thirty"),word_to_diphones("six"));
		break;
		case 37:
		result =g_list_concat(word_to_diphones("thirty"),word_to_diphones("seven"));
		break;
		case 38:
		result =g_list_concat(word_to_diphones("thirty"),word_to_diphones("eight"));
		break;
		case 39:
		result =g_list_concat(word_to_diphones("thirty"),word_to_diphones("nine"));
		break;
		case 40:
		result =word_to_diphones("forty");
		break;
		case 41:
		result =g_list_concat(word_to_diphones("forty"),word_to_diphones("one"));
		break;
		case 42:
		result =g_list_concat(word_to_diphones("forty"),word_to_diphones("two"));
		break;
		case 43:
		result =g_list_concat(word_to_diphones("forty"),word_to_diphones("three"));
		break;
		case 44:
		result =g_list_concat(word_to_diphones("forty"),word_to_diphones("four"));
		break;
		case 45:
		result =g_list_concat(word_to_diphones("forty"),word_to_diphones("five"));
		break;
		case 46:
		result =g_list_concat(word_to_diphones("forty"),word_to_diphones("six"));
		break;
		case 47:
		result =g_list_concat(word_to_diphones("forty"),word_to_diphones("seven"));
		break;
		case 48:
		result =g_list_concat(word_to_diphones("forty"),word_to_diphones("eight"));
		break;
		case 49:
		result =g_list_concat(word_to_diphones("forty"),word_to_diphones("nine"));
		break;
		case 50:
		result =word_to_diphones("fifty");
		break;
		case 51:
		result =g_list_concat(word_to_diphones("fifty"),word_to_diphones("one"));
		break;
		case 52:
		result =g_list_concat(word_to_diphones("fifty"),word_to_diphones("two"));
		break;
		case 53:
		result =g_list_concat(word_to_diphones("fifty"),word_to_diphones("three"));
		break;
		case 54:
		result =g_list_concat(word_to_diphones("fifty"),word_to_diphones("four"));
		break;
		case 55:
		result =g_list_concat(word_to_diphones("fifty"),word_to_diphones("five"));
		break;
		case 56:
		result =g_list_concat(word_to_diphones("fifty"),word_to_diphones("six"));
		break;
		case 57:
		result =g_list_concat(word_to_diphones("fifty"),word_to_diphones("seven"));
		break;
		case 58:
		result =g_list_concat(word_to_diphones("fifty"),word_to_diphones("eight"));
		break;
		case 59:
		result =g_list_concat(word_to_diphones("fifty"),word_to_diphones("nine"));
		break;
		
		default:		
		result =word_to_diphones("zero");
		break;		
				
	}
		
	return result;
}


//---------------------------------------------------------------------
// Speak events
//---------------------------------------------------------------------

static void speak_events() {
	
	if(m_talk==0) return;
		
	//get day events and sort -----------------------------------------
	int day_event_number=0;
	Event e;  
	for (int i=0; i<m_db_size; i++)
	{  
	e=db_store[i];
	//normal events
	if(m_year==e.year && m_month ==e.month && m_day==e.day)
	{		
	day_event_number++;
	}//if		
	//year repeat events
	if(m_year!= e.year && m_month ==e.month && m_day==e.day && e.is_yearly==1)
	{		
	day_event_number++;
	}//if	
	}//for
		
   Event day_events[day_event_number]; 
   //Event e;
   //load day events 
   int jj=0;
   for (int i=0; i<m_db_size; i++)
	{  
	e=db_store[i];
	//normal events
	if(m_year==e.year && m_month ==e.month && m_day==e.day)
	{		
	day_events[jj] =e;	
	jj++;
	}//if
	//year repeat events
	if(m_year!= e.year && m_month ==e.month && m_day==e.day && e.is_yearly==1)
	{		
	day_events[jj] =e;	
	jj++;
	}//if
	}//for   
   //sort   
   qsort (day_events, day_event_number, sizeof(Event), compare);
   	
	//----------------------------------------------------------
		
	GList *wavlist=NULL;
	//gchar *cur_dir;
	GList *all_diphones=NULL;
	

	GList *weekday_list=convert_date_to_weekday_diphone_list(m_day, m_month, m_year);
	GList *day_number_list =convert_day_number_to_diphone_list(m_day);
	GList *month_list=convert_month_to_diphone_list(m_month);
	
	all_diphones =g_list_concat(all_diphones,weekday_list);
	all_diphones =g_list_concat(all_diphones,day_number_list);
	all_diphones =g_list_concat(all_diphones,month_list);
	all_diphones =g_list_concat(all_diphones, word_to_diphones("pau"));
	
	
	if(m_talk_event_number) {
		GList* event_number_list =get_event_number_diphone_list(day_event_number);
	    all_diphones =g_list_concat(all_diphones,event_number_list);
	    all_diphones =g_list_concat(all_diphones, word_to_diphones("pau"));		
	}
	
	
	//cycle through day events ---------------------------------------
	
	Event day_event;
    
    for(int i=0; i<day_event_number; i++)
    {
    day_event =day_events[i];
    
    //----------------------------------------------------------------
    if (m_talk_time) {
		//talk start time
	   //float start_time =day_event.start_time;	   
	   float integral_part, fractional_part;
	   fractional_part = modff(day_event.start_time, &integral_part);  
	   int start_hour =(int) integral_part; //start_hour
	   fractional_part=round(fractional_part *100);
	   int start_min=(int) (fractional_part); //start_min
	  	   
	 //Time ----------------------------------------------------------
	 
	 GList* time_list=NULL;
	 
		if(day_event.is_allday) {			
		
		time_list =g_list_concat(time_list,word_to_diphones("all"));
		time_list =g_list_concat(time_list, word_to_diphones("day"));
		time_list =g_list_concat(time_list, word_to_diphones("event")); 
		
		}
		else {
	  	
	  	GList* hour_list=NULL;
	  	GList* min_list=NULL;
	  	
	  	if(start_min <10) {
			hour_list =convert_number_to_diphone_list(start_hour);
			GList* zero_list=convert_number_to_diphone_list(0);
			min_list =convert_number_to_diphone_list(start_min);
		    zero_list =g_list_concat(zero_list,min_list);			
			time_list =g_list_concat(hour_list,zero_list);
			
		}
		else {	  	
	  	hour_list =convert_number_to_diphone_list(start_hour);
	  	min_list =convert_number_to_diphone_list(start_min);
	  	time_list =g_list_concat(hour_list,min_list);
	     } 
	 
	 
	} //else 
	
	time_list =g_list_concat(time_list, word_to_diphones("pau"));	
	all_diphones =g_list_concat(all_diphones,time_list);
	
	
	} //talk time
    //------------------------------------------------------------------
    if(m_talk_title) {
    GList *event_title_list=NULL;  
    char* str = remove_semicolons(day_event.title);
    str = remove_fullstops(str);
    str = remove_commas(str);
  
	gchar** words;		 
	words = g_strsplit (str, " ", 0); //split on space
	int j=0;			   
	while(words[j] != NULL)
	{	
	event_title_list=word_to_diphones(words[j]);
	all_diphones =g_list_concat(all_diphones,event_title_list);	
	j++;
	} //while loop words
	
    all_diphones =g_list_concat(all_diphones, word_to_diphones("pau"));
    } //if talking title   
    
    
    if(m_talk_notes) {
		
	GList *event_notes_list=NULL;  
    char* str_notes = remove_semicolons(day_event.notes);
    str_notes = remove_fullstops(str_notes);
    str_notes = remove_commas(str_notes);
  
  
	gchar** note_words;		 
	note_words = g_strsplit (str_notes, " ", 0); //split on space
	int j=0;			   
	while(note_words[j] != NULL)
	{	
	event_notes_list=word_to_diphones(note_words[j]);
	all_diphones =g_list_concat(all_diphones,event_notes_list);	
	j++;
	} //while loop words
	
   
    all_diphones =g_list_concat(all_diphones, word_to_diphones("pau"));	
		
		
	}//m_talk_notes
    
    
    }//for dayevents
	//end cycle through day events ---------------------------------------
	
	
	//overlap check
	GList* overlap_list=NULL;
	if(m_talk_overlap && check_day_events_for_overlap())
	{
	//g_print("events are overlapping\n");	
	overlap_list =word_to_diphones("you");
	overlap_list =g_list_concat(overlap_list,word_to_diphones("have")); 
	overlap_list =g_list_concat(overlap_list,word_to_diphones("overlapping")); 
	overlap_list =g_list_concat(overlap_list,word_to_diphones("events")); 	 
	all_diphones =g_list_concat(all_diphones,overlap_list);
	}
	
	
	
	//speak diphones
	
	//iterate over GList
	GList *l;
    for (l = all_diphones; l != NULL; l = l->next) {    
    char *str = l->data;       
    char* diphone_wav_str =get_diphone_wav_path(str);   
    
     if (g_file_test(diphone_wav_str, G_FILE_TEST_IS_REGULAR)) {
	  wavlist = g_list_append(wavlist,diphone_wav_str);
	 }
	 else {
		 g_print("diphone_wav_str = %s NOT found\n",diphone_wav_str);
	 }  
    } //for-loop
	
	

	//-----------------------------------------------------------------
	//prepare for wavcat  
	//------------------------------------------------------------------
				  
	char* merge_file ="/tmp/talkout.wav";	
	int num_files = g_list_length(wavlist);
	char* file_names[g_list_length(wavlist)];
		
	GList *wl;//iterate through GList wavlist
	int i=0; 
    for (wl = wavlist; wl != NULL; wl = wl->next) {    
    char *wstr = wl->data;
    file_names[i] = wstr;	//populate char* array
    i=i+1;    
    } //for-loop
	
		
	merge_wav_files2(merge_file, num_files, file_names, m_talk_sample_rate);
	
	//play audio in a thread
	GThread *thread_audio; 	
	gchar* wav_file ="/tmp/talkout.wav"; //wavcat way	
	g_mutex_lock (&lock);
    thread_audio = g_thread_new(NULL, thread_playwav, wav_file);  
	g_thread_unref (thread_audio);
		
	//clean up 
	g_list_free(wavlist);
	
		
}

//------------------------------------------------------------------
// Check day for event overlap (include repeating events)
//-------------------------------------------------------------------

bool overlap(Event event1, Event event2) {
		 
    float A = event1.start_time;
    float B =event1.end_time;
    float C =event2.start_time;
    float D =event2.end_time;
    
    float maxAC = fmaxf(A, C);
    float minBD = fminf(B,D);
    
    float overlap =minBD-maxAC;
    
    if (overlap<0) return FALSE;
    else return TRUE;    
	
}

//-----------------------------------------------------------------
// Speak
//------------------------------------------------------------------

static void callbk_speak(GSimpleAction* action, GVariant *parameter,gpointer user_data){
		
	speak_events();	
	
}


//---------------------------------------------------------------
// play wav file 
//---------------------------------------------------------------
	
static gpointer thread_playwav(gpointer user_data)
{   
    gchar *wav_path =user_data; 
    
    //g_print("thread_playwav: speaking wav file %s\n", wav_path);  
    gchar * command_str ="aplay -q";    
    gchar *m_sample_rate_str = g_strdup_printf("%i", m_talk_sample_rate); 
    gchar *sample_rate_str ="-r ";    
    sample_rate_str= g_strconcat(sample_rate_str,m_sample_rate_str, NULL); 
   	char input[50];		
	strcpy(input, wav_path);	  
    command_str =g_strconcat(command_str," ",sample_rate_str, " ", input, NULL); 
     //g_print("thread_playwav: command_str= %s\n",command_str);  
    system(command_str); 
    //g_print("lock = %i\n",lock);  
    g_mutex_unlock (&lock); //thread mutex unlock 
    //g_print("after unlock: lock = %i\n",lock);  

    return NULL; 
}




gboolean check_day_events_for_overlap() {
	
	int day_event_number=0;
	Event e;  
	for (int i=0; i<m_db_size; i++)
	{  
	e=db_store[i];
	//normal events
	if(m_year==e.year && m_month ==e.month && m_day==e.day)
	{		
	day_event_number++;
	}//if		
	//year repeat events
	if(m_year!= e.year && m_month ==e.month && m_day==e.day && e.is_yearly==1)
	{		
	day_event_number++;
	}//if	
	}//for
	
	if (day_event_number<=1) return FALSE; //one or zero events
	
	//load day events
	Event day_events[day_event_number];  
	int jj=0;
	for (int i=0; i<m_db_size; i++)
	{  
	e=db_store[i];
	//normal events
	if(m_year==e.year && m_month ==e.month && m_day==e.day)
	{		
	day_events[jj] =e;
	//day_events_number=day_events_number+1;
	jj++;
	}//if
	//year repeat events
	if(m_year!= e.year && m_month ==e.month && m_day==e.day && e.is_yearly==1)
	{		
	day_events[jj] =e;
	//day_events_number=day_events_number+1;
	jj++;
	}//if
	}//for
	
	// Now go through day events checking for overlap  
	
	for (int i = 1; i < day_event_number; i++ ) 
    { 
        
        Event a = day_events[i];
        for (int j = 0; j < i; j++ ) 
        { 
          Event b = day_events[j]; 
	      bool result =overlap(a,b);
	      if (result) return TRUE; 
          
        } //j       
    } //i	
	
	return FALSE;
}
//---------------------------------------------------------------------

//---------------------------------------------------------------------
static void set_text_view_border(GtkWidget *text_view) {
	
  GtkStyleContext *context;

  context = gtk_widget_get_style_context (GTK_WIDGET (text_view));
  GtkCssProvider *provider = gtk_css_provider_new ();
  //gtk_css_provider_load_from_data (provider, "textview {border-width: 4px; border-style: solid; border-color: #000;}", -1);
  gtk_css_provider_load_from_data (provider, "textview {border-width: 1px; border-style: solid;}", -1);
  gtk_style_context_add_provider (context, GTK_STYLE_PROVIDER (provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
	
}

static void callbk_new_event_response(GtkDialog *dialog, gint response_id,  gpointer  user_data)
{
	
	if(!GTK_IS_DIALOG(dialog)) { 
	//g_print("New Event Response: not a dialog\n");	
	return;
	}
	
	GtkWidget *window = user_data;
	
	GtkEntryBuffer *buffer_title; 	
	GtkWidget *entry_title = g_object_get_data(G_OBJECT(dialog), "entry-title-key");
		
	GtkWidget *text_view_notes= g_object_get_data(G_OBJECT(dialog), "text-view-notes-key");
    GtkTextBuffer *buffer_notes;
    GtkTextIter start_iter, end_iter;
	
	  
	GtkWidget *spin_button_start_time= g_object_get_data(G_OBJECT(dialog), "spin-start-time-key");  
    GtkWidget *spin_button_end_time= g_object_get_data(G_OBJECT(dialog), "spin-end-time-key");       
   
	GtkWidget *check_button_allday= g_object_get_data(G_OBJECT(dialog), "check-button-allday-key"); 
    GtkWidget *check_button_isyearly= g_object_get_data(G_OBJECT(dialog), "check-button-isyearly-key");  
    GtkWidget *check_button_priority= g_object_get_data(G_OBJECT(dialog), "check-button-priority-key");
		
	
	if(response_id==GTK_RESPONSE_OK)
	{
	buffer_title = gtk_entry_get_buffer (GTK_ENTRY(entry_title));	
	m_title= gtk_entry_buffer_get_text (buffer_title);	
		
	m_title =remove_commas(m_title);
	m_title =remove_semicolons(m_title);
		
	//notes
	buffer_notes=gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view_notes));	
    gtk_text_buffer_get_start_iter(GTK_TEXT_BUFFER(buffer_notes),&start_iter);	 
    gtk_text_buffer_get_end_iter(GTK_TEXT_BUFFER(buffer_notes),&end_iter);
       
    
    gchar* notes_str = gtk_text_buffer_get_text(GTK_TEXT_BUFFER(buffer_notes),&start_iter,&end_iter,FALSE);
    //g_print("notes = %s\n",notes_str);
    //Testing -put notes into location
    m_notes= notes_str;
    m_notes =remove_newline(m_notes);	
	m_notes =remove_commas(m_notes);	
	m_notes =remove_semicolons(m_notes);
   	
	//int fd;
	Event event;
	event.id =m_db_size;	
	strcpy(event.title,m_title);
	strcpy(event.notes,m_notes);	
	event.year=m_year;
	event.month=m_month;
	event.day=m_day;
	//float start_time, end_time;
	m_start_time =gtk_spin_button_get_value (GTK_SPIN_BUTTON(spin_button_start_time));
	m_end_time =gtk_spin_button_get_value (GTK_SPIN_BUTTON(spin_button_end_time));
		
	event.start_time=m_start_time;
	event.end_time=m_end_time;
	
	if(event.end_time<event.start_time) {
		event.end_time=event.start_time;
	}
    
	event.is_yearly=gtk_check_button_get_active (GTK_CHECK_BUTTON(check_button_isyearly));
	event.is_allday=gtk_check_button_get_active (GTK_CHECK_BUTTON(check_button_allday));
	event.priority=gtk_check_button_get_active(GTK_CHECK_BUTTON(check_button_priority));
	
	db_store[m_db_size] =event;			
	m_db_size=m_db_size+1;	
	update_calendar(GTK_WINDOW(window));
	update_store(m_year,m_month,m_day);
	m_id_selection=-1;			
	}		
	gtk_window_destroy(GTK_WINDOW(dialog));	
}


static void callbk_new_event(GtkButton *button, gpointer  user_data){
 
  GtkWidget *window =user_data;
  
  GtkWidget *dialog;  
  //gint response; 
  //GtkWidget *grid; 
  GtkWidget *box;  
  GtkWidget *label_date;  
  //GtkEntryBuffer *buffer; 
  GtkWidget *label_entry_title; 
  GtkWidget *entry_title;

 
	//event notes
	GtkWidget *label_notes;
	GtkWidget *text_view_notes;    
	GtkTextBuffer *buffer_notes;
	
 
  //Start time
  GtkWidget *label_start_time;  
  GtkWidget *spin_button_start_time;  
  GtkWidget *box_start_time;
  
  //End time
  GtkWidget *label_end_time;  
  GtkWidget *spin_button_end_time; 
  GtkWidget *box_end_time;
  
  
  //Check buttons
  GtkWidget *check_button_allday;	
  GtkWidget *check_button_isyearly;
  GtkWidget *check_button_priority;

  GDate *event_date; 
  event_date = g_date_new();
  event_date = g_date_new_dmy(m_day,m_month,m_year);
  int event_day= g_date_get_day(event_date);
  int event_month= g_date_get_month(event_date);
  int event_year= g_date_get_year(event_date);
  
  gchar * date_str="Event Date: ";
  gchar *day_str = g_strdup_printf("%d",event_day); 
  gchar *month_str = g_strdup_printf("%d",event_month); 
  gchar *year_str = g_strdup_printf("%d",event_year);
  
  date_str =g_strconcat(date_str,day_str,"-",month_str,"-",year_str,NULL); 
  
  dialog = gtk_dialog_new_with_buttons ("New Event", GTK_WINDOW(window),   
  GTK_DIALOG_MODAL|GTK_DIALOG_DESTROY_WITH_PARENT|GTK_DIALOG_USE_HEADER_BAR,
  "OK", GTK_RESPONSE_OK, "Cancel", GTK_RESPONSE_CANCEL, NULL);
  
  gtk_window_set_title (GTK_WINDOW (dialog), "New Event");
  gtk_window_set_default_size(GTK_WINDOW(dialog),350,100);  
  
  box =gtk_box_new(GTK_ORIENTATION_VERTICAL,1);  
  gtk_window_set_child (GTK_WINDOW (dialog), box);
    
  label_date =gtk_label_new(date_str);  
  
  label_entry_title =gtk_label_new("Event Title"); 
  entry_title =gtk_entry_new(); 
  gtk_entry_set_max_length(GTK_ENTRY(entry_title),100);
  
  
  gtk_box_append(GTK_BOX(box), label_date);
  gtk_box_append(GTK_BOX(box), label_entry_title);
  gtk_box_append(GTK_BOX(box), entry_title);
  
  g_object_set_data(G_OBJECT(dialog), "entry-title-key",entry_title);  
  g_object_set_data(G_OBJECT(dialog), "dialog-window-key",window); 
  
  //---------------------------------------------------------
  // Notes entry
  //----------------------------------------------------------     
  label_notes =gtk_label_new("Notes ");   
  buffer_notes = gtk_text_buffer_new (NULL); 
  text_view_notes = gtk_text_view_new_with_buffer (buffer_notes); 
  gtk_text_view_set_editable(GTK_TEXT_VIEW(text_view_notes),TRUE);  
  gtk_text_view_set_wrap_mode (GTK_TEXT_VIEW (text_view_notes), GTK_WRAP_WORD); 	
  set_text_view_border(text_view_notes);
  gtk_box_append(GTK_BOX(box), label_notes);
  gtk_box_append(GTK_BOX(box), text_view_notes);	
  
  g_object_set_data(G_OBJECT(dialog), "text-view-notes-key",text_view_notes);
  
   
  //--------------------------------------------------------
  // Start time spin buttons
  //--------------------------------------------------------- 
   
  GtkAdjustment *adjustment_start;
  //value,lower,upper,step_increment,page_increment,page_size
  adjustment_start = gtk_adjustment_new (8.00, 0.0, 23.59, 1.0, 1.0, 0.0);
  //start time spin
  label_start_time =gtk_label_new("Start Time (24 hour) "); 
  spin_button_start_time = gtk_spin_button_new (adjustment_start, 1.0, 2);  
  box_start_time=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,1);
  gtk_box_append (GTK_BOX(box_start_time),label_start_time);
  gtk_box_append (GTK_BOX(box_start_time),spin_button_start_time);  
  gtk_box_append(GTK_BOX(box), box_start_time);
  g_object_set_data(G_OBJECT(dialog), "spin-start-time-key",spin_button_start_time); 
  
  //end time spin
   GtkAdjustment *adjustment_end;  
  adjustment_end = gtk_adjustment_new (8.00, 0.0, 23.59, 1.0, 1.0, 0.0);
  label_end_time =gtk_label_new("End Time (24 hour) ");
  spin_button_end_time = gtk_spin_button_new (adjustment_end, 1.0, 2);  
  box_end_time=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,1);
  gtk_box_append (GTK_BOX(box_end_time),label_end_time);
  gtk_box_append (GTK_BOX(box_end_time),spin_button_end_time);  
  gtk_box_append(GTK_BOX(box), box_end_time);
  g_object_set_data(G_OBJECT(dialog), "spin-end-time-key",spin_button_end_time);   
  
  //check buttons 
  check_button_allday = gtk_check_button_new_with_label ("Is All Day");  
  
  g_object_set_data(G_OBJECT(check_button_allday), "cb_allday_spin_start_time_key",spin_button_start_time);
  g_object_set_data(G_OBJECT(check_button_allday), "cb_allday_spin_end_time_key",spin_button_end_time); 

  g_signal_connect_swapped (GTK_CHECK_BUTTON(check_button_allday), "toggled", 
					G_CALLBACK (callbk_check_button_allday_toggled), check_button_allday);
    
  check_button_isyearly = gtk_check_button_new_with_label ("Is Yearly");
  check_button_priority = gtk_check_button_new_with_label ("Is High Priority");
  gtk_box_append(GTK_BOX(box), check_button_allday);
  gtk_box_append(GTK_BOX(box), check_button_isyearly);
  gtk_box_append(GTK_BOX(box), check_button_priority);
  
  g_object_set_data(G_OBJECT(dialog), "check-button-allday-key",check_button_allday);
  g_object_set_data(G_OBJECT(dialog), "check-button-isyearly-key",check_button_isyearly);
  g_object_set_data(G_OBJECT(dialog), "check-button-priority-key",check_button_priority);
   
  set_widget_font_size(dialog);
  g_signal_connect (dialog, "response", G_CALLBACK (callbk_new_event_response),window);
  
  gtk_window_present (GTK_WINDOW (dialog)); 
  
}
//----------------------------------------------------------------------
// Edit event
//----------------------------------------------------------------------

void callbk_edit_event_response(GtkDialog *dialog, gint response_id,  gpointer  user_data)
{
		
	if(!GTK_IS_DIALOG(dialog)) { 
	g_print("New Event Response: not a dialog\n");	
	return;
	}
		
	GtkWidget *window = user_data;	
	GtkEntryBuffer *buffer_title; 	
	GtkWidget *entry_title = g_object_get_data(G_OBJECT(dialog), "entry-title-key");
	
	GtkWidget *text_view_notes= g_object_get_data(G_OBJECT(dialog), "text-view-notes-key");
    GtkTextBuffer *buffer_notes;
    GtkTextIter start_iter, end_iter;
		
	GtkWidget *spin_button_start_time= g_object_get_data(G_OBJECT(dialog), "spin-start-time-key");  
    GtkWidget *spin_button_end_time= g_object_get_data(G_OBJECT(dialog), "spin-end-time-key");       
    
    GtkWidget *check_button_allday= g_object_get_data(G_OBJECT(dialog), "check-button-allday-key"); 
    GtkWidget  *check_button_isyearly= g_object_get_data(G_OBJECT(dialog), "check-button-isyearly-key");  
    GtkWidget  *check_button_priority= g_object_get_data(G_OBJECT(dialog), "check-button-priority-key");
	
			
	if(response_id==GTK_RESPONSE_OK)
	{	
	//set data
	buffer_title = gtk_entry_get_buffer (GTK_ENTRY(entry_title));	
	m_title= gtk_entry_buffer_get_text (buffer_title);
	m_title =remove_commas(m_title);
	m_title =remove_semicolons(m_title);	
	
	//notes
	buffer_notes=gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view_notes));	
    gtk_text_buffer_get_start_iter(GTK_TEXT_BUFFER(buffer_notes),&start_iter);	 
    gtk_text_buffer_get_end_iter(GTK_TEXT_BUFFER(buffer_notes),&end_iter);
        
    gchar* notes_str = gtk_text_buffer_get_text(GTK_TEXT_BUFFER(buffer_notes),&start_iter,&end_iter,FALSE);
    //g_print("notes = %s\n",notes_str);
   
    m_notes= notes_str;
    m_notes =remove_newline(m_notes);		
	m_notes =remove_commas(m_notes);
	m_notes =remove_semicolons(m_notes);
	
			
	//insert change into database	
	Event event;
    for(int i=0; i<m_db_size; i++)
    {
	event=db_store[i];
	
	if(event.id==m_id_selection){		
	
	strcpy(event.title, m_title); 
	strcpy(event.notes, m_notes);		
	event.year=m_year;
	event.month=m_month;
	event.day=m_day;	
	//float start_time, end_time;
	m_start_time =gtk_spin_button_get_value (GTK_SPIN_BUTTON(spin_button_start_time));
	m_end_time =gtk_spin_button_get_value (GTK_SPIN_BUTTON(spin_button_end_time));		
		
	event.start_time=m_start_time;
	event.end_time=m_end_time;
	
	if(event.end_time<event.start_time) {
		event.end_time=event.start_time;
	}
	//GTK_IS_CHECK_BUTTON
	event.is_yearly=gtk_check_button_get_active (GTK_CHECK_BUTTON(check_button_isyearly));
	event.is_allday=gtk_check_button_get_active (GTK_CHECK_BUTTON(check_button_allday));
	event.priority=gtk_check_button_get_active(GTK_CHECK_BUTTON(check_button_priority));	
	db_store[i]=event;	
	break;	
	} //if
	
    } //for
		
	update_calendar(GTK_WINDOW(window));
	update_store(m_year,m_month,m_day);
	m_row_index=-1;
	m_id_selection=-1;
	
	}
			
	gtk_window_destroy(GTK_WINDOW(dialog));	
}




//----------------------------------------------------------------------
static void callbk_edit_event(GtkButton *button, gpointer  user_data){
	
	
	if (m_id_selection==-1) return;
		
	GtkWindow *window =user_data;
	
	GtkWidget *dialog; 
	GtkWidget *box;  
	GtkWidget *label_date;  
	GtkEntryBuffer *buffer_title; 
	
	GtkWidget *label_entry_title; 
	GtkWidget *entry_title;	
	
    
    GtkWidget *label_notes;
	GtkWidget *text_view_notes;    
    GtkTextBuffer *buffer_notes;
   
	//Start time
	GtkWidget *label_start_time;
	GtkWidget *spin_button_start_time;	
	GtkWidget *box_start_time;
	
	//End time
	GtkWidget *label_end_time;	
	GtkWidget *spin_button_end_time;	
	GtkWidget *box_end_time;
	
	//Check buttons
	GtkWidget *check_button_allday;	
	GtkWidget *check_button_isyearly;
	GtkWidget *check_button_priority;
	
	GDate *event_date; 
	event_date = g_date_new();
	event_date = g_date_new_dmy(m_day,m_month,m_year);
	int event_day= g_date_get_day(event_date);
	int event_month= g_date_get_month(event_date);
	int event_year= g_date_get_year(event_date);
	
	gchar * date_str="Event Date: ";
	gchar *day_str = g_strdup_printf("%d",event_day); 
	gchar *month_str = g_strdup_printf("%d",event_month); 
	gchar *year_str = g_strdup_printf("%d",event_year);
	
	date_str =g_strconcat(date_str,day_str,"-",month_str,"-",year_str,NULL); 
	
    dialog = gtk_dialog_new_with_buttons ("Edit Event", GTK_WINDOW(window), 
	GTK_DIALOG_MODAL|GTK_DIALOG_DESTROY_WITH_PARENT|GTK_DIALOG_USE_HEADER_BAR,
	"OK", GTK_RESPONSE_OK, "Cancel", GTK_RESPONSE_CANCEL, NULL);
	
	gtk_window_set_title (GTK_WINDOW (dialog), "Edit Event");
	gtk_window_set_default_size(GTK_WINDOW(dialog),350,100);  
	
	box =gtk_box_new(GTK_ORIENTATION_VERTICAL,1);  
	gtk_window_set_child (GTK_WINDOW (dialog), box);
		
	//find event in database    
	Event e;
    for(int i=0; i<m_db_size; i++)
    {
	e=db_store[i];	
	if(e.id==m_id_selection){	
	m_title =e.title;
	m_notes =e.notes;	
	m_year=e.year;
	m_month=e.month;
	m_day=e.day;            
	break;	
	}	
    }
		
	label_date =gtk_label_new(date_str);  
	
	label_entry_title =gtk_label_new("Event Title"); 
    entry_title =gtk_entry_new(); 
    gtk_entry_set_max_length(GTK_ENTRY(entry_title),100);
    buffer_title=gtk_entry_buffer_new(m_title,-1); //show  title
	gtk_entry_set_buffer(GTK_ENTRY(entry_title),buffer_title);
	    
	//---------------------------------------------------------
	// Notes entry
	//----------------------------------------------------------     
	label_notes =gtk_label_new("Notes ");   
	buffer_notes = gtk_text_buffer_new (NULL);
	//load buffer with notes data location
	gtk_text_buffer_set_text(buffer_notes, m_notes, -1); 		 
	text_view_notes = gtk_text_view_new_with_buffer (buffer_notes); 
	gtk_text_view_set_editable(GTK_TEXT_VIEW(text_view_notes),TRUE);  
	gtk_text_view_set_wrap_mode (GTK_TEXT_VIEW (text_view_notes), GTK_WRAP_WORD); 	
	set_text_view_border(text_view_notes);
	
    g_object_set_data(G_OBJECT(dialog), "text-view-notes-key",text_view_notes);
   
	gtk_box_append(GTK_BOX(box), label_date);
     
     gtk_box_append(GTK_BOX(box), label_entry_title);
     gtk_box_append(GTK_BOX(box), entry_title);
     
     gtk_box_append(GTK_BOX(box), label_notes);
	 gtk_box_append(GTK_BOX(box), text_view_notes);	
    
     
    g_object_set_data(G_OBJECT(dialog), "entry-title-key",entry_title);    
     g_object_set_data(G_OBJECT(dialog), "dialog-window-key",window); 
	
	
  //start time spin
  GtkAdjustment *adjustment_start;
  adjustment_start = gtk_adjustment_new (8.00, 0.0, 23.59, 1.0, 1.0, 0.0);
  //start time spin
  label_start_time =gtk_label_new("Start Time (24 hour) "); 
  spin_button_start_time = gtk_spin_button_new (adjustment_start, 1.0, 2); 
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin_button_start_time),e.start_time);	 
  box_start_time=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,1);
  gtk_box_append (GTK_BOX(box_start_time),label_start_time);
  gtk_box_append (GTK_BOX(box_start_time),spin_button_start_time);  
  gtk_box_append(GTK_BOX(box), box_start_time);
  g_object_set_data(G_OBJECT(dialog), "spin-start-time-key",spin_button_start_time); 
  
  //end time spin
   GtkAdjustment *adjustment_end;
  //value,lower,upper,step_increment,page_increment,page_size
  adjustment_end = gtk_adjustment_new (8.00, 0.0, 23.59, 1.0, 1.0, 0.0);
  label_end_time =gtk_label_new("End Time (24 hour) ");
  spin_button_end_time = gtk_spin_button_new (adjustment_end, 1.0, 2); 
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin_button_end_time),e.end_time);	 
  box_end_time=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,1);
  gtk_box_append (GTK_BOX(box_end_time),label_end_time);
  gtk_box_append (GTK_BOX(box_end_time),spin_button_end_time);  
  gtk_box_append(GTK_BOX(box), box_end_time);
  g_object_set_data(G_OBJECT(dialog), "spin-end-time-key",spin_button_end_time);  
    
  //check buttons 
  check_button_allday = gtk_check_button_new_with_label ("Is All Day");
  gtk_check_button_set_active (GTK_CHECK_BUTTON(check_button_allday), e.is_allday);  
  
  g_object_set_data(G_OBJECT(check_button_allday), "cb_allday_spin_start_time_key",spin_button_start_time);
  g_object_set_data(G_OBJECT(check_button_allday), "cb_allday_spin_end_time_key",spin_button_end_time); 
  
  g_signal_connect_swapped (GTK_CHECK_BUTTON(check_button_allday), "toggled", 
  G_CALLBACK (callbk_check_button_allday_toggled), check_button_allday);
  
  if(e.is_allday) {
  gtk_widget_set_sensitive(spin_button_start_time,FALSE);	   
  gtk_widget_set_sensitive(spin_button_end_time,FALSE);	    
  }
  else {
  gtk_widget_set_sensitive(spin_button_start_time,TRUE);		
  gtk_widget_set_sensitive(spin_button_end_time,TRUE);		
  }
    
  check_button_isyearly = gtk_check_button_new_with_label("Is Yearly");
  check_button_priority = gtk_check_button_new_with_label ("Is High Priority");
  gtk_box_append(GTK_BOX(box), check_button_allday);
  gtk_box_append(GTK_BOX(box), check_button_isyearly);
  gtk_box_append(GTK_BOX(box), check_button_priority);
  
  gtk_check_button_set_active (GTK_CHECK_BUTTON(check_button_isyearly), e.is_yearly);
  
  gtk_check_button_set_active (GTK_CHECK_BUTTON(check_button_priority), e.priority);
	
  g_object_set_data(G_OBJECT(dialog), "check-button-allday-key",check_button_allday);
  g_object_set_data(G_OBJECT(dialog), "check-button-isyearly-key",check_button_isyearly);
  g_object_set_data(G_OBJECT(dialog), "check-button-priority-key",check_button_priority);
    
   set_widget_font_size(dialog);
  g_signal_connect (dialog, "response", G_CALLBACK (callbk_edit_event_response),window);
  
  gtk_window_present (GTK_WINDOW (dialog)); 

}
 
static void callbk_delete_selected(GtkButton *button, gpointer  user_data){
		
	if (m_row_index==-1) return;
	
	GtkWindow *window =user_data;
	
	//remove event from db  
	int j=0;
	Event e;
	for(int i=0; i<m_db_size; i++)
	{
	e=db_store[i];      
	if(e.id==m_id_selection){
	continue;
	}
	db_store[j] = db_store[i];
	j++;
	}
	
	////Decrement db size
	m_db_size=m_db_size-1;
	
	g_list_store_remove (m_store, m_row_index); //remove selected
	update_calendar(GTK_WINDOW(window));
	update_store(m_year, m_month, m_day); 
	
}

//----------------------------------------------------------------------
// flat csv database functions
//----------------------------------------------------------------------

int break_fields(char *s, char** data, int n)
{
	//n = number of fields
	//assumes comma delimiter
	
	int fields=0;
	int i;
	char *start=s; //start at begining of string
	char *end=s; //walking pointer
	
	for(i=0; i<n; i++)
	{
		while(*end !=',' && *end != '\0') {
			end++;			
		}
		
		if(*end =='\0') {
			
			data[i]=(char*) malloc(strlen(start)+1);
			strcpy(data[i],start);
			fields++;
			break;
		}
		else if (*end ==',') {
			*end ='\0';
			data[i]=(char*) malloc(strlen(start)+1);
			strcpy(data[i],start);
			start=end+1;
			end=start;
			fields++;
		}		
	}		
	return fields;	
} 

void load_csv_file(){	
	
	int field_num =11; //fixed for now?	
	char *data[field_num]; // fields
	//int i = 0; //counter	
    //int total_num_lines = 0; //total number of lines
    int ret;
    
	GFile *file;
    GFileInputStream *file_stream=NULL;   
	GDataInputStream *input = NULL;
    
    file = g_file_new_for_path("eventsdb.csv");

	file_stream = g_file_read(file, NULL, NULL);	
	if(!file_stream) {
		g_print("error: unable to open database\n");
		return;
	}
	
	input = g_data_input_stream_new (G_INPUT_STREAM (file_stream));
		
	while (TRUE) {
		
		char *line;
		line = g_data_input_stream_read_line (input, NULL, NULL, NULL);		
		if (line == NULL) break;
		
		Event e;  
		      
        ret=break_fields(line,data,field_num);
        //g_print("break_fields return value %d\n",ret);	
        
        if(ret != field_num) {
			g_print("database corrupted\n");				    
		    m_error_flag=1;
		    m_error="Database Corrupted Restart";
		    return;
		}
        
        
		
		for (int j=0; j<field_num;j++) {
			
			
			if (j==0) e.id =m_db_size; 
			if (j==1) strcpy(e.title,data[j]);
			if (j==2) strcpy(e.notes,data[j]);			
			if (j==3) e.year=atoi(data[j]);
			if (j==4) e.month=atoi(data[j]);
			if (j==5) e.day=atoi(data[j]);				          
			          
			if (j==6) e.start_time=atof(data[j]);
			if (j==7) e.end_time=atof(data[j]);          
			
			if (j==8) e.priority=atoi(data[j]);
			if (j==9) e.is_yearly=atoi(data[j]);
			if (j==10) e.is_allday=atoi(data[j]);
			
			//printf("data[%d] = %s\n",j, data[j]);
			free(data[j]);
			
		}
		
		db_store[m_db_size] =e;			
		m_db_size=m_db_size+1;		
		if(m_db_size>max_records)
		{
			g_print("Error: max number of records exceeded\n");
			exit(1);
		}
		//i++;		
	}
	
	//total_num_lines=i;
    //g_print("total_number_of_lines =%d\n",total_num_lines);	
	g_object_unref (file_stream);	
	g_object_unref (file);	
		
}

void save_csv_file(){

    GFile *file;
	gchar *file_name ="eventsdb.csv";

	GFileOutputStream *file_stream;
	GDataOutputStream *data_stream;
	
	//g_print("Saving csv data with filename = %s\n",file_name);
	
	file = g_file_new_for_path (file_name);
	file_stream = g_file_replace (file, NULL, FALSE, G_FILE_CREATE_NONE, NULL, NULL);
	
	if (file_stream == NULL) {
		g_object_unref (file);
		g_print("error: unable to open abd save database file\n");
		return;
	}

	data_stream = g_data_output_stream_new (G_OUTPUT_STREAM (file_stream));
	
	
	for (int i=0; i<m_db_size; i++)
	{
	char *line="";  
	Event e;
	e=db_store[i];     
	
	gchar *id_str = g_strdup_printf("%d", e.id); 
	gchar *year_str = g_strdup_printf("%d", e.year); 
	gchar *month_str = g_strdup_printf("%d", e.month);
	gchar *day_str = g_strdup_printf("%d", e.day); 
	
	gchar *starttime_str = g_strdup_printf("%0.2f", e.start_time); 
	gchar *endtime_str = g_strdup_printf("%0.2f", e.end_time);
	
	gchar *priority_str = g_strdup_printf("%d", e.priority); 
	gchar *isyearly_str = g_strdup_printf("%d", e.is_yearly); 
	gchar *isallday_str = g_strdup_printf("%d", e.is_allday); 
		
	
	line =g_strconcat(line,
	id_str,",",
	e.title,",",
	e.notes,",",	
	year_str,",",
	month_str,",",
	day_str,",",
	starttime_str,",",
	endtime_str,",",	
	priority_str,",",
	isyearly_str,",",
	isallday_str,",",
	"\n", NULL);
	
	g_data_output_stream_put_string (data_stream, line, NULL, NULL)	;
	}
	
	g_object_unref (data_stream);
	g_object_unref (file_stream);
	g_object_unref (file);
	
}
 



//----------------------------------------------------------------------

static void callbk_day_selected (GtkButton *button, gpointer user_data)
{
   
  GDate *date =user_data;  
  GtkWidget *window = g_object_get_data(G_OBJECT(button), "button-window-key");  
  int day =g_date_get_day(date);
  int month =g_date_get_month(date);  
  int year =g_date_get_year(date);
  m_day =day;
  m_month=month;
  m_year=year;  
  update_calendar(GTK_WINDOW(window)); 
  update_store(m_year,m_month,m_day);
}

static void callbk_next_month(GtkButton *button, gpointer user_data)
{
	
	GtkWindow *window = user_data;	
	
	m_month=m_month+1;
	m_day=1;
	
	if (m_month >= 13) {
	m_day=1;
	m_month = 1;
	m_year =m_year+1;
	}
	m_id_selection=-1;
	m_row_index=-1;
	update_calendar(GTK_WINDOW (window));
}

static void callbk_prev_month(GtkButton *button, gpointer user_data)
{
	
	GtkWindow *window = user_data;	
	
	m_month=m_month-1;
	m_day =1;
	if (m_month < 1)
	{
	m_month = 12;
	m_year=m_year-1;
	m_day=1;
	}
	m_id_selection=-1;
	m_row_index=-1;
	update_calendar(GTK_WINDOW (window));
	
}
//---------------------------------------------------------------------
//list box methods
//---------------------------------------------------------------------
static void add_separator (GtkListBoxRow *row, GtkListBoxRow *before, gpointer data)
{
  if (!before)
    return;

  gtk_list_box_row_set_header (row, gtk_separator_new (GTK_ORIENTATION_HORIZONTAL));
}
//---------------------------------------------------------------------
static void callbk_row_activated (GtkListBox    *listbox,
                                  GtkListBoxRow *row,
                                  gpointer       user_data){
   
  
  m_row_index = gtk_list_box_row_get_index (row);
 
  DisplayObject *obj = g_list_model_get_item (G_LIST_MODEL (m_store), m_row_index); 
   
   if(obj==NULL) return; 
   
   gint id_value;
   gchar* label_value;
  
   g_object_get (obj, "id", &id_value, NULL);
   g_object_get (obj, "label", &label_value, NULL);
 
  
  m_id_selection=id_value;
  
  
}
//---------------------------------------------------------------------
static void update_store(int year, int month, int day) {	
   
  g_list_store_remove_all (m_store);//clear
 
  Event e; 
  int start_time=0; 
  for (int i=0; i<m_db_size; i++)
  {
  e=db_store[i]; 
 
  if ((year==e.year && month ==e.month && day==e.day) || (e.is_yearly && month==e.month && day==e.day))
  {  
  
  DisplayObject *obj; 
  char *time_str="";
  char *title_str="";
  char* starthour_str="";
  char *startmin_str="";
  char* endhour_str="";
  char *endmin_str="";
  
  float integral_part, fractional_part;
  fractional_part = modff(e.start_time, &integral_part);  
  int start_hour =(int) integral_part; //start_hour
  fractional_part=round(fractional_part *100);
  int start_min=(int) (fractional_part); //start_min
  
  starthour_str = g_strdup_printf("%d", start_hour); 
  startmin_str = g_strdup_printf("%d", start_min);
  
  if (start_min <10){       
  time_str = g_strconcat(time_str, starthour_str,":0", startmin_str," ",NULL);
  } else
  {
  time_str = g_strconcat(time_str, starthour_str,":", startmin_str," ",NULL);
  }
  
   
 // now end time (optional)

 if(m_show_end_time){
	 
  float integral_part_end, fractional_part_end;
  fractional_part_end = modff(e.end_time, &integral_part_end);  
  int end_hour =(int) integral_part_end; //end_hour
  fractional_part_end=round(fractional_part_end *100);
  int end_min=(int) (fractional_part_end); //start_min
  
  endhour_str = g_strdup_printf("%d", end_hour); 
  endmin_str = g_strdup_printf("%d", end_min); 
  
  if (end_min <10){       
     time_str = g_strconcat(time_str,"to ",  endhour_str,":0", endmin_str," ",NULL);
    } else {
		time_str = g_strconcat(time_str,"to ", endhour_str,":", endmin_str," ",NULL);
	} 
 }//show_end_time 
  
  
  if (e.is_allday) {
	  time_str="All day.  ";
  }
  else {
	 time_str = g_strconcat(time_str,NULL);
  }
    
  char *display_str ="";
  title_str=e.title;  
  if(strlen(e.notes) ==0)
  {
	display_str = g_strconcat(display_str,time_str,title_str, NULL);  
  }
  else {    
   display_str = g_strconcat(display_str,time_str,title_str, "\n",e.notes, " ", NULL);
  }
  
  if(e.priority) {	  
	  display_str=g_strconcat(display_str, "\n","High Priority", NULL);
  }
  
  display_str=g_strconcat(display_str, "\n", NULL);
    
  
  float integral_part_sort, fractional_part_sort;
  fractional_part_sort = modff(e.start_time, &integral_part_sort);  
  int start_hour_sort =(int) integral_part_sort; //sort start_hour 
  fractional_part_sort=round(fractional_part_sort *100);
  int start_min_sort=(int) (fractional_part_sort); //sort start_min 
  
  start_time =start_hour_sort*60*60+60*start_min_sort;
  
  //create a g_object for sorting
  obj = g_object_new (display_object_get_type (),
  //"id",     e.id,
  "id",     e.id,
  "label",  display_str, 
  "starttime", start_time,   
  NULL); 					
						
  
  g_list_store_insert_sorted(m_store, obj, compare_items, NULL); 
  g_object_unref (obj);
  } //if selected date 
  } //for
}


//----------------------------------------------------------------------
static void reset_marked_dates() {
	
  //reset marked dates
  int i=0;
  for (i=0;i<31;i++) marked_date[i] = FALSE;
  num_marked_dates = 0;
  
}

static void update_marked_dates(int month, int year) {
	
  //reset marked dates 
  num_marked_dates = 0;  
  Event e;  
  for (int i=0; i<m_db_size; i++)
  {
  e=db_store[i];  
  if ((e.month==month && e.year ==year)  || (e.is_yearly && month==e.month))  
  {
	  marked_date[e.day-1]=TRUE; //zero index so 1=0
	  num_marked_dates= num_marked_dates+1;
  } //if
  } //for 
}

static void reset_priority_dates() {
	
  //reset marked dates
  int i=0;
  for (i=0;i<31;i++) priority_date[i] = FALSE;
  num_priority_dates = 0;
  
}

static void update_priority_dates(int month, int year) {
	
  //reset marked dates 
  num_priority_dates = 0;  
  Event e;  
  for (int i=0; i<m_db_size; i++)
  {
  e=db_store[i];  
  if ((e.month==month && e.year ==year && e.priority==1)  || (e.is_yearly && month==e.month && e.priority==1))  
  {
	  priority_date[e.day-1]=TRUE; //zero index so 1=0
	  num_priority_dates= num_priority_dates+1;
  } //if
  } //for 
}


//--------------------------------------------------------------------
// About
//----------------------------------------------------------------------
//-------------------------------------------------------------------
// About callbk
//-------------------------------------------------------------------
static void callbk_about(GSimpleAction * action, GVariant *parameter, gpointer user_data){
	
	
	GtkWindow *window = GTK_WINDOW (gtk_widget_get_ancestor (GTK_WIDGET (user_data),
                                                 GTK_TYPE_WINDOW));
		
	const gchar *authors[] = {"Alan Crispin", NULL};		
	GtkWidget *about_dialog;
	about_dialog = gtk_about_dialog_new();	
	gtk_window_set_transient_for(GTK_WINDOW(about_dialog),GTK_WINDOW(window));
	gtk_widget_set_size_request(about_dialog, 200,200);
    gtk_window_set_modal(GTK_WINDOW(about_dialog),TRUE);	
	gtk_about_dialog_set_program_name(GTK_ABOUT_DIALOG(about_dialog), " Talk Calendar");
	gtk_about_dialog_set_version (GTK_ABOUT_DIALOG(about_dialog), "Version 1.4.4");
	gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(about_dialog),"Copyright ?? 2022");
	gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(about_dialog),"Personal calendar with built-in speech synthesizer "); 
	gtk_about_dialog_set_license_type (GTK_ABOUT_DIALOG(about_dialog), GTK_LICENSE_GPL_3_0);
	gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(about_dialog),"https://github.com/crispinalan/"); 
	gtk_about_dialog_set_website_label(GTK_ABOUT_DIALOG(about_dialog),"Talk Calendar Website");
	gtk_about_dialog_set_authors(GTK_ABOUT_DIALOG(about_dialog), authors);
		
	gtk_about_dialog_set_logo_icon_name(GTK_ABOUT_DIALOG(about_dialog), "x-office-calendar");
	
	set_widget_font_size(about_dialog);	
	//gtk_widget_show(about_dialog);	
	gtk_window_present (GTK_WINDOW(about_dialog)); 
		
}

//-----------------------------------------------------------------------------------
// Talk Options
//----------------------------------------------------------------------------------

void callbk_talkoptions_response(GtkDialog *dialog, gint response_id,  gpointer  user_data)
{
	if(!GTK_IS_DIALOG(dialog)) { 
	g_print("talkoptions Response: not a dialog\n");	
	return;
	}
	
	GtkWidget *window = user_data;
	
	//checks
	GtkWidget *check_button_talk= g_object_get_data(G_OBJECT(dialog), "check-button-talk-key"); 
    GtkWidget *check_button_talk_startup= g_object_get_data(G_OBJECT(dialog), "check-button-talk-startup-key"); 
    GtkWidget *check_button_talk_event_number= g_object_get_data(G_OBJECT(dialog), "check-button-talk-event-number-key");
    GtkWidget *check_button_talk_times= g_object_get_data(G_OBJECT(dialog), "check-button-talk-times-key");
    GtkWidget *check_button_talk_title= g_object_get_data(G_OBJECT(dialog), "check-button-talk-title-key");
    GtkWidget *check_button_talk_notes= g_object_get_data(G_OBJECT(dialog), "check-button-talk-notes-key");
    GtkWidget *check_button_talk_overlap= g_object_get_data(G_OBJECT(dialog), "check-button-talk-overlap-key");
    GtkWidget *check_button_reset_all= g_object_get_data(G_OBJECT(dialog), "check-button-reset-all-key");
    
    GtkWidget *spin_button_talk_speed= g_object_get_data(G_OBJECT(dialog), "spin-talk-speed-key");
    
       
    if(response_id==GTK_RESPONSE_OK)
	{
	m_talk=gtk_check_button_get_active (GTK_CHECK_BUTTON(check_button_talk));
	m_talk_at_startup=gtk_check_button_get_active (GTK_CHECK_BUTTON(check_button_talk_startup));
	m_talk_event_number=gtk_check_button_get_active (GTK_CHECK_BUTTON(check_button_talk_event_number));
	m_talk_time=gtk_check_button_get_active(GTK_CHECK_BUTTON(check_button_talk_times));
	m_talk_title=gtk_check_button_get_active(GTK_CHECK_BUTTON(check_button_talk_title));
	m_talk_notes=gtk_check_button_get_active(GTK_CHECK_BUTTON(check_button_talk_notes));
	m_talk_overlap=gtk_check_button_get_active(GTK_CHECK_BUTTON(check_button_talk_overlap));
	
	m_talk_sample_rate=gtk_spin_button_get_value (GTK_SPIN_BUTTON(spin_button_talk_speed));
		
	m_talk_reset=gtk_check_button_get_active(GTK_CHECK_BUTTON(check_button_reset_all));
	
	if(m_talk_reset) {
		//reset everything 
	m_talk = 1;	
	m_talk_at_startup=1;
	m_talk_event_number=1;	
	m_talk_title=1;
	m_talk_notes=0;
	m_talk_time=0;
	m_talk_sample_rate=16000;	
	m_talk_overlap=0;		
    m_talk_reset=0; //toggle		
	}
	
	config_write();	
	//set_widget_font_size(dialog);
	update_calendar(GTK_WINDOW(window));
	update_store(m_year,m_month,m_day);
	update_header(GTK_WINDOW(window));
	gtk_window_destroy(GTK_WINDOW(dialog));
	
	}	
	gtk_window_destroy(GTK_WINDOW(dialog));	
    
	
}
//Talk Options
static void callbk_talkoptions(GSimpleAction* action, GVariant *parameter,gpointer user_data)
{
	//g_print("Talk options\n");
	
	GtkWidget *window =user_data;
	
	GtkWidget *dialog; 
	GtkWidget *box; 

	//Check buttons
	GtkWidget *check_button_talk;	
	GtkWidget *check_button_talk_startup;
	GtkWidget *check_button_talk_title;	
	GtkWidget *check_button_talk_times;
	GtkWidget *check_button_talk_notes;
	GtkWidget *check_button_talk_event_number;
	GtkWidget *check_button_talk_overlap;
	
	GtkWidget *check_button_reset_all;
	
	//Talk speed spin
	GtkWidget *label_talk_speed;  
	GtkWidget *spin_button_talk_speed;  
	GtkWidget *box_talk_speed;
			
	
	dialog = gtk_dialog_new_with_buttons ("Talk Options", GTK_WINDOW(window),   
	GTK_DIALOG_MODAL|GTK_DIALOG_DESTROY_WITH_PARENT|GTK_DIALOG_USE_HEADER_BAR,
	"OK", GTK_RESPONSE_OK, "Cancel", GTK_RESPONSE_CANCEL, NULL);
	
	gtk_window_set_title (GTK_WINDOW (dialog), "Talk Options");
	gtk_window_set_default_size(GTK_WINDOW(dialog),350,100);  
	
	box =gtk_box_new(GTK_ORIENTATION_VERTICAL,1);  
	gtk_window_set_child (GTK_WINDOW (dialog), box);
	
	check_button_talk = gtk_check_button_new_with_label ("Talk");
	check_button_talk_startup = gtk_check_button_new_with_label ("Talk At Startup");
	check_button_talk_title = gtk_check_button_new_with_label ("Talk Title");
	check_button_talk_notes = gtk_check_button_new_with_label ("Talk Notes");	
	check_button_talk_times = gtk_check_button_new_with_label ("Talk Time");
	check_button_talk_event_number = gtk_check_button_new_with_label ("Talk Event Number");
	check_button_talk_overlap = gtk_check_button_new_with_label ("Overlap Alert");	
	check_button_reset_all = gtk_check_button_new_with_label ("Reset All");
		
	
	gtk_check_button_set_active (GTK_CHECK_BUTTON(check_button_talk), m_talk);
	gtk_check_button_set_active (GTK_CHECK_BUTTON(check_button_talk_startup), m_talk_at_startup);
	gtk_check_button_set_active (GTK_CHECK_BUTTON(check_button_talk_times), m_talk_time);
	gtk_check_button_set_active (GTK_CHECK_BUTTON(check_button_talk_title), m_talk_title);
	gtk_check_button_set_active (GTK_CHECK_BUTTON(check_button_talk_notes), m_talk_notes);		
	gtk_check_button_set_active (GTK_CHECK_BUTTON(check_button_talk_event_number), m_talk_event_number);
	gtk_check_button_set_active (GTK_CHECK_BUTTON(check_button_talk_overlap), m_talk_overlap);
	gtk_check_button_set_active (GTK_CHECK_BUTTON(check_button_reset_all), m_talk_reset);
	
	g_object_set_data(G_OBJECT(dialog), "check-button-talk-key",check_button_talk);
	g_object_set_data(G_OBJECT(dialog), "check-button-talk-startup-key",check_button_talk_startup);	
	g_object_set_data(G_OBJECT(dialog), "check-button-talk-times-key",check_button_talk_times);
	g_object_set_data(G_OBJECT(dialog), "check-button-talk-title-key",check_button_talk_title);
	g_object_set_data(G_OBJECT(dialog), "check-button-talk-notes-key",check_button_talk_notes);
	g_object_set_data(G_OBJECT(dialog), "check-button-talk-event-number-key",check_button_talk_event_number);
	g_object_set_data(G_OBJECT(dialog), "check-button-talk-overlap-key",check_button_talk_overlap);
		
	g_object_set_data(G_OBJECT(dialog), "check-button-reset-all-key",check_button_reset_all);
	
	
	//talk speed spin    
	label_talk_speed =gtk_label_new("Talk Speaking Rate"); 
	spin_button_talk_speed = gtk_spin_button_new_with_range(16000.0,32000.0,1000.0);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin_button_talk_speed),m_talk_sample_rate);	 
	box_talk_speed=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,1);
	gtk_box_append (GTK_BOX(box_talk_speed),label_talk_speed);
	gtk_box_append (GTK_BOX(box_talk_speed),spin_button_talk_speed);  
	
	g_object_set_data(G_OBJECT(dialog), "spin-talk-speed-key",spin_button_talk_speed); 
	
	gtk_box_append(GTK_BOX(box), check_button_talk);
	gtk_box_append(GTK_BOX(box), check_button_talk_startup);
	gtk_box_append(GTK_BOX(box), check_button_talk_event_number);	
	gtk_box_append(GTK_BOX(box), check_button_talk_title);
	gtk_box_append(GTK_BOX(box), check_button_talk_times);
	gtk_box_append(GTK_BOX(box), check_button_talk_notes);
	gtk_box_append(GTK_BOX(box), check_button_talk_overlap);
	gtk_box_append(GTK_BOX(box), box_talk_speed);	
	gtk_box_append(GTK_BOX(box), check_button_reset_all);
	
	set_widget_font_size(dialog);		
	g_signal_connect (dialog, "response", G_CALLBACK (callbk_talkoptions_response),window);
	
	gtk_window_present (GTK_WINDOW (dialog)); 	
	
	
}

//----------------------------------------------------------------
// Calendar options
//-----------------------------------------------------------------

void callbk_calendar_options_response(GtkDialog *dialog, gint response_id,  gpointer  user_data)
{
	//g_print("Calendar Options Response\n");
	
	if(!GTK_IS_DIALOG(dialog)) { 
		g_print("Calendar Options Response: not a dialog\n");	
	return;
	}
	
	
	GtkWidget *check_button_holidays= g_object_get_data(G_OBJECT(dialog), "check-button-holidays-key");
    GtkWidget *check_button_end_time= g_object_get_data(G_OBJECT(dialog), "check-button-display-end-time-key");
    GtkWidget *check_button_adwaita_icons= g_object_get_data(G_OBJECT(dialog), "check-button-adwaita-icons-key");
    GtkWidget *check_button_startup_notification= g_object_get_data(G_OBJECT(dialog), "check-button-startup-notification-key");
    
	
	GtkWidget *check_button_today_border= g_object_get_data(G_OBJECT(dialog), "check-button-today-border"); 
	GtkWidget *check_button_event_border= g_object_get_data(G_OBJECT(dialog), "check-button-event-border"); 
	GtkWidget *check_button_holiday_border= g_object_get_data(G_OBJECT(dialog), "check-button-holiday-border"); 
	GtkWidget *check_button_priority_border= g_object_get_data(G_OBJECT(dialog), "check-button-priority-border"); 
	
	GtkWidget *check_button_reset= g_object_get_data(G_OBJECT(dialog), "check-button-reset"); 
	
	GtkWidget *colour_button_today= g_object_get_data(G_OBJECT(dialog), "colour-button-today-key"); 
	GtkWidget *colour_button_today_bg= g_object_get_data(G_OBJECT(dialog), "colour-button-today-bg-key"); 
	
	GtkWidget *colour_button_event= g_object_get_data(G_OBJECT(dialog), "colour-button-event-key"); 
	GtkWidget *colour_button_event_bg= g_object_get_data(G_OBJECT(dialog), "colour-button-event-bg-key"); 
	
	GtkWidget *colour_button_holiday= g_object_get_data(G_OBJECT(dialog), "colour-button-holiday-key");
	GtkWidget *colour_button_holiday_bg= g_object_get_data(G_OBJECT(dialog), "colour-button-holiday-bg-key"); 
	
    GtkWidget *colour_button_priority= g_object_get_data(G_OBJECT(dialog), "colour-button-priority-key");
	GtkWidget *colour_button_priority_bg= g_object_get_data(G_OBJECT(dialog), "colour-button-priority-bg-key"); 
	
	GtkWidget *spin_button_font_size= g_object_get_data(G_OBJECT(dialog), "spin-font-size-key");  
	
	GtkWidget *window = user_data;
	
	if(response_id==GTK_RESPONSE_OK)
	{
	
	m_holidays=gtk_check_button_get_active(GTK_CHECK_BUTTON(check_button_holidays));
	m_show_end_time=gtk_check_button_get_active(GTK_CHECK_BUTTON(check_button_end_time));
	m_use_adwaita_icons=gtk_check_button_get_active(GTK_CHECK_BUTTON(check_button_adwaita_icons));
	m_startup_notification=gtk_check_button_get_active(GTK_CHECK_BUTTON(check_button_startup_notification));	
	
	m_font_size =gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_button_font_size));
	
	
	m_today_frame=gtk_check_button_get_active (GTK_CHECK_BUTTON(check_button_today_border));
	m_event_frame=gtk_check_button_get_active (GTK_CHECK_BUTTON(check_button_event_border));
	m_holiday_frame=gtk_check_button_get_active (GTK_CHECK_BUTTON(check_button_holiday_border));
	m_priority_frame=gtk_check_button_get_active (GTK_CHECK_BUTTON(check_button_priority_border));
	//Today
	GdkRGBA rgba_today;
    gtk_color_chooser_get_rgba (GTK_COLOR_CHOOSER (colour_button_today), &rgba_today);
	m_today_red=rgba_today.red;
	m_today_green=rgba_today.green;
	m_today_blue=rgba_today.blue; 
	
	GdkRGBA rgba_today_bg;
    gtk_color_chooser_get_rgba (GTK_COLOR_CHOOSER (colour_button_today_bg), &rgba_today_bg);
	m_today_bg_red=rgba_today_bg.red;
	m_today_bg_green=rgba_today_bg.green;
	m_today_bg_blue=rgba_today_bg.blue;  
	
	//Event
	GdkRGBA rgba_event;
    gtk_color_chooser_get_rgba (GTK_COLOR_CHOOSER (colour_button_event), &rgba_event);
	m_event_red=rgba_event.red;
	m_event_green=rgba_event.green;
	m_event_blue=rgba_event.blue; 
	
	GdkRGBA rgba_event_bg;
    gtk_color_chooser_get_rgba (GTK_COLOR_CHOOSER (colour_button_event_bg), &rgba_event_bg);
	m_event_bg_red=rgba_event_bg.red;
	m_event_bg_green=rgba_event_bg.green;
	m_event_bg_blue=rgba_event_bg.blue;  
	
	//Holiday
	GdkRGBA rgba_holiday;
    gtk_color_chooser_get_rgba (GTK_COLOR_CHOOSER (colour_button_holiday), &rgba_holiday);
	m_holiday_red=rgba_holiday.red;
	m_holiday_green=rgba_holiday.green;
	m_holiday_blue=rgba_holiday.blue; 
	
	GdkRGBA rgba_holiday_bg;
    gtk_color_chooser_get_rgba (GTK_COLOR_CHOOSER (colour_button_holiday_bg), &rgba_holiday_bg);
	m_holiday_bg_red=rgba_holiday_bg.red;
	m_holiday_bg_green=rgba_holiday_bg.green;
	m_holiday_bg_blue=rgba_holiday_bg.blue;  
	
	//Priority
	GdkRGBA rgba_priority;
    gtk_color_chooser_get_rgba (GTK_COLOR_CHOOSER (colour_button_priority), &rgba_priority);
	m_priority_red=rgba_priority.red;
	m_priority_green=rgba_priority.green;
	m_priority_blue=rgba_priority.blue; 
	
	GdkRGBA rgba_priority_bg;
    gtk_color_chooser_get_rgba (GTK_COLOR_CHOOSER (colour_button_priority_bg), &rgba_priority_bg);
	m_priority_bg_red=rgba_priority_bg.red;
	m_priority_bg_green=rgba_priority_bg.green;
	m_priority_bg_blue=rgba_priority_bg.blue;  
	
	   
   m_colour_reset=gtk_check_button_get_active (GTK_CHECK_BUTTON(check_button_reset));
   
   if (m_colour_reset) {
   //reset everything  
   m_today_red =0.0;
   m_today_green =0.0;
   m_today_blue =0.0;
   m_today_bg_red =0.59;
   m_today_bg_green =0.98;
   m_today_bg_blue =0.59;
   m_today_frame =1;
   
   m_event_red =0.0;
   m_event_green =0.0;
   m_event_blue =0.0;
   m_event_bg_red =1.0;
   m_event_bg_green =0.8;
   m_event_bg_blue =0.8;
   m_event_frame =1;
   
   m_holiday_red =0.0;
   m_holiday_green =0.0;
   m_holiday_blue =0.0;
   m_holiday_bg_red =1.0;
   m_holiday_bg_green =1.0;
   m_holiday_bg_blue =0.7;
   m_holiday_frame =1;
   
   m_priority_red =0.0;
   m_priority_green =0.0;
   m_priority_blue =0.0;
   m_priority_bg_red =1.0;
   m_priority_bg_green =0.0;
   m_priority_bg_blue =0.4;
   m_priority_frame =1;
   
   m_colour_reset =0; 
   }
   
    config_write();		
	update_calendar(GTK_WINDOW(window));
	update_store(m_year,m_month,m_day);
	update_header(GTK_WINDOW(window));
    
   gtk_window_destroy(GTK_WINDOW(dialog));		
   
   }
   
	gtk_window_destroy(GTK_WINDOW(dialog));		
	
}


static void callbk_calendar_options(GSimpleAction* action, GVariant *parameter,gpointer user_data){
  
 GtkWidget *window =user_data;
	
	GtkWidget *dialog; 
	GtkWidget *box; 
	GtkWidget *box_today; 
	GtkWidget *box_event;
	GtkWidget *box_holiday;
	GtkWidget *box_priority;
	//gint response; 
	
	GtkWidget *check_button_holidays;
	GtkWidget *check_button_end_time;
	GtkWidget *check_button_startup_notification;
	GtkWidget *check_button_adwaita_icons;
	
	//font size
	GtkWidget *label_font_size;  
    GtkWidget *spin_button_font_size;  
    GtkWidget *box_font_size;
		
	//Today colours
	GtkWidget *label_today_text_colour;
	GtkWidget *label_today_bg_colour;
	GtkWidget *colour_button_today;
	GtkWidget *colour_button_today_bg;
			
	//Event colours
	GtkWidget *label_event_text_colour;
	GtkWidget *label_event_bg_colour;
	GtkWidget *colour_button_event;
	GtkWidget *colour_button_event_bg;
	
	//Holiday colours
	GtkWidget *label_holiday_text_colour;
	GtkWidget *label_holiday_bg_colour;
	GtkWidget *colour_button_holiday;
	GtkWidget *colour_button_holiday_bg;
	
	//Priority colours
	GtkWidget *label_priority_text_colour;
	GtkWidget *label_priority_bg_colour;
	GtkWidget *colour_button_priority;
	GtkWidget *colour_button_priority_bg;
	
	GtkWidget *check_button_today_border;
	GtkWidget *check_button_event_border;
	GtkWidget *check_button_holiday_border;
	GtkWidget *check_button_priority_border;
	
	GtkWidget *check_button_reset;
	
	dialog = gtk_dialog_new_with_buttons ("Calendar Options", GTK_WINDOW(window),   
	GTK_DIALOG_MODAL|GTK_DIALOG_DESTROY_WITH_PARENT|GTK_DIALOG_USE_HEADER_BAR,
	"OK", GTK_RESPONSE_OK, "Cancel", GTK_RESPONSE_CANCEL, NULL);
	
	gtk_window_set_title (GTK_WINDOW (dialog), "Calendar Options");
	gtk_window_set_default_size(GTK_WINDOW(dialog),350,100);  
	
	box =gtk_box_new(GTK_ORIENTATION_VERTICAL,1);  
	gtk_window_set_child (GTK_WINDOW (dialog), box);
	
	
	//General options
	check_button_holidays = gtk_check_button_new_with_label ("Show UK Public Holidays");
	check_button_end_time = gtk_check_button_new_with_label ("Show End Time");
	check_button_adwaita_icons = gtk_check_button_new_with_label ("Use Adwaita Button Icons");
	check_button_startup_notification= gtk_check_button_new_with_label ("Startup Notification");
	
	gtk_check_button_set_active (GTK_CHECK_BUTTON(check_button_holidays), m_holidays);
	gtk_check_button_set_active (GTK_CHECK_BUTTON(check_button_end_time), m_show_end_time);	
	gtk_check_button_set_active (GTK_CHECK_BUTTON(check_button_adwaita_icons), m_use_adwaita_icons);	
	gtk_check_button_set_active (GTK_CHECK_BUTTON(check_button_startup_notification), m_startup_notification);

	g_object_set_data(G_OBJECT(dialog), "check-button-holidays-key",check_button_holidays);
	g_object_set_data(G_OBJECT(dialog), "check-button-display-end-time-key",check_button_end_time);
	g_object_set_data(G_OBJECT(dialog), "check-button-adwaita-icons-key",check_button_adwaita_icons);
	g_object_set_data(G_OBJECT(dialog), "check-button-startup-notification-key",check_button_startup_notification);
	
	//Font size
	
	GtkAdjustment *adjustment;
	
	adjustment = gtk_adjustment_new (14.00, 8.0, 30.0, 1.0, 1.0, 0.0);
	spin_button_font_size = gtk_spin_button_new (adjustment, 1.0, 0);      
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin_button_font_size),m_font_size);
	gtk_spin_button_set_numeric(GTK_SPIN_BUTTON(spin_button_font_size),TRUE);		
	label_font_size =gtk_label_new("Font Size: "); 
	
	box_font_size=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,1);
	gtk_box_append (GTK_BOX(box_font_size),label_font_size);
	gtk_box_append (GTK_BOX(box_font_size),spin_button_font_size);  
	g_object_set_data(G_OBJECT(dialog), "spin-font-size-key",spin_button_font_size); 
		
	//-----------------------------------------------------------------
	// Colour Borders
	//-----------------------------------------------------------------
	check_button_today_border = gtk_check_button_new_with_label ("Today Border");
	gtk_check_button_set_active (GTK_CHECK_BUTTON(check_button_today_border), m_today_frame);
	g_object_set_data(G_OBJECT(dialog), "check-button-today-border",check_button_today_border);
	
	check_button_event_border = gtk_check_button_new_with_label ("Event Border");
	gtk_check_button_set_active (GTK_CHECK_BUTTON(check_button_event_border), m_event_frame);
	g_object_set_data(G_OBJECT(dialog), "check-button-event-border",check_button_event_border);
	
	check_button_holiday_border = gtk_check_button_new_with_label ("Holiday Border");
	gtk_check_button_set_active (GTK_CHECK_BUTTON(check_button_holiday_border), m_holiday_frame);
	g_object_set_data(G_OBJECT(dialog), "check-button-holiday-border",check_button_holiday_border);
	
	check_button_priority_border = gtk_check_button_new_with_label ("Priority Border");
	gtk_check_button_set_active (GTK_CHECK_BUTTON(check_button_priority_border), m_priority_frame);
	g_object_set_data(G_OBJECT(dialog), "check-button-priority-border",check_button_priority_border);
			
	//--------------------------------------------------------------
	// Today
	//--------------------------------------------------------------
	label_today_text_colour =gtk_label_new("Today Colour:");
	label_today_bg_colour =gtk_label_new("Background:");
			
	GdkRGBA rgba_color;
	rgba_color.red=m_today_red;
	rgba_color.green=m_today_green;
	rgba_color.blue=m_today_blue;
	rgba_color.alpha=1.0;	
	colour_button_today =gtk_color_button_new_with_rgba(&rgba_color);
	gtk_color_button_set_title(GTK_COLOR_BUTTON(colour_button_today), "Pick Today Colour");
		
	rgba_color.red=m_today_bg_red;
	rgba_color.green=m_today_bg_green;
	rgba_color.blue=m_today_bg_blue;
	rgba_color.alpha=1.0;
	colour_button_today_bg =gtk_color_button_new_with_rgba(&rgba_color);	
	gtk_color_button_set_title(GTK_COLOR_BUTTON(colour_button_today_bg), "Pick Today Background Colour");
		
	box_today=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,1);
	
	gtk_box_append (GTK_BOX(box_today),label_today_text_colour);
	gtk_box_append (GTK_BOX(box_today),colour_button_today);  
	gtk_box_append (GTK_BOX(box_today),label_today_bg_colour);
	gtk_box_append (GTK_BOX(box_today),colour_button_today_bg);
	gtk_box_append (GTK_BOX(box_today),check_button_today_border);
	
	gtk_box_set_homogeneous(GTK_BOX(box_today),1);
	gtk_box_set_spacing(GTK_BOX(box_today),3);   
	
	g_object_set_data(G_OBJECT(dialog), "colour-button-today-key",colour_button_today);
	g_object_set_data(G_OBJECT(dialog), "colour-button-today-bg-key",colour_button_today_bg);
		
	//--------------------------------------------------------------
	// Event
	//--------------------------------------------------------------
	label_event_text_colour =gtk_label_new("Event Colour:");
	label_event_bg_colour =gtk_label_new("Background:");
	
	rgba_color.red=m_event_red;
	rgba_color.green=m_event_green;
	rgba_color.blue=m_event_blue;
	rgba_color.alpha=1.0;
	colour_button_event = gtk_color_button_new_with_rgba(&rgba_color);
	gtk_color_button_set_title(GTK_COLOR_BUTTON(colour_button_event), "Pick Event Colour");
	
	rgba_color.red=m_event_bg_red;
	rgba_color.green=m_event_bg_green;
	rgba_color.blue=m_event_bg_blue;
	rgba_color.alpha=1.0;
	colour_button_event_bg = gtk_color_button_new_with_rgba(&rgba_color);
	gtk_color_button_set_title(GTK_COLOR_BUTTON(colour_button_event_bg), "Pick Event Background Colour");
	 	
	box_event=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,1);
	
	gtk_box_append (GTK_BOX(box_event),label_event_text_colour);
	gtk_box_append (GTK_BOX(box_event),colour_button_event);  
	gtk_box_append (GTK_BOX(box_event),label_event_bg_colour);
	gtk_box_append (GTK_BOX(box_event),colour_button_event_bg);
	gtk_box_append (GTK_BOX(box_event),check_button_event_border);
	
	gtk_box_set_homogeneous(GTK_BOX(box_event),1);
	gtk_box_set_spacing(GTK_BOX(box_event),3);   
	
	g_object_set_data(G_OBJECT(dialog), "colour-button-event-key",colour_button_event);
	g_object_set_data(G_OBJECT(dialog), "colour-button-event-bg-key",colour_button_event_bg);
		
	
	//--------------------------------------------------------------
	// Holiday
	//--------------------------------------------------------------
	
	label_holiday_text_colour =gtk_label_new("Holiday Colour:");
	label_holiday_bg_colour =gtk_label_new("Background:");
	
	rgba_color.red=m_holiday_red;
	rgba_color.green=m_holiday_green;
	rgba_color.blue=m_holiday_blue;
	rgba_color.alpha=1.0;	
	colour_button_holiday = gtk_color_button_new_with_rgba(&rgba_color);
	gtk_color_button_set_title(GTK_COLOR_BUTTON(colour_button_holiday), "Pick Holiday Colour");
	
	
	rgba_color.red=m_holiday_bg_red;
	rgba_color.green=m_holiday_bg_green;
	rgba_color.blue=m_holiday_bg_blue;
	rgba_color.alpha=1.0;
	colour_button_holiday_bg = gtk_color_button_new_with_rgba(&rgba_color);
	
	gtk_color_button_set_title(GTK_COLOR_BUTTON(colour_button_holiday_bg), "Pick Holiday Background Colour");
	 	
	box_holiday=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,1);
	
	gtk_box_append (GTK_BOX(box_holiday),label_holiday_text_colour);
	gtk_box_append (GTK_BOX(box_holiday),colour_button_holiday);  
	gtk_box_append (GTK_BOX(box_holiday),label_holiday_bg_colour);
	gtk_box_append (GTK_BOX(box_holiday),colour_button_holiday_bg);
	gtk_box_append (GTK_BOX(box_holiday),check_button_holiday_border);
	
	gtk_box_set_homogeneous(GTK_BOX(box_holiday),1);
	gtk_box_set_spacing(GTK_BOX(box_holiday),3);   
	
	g_object_set_data(G_OBJECT(dialog), "colour-button-holiday-key",colour_button_holiday);
	g_object_set_data(G_OBJECT(dialog), "colour-button-holiday-bg-key",colour_button_holiday_bg);
	
	//--------------------------------------------------------------
	// Priority
	//--------------------------------------------------------------
	
	label_priority_text_colour =gtk_label_new("Priority Colour:");
	label_priority_bg_colour =gtk_label_new("Background:");
	
	rgba_color.red=m_priority_red;
	rgba_color.green=m_priority_green;
	rgba_color.blue=m_priority_blue;
	rgba_color.alpha=1.0;	
	colour_button_priority = gtk_color_button_new_with_rgba(&rgba_color);
	gtk_color_button_set_title(GTK_COLOR_BUTTON(colour_button_priority), "Pick Priority Colour");
		
	rgba_color.red=m_priority_bg_red;
	rgba_color.green=m_priority_bg_green;
	rgba_color.blue=m_priority_bg_blue;
	rgba_color.alpha=1.0;
	colour_button_priority_bg = gtk_color_button_new_with_rgba(&rgba_color);
	
	gtk_color_button_set_title(GTK_COLOR_BUTTON(colour_button_priority_bg), "Pick Priority Background Colour");
		
	box_priority=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,1);
	
	gtk_box_append (GTK_BOX(box_priority),label_priority_text_colour);
	gtk_box_append (GTK_BOX(box_priority),colour_button_priority);  
	gtk_box_append (GTK_BOX(box_priority),label_priority_bg_colour);
	gtk_box_append (GTK_BOX(box_priority),colour_button_priority_bg);
	gtk_box_append (GTK_BOX(box_priority),check_button_priority_border);
	
	gtk_box_set_homogeneous(GTK_BOX(box_priority),1);
	gtk_box_set_spacing(GTK_BOX(box_priority),3);   
	
	g_object_set_data(G_OBJECT(dialog), "colour-button-priority-key",colour_button_priority);
	g_object_set_data(G_OBJECT(dialog), "colour-button-priority-bg-key",colour_button_priority_bg);
	
	//-----------------------------------------------------------------
	// reset check button
	//----------------------------------------------------------------	
	check_button_reset = gtk_check_button_new_with_label ("Reset All Colours");
	gtk_check_button_set_active (GTK_CHECK_BUTTON(check_button_reset), m_colour_reset);
	g_object_set_data(G_OBJECT(dialog), "check-button-reset",check_button_reset);
	
	 
	//--------------------------------------------------------------
	// top box
	//---------------------------------------------------------------
	
	
	gtk_box_append(GTK_BOX(box), check_button_holidays);
	gtk_box_append(GTK_BOX(box), check_button_end_time);
	gtk_box_append(GTK_BOX(box), check_button_startup_notification);
	gtk_box_append(GTK_BOX(box), check_button_adwaita_icons);
	gtk_box_append(GTK_BOX(box), box_font_size);
	
	gtk_box_append(GTK_BOX(box), box_today);	
	gtk_box_append(GTK_BOX(box), box_event);
	gtk_box_append(GTK_BOX(box), box_holiday);
	gtk_box_append(GTK_BOX(box), box_priority);	
	gtk_box_append(GTK_BOX(box), check_button_reset);
		gtk_box_set_spacing(GTK_BOX(box),5); 
	
	set_widget_font_size(dialog);		
	g_signal_connect (dialog, "response", G_CALLBACK (callbk_calendar_options_response),window);
	
	gtk_window_present (GTK_WINDOW (dialog)); 	
	

}
//---------------------------------------------------------------------
// Speak version
//---------------------------------------------------------------------

static void callbk_speak_version(GSimpleAction *action,
							G_GNUC_UNUSED  GVariant      *parameter,
							  gpointer       user_data){
	
	GtkWidget *window =user_data;	
	GList *wavlist=NULL;
			
	GList* word_list=NULL;	
	
	word_list =word_to_diphones("talk");	
	word_list =g_list_concat(word_list,word_to_diphones("calendar"));
	word_list =g_list_concat(word_list,word_to_diphones("pau"));
	word_list =g_list_concat(word_list,word_to_diphones("version"));
	word_list =g_list_concat(word_list,word_to_diphones("one"));
	word_list =g_list_concat(word_list,word_to_diphones("point"));
	word_list =g_list_concat(word_list,word_to_diphones("four"));
	word_list =g_list_concat(word_list,word_to_diphones("point"));
	word_list =g_list_concat(word_list,word_to_diphones("four"));
	
	
	//iterate over GList
	GList *l;
    for (l = word_list; l != NULL; l = l->next) {    
    char *str = l->data;
     
    char* diphone_wav_str =get_diphone_wav_path(str);
   	 
	 if (g_file_test(diphone_wav_str, G_FILE_TEST_IS_REGULAR)) {
	  wavlist = g_list_append(wavlist,diphone_wav_str);
	 }
	 else {
		 g_print("diphone_wav_str = %s NOT found\n",diphone_wav_str);
	 }    
     
     } //for-loop
	
	  
	char* merge_file ="/tmp/talkout.wav";	
	int num_files = g_list_length(wavlist);
	char* file_names[g_list_length(wavlist)];
	
	GList *wl;//iterate through GList wavlist
	int i=0; 
    for (wl = wavlist; wl != NULL; wl = wl->next) {    
    char *wstr = wl->data;
    //g_print("wavlist_str =%s\n",wstr);
    file_names[i] = wstr;	//populate char* array
    i=i+1;    
    } //for-loop
		
	merge_wav_files2(merge_file, num_files, file_names, m_talk_sample_rate);
	
	//clean up  lists
	g_list_free(word_list);
	g_list_free(wavlist);
	
	
	//play audio in a thread
	GThread *thread_audio; 	
	gchar* wav_file ="/tmp/talkout.wav"; 
	g_mutex_lock (&lock);
    thread_audio = g_thread_new(NULL, thread_playwav, wav_file);  
	g_thread_unref (thread_audio);	
	
	//Give back focus to calendar
	//gtk_window_set_focus(GTK_WINDOW(window), GTK_WIDGET(calendar));
	//work around
	update_header(GTK_WINDOW(window));    
    set_widget_font_size(window);    
    update_calendar(GTK_WINDOW (window)); 
		
}



//-----------------------------------------------------------------
// Keyboard shortcuts
//-----------------------------------------------------------------

static void callbk_shortcuts(GSimpleAction * action, GVariant *parameter, gpointer user_data){

	GtkWidget *window =user_data;
	GtkWidget *dialog; 
	GtkWidget *box; 
	//gint response; 
	
	//labels 	
	GtkWidget *label_speak_sc;
	GtkWidget *label_home_sc;
	GtkWidget *label_f12_sc;
	
	
	dialog = gtk_dialog_new_with_buttons ("Shortcut Keys", GTK_WINDOW(window), 
	GTK_DIALOG_MODAL|GTK_DIALOG_DESTROY_WITH_PARENT,
	"Close", GTK_RESPONSE_CLOSE,
	NULL);                                         
	
	gtk_window_set_default_size(GTK_WINDOW(dialog),380,100);  
	
	box =gtk_box_new(GTK_ORIENTATION_VERTICAL,1);  
	gtk_window_set_child (GTK_WINDOW (dialog), box);
	
	label_speak_sc=gtk_label_new("Speak: Spacebar");  
	label_home_sc=gtk_label_new("Goto today: Home key");
	label_f12_sc=gtk_label_new("Information: F12 function key");
		
	gtk_box_append(GTK_BOX(box), label_speak_sc);
	gtk_box_append(GTK_BOX(box),label_home_sc);
	gtk_box_append(GTK_BOX(box),label_f12_sc);
	
	gtk_window_present (GTK_WINDOW (dialog));
	g_signal_connect (dialog, "response", G_CALLBACK (gtk_window_destroy), NULL);

}


static void callbk_info(GSimpleAction *action, GVariant *parameter,  gpointer user_data){

	GtkWidget *window =user_data;
	GtkWidget *dialog; 
	GtkWidget *box; 
		
	
	GtkWidget *label_record_number;		
	GtkWidget *label_desktop_font;
	GtkWidget *label_gnome_text_scale;
	GtkWidget *label_font_size;	
	GtkWidget *label_work_dir;
	GtkWidget *label_working_dir;
		
	GSettings *settings;
                                               
   dialog = gtk_dialog_new_with_buttons ("Information", GTK_WINDOW(window), 
   GTK_DIALOG_MODAL|GTK_DIALOG_DESTROY_WITH_PARENT,
   "Close", GTK_RESPONSE_CLOSE,
   NULL);                                         
   
	gtk_window_set_default_size(GTK_WINDOW(dialog),380,100);  
	
	box =gtk_box_new(GTK_ORIENTATION_VERTICAL,1);  
	gtk_window_set_child (GTK_WINDOW (dialog), box);
	
	char* record_num_str =" Number of records (max 5000) = ";
	char* n_str = g_strdup_printf("%d", m_db_size);   
	record_num_str = g_strconcat(record_num_str, n_str,NULL);   
	label_record_number =gtk_label_new(record_num_str); 
	
	
	settings = g_settings_new ("org.gnome.desktop.interface");	
	
	gchar* desktop_font_str = g_settings_get_string (settings, "font-name");
	
	char* desktop_str = "Desktop font = ";
	desktop_str =g_strconcat(desktop_str, desktop_font_str,NULL); 	
	label_desktop_font=gtk_label_new(desktop_str); 
	
	gdouble sf =g_settings_get_double (settings,"text-scaling-factor");    
    //g_print("scale factor =%0.1lf\n",sf);
	char* gnome_text_scale_factor ="GNOME text scale actor = ";
	char* font_scale_value_str = g_strdup_printf("%0.2lf", sf);
	gnome_text_scale_factor=g_strconcat(gnome_text_scale_factor, font_scale_value_str,NULL); 
	label_gnome_text_scale=gtk_label_new(gnome_text_scale_factor); 
	
	char* font_size_str =" Talk Calendar font size = ";
	char* font_n_str = g_strdup_printf("%d", m_font_size);   
	font_size_str = g_strconcat(font_size_str, font_n_str,NULL);   
	label_font_size =gtk_label_new(font_size_str); 
		
	char *cur_dir;	
	cur_dir = g_get_current_dir ();	
	char* dir_str ="";
	dir_str = g_strconcat(dir_str, cur_dir,NULL);
	label_work_dir=gtk_label_new("Working directory"); 
	label_working_dir=gtk_label_new(dir_str); 
	//g_print("current directory = %s\n", cur_dir);
	
	gtk_box_append(GTK_BOX(box), label_record_number);
	//gtk_box_append(GTK_BOX(box), label_font_name);	
	gtk_box_append(GTK_BOX(box),label_desktop_font);
	gtk_box_append(GTK_BOX(box),label_gnome_text_scale);
	gtk_box_append(GTK_BOX(box),label_font_size);
	gtk_box_append(GTK_BOX(box),label_work_dir);
	gtk_box_append(GTK_BOX(box),label_working_dir);
	
	set_widget_font_size(dialog);	
	gtk_window_present (GTK_WINDOW (dialog));
	g_signal_connect (dialog, "response", G_CALLBACK (gtk_window_destroy), NULL);
 	
}

static void callbk_delete_all_response(GtkDialog *dialog, gint response_id, gpointer  user_data)								 
{
	
	
	GtkWindow *window = user_data; //window data
    if(response_id==GTK_RESPONSE_OK)
	{    
    //g_print("Danger: Deleting everything\n");
    
    Event e_empty;
    e_empty.id=0;    
    strcpy(e_empty.title, "");   
    strcpy(e_empty.notes,"");   
    e_empty.year=0;
    e_empty.month=0;
    e_empty.day=0;
    e_empty.start_time=0;
    e_empty.end_time=0;	
    e_empty.priority=0;
    e_empty.is_yearly=0;
    e_empty.is_allday=0;
    
    for(int i=0;  i<m_db_size; i++)
    {
		db_store[i]=e_empty;		
	}
    
    reset_marked_dates(); 
    reset_priority_dates(); 
    update_calendar(GTK_WINDOW(window));
	update_store(m_year,m_month,m_day);
	m_db_size=0;
	m_id_selection=-1;
	m_row_index=-1; 	
    }
    gtk_window_destroy(GTK_WINDOW(dialog));	       

}

static void callbk_delete_all(GSimpleAction *action, GVariant *parameter,  gpointer user_data){

	
	GtkWindow *window = GTK_WINDOW (gtk_widget_get_ancestor (GTK_WIDGET (user_data),
	GTK_TYPE_WINDOW));
	
	if (!GTK_IS_WINDOW (window))
	{      
	g_print("callbk font: error not a window\n");
	return;      
	}
 
  GtkWidget *dialog;
 
  dialog = GTK_WIDGET (gtk_message_dialog_new (window,
                                               GTK_DIALOG_MODAL|
                                               GTK_DIALOG_DESTROY_WITH_PARENT|
                                               GTK_DIALOG_USE_HEADER_BAR,
                                               GTK_MESSAGE_INFO,
                                               GTK_BUTTONS_NONE,
                                               "Delete"));
  gtk_message_dialog_format_secondary_text (GTK_MESSAGE_DIALOG (dialog),
                                            "All events will be delete");
  gtk_dialog_add_buttons (GTK_DIALOG (dialog), 
                          "Cancel", GTK_RESPONSE_CANCEL,
                          "Delete", GTK_RESPONSE_OK,
                          NULL);  

  set_widget_font_size(dialog);
    
  g_signal_connect (dialog, "response", G_CALLBACK (callbk_delete_all_response),window);
  gtk_window_present (GTK_WINDOW (dialog));
}

static void callbk_home(GSimpleAction * action, GVariant *parameter, gpointer user_data){
	
		
   GtkWindow *window = GTK_WINDOW (gtk_widget_get_ancestor (GTK_WIDGET (user_data),
                                                 GTK_TYPE_WINDOW));
     
   if( !GTK_IS_WINDOW(window)) {
	   g_print("callbk home: not a window\n");	   	
       return;
   }
   
  GDate *current_date; 
  current_date = g_date_new();
  g_date_set_time_t (current_date, time (NULL)); 
  
  m_day =g_date_get_day(current_date);
  m_month =g_date_get_month(current_date);  
  m_year =g_date_get_year(current_date); 
  g_date_free (current_date);
    
  //mark days with events
  reset_marked_dates();
  reset_priority_dates();
  update_marked_dates(m_month,m_year);
  update_priority_dates(m_month,m_year);
  update_calendar(GTK_WINDOW (window)); 
  update_store(m_year,m_month,m_day); 
   
}

static void callbk_quit(GSimpleAction * action,
							G_GNUC_UNUSED GVariant      *parameter,
							              gpointer       user_data)
{
	
	g_application_quit(G_APPLICATION(user_data));
	
}

int compare (const void * a, const void * b)
{

  Event *eventA = (Event *)a;
  Event *eventB = (Event *)b;
  
  if (eventA->start_time>eventB->start_time) return 1;
    else if (eventA->start_time<eventB->start_time)return -1;
    return 0;
}


//---------------------------------------------------------------------
// startup and shutdown
//---------------------------------------------------------------------
int file_exists(const char *file_name)
{
    FILE *file;
    file = fopen(file_name, "r");
    if (file){       
        fclose(file);
        return 1; //file exists return 1
    }
    return 0; //file does not exist
}

static void startup (GtkApplication *app)
{
	create_diphones();
	//g_print("Allocating memory of size %d bytes\n",max_records*sizeof(Event));	
	db_store=malloc(max_records*sizeof(Event));
	
	if (db_store==NULL){
	g_print("memory allocation failed -not enough RAM\n");
	exit(1);
	}
	
	
	if(file_exists("eventsdb.csv"))
	{
		//g_print("eventsdb.csv exists-load it\n");
		load_csv_file();
	}
		
	 //---------------------------------------------------
  
		
}

void callbk_shutdown(GtkWindow *window, gint response_id,  gpointer  user_data){
	//g_print("shutdown function called\n");	
	save_csv_file();
	free(db_store);		
}


//--------------------------------------------------------------------
// public holidays
//---------------------------------------------------------------------
gboolean is_public_holiday(int day) {
	
// UK public holidays 
// New Year's Day: 1 January (DONE)
// Good Friday: March or April  (DONE)
// Easter Monday: March or April (DONE)
// Early May: First Monday of May (DONE)
// Spring Bank Holiday: Last Monday of May (DONE)
// Summer Bank Holiday: Last Monday of August (DONE)
// Christmas Day: 25 December (DONE)
// Boxing day: 26 December (DONE)
	
	//markup public holidays
	if (m_month==1 && day ==1) {  
	//new year	
	 return TRUE;
	}
	
	if (m_month==12 && day==25) {
	//christmas day
	return TRUE;	  
	} 
	
	if (m_month==12 && day==26) {
	//boxing day
	return TRUE;	  
	}
		
	if (m_month == 5) {
     //May complicated
     GDate *first_monday_may;
     first_monday_may = g_date_new_dmy(1, m_month, m_year);
             
     while (g_date_get_weekday(first_monday_may) != G_DATE_MONDAY)
       g_date_add_days(first_monday_may,1);
       
     int may_day = g_date_get_day(first_monday_may);  
       
     if( day==may_day) return TRUE;
     //else return FALSE;
     
     int days_in_may =g_date_get_days_in_month (m_month, m_year);
     int plus_days = 0;
     
     if (may_day + 28 <= days_in_may) {
       plus_days = 28;
     } else {
       plus_days = 21;
     }
     
     GDate *spring_bank =g_date_new_dmy (may_day, m_month, m_year);
     
     g_date_add_days(spring_bank,plus_days);
      
     int spring_bank_day = g_date_get_day(spring_bank);   
      
     if (g_date_valid_dmy (spring_bank_day,m_month,m_year) && day ==spring_bank_day) 
     return TRUE;       
	} //m_month==5 (may)
	
	GDate *easter_date =calculate_easter(m_year); 
	int easter_day = g_date_get_day(easter_date);
	int easter_month =g_date_get_month(easter_date);
	
	if(m_month==easter_month && day == easter_day)
	{
	//easter day
	return TRUE;
	}
	
	g_date_subtract_days(easter_date,2);
	int easter_friday = g_date_get_day(easter_date); 
	int easter_friday_month =g_date_get_month(easter_date); 
	
	if(m_month==easter_friday_month && day ==easter_friday)
	{
	//easter friday
	return TRUE;
	}
	
	g_date_add_days(easter_date,3);
	int easter_monday = g_date_get_day(easter_date); //easter monday
	int easter_monday_month =g_date_get_month(easter_date); 
    
	if(m_month==easter_monday_month && day ==easter_monday)
	{
	//easter monday
	return TRUE;
	}
	
	if (m_month == 8) {
      //August complicated
    GDate *first_monday_august;
     first_monday_august = g_date_new_dmy(1, m_month, m_year);
             
     while (g_date_get_weekday(first_monday_august) != G_DATE_MONDAY)
       g_date_add_days(first_monday_august,1);
       
     int august_day = g_date_get_day(first_monday_august);  
       
          
     int days_in_august =g_date_get_days_in_month (m_month, m_year);
     int plus_days = 0;
     
     if (august_day + 28 <= days_in_august) {
       plus_days = 28;
     } else {
       plus_days = 21;
     }
     
     GDate *august_bank =g_date_new_dmy (august_day, m_month, m_year);
     
     g_date_add_days(august_bank,plus_days);
      
     int august_bank_day = g_date_get_day(august_bank);   
      
     if (g_date_valid_dmy (august_bank_day,m_month,m_year) && day ==august_bank_day) 
     return TRUE;         
      
      
    } //m_month==8
		
	return FALSE;
}

char* get_holiday(int day) {
	
// UK public holidays 
// New Year's Day: 1 January (DONE)
// Good Friday: March or April  (DONE)
// Easter Monday: March or April (DONE)
// Early May: First Monday of May (TODO)
// Spring Bank Holiday: Last Monday of May (DONE)
// Summer Bank Holiday: Last Monday of August (DONE)
// Christmas Day: 25 December (DONE)
// Boxing day: 26 December (DONE)
	
	//markup public holidays
	if (m_month==1 && day ==1) { 
	return "New Year's Day";
	}
	
	if (m_month==12 && day==25) {
	//christmas day
	return "Christmas Day";	  
	} 
	
	if (m_month==12 && day==26) {
	//boxing day
	return "Boxing Day";	  
	}
	
	if (m_month == 5) {
     //May complicated
     GDate *first_monday_may;
     first_monday_may = g_date_new_dmy(1, m_month, m_year);
        
     
     while (g_date_get_weekday(first_monday_may) != G_DATE_MONDAY)
       g_date_add_days(first_monday_may,1);
       
     int may_day = g_date_get_day(first_monday_may);  
       
     if( day==may_day) return "May Bank Holiday";
     
     int days_in_may =g_date_get_days_in_month (m_month, m_year);
     
     int plus_days = 0;
     
     if (may_day + 28 <= days_in_may) {
       plus_days = 28;
     } else {
       plus_days = 21;
     }
     
     GDate *spring_bank =g_date_new_dmy (may_day, m_month, m_year);     
     g_date_add_days(spring_bank,plus_days);      
     int spring_bank_day = g_date_get_day(spring_bank);        
     if (g_date_valid_dmy (spring_bank_day,m_month,m_year) && day ==spring_bank_day) 
     return "Spring Bank Holiday";     
           
	} //m_month ==5 (May)
	
	GDate *easter_date =calculate_easter(m_year); 
	int easter_day = g_date_get_day(easter_date);
	int easter_month =g_date_get_month(easter_date);
	
	if(m_month==easter_month && day == easter_day)
	{
	//easter day
	return "Easter Day";
	}
	
	g_date_subtract_days(easter_date,2);
	int easter_friday = g_date_get_day(easter_date); 
	int easter_friday_month =g_date_get_month(easter_date); 
	
	if(m_month==easter_friday_month && day ==easter_friday)
	{
	//easter friday
	return "Easter Friday";
	}
	
	g_date_add_days(easter_date,3);
	int easter_monday = g_date_get_day(easter_date); //easter monday
	int easter_monday_month =g_date_get_month(easter_date); 
    
	if(m_month==easter_monday_month && day ==easter_monday)
	{
	//easter monday
	return "Easter Monday";
	}
	
	if (m_month == 8) {
      //August complicated
    GDate *first_monday_august;
     first_monday_august = g_date_new_dmy(1, m_month, m_year);
             
     while (g_date_get_weekday(first_monday_august) != G_DATE_MONDAY)
       g_date_add_days(first_monday_august,1);
       
     int august_day = g_date_get_day(first_monday_august);  
       
          
     int days_in_august =g_date_get_days_in_month (m_month, m_year);
     int plus_days = 0;
     
     if (august_day + 28 <= days_in_august) {
       plus_days = 28;
     } else {
       plus_days = 21;
     }
     
     GDate *august_bank =g_date_new_dmy (august_day, m_month, m_year);
     
     g_date_add_days(august_bank,plus_days);
      
     int august_bank_day = g_date_get_day(august_bank);   
      
     if (g_date_valid_dmy (august_bank_day,m_month,m_year) && day ==august_bank_day) 
     return "August Bank Holiday";   
     
    } //m_month==8
		
	return "";
}

//---------------------------------------------------------------------
// update ui
//---------------------------------------------------------------------
static void update_calendar(GtkWindow *window) {
	
 
  GtkWidget* label_date;
  GtkWidget *button;
  GtkWidget *grid;
  GtkWidget *button_next_month;
  GtkWidget *button_prev_month; 
  GtkWidget *sw; //scrolled window
  GtkWidget* listbox;
  GtkWidget *label; //for days of week Mon, Tue etc..
 
   //mark days with events
  reset_marked_dates();
  update_marked_dates(m_month,m_year);
  reset_priority_dates();
  update_priority_dates(m_month,m_year);
  
  grid =gtk_grid_new();
  gtk_window_set_child (GTK_WINDOW (window), grid);
  
  //GListStore *store;		
  m_store = g_list_store_new (display_object_get_type ()); 
  
  char* weekday_str="";
  GDate *day_date;
  day_date = g_date_new_dmy(m_day, m_month, m_year);
  GDateWeekday weekday =g_date_get_weekday(day_date);
  
  switch(weekday)
  {
  case G_DATE_MONDAY:                    
  weekday_str="Monday";
  break;
  case G_DATE_TUESDAY:          
  weekday_str="Tuesday";
  break;
  case G_DATE_WEDNESDAY:          
  weekday_str="Wednesday";
  break;
  case G_DATE_THURSDAY:          
  weekday_str="Thursday";
  break;
  case G_DATE_FRIDAY:          
  weekday_str="Friday";
  break;
  case G_DATE_SATURDAY:          
  weekday_str="Saturday";
  break;
  case G_DATE_SUNDAY:         
  weekday_str="Sunday";
  break;
  default:
  weekday_str="Unknown";  
  }//switch
 
  gchar* day_str =	g_strdup_printf("%d",m_day);    
  gchar *year_str = g_strdup_printf("%d",m_year ); 
  
  gchar * day_month_year_str="";
  
  day_month_year_str =g_strconcat(day_month_year_str,weekday_str," ", day_str, " ", NULL);
  
  switch(m_month)
     {
         case G_DATE_JANUARY:                    
          day_month_year_str =g_strconcat(day_month_year_str,"January ",year_str, NULL);
          break;
         case G_DATE_FEBRUARY:          
           day_month_year_str =g_strconcat(day_month_year_str,"February ",year_str, NULL);
           break;
         case G_DATE_MARCH:
           day_month_year_str =g_strconcat(day_month_year_str,"March ",year_str, NULL);
           break;
          case G_DATE_APRIL:
           day_month_year_str =g_strconcat(day_month_year_str,"April ",year_str, NULL); 
           break;        
          case G_DATE_MAY:
           day_month_year_str =g_strconcat(day_month_year_str,"May ",year_str, NULL);
           break;         
          case G_DATE_JUNE:
          day_month_year_str =g_strconcat(day_month_year_str,"June ",year_str, NULL); 
           break;        
          case G_DATE_JULY:
           day_month_year_str =g_strconcat(day_month_year_str,"July ",year_str, NULL);
           break;         
          case G_DATE_AUGUST:
           day_month_year_str =g_strconcat(day_month_year_str,"August ",year_str, NULL);
           break;         
          case G_DATE_SEPTEMBER:
           day_month_year_str =g_strconcat(day_month_year_str,"September ",year_str, NULL); 
           break;                  
          case G_DATE_OCTOBER:
           day_month_year_str =g_strconcat(day_month_year_str,"October ",year_str, NULL);
           break;         
          case G_DATE_NOVEMBER:
           day_month_year_str =g_strconcat(day_month_year_str,"November ",year_str, NULL);
           break;         
          case G_DATE_DECEMBER:
           day_month_year_str =g_strconcat(day_month_year_str,"December ",year_str, NULL);
           break;         
         default:
           day_month_year_str =g_strconcat(day_month_year_str,"Unknown ",year_str, NULL);
    }
   
   if (m_holidays) {
	   
	   //append holiday text
	   char * holiday_str = get_holiday(m_day);
	   day_month_year_str =g_strconcat(day_month_year_str," ",holiday_str, NULL);
   }
   
   label_date = gtk_label_new("");
   gtk_label_set_xalign(GTK_LABEL(label_date), 0.5);
   gtk_label_set_text(GTK_LABEL(label_date),day_month_year_str);
   
   PangoAttrList *attrs; //should I be using pango?
   attrs = pango_attr_list_new ();
   pango_attr_list_insert (attrs, pango_attr_weight_new (PANGO_WEIGHT_BOLD));
   gtk_label_set_attributes (GTK_LABEL (label_date), attrs);
   pango_attr_list_unref (attrs);
     
  int week_start = 1; //Monday 
  int day=0;  
  int remainder = (first_day_of_month(m_month,m_year) - week_start + 7) % 7;   
  day = 1 - remainder;   
  int n_cols=7;
  int n_rows=8; 
  gchar* btn_str="";
  
  button_next_month=gtk_button_new_with_label (">>");
  g_signal_connect (button_next_month, "clicked", G_CALLBACK (callbk_next_month),window);
  
  button_prev_month=gtk_button_new_with_label ("<<");
  g_signal_connect (button_prev_month, "clicked", G_CALLBACK (callbk_prev_month),window);  
   
  gtk_grid_attach(GTK_GRID(grid),button_prev_month,0,0,1,1); 
  gtk_grid_attach(GTK_GRID(grid),label_date,1,0,5,1);
  gtk_grid_attach(GTK_GRID(grid),button_next_month,6,0,1,1);
    	
 
  label= gtk_label_new("Mon");
  set_widget_font_size(label); 
  gtk_grid_attach(GTK_GRID(grid),label,0,1,1,1);
  
  label= gtk_label_new("Tue");
  set_widget_font_size(label);   
  gtk_grid_attach(GTK_GRID(grid),label,1,1,1,1);
  
  label= gtk_label_new("Wed");
  set_widget_font_size(label);
  gtk_grid_attach(GTK_GRID(grid),label,2,1,1,1);
  
  label= gtk_label_new("Thu");
  set_widget_font_size(label);
  gtk_grid_attach(GTK_GRID(grid),label,3,1,1,1);
  
  label= gtk_label_new("Fri");
  set_widget_font_size(label);
  gtk_grid_attach(GTK_GRID(grid),label,4,1,1,1);
  
  label= gtk_label_new("Sat");
  set_widget_font_size(label); 
  gtk_grid_attach(GTK_GRID(grid),label,5,1,1,1);
  
  label= gtk_label_new("Sun");
  set_widget_font_size(label);
  gtk_grid_attach(GTK_GRID(grid),label,6,1,1,1);
  
  GDate *today_date; 
  today_date = g_date_new();
  g_date_set_time_t (today_date, time (NULL));
  int today_day= g_date_get_day(today_date);
  int today_month= g_date_get_month(today_date);
  int today_year= g_date_get_year(today_date);
  
   
  int days_in_month =g_date_get_days_in_month (m_month, m_year); 
 
  for (int row=2; row<n_rows; row++)
    {
        
        for(int col=0; col<n_cols; col++)
        {
                
        if (day > 0 && day <= days_in_month) {
        
        btn_str =g_strdup_printf ("%d", day); //%i
        
        button = gtk_button_new_with_label (btn_str); 
        
        gtk_button_set_has_frame (GTK_BUTTON(button),m_frame); //no frame
		
		gtk_widget_set_hexpand(button, TRUE); //horizontal expand
		gtk_widget_set_vexpand(button,TRUE); //vertical expand
		
		 GDate *current_date = g_date_new();
		 g_date_set_dmy (current_date, day, m_month, m_year);
		
			
		
		//markup event days
		if(marked_date[day-1]) {			
			set_event_button_colour(GTK_BUTTON(button));			
		}
		
		if(priority_date[day-1]) {	
			//g_print("Priority day = %i\n",day);	
			set_priority_button_colour(GTK_BUTTON(button));		
		}
		
		if(is_public_holiday(day) && m_holidays) {
		set_holiday_button_colour(GTK_BUTTON(button));
	    }
	    
	    //Always show today color
	    if(day==today_day && m_month==today_month && m_year==today_year) {
			set_today_button_colour(GTK_BUTTON(button));
		}
	
		set_widget_font_size(button);
		g_object_set_data(G_OBJECT(button), "button-window-key",window);         
        g_signal_connect (button, "clicked", G_CALLBACK (callbk_day_selected), current_date);
        gtk_grid_attach(GTK_GRID(grid),button,col,row,1,1);	
        btn_str="";         
         }                        
        day=day+1;        
        }
        
    }

  //set scrolled window
  sw = gtk_scrolled_window_new ();
  gtk_widget_set_hexpand (GTK_WIDGET (sw), true);
  gtk_widget_set_vexpand (GTK_WIDGET (sw), true);
  
  listbox = gtk_list_box_new ();
  gtk_list_box_set_selection_mode (GTK_LIST_BOX (listbox), GTK_SELECTION_SINGLE);
  
  gtk_list_box_set_show_separators (GTK_LIST_BOX (listbox), TRUE);
 
  gtk_list_box_set_header_func (GTK_LIST_BOX (listbox), add_separator, NULL, NULL); 
  gtk_list_box_bind_model (GTK_LIST_BOX (listbox), G_LIST_MODEL (m_store), create_widget, NULL, NULL);
  g_signal_connect (listbox, "row-activated", G_CALLBACK (callbk_row_activated),NULL);
  gtk_scrolled_window_set_child (GTK_SCROLLED_WINDOW (sw), listbox);
  //col-rows (span all 7 days and a further 8 rows)
  gtk_grid_attach(GTK_GRID(grid),sw,0,n_rows+1,7,8);
  
  g_object_set_data(G_OBJECT(window), "window-listbox-key",listbox);
  
  
  set_widget_font_size(label_date);
  set_widget_font_size(button_next_month);
  set_widget_font_size(button_prev_month);
  set_widget_font_size(listbox);
  //set_widget_font_size(label);  
}

static void update_header (GtkWindow *window)
{
	GtkWidget *header;
	GtkWidget *button_new_event;
	GtkWidget *button_edit_event;
	GtkWidget *button_delete_selected;
	
	GtkWidget *menu_button; 
	GtkStyleContext *context;  //needed for adwaita button icons
				
	header = gtk_header_bar_new ();	
	gtk_window_set_titlebar (GTK_WINDOW(window), header);
	
		
	if(m_use_adwaita_icons){
	//appointment-new-symbolic or document-new-symbolic
	button_new_event = gtk_button_new_from_icon_name ("appointment-new-symbolic"); 	
	context = gtk_widget_get_style_context (button_new_event);
	gtk_style_context_add_class (context, "circular");
	gtk_style_context_add_class (context, "flat");
	gtk_widget_set_valign (button_new_event, GTK_ALIGN_CENTER); 
	} else {
		
		button_new_event = gtk_button_new_with_label ("New");
	}
			
	gtk_widget_set_tooltip_text(button_new_event, "New Event");
	g_signal_connect (button_new_event, "clicked", G_CALLBACK (callbk_new_event), window);	
	g_object_set_data(G_OBJECT(button_new_event), "button-window-key",window); 
	
	//button edit selected event
	
	if(m_use_adwaita_icons) {	
	//what to use --- document-edit-symbolic edit-redo-symbolic edit-select-symbolic
	//legacy:appointment-missed.png appointment-new.png appointment-soon.png
	button_edit_event = gtk_button_new_from_icon_name ("appointment-soon-symbolic"); 
	context = gtk_widget_get_style_context (button_edit_event);
	gtk_style_context_add_class (context, "circular");
	gtk_style_context_add_class (context, "flat");
	gtk_widget_set_valign (button_edit_event, GTK_ALIGN_CENTER); 
	} else {
	button_edit_event = gtk_button_new_with_label ("Edit");	
	}
	
	gtk_widget_set_tooltip_text(button_edit_event, "Edit Selected Event");
	g_signal_connect (button_edit_event, "clicked", G_CALLBACK (callbk_edit_event), window);    
	
	//button delete selected event
		
	if(m_use_adwaita_icons) {
	button_delete_selected = gtk_button_new_from_icon_name ("edit-delete-symbolic");
	context = gtk_widget_get_style_context (button_delete_selected);
	gtk_style_context_add_class (context, "circular");
	gtk_style_context_add_class (context, "flat");
	gtk_widget_set_valign (button_delete_selected, GTK_ALIGN_CENTER); 
	} else {
	button_delete_selected = gtk_button_new_with_label ("Delete");
	}
		
	gtk_widget_set_tooltip_text(button_delete_selected, "Delete Selected");  
	
	g_signal_connect (button_delete_selected, "clicked", G_CALLBACK (callbk_delete_selected), window);
		
	//Packing
	gtk_header_bar_pack_start(GTK_HEADER_BAR (header),button_new_event);
	gtk_header_bar_pack_start(GTK_HEADER_BAR (header),button_edit_event);   
	gtk_header_bar_pack_start(GTK_HEADER_BAR (header), button_delete_selected);
	//gtk_header_bar_pack_start(GTK_HEADER_BAR (header), button_speak);
	
	
	//Menu model
	GMenu *menu, *section; 	
	menu = g_menu_new ();  
	
	section = g_menu_new ();
	g_menu_append (section, "Calendar Options", "app.calendaroptions");	
	g_menu_append_section (menu, NULL, G_MENU_MODEL (section));
	g_object_unref (section);
	
	section = g_menu_new ();
	g_menu_append (section, "Talk Options", "app.talkoptions");	
	g_menu_append_section (menu, NULL, G_MENU_MODEL (section));
	g_object_unref (section);
		
	section = g_menu_new ();
	g_menu_append (section, "Speak", "app.speak"); 	
	g_menu_append_section (menu, NULL, G_MENU_MODEL (section));
	g_object_unref (section);
	
	//section = g_menu_new ();
	//g_menu_append (section, "Shortcuts", "app.f1"); //show shortcuts
	//g_menu_append_section (menu, NULL, G_MENU_MODEL (section));
	//g_object_unref (section);
	
	//section = g_menu_new ();
	//g_menu_append (section, "Information", "app.f12"); //show app info	
	//g_menu_append_section (menu, NULL, G_MENU_MODEL (section));
	//g_object_unref (section);
		
	//section = g_menu_new ();
	//g_menu_append (section, "Delete All", "app.delete");	
	//g_menu_append_section (menu, NULL, G_MENU_MODEL (section));
	//g_object_unref (section);
	
	//section = g_menu_new ();
	//g_menu_append (section, "About", "app.about");	
	//g_menu_append_section (menu, NULL, G_MENU_MODEL (section));
	//g_object_unref (section);
	
	
	section = g_menu_new ();
	g_menu_append (section, "Information", "app.info"); //show app info
	g_menu_append (section, "Shortcuts", "app.shortcuts"); //show shortcuts
	g_menu_append (section, "Speak Version", "app.version");  //speak version	
	g_menu_append (section, "About", "app.about");
	g_menu_append_submenu (menu, "_Help", G_MENU_MODEL (section));
	g_object_unref (section);
	
	section = g_menu_new ();
	g_menu_append (section, "Quit", "app.quit");
	g_menu_append_section (menu, NULL, G_MENU_MODEL(section));
	g_object_unref (section);
	
	//Now hamburger style menu button
	menu_button = gtk_menu_button_new();
	gtk_widget_set_tooltip_text(menu_button, "Menu");
	gtk_menu_button_set_icon_name (GTK_MENU_BUTTON (menu_button),"open-menu-symbolic"); 		
	gtk_menu_button_set_menu_model (GTK_MENU_BUTTON (menu_button), G_MENU_MODEL(menu));
	
	//gtk_widget_show (menu_button);  
	gtk_header_bar_pack_end(GTK_HEADER_BAR (header), menu_button);
	//gtk_header_bar_pack_end(GTK_HEADER_BAR (header), button_speak);
		
	set_widget_font_size(header);
	set_widget_font_size(button_new_event);
	set_widget_font_size(button_edit_event);
	set_widget_font_size(button_delete_selected);
	//set_widget_font_size(button_speak);
	set_widget_font_size(menu_button);
	
}
    

//----------------------------------------------------------------------

static void activate (GtkApplication *app, gpointer  user_data)
{
  GtkWidget *window;
  //GtkWidget *header;  
   
   
  const gchar *speak_accels[2] = { "space", NULL }; 
  const gchar *home_accels[2] = { "Home", NULL }; 
  const gchar *f1_accels[2] = { "F1", NULL };
  const gchar *f12_accels[2] = { "F12", NULL };
  
  // create a new window, and set its title 
  window = gtk_application_window_new (app);
  gchar *title ="Talk Calendar";
  
  if (m_error_flag) {
	  title=m_error;
  }
  gtk_window_set_title (GTK_WINDOW (window), title);
  //m_error_flag=0; //reset on start up
  gtk_window_set_default_size(GTK_WINDOW (window),700,400);
  g_signal_connect (window, "destroy", G_CALLBACK (callbk_shutdown), NULL);
    
  GDate *current_date; 
  current_date = g_date_new();
  g_date_set_time_t (current_date, time (NULL)); 
  
  m_day =g_date_get_day(current_date);
  m_month =g_date_get_month(current_date);  
  m_year =g_date_get_year(current_date);
  
  m_today_day =m_day;
  m_today_month=m_month;
  m_today_year =m_year;
  
  g_date_free (current_date);
  
  //startup notifcation
  if(m_startup_notification) {
  char* message="You have ";
  char *event_number_str;
  int event_number=get_number_of_events();
  
  if (event_number==0) event_number_str = "no events today";
  else if (event_number==1) {
  event_number_str = g_strdup_printf("%i", event_number); 
  event_number_str =g_strconcat(event_number_str," event today", NULL);
  }
  else {
  event_number_str = g_strdup_printf("%i", event_number); 
  event_number_str =g_strconcat(event_number_str," events today", NULL);	  
  }
  message=g_strconcat(message,event_number_str, NULL);	
  show_notification(message);
  } //if startup notification
  
    
  //mark days with events
  reset_marked_dates();
  update_marked_dates(m_month,m_year);
  reset_priority_dates();
  update_priority_dates(m_month,m_year);  
  
  	
	GSimpleAction *speak_action;	
	speak_action=g_simple_action_new("speak",NULL); //app.speak
	g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(speak_action)); //add to action_map	
	g_signal_connect(speak_action, "activate",  G_CALLBACK(callbk_speak), window);
	
	GSimpleAction *speak_version_action;	
	speak_version_action=g_simple_action_new("version",NULL); //app.version
	g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(speak_version_action)); //add to action_map		
	g_signal_connect(speak_version_action, "activate",  G_CALLBACK(callbk_speak_version), window);
	
	
	
	GSimpleAction *f12_action;	
	f12_action=g_simple_action_new("f12",NULL); //app.f12
	g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(f12_action)); //add to action_map		
	g_signal_connect(f12_action, "activate",  G_CALLBACK(callbk_info), window);
	
	GSimpleAction *f1_action;	
	f1_action=g_simple_action_new("f1",NULL); //app.f1
	g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(f1_action)); //add to action_map		
	g_signal_connect(f1_action, "activate",  G_CALLBACK(callbk_shortcuts), window);
	
	GSimpleAction *about_action;	
	about_action=g_simple_action_new("about",NULL); //app.about
	g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(about_action)); //add to action_map	
	g_signal_connect(about_action, "activate",  G_CALLBACK(callbk_about), window);

	GSimpleAction *calendar_options_action;	
	calendar_options_action=g_simple_action_new("calendaroptions",NULL); //app.calendaroptions
	g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(calendar_options_action)); //add to action_map		
	g_signal_connect(calendar_options_action, "activate",  G_CALLBACK(callbk_calendar_options), window);
		
	GSimpleAction *talkoptions_action;	
	talkoptions_action=g_simple_action_new("talkoptions",NULL); //app.talkoptions
	g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(talkoptions_action)); //add to action_map		
	g_signal_connect(talkoptions_action, "activate",  G_CALLBACK(callbk_talkoptions), window);
			
	GSimpleAction *home_action;	
	home_action=g_simple_action_new("home",NULL); //app.home
	g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(home_action)); //add to action_map		
	g_signal_connect(home_action, "activate",  G_CALLBACK(callbk_home), window);
	
	GSimpleAction *delete_events_action;	
	delete_events_action=g_simple_action_new("delete",NULL); //action = app.delete
	g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(delete_events_action)); //add to action_map	
	g_signal_connect(delete_events_action, "activate",  G_CALLBACK(callbk_delete_all), window);
	
		
	GSimpleAction *info_action;	
	info_action=g_simple_action_new("info",NULL); //app.info
	g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(info_action)); //add to action_map		
	g_signal_connect(info_action, "activate",  G_CALLBACK(callbk_info), window);
	
	
	GSimpleAction *shortcuts_action;	
	shortcuts_action=g_simple_action_new("shortcuts",NULL); //app.shortcuts
	g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(shortcuts_action)); //add to action_map		
	g_signal_connect(shortcuts_action, "activate",  G_CALLBACK(callbk_shortcuts), window);
	
	GSimpleAction *quit_action;	
	quit_action=g_simple_action_new("quit",NULL); //app.quit
	g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(quit_action)); //add to action_map		
	g_signal_connect(quit_action, "activate",  G_CALLBACK(callbk_quit), app);
	
    
  // connect keyboard accelerators  
	gtk_application_set_accels_for_action(GTK_APPLICATION(app),
	"app.speak", speak_accels); 
	
	gtk_application_set_accels_for_action(GTK_APPLICATION(app),
	"app.home", home_accels); 
	
	gtk_application_set_accels_for_action(GTK_APPLICATION(app),
	"app.f12", f12_accels); 
	
	gtk_application_set_accels_for_action(GTK_APPLICATION(app),
	"app.f1", f1_accels); 
	
    update_header(GTK_WINDOW(window));
    
    set_widget_font_size(window);
    
  update_calendar(GTK_WINDOW (window));  
  //gtk_widget_show (window); //use present with gtk4
  gtk_window_present (GTK_WINDOW (window));     
  update_store(m_year,m_month,m_day); 
    
  if(m_talk && m_talk_at_startup) speak_events(); 
    
}

int main (int  argc, char **argv)
{
  
  config_initialize();
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.talkcalendar", G_APPLICATION_FLAGS_NONE);
  
  g_signal_connect_swapped(app, "startup", G_CALLBACK (startup),app);
  
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
