/***************************************************************************
 * GPL v2.0 license (see license document distributed with this software)
 * Talk Calendar Gtk
 * Author: crispinalan@gmail.com
 ***************************************************************************/

#include <gtk/gtk.h>
#include <glib.h>
#include <glib/gstdio.h>
#include <math.h>
#include "dbmanager.h"
#include "event.h"
#include <gdk/gdk.h>
//#include<libnotify/notify.h>
#include <flite/flite.h>

// Definitions
#define CONFIG_DIRNAME "talkcalendar-v1-4"
#define CONFIG_FILENAME "talkcalendar-config-v1-4"

//flite voice
cst_voice *register_cmu_us_kal();

//Action callbacks
static void callbk_import(GSimpleAction * action, GVariant  *parameter, gpointer user_data);
static void callbk_export(GSimpleAction * action, GVariant *parameter,  gpointer user_data);
static void callbk_delete(GSimpleAction *action, GVariant *parameter,  gpointer user_data);
static void callbk_speak(GSimpleAction* action, GVariant *parameter,gpointer user_data);
static void callbk_preferences(GSimpleAction* action, GVariant *parameter,gpointer user_data);
static void callbk_font(GSimpleAction* action, GVariant *parameter,gpointer user_data);
static void callbk_about(GSimpleAction * action, GVariant *parameter, gpointer user_data);
static void callbk_quit(GSimpleAction * action, GVariant *parameter, gpointer user_data);
static void callbk_home(GSimpleAction * action, GVariant *parameter, gpointer user_data);
static void callbk_speak_about(GSimpleAction *action, GVariant *parameter, gpointer user_data);
static void callbk_shortcuts(GSimpleAction * action, GVariant *parameter, gpointer user_data);

//Calendar callbacks
static void callbk_calendar_day_clicked(GtkCalendar *calendar, gpointer user_data);
static void callbk_calendar_day_double_click(GtkCalendar *calendar, gpointer user_data);
static void callbk_calendar_month_changed(GtkCalendar *calendar, gpointer user_data);

//Button click callbacks
static void callbk_new_event(GtkWidget *button, GtkWidget* window);
static void callbk_alarm(GtkWidget *button, GtkWidget* window);
//static void callbk_preferences(GtkWidget *button, GtkWidget* window);

//dialogs
static void talkcalendar_talk_options_dialog(GtkWidget *widget);
static void talkcalendar_other_options_dialog(GtkWidget *widget);
static void talkcalendar_alarm_dialog(GtkWidget *widget);
static void talkcalendar_new_event(GtkWidget *widget, guint year, guint month, guint day);
static void talkcalendar_update_event(GtkWidget *widget, gpointer data);

//holidays
GDate* calculate_easter(gint year);
static void mark_holidays_on_calendar(GtkCalendar *calendar, gint month, gint year);
void change_window_font_size(GtkWindow *window);



//other
static void show_notification(gchar *message, GtkApplication* app); //desktop notifications 
static void speak_events_at_date(GtkCalendar *calendar);

// map menu actions to callbacks
const GActionEntry app_actions[] = {
  { "import", callbk_import },
  { "export", callbk_export},
  { "delete", callbk_delete },
  { "speak", callbk_speak },
  { "preferences", callbk_preferences },  
  { "version", callbk_speak_about},
  { "home", callbk_home},
  { "shortcuts",  callbk_shortcuts},
  { "about",  callbk_about},
  { "quit",   callbk_quit}
};

//declarations
GtkWidget *create_view_and_model(Event *event_arry, gint arry_size);
GtkTreeModel *create_and_fill_model(Event *event_arry, gint arry_size);
//static void callbk_new_event(GtkWidget *window);

//static void callbk_preferences(GSimpleAction *action,G_GNUC_UNUSED  GVariant *parameter,gpointer user_data);
//static void callbk_gotoday(GSimpleAction *action, G_GNUC_UNUSED  GVariant  *parameter,	gpointer window);


//Static variables (configuration variables)
static char * m_config_file = NULL;

static GMutex lock;
gint debug=0;

static int m_talk =1;
static int m_talk_title =0;
static int m_talk_time =0;
static int m_talk_priority =0;
static int m_talk_at_startup=1;
static int m_talk_description =0;

static int m_font_size=22;
static const gchar* m_font_family="Sans";

static int m_holidays=0; //show holidays

static int m_alarm_notification=1;
static int m_alarm_hour=0;
static int m_alarm_min=0;


const int COLUMN = 1;
const int NUM_COLS = 2;

static void config_load_default()
{		
	if(!m_talk) m_talk=1;
	if(!m_talk_at_startup) m_talk_at_startup=1;
	if(!m_talk_title) m_talk_title =1;
	if(!m_talk_time) m_talk_time =1;
	if(!m_talk_priority) m_talk_priority =0;
	if(!m_talk_description) m_talk_description =0;
	
	m_font_family="Sans";
	if(!m_font_size) m_font_size=22;  
	
	if(!m_holidays) m_holidays=0;
	
	if(!m_alarm_notification) m_alarm_notification=0;
	if(!m_alarm_hour) m_alarm_hour=0;
	if(!m_alarm_min) m_alarm_min=0;
	
}

static void config_read()
{
	// Clean up previously loaded configuration values	
	m_talk = 1;
	m_talk_title =1;
	m_talk_time =1;
	m_talk_at_startup=1;
	m_talk_priority =0;
	m_talk_description =0;
	
	m_font_family="Sans"; 
	m_font_size=22; 
	
	m_holidays=0;
	
	m_alarm_notification=1;
	m_alarm_hour=0;
	m_alarm_min=0;
	
	// Load keys from keyfile
	GKeyFile * kf = g_key_file_new();
	g_key_file_load_from_file(kf, m_config_file, G_KEY_FILE_NONE, NULL);
	m_talk = g_key_file_get_integer(kf, "calendar_settings", "talk", NULL);
	m_talk_at_startup=g_key_file_get_integer(kf, "calendar_settings", "talk_startup", NULL);
	m_talk_title = g_key_file_get_integer(kf, "calendar_settings", "talk_title", NULL);
	m_talk_time = g_key_file_get_integer(kf, "calendar_settings", "talk_time", NULL);
	m_talk_priority = g_key_file_get_integer(kf, "calendar_settings", "talk_priority", NULL);	
	m_talk_description=g_key_file_get_integer(kf, "calendar_settings", "talk_description", NULL);
	
	m_holidays = g_key_file_get_integer(kf, "calendar_settings", "holidays", NULL);	
	
	
	m_font_family=g_key_file_get_string(kf, "calendar_settings", "font_family", NULL);	
	m_font_size=g_key_file_get_integer(kf, "calendar_settings", "font-size", NULL);	
	
	m_alarm_notification=g_key_file_get_integer(kf, "calendar_settings", "alarm-notification", NULL);	
	m_alarm_hour=g_key_file_get_integer(kf, "calendar_settings", "alarm-hour", NULL);	
	m_alarm_min=g_key_file_get_integer(kf, "calendar_settings", "alarm-min", NULL);
	
	g_key_file_free(kf);	
	//config_load_default();	
}

void config_write()
{
	
	GKeyFile * kf = g_key_file_new();	
	
	//(key-file, group, key, value)	
	g_key_file_set_integer(kf, "calendar_settings", "talk", m_talk);
	g_key_file_set_integer(kf, "calendar_settings", "talk_startup", m_talk_at_startup);	
	g_key_file_set_integer(kf, "calendar_settings", "talk_title", m_talk_title);
	g_key_file_set_integer(kf, "calendar_settings", "talk_time", m_talk_time);
	g_key_file_set_integer(kf, "calendar_settings", "talk_priority", m_talk_priority);
	g_key_file_set_integer(kf, "calendar_settings", "talk_description", m_talk_description);
	
	g_key_file_set_integer(kf, "calendar_settings", "holidays", m_holidays);
	
	
	g_key_file_set_string(kf, "calendar_settings", "font_family", m_font_family);
	g_key_file_set_integer(kf, "calendar_settings", "font-size", m_font_size);
	
	g_key_file_set_integer(kf, "calendar_settings", "alarm-notification", m_alarm_notification);
	g_key_file_set_integer(kf, "calendar_settings", "alarm-hour", m_alarm_hour);
	g_key_file_set_integer(kf, "calendar_settings", "alarm-min", m_alarm_min);
	
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

//---------------------------------------------------------------
// thread speak funtion
//---------------------------------------------------------------

static gpointer thread_speak_func(gpointer user_data)
{ 
	gchar *text =user_data;        
    cst_voice *voice;  
    flite_init();   
    voice = register_cmu_us_kal(NULL);        
    flite_text_to_speech(text,voice,"play"); 	
	g_mutex_unlock (&lock); //thread mutex unlock 
	return NULL;
}

//---------------------------------------------------------------------
// treeview remove all items
//---------------------------------------------------------------------

void remove_all(GtkTreeView *treeview) {
    
  GtkTreeStore *store;
  GtkTreeModel *model;
  GtkTreeIter  iter;

  store = GTK_TREE_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(treeview)));
  model = gtk_tree_view_get_model(GTK_TREE_VIEW(treeview));

  if (gtk_tree_model_get_iter_first(model, &iter) == FALSE) {
      return;
  }
  
 // void gtk_tree_store_clear (GtkTreeStore *tree_store);
  gtk_tree_store_clear(store);
  
  
  //g_object_unref (model);
  //g_object_unref(store);
}


//---------------------------------------------------------------------
// treeview activated double click
//---------------------------------------------------------------------

static void callbk_treeview_row_activated(GtkTreeView  *tree_view,
										 GtkTreePath       *path,
										 GtkTreeViewColumn *column,
										 gpointer           user_window)
										 
{
      
   GtkWindow *window = user_window; //window   
   GtkTreeIter iter; //row iterator (internal structure)
   GtkTreeModel *model = gtk_tree_view_get_model(tree_view);
   
   gchar *value;
   gint id=0;
  
   if (gtk_tree_model_get_iter(model, &iter, path)) { 
   gtk_tree_model_get(model, &iter, 0, &id,  -1);
   gtk_tree_model_get(model, &iter, COLUMN, &value,  -1);  
   Event *event =g_malloc(sizeof(Event));    
   db_get_event(id, event);    
   talkcalendar_update_event(GTK_WIDGET(window), event); 
   }
   g_object_unref(model); 
   g_free(value);
}

//---------------------------------------------------------------------
// treeview selection changed
//--------------------------------------------------------------------- 
void on_changed(GtkWidget *widget, gpointer statusbar) {
    
  GtkTreeIter iter;
  GtkTreeModel *model;
  gchar *value;

  if (gtk_tree_selection_get_selected(GTK_TREE_SELECTION(widget), &model, &iter)) {
    gtk_tree_model_get(model, &iter, COLUMN, &value,  -1);   
    g_free(value);
  }
}

//---------------------------------------------------------------------
// update treeview model
//---------------------------------------------------------------------
GtkTreeModel *create_and_fill_model(Event *event_arry, gint arry_size) {
    
  GtkTreeStore *treestore;
  GtkTreeIter toplevel, child;
  
  GDateTime  *time_start;
  time_start =g_date_time_new_now_local(); 
  
  GDateTime  *time_end;
  time_end =g_date_time_new_now_local();          
   
  //2 columns col0=id col1=event values
  treestore = gtk_tree_store_new(NUM_COLS,G_TYPE_INT, G_TYPE_STRING);
  for(int i=0; i<arry_size; i++) {
  
  Event e =event_arry[i];
  //these two lines create a top level node
  gtk_tree_store_append(treestore, &toplevel, NULL);  
  gtk_tree_store_set(treestore, &toplevel, COLUMN, e.title, -1);
  gtk_tree_store_set(treestore, &toplevel, 0, e.id, -1);  
  gchar* time_str="";   
  gchar* time_start_str;  
  time_start = g_date_time_new_local(e.year,e.month,e.day,e.startHour, e.startMin,0.0);         
  time_start_str = g_date_time_format (time_start, "%l:%M %P");  
  gchar* time_end_str;
  time_end = g_date_time_new_local(e.year,e.month,e.day,e.endHour, e.endMin,0.0);         
  time_end_str = g_date_time_format (time_end, "%l:%M %P");  
  if(e.isAllday) {
  time_str= g_strconcat(time_str, "This is an all day event", NULL);			
  }
  else {			
  time_str= g_strconcat(time_str, time_start_str, " to ", time_end_str, NULL); 		
  //Two new lines for spacing -option?	
  } 
  
  //add a child item into the top level node
  gtk_tree_store_append(treestore, &child, &toplevel);  
  gtk_tree_store_set(treestore, &child, COLUMN, time_str, -1);
  gtk_tree_store_set(treestore, &child, 0, e.id, -1);
  //add a child item into the top level node
  gtk_tree_store_append(treestore, &child, &toplevel);  
  gtk_tree_store_set(treestore, &child, COLUMN, e.description, -1);
  gtk_tree_store_set(treestore, &child, 0, e.id, -1);  
  g_free(time_str);
  g_free(time_start_str);
  g_free(time_end_str);
  }
  g_date_time_unref (time_start);
  g_date_time_unref (time_end);

  return GTK_TREE_MODEL(treestore);
}

//---------------------------------------------------------------------
// create treeview and model
//---------------------------------------------------------------------
GtkWidget *create_view_and_model(Event *event_arry, gint arry_size) {
	    
  GtkTreeViewColumn *col;
  GtkCellRenderer *renderer;
  GtkWidget *view;
  GtkTreeModel *model; 
  
  view = gtk_tree_view_new();

  col = gtk_tree_view_column_new();
  gtk_tree_view_column_set_title(col, "Events");
  gtk_tree_view_append_column(GTK_TREE_VIEW(view), col);
  renderer = gtk_cell_renderer_text_new();
  gtk_tree_view_column_pack_start(col, renderer, TRUE);
  gtk_tree_view_column_add_attribute(col, renderer, "text", COLUMN);
  model = create_and_fill_model(event_arry, arry_size);  
  gtk_tree_view_set_model(GTK_TREE_VIEW(view), model);
  g_object_unref(model); 
  return view;
}

//---------------------------------------------------------------
// alarm revealer
//----------------------------------------------------------------

static gboolean revealer_timeout (gpointer userdata)
{   
    gtk_revealer_set_reveal_child (GTK_REVEALER (userdata), FALSE);    
    return TRUE; 
}

void show_revealer(GtkRevealer *revealer){
	
	gtk_revealer_set_reveal_child (GTK_REVEALER (revealer), TRUE);		
	g_timeout_add_seconds (10, revealer_timeout, revealer);
}


//---------------------------------------------------------------
// notifications
//----------------------------------------------------------------

static void show_notification(gchar *message, GtkApplication* app)
{
 
 GNotification* notification;
 
 
 gchar* title_str ="Talk Calendar";
 gchar* body_str="Alarm Reminder";
 
 notification = g_notification_new(title_str);
 g_notification_set_body(notification, body_str);
 g_application_send_notification(G_APPLICATION(app), NULL, notification);
 
 g_object_unref(notification);
 
 
 
}

//-----------------------------------------------------------------
// timer update callback
//------------------------------------------------------------------
static gboolean callbk_timer_update(gpointer data)
{
	GtkWindow *window = (GtkWindow*)data;
	
	GtkWidget *label =g_object_get_data(G_OBJECT(window), "label-time-key");
    
    GDateTime *date_time;
    //gchar *dt_format;
    date_time = g_date_time_new_now_local(); // get local time   
	gint hour =g_date_time_get_hour(date_time);
	gint min =g_date_time_get_minute (date_time);
	gint sec = g_date_time_get_second (date_time);
	
    //get events for date (do this outside timer function)
    // check reminder times
        
    gchar *dt_format_time;                         
    dt_format_time = g_date_time_format(date_time, "%H:%M:%S");   // 24hr time format
    gtk_label_set_text(GTK_LABEL(label), dt_format_time);   // update label         
    g_free (dt_format_time);
    
    gchar* message ="Alarm Reminder ";
    
    if(hour==m_alarm_hour && min==m_alarm_min && sec==0)
	{
	 
	 GtkRevealer *revealer =g_object_get_data(G_OBJECT(window), "revealer-key"); 
	 gtk_revealer_set_reveal_child (GTK_REVEALER (revealer), TRUE);
	 
	//speak now
	 GThread *thread_speak; 
		
	gchar* message_speak ="Talk Calendar. Alarm Reminder";    
		
	if(m_talk) {	
	g_mutex_lock (&lock);
    thread_speak = g_thread_new(NULL, thread_speak_func, message_speak);   
	}	
	g_thread_unref (thread_speak);	
				
	if(m_alarm_notification){	
	GtkApplication *app =g_object_get_data(G_OBJECT(window), "app-key"); 	
	show_notification(message,GTK_APPLICATION(app));
	}
	
	g_date_time_unref (date_time);
	return TRUE;
	}
    
    g_date_time_unref (date_time);    
    return TRUE;
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
// mark holidays
//---------------------------------------------------------------------

static void mark_holidays_on_calendar(GtkCalendar *calendar, gint month, gint year)
{
	    
   if (month==1) {  	
	gtk_calendar_mark_day(calendar,1); //day =1
   }
   
   GDate *edate =calculate_easter(year); 
   gint eday = g_date_get_day(edate);
   gint emonth =g_date_get_month(edate);
   
   if(month==emonth)
   {
	   gtk_calendar_mark_day(calendar,eday);
   }
     
   g_date_subtract_days(edate,2);
   gint efday = g_date_get_day(edate); //ef=easter friday
   gint efmonth =g_date_get_month(edate); 
   
   if(month==efmonth)
   {
	   gtk_calendar_mark_day(calendar,efday);
   }
     
   g_date_add_days(edate,3);
   gint emonday = g_date_get_day(edate); //easter monday
   gint emmonth =g_date_get_month(edate); 
    
   if(month==emmonth)
   {
	   gtk_calendar_mark_day(calendar,emonday);
   } 
      
   if (month==12) {
	   
	  gtk_calendar_mark_day(calendar, 25); //christmas day
	  gtk_calendar_mark_day(calendar, 26); //boxing
	}   
}




//---------------------------------------------------------------------
// calendar month changed callback
//---------------------------------------------------------------------

static void callbk_calendar_month_changed(GtkCalendar *calendar, gpointer user_data) {
	  
   guint day, month, year;
   gtk_calendar_get_date(GTK_CALENDAR (calendar), &year, &month, &day);    
   gtk_calendar_clear_marks(GTK_CALENDAR (calendar)); 
        
   if(m_holidays) mark_holidays_on_calendar(calendar, month+1,year); //option
   
   gint row_number = db_get_number_of_rows_month_year(month+1, year);
  
		
	Event event_array[row_number];		 
	db_get_all_events_year_month(event_array, year, month+1, row_number);
	 //mark up calendar
	Event evt;	
	for(int i=0; i<row_number; i++) {		
		evt=event_array[i];		//
		guint day = evt.day;
		if  (evt.isYearly == 0)	{	
		gtk_calendar_mark_day(calendar, day);
		}
	} 	 
  
   //Now fetch the isYearly events    
   
   gint isyearly_number = db_get_number_of_isyearly_events_month(month+1);
      
   Event isyearly_array[isyearly_number];	
   db_get_isyearly_events_month(isyearly_array, month+1, isyearly_number);
	
	 // mark up calendar
	Event evty;	
	for(int i=0; i<isyearly_number; i++) {		
		evty=isyearly_array[i];	
		evty.year=year;	
		guint rday = evty.day;
		gtk_calendar_mark_day(calendar, rday);
	} 
  
}
//---------------------------------------------------------------------
// calendar double clicked callback
//---------------------------------------------------------------------
static void callbk_calendar_day_double_click(GtkCalendar *calendar, gpointer user_data)
{
   guint day, month, year;
   gtk_calendar_get_date(GTK_CALENDAR (calendar), &year, &month, &day);    
   
   GtkWidget *window = (GtkWidget *) user_data;
   
   if( !GTK_IS_WINDOW(window)) { 
	  return;
  }
  
  talkcalendar_new_event(window, year, month+1, day);
  
}

//---------------------------------------------------------------------
// calendar clicked  callback
//---------------------------------------------------------------------
static void callbk_calendar_day_clicked(GtkCalendar *calendar, gpointer user_data)
{
    
   //calendar day clicked   
   GtkWidget *window = (GtkWidget *) user_data;
   
   if( !GTK_IS_WINDOW(window)) { 
   return;
   }
     
  GtkWidget *label_date =g_object_get_data(G_OBJECT(window), "label-date-key"); 
 
   guint day, month, year;
   gtk_calendar_get_date(GTK_CALENDAR (calendar), &year, &month, &day);
    
    GDateTime *dt;
    //dt =g_date_time_new_now_local();
    gchar *dt_str;
    dt = g_date_time_new_local(year,month+1,day,0,0,0.0);   // get date    
    dt_str = g_date_time_format(dt, "%a %e %b %Y");	
    gtk_label_set_xalign(GTK_LABEL(label_date),0.5); //add date to label    	
	
	if(m_holidays) { //check for holidays	
	
	//Check for new year, easter and christmas
    if(month+1==1 && day==1)
    {
    dt_str=g_strconcat(dt_str, " New year",NULL);
    }
    
    GDate *edate =calculate_easter(year); 
    gint eday = g_date_get_day(edate);
    gint emonth =g_date_get_month(edate);
    
    if(month+1==emonth && day==eday)
    {
    dt_str=g_strconcat(dt_str, " Easter",NULL); 
    }
    
    g_date_subtract_days(edate,2);
    gint efday = g_date_get_day(edate); //easter friday
    gint efmonth =g_date_get_month(edate); 
	
	if(month+1==efmonth && day==efday)
	{
	dt_str=g_strconcat(dt_str, " Easter Friday",NULL);
	}
	
	//GDate *edate2 =calculateEaster(year); 
	g_date_add_days(edate,3);
	gint emonday = g_date_get_day(edate); //easter monday
	gint emmonth =g_date_get_month(edate); 
    
	if(month+1==emmonth && day==emonday)
	{
	dt_str=g_strconcat(dt_str, " Easter Monday",NULL);
	} 
	
    if(month+1 ==12 && day==25) {
    dt_str=g_strconcat(dt_str, " Christmas",NULL);
	}
    if(month+1 ==12 && day==26) {
    dt_str=g_strconcat(dt_str, " Boxing Day",NULL);
	}
	} //m_holidsays	
	
	gtk_label_set_text(GTK_LABEL(label_date), dt_str); 
    
   	//get all day events from database
	
	gint n_regular_events = db_get_number_of_rows_year_month_day(year, month+1, day);    
	gint n_isyearly_month_events = db_get_number_of_isyearly_events_month(month+1);   
	gint n_isyearly_day_events=0;
	
	Event isyearly_array[n_isyearly_month_events];
		 
	db_get_isyearly_events_month(isyearly_array, month+1, n_isyearly_month_events);
	Event e1;	
	for(int i=0; i<n_isyearly_month_events; i++) {		
	e1=isyearly_array[i];
	if(e1.day == day && e1.year!=year){	
	n_isyearly_day_events=n_isyearly_day_events+1;
	}
	}
	
	gint total_number_events = n_regular_events+n_isyearly_day_events;
	
	//Now create total event array i.e. contains regular plus isyearly events
	Event* event_array_total = NULL;	
	event_array_total = malloc(total_number_events * sizeof(Event));
	
	Event event_array[n_regular_events]; //regular event array
	db_get_all_events_year_month_day(event_array, year, month+1, day, n_regular_events);
	
	int count=0;  //event array total count
	
	for(int i=0; i<n_regular_events; i++) {	//add regular events to total		
	event_array_total[count] = event_array[i];
	count =count+1;
	if(count>total_number_events)
	{
	g_print("fatal error: malloc over run\n");
	break;
	}
	}	
	//now add yearly events
	for(int i=0; i<n_isyearly_month_events; i++) {		
	Event e2=isyearly_array[i];
	if(e2.day == day && e2.year!=year){			
    event_array_total[count] = isyearly_array[i];
	count =count+1;
	if(count>total_number_events)
	{
	g_print("fatal error: malloc over run\n");
	break;
	}
	}
	}	 
		
   GtkTreeView *treeview =g_object_get_data(G_OBJECT(window), "treeview-key");
   //remove all and recreate view
	remove_all(treeview);
	
	//change the model data not the view which exists
	GtkTreeModel *model;	
	model =create_and_fill_model(event_array_total,total_number_events);
	//connect the model to the view  
    gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), model);
    //g_object_unref(model); unref error!!!	
	gtk_widget_show_all(window);
}


static void callbk_home(GSimpleAction * action, GVariant *parameter, gpointer user_data){
	
	 GtkWindow *window = GTK_WINDOW (gtk_widget_get_ancestor (GTK_WIDGET (user_data),
                                                 GTK_TYPE_WINDOW));
   
   if( !GTK_IS_WINDOW(window)) {	   	
       return;
   }
	
   GtkCalendar *calendar =g_object_get_data(G_OBJECT(window), "calendar-key");
   GtkWidget *label_date =g_object_get_data(G_OBJECT(window), "label-date-key"); 
   
   GDateTime *dt; 
   gchar *dt_format;
   dt = g_date_time_new_now_local();   // get local time     
   dt_format = g_date_time_format(dt, "%a %e %b %Y");	   
   
   gtk_label_set_xalign(GTK_LABEL(label_date),0.5);
   gtk_label_set_text(GTK_LABEL(label_date), dt_format); 	
   
   gint year = g_date_time_get_year(dt);
   gint month =g_date_time_get_month(dt);    
   gint day = g_date_time_get_day_of_month(dt); 
      
   gtk_calendar_select_month (calendar, month-1, year);	   
   gtk_calendar_select_day (calendar, day);	   
  
   g_date_time_unref(dt); 
}

static void speak_events_at_date(GtkCalendar *calendar) {
	
		
	guint day, month, year;
	
	gchar *dow_str=""; //day of week
	gchar *day_str="";
	gchar *month_str="";	
	GDate *date;
	GDateWeekday weekday; 
	GDateMonth month_enum;
	
	gchar *speak_str;
    speak_str ="";   
		
    gtk_calendar_get_date(GTK_CALENDAR (calendar), &year, &month, &day);
       
   date =g_date_new_dmy (day,month+1,year); 
   weekday= g_date_get_weekday(date);
      	
   
   switch (weekday) {
		case G_DATE_MONDAY:
		dow_str="Monday";		
		break;
		case G_DATE_TUESDAY:
		dow_str="Tuesday";
		break;
		case G_DATE_WEDNESDAY:
		dow_str="Wednesday";
		break;
		case G_DATE_THURSDAY:
		dow_str="Thursday";
		break;
		case G_DATE_FRIDAY:
		dow_str="Friday";
		break;
		case G_DATE_SATURDAY:
		dow_str="Saturday";
		break;
		case G_DATE_SUNDAY:
		dow_str="Sunday";
		break;
		default:
		//Unknown day of week
		dow_str="Unknown Day";
		break;
	    }//switch dow
	    
	    speak_str= g_strconcat(speak_str, dow_str, " ", NULL);
	    
		
       switch (day) {
		case 1:
		day_str="first";
		break;		
		case 2:
		day_str="second";
		break;
		case 3:
		day_str="third";
		break;
		case 4:
		day_str="fourth";
		break;
		case 5:
		day_str="fifth";
		break;
		case 6:
		day_str="sixth";
		break;
		case 7:
		day_str="seventh";
		break;
		case 8:
		day_str="eighth";
		break;
		case 9:
		day_str="ninth";
		break;
		case 10:
		day_str="tenth";
		break;
		case 11:
		day_str="eleventh";		
		break;
		case 12:
		day_str="twelfth";		
		break;
		case 13:
		day_str="thirteenth";
		
		break;
		case 14:
		day_str="fourteenth";
		
		break;
		case 15:
		day_str="fifteenth";
		
		break;
		case 16:
		day_str="sixteenth";
		
		break;
		case 17:
		day_str="seventeenth";
		
		break;
		case 18:
		day_str="eighteenth";
		
		break;
		case 19:
		day_str="nineteenth";
		
		break;
		case 20:
		day_str="twentieth";
		
		break;
		case 21:
		day_str="twenty first";
		
		break;
		case 22:
		day_str="twenty second";		
		break;
		case 23:
		day_str="twenty third";		
		break;
		case 24:
		day_str="twenty fourth";
		
		break;
		case 25:
		day_str="twenty fifth";
		
		break;
		case 26:
		day_str="twenty sixth";
		
		break;
		case 27:
		day_str="twenty seventh";
		
		break;
		case 28:
		day_str="twenty eighth";
		
		break;
		case 29:
		day_str="twenty ninth";
		
		break;
		case 30:
		day_str="thirtieth";
		
		break;
		case 31:
		day_str="thirty first";
		
		break;
		default:
		//Unknown ordinal
		day_str="unknown";
		break;		
	  } //day switch
      
      speak_str= g_strconcat(speak_str, day_str, " ", NULL);
            
      month_enum =g_date_get_month (date);
      
      switch (month_enum) {
		case G_DATE_JANUARY:
		month_str="January";		
		break;
		case G_DATE_FEBRUARY:		
		month_str="February";
		break;
		case G_DATE_MARCH:		
		month_str=" March";
		break;
		case G_DATE_APRIL:		
		month_str="April";
		break;
		case G_DATE_MAY:		
		month_str="May";
		break;
		case G_DATE_JUNE:		
		month_str=" June";
		break;
		case G_DATE_JULY:		
		month_str="July";
		break;
		case G_DATE_AUGUST:		
		month_str="August";
		break;
		case G_DATE_SEPTEMBER:		
		month_str="September";
		break;
		case G_DATE_OCTOBER:		
		month_str="October";
		break;
		case G_DATE_NOVEMBER:		
		month_str="November";
		break;
		case G_DATE_DECEMBER:		
		month_str="December";
		break;
		default:
		month_str=" Unknown Month";
		
		break;
	  } //month switch
      
      
    speak_str= g_strconcat(speak_str, month_str, " ", NULL);  
    
    //Get total number of event i.e. regular plus isyearly events
    
    //regular events
    gint n_regular_events = db_get_number_of_rows_year_month_day(year, month+1, day);    
    
    //repeat yearly events
    gint n_isyearly_month_events = db_get_number_of_isyearly_events_month(month+1);    
    Event isyearly_array[n_isyearly_month_events];	 
    db_get_isyearly_events_month(isyearly_array, month+1, n_isyearly_month_events);
	Event evty;	
	gint n_isyearly_day_events=0;
	for(int i=0; i<n_isyearly_month_events; i++) {		
    evty=isyearly_array[i];
    if(evty.day == day && evty.year!=year){	
    n_isyearly_day_events=n_isyearly_day_events+1;
    }
	}
   
    gint total_number_events = n_regular_events+n_isyearly_day_events;
   
    gchar* event_num_str;
    
    if (total_number_events ==0) {	
        event_num_str="no events";  
	} //if
	
	else if(total_number_events ==1){
		event_num_str="one event"; 
	}
	else if(total_number_events ==2){
		event_num_str="two events"; 
	}
	else if(total_number_events ==3){
		 event_num_str="three events"; 
	}
	else if(total_number_events ==4){
		event_num_str="four events"; 
	}
	else if(total_number_events ==5){ 
		event_num_str="five events"; 
	
	}		
	else {
	event_num_str="many events today"; 
	}
	
	speak_str= g_strconcat(speak_str, event_num_str, " ", NULL); 
	
	//Get total event array i.e. regular plus isyearly events
	Event* event_array_total = NULL;	
	event_array_total = malloc(total_number_events * sizeof(Event));
	Event event_array[n_regular_events]; //regular event array
    db_get_all_events_year_month_day(event_array, year, month+1, day, n_regular_events);
		
	int count=0;  //event array total count
	
	for(int i=0; i<n_regular_events; i++) {	//add regular events to total		
	event_array_total[count] = event_array[i];
    count =count+1;
    if(count>total_number_events)
	{
	printf("fatal error: malloc over run\n");
	break;
	}
	}
	//now add yearly event
	for(int i=0; i<n_isyearly_month_events; i++) {		
	Event e2=isyearly_array[i];
	if(e2.day == day && e2.year!=year){			
	event_array_total[count] = isyearly_array[i];
	count =count+1;
	if(count>total_number_events)
	{
	printf("fatal error: malloc over run\n");
	break;
	}
    }
	}
	
	//TALK event details
    
	Event evt;	
		
		for(int i=0; i<total_number_events; i++) {	
		evt=event_array_total[i];
				
		if(m_talk_title) {
		speak_str= g_strconcat(speak_str, evt.title, ".  ", NULL); 
		} //if talk title
		
		if(m_talk_time){
		
		GDateTime* time_start;
		gchar* time_start_str;
		time_start = g_date_time_new_local(evt.year,evt.month,evt.day,evt.startHour, evt.startMin,0.0);         
		time_start_str = g_date_time_format (time_start, "%l:%M %P");
		
		GDateTime* time_end;
		gchar* time_end_str;
		time_end = g_date_time_new_local(evt.year,evt.month,evt.day,evt.endHour, evt.endMin,0.0);         
		time_end_str = g_date_time_format (time_end, "%l:%M %P");
		
		if(evt.isAllday) {
			speak_str= g_strconcat(speak_str, "This is an all day event\n", NULL);			
		}
		else {			
		speak_str= g_strconcat(speak_str, time_start_str, " to ", time_end_str, "\n", NULL); 			
		}			
		}//if talk time
				
		if (m_talk_description) {
			speak_str= g_strconcat(speak_str, evt.description, ".  ", NULL);
		} //if talk description
		
		if (m_talk_priority){
			gchar* priority_str="";
			if (evt.priority ==1) priority_str="low priority event";
			if (evt.priority ==2) priority_str="medium priority event";
			if (evt.priority ==3) priority_str="high priority event";
			speak_str= g_strconcat(speak_str, priority_str, ".  ", NULL);
			
		} //if talk priority
		
		}	//for total events
  
     //free
     free(event_array_total);  
      
    GThread *thread_speak;   
    if(m_talk) {	
	g_mutex_lock (&lock);
    thread_speak = g_thread_new(NULL, thread_speak_func, speak_str);   
	}	
	g_thread_unref (thread_speak);	
	
}


//-------------------------------------------------------------------
// speak callback
//--------------------------------------------------------------------

static void callbk_speak(GSimpleAction* action, GVariant *parameter,gpointer user_data){
	
		
	GtkWidget *window = gtk_widget_get_toplevel (user_data);
	
	if (!GTK_IS_WINDOW (window))
    {      
      return; 
    }
   
	GtkWidget *calendar =g_object_get_data(G_OBJECT(window), "calendar-key"); 
	speak_events_at_date(GTK_CALENDAR(calendar));
}


//---------------------------------------------------------------------
// exit callback
//---------------------------------------------------------------------

static void callbk_quit(GSimpleAction * action,
							G_GNUC_UNUSED GVariant      *parameter,
							              gpointer       user_data)
{
	
	g_application_quit(G_APPLICATION(user_data));
	
}
//---------------------------------------------------------------------
// export callback
//---------------------------------------------------------------------
static void callbk_export(GSimpleAction * action,
							G_GNUC_UNUSED GVariant      *parameter,
							              gpointer       user_data)
{
		
	GtkWidget *dialog; 
	GtkFileFilter *filter1, *filter2;   
    gchar *filename;
    gchar *csv_str;
    csv_str="";
        
    gint row_count_all = db_get_number_of_rows_all();
    
   if (row_count_all ==0) {	
		return;
	}
	
	else {			
	 Event event_array[row_count_all];		 
	 db_get_all_events(event_array,row_count_all);
	 
	 Event evt;	
	 for(int i=0; i<row_count_all; i++) {		
		evt=event_array[i];	
		
	    gchar *priority_str = g_strdup_printf("%i", evt.priority);	   
	    gchar *year_str = g_strdup_printf("%i", evt.year);
		gchar *month_str = g_strdup_printf("%i", evt.month);
		gchar *day_str = g_strdup_printf("%i", evt.day);
		gchar *start_hour_str = g_strdup_printf("%i", evt.startHour);
		gchar *start_min_str = g_strdup_printf("%i", evt.startMin);
		gchar *end_hour_str = g_strdup_printf("%i", evt.endHour);
		gchar *end_min_str = g_strdup_printf("%i", evt.endMin);
		gchar *is_yearly_str = g_strdup_printf("%i", evt.isYearly);
		gchar *is_allday_str = g_strdup_printf("%i", evt.isAllday);
	    
		csv_str= g_strconcat(csv_str, 
		evt.title, ",", 
		priority_str,",",
		evt.description, ",",
		year_str,",",
		month_str,",",
		day_str,",",
		start_hour_str,",",
		start_min_str,",",
		end_hour_str,",",
		end_min_str,",",
		is_yearly_str,",",
		is_allday_str,"\n", //terminate with new line	
		NULL);
		
	  }//for i events	
	
     }
    
    dialog = gtk_file_chooser_dialog_new ("Save",
									NULL,
									GTK_FILE_CHOOSER_ACTION_SAVE,                      
									"_Cancel", GTK_RESPONSE_CANCEL,
									"_Save", GTK_RESPONSE_ACCEPT, 
									NULL);
									
    // gtk_window_set_default_size (GTK_WINDOW (dialog), 220, 200);   
    
    filter1 = gtk_file_filter_new();
    filter2 = gtk_file_filter_new();
    
    gtk_file_filter_add_pattern(filter1, "*.csv");
    gtk_file_filter_set_name(filter1, "Comma Separated Values (*.csv)");
   
    
    gtk_file_filter_add_pattern(filter2, "*.*");
    gtk_file_filter_set_name (filter2, "All Files (*.*)");
    gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(dialog), filter1);
    gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(dialog), filter2);    
    
    // default file name
    gtk_file_chooser_set_current_name(GTK_FILE_CHOOSER(dialog), "filename.csv");
    gtk_widget_show_all(dialog);
    
    gint resp = gtk_dialog_run(GTK_DIALOG(dialog));
    
    if (resp == GTK_RESPONSE_ACCEPT){		
   
    filename = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (dialog));
   
	
   
    g_file_set_contents (filename, csv_str, -1,NULL);
    
    //g_free (text); //core dumped invalid pointer
    g_free (filename);
    
	}
    else{    
    //gtk_widget_destroy(GTK_WIDGET(dialog));
	}
    gtk_widget_destroy(GTK_WIDGET(dialog));
	
}

//---------------------------------------------------------------------
// import callback
//---------------------------------------------------------------------
static void callbk_import(GSimpleAction * action,
							G_GNUC_UNUSED GVariant      *parameter,
							              gpointer       user_data)
{
		
	GtkCalendar *calendar =user_data;
	
	gchar *file_name = NULL;        // Name of file to open from dialog box
    gchar *file_contents = NULL;    // For reading contents of file
    gboolean file_success = FALSE;  // File read status
    GtkWidget *dialog; 
    GtkFileFilter *filter1, *filter2;
    GtkTextIter start, end;
    GtkTextBuffer *textbuffer;
    textbuffer = gtk_text_buffer_new (NULL);
    gchar *text; 
     
       
     dialog = gtk_file_chooser_dialog_new ("Open",
                      NULL,
                      GTK_FILE_CHOOSER_ACTION_OPEN,
                      "_Cancel", GTK_RESPONSE_CANCEL,                      
                      "_Open", GTK_RESPONSE_ACCEPT,                      
                      NULL);
                      
	  filter1 = gtk_file_filter_new();
	  filter2 = gtk_file_filter_new();    
	  gtk_file_filter_add_pattern(filter1, "*.csv");
	  gtk_file_filter_set_name(filter1, "Comma Separated Values (*.csv)");
	  gtk_file_filter_add_pattern(filter2, "*.*");
	  gtk_file_filter_set_name (filter2, "All Files (*.*)");
	  gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(dialog), filter1);
	  gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(dialog), filter2);   
	  
	  
	  gtk_widget_show_all(dialog);
	  
	  gint resp = gtk_dialog_run(GTK_DIALOG(dialog));
	  
    if (resp == GTK_RESPONSE_ACCEPT){
				
		file_name = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (dialog));
		
		if (file_name != NULL) {
            
            //g_file_get_contents(filename, &contents, &length, &error)
            // Copy the contents of the file to dynamically allocated memory
            file_success = g_file_get_contents(file_name, &file_contents, NULL, NULL);
            if (file_success) {
                // Put the contents of the file into the GtkTextBuffer
                gtk_text_buffer_set_text(textbuffer, file_contents, -1);
               
				gtk_text_buffer_get_bounds(textbuffer, &start, &end);
				text = gtk_text_buffer_get_text(textbuffer, &start, &end, FALSE);  
				
				gint line_count = gtk_text_buffer_get_line_count(textbuffer)-1;  //-1
			   			   
			   //Create event array with line count
			    Event event_array[line_count]; 
				
				gchar **lines = g_strsplit (text, "\n", -1);
				
				for (int i = 0; lines[i] != NULL; i++) {					
					if (lines[i][0] == '\0') continue; //ignore blank lines	
					//create an event from line and store
					//Event e;   
			   Event e; 
			   gchar** items = g_strsplit (lines[i],",",-1);
			   
			   gint j=0;			   
			   while(items[j] != NULL)
			   {			   		   
			   if (j==0) {			 
			   strcpy(e.title,items[0]);
			   }
			   else if(j==1) {			 		   
			   gint priority_num = -1;
			   priority_num = atoi(items[1]);			   
			   e.priority=priority_num;			   
			   }
			   else if(j==2) {			   
			   strcpy(e.description,items[2]);
			   }
			   else if(j==3) {			  
			   gint year = -1;
			   year = atoi(items[3]);
			   e.year=year;   
			   }
			   else if(j==4) {			   
			   gint month = -1;
			   month = atoi(items[4]);
			   e.month=month;			   			 				   
			   }
			   else if(j==5) {				  
			   gint day = -1;
			   day= atoi(items[5]);				  
			   e.day=day;				   
			   }
			   else if(j==6) {				  
			   gint startHour = -1;
			   startHour= atoi(items[6]);				  
			   e.startHour=startHour;				   
			   }
			   else if(j==7) {				  
			   gint startMin = -1;
			   startMin= atoi(items[7]);				  
			   e.startMin=startMin;				   
			   }
			   else if(j==8) {				  
			   gint endHour = -1;
			   endHour= atoi(items[8]);				  
			   e.endHour=endHour;				   
			   }
			   else if(j==9) {				  
			   gint endMin = -1;
			   endMin= atoi(items[9]);
			   e.endMin= endMin;				   
			   }
			   else if(j==10) {				  
			   gint isYearly = -1;
			   isYearly= atoi(items[10]);
			   e.isYearly= isYearly;				   
			   }
			   else if(j==11) {				  
			   gint isAllday= -1;
			   isAllday= atoi(items[11]);				  
			   e.isAllday=isAllday;				   
			   }
			   j++;		
			   } //while j
			   //insert event e into db
			   event_array[i]=e;					
			} //for lines[i]	
			          
            Event evt;	
			for(int k=0; k<line_count; k++) {		
			evt=event_array[k];			
			db_insert_event_struct(evt);
			} //for k   
		   g_free(file_contents);	
	    }//if success
	   g_free(file_name); 
	}//file name not null
	} //response Accept
	else {
		;
		gtk_widget_destroy(GTK_WIDGET(dialog));
		return;
	}
	

   guint cday, cmonth, cyear;
   gtk_calendar_get_date(GTK_CALENDAR (calendar), &cyear, &cmonth, &cday);
      
   gtk_calendar_clear_marks(GTK_CALENDAR (calendar));  
   gint row_number = db_get_number_of_rows_month_year(cmonth+1, cyear); 	
   if (row_number ==0) {
		return;
	}
	else { 
	 Event event_array[row_number];		 
	 db_get_all_events_year_month(event_array, cyear, cmonth+1, row_number);
	 //mark up calendar
	 Event evtmarkup;	
	for(int i=0; i<row_number; i++) {		
		evtmarkup=event_array[i];		//
		guint dday = evtmarkup.day;		
		gtk_calendar_mark_day(calendar, dday);
	} 	 
   }
      
   gtk_widget_destroy(GTK_WIDGET(dialog));  
	
}

static void callbk_font(GSimpleAction* action, GVariant *parameter,gpointer user_data)
{
		
	GtkWidget *window = gtk_widget_get_toplevel (user_data);
	
	if (!GTK_IS_WINDOW (window))
    {      
      return;      
    }
	
	GtkWidget *font_chooser = NULL;	
	const gchar* font_str;	
	PangoFontDescription *font_desc = NULL;
	
	font_chooser = gtk_font_chooser_dialog_new("Select Font", NULL);
	
	const gchar* current_font_str=m_font_family;	
	gchar *size_str = g_strdup_printf("%i", m_font_size);  	
	current_font_str =g_strconcat(current_font_str," ", size_str, NULL); 
	
	gchar* preview_str="Talk Calendar";
	gtk_font_chooser_set_preview_text (GTK_FONT_CHOOSER(font_chooser), preview_str);
		
	gtk_font_chooser_set_font(GTK_FONT_CHOOSER(font_chooser), current_font_str);

	if (gtk_dialog_run(GTK_DIALOG(font_chooser)) == GTK_RESPONSE_OK)
	{
				
		font_str = gtk_font_chooser_get_font(GTK_FONT_CHOOSER(font_chooser));	
		font_desc = pango_font_description_from_string(font_str);		
		const gchar* font_family= pango_font_description_get_family(font_desc);		
		m_font_family=font_family;				
		gint pango_font_size =pango_font_description_get_size(font_desc);		
		m_font_size=pango_font_size/1024;
		config_write();			
		change_window_font_size(GTK_WINDOW(window));
		pango_font_description_free(font_desc);
		//g_free(font_str);		
	}
	gtk_widget_destroy(font_chooser);
}

//--------------------------------------------------------------------
// Other Preferences callback
//--------------------------------------------------------------------

static void callbk_other_options(GSimpleAction* action, GVariant *parameter,gpointer user_data)
{
	GtkWidget *window = gtk_widget_get_toplevel (user_data);
	
	if (!GTK_IS_WINDOW (window))
    {
      return; 
    }
	talkcalendar_other_options_dialog(window);
}
//--------------------------------------------------------------------
// Talk Preferences callback
//--------------------------------------------------------------------

//static void callbk_preferences(GtkWidget *button, GtkWidget* window)
static void callbk_preferences(GSimpleAction* action, GVariant *parameter,gpointer user_data)
{
	//GtkWindow *window = GTK_WINDOW (gtk_widget_get_ancestor (GTK_WIDGET (user_data), GTK_TYPE_WINDOW));	
	
	GtkWidget *window = gtk_widget_get_toplevel (user_data);
	
	if (!GTK_IS_WINDOW (window))
    {      
      return;
    }
   talkcalendar_talk_options_dialog(window);	
}

//---------------------------------------------------------------------
// Delete all events
//---------------------------------------------------------------------

static void callbk_delete_all_response(GtkDialog *dialog, gint response_id, gpointer  user_data)								 
{
	
	GtkWindow *window = user_data; //window data
	
    GtkTreeView *treeview =g_object_get_data(G_OBJECT(window), "treeview-key");
	GtkCalendar *calendar =g_object_get_data(G_OBJECT(window), "calendar-key");
	
     
     if (response_id == GTK_RESPONSE_OK) {
     //Delete everything
     db_delete_all();
     db_reset_sequence();
     //clear 
    
     //clear treeview list   
	 remove_all(treeview);    
      //clear calendar marks
     callbk_calendar_month_changed(calendar, NULL); 
     gtk_widget_destroy (GTK_WIDGET (dialog));
     }     
     else if (response_id == GTK_RESPONSE_CANCEL) {
		 //cancel			
		gtk_widget_destroy(GTK_WIDGET (dialog));
	 }
	  else if (response_id == GTK_RESPONSE_DELETE_EVENT) {
          //dialog closed or cancelled          
		  gtk_widget_destroy(GTK_WIDGET (dialog));
	 }
}


//--------------------------------------------------------------------
// Delete events callback
//--------------------------------------------------------------------

static void callbk_delete(GSimpleAction *action, GVariant *parameter,  gpointer user_data){

	
	GtkWidget *window = gtk_widget_get_toplevel (user_data);
	
	if (!GTK_IS_WINDOW (window))
    {
      return;
    }
	
	GtkWidget *message_dialog;
	message_dialog = gtk_message_dialog_new (GTK_WINDOW(window), GTK_DIALOG_MODAL, 
                                            GTK_MESSAGE_WARNING, 
                                            GTK_BUTTONS_OK_CANCEL, 
                                            "Delete All Events?");
	
	g_signal_connect (GTK_DIALOG (message_dialog), "response",   G_CALLBACK (callbk_delete_all_response), window);
	
	gtk_widget_show(message_dialog); 	
}

//--------------------------------------------------------------------
// New event callback
//--------------------------------------------------------------------


static void callbk_new_event(GtkWidget *button, GtkWidget* window){

	if( !GTK_IS_WINDOW(window)) { 	
	return;
	}	
	GtkCalendar *calendar =g_object_get_data(G_OBJECT(window), "calendar-key"); 
	guint day, month, year;	
	gtk_calendar_get_date(GTK_CALENDAR (calendar), &year, &month, &day);  
	talkcalendar_new_event(window, year, month+1, day);
}


//-------------------------------------------------------------------
// Set alarm callback
//-------------------------------------------------------------------

static void callbk_alarm(GtkWidget *button, GtkWidget* window)
{
	
	if( !GTK_IS_WINDOW(window)) { 
	return;
	}
	GtkRevealer *revealer =g_object_get_data(G_OBJECT(window), "revealer-key"); 
	gtk_revealer_set_reveal_child (GTK_REVEALER (revealer), FALSE);	
	talkcalendar_alarm_dialog(window);
}


static void callbk_about_close (GtkDialog *dialog, gint response_id, gpointer user_data)
{
  // destroy the about dialog 
  gtk_widget_destroy (GTK_WIDGET (dialog));
}

//-----------------------------------------------------------------
// Keyboard shortcuts
//-----------------------------------------------------------------

static void callbk_shortcuts(GSimpleAction * action, GVariant *parameter, gpointer user_data){

	GtkWindow *window = GTK_WINDOW (gtk_widget_get_ancestor (GTK_WIDGET (user_data),
	GTK_TYPE_WINDOW));
	
	gchar* shortcuts_str ="\n\
	Import		<Ctrl>O\n\
	Export		<Ctrl>S\n\
	Delete		<Ctrl>D\n\
	Speak		Spacebar\n\
	Today		Home Key\n\
	About		<Ctrl>A\n\
	Quit		<Ctrl>Q\
	";
	
	GtkWidget *dialog;
	dialog = gtk_message_dialog_new(GTK_WINDOW(window),
	GTK_DIALOG_DESTROY_WITH_PARENT,
	GTK_MESSAGE_INFO,
	GTK_BUTTONS_OK,
	"%s", shortcuts_str);
		
	gtk_window_set_title(GTK_WINDOW(dialog), "Shortcut Keys");
			
	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);

}


//-------------------------------------------------------------------
// About callback
//-------------------------------------------------------------------
static void callbk_about(GSimpleAction * action, GVariant *parameter, gpointer user_data){
	
	
	GtkWindow *window = GTK_WINDOW (gtk_widget_get_ancestor (GTK_WIDGET (user_data),
                                                 GTK_TYPE_WINDOW));
		
	const gchar *authors[] = {"Alan Crispin", NULL};		
	GtkWidget *about_dialog;
	about_dialog = gtk_about_dialog_new();	
	g_signal_connect (GTK_DIALOG (about_dialog), "response", G_CALLBACK (callbk_about_close), NULL);
	
	gtk_window_set_transient_for(GTK_WINDOW(about_dialog),GTK_WINDOW(window));
	gtk_widget_set_size_request(about_dialog, 200,200);
    gtk_window_set_modal(GTK_WINDOW(about_dialog),TRUE);	
	gtk_about_dialog_set_program_name(GTK_ABOUT_DIALOG(about_dialog), "Gtk Talk Calendar");
	gtk_about_dialog_set_version (GTK_ABOUT_DIALOG(about_dialog), "1.4");
	gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(about_dialog),"Copyright © 2021");
	gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(about_dialog),"Calendar Assistant"); 	
	//gtk_about_dialog_set_wrap_license(GTK_ABOUT_DIALOG(about_dialog),TRUE);	
	gtk_about_dialog_set_license_type (GTK_ABOUT_DIALOG(about_dialog), GTK_LICENSE_GPL_2_0);
	gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(about_dialog),"https://github.com/crispinalan/"); 
	gtk_about_dialog_set_website_label(GTK_ABOUT_DIALOG(about_dialog),"Talk Calendar Website");
	gtk_about_dialog_set_authors(GTK_ABOUT_DIALOG(about_dialog), authors);
	//gtk_about_dialog_set_logo_icon_name(GTK_ABOUT_DIALOG(about_dialog), NULL);	
	gtk_about_dialog_set_logo_icon_name(GTK_ABOUT_DIALOG(about_dialog), "x-office-calendar");
	
	//Font size
	GtkCssProvider *cssProvider;
	GtkStyleContext *context_about_dialog;	
	cssProvider = gtk_css_provider_new();	
	gtk_widget_set_name (GTK_WIDGET(about_dialog), "cssView");  
	
	char *size_str = g_strdup_printf("%i", m_font_size); 
	size_str =g_strconcat(size_str,"px;", NULL);
	
	const gchar* font_family = m_font_family; 
    font_family =g_strconcat(font_family,";", NULL); 
	
	gchar* css_str = g_strdup_printf ("#cssView {font-family: %s font-size: %s }", font_family, size_str);
	gtk_css_provider_load_from_data(cssProvider, css_str,-1, NULL); 
	
	// get GtkStyleContext from widget
	context_about_dialog = gtk_widget_get_style_context(GTK_WIDGET(about_dialog));	
	//finally load style provider 
	gtk_style_context_add_provider(context_about_dialog,    
	GTK_STYLE_PROVIDER(cssProvider), 
	GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);	
	
	gtk_widget_show(about_dialog);	
		
}


//--------------------------------------------------------------------
// About audio callback
//--------------------------------------------------------------------
static void callbk_speak_about(GSimpleAction *action,
							G_GNUC_UNUSED  GVariant      *parameter,
							  gpointer       user_data){
		
	GThread *thread_speak; 
		
	gchar* message_speak ="Talk Calendar. Version. 1.4.";    
		
	if(m_talk) {	
	g_mutex_lock (&lock);
    thread_speak = g_thread_new(NULL, thread_speak_func, message_speak);   
	}	
	g_thread_unref (thread_speak);	
}

//---------------------------------------------------------------------
// change window font size
//---------------------------------------------------------------------
void change_window_font_size(GtkWindow *window){
	
	if( !GTK_IS_WINDOW(window)) { 
	return;
	}
	
	GtkCalendar *calendar =g_object_get_data(G_OBJECT(window), "calendar-key");
	GtkWidget *label_date =g_object_get_data(G_OBJECT(window), "label-date-key");
	GtkWidget *label_time =g_object_get_data(G_OBJECT(window), "label-time-key");
	GtkWidget *tree_view =g_object_get_data(G_OBJECT(window), "treeview-key");
	
	
 GtkCssProvider *cssProvider;
 //GtkSourceView *view;
 //GError *error = NULL;
 GtkStyleContext *context_window;
 GtkStyleContext *context_tree_view;
 GtkStyleContext *context_label_date;
 GtkStyleContext *context_label_time;
 GtkStyleContext *context_calendar;
 
 /* new css provider */
 cssProvider = gtk_css_provider_new(); 
 gtk_widget_set_name (GTK_WIDGET(window), "cssView"); 
 gtk_widget_set_name (GTK_WIDGET(tree_view), "cssView");   
 gtk_widget_set_name (GTK_WIDGET(label_date), "cssView");
 gtk_widget_set_name (GTK_WIDGET(label_time), "cssView");  
 gtk_widget_set_name (GTK_WIDGET(calendar), "cssView"); 
 
 
 gchar *size_str = g_strdup_printf("%i", m_font_size); 
 size_str =g_strconcat(size_str,"px;", NULL); 
 
 const gchar* font_family = m_font_family; 
 font_family =g_strconcat(font_family,";", NULL); 
 
gchar* css_str = g_strdup_printf ("#cssView {font-family: %s font-size: %s }", font_family, size_str);

gtk_css_provider_load_from_data(cssProvider, css_str,-1, NULL); 
 
/* get GtkStyleContext from widget   */
context_window = gtk_widget_get_style_context(GTK_WIDGET(window)); 
context_tree_view = gtk_widget_get_style_context(GTK_WIDGET(tree_view));  
context_label_date = gtk_widget_get_style_context(GTK_WIDGET(label_date));
context_label_time = gtk_widget_get_style_context(GTK_WIDGET(label_time));
context_calendar = gtk_widget_get_style_context(GTK_WIDGET(calendar));

 
 /* finally load style provider */
gtk_style_context_add_provider(context_window,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
                             
gtk_style_context_add_provider(context_tree_view,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

gtk_style_context_add_provider(context_label_date,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
                             
gtk_style_context_add_provider(context_label_time,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
                           

gtk_style_context_add_provider(context_calendar,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);     
	
  
}

//---------------------------------------------------------------------
// Alarm dialog spin button show leading zeros
//---------------------------------------------------------------------
static gboolean on_output_alarm_spins (GtkSpinButton *spin, gpointer data)
{
   GtkAdjustment *adjustment;
   gchar *text;
   int value;
   adjustment = gtk_spin_button_get_adjustment (spin);
   value = (int)gtk_adjustment_get_value (adjustment);
   text = g_strdup_printf ("%02d", value);
   gtk_entry_set_text (GTK_ENTRY (spin), text);
   g_free (text);
   return TRUE;
}


//---------------------------------------------------------------------
// Alarm dialog close
//---------------------------------------------------------------------
static void alarm_close_callbk(GtkDialog *dialog,
					     G_GNUC_UNUSED gpointer   user_data)  
{
	if( !GTK_IS_DIALOG(dialog)) { 
	return;
	}	
	
} 


//------------------------------------------------------------------
// Alarm dialog
//-------------------------------------------------------------------
static void talkcalendar_alarm_dialog(GtkWidget *widget) {
	
  GtkWidget *window = (GtkWidget *) widget;
   
   
  if( !GTK_IS_WINDOW(window)) {	  	 
	  return;
  }
  config_read();
  
  GtkWidget *dialog;    
  GtkWidget *container;	
  gint response;
  GtkWidget *label_alarm_info;
  
  GtkWidget *label_alarm_time;
  GtkWidget *label_alarm_colon;
  GtkWidget *spin_button_alarm_hour;
  GtkWidget *spin_button_alarm_minutes;
  GtkWidget *box_alarm_time;
  GtkWidget *check_button_alarm_notification;
  
  //Create dialog
  dialog= gtk_dialog_new();   
  gtk_window_set_title (GTK_WINDOW (dialog), "Talk Calendar"); 
  g_signal_connect_swapped(dialog,"close",G_CALLBACK(alarm_close_callbk),dialog);//escape close
  gtk_window_set_transient_for(GTK_WINDOW(dialog),GTK_WINDOW(window));  
   
  gtk_widget_set_size_request(dialog, 200,150);
  gtk_window_set_modal(GTK_WINDOW(dialog),TRUE);  
  gtk_dialog_add_button(GTK_DIALOG(dialog),"Ok",1);  
  gtk_dialog_add_button(GTK_DIALOG(dialog),"Cancel",2);
   
  gchar* alarm_str ="Set Alarm Time ";  
  label_alarm_info =gtk_label_new(alarm_str); 
  
  label_alarm_time =gtk_label_new("Alarm Time (24 hour) ");
  label_alarm_colon=gtk_label_new(" : ");
  
  spin_button_alarm_hour = gtk_spin_button_new_with_range(0.0,23.0,1.0); //23 hours	
  gtk_spin_button_set_digits(GTK_SPIN_BUTTON(spin_button_alarm_hour),0);
  gtk_spin_button_set_increments(GTK_SPIN_BUTTON(spin_button_alarm_hour),1.0,23.0);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin_button_alarm_hour),m_alarm_hour);
  gtk_spin_button_set_numeric(GTK_SPIN_BUTTON(spin_button_alarm_hour),TRUE);		
  g_signal_connect(spin_button_alarm_hour, "output", G_CALLBACK (on_output_alarm_spins), NULL);
  
  
  spin_button_alarm_minutes=gtk_spin_button_new_with_range(0.0,59.0,1.0);
  gtk_spin_button_set_digits(GTK_SPIN_BUTTON(spin_button_alarm_minutes),0);
  gtk_spin_button_set_increments(GTK_SPIN_BUTTON(spin_button_alarm_minutes),1.0,10.0);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin_button_alarm_minutes),m_alarm_min);
  gtk_spin_button_set_numeric(GTK_SPIN_BUTTON(spin_button_alarm_minutes),TRUE);		
  g_signal_connect(spin_button_alarm_minutes, "output", G_CALLBACK (on_output_alarm_spins), NULL);	
  
   
  box_alarm_time=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
  gtk_box_pack_start(GTK_BOX(box_alarm_time),label_alarm_time,FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(box_alarm_time),spin_button_alarm_hour,TRUE, TRUE, 5);
  gtk_box_pack_start(GTK_BOX(box_alarm_time),label_alarm_colon,FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(box_alarm_time),spin_button_alarm_minutes,TRUE, TRUE, 5);
 
 check_button_alarm_notification = gtk_check_button_new_with_label ("System Notification");
 gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (check_button_alarm_notification), m_alarm_notification); 
	
//---------------------------------------------------------------
// Font size
//----------------------------------------------------------------

GtkCssProvider *cssProvider;

GtkStyleContext *context_dialog;
 
GtkStyleContext *context_label_alarm_info;
GtkStyleContext *context_label_alarm_time;
GtkStyleContext *context_label_alarm_colon;
GtkStyleContext *context_spin_button_alarm_hour;
GtkStyleContext *context_spin_button_alarm_minutes; 
GtkStyleContext *context_box_alarm_time; 
GtkStyleContext *context_check_button_alarm_notification;
//new css provider 
cssProvider = gtk_css_provider_new(); 
gtk_widget_set_name (GTK_WIDGET(dialog), "cssView"); 
gtk_widget_set_name (GTK_WIDGET(label_alarm_info), "cssView"); 
gtk_widget_set_name (GTK_WIDGET(label_alarm_time), "cssView"); 
gtk_widget_set_name (GTK_WIDGET(label_alarm_colon), "cssView"); 
gtk_widget_set_name (GTK_WIDGET(spin_button_alarm_hour), "cssView"); 
gtk_widget_set_name (GTK_WIDGET(spin_button_alarm_minutes), "cssView");
gtk_widget_set_name (GTK_WIDGET(box_alarm_time), "cssView");
gtk_widget_set_name (GTK_WIDGET(check_button_alarm_notification), "cssView");

gchar *size_str = g_strdup_printf("%i", m_font_size); 
size_str =g_strconcat(size_str,"px;", NULL); 
const gchar* font_family = m_font_family; 
font_family =g_strconcat(font_family,";", NULL); 

gchar* css_str = g_strdup_printf ("#cssView {font-family: %s font-size: %s }", font_family, size_str);
gtk_css_provider_load_from_data(cssProvider, css_str,-1, NULL); 
  
// get GtkStyleContext from widget 
context_dialog = gtk_widget_get_style_context(GTK_WIDGET(dialog));  
context_label_alarm_info = gtk_widget_get_style_context(GTK_WIDGET(label_alarm_info)); 
context_label_alarm_time = gtk_widget_get_style_context(GTK_WIDGET(label_alarm_time)); 
context_label_alarm_colon= gtk_widget_get_style_context(GTK_WIDGET(label_alarm_colon)); 
context_spin_button_alarm_hour= gtk_widget_get_style_context(GTK_WIDGET(spin_button_alarm_hour));
context_spin_button_alarm_minutes= gtk_widget_get_style_context(GTK_WIDGET(spin_button_alarm_minutes));
context_box_alarm_time = gtk_widget_get_style_context(GTK_WIDGET(box_alarm_time));
context_check_button_alarm_notification= gtk_widget_get_style_context(GTK_WIDGET(check_button_alarm_notification));


gtk_style_context_add_provider(context_dialog,    
							GTK_STYLE_PROVIDER(cssProvider), 
							GTK_STYLE_PROVIDER_PRIORITY_APPLICATION); 
 
gtk_style_context_add_provider(context_label_alarm_info,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
                             
gtk_style_context_add_provider(context_label_alarm_time,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
                             
gtk_style_context_add_provider(context_label_alarm_colon,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

gtk_style_context_add_provider(context_spin_button_alarm_hour,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
                           

gtk_style_context_add_provider(context_spin_button_alarm_minutes,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
             
gtk_style_context_add_provider(context_box_alarm_time,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
                             
gtk_style_context_add_provider(context_check_button_alarm_notification,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);                             
  
//--------------------------------------------------------------
// Dialog PACKING
//--------------------------------------------------------------  
container = gtk_dialog_get_content_area (GTK_DIALOG(dialog));
gtk_container_add(GTK_CONTAINER(container),label_alarm_info);
gtk_container_add(GTK_CONTAINER(container),box_alarm_time);			
gtk_container_add(GTK_CONTAINER(container),check_button_alarm_notification);	
gtk_widget_show_all(GTK_WIDGET(dialog));      

response = gtk_dialog_run(GTK_DIALOG(dialog));  
   
  
  switch (response)
  {
  case 1: //OK
  
 
  m_alarm_hour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_button_alarm_hour));
  m_alarm_min=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_button_alarm_minutes));  
  
  m_alarm_notification =gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check_button_alarm_notification));
    
  config_write();
  
  gtk_widget_destroy(GTK_WIDGET(dialog));
  break;	 
  
  case 2: //cancel pressed   
  gtk_widget_destroy(GTK_WIDGET(dialog));	 
  break;	  
  default:
  gtk_widget_destroy(GTK_WIDGET(dialog));
  break;
  
  } //switch
  
 
}





//------------------------------------------------------------------
//  Options Talk Toggled
//------------------------------------------------------------------

static void check_button_talk_toggled_callbk (GtkToggleButton *toggle_button, gpointer user_data)
{
 	
 	GtkWidget *check_button_talk_startup; //enable startup talk  
 	GtkWidget *check_button_talk_title; //enable  talk title 
 	GtkWidget *check_button_talk_time; //enable  talk time	
 	GtkWidget *check_button_talk_priority; //enable  talk priority 
 	GtkWidget *check_button_talk_description;
 		
 	check_button_talk_startup =g_object_get_data(G_OBJECT(user_data), "cb_talk_startup_key");	
	check_button_talk_title =g_object_get_data(G_OBJECT(user_data), "cb_talk_title_key");
	check_button_talk_time =g_object_get_data(G_OBJECT(user_data), "cb_talk_time_key");  
	check_button_talk_priority= g_object_get_data(G_OBJECT(user_data), "cb_talk_priority_key");
	check_button_talk_description= g_object_get_data(G_OBJECT(user_data), "cb_talk_description_key");
	
		 	
 	if (gtk_toggle_button_get_active(toggle_button)){		
			
	gtk_widget_set_sensitive(check_button_talk_startup,TRUE);
	gtk_widget_set_sensitive(check_button_talk_title,TRUE);
	gtk_widget_set_sensitive(check_button_talk_time,TRUE);	
	gtk_widget_set_sensitive(check_button_talk_priority,TRUE);
	gtk_widget_set_sensitive(check_button_talk_description,TRUE);
	
	}     
	else{	
		
	gtk_widget_set_sensitive(check_button_talk_startup,FALSE);
	gtk_widget_set_sensitive(check_button_talk_title,FALSE);
	gtk_widget_set_sensitive(check_button_talk_time,FALSE);	
	gtk_widget_set_sensitive(check_button_talk_priority,FALSE);
	gtk_widget_set_sensitive(check_button_talk_description,FALSE);
		
	}
  
}

//----------------------------------------------------------
// Options close callback
//-----------------------------------------------------------

static void options_close_callbk(GtkDialog *dialog,
					     G_GNUC_UNUSED gpointer   user_data)  
{
	if( !GTK_IS_DIALOG(dialog)) { 
	return;
	}	
	
} 

//----------------------------------------------------------
// New Event  checkbutton allday callback
//-----------------------------------------------------------
static void check_button_allday_toggled_callbk (GtkToggleButton *toggle_button, gpointer user_data)
{
 	
 	GtkWidget *spin_button_start_hour;
 	GtkWidget *spin_button_start_minutes; 
 	GtkWidget *spin_button_end_hour;
 	GtkWidget *spin_button_end_minutes;	
 	
 	
 	spin_button_start_hour =g_object_get_data(G_OBJECT(user_data), "cb_allday_spin_start_hour_key");
	spin_button_start_minutes =g_object_get_data(G_OBJECT(user_data), "cb_allday_spin_start_min_key"); 
	spin_button_end_hour= g_object_get_data(G_OBJECT(user_data), "cb_allday_spin_end_hour_key");
	spin_button_end_minutes= g_object_get_data(G_OBJECT(user_data), "cb_allday_spin_end_min_key");
	
 	
 	if (gtk_toggle_button_get_active(toggle_button)){		
	
	gtk_widget_set_sensitive(spin_button_start_hour,FALSE);
	gtk_widget_set_sensitive(spin_button_start_minutes,FALSE);
	gtk_widget_set_sensitive(spin_button_end_hour,FALSE);
	gtk_widget_set_sensitive(spin_button_end_minutes,FALSE);
	
	
	}     
	else{	
		
	gtk_widget_set_sensitive(spin_button_start_hour,TRUE);
	gtk_widget_set_sensitive(spin_button_start_minutes,TRUE);
	gtk_widget_set_sensitive(spin_button_end_hour,TRUE);
	gtk_widget_set_sensitive(spin_button_end_minutes,TRUE);
	}
  
}

//---------------------------------------------------------------------
// combobox priority changed callback
//---------------------------------------------------------------------

static void callbk_combo_box_priority_on_changed(GtkComboBox *widget,  gpointer  user_data)
{
	GtkComboBox *combo_box_priorities = widget;
	gchar *priority_str = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(combo_box_priorities));   
	g_free (priority_str);
}

// signal handler for "toggled" signal of the CheckButton  -todo
static void check_button_isyearly_toggled_callbk (GtkToggleButton *toggle_button, gpointer user_data)
{
 	 	
 	if (gtk_toggle_button_get_active(toggle_button)){		
	 //IsYearly TRUE
	 //g_print("isYearly=TRUE\n");	
	}     
	else{	
	//IsYearly FALSE
	//g_print("isYearly=FALSE\n");
	}
  
}

//---------------------------------------------------------------------
// Update event
//---------------------------------------------------------------------

static void check_button_delete_toggled_callbk (GtkToggleButton *toggle_button, gpointer user_data)
{
 	if (gtk_toggle_button_get_active(toggle_button)){		
	//Toggled delete TRUE	
	}     
	else{	
	 //Toggled delete FALSE
	}  
}


void callbk_talkcalendar_update_event_response(GtkDialog *dialog, gint response_id,  gpointer  user_data) 
{
		
	if(!GTK_IS_DIALOG(dialog)) { 	
	return;
	}
	
	Event *event =(Event*) user_data;
	gint id =event->id;
	
	//get data
	GtkWidget *window = g_object_get_data(G_OBJECT(dialog), "dialog-window-key"); 
	GtkWidget *entry_title = g_object_get_data(G_OBJECT(dialog), "entry-title-key");  
    GtkWidget *combo_box_priority= g_object_get_data(G_OBJECT(dialog), "combo-box-priority-key");  
    GtkWidget *text_view_description= g_object_get_data(G_OBJECT(dialog), "text-view-description-key");
    GtkTextBuffer *buffer_description;   
    GtkTextIter range_start, range_end;
	GtkWidget *spin_button_start_hour= g_object_get_data(G_OBJECT(dialog), "spin-start-hour-key");  
    GtkWidget *spin_button_start_minutes= g_object_get_data(G_OBJECT(dialog), "spin-start-minutes-key");       
    GtkWidget *spin_button_end_hour= g_object_get_data(G_OBJECT(dialog), "spin-end-hour-key");	
	GtkWidget *spin_button_end_minutes= g_object_get_data(G_OBJECT(dialog), "spin-end-minutes-key"); 
    GtkWidget *check_button_allday= g_object_get_data(G_OBJECT(dialog), "check-button-allday-key"); 
    GtkWidget *check_button_isyearly= g_object_get_data(G_OBJECT(dialog), "check-button-isyearly-key");  
    GtkWidget *check_button_delete= g_object_get_data(G_OBJECT(dialog), "check-button-delete-key");
    
    //GtkWidget *list = g_object_get_data(G_OBJECT(dialog), "dialog-list-key");
    //GtkTreeSelection *selection;
    
    //GPOINTER_TO_INT()
    //gint year = GPOINTER_TO_INT(g_object_get_data(G_OBJECT(dialog), "dialog-year-key")); 
    //gint month = GPOINTER_TO_INT(g_object_get_data(G_OBJECT(dialog), "dialog-month-key"));  
    //gint day= GPOINTER_TO_INT(g_object_get_data(G_OBJECT(dialog), "dialog-day-key"));  
    //gint year = g_object_get_data(G_OBJECT(dialog), "dialog-year-key"); 
    //gint month = g_object_get_data(G_OBJECT(dialog), "dialog-month-key");  
    //gint day= g_object_get_data(G_OBJECT(dialog), "dialog-day-key");  
 
	
	switch (response_id)
	{
	case 1: //OK pressed
	
	//CHECK DELETE request	
	if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check_button_delete)) ==1) {		
	db_delete_row(id);	//DELETE  
	
	//update tree view    
	GtkWidget *calendar =g_object_get_data(G_OBJECT(window), "calendar-key"); 
    callbk_calendar_day_clicked(GTK_CALENDAR(calendar), window);
    callbk_calendar_month_changed(GTK_CALENDAR(calendar), NULL);
	
	gtk_widget_destroy(GTK_WIDGET(dialog));
	return; //return after delete	
	}
	
	if (gtk_entry_get_text_length(GTK_ENTRY(entry_title))>0) {
	const gchar *tmp_str = gtk_entry_get_text(GTK_ENTRY(entry_title));
	//sprintf(event->title,tmp_str);
	strcpy(event->title,tmp_str);
	}
	else {
	//sprintf(event->title,"No title set");
	strcpy(event->title,"No title set");
	}	 
		
	
	event->priority = gtk_combo_box_get_active(GTK_COMBO_BOX (combo_box_priority));	
		 
	buffer_description=gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view_description));		
	gtk_text_buffer_get_start_iter(GTK_TEXT_BUFFER(buffer_description), &range_start);
	range_end = range_start;
	gtk_text_iter_forward_chars(&range_end, 1000); 
	const gchar* description_str = gtk_text_buffer_get_text(GTK_TEXT_BUFFER(buffer_description),&range_start,&range_end,FALSE);

	
	strcpy(event->description,description_str); 
		
	event->startHour =gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_button_start_hour));
	event->startMin=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_button_start_minutes));		 
	event->endHour =gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_button_end_hour));
	event->endMin=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_button_end_minutes));	
	
	if ((event->endHour<event->startHour) ||
	(event->endHour==event->startHour && event->endMin < event->startMin))
	{
	event->endHour =event->startHour;
	event->endMin =event->startMin;
	}
	
	event->isAllday=gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check_button_allday));
	
	if(event->isAllday) {	
	event->startHour =0;
	event->startMin=0;		 
	event->endHour =23;
	event->endMin=59;
	}
	
	event->isYearly=gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check_button_isyearly));
	
	db_update_event(event);	
    //reload_events(window, year, month, day );	
    
    //update tree view    
	GtkWidget *calendar =g_object_get_data(G_OBJECT(window), "calendar-key"); 
    callbk_calendar_day_clicked(GTK_CALENDAR(calendar), window);
	
	g_free(event);
	//g_free(title_str); //title is const?
	//g_free(description_str);  
	gtk_widget_destroy(GTK_WIDGET(dialog));
	break;
	
	case 2: //cancel pressed	
	g_free(event); 
	gtk_widget_destroy(GTK_WIDGET(dialog)); 
	break;
	case 3:
	g_free(event);
	gtk_widget_destroy(GTK_WIDGET(dialog));
	break;
	}
	
}

//---------------------------------------------------------------------
// spin button show leading zeros
//---------------------------------------------------------------------
static gboolean on_output (GtkSpinButton *spin, gpointer data)
{
   GtkAdjustment *adjustment;
   gchar *text;
   int value;
   adjustment = gtk_spin_button_get_adjustment (spin);
   value = (int)gtk_adjustment_get_value (adjustment);
   text = g_strdup_printf ("%02d", value);
   gtk_entry_set_text (GTK_ENTRY (spin), text);
   g_free (text);
   return TRUE;
}

//static void talkcalendar_update_event(GtkWidget *widget) {
static void talkcalendar_update_event(GtkWidget *widget, gpointer data) {

 GtkWidget *window = (GtkWidget *) widget;
 Event *event =(Event*) data;
   
   if( !GTK_IS_WINDOW(window)) { 
	  return;
  }
    GtkWidget *list = g_object_get_data(G_OBJECT(window), "list-key"); //object-key association
        
    GtkWidget *dialog;    
    GtkWidget *container;	
	
	GtkWidget *label_date;
	//Title Entry
	GtkWidget *label_title;
	GtkWidget *entry_title;	
	GtkWidget *box_title;
	
	//Priority	
	GtkWidget *label_priority;
	GtkWidget *combo_box_priority;
	GtkWidget *box_priority;
		
	//Description
	GtkWidget *label_description;
	GtkWidget *text_view_description;
    GtkWidget *scrolled_window_description;
    GtkTextBuffer *buffer_description;
    GtkWidget *box_description;
   // GtkTextIter start_iter, end_iter;

	//All day
	GtkWidget *check_button_allday;
	//is yearly
	GtkWidget *check_button_isyearly;

	//Start time
	GtkWidget *label_start_time;
	GtkWidget *label_start_colon;
	GtkWidget *spin_button_start_hour;
	GtkWidget *spin_button_start_minutes;
	GtkWidget *box_start_time;
	
	//End time
	GtkWidget *label_end_time;
	GtkWidget *label_end_colon;
	GtkWidget *spin_button_end_hour;
	GtkWidget *spin_button_end_minutes;
	GtkWidget *box_end_time;
	
	//Delete event
	GtkWidget *check_button_delete;
		
			
   // gint response;
    
    GDateTime *date;
    gchar *date_str;
    date = g_date_time_new_local(event->year,event->month,event->day,0,0,0.0);
    date_str =g_date_time_format(date, "%d-%m-%Y");  //%d-%m-%Y
    g_date_time_unref (date);
    
    gchar *update_event_str;  
	update_event_str= g_strconcat("Update Event on ",date_str, NULL);
    
    label_date =gtk_label_new(update_event_str);  
    
    gtk_label_set_xalign(GTK_LABEL(label_date),0.5);  
    
    //Create dialog
    dialog= gtk_dialog_new();
    //callbacks   
    g_signal_connect(dialog,"response",G_CALLBACK(callbk_talkcalendar_update_event_response),event);
    //g_signal_connect(dialog,"close",G_CALLBACK(callbk_event_dialog_close),NULL); 
        
    gtk_window_set_title (GTK_WINDOW (dialog), "Talk Calendar");  
    
    gtk_window_set_transient_for(GTK_WINDOW(dialog),GTK_WINDOW(window));  
    //gtk_window_set_title(GTK_WINDOW(dialog),"Update Event");
    gtk_widget_set_size_request(dialog, 300,200);
    gtk_window_set_modal(GTK_WINDOW(dialog),TRUE);  
    gtk_dialog_add_button(GTK_DIALOG(dialog),"Ok",1);  //OK response_id=1
    gtk_dialog_add_button(GTK_DIALOG(dialog),"Cancel",2); //Cancel response_id=2
    gtk_dialog_set_default_response(GTK_DIALOG(dialog),2); //default response cancel
           
	//--------------------------------------------------------
	// Title entry
	//---------------------------------------------------------
	label_title =gtk_label_new("Event Title: ");  
	entry_title =gtk_entry_new(); 
	gtk_entry_set_max_length(GTK_ENTRY(entry_title),30); 
	box_title=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
	gtk_box_pack_start(GTK_BOX(box_title),label_title,FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box_title),entry_title,TRUE, TRUE, 0);
	 
	gtk_entry_set_text(GTK_ENTRY(entry_title), event->title);
	  
	  //---------------------------------------------------------------
	  // Priority combobox
	  //------------------------------------------------------------------
	  
	  label_priority =gtk_label_new("Priority: ");  
	  /* Create the combo box and append your string values to it. */
	  combo_box_priority = gtk_combo_box_text_new ();
	  const char *priority[] = {"None", 
	  "Low", 
	  "Medium", 
	  "High"};
	  
	  
	  /* G_N_ELEMENTS is a macro which determines the number of elements in an array.*/ 
	  for (int i = 0; i < G_N_ELEMENTS (priority); i++){
	  gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (combo_box_priority), priority[i]);
	  }
	  
	  gtk_combo_box_set_active (GTK_COMBO_BOX (combo_box_priority),event->priority);	
	  g_signal_connect (combo_box_priority,"changed", G_CALLBACK (callbk_combo_box_priority_on_changed), NULL);
	  box_priority=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
	  gtk_box_pack_start(GTK_BOX(box_priority),label_priority,FALSE, FALSE, 0);
	  gtk_box_pack_start(GTK_BOX(box_priority),combo_box_priority,TRUE, TRUE, 0);
	
	
	//---------------------------------------------------------
	// Description entry
	//----------------------------------------------------------     
	label_description =gtk_label_new("Description: ");   
	buffer_description = gtk_text_buffer_new (NULL); 
	text_view_description = gtk_text_view_new_with_buffer (buffer_description); 
	gtk_text_view_set_editable(GTK_TEXT_VIEW(text_view_description),TRUE);  
	gtk_text_view_set_wrap_mode (GTK_TEXT_VIEW (text_view_description), GTK_WRAP_WORD); 
	scrolled_window_description = gtk_scrolled_window_new (NULL, NULL);
	gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolled_window_description), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);      
	gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(scrolled_window_description),GTK_SHADOW_ETCHED_IN);  
	gtk_container_set_border_width (GTK_CONTAINER (scrolled_window_description), 5);  
	gtk_container_add (GTK_CONTAINER (scrolled_window_description), text_view_description); 
	box_description=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
	gtk_box_pack_start(GTK_BOX(box_description),label_description,FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box_description),scrolled_window_description,TRUE, TRUE, 0);
	
	gtk_text_buffer_set_text (buffer_description, event->description, -1);  
		
	
	//--------------------------------------------------------
	// Start time spin buttons
	//--------------------------------------------------------- 
	label_start_time =gtk_label_new("Start Time (24 hour) ");
	label_start_colon=gtk_label_new(" : ");
	
	spin_button_start_hour = gtk_spin_button_new_with_range(0.0,23.0,1.0); //23 hours	
	gtk_spin_button_set_digits(GTK_SPIN_BUTTON(spin_button_start_hour),0);
	gtk_spin_button_set_increments(GTK_SPIN_BUTTON(spin_button_start_hour),1.0,23.0);
	gtk_spin_button_set_numeric(GTK_SPIN_BUTTON(spin_button_start_hour),TRUE);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin_button_start_hour),event->startHour);	
	g_signal_connect(spin_button_start_hour, "output", G_CALLBACK (on_output), NULL);
	
	
	spin_button_start_minutes=gtk_spin_button_new_with_range(0.0,59.0,1.0);
	gtk_spin_button_set_digits(GTK_SPIN_BUTTON(spin_button_start_minutes),0);
	gtk_spin_button_set_increments(GTK_SPIN_BUTTON(spin_button_start_minutes),1.0,10.0);
	gtk_spin_button_set_numeric(GTK_SPIN_BUTTON(spin_button_start_minutes),TRUE);	
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin_button_start_minutes),event->startMin);	
	g_signal_connect(spin_button_start_minutes, "output", G_CALLBACK (on_output), NULL);		
	
	box_start_time=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
	gtk_box_pack_start(GTK_BOX(box_start_time),label_start_time,FALSE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(box_start_time),spin_button_start_hour,TRUE, TRUE, 5);
	gtk_box_pack_start(GTK_BOX(box_start_time),label_start_colon,FALSE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(box_start_time),spin_button_start_minutes,TRUE, TRUE, 5);
		
	//--------------------------------------------------------
	// End time spin buttons
	//---------------------------------------------------------  
	label_end_time =gtk_label_new("End Time (24 hour) ");
	label_end_colon=gtk_label_new(" : ");
	
	spin_button_end_hour = gtk_spin_button_new_with_range(0.0,23.0,1.0); //23 hours	
	gtk_spin_button_set_digits(GTK_SPIN_BUTTON(spin_button_end_hour),0);
	gtk_spin_button_set_increments(GTK_SPIN_BUTTON(spin_button_end_hour),1.0,23.0);
	gtk_spin_button_set_numeric(GTK_SPIN_BUTTON(spin_button_end_hour),TRUE);	
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin_button_end_hour),event->endHour);	
	g_signal_connect(spin_button_end_hour, "output", G_CALLBACK (on_output), NULL);
	
	spin_button_end_minutes=gtk_spin_button_new_with_range(0.0,59.0,1.0);
	gtk_spin_button_set_digits(GTK_SPIN_BUTTON(spin_button_end_minutes),0);
	gtk_spin_button_set_increments(GTK_SPIN_BUTTON(spin_button_end_minutes),1.0,10.0);
	gtk_spin_button_set_numeric(GTK_SPIN_BUTTON(spin_button_end_minutes),TRUE);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin_button_end_minutes), event->endMin);	
	g_signal_connect(spin_button_end_minutes, "output", G_CALLBACK (on_output), NULL);	
	
	box_end_time=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
	gtk_box_pack_start(GTK_BOX(box_end_time),label_end_time,FALSE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(box_end_time),spin_button_end_hour,TRUE, TRUE, 5);
	gtk_box_pack_start(GTK_BOX(box_end_time),label_end_colon,FALSE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(box_end_time),spin_button_end_minutes,TRUE, TRUE, 5);
		
	//---------------------------------------------------------------
	// All day checkbox
	//---------------------------------------------------------------
	
	check_button_allday = gtk_check_button_new_with_label ("All Day Event");
	
	 gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (check_button_allday), event->isAllday); 
    
    if(event->isAllday) {
		gtk_widget_set_sensitive(spin_button_start_hour,FALSE);
	    gtk_widget_set_sensitive(spin_button_start_minutes,FALSE);
	    gtk_widget_set_sensitive(spin_button_end_hour,FALSE);
	    gtk_widget_set_sensitive(spin_button_end_minutes,FALSE);
	}
	else {
		gtk_widget_set_sensitive(spin_button_start_hour,TRUE);
		gtk_widget_set_sensitive(spin_button_start_minutes,TRUE);
		gtk_widget_set_sensitive(spin_button_end_hour,TRUE);
		gtk_widget_set_sensitive(spin_button_end_minutes,TRUE);
	}
	
	 g_object_set_data(G_OBJECT(check_button_allday), "cb_allday_spin_start_hour_key",spin_button_start_hour);
	 g_object_set_data(G_OBJECT(check_button_allday), "cb_allday_spin_start_min_key",spin_button_start_minutes); 
	 g_object_set_data(G_OBJECT(check_button_allday), "cb_allday_spin_end_hour_key",spin_button_end_hour);
	 g_object_set_data(G_OBJECT(check_button_allday), "cb_allday_spin_end_min_key",spin_button_end_minutes);
	
	 
       
    g_signal_connect_swapped (GTK_TOGGLE_BUTTON (check_button_allday), "toggled", 
						G_CALLBACK (check_button_allday_toggled_callbk), check_button_allday);
						
   
		
	//---------------------------------------------------------------
	// Is yearly checkbox
	//---------------------------------------------------------------
	check_button_isyearly = gtk_check_button_new_with_label ("Is Yearly");
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (check_button_isyearly), event->isYearly);
	
	g_signal_connect_swapped (GTK_TOGGLE_BUTTON (check_button_allday), "toggled", 
						G_CALLBACK (check_button_isyearly_toggled_callbk), check_button_isyearly);
						
	
	
	// Delete check button
	check_button_delete = gtk_check_button_new_with_label ("Delete Event");
    gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (check_button_delete), FALSE);   
    g_signal_connect (GTK_TOGGLE_BUTTON (check_button_delete), "toggled", G_CALLBACK (check_button_delete_toggled_callbk), NULL);
	
	//Data
	
	 //set up dialog data connections	
	 //g_object_set_data() makes a connection between two objects
	 g_object_set_data(G_OBJECT(dialog), "dialog-window-key",window); 
	 g_object_set_data(G_OBJECT(dialog), "entry-title-key",entry_title);  
     g_object_set_data(G_OBJECT(dialog), "combo-box-priority-key",combo_box_priority);  
     g_object_set_data(G_OBJECT(dialog), "text-view-description-key",text_view_description);	
	 g_object_set_data(G_OBJECT(dialog), "spin-start-hour-key",spin_button_start_hour);  
     g_object_set_data(G_OBJECT(dialog), "spin-start-minutes-key",spin_button_start_minutes); 
     g_object_set_data(G_OBJECT(dialog), "spin-end-hour-key",spin_button_end_hour);	
	 g_object_set_data(G_OBJECT(dialog), "spin-end-minutes-key",spin_button_end_minutes);  
     g_object_set_data(G_OBJECT(dialog), "check-button-allday-key",check_button_allday);
     g_object_set_data(G_OBJECT(dialog), "check-button-isyearly-key",check_button_isyearly);
     g_object_set_data(G_OBJECT(dialog), "check-button-delete-key",check_button_delete);
     g_object_set_data(G_OBJECT(dialog), "dialog-list-key",list);
     
     g_object_set_data(G_OBJECT(dialog), "dialog-year-key",GINT_TO_POINTER(event->year)); 
     g_object_set_data(G_OBJECT(dialog), "dialog-month-key",GINT_TO_POINTER(event->month));  
     g_object_set_data(G_OBJECT(dialog), "dialog-day-key",GINT_TO_POINTER(event->day));  
    
   
//---------------------------------------------------------------
// Font size
//----------------------------------------------------------------

GtkCssProvider *cssProvider;
 
GtkStyleContext *context_dialog;

GtkStyleContext *context_label_date;
 
GtkStyleContext *context_label_title;
GtkStyleContext *context_entry_title;
GtkStyleContext *context_box_title;

GtkStyleContext *context_label_priority;
GtkStyleContext *context_combo_box_priority;
GtkStyleContext *context_box_priority;

GtkStyleContext *context_label_description;
GtkStyleContext *context_text_view_description;
GtkStyleContext *context_scrolled_window_description;
GtkStyleContext *context_box_description;
  
GtkStyleContext *context_check_button_allday;
GtkStyleContext *context_check_button_isyearly;
GtkStyleContext *context_check_button_delete;
  
GtkStyleContext *context_label_start_time; 
GtkStyleContext *context_label_start_colon; 
GtkStyleContext *context_spin_button_start_hour;  
GtkStyleContext *context_spin_button_start_minutes; 
GtkStyleContext *context_box_start_time; 

GtkStyleContext *context_label_end_time; 
GtkStyleContext *context_label_end_colon;  
GtkStyleContext *context_spin_button_end_hour;  
GtkStyleContext *context_spin_button_end_minutes; 
GtkStyleContext *context_box_end_time; 

    
//new css provider 
cssProvider = gtk_css_provider_new(); 

gtk_widget_set_name (GTK_WIDGET(dialog), "cssView"); 
gtk_widget_set_name (GTK_WIDGET(label_date), "cssView"); 

//title
gtk_widget_set_name (GTK_WIDGET(label_title), "cssView"); 
gtk_widget_set_name (GTK_WIDGET(entry_title), "cssView"); 
gtk_widget_set_name (GTK_WIDGET(box_title), "cssView");
//priority
gtk_widget_set_name (GTK_WIDGET(label_priority), "cssView"); 
gtk_widget_set_name (GTK_WIDGET(combo_box_priority), "cssView"); 
gtk_widget_set_name (GTK_WIDGET(box_priority), "cssView");
//description
gtk_widget_set_name (GTK_WIDGET(label_description), "cssView"); 
gtk_widget_set_name (GTK_WIDGET(text_view_description), "cssView");  
gtk_widget_set_name (GTK_WIDGET(scrolled_window_description), "cssView"); 
gtk_widget_set_name (GTK_WIDGET(box_description), "cssView");

//check buttons
gtk_widget_set_name (GTK_WIDGET(check_button_allday), "cssView");
gtk_widget_set_name (GTK_WIDGET(check_button_isyearly), "cssView"); 
gtk_widget_set_name (GTK_WIDGET(check_button_delete), "cssView");
//spin buttons
gtk_widget_set_name (GTK_WIDGET(label_start_time), "cssView");  
gtk_widget_set_name (GTK_WIDGET(label_start_colon), "cssView"); 
gtk_widget_set_name (GTK_WIDGET(spin_button_start_hour), "cssView"); 
gtk_widget_set_name (GTK_WIDGET(spin_button_start_minutes), "cssView"); 
gtk_widget_set_name (GTK_WIDGET(box_start_time), "cssView"); 

gtk_widget_set_name (GTK_WIDGET(label_end_time), "cssView");  
gtk_widget_set_name (GTK_WIDGET(label_end_colon), "cssView"); 
gtk_widget_set_name (GTK_WIDGET(spin_button_end_hour), "cssView"); 
gtk_widget_set_name (GTK_WIDGET(spin_button_end_minutes), "cssView"); 
gtk_widget_set_name (GTK_WIDGET(box_end_time), "cssView"); 

gchar *size_str = g_strdup_printf("%i", m_font_size); 
size_str =g_strconcat(size_str,"px;", NULL); 

const gchar* font_family = m_font_family; 
font_family =g_strconcat(font_family,";", NULL); 

gchar* css_str = g_strdup_printf ("#cssView {font-family: %s font-size: %s }", font_family, size_str);
gtk_css_provider_load_from_data(cssProvider, css_str,-1, NULL); 
 
  
// get GtkStyleContext from widget 
context_dialog = gtk_widget_get_style_context(GTK_WIDGET(dialog));

context_label_date = gtk_widget_get_style_context(GTK_WIDGET(label_date)); 
//title  
context_label_title = gtk_widget_get_style_context(GTK_WIDGET(label_title)); 
context_entry_title= gtk_widget_get_style_context(GTK_WIDGET(entry_title)); 
context_box_title= gtk_widget_get_style_context(GTK_WIDGET(box_title));
//priority
context_label_priority = gtk_widget_get_style_context(GTK_WIDGET(label_priority)); 
context_combo_box_priority= gtk_widget_get_style_context(GTK_WIDGET(combo_box_priority)); 
context_box_priority= gtk_widget_get_style_context(GTK_WIDGET(box_priority));
//description
context_label_description= gtk_widget_get_style_context(GTK_WIDGET(label_description));  
context_text_view_description = gtk_widget_get_style_context(GTK_WIDGET(text_view_description));
context_scrolled_window_description= gtk_widget_get_style_context(GTK_WIDGET(scrolled_window_description)); 
context_box_description = gtk_widget_get_style_context(GTK_WIDGET(box_description));
//checkbuttons
context_check_button_allday = gtk_widget_get_style_context(GTK_WIDGET(check_button_allday));
context_check_button_isyearly= gtk_widget_get_style_context(GTK_WIDGET(check_button_isyearly));
context_check_button_delete= gtk_widget_get_style_context(GTK_WIDGET(check_button_delete));
//spin buttons
context_label_start_time= gtk_widget_get_style_context(GTK_WIDGET(label_start_time));  
context_label_start_colon = gtk_widget_get_style_context(GTK_WIDGET(label_start_colon));
context_spin_button_start_hour= gtk_widget_get_style_context(GTK_WIDGET(spin_button_start_hour)); 
context_spin_button_start_minutes = gtk_widget_get_style_context(GTK_WIDGET(spin_button_start_minutes));
context_box_start_time = gtk_widget_get_style_context(GTK_WIDGET(box_start_time));

context_label_end_time= gtk_widget_get_style_context(GTK_WIDGET(label_end_time));  
context_label_end_colon = gtk_widget_get_style_context(GTK_WIDGET(label_end_colon));
context_spin_button_end_hour= gtk_widget_get_style_context(GTK_WIDGET(spin_button_end_hour)); 
context_spin_button_end_minutes = gtk_widget_get_style_context(GTK_WIDGET(spin_button_end_minutes));
context_box_end_time = gtk_widget_get_style_context(GTK_WIDGET(box_end_time));


//finally load style provider 
gtk_style_context_add_provider(context_dialog,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
//date
gtk_style_context_add_provider(context_label_date,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

//title
gtk_style_context_add_provider(context_label_title,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
                             
gtk_style_context_add_provider(context_entry_title,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
                             
gtk_style_context_add_provider(context_box_title,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
//priority                             
gtk_style_context_add_provider(context_label_priority,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
                             
gtk_style_context_add_provider(context_combo_box_priority,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
                             
gtk_style_context_add_provider(context_box_priority,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
//description
gtk_style_context_add_provider(context_label_description,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
                             
gtk_style_context_add_provider(context_text_view_description,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
                              
gtk_style_context_add_provider(context_scrolled_window_description,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);   

gtk_style_context_add_provider(context_box_description,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

//checkbuttons
gtk_style_context_add_provider(context_check_button_allday,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

gtk_style_context_add_provider(context_check_button_isyearly,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
                             
gtk_style_context_add_provider(context_check_button_delete,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
//spinbuttons start
gtk_style_context_add_provider(context_label_start_time,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
                             
gtk_style_context_add_provider(context_label_start_colon,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
                             
gtk_style_context_add_provider(context_spin_button_start_hour,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION); 
                             
gtk_style_context_add_provider(context_spin_button_start_minutes,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION); 
                                                                                                                  
gtk_style_context_add_provider(context_box_start_time,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);                             

//spinbuttons end

gtk_style_context_add_provider(context_label_end_time,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
                             
gtk_style_context_add_provider(context_label_end_colon,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
                             
gtk_style_context_add_provider(context_spin_button_end_hour,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION); 
                             
gtk_style_context_add_provider(context_spin_button_end_minutes,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION); 
                                                                                                                  
gtk_style_context_add_provider(context_box_end_time,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
         	
	//--------------------------------------------------------------
	// Dialog PACKING
	//--------------------------------------------------------------  
	container = gtk_dialog_get_content_area (GTK_DIALOG(dialog));
	gtk_container_add(GTK_CONTAINER(container),label_date);	
	gtk_container_add(GTK_CONTAINER(container),box_title);
	gtk_container_add(GTK_CONTAINER(container),box_priority);			
	gtk_container_add (GTK_CONTAINER (container), box_description);	
	gtk_container_add(GTK_CONTAINER(container),check_button_allday);
	gtk_container_add(GTK_CONTAINER(container),check_button_isyearly);
	gtk_container_add(GTK_CONTAINER(container),box_start_time);		
	gtk_container_add(GTK_CONTAINER(container),box_end_time);
	gtk_container_add(GTK_CONTAINER(container),check_button_delete);
	gtk_widget_show_all(dialog);    
	
  
}









//--------------------------------------------------------------------
// New event dialog close callback
//---------------------------------------------------------------------

static void callbk_event_dialog_close(GtkDialog *dialog,
					     G_GNUC_UNUSED gpointer   user_data)  
{
	if( !GTK_IS_DIALOG(dialog)) { 
	return;
	}
	gtk_widget_destroy(GTK_WIDGET(dialog));
} 

//---------------------------------------------------------------------
// spin button show leading zeros
//---------------------------------------------------------------------
//static gboolean on_output (GtkSpinButton *spin, gpointer data)
//{
   //GtkAdjustment *adjustment;
   //gchar *text;
   //int value;
   //adjustment = gtk_spin_button_get_adjustment (spin);
   //value = (int)gtk_adjustment_get_value (adjustment);
   //text = g_strdup_printf ("%02d", value);
   //gtk_entry_set_text (GTK_ENTRY (spin), text);
   //g_free (text);
   //return TRUE;
//}

//--------------------------------------------------------------------
// New event response callback
//---------------------------------------------------------------------


void callbk_talkcalendar_new_event_response(GtkDialog *dialog, gint response_id,  gpointer  user_data) 
{
	
	if(!GTK_IS_DIALOG(dialog)) { 
	return;
	}
	Event *event =user_data;
	
	//get data
	GtkWidget *window = g_object_get_data(G_OBJECT(dialog), "dialog-window-key"); 
	GtkWidget *entry_title = g_object_get_data(G_OBJECT(dialog), "entry-title-key");  
    GtkWidget *combo_box_priority= g_object_get_data(G_OBJECT(dialog), "combo-box-priority-key");  
    GtkWidget *text_view_description= g_object_get_data(G_OBJECT(dialog), "text-view-description-key");
    GtkTextBuffer *buffer_description;    
    GtkTextIter range_start, range_end;    
	GtkWidget *spin_button_start_hour= g_object_get_data(G_OBJECT(dialog), "spin-start-hour-key");  
    GtkWidget *spin_button_start_minutes= g_object_get_data(G_OBJECT(dialog), "spin-start-minutes-key");       
    GtkWidget *spin_button_end_hour= g_object_get_data(G_OBJECT(dialog), "spin-end-hour-key");	
	GtkWidget *spin_button_end_minutes= g_object_get_data(G_OBJECT(dialog), "spin-end-minutes-key"); 
    GtkWidget *check_button_allday= g_object_get_data(G_OBJECT(dialog), "check-button-allday-key");  
    GtkWidget *check_button_isyearly= g_object_get_data(G_OBJECT(dialog), "check-button-isyearly-key"); 
    //GtkWidget *check_button_delete= g_object_get_data(G_OBJECT(dialog), "check-button-delete-key");
    //GPOINTER_TO_INT()
    gint year = GPOINTER_TO_INT(g_object_get_data(G_OBJECT(dialog), "dialog-year-key")); 
    gint month = GPOINTER_TO_INT(g_object_get_data(G_OBJECT(dialog), "dialog-month-key"));  
    gint day= GPOINTER_TO_INT(g_object_get_data(G_OBJECT(dialog), "dialog-day-key"));  
 
	
switch (response_id)
{
	case 1: //Ok pressed
	event->year =year;
	event->month=month;
	event->day=day;
	
	if (gtk_entry_get_text_length(GTK_ENTRY(entry_title))>0) {
	const gchar *tmp_str = gtk_entry_get_text(GTK_ENTRY(entry_title));
	//sprintf(event->title,tmp_str);
	strcpy(event->title,tmp_str);
	}
	else {
	//sprintf(event->title,"No title set");
	strcpy(event->title,"No title set");
	}	 
  
	gint active_id = gtk_combo_box_get_active (GTK_COMBO_BOX(combo_box_priority));
  
	  switch (active_id)
	  {
		  case 0:
		  event->priority=0; //None
		  break;
		  case 1:
		  event->priority=1; //Low
		  break;
		  case 2:
		  event->priority=2; //Medium
		  break;
		  case 3:
		  event->priority=3; //High
		  break;		  
		  default:
		  event->priority=0; 
		  break; 
	  }
	  
	  
	 
	buffer_description=gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view_description));	
	
	gtk_text_buffer_get_start_iter(GTK_TEXT_BUFFER(buffer_description), &range_start);
	range_end = range_start;
	gtk_text_iter_forward_chars(&range_end, 1000); 
	const gchar* description_str = gtk_text_buffer_get_text(GTK_TEXT_BUFFER(buffer_description),&range_start,&range_end,FALSE);

	strcpy(event->description,description_str); 

	 
   
  event->startHour =gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_button_start_hour));
  event->startMin=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_button_start_minutes));		 
  event->endHour =gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_button_end_hour));
  event->endMin=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_button_end_minutes));	
  
  if ((event->endHour<event->startHour) ||
  (event->endHour==event->startHour && event->endMin < event->startMin))
  {
	  event->endHour =event->startHour;
	  event->endMin =event->startMin;
  }
  
  event->isAllday=gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check_button_allday));   
  
    
  if(event->isAllday) 
  {	
	  event->startHour =0;
	  event->startMin=0;		 
	  event->endHour =23;
	  event->endMin=59;
  }
  
  event->isYearly=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(check_button_isyearly));
  db_insert_event(event);
  
  //Reload events
  //reload_events(window, year, month, day );
  
  GtkWidget *calendar =g_object_get_data(G_OBJECT(window), "calendar-key"); 
  callbk_calendar_day_clicked(GTK_CALENDAR(calendar), window);
  callbk_calendar_month_changed(GTK_CALENDAR(calendar), NULL);
   
  g_free(event);
  
  gtk_widget_destroy(GTK_WIDGET(dialog));
  break;
  
	case 2:	
	g_free(event);
	gtk_widget_destroy(GTK_WIDGET(dialog));
	break;
	
	case 3:	
	g_free(event);
	gtk_widget_destroy(GTK_WIDGET(dialog));
	break;
}	
	
}
//----------------------------------------------------------------------
// Talk Calendar  New Event
//----------------------------------------------------------------------

static void talkcalendar_new_event(GtkWidget *widget, guint year, guint month, guint day ) {

 GtkWidget *window = (GtkWidget *) widget;
   
   if( !GTK_IS_WINDOW(window)) { 
	  return;
  }
 
  
    GtkWidget *dialog;    
    GtkWidget *container;	
	//Event date
	GtkWidget *label_date;
	//Title Entry
	GtkWidget *label_title;
	GtkWidget *entry_title;	
	GtkWidget *box_title;
	
	//Priority	
	GtkWidget *label_priority;
	GtkWidget *combo_box_priority;
	GtkWidget *box_priority;
	
	
	//Description
	GtkWidget *label_description;
	GtkWidget *text_view_description;
    GtkWidget *scrolled_window_description;
    GtkTextBuffer *buffer_description;
    GtkWidget *box_description;
    //GtkTextIter start_iter, end_iter;

	//All day
	GtkWidget *check_button_allday;
	//Is yearly
	GtkWidget *check_button_isyearly;
	//GtkWidget *check_button_delete; //not used with new event


	//Start time
	GtkWidget *label_start_time;
	GtkWidget *label_start_colon;
	GtkWidget *spin_button_start_hour;
	GtkWidget *spin_button_start_minutes;
	GtkWidget *box_start_time;
	
	//End time
	GtkWidget *label_end_time;
	GtkWidget *label_end_colon;
	GtkWidget *spin_button_end_hour;
	GtkWidget *spin_button_end_minutes;
	GtkWidget *box_end_time;
		
	 //Event event;	
	 Event *event =g_malloc(sizeof(Event));	//free in callbk
      
    GDateTime *date;
    gchar *date_str;
    date = g_date_time_new_local(year,month,day,0,0,0.0);
    date_str =g_date_time_format(date, "%d-%m-%Y");  //%d-%m-%Y
    g_date_time_unref (date);
    
    gchar *new_event_str;  
	new_event_str= g_strconcat("New Event on ",date_str, NULL);
    label_date =gtk_label_new(new_event_str);  
    
    gtk_label_set_xalign(GTK_LABEL(label_date),0.5);
	//gtk_label_set_text(GTK_LABEL(label_date), dt_format); 
    
       
    //Create dialog
    dialog= gtk_dialog_new(); 
    gtk_window_set_title (GTK_WINDOW (dialog), "Talk Calendar"); 
   
   //dialog new event callbacks   
    g_signal_connect(dialog,"response",G_CALLBACK(callbk_talkcalendar_new_event_response),event);
    g_signal_connect(dialog,"close",G_CALLBACK(callbk_event_dialog_close),NULL); 
    
    gtk_window_set_transient_for(GTK_WINDOW(dialog),GTK_WINDOW(window));  
    //gtk_window_set_title(GTK_WINDOW(dialog),"New Event");
    gtk_widget_set_size_request(dialog, 300,200);
    gtk_window_set_modal(GTK_WINDOW(dialog),TRUE);  
    gtk_dialog_add_button(GTK_DIALOG(dialog),"Ok",1);  //Ok button has response_id=1
    gtk_dialog_add_button(GTK_DIALOG(dialog),"Cancel",2); //Cancel button has response_id =2
    //Note all other actions have response_id =3
    gtk_dialog_set_default_response(GTK_DIALOG(dialog),2); //default response cancel
       
	//--------------------------------------------------------
	// Title entry
	//---------------------------------------------------------
	label_title =gtk_label_new("Event Title: ");  
	entry_title =gtk_entry_new(); 
	gtk_entry_set_max_length(GTK_ENTRY(entry_title),30); 
	box_title=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
	gtk_box_pack_start(GTK_BOX(box_title),label_title,FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box_title),entry_title,TRUE, TRUE, 0);
	  
	//---------------------------------------------------------------
	// Priority combobox
	//------------------------------------------------------------------
	
	label_priority =gtk_label_new("Priority: ");  
	/* Create the combo box and append your string values to it. */
    combo_box_priority = gtk_combo_box_text_new ();
    const char *priority[] = {"None", 
	"Low", 
	"Medium", 
	"High"};
	
	
	/* G_N_ELEMENTS is a macro which determines the number of elements in an array.*/ 
	for (int i = 0; i < G_N_ELEMENTS (priority); i++){
	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (combo_box_priority), priority[i]);
	}
	
	gtk_combo_box_set_active (GTK_COMBO_BOX (combo_box_priority), 0);	
	g_signal_connect (combo_box_priority,"changed", G_CALLBACK (callbk_combo_box_priority_on_changed), NULL);
	box_priority=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
	gtk_box_pack_start(GTK_BOX(box_priority),label_priority,FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box_priority),combo_box_priority,TRUE, TRUE, 0);
	
	//---------------------------------------------------------
	// Description entry
	//----------------------------------------------------------     
	label_description =gtk_label_new("Description: ");   
	buffer_description = gtk_text_buffer_new (NULL); 
	text_view_description = gtk_text_view_new_with_buffer (buffer_description); 
	gtk_text_view_set_editable(GTK_TEXT_VIEW(text_view_description),TRUE);  
	gtk_text_view_set_wrap_mode (GTK_TEXT_VIEW (text_view_description), GTK_WRAP_WORD); 
	scrolled_window_description = gtk_scrolled_window_new (NULL, NULL);
	gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolled_window_description), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);      
	gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(scrolled_window_description),GTK_SHADOW_ETCHED_IN);  
	gtk_container_set_border_width (GTK_CONTAINER (scrolled_window_description), 5);  
	gtk_container_add (GTK_CONTAINER (scrolled_window_description), text_view_description); 
	box_description=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
	gtk_box_pack_start(GTK_BOX(box_description),label_description,FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box_description),scrolled_window_description,TRUE, TRUE, 0);
		
	
	//--------------------------------------------------------
	// Start time spin buttons
	//--------------------------------------------------------- 
	label_start_time =gtk_label_new("Start Time (24 hour) ");
	label_start_colon=gtk_label_new(" : ");
	spin_button_start_hour = gtk_spin_button_new_with_range(0.0,23.0,1.0); //23 hours	
	gtk_spin_button_set_digits(GTK_SPIN_BUTTON(spin_button_start_hour),0);
	gtk_spin_button_set_increments(GTK_SPIN_BUTTON(spin_button_start_hour),1.0,23.0);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin_button_start_hour),0.0);
	gtk_spin_button_set_numeric(GTK_SPIN_BUTTON(spin_button_start_hour),TRUE);		
	g_signal_connect(spin_button_start_hour, "output", G_CALLBACK (on_output), NULL);
	
	spin_button_start_minutes=gtk_spin_button_new_with_range(0.0,59.0,1.0);
	gtk_spin_button_set_digits(GTK_SPIN_BUTTON(spin_button_start_minutes),0);
	gtk_spin_button_set_increments(GTK_SPIN_BUTTON(spin_button_start_minutes),1.0,10.0);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin_button_start_minutes),0.0);
	gtk_spin_button_set_numeric(GTK_SPIN_BUTTON(spin_button_start_minutes),TRUE);	
	
	g_signal_connect(spin_button_start_minutes, "output", G_CALLBACK (on_output), NULL);		
	
	box_start_time=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
	gtk_box_pack_start(GTK_BOX(box_start_time),label_start_time,FALSE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(box_start_time),spin_button_start_hour,TRUE, TRUE, 5);
	gtk_box_pack_start(GTK_BOX(box_start_time),label_start_colon,FALSE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(box_start_time),spin_button_start_minutes,TRUE, TRUE, 5);
		
	//--------------------------------------------------------
	// End time spin buttons
	//---------------------------------------------------------  
	label_end_time =gtk_label_new("End Time (24 hour) ");
	label_end_colon=gtk_label_new(" : ");
	spin_button_end_hour = gtk_spin_button_new_with_range(0.0,23.0,1.0); //23 hours	
	gtk_spin_button_set_digits(GTK_SPIN_BUTTON(spin_button_end_hour),0);
	gtk_spin_button_set_increments(GTK_SPIN_BUTTON(spin_button_end_hour),1.0,23.0);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin_button_end_hour),0.0);
	gtk_spin_button_set_numeric(GTK_SPIN_BUTTON(spin_button_end_hour),TRUE);
	g_signal_connect(spin_button_end_hour, "output", G_CALLBACK (on_output), NULL);
	
	spin_button_end_minutes=gtk_spin_button_new_with_range(0.0,59.0,1.0);
	gtk_spin_button_set_digits(GTK_SPIN_BUTTON(spin_button_end_minutes),0);
	gtk_spin_button_set_increments(GTK_SPIN_BUTTON(spin_button_end_minutes),1.0,10.0);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin_button_end_minutes),0.0);
	gtk_spin_button_set_numeric(GTK_SPIN_BUTTON(spin_button_end_minutes),TRUE);		 
	g_signal_connect(spin_button_end_minutes, "output", G_CALLBACK (on_output), NULL);	
	
		
	box_end_time=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
	gtk_box_pack_start(GTK_BOX(box_end_time),label_end_time,FALSE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(box_end_time),spin_button_end_hour,TRUE, TRUE, 5);
	gtk_box_pack_start(GTK_BOX(box_end_time),label_end_colon,FALSE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(box_end_time),spin_button_end_minutes,TRUE, TRUE, 5);
	
	//---------------------------------------------------------------
	// All day checkbox
	//---------------------------------------------------------------
	//gboolean f_all_day =FALSE;
	check_button_allday = gtk_check_button_new_with_label ("All Day Event");
	
	g_object_set_data(G_OBJECT(check_button_allday), "cb_allday_spin_start_hour_key",spin_button_start_hour);
	g_object_set_data(G_OBJECT(check_button_allday), "cb_allday_spin_start_min_key",spin_button_start_minutes); 
	g_object_set_data(G_OBJECT(check_button_allday), "cb_allday_spin_end_hour_key",spin_button_end_hour);
	g_object_set_data(G_OBJECT(check_button_allday), "cb_allday_spin_end_min_key",spin_button_end_minutes);
	
	 
       
    g_signal_connect_swapped (GTK_TOGGLE_BUTTON (check_button_allday), "toggled", 
						G_CALLBACK (check_button_allday_toggled_callbk), check_button_allday);
						
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (check_button_allday), FALSE);  
	
	//---------------------------------------------------------------
	// Is Yearly checkbox
	//---------------------------------------------------------------
	check_button_isyearly = gtk_check_button_new_with_label ("Is Yearly");
	g_signal_connect_swapped (GTK_TOGGLE_BUTTON (check_button_allday), "toggled", 
						G_CALLBACK (check_button_isyearly_toggled_callbk), check_button_isyearly);
						
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (check_button_allday), FALSE);
	
	 //set up dialog data connections	
	 //g_object_set_data() makes a connection between two objects
	 g_object_set_data(G_OBJECT(dialog), "dialog-window-key",window); 
	 g_object_set_data(G_OBJECT(dialog), "entry-title-key",entry_title);  
     g_object_set_data(G_OBJECT(dialog), "combo-box-priority-key",combo_box_priority);  
     g_object_set_data(G_OBJECT(dialog), "text-view-description-key",text_view_description);	
	 g_object_set_data(G_OBJECT(dialog), "spin-start-hour-key",spin_button_start_hour);  
     g_object_set_data(G_OBJECT(dialog), "spin-start-minutes-key",spin_button_start_minutes); 
     g_object_set_data(G_OBJECT(dialog), "spin-end-hour-key",spin_button_end_hour);	
	 g_object_set_data(G_OBJECT(dialog), "spin-end-minutes-key",spin_button_end_minutes);  
     g_object_set_data(G_OBJECT(dialog), "check-button-allday-key",check_button_allday);
     g_object_set_data(G_OBJECT(dialog), "check-button-isyearly-key",check_button_isyearly);
    // g_object_set_data(G_OBJECT(dialog), "check-button-delete-key",check_button_delete);
     
     g_object_set_data(G_OBJECT(dialog), "dialog-year-key",GINT_TO_POINTER(year)); 
     g_object_set_data(G_OBJECT(dialog), "dialog-month-key",GINT_TO_POINTER(month));  
     g_object_set_data(G_OBJECT(dialog), "dialog-day-key",GINT_TO_POINTER(day));  
 
 
//---------------------------------------------------------------
// Font size
//----------------------------------------------------------------

GtkCssProvider *cssProvider;
 
GtkStyleContext *context_dialog;

GtkStyleContext *context_label_date;

GtkStyleContext *context_label_title;
GtkStyleContext *context_entry_title;
GtkStyleContext *context_box_title;

GtkStyleContext *context_label_priority;
GtkStyleContext *context_combo_box_priority;
GtkStyleContext *context_box_priority;

GtkStyleContext *context_label_description;
GtkStyleContext *context_text_view_description;
GtkStyleContext *context_scrolled_window_description;
GtkStyleContext *context_box_description;
  
GtkStyleContext *context_check_button_allday;
GtkStyleContext *context_check_button_isyearly;
  
GtkStyleContext *context_label_start_time; 
GtkStyleContext *context_label_start_colon; 
GtkStyleContext *context_spin_button_start_hour;  
GtkStyleContext *context_spin_button_start_minutes; 
GtkStyleContext *context_box_start_time; 

GtkStyleContext *context_label_end_time; 
GtkStyleContext *context_label_end_colon;  
GtkStyleContext *context_spin_button_end_hour;  
GtkStyleContext *context_spin_button_end_minutes; 
GtkStyleContext *context_box_end_time; 
	
 
    
//new css provider 
cssProvider = gtk_css_provider_new();

gtk_widget_set_name (GTK_WIDGET(dialog), "cssView"); 

gtk_widget_set_name (GTK_WIDGET(label_date), "cssView");  

gtk_widget_set_name (GTK_WIDGET(label_title), "cssView"); 
gtk_widget_set_name (GTK_WIDGET(entry_title), "cssView"); 
gtk_widget_set_name (GTK_WIDGET(box_title), "cssView");

gtk_widget_set_name (GTK_WIDGET(label_priority), "cssView"); 
gtk_widget_set_name (GTK_WIDGET(combo_box_priority), "cssView"); 
gtk_widget_set_name (GTK_WIDGET(box_priority), "cssView");

gtk_widget_set_name (GTK_WIDGET(label_description), "cssView"); 
gtk_widget_set_name (GTK_WIDGET(text_view_description), "cssView");  
gtk_widget_set_name (GTK_WIDGET(scrolled_window_description), "cssView"); 
gtk_widget_set_name (GTK_WIDGET(box_description), "cssView");

//check buttons
gtk_widget_set_name (GTK_WIDGET(check_button_allday), "cssView");
gtk_widget_set_name (GTK_WIDGET(check_button_isyearly), "cssView"); 
//spin buttons
gtk_widget_set_name (GTK_WIDGET(label_start_time), "cssView");  
gtk_widget_set_name (GTK_WIDGET(label_start_colon), "cssView"); 
gtk_widget_set_name (GTK_WIDGET(spin_button_start_hour), "cssView"); 
gtk_widget_set_name (GTK_WIDGET(spin_button_start_minutes), "cssView"); 
gtk_widget_set_name (GTK_WIDGET(box_start_time), "cssView"); 

gtk_widget_set_name (GTK_WIDGET(label_end_time), "cssView");  
gtk_widget_set_name (GTK_WIDGET(label_end_colon), "cssView"); 
gtk_widget_set_name (GTK_WIDGET(spin_button_end_hour), "cssView"); 
gtk_widget_set_name (GTK_WIDGET(spin_button_end_minutes), "cssView"); 
gtk_widget_set_name (GTK_WIDGET(box_end_time), "cssView"); 

gchar *size_str = g_strdup_printf("%i", m_font_size); 
size_str =g_strconcat(size_str,"px;", NULL); 
const gchar* font_family = m_font_family; 
font_family =g_strconcat(font_family,";", NULL); 

gchar* css_str = g_strdup_printf ("#cssView {font-family: %s font-size: %s }", font_family, size_str);
gtk_css_provider_load_from_data(cssProvider, css_str,-1, NULL); 
 
  
// get GtkStyleContext from widget
context_dialog = gtk_widget_get_style_context(GTK_WIDGET(dialog));

context_label_date = gtk_widget_get_style_context(GTK_WIDGET(label_date)); 
   
context_label_title = gtk_widget_get_style_context(GTK_WIDGET(label_title)); 
context_entry_title= gtk_widget_get_style_context(GTK_WIDGET(entry_title)); 
context_box_title= gtk_widget_get_style_context(GTK_WIDGET(box_title));

context_label_priority = gtk_widget_get_style_context(GTK_WIDGET(label_priority)); 
context_combo_box_priority= gtk_widget_get_style_context(GTK_WIDGET(combo_box_priority)); 
context_box_priority= gtk_widget_get_style_context(GTK_WIDGET(box_priority));

context_label_description= gtk_widget_get_style_context(GTK_WIDGET(label_description));  
context_text_view_description = gtk_widget_get_style_context(GTK_WIDGET(text_view_description));
context_scrolled_window_description= gtk_widget_get_style_context(GTK_WIDGET(scrolled_window_description)); 
context_box_description = gtk_widget_get_style_context(GTK_WIDGET(box_description));

context_check_button_allday = gtk_widget_get_style_context(GTK_WIDGET(check_button_allday));
context_check_button_isyearly= gtk_widget_get_style_context(GTK_WIDGET(check_button_isyearly));

//spin buttons
context_label_start_time= gtk_widget_get_style_context(GTK_WIDGET(label_start_time));  
context_label_start_colon = gtk_widget_get_style_context(GTK_WIDGET(label_start_colon));
context_spin_button_start_hour= gtk_widget_get_style_context(GTK_WIDGET(spin_button_start_hour)); 
context_spin_button_start_minutes = gtk_widget_get_style_context(GTK_WIDGET(spin_button_start_minutes));
context_box_start_time = gtk_widget_get_style_context(GTK_WIDGET(box_start_time));

context_label_end_time= gtk_widget_get_style_context(GTK_WIDGET(label_end_time));  
context_label_end_colon = gtk_widget_get_style_context(GTK_WIDGET(label_end_colon));
context_spin_button_end_hour= gtk_widget_get_style_context(GTK_WIDGET(spin_button_end_hour)); 
context_spin_button_end_minutes = gtk_widget_get_style_context(GTK_WIDGET(spin_button_end_minutes));
context_box_end_time = gtk_widget_get_style_context(GTK_WIDGET(box_end_time));


//finally load style provider 

gtk_style_context_add_provider(context_dialog,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
//date
gtk_style_context_add_provider(context_label_date,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
 
                             
//title
gtk_style_context_add_provider(context_label_title,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
                             
gtk_style_context_add_provider(context_entry_title,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
                             
gtk_style_context_add_provider(context_box_title,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
//priority                             
gtk_style_context_add_provider(context_label_priority,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
                             
gtk_style_context_add_provider(context_combo_box_priority,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
                             
gtk_style_context_add_provider(context_box_priority,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
//description
gtk_style_context_add_provider(context_label_description,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
                             
gtk_style_context_add_provider(context_text_view_description,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
                              
gtk_style_context_add_provider(context_scrolled_window_description,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);   

gtk_style_context_add_provider(context_box_description,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

//checkbuttons
gtk_style_context_add_provider(context_check_button_allday,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

gtk_style_context_add_provider(context_check_button_isyearly,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

//spinbuttons start
gtk_style_context_add_provider(context_label_start_time,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
                             
gtk_style_context_add_provider(context_label_start_colon,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
                             
gtk_style_context_add_provider(context_spin_button_start_hour,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION); 
                             
gtk_style_context_add_provider(context_spin_button_start_minutes,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION); 
                                                                                                                  
gtk_style_context_add_provider(context_box_start_time,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);                             

//spinbuttons end

gtk_style_context_add_provider(context_label_end_time,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
                             
gtk_style_context_add_provider(context_label_end_colon,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
                             
gtk_style_context_add_provider(context_spin_button_end_hour,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION); 
                             
gtk_style_context_add_provider(context_spin_button_end_minutes,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION); 
                                                                                                                  
gtk_style_context_add_provider(context_box_end_time,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);                             
		
	//--------------------------------------------------------------
	// Dialog PACKING
	//--------------------------------------------------------------  
	container = gtk_dialog_get_content_area (GTK_DIALOG(dialog));	
	gtk_container_add(GTK_CONTAINER(container),label_date);
	gtk_container_add(GTK_CONTAINER(container),box_title);
	gtk_container_add(GTK_CONTAINER(container),box_priority);			
	gtk_container_add (GTK_CONTAINER (container), box_description);	
	gtk_container_add(GTK_CONTAINER(container),check_button_allday);
	gtk_container_add(GTK_CONTAINER(container),check_button_isyearly);
	gtk_container_add(GTK_CONTAINER(container),box_start_time);		
	gtk_container_add(GTK_CONTAINER(container),box_end_time);
	gtk_widget_show_all(dialog); 
	
	//g_free(event);
 
   
}

//------------------------------------------------------------------
// Talk Calendar Other Options
//------------------------------------------------------------------
static void talkcalendar_other_options_dialog(GtkWidget *widget) {
	
  GtkWidget *window = (GtkWidget *) widget;
   
   
  if( !GTK_IS_WINDOW(window)) {	  	 
	  return;
  }
  config_read();
  
  GtkWidget *dialog;    
  GtkWidget *container;	
  GtkWidget *check_button_holidays; //show public holidays on calendar
  gint response;
  dialog= gtk_dialog_new(); 
  gtk_window_set_title (GTK_WINDOW (dialog), "Other Options"); 
  g_signal_connect_swapped(dialog,"close",G_CALLBACK(options_close_callbk),dialog);//escape close
  gtk_window_set_transient_for(GTK_WINDOW(dialog),GTK_WINDOW(window));  
  
  gtk_widget_set_size_request(dialog, 200,100);
  gtk_window_set_modal(GTK_WINDOW(dialog),TRUE);  
  gtk_dialog_add_button(GTK_DIALOG(dialog),"Ok",1);  
  gtk_dialog_add_button(GTK_DIALOG(dialog),"Cancel",2);
  
  //check_button_holidays = gtk_check_button_new_with_label ("Show Public Holidays");
  check_button_holidays = gtk_check_button_new_with_label ("Show Public Holidays");
  //gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (check_button_holidays), m_holidays);
  gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (check_button_holidays), m_holidays);
  
  //---------------------------------------------------------------
  // Font size
  //----------------------------------------------------------------
  
  GtkCssProvider *cssProvider;  
  GtkStyleContext *context_dialog;
  GtkStyleContext *context_check_button_holidays; //show public holidays on calendar
  //new css provider 
  cssProvider = gtk_css_provider_new(); 
  gtk_widget_set_name (GTK_WIDGET(dialog), "cssView");
  gtk_widget_set_name (GTK_WIDGET(check_button_holidays), "cssView");
  
  gchar *size_str = g_strdup_printf("%i", m_font_size); 
  size_str =g_strconcat(size_str,"px;", NULL);   
  const gchar* font_family = m_font_family; 
  font_family =g_strconcat(font_family,";", NULL); 
  
  gchar* css_str = g_strdup_printf ("#cssView {font-family: %s font-size: %s }", font_family, size_str);
  gtk_css_provider_load_from_data(cssProvider, css_str,-1, NULL); 
    
  // get GtkStyleContext from widget 
  context_dialog = gtk_widget_get_style_context(GTK_WIDGET(dialog));
  context_check_button_holidays= gtk_widget_get_style_context(GTK_WIDGET(check_button_holidays));
  
  // finally load style provider 
  gtk_style_context_add_provider(context_dialog,    
  GTK_STYLE_PROVIDER(cssProvider), 
  GTK_STYLE_PROVIDER_PRIORITY_APPLICATION); 
  gtk_style_context_add_provider(context_check_button_holidays,    
  GTK_STYLE_PROVIDER(cssProvider), 
  GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
  //pack
  container = gtk_dialog_get_content_area (GTK_DIALOG(dialog));	
  //gtk_container_add(GTK_CONTAINER(container),check_button_holidays);
  gtk_container_add(GTK_CONTAINER(container),check_button_holidays);
  
  gtk_widget_show_all(GTK_WIDGET(dialog));      
  response = gtk_dialog_run(GTK_DIALOG(dialog));  
  
  
  switch (response)
  {
  case 1:
  
  //m_holidays =gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check_button_holidays));
  m_holidays =gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check_button_holidays));
  
 //calandar month changed
  GtkWidget *calendar =g_object_get_data(G_OBJECT(window), "calendar-key"); 
  callbk_calendar_month_changed(GTK_CALENDAR(calendar), NULL);
  
   
  config_write();
  
  gtk_widget_destroy(GTK_WIDGET(dialog));	 
  break;	 
  
  case 2: //cancel pressed  
  gtk_widget_destroy(GTK_WIDGET(dialog));	 
  break;	  
  default:
  gtk_widget_destroy(GTK_WIDGET(dialog));
  break;
  } 	
    
}

//------------------------------------------------------------------
// Talk Calendar Talk Options
//------------------------------------------------------------------

static void talkcalendar_talk_options_dialog(GtkWidget *widget) {
	
  GtkWidget *window = (GtkWidget *) widget;
   
   
  if( !GTK_IS_WINDOW(window)) {	  	 
	  return;
  }
  config_read();
  
  GtkWidget *dialog;    
  GtkWidget *container;	
  
  GtkWidget *check_button_talk; //enable talk 
  GtkWidget *check_button_talk_startup; //enable talk startup   
  GtkWidget *check_button_talk_title; //enable title talk
  GtkWidget *check_button_talk_time; //enable title talk  
  GtkWidget *check_button_talk_priority; //enable priority talk 
  GtkWidget *check_button_talk_description; //enable talk  description 
    
  gint response;
  
  //Create dialog
    dialog= gtk_dialog_new(); 
    gtk_window_set_title (GTK_WINDOW (dialog), "Talk Options"); 
    g_signal_connect_swapped(dialog,"close",G_CALLBACK(options_close_callbk),dialog);//escape close
    gtk_window_set_transient_for(GTK_WINDOW(dialog),GTK_WINDOW(window));  
   
    gtk_widget_set_size_request(dialog, 300,200);
    gtk_window_set_modal(GTK_WINDOW(dialog),TRUE);  
    gtk_dialog_add_button(GTK_DIALOG(dialog),"Ok",1);  
    gtk_dialog_add_button(GTK_DIALOG(dialog),"Cancel",2);

		
	GtkWidget *box_talk_options1;
	GtkWidget *box_talk_options2;
	
	check_button_talk_startup = gtk_check_button_new_with_label ("Talk At Startup");
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (check_button_talk_startup), m_talk_at_startup); 
	
	check_button_talk_title = gtk_check_button_new_with_label ("Talk Title");
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (check_button_talk_title), m_talk_title); 
	
	check_button_talk_time = gtk_check_button_new_with_label ("Talk Time");
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (check_button_talk_time), m_talk_time); 
	
	check_button_talk_description = gtk_check_button_new_with_label ("Talk Description");
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (check_button_talk_description), m_talk_description); 
			
	check_button_talk_priority = gtk_check_button_new_with_label ("Talk Priority");
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (check_button_talk_priority), m_talk_priority); 
	
	
	
	
	box_talk_options1 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
	gtk_box_pack_start(GTK_BOX(box_talk_options1),check_button_talk_title, FALSE, FALSE, 10);
	gtk_box_pack_start(GTK_BOX(box_talk_options1),check_button_talk_time, FALSE, FALSE, 10);
	
	box_talk_options2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
	gtk_box_pack_start(GTK_BOX(box_talk_options2),check_button_talk_description, FALSE, FALSE, 10);
	gtk_box_pack_start(GTK_BOX(box_talk_options2),check_button_talk_priority,TRUE, TRUE, 0);	
	
	check_button_talk = gtk_check_button_new_with_label ("Enable Talking");	
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (check_button_talk), m_talk); 
	
	if(m_talk) {
		gtk_widget_set_sensitive(check_button_talk_startup,TRUE);
	    gtk_widget_set_sensitive(check_button_talk_title,TRUE);
	    gtk_widget_set_sensitive(check_button_talk_time,TRUE);	    
	    gtk_widget_set_sensitive(check_button_talk_priority,TRUE);
	    gtk_widget_set_sensitive(check_button_talk_description,TRUE);
	    
	}
	else {
		gtk_widget_set_sensitive(check_button_talk_startup,FALSE);
	    gtk_widget_set_sensitive(check_button_talk_title,FALSE);
	    gtk_widget_set_sensitive(check_button_talk_time,FALSE);	    
	    gtk_widget_set_sensitive(check_button_talk_priority,FALSE);	
	    gtk_widget_set_sensitive(check_button_talk_description,FALSE);	    
	  
	}
	
	g_object_set_data(G_OBJECT(check_button_talk), "cb_talk_startup_key",check_button_talk_startup);
	g_object_set_data(G_OBJECT(check_button_talk), "cb_talk_title_key",check_button_talk_title);
	g_object_set_data(G_OBJECT(check_button_talk), "cb_talk_time_key",check_button_talk_time);	
	g_object_set_data(G_OBJECT(check_button_talk), "cb_talk_priority_key",check_button_talk_priority);
	g_object_set_data(G_OBJECT(check_button_talk), "cb_talk_description_key",check_button_talk_description);
		
	//g_signal_connect (GTK_TOGGLE_BUTTON (check_button_talk), "toggled", G_CALLBACK (check_button_talk_toggled_callbk), NULL);
	g_signal_connect_swapped (GTK_TOGGLE_BUTTON (check_button_talk), "toggled", 
						G_CALLBACK (check_button_talk_toggled_callbk), check_button_talk);
	
	
//---------------------------------------------------------------
// Font size
//----------------------------------------------------------------

GtkCssProvider *cssProvider;

GtkStyleContext *context_dialog;

//check buttons
GtkStyleContext *context_check_button_talk; //enable talk 
GtkStyleContext *context_check_button_talk_startup; //enable talk startup 
GtkStyleContext *context_box_talk_options1;
GtkStyleContext *context_box_talk_options2; 
GtkStyleContext *context_check_button_talk_title; //enable title talk
GtkStyleContext *context_check_button_talk_time; //enable title talk  
GtkStyleContext *context_check_button_talk_priority; //enable priority talk 
GtkStyleContext *context_check_button_talk_description; //enable p description talk  
   
//new css provider 
cssProvider = gtk_css_provider_new(); 
gtk_widget_set_name (GTK_WIDGET(dialog), "cssView"); 

//check buttons
gtk_widget_set_name (GTK_WIDGET(check_button_talk), "cssView");
gtk_widget_set_name (GTK_WIDGET(check_button_talk_startup), "cssView"); 
gtk_widget_set_name (GTK_WIDGET(box_talk_options1), "cssView"); 
gtk_widget_set_name (GTK_WIDGET(box_talk_options2), "cssView");   
gtk_widget_set_name (GTK_WIDGET(check_button_talk_title), "cssView"); 
gtk_widget_set_name (GTK_WIDGET(check_button_talk_time), "cssView"); 
gtk_widget_set_name (GTK_WIDGET(check_button_talk_priority), "cssView"); 
gtk_widget_set_name (GTK_WIDGET(check_button_talk_description), "cssView"); 
 


gchar *size_str = g_strdup_printf("%i", m_font_size); 
size_str =g_strconcat(size_str,"px;", NULL); 

const gchar* font_family = m_font_family; 
font_family =g_strconcat(font_family,";", NULL); 

gchar* css_str = g_strdup_printf ("#cssView {font-family: %s font-size: %s }", font_family, size_str);
gtk_css_provider_load_from_data(cssProvider, css_str,-1, NULL); 
 
// get GtkStyleContext from widget 
context_dialog = gtk_widget_get_style_context(GTK_WIDGET(dialog));
 
context_check_button_talk= gtk_widget_get_style_context(GTK_WIDGET(check_button_talk));  
context_check_button_talk_startup = gtk_widget_get_style_context(GTK_WIDGET(check_button_talk_startup));

context_box_talk_options1= gtk_widget_get_style_context(GTK_WIDGET(box_talk_options1)); 
context_box_talk_options2= gtk_widget_get_style_context(GTK_WIDGET(box_talk_options2));
 
context_check_button_talk_title = gtk_widget_get_style_context(GTK_WIDGET(check_button_talk_title));
context_check_button_talk_time = gtk_widget_get_style_context(GTK_WIDGET(check_button_talk_time));
context_check_button_talk_priority= gtk_widget_get_style_context(GTK_WIDGET(check_button_talk_priority));
context_check_button_talk_description= gtk_widget_get_style_context(GTK_WIDGET(check_button_talk_description));

// finally load style provider 
gtk_style_context_add_provider(context_dialog,    
							GTK_STYLE_PROVIDER(cssProvider), 
							GTK_STYLE_PROVIDER_PRIORITY_APPLICATION); 
 
         
//checkboxes
gtk_style_context_add_provider(context_check_button_talk,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

gtk_style_context_add_provider(context_check_button_talk_startup,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
                             
gtk_style_context_add_provider(context_box_talk_options1,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
                             
gtk_style_context_add_provider(context_box_talk_options2,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);                                                           
                             
gtk_style_context_add_provider(context_check_button_talk_title,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);                            

gtk_style_context_add_provider(context_check_button_talk_time,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

gtk_style_context_add_provider(context_check_button_talk_description,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);                            
             
gtk_style_context_add_provider(context_check_button_talk_priority,    
                             GTK_STYLE_PROVIDER(cssProvider), 
                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
                             
                
	

		
//--------------------------------------------------------------
// Dialog PACKING
//--------------------------------------------------------------  
container = gtk_dialog_get_content_area (GTK_DIALOG(dialog));			

gtk_container_add(GTK_CONTAINER(container),check_button_talk);
gtk_container_add(GTK_CONTAINER(container),check_button_talk_startup);	
gtk_container_add(GTK_CONTAINER(container),box_talk_options1);
gtk_container_add(GTK_CONTAINER(container),box_talk_options2);	

		
gtk_widget_show_all(GTK_WIDGET(dialog));      
response = gtk_dialog_run(GTK_DIALOG(dialog));  
    
  
  switch (response)
  {
  case 1:
  
  m_talk =gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check_button_talk));
  m_talk_at_startup=gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check_button_talk_startup));
  m_talk_time =gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check_button_talk_time));
  m_talk_description=gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check_button_talk_description));
  m_talk_priority =gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check_button_talk_priority));
  
  config_write();
  
  gtk_widget_destroy(GTK_WIDGET(dialog));	 
  break;	 
  
  case 2: //cancel pressed  
  gtk_widget_destroy(GTK_WIDGET(dialog));	 
  break;	  
  default:
  gtk_widget_destroy(GTK_WIDGET(dialog));
  break;
} 	
}

//------------------------------------------------------------------
// Start up
//------------------------------------------------------------------
    
static void startup (GtkApplication *app)
{
	//removed menubar (menubar depreciated and gone in gtk4)	
}


static void activate (GtkApplication* app, gpointer user_data)
{

	GtkWidget *window;
	GtkWidget *calendar;
	
	GtkWidget *label_date;
	GtkWidget *label_time;
	//GtkWidget *label_alarm;
	
	GtkWidget *paned;	
	GtkWidget *scrolled_window;
	GtkWidget *box_pane1;
	GtkWidget *box_pane2;
	
	GtkWidget *treeview;	
	//GtkTreeSelection *selection;  
	
	GtkWidget *header;
	GtkWidget *button;	
	GtkWidget *menu_button;
	 
	//GIcon *icon;
	GtkWidget *icon;
	GtkStyleContext *context;
		
	GDateTime *date_time;	
	date_time = g_date_time_new_now_local();   // get local time     
	
	// Date time labels	
	gchar *dt_format_date;
	dt_format_date = g_date_time_format(date_time, "%a %e %b %Y");
	label_date=gtk_label_new("");	
	gtk_label_set_xalign(GTK_LABEL(label_date),0.5);
	gtk_label_set_text(GTK_LABEL(label_date), dt_format_date); 	
	g_free (dt_format_date);	
	
	gchar *dt_format_time;                         
	dt_format_time = g_date_time_format(date_time, "%H:%M:%S");  // 24hr time format
	label_time=gtk_label_new("");	
	gtk_label_set_xalign(GTK_LABEL(label_time),0.5);	 
	gtk_label_set_text(GTK_LABEL(label_time), dt_format_time);   // update label        
	g_free (dt_format_time);	
	
	
	// define keyboard accelerators
	const gchar *import_accels[2] = { "<Ctrl>O", NULL };
	const gchar *export_accels[2] = { "<Ctrl>S", NULL };
	const gchar *delete_accels[2] = { "<Ctrl>D", NULL };
	const gchar *speak_accels[2] = { "space", NULL };
	const gchar *home_accels[2] = { "Home", NULL };
	const gchar *about_accels[2] =  { "<Ctrl>A", NULL };
	const gchar *quit_accels[2] =   { "<Ctrl>Q", NULL };
		
	//Setup window
	gchar* title ="Talk Calendar";	
	window = gtk_application_window_new (app);
	gtk_window_set_title (GTK_WINDOW (window), title);
	gtk_window_set_default_size (GTK_WINDOW (window), 750, 500);
	gtk_window_set_icon_name (GTK_WINDOW (window), "x-office-calendar");
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);	
	gtk_container_set_border_width(GTK_CONTAINER(window), 3);
		
		
	//set up calendar
	calendar = gtk_calendar_new();		
	g_signal_connect(GTK_CALENDAR(calendar), "day-selected", G_CALLBACK(callbk_calendar_day_clicked), window); //calnedar clicked	
	g_signal_connect(GTK_CALENDAR(calendar), "day-selected-double-click", G_CALLBACK(callbk_calendar_day_double_click), window); //calendar double clicked
	g_signal_connect(GTK_CALENDAR(calendar), "month-changed", G_CALLBACK(callbk_calendar_month_changed), NULL);
	
	//get the day month and year from calendar
    guint day, month, year;
    gtk_calendar_get_date(GTK_CALENDAR (calendar), &year, &month, &day);
    
   
	gint n_regular_events = db_get_number_of_rows_year_month_day(year, month+1, day);    
	gint n_isyearly_month_events = db_get_number_of_isyearly_events_month(month+1);   
	gint n_isyearly_day_events=0;
	
	Event isyearly_array[n_isyearly_month_events];
		 
	db_get_isyearly_events_month(isyearly_array, month+1, n_isyearly_month_events);
	Event e1;	
	for(int i=0; i<n_isyearly_month_events; i++) {		
	e1=isyearly_array[i];
	if(e1.day == day && e1.year!=year){	
	n_isyearly_day_events=n_isyearly_day_events+1;
	}
	}
	
	gint total_number_events = n_regular_events+n_isyearly_day_events;
	
	//Now create total event array i.e. contains regular plus isyearly events
	Event* event_array_total = NULL;	
	event_array_total = malloc(total_number_events * sizeof(Event));
	
	Event event_array[n_regular_events]; //regular event array
	db_get_all_events_year_month_day(event_array, year, month+1, day, n_regular_events);
	
	int count=0;  //event array total count
	
	for(int i=0; i<n_regular_events; i++) {	//add regular events to total		
	event_array_total[count] = event_array[i];
	count =count+1;
	if(count>total_number_events)
	{
	g_print("fatal error: malloc over run\n");
	break;
	}
	}	
	//now add yearly events
	for(int i=0; i<n_isyearly_month_events; i++) {		
	Event e2=isyearly_array[i];
	if(e2.day == day && e2.year!=year){			
    event_array_total[count] = isyearly_array[i];
	count =count+1;
	if(count>total_number_events)
	{
	g_print("fatal error: malloc over run\n");
	break;
	}
	}
	}	 
		
	treeview = create_view_and_model(event_array_total,total_number_events);	
	g_signal_connect(GTK_TREE_VIEW(treeview), "row-activated", G_CALLBACK(callbk_treeview_row_activated), window); 
	
	//Set up scrolled window
	scrolled_window = gtk_scrolled_window_new (NULL, NULL);
	gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolled_window), 	GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC); 	
	gtk_container_add (GTK_CONTAINER (scrolled_window), treeview); //put treeview inside scrolled window
	gtk_container_set_border_width (GTK_CONTAINER (scrolled_window), 5);
	
	
	//setup actions (actions needed for menu)
	GSimpleAction *import_action;	
	import_action=g_simple_action_new("import",NULL); //app.import
	g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(import_action)); //make visible	
	g_signal_connect(import_action, "activate",  G_CALLBACK(callbk_import), calendar);
	
	GSimpleAction *export_action;	
	export_action=g_simple_action_new("export",NULL); //app.export
	g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(export_action)); //make visible
	g_signal_connect(export_action, "activate",  G_CALLBACK(callbk_export), window);
	
	GSimpleAction *delete_events_action;	
	delete_events_action=g_simple_action_new("delete",NULL); //action = app.delete
	g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(delete_events_action)); //make visible	
	g_signal_connect(delete_events_action, "activate",  G_CALLBACK(callbk_delete), window);
	
	
	GSimpleAction *speak_action;	
	speak_action=g_simple_action_new("speak",NULL); //app.speak
	g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(speak_action)); //make visible	
	g_signal_connect(speak_action, "activate",  G_CALLBACK(callbk_speak), window);
	
	GSimpleAction *preferences_action;	
	preferences_action=g_simple_action_new("preferences",NULL); //app.spreferences
	g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(preferences_action)); //make visible	
	g_signal_connect(preferences_action, "activate",  G_CALLBACK(callbk_preferences), window);
	
	GSimpleAction *other_action;	
	other_action=g_simple_action_new("other",NULL); //app.other
	g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(other_action)); //make visible	
	g_signal_connect(other_action, "activate",  G_CALLBACK(callbk_other_options), window);
	
	GSimpleAction *font_action;	
	font_action=g_simple_action_new("font",NULL); //app.font
	g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(font_action)); //make visible	
	g_signal_connect(font_action, "activate",  G_CALLBACK(callbk_font), window);
	
	GSimpleAction *about_action;	
	about_action=g_simple_action_new("about",NULL); //app.about
	g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(about_action)); //make visible	
	g_signal_connect(about_action, "activate",  G_CALLBACK(callbk_about), window);
	
	GSimpleAction *speak_about_action;	
	speak_about_action=g_simple_action_new("version",NULL); //app.version
	g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(speak_about_action)); //make visible	
	g_signal_connect(speak_about_action, "activate",  G_CALLBACK(callbk_speak_about), window);
	
	GSimpleAction *home_action;	
	home_action=g_simple_action_new("home",NULL); //app.home
	g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(home_action)); //make visible	
	g_signal_connect(home_action, "activate",  G_CALLBACK(callbk_home), window);
	
	
	GSimpleAction *shortcuts_action;	
	shortcuts_action=g_simple_action_new("shortcuts",NULL); //app.shortcuts
	g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(shortcuts_action)); //make visible	
	g_signal_connect(shortcuts_action, "activate",  G_CALLBACK(callbk_shortcuts), window);
	
	GSimpleAction *quit_action;	
	quit_action=g_simple_action_new("quit",NULL); //app.quit
	g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(quit_action)); //make visible	
	g_signal_connect(quit_action, "activate",  G_CALLBACK(callbk_quit), app);
	
	
	GMenu *appmenu, *section; 
	//GMenuModel *menu_model;
	
	appmenu = g_menu_new ();  
	
	section = g_menu_new ();  
	g_menu_append (section, "Import", "app.import");
	g_menu_append (section, "Export", "app.export");	
	g_menu_append_section (appmenu, NULL, G_MENU_MODEL (section));
	g_object_unref (section);
	
	section = g_menu_new ();
	g_menu_append (section, "Delete", "app.delete");	
	g_menu_append_section (appmenu, NULL, G_MENU_MODEL (section));
	g_object_unref (section);
	
	section = g_menu_new ();
	g_menu_append (section, "Talk", "app.preferences");
	g_menu_append (section, "Font", "app.font"); 
	g_menu_append (section, "Other", "app.other"); 		
	g_menu_append_submenu (appmenu, "_Preferences", G_MENU_MODEL (section));
	g_object_unref (section);
	
	section = g_menu_new ();
	g_menu_append (section, "Shortcuts", "app.shortcuts"); //show shortcuts
	g_menu_append (section, "About", "app.about");
	g_menu_append (section, "Speak Version", "app.version");  //speak version
	g_menu_append_submenu (appmenu, "_Help", G_MENU_MODEL (section));
	g_object_unref (section);
	
	section = g_menu_new ();
	g_menu_append (section, "Quit", "app.quit");
	g_menu_append_section (appmenu, NULL, G_MENU_MODEL(section));
	g_object_unref (section);
	
	gtk_application_set_app_menu (GTK_APPLICATION (app), G_MENU_MODEL (appmenu));
	
	
	header = gtk_header_bar_new ();
	gtk_header_bar_set_title (GTK_HEADER_BAR (header), "Talk Calendar");
	gtk_window_set_titlebar (GTK_WINDOW(window), header);
	gtk_header_bar_set_show_close_button (GTK_HEADER_BAR (header), TRUE);
	
	//hamburger
	menu_button = gtk_menu_button_new();
	gtk_widget_set_tooltip_text(menu_button, "Menu");
	icon = gtk_image_new_from_icon_name ("open-menu-symbolic", GTK_ICON_SIZE_BUTTON);
	gtk_button_set_image (GTK_BUTTON (menu_button), icon);		
	gtk_menu_button_set_menu_model (GTK_MENU_BUTTON (menu_button), G_MENU_MODEL(appmenu));
	gtk_widget_show (menu_button);
	gtk_header_bar_pack_end(GTK_HEADER_BAR (header), menu_button);
	
	//-----------------------------------------------------------------
	//New event
	button = gtk_button_new_from_icon_name ("appointment-new-symbolic", GTK_ICON_SIZE_BUTTON); 
	gtk_button_set_relief (GTK_BUTTON(button), GTK_RELIEF_NONE); //no border
	context = gtk_widget_get_style_context (button);
	gtk_style_context_add_class (context, "circular");
	gtk_style_context_add_class (context, "flat");
	gtk_widget_set_valign (button, GTK_ALIGN_CENTER);  
	gtk_header_bar_pack_start(GTK_HEADER_BAR (header), button);
	gtk_widget_set_tooltip_text(button, "New Appointment");
	g_signal_connect (button, "clicked", G_CALLBACK (callbk_new_event), window);
	
	//separator = gtk_separator_new(GTK_ORIENTATION_VERTICAL);
	//gtk_header_bar_pack_start(GTK_HEADER_BAR(header), separator);
	//Alarm
	button = gtk_button_new_from_icon_name ("appointment-soon-symbolic", GTK_ICON_SIZE_BUTTON);
	gtk_button_set_relief (GTK_BUTTON(button), GTK_RELIEF_NONE); //no border
	context = gtk_widget_get_style_context (button);
	gtk_style_context_add_class (context, "circular");
	gtk_style_context_add_class (context, "flat");
	gtk_widget_set_valign (button, GTK_ALIGN_CENTER);
	gtk_widget_set_tooltip_text(button, "Set Alarm");
	g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(callbk_alarm), window);
	gtk_header_bar_pack_start(GTK_HEADER_BAR (header), button);
	
	
	//Revealer test
	GtkWidget *revealer = gtk_revealer_new ();
	gtk_container_add (GTK_CONTAINER (revealer),
	gtk_image_new_from_icon_name ("software-update-urgent-symbolic",
	GTK_ICON_SIZE_BUTTON));
	gtk_revealer_set_transition_duration (GTK_REVEALER (revealer), 500);
	gtk_revealer_set_transition_type (GTK_REVEALER (revealer),
	GTK_REVEALER_TRANSITION_TYPE_CROSSFADE);
	gtk_header_bar_pack_start (GTK_HEADER_BAR (header), revealer);
	
	
	// Set up gobject key value pairs
	g_object_set_data(G_OBJECT(window), "treeview-key",treeview); 
	g_object_set_data(G_OBJECT(window), "calendar-key",calendar);
	g_object_set_data(G_OBJECT(window), "label-date-key",label_date);
	g_object_set_data(G_OBJECT(window), "label-time-key",label_time);
	g_object_set_data(G_OBJECT(window), "revealer-key",revealer);
	g_object_set_data(G_OBJECT(window), "app-key",app);
	//GtkWidget *header =g_object_get_data(G_OBJECT(window), "header-key"); 
	
	//g_object_set_data(G_OBJECT(calendar), "calendar-treeview-key",treeview);	
	//g_object_set_data(G_OBJECT(calendar), "calendar-label-date-key",label_date);   
		
	
	box_pane1=gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
	//gtk_box_pack_start(GTK_BOX(box_pane1),popover,FALSE, FALSE, 5);	
	gtk_box_pack_start(GTK_BOX(box_pane1),label_date,FALSE, FALSE, 5);	
	gtk_box_pack_start(GTK_BOX(box_pane1),calendar,TRUE, TRUE, 2);
	
	
	box_pane2=gtk_box_new(GTK_ORIENTATION_VERTICAL,0);   
	gtk_box_pack_start(GTK_BOX(box_pane2),scrolled_window,TRUE, TRUE, 5);
	gtk_box_pack_start(GTK_BOX(box_pane2),label_time,FALSE, FALSE, 5);	
	
	paned = gtk_paned_new (GTK_ORIENTATION_VERTICAL);	
	gtk_paned_add1 (GTK_PANED (paned), box_pane1);
	gtk_paned_add2 (GTK_PANED (paned), box_pane2);
	
	gtk_paned_set_position(GTK_PANED (paned), 300); //window 600x450
	
	gtk_container_add (GTK_CONTAINER (window), paned);	
	callbk_calendar_month_changed(GTK_CALENDAR(calendar),NULL);
	
	//call calendar day clicked directly at startup
	//callbk_calendar_day_clicked(GTK_CALENDAR(calendar), GTK_WINDOW(window));
	
	change_window_font_size(GTK_WINDOW(window));
	
	
	PangoAttrList *attrs;
	attrs = pango_attr_list_new ();
	pango_attr_list_insert (attrs, pango_attr_weight_new (PANGO_WEIGHT_BOLD));
	gtk_label_set_attributes (GTK_LABEL (label_date), attrs);
	pango_attr_list_unref (attrs);
	
	if(m_talk && m_talk_at_startup) speak_events_at_date(GTK_CALENDAR(calendar));
	
		
	// connect keyboard accelerators
	gtk_application_set_accels_for_action(GTK_APPLICATION(app),
	"app.import", import_accels);
	gtk_application_set_accels_for_action(GTK_APPLICATION(app),
	"app.export", export_accels);
	gtk_application_set_accels_for_action(GTK_APPLICATION(app),
	"app.delete", delete_accels);
	gtk_application_set_accels_for_action(GTK_APPLICATION(app),
	"app.speak", speak_accels);                                     
	gtk_application_set_accels_for_action(GTK_APPLICATION(app),
	"app.home", home_accels); 
	gtk_application_set_accels_for_action(GTK_APPLICATION(app),
	"app.about", about_accels);
	gtk_application_set_accels_for_action(GTK_APPLICATION(app),
	"app.quit", quit_accels);
	
	g_date_time_unref(date_time);
	gtk_widget_show_all (window);
	
	//Timer
	g_timeout_add_seconds(1, callbk_timer_update, window);
	//notifications
	//notify_uninit();

}

int main (int argc, char **argv)
{
  //setup database
  db_create_events_table();  
  //setup preferences
  config_initialize();
   
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.talkcalendar", G_APPLICATION_FLAGS_NONE);
  
  g_signal_connect_swapped(app, "startup", G_CALLBACK (startup),app);
  g_signal_connect_swapped(app, "activate", G_CALLBACK (activate),app);  
  
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref(app);
  
  return status;
}
