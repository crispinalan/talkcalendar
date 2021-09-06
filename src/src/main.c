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
#include "wavplay.h"
#include "wavcat.h"

// Definitions
#define CONFIG_DIRNAME "talkcalendar-gtk"
#define CONFIG_FILENAME "talkcalendar-gtk"

//Static variables (configuration variables)
static char * m_config_file = NULL;

static GMutex lock;
gint debug=0;
static int m_talk =0;
static int m_talk_title =0;
static int m_talk_priority =0;
static int m_talk_at_startup=1;
static int m_holidays=0; //show holidays

//Prototypes

static void reload_events(GtkWidget *widget, int year, int month, int day);
static void talkcalendar_new_event(GtkWidget *widget, guint year, guint month, guint day);
static void talkcalendar_update_event(GtkWidget *widget, gpointer data);
static void calendar_day_selected_callbk(GtkCalendar *calendar, gpointer user_data);


static void add_to_list(GtkWidget *list, const gint id, const gchar* title);
void remove_item(GtkWidget *list, gpointer selection);
gchar* num_chars_only(const char* cstr);
GDate* calculate_easter(gint year);
static void mark_holidays_on_calendar(GtkCalendar *calendar, gint month, gint year);


static void config_load_default()
{		
	if(!m_talk) m_talk=1;
	if(!m_talk_at_startup) m_talk_at_startup=1;
	if(!m_talk_title) m_talk_title =1;
	if(!m_talk_priority) m_talk_priority =0;   
	if(!m_holidays) m_holidays=0;
	
}

static void config_read()
{
	// Clean up previously loaded configuration values	
	m_talk = 1;
	m_talk_title =1;
	m_talk_at_startup=1;
	m_talk_priority =0;  
	m_holidays=0;
	
	// Load keys from keyfile
	GKeyFile * kf = g_key_file_new();
	g_key_file_load_from_file(kf, m_config_file, G_KEY_FILE_NONE, NULL);
	m_talk = g_key_file_get_integer(kf, "calendar_settings", "talk", NULL);
	m_talk_at_startup=g_key_file_get_integer(kf, "calendar_settings", "talk_startup", NULL);
	m_talk_title = g_key_file_get_integer(kf, "calendar_settings", "talk_title", NULL);
	m_talk_priority = g_key_file_get_integer(kf, "calendar_settings", "talk_priority", NULL);	
	m_holidays = g_key_file_get_integer(kf, "calendar_settings", "holidays", NULL);	
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
	g_key_file_set_integer(kf, "calendar_settings", "talk_priority", m_talk_priority);
	g_key_file_set_integer(kf, "calendar_settings", "holidays", m_holidays);
	
	
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
static void import_callbk(GSimpleAction * action,
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

gchar* getPublicHoliday(GDate *date) {

	gchar *hol_str="";

	gint day = g_date_get_day(date);
	gint month =g_date_get_month(date);
	gint year=g_date_get_year(date);
	
	if ((day==25) && (month==12)) {
		hol_str = "Christmas";
	}
	if ((day==26) && (month==12)) {
		hol_str = "Boxing Day";
	}
	if ((day==1) && (month==1)) {
		hol_str = "New Year";
	}
	GDate *edate =calculate_easter(year);
    
    gint eday = g_date_get_day(edate);
    gint emonth =g_date_get_month(edate);
    
     if ((day==eday) && (month=emonth)){
		 hol_str="Easter";
	 }
   
     //if (date == easterDate)
        //holStr = " (Easter)";
    //if (date == easterDate.addDays(-2))
        //holStr = " (Good Friday)";
    //if (date == easterDate.addDays(1))
        //holStr = " (Easter Monday)"; 	
	return hol_str;
	
}



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

static void export_callbk(GSimpleAction * action,
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
// exit callback
//---------------------------------------------------------------------

static void exit_callbk(GSimpleAction * action,
							G_GNUC_UNUSED GVariant      *parameter,
							              gpointer       user_data)
{
		
	g_application_quit(G_APPLICATION(user_data));
	
}


static void options_close_callbk(GtkDialog *dialog,
					     G_GNUC_UNUSED gpointer   user_data)  
{
	if( !GTK_IS_DIALOG(dialog)) { 
	return;
	}	
	
} 

static void check_button_talk_toggled_callbk (GtkToggleButton *toggle_button, gpointer user_data)
{
 	
 	GtkWidget *check_button_talk_startup; //enable startup talk  
 	GtkWidget *check_button_talk_title; //enable  talk title 	
 	GtkWidget *check_button_talk_priority; //enable  talk priority 
 	
 		
 	check_button_talk_startup =g_object_get_data(G_OBJECT(user_data), "cb_talk_startup_key");	
	check_button_talk_title =g_object_get_data(G_OBJECT(user_data), "cb_talk_title_key"); 
	check_button_talk_priority= g_object_get_data(G_OBJECT(user_data), "cb_talk_priority_key");
	
		 	
 	if (gtk_toggle_button_get_active(toggle_button)){		
	//g_print("Toggled callbk: Talk TRUE\n");
		
	gtk_widget_set_sensitive(check_button_talk_startup,TRUE);
	gtk_widget_set_sensitive(check_button_talk_title,TRUE);	
	gtk_widget_set_sensitive(check_button_talk_priority,TRUE);
	
	
	}     
	else{	
	//g_print("Toggled callbk: Talk FALSE\n");
	
	gtk_widget_set_sensitive(check_button_talk_startup,FALSE);
	gtk_widget_set_sensitive(check_button_talk_title,FALSE);	
	gtk_widget_set_sensitive(check_button_talk_priority,FALSE);
		
	}
  
}

//--------------------------------------------------------------

static void talkcalendar_options_dialog(GtkWidget *widget) {
	
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
  GtkWidget *check_button_talk_priority; //enable priority talk  
  GtkWidget *check_button_holidays; //show public holidays on calendar
      
  gint response;
  
  //Create dialog
    dialog= gtk_dialog_new(); 
    gtk_window_set_title (GTK_WINDOW (dialog), "Options"); 
    g_signal_connect_swapped(dialog,"close",G_CALLBACK(options_close_callbk),dialog);//escape close
    gtk_window_set_transient_for(GTK_WINDOW(dialog),GTK_WINDOW(window));  
   
    gtk_widget_set_size_request(dialog, 200,100);
    gtk_window_set_modal(GTK_WINDOW(dialog),TRUE);  
    gtk_dialog_add_button(GTK_DIALOG(dialog),"Ok",1);  
    gtk_dialog_add_button(GTK_DIALOG(dialog),"Cancel",2);

	GtkWidget *box_title_priority;
	
	check_button_talk_startup = gtk_check_button_new_with_label ("Talk At Startup");
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (check_button_talk_startup), m_talk_at_startup); 
	
	check_button_talk_title = gtk_check_button_new_with_label ("Talk Title");
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (check_button_talk_title), m_talk_title); 
	
	check_button_talk_priority = gtk_check_button_new_with_label ("Talk Priority");
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (check_button_talk_priority), m_talk_priority); 
	
	check_button_holidays = gtk_check_button_new_with_label ("Show Public Holidays");
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (check_button_holidays), m_holidays);
	
	box_title_priority = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
	gtk_box_pack_start(GTK_BOX(box_title_priority),check_button_talk_title, FALSE, FALSE, 10);
	gtk_box_pack_start(GTK_BOX(box_title_priority),check_button_talk_priority,TRUE, TRUE, 0);	
	
	check_button_talk = gtk_check_button_new_with_label ("Enable Talking");	
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (check_button_talk), m_talk); 
	
	if(m_talk) {
		gtk_widget_set_sensitive(check_button_talk_startup,TRUE);
	    gtk_widget_set_sensitive(check_button_talk_title,TRUE);	    
	    gtk_widget_set_sensitive(check_button_talk_priority,TRUE);
	    
	}
	else {
		gtk_widget_set_sensitive(check_button_talk_startup,FALSE);
	    gtk_widget_set_sensitive(check_button_talk_title,FALSE);	    
	    gtk_widget_set_sensitive(check_button_talk_priority,FALSE);	    
	  
	}
	
	g_object_set_data(G_OBJECT(check_button_talk), "cb_talk_startup_key",check_button_talk_startup);
	g_object_set_data(G_OBJECT(check_button_talk), "cb_talk_title_key",check_button_talk_title);	
	g_object_set_data(G_OBJECT(check_button_talk), "cb_talk_priority_key",check_button_talk_priority);
		
	//g_signal_connect (GTK_TOGGLE_BUTTON (check_button_talk), "toggled", G_CALLBACK (check_button_talk_toggled_callbk), NULL);
	g_signal_connect_swapped (GTK_TOGGLE_BUTTON (check_button_talk), "toggled", 
						G_CALLBACK (check_button_talk_toggled_callbk), check_button_talk);
	
		
	//--------------------------------------------------------------
	// Dialog PACKING
	//--------------------------------------------------------------  
	container = gtk_dialog_get_content_area (GTK_DIALOG(dialog));			
	
	gtk_container_add(GTK_CONTAINER(container),check_button_talk);
	gtk_container_add(GTK_CONTAINER(container),check_button_talk_startup);	
	gtk_container_add(GTK_CONTAINER(container),box_title_priority);		
	gtk_container_add(GTK_CONTAINER(container),check_button_holidays);
			
    gtk_widget_show_all(GTK_WIDGET(dialog));      
    response = gtk_dialog_run(GTK_DIALOG(dialog));  
	 
   
  
  switch (response)
  {
  case 1:
  
  m_talk =gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check_button_talk));
  m_talk_at_startup=gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check_button_talk_startup));
  m_talk_title =gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check_button_talk_title));     
  m_talk_priority =gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check_button_talk_priority));
  
  m_holidays =gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check_button_holidays));
  
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

gchar* num_chars_only(const char* cstr)
{    
const char* c;
gchar* ret_val;
GString* s = g_string_new("");
	//c strings terminated by a null character '\0'
	for ( c = cstr; *c != '0'; c = g_utf8_next_char(c) ) 
	{
	    gunichar cp = g_utf8_get_char(c); 
		if ( cp == 0 ) break;		
		if (g_unichar_isdigit(cp)) // allow numbers	
		{ 	 
		g_string_append_unichar( s, cp);
		} 
	} 
ret_val = s->str;
g_string_free(s, FALSE);
return ret_val; 
}



static void callbk_gotoday(GSimpleAction *action, G_GNUC_UNUSED  GVariant  *parameter,	gpointer window)
{

GtkCalendar *calendar =g_object_get_data(G_OBJECT(window), "calendar-key");
GtkWidget *label_date =g_object_get_data(G_OBJECT(window), "label-date-key");

GDateTime *dt;  
gchar *dt_format;  
dt = g_date_time_new_now_local();

gint year = g_date_time_get_year(dt);
gint month =g_date_time_get_month(dt);    
gint day = g_date_time_get_day_of_month(dt); 
dt_format = g_date_time_format(dt, "%a %e %b %Y"); 
gtk_label_set_xalign(GTK_LABEL(label_date),0.5);
gtk_label_set_text(GTK_LABEL(label_date), dt_format); 

gtk_calendar_select_month (calendar, month-1, year);
gtk_calendar_select_day (calendar, day);
reload_events(window, year, month,day);

//mark_holidays_on_calendar(calendar);
//gtk_calendar_set_date(GTK_CALENDAR (calendar), &year, &month, &day);

g_date_time_unref (dt);

}




static gpointer thread_playwav(gpointer user_data)
{     
   
    gchar *file_name =user_data;
   	
   	char input[50];		
	strcpy(input, file_name);
	wavplay(input);
   
   
    g_mutex_unlock (&lock); //thread mutex unlock 
    return NULL;   
}


//--------------------------------------------------------------------
// audio test callback
//--------------------------------------------------------------------
static void audio_callbk(GSimpleAction *action,
							G_GNUC_UNUSED  GVariant      *parameter,
							  gpointer       user_data){
	
	
	GList *wavlist=NULL;
	gchar *cur_dir;
	cur_dir = g_get_current_dir ();
			
	g_print("Locate talk dictionary in directory: %s\n",cur_dir); 

	//Check if talk directory exists
	gchar* talk_directory = g_build_filename(cur_dir, "talk", NULL);
	
	if (g_file_test(talk_directory, G_FILE_TEST_IS_DIR)==FALSE){
		g_print("talk directory does not exists\n");
		return;
	}
	
	if (g_file_test(g_build_filename(cur_dir, "talk/l/linux.wav", NULL), G_FILE_TEST_IS_REGULAR)) {		
		wavlist = g_list_append(wavlist, g_build_filename (cur_dir, "talk/l/linux.wav", NULL));		
	}		 
	if (g_file_test(g_build_filename (cur_dir,"talk/t/talk.wav",NULL), G_FILE_TEST_IS_REGULAR)) {
		wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/t/talk.wav",NULL));
	}	
	if (g_file_test(g_build_filename (cur_dir, "talk/c/calendar.wav",NULL), G_FILE_TEST_IS_REGULAR)) {
		wavlist = g_list_append(wavlist, g_build_filename (cur_dir, "talk/c/calendar.wav",NULL));		
	}
	if (g_file_test(g_build_filename (cur_dir, "talk/p/project.wav",NULL), G_FILE_TEST_IS_REGULAR)) {
		wavlist = g_list_append(wavlist, g_build_filename (cur_dir, "talk/p/project.wav",NULL));
	}
	if (g_file_test(g_build_filename (cur_dir,"talk/v/version.wav",NULL), G_FILE_TEST_IS_REGULAR)) {
		wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/v/version.wav",NULL));
	}
	if (g_file_test(g_build_filename (cur_dir, "talk/cardinal/one.wav",NULL), G_FILE_TEST_IS_REGULAR)) {
		wavlist = g_list_append(wavlist, g_build_filename (cur_dir, "talk/cardinal/one.wav",NULL));
	}
	if (g_file_test(g_build_filename (cur_dir,"talk/p/point.wav",NULL), G_FILE_TEST_IS_REGULAR)) {
		wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/p/point.wav",NULL));
	}
	if (g_file_test(g_build_filename (cur_dir, "talk/cardinal/one.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
		wavlist = g_list_append(wavlist, g_build_filename (cur_dir, "talk/cardinal/one.wav", NULL));
	}
	
	if (g_file_test(g_build_filename (cur_dir, "talk/f/fullstop.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
		wavlist = g_list_append(wavlist, g_build_filename (cur_dir, "talk/f/fullstop.wav", NULL));	//wait
	}
	
			
	//use wavcat for concatenation (see audio limitations)
	gpointer pt_data;
	gchar* list_str;
			  
	char* merge_file ="/tmp/talkout.wav";
	int num_files = g_list_length(wavlist);
	char* file_names[g_list_length(wavlist)];
	
	for(int i=0;i<g_list_length(wavlist);i++) //iterate through GList wavlist 
	{	  
	pt_data=g_list_nth_data(wavlist,i);
	list_str=(char *)pt_data;	
	file_names[i] = list_str;	//populate char* array
	
	}
	
	merge_wav_files(merge_file, num_files, file_names);
	
	g_list_free(wavlist);
	g_free (cur_dir);	
	
	//play audio in a thread
	GThread *thread_audio; 	
	gchar* wav_file ="/tmp/talkout.wav"; 
	g_mutex_lock (&lock);
    thread_audio = g_thread_new(NULL, thread_playwav, wav_file);  
	g_thread_unref (thread_audio);
	
 	
		
}
//---------------------------------------------------------------------

static void speak_events_at_date(GtkCalendar *calendar) {
	
	guint day, month, year;
	//gint size=0;	
	gchar *dow_str=""; //day of week
	gchar *day_str="";
	gchar *month_str="";	
	GDate *date;
	GDateWeekday weekday; 
	GDateMonth month_enum;
	
	gchar *cur_dir;
	cur_dir = g_get_current_dir ();
		
    gtk_calendar_get_date(GTK_CALENDAR (calendar), &year, &month, &day);
        
   //Check if dictionary directory exists
	gchar* talk_directory = g_build_filename(cur_dir, "talk", NULL);
	
	if (g_file_test(talk_directory, G_FILE_TEST_IS_DIR)==FALSE){		
		return;
	}
	
   
   date =g_date_new_dmy (day,month+1,year); 
   weekday= g_date_get_weekday(date);
   
   GList *wavlist=NULL;	  	
   
   switch (weekday) {
		case G_DATE_MONDAY:		
		dow_str="talk/day/monday.wav";
		break;
		case G_DATE_TUESDAY:
		dow_str="talk/day/tuesday.wav";
		break;
		case G_DATE_WEDNESDAY:
		dow_str="talk/day/wednesday.wav";
		break;
		case G_DATE_THURSDAY:
		dow_str="talk/day/thursday.wav";
		break;
		case G_DATE_FRIDAY:
		dow_str="talk/day/friday.wav";
		break;
		case G_DATE_SATURDAY:
		dow_str="talk/day/saturday.wav";
		break;
		case G_DATE_SUNDAY:
		dow_str="talk/day/sunday.wav";
		break;
		default:
		//Unknown day of week
		dow_str="talk/f/fullstop.wav";
		break;
	    }//switch dow
	    
	    if (g_file_test(g_build_filename (cur_dir, dow_str, NULL), G_FILE_TEST_IS_REGULAR)) {
			wavlist = g_list_append(wavlist, g_build_filename (cur_dir, dow_str, NULL));	
	    }
	    	  
		
       switch (day) {
		case 1:
		day_str="talk/ordinal/first.wav";
		break;		
		case 2:
		day_str="talk/ordinal/second.wav";
		break;
		case 3:
		day_str="talk/ordinal/third.wav";
		break;
		case 4:
		day_str="talk/ordinal/fourth.wav";
		break;
		case 5:
		day_str="talk/ordinal/fifth.wav";
		break;
		case 6:
		day_str="talk/ordinal/sixth.wav";
		break;
		case 7:
		day_str="talk/ordinal/seventh.wav";
		break;
		case 8:
		day_str="talk/ordinal/eighth.wav";
		break;
		case 9:
		day_str="talk/ordinal/ninth.wav";
		break;
		case 10:
		day_str="talk/ordinal/tenth.wav";
		break;
		case 11:
		day_str="talk/ordinal/eleventh.wav";		
		break;
		case 12:
		day_str="talk/ordinal/twelfth.wav";		
		break;
		case 13:
		day_str="talk/ordinal/thirteenth.wav";
		
		break;
		case 14:
		day_str="talk/ordinal/fourteenth.wav";
		
		break;
		case 15:
		day_str="talk/ordinal/fifteenth.wav";
		
		break;
		case 16:
		day_str="talk/ordinal/sixteenth.wav";
		
		break;
		case 17:
		day_str="talk/ordinal/seventeenth.wav";
		
		break;
		case 18:
		day_str="talk/ordinal/eighteenth.wav";
		
		break;
		case 19:
		day_str="talk/ordinal/nineteenth.wav";
		
		break;
		case 20:
		day_str="talk/ordinal/twentieth.wav";
		
		break;
		case 21:
		day_str="talk/ordinal/twentyfirst.wav";
		
		break;
		case 22:
		day_str="talk/ordinal/twentysecond.wav";		
		break;
		case 23:
		day_str="talk/ordinal/twentythird.wav";		
		break;
		case 24:
		day_str="talk/ordinal/twentyfourth.wav";
		
		break;
		case 25:
		day_str="talk/ordinal/twentyfifth.wav";
		
		break;
		case 26:
		day_str="talk/ordinal/twentysixth.wav";
		
		break;
		case 27:
		day_str="talk/ordinal/twentyseventh.wav";
		
		break;
		case 28:
		day_str="talk/ordinal/twentyeighth.wav";
		
		break;
		case 29:
		day_str="talk/ordinal/twentyninth.wav";
		
		break;
		case 30:
		day_str="talk/ordinal/thirtieth.wav";
		
		break;
		case 31:
		day_str="talk/ordinal/thirtyfirst.wav";
		
		break;
		default:
		//Unknown ordinal
		day_str="talk/f/fullstop.wav";
		break;		
	  } //day switch
      
      if (g_file_test(g_build_filename (cur_dir, day_str, NULL), G_FILE_TEST_IS_REGULAR)) {
			wavlist = g_list_append(wavlist, g_build_filename (cur_dir, day_str, NULL));	
	  }
            
     //if (, G_FILE_TEST_IS_REGULAR)) {
				
	  //}
            
      month_enum =g_date_get_month (date);
      
      switch (month_enum) {
		case G_DATE_JANUARY:
		//month_str=" January";
		month_str="talk/month/january.wav";
		break;
		case G_DATE_FEBRUARY:
		month_str="talk/month/february.wav";
		//month_str=" February";
		break;
		case G_DATE_MARCH:
		month_str="talk/month/march.wav";
		//month_str=" March";
		break;
		case G_DATE_APRIL:
		month_str="talk/month/april.wav";
		//month_str=" April";
		break;
		case G_DATE_MAY:
		month_str="talk/month/may.wav";
		//month_str=" May";
		break;
		case G_DATE_JUNE:
		month_str="talk/month/june.wav";
		//month_str=" June";
		break;
		case G_DATE_JULY:
		month_str="talk/month/july.wav";
		//month_str=" July";
		break;
		case G_DATE_AUGUST:
		month_str="talk/month/august.wav";
		//month_str=" August";
		break;
		case G_DATE_SEPTEMBER:
		month_str="talk/month/september.wav";
		//month_str=" September";
		break;
		case G_DATE_OCTOBER:
		month_str="talk/month/october.wav";
		//month_str=" October";
		break;
		case G_DATE_NOVEMBER:
		month_str="talk/month/november.wav";
		//month_str=" November";
		break;
		case G_DATE_DECEMBER:
		month_str="talk/month/december.wav";
		//month_str=" December";
		break;
		default:
		//month_str=" Unknown Month";
		month_str="talk/f/fullstop.wav";
		break;
	  } //month switch
      
       if (g_file_test(g_build_filename (cur_dir, month_str, NULL), G_FILE_TEST_IS_REGULAR)) {
			 wavlist = g_list_append(wavlist, g_build_filename (cur_dir, month_str, NULL));	
	  }
       
            
    // Now deal with events
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
    
     if (total_number_events ==0) {		
          	  
	 if (g_file_test(g_build_filename (cur_dir,"talk/n/no.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
		wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/n/no.wav", NULL));		
	 }	 
	  if (g_file_test(g_build_filename (cur_dir,"talk/e/events.wav", NULL), G_FILE_TEST_IS_REGULAR)) {				
	  wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/e/events.wav", NULL));
	  }      
	} //if
		
	else {
	
	if(total_number_events ==1){
	if (g_file_test(g_build_filename (cur_dir,"talk/cardinal/one.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/cardinal/one.wav", NULL));	
	}
	if (g_file_test(g_build_filename (cur_dir,"talk/e/event.wav", NULL), G_FILE_TEST_IS_REGULAR)) {				
	wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/e/event.wav", NULL));
	}
	}       
	else if(total_number_events ==2){
	if (g_file_test(g_build_filename (cur_dir,"talk/cardinal/two.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/cardinal/two.wav", NULL)); 
	}
	if (g_file_test(g_build_filename (cur_dir,"talk/e/events.wav", NULL), G_FILE_TEST_IS_REGULAR)) {				
	wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/e/events.wav", NULL));
	}     
	}  
	else if(total_number_events ==3){
	if (g_file_test(g_build_filename (cur_dir,"talk/cardinal/three.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/cardinal/three.wav", NULL));
	}
	if (g_file_test(g_build_filename (cur_dir,"talk/e/events.wav", NULL), G_FILE_TEST_IS_REGULAR)) {				
	wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/e/events.wav", NULL));
	}		 
	}
	else if(total_number_events ==4){ 
	if (g_build_filename (cur_dir,"talk/cardinal/four.wav", NULL), G_FILE_TEST_IS_REGULAR) {
	wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/cardinal/four.wav", NULL));
	}
	if (g_file_test(g_build_filename (cur_dir,"talk/e/events.wav", NULL), G_FILE_TEST_IS_REGULAR)) {				
	wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/e/events.wav", NULL));
	}
	}
	else if(total_number_events ==5){ 
	if ( g_file_test(g_build_filename (cur_dir,"talk/cardinal/five.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/cardinal/five.wav", NULL));
	}
	if (g_file_test(g_build_filename (cur_dir,"talk/e/events.wav", NULL), G_FILE_TEST_IS_REGULAR)) {				
	wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/e/events.wav", NULL));
	}
	}		
	else {
	if (g_file_test(g_build_filename (cur_dir,"talk/m/many.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/m/many.wav", NULL));
	}
	if (g_file_test(g_build_filename (cur_dir,"talk/e/events.wav", NULL), G_FILE_TEST_IS_REGULAR)) {				
	wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/e/events.wav", NULL));
	}
	}
	
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
    
    if(m_talk_title) {
    //Now get event titles
    GList *event_title_list=NULL;	
    
   	
	Event evt;	
	gchar* str;
	gchar** words;
	//gchar* word;	
	gint j=0;
	
	for(int i=0; i<total_number_events; i++) {	
	evt=event_array_total[i];	
	
	if(m_talk_priority) {
		gint p = evt.priority;
		
		if (p==1) {			
			if (g_file_test(g_build_filename (cur_dir,"talk/l/low.wav", NULL), G_FILE_TEST_IS_REGULAR)) {				
				wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/l/low.wav", NULL));
	        }
	        if (g_file_test(g_build_filename (cur_dir,"talk/p/priority.wav", NULL), G_FILE_TEST_IS_REGULAR)) {				
				wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/p/priority.wav", NULL));
	        }
	        if (g_file_test(g_build_filename (cur_dir,"talk/e/event.wav", NULL), G_FILE_TEST_IS_REGULAR)) {				
				wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/e/event.wav", NULL));
	        }			
		}
		if (p==2) {			
			if (g_file_test(g_build_filename (cur_dir,"talk/m/medium.wav", NULL), G_FILE_TEST_IS_REGULAR)) {				
				wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/m/medium.wav", NULL));
	        }
	        if (g_file_test(g_build_filename (cur_dir,"talk/p/priority.wav", NULL), G_FILE_TEST_IS_REGULAR)) {				
				wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/p/priority.wav", NULL));
	        }
	        if (g_file_test(g_build_filename (cur_dir,"talk/e/event.wav", NULL), G_FILE_TEST_IS_REGULAR)) {				
				wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/e/event.wav", NULL));
	        }
		}
		if (p==3) {			
			if (g_file_test(g_build_filename (cur_dir,"talk/h/high.wav", NULL), G_FILE_TEST_IS_REGULAR)) {				
				wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/h/high.wav", NULL));
	        }
	        if (g_file_test(g_build_filename (cur_dir,"talk/p/priority.wav", NULL), G_FILE_TEST_IS_REGULAR)) {				
				wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/p/priority.wav", NULL));
	        }
	        if (g_file_test(g_build_filename (cur_dir,"talk/e/event.wav", NULL), G_FILE_TEST_IS_REGULAR)) {				
				wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/e/event.wav", NULL));
	        }			
		}
	}
	
		
	str=evt.title;
	//split title words	
	words = g_strsplit (str, " ", 0); //split on space
	j=0;			   
	while(words[j] != NULL)
	{
	event_title_list = g_list_append(event_title_list, words[j]);
	j++;
	} //while loop words
	} //for events 
	free(event_array_total);
	//cycle through the event title word list
	gpointer pt_event_title_list;
	gchar* event_title_list_str;
	gchar* event_title_list_str_lower;
	
	for(int i=0;i<g_list_length(event_title_list);i++)
	 {	  
	 pt_event_title_list=g_list_nth_data(event_title_list,i);
	 event_title_list_str=(gchar *)pt_event_title_list;
	 event_title_list_str_lower= g_ascii_strdown(event_title_list_str, -1);
	 
	 //a words	
	 if (g_strcmp0(event_title_list_str_lower,"agent")==0) {		  
	 if (g_file_test(g_build_filename (cur_dir,"talk/a/agent.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/a/agent.wav", NULL));
	 }	   	  
	 }  
	 if (g_strcmp0(event_title_list_str_lower,"alert")==0) {		  
	 if (g_file_test(g_build_filename (cur_dir,"talk/a/alert.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/a/alert.wav", NULL));	
	 }  		  
	 }  
	 if (g_strcmp0(event_title_list_str_lower,"allotment")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/a/allotment.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/a/allotment.wav", NULL));
	 }   		  
	 }  
	 if (g_strcmp0(event_title_list_str_lower,"anniversary")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/a/anniversary.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/a/anniversary.wav", NULL));
	 } 		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"annual")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/a/annual.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/a/annual.wav", NULL));
	 }		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"appointment")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/a/appointment.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/a/appointment.wav", NULL));
	 }		  
	 }
	 
	 //b words
	 if (g_strcmp0(event_title_list_str_lower,"bank")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/b/bank.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/b/bank.wav", NULL));
	 }  	  
	 }	  
	 if (g_strcmp0(event_title_list_str_lower,"bill")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/b/bill.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/b/bill.wav", NULL));
	 } 		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"birthday")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/b/birthday.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/b/birthday.wav", NULL));
	 } 	  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"book")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/b/book.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/b/book.wav", NULL));
	 } 		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"boxing")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/b/boxing.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/b/boxing.wav", NULL));
	 } 		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"breakfast")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/b/breakfast.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/b/breakfast.wav", NULL));
	 } 	  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"builder")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/b/builder.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/b/builder.wav", NULL));
	 }		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"business")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/b/business.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/b/business.wav", NULL));
	 }  		  
	 }
	 
	 //c words
	 if (g_strcmp0(event_title_list_str_lower,"calendar")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/c/calendar.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/c/calendar.wav", NULL));
	 } 		  
	 }	  
	 if (g_strcmp0(event_title_list_str_lower,"call")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/c/call.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/c/call.wav", NULL));
	 }		  
	 }	  
	 if (g_strcmp0(event_title_list_str_lower,"cancel")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/c/cancel.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/c/cancel.wav", NULL));
	 } 	  
	 }	  
	 if (g_strcmp0(event_title_list_str_lower,"car")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/c/car.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/c/car.wav", NULL));
	 }		  
	 }	  
	 if (g_strcmp0(event_title_list_str_lower,"change")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/c/change.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/c/change.wav", NULL));
	 }		  
	 }	  
	 if (g_strcmp0(event_title_list_str_lower,"check")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/c/check.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/c/check.wav", NULL));
	 }		  
	 }	  
	 if (g_strcmp0(event_title_list_str_lower,"christmas")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/c/christmas.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/c/christmas.wav", NULL));
	 } 		  
	 }	  
	 if (g_strcmp0(event_title_list_str_lower,"church")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/c/church.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/c/church.wav", NULL));
	 }   	  
	 }	  
	 if (g_strcmp0(event_title_list_str_lower,"clean")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/c/clean.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/c/clean.wav", NULL));
	 }   		  
	 }	  
	 if (g_strcmp0(event_title_list_str_lower,"club")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/c/club.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/c/club.wav", NULL));
	 } 		  
	 }	  
	 if (g_strcmp0(event_title_list_str_lower,"code")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/c/code.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/c/code.wav", NULL));
	 }  		  
	 }	  
	 if (g_strcmp0(event_title_list_str_lower,"company")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/c/company.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/c/company.wav", NULL));
	 }		  
	 }	  
	 if (g_strcmp0(event_title_list_str_lower,"conference")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/c/conference.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/c/conference.wav", NULL));
	 }		  
	 }	  
	 if (g_strcmp0(event_title_list_str_lower,"contact")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/c/contract.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/c/contract.wav", NULL));
	 }		  
	 }	  
	 if (g_strcmp0(event_title_list_str_lower,"contract")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/c/contract.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/c/contract.wav", NULL));	  
	 }  		  
	 }
	 
	 //Cardinal
	 if (g_strcmp0(event_title_list_str_lower,"one")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/cardinal/one.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/cardinal/one.wav", NULL));
	 }	  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"two")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/cardinal/two.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/cardinal/two.wav", NULL));
	 }		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"three")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/cardinal/three.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/cardinal/three.wav", NULL)); 
	 }		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"four")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/cardinal/four.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/cardinal/four.wav", NULL));
	 } 		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"five")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/cardinal/five.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/cardinal/five.wav", NULL));
	 } 		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"six")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/cardinal/six.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/cardinal/six.wav", NULL));
	 }  	  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"seven")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/cardinal/seven.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/cardinal/seven.wav", NULL));
	 } 		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"eight")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/cardinal/eight.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/cardinal/eight.wav", NULL));
	 } 		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"nine")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/cardinal/nine.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/cardinal/nine.wav", NULL));
	 }  		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"ten")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/cardinal/ten.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/cardinal/ten.wav", NULL)); 
	 } 		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"eleven")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/cardinal/eleven.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/cardinal/eleven.wav", NULL));
	 } 		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"twelve")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/cardinal/twelve.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/cardinal/twelve.wav", NULL));
	 }   		  
	 }
	 
	 //d words
	 if (g_strcmp0(event_title_list_str_lower,"day")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/d/day.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/d/day.wav", NULL));
	 }		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"decorate")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/d/decorate.wav", NULL), G_FILE_TEST_IS_REGULAR)) { 
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/d/decorate.wav", NULL));
	 }	  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"dentist")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/d/dentist.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/d/dentist.wav", NULL));
	 }  		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"development")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/d/development.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/d/development.wav", NULL));
	 } 		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"diary")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/d/diary.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/d/diary.wav", NULL));
	 }  	  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"dinner")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/d/dinner.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/d/dinner.wav", NULL));
	 }  	  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"do")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/d/do.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/d/do.wav", NULL));
	 } 	  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"doctor")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/d/doctor.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/d/doctor.wav", NULL));
	 }  	  
	 }
	 
	 //day
	 if (g_strcmp0(event_title_list_str_lower,"monday")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/day/monday.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/day/monday.wav", NULL));
	 }   		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"tuesday")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/day/tuesday.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/day/tuesday.wav", NULL));
	 }   	  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"wednesday")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/day/wednesday.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/day/wednesday.wav", NULL));
	 }   		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"thursday")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/day/thursday.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/day/thursday.wav", NULL));
	 }  	  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"friday")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/day/friday.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/day/friday.wav", NULL));
	 }  	  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"saturday")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/day/saturday.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/day/saturday.wav", NULL));
	 }  	  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"sunday")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/day/sunday.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/day/sunday.wav", NULL));
	 }  		  
	 }
	 	 
	 //e words
	 if (g_strcmp0(event_title_list_str_lower,"easter")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/e/easter.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/e/easter.wav", NULL));
	 }			  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"engagement")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/e/engagement.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/e/engagement.wav", NULL));
	 }		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"estate")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/e/estate.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/e/estate.wav", NULL));
	 }  		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"event")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/e/event.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/e/event.wav", NULL));
	 }	  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"events")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/e/events.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/e/events.wav", NULL)); 
	 }	  
	 }
	 	 
	 //f words
	 if (g_strcmp0(event_title_list_str_lower,"family")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/f/family.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/f/family.wav", NULL));
	 }	  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"fathers")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/f/fathers.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/f/fathers.wav", NULL));
	 }  		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"film")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/f/film.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/f/film.wav", NULL));
	 }  		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"friends")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/f/friends.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/f/friends.wav", NULL));
	 }   		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"funeral")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/f/funeral.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/f/funeral.wav", NULL));
	 }		  
	 }
	 	 
	 //g words
	 if (g_strcmp0(event_title_list_str_lower,"gala")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/g/gala.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/g/gala.wav", NULL));
	 } 		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"game")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/g/game.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/g/game.wav", NULL));
	 }  		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"garden")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/g/garden.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/g/garden.wav", NULL));
	 }   		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"gas")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/g/gas.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/g/gas.wav", NULL)); 
	 }		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"general")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/g/general.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/g/general.wav", NULL)); 
	 } 		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"go")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/g/go.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/g/go.wav", NULL));
	 }  		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"graduation")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/g/graduation.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/g/graduation.wav", NULL)); 
	 }  	  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"gym")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/g/gym.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/g/gym.wav", NULL));
	 }  		  
	 }
	 
	 //h words
	 if (g_strcmp0(event_title_list_str_lower,"halloween")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/h/halloween.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/h/halloween.wav", NULL));
	 }   		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"hello")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/h/hello.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/h/hello.wav", NULL));
	 }  		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"holiday")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/h/holiday.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/h/holiday.wav", NULL));
	 }   		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"hospital")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/h/hospital.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/h/hospital.wav", NULL));
	 }   		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"house")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/h/house.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/h/house.wav", NULL));
	 }  		  
	 }
	 	 
	 //i words
	 if (g_strcmp0(event_title_list_str_lower,"interview")==0) {	  
	 if (g_file_test(g_build_filename (cur_dir,"talk/i/interview.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/i/interview.wav", NULL));	  
	 }
	 }
	 
	 //l words
	 if (g_strcmp0(event_title_list_str_lower,"lecture")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/l/lecture.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/l/lecture.wav", NULL));
	 }	  		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"leisure")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/l/leisure.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/l/leisure.wav", NULL));
	 }		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"lift")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/l/lift.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/l/lift.wav", NULL));
	 }		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"linux")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/l/linux.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/l/linux.wav", NULL));
	 }  	  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"lunch")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/l/lunch.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/l/lunch.wav", NULL));
	 }   		  
	 }
	 
	 
	 //m words
	 if (g_strcmp0(event_title_list_str_lower,"maintenance")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/m/maintenance.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/m/maintenance.wav", NULL));
	 }   		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"meal")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/m/meal.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/m/meal.wav", NULL));
	 }  		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"medical")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/m/medical.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/m/medical.wav", NULL)); 
	 }  	  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"meeting")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/m/meeting.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/m/meeting.wav", NULL)); 
	 }		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"memo")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/m/memo.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/m/memo.wav", NULL));
	 } 		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"mothers")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/m/mothers.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/m/mothers.wav", NULL)); 
	 } 		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"music")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/m/music.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/m/music.wav", NULL)); 
	 } 		  
	 }
	 //n words
	 //o words
	
	 //p words
	 if (g_strcmp0(event_title_list_str_lower,"party")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/p/party.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/p/party.wav", NULL));  
	 }  		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"payment")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/p/payment.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/p/payment.wav", NULL));
	 } 		  
	 } 
	 if (g_strcmp0(event_title_list_str_lower,"phone")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/p/phone.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/p/phone.wav", NULL));
	 }	   	  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"picnic")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/p/picnic.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/p/picnic.wav", NULL));
	 }  	  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"prescription")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/p/prescription.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/p/prescription.wav", NULL));
	 }	  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"priority")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/p/priority.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/p/priority.wav", NULL));
	 }  		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"project")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/p/project.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/p/project.wav", NULL));
	 } 		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"pub")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/p/pub.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/p/pub.wav", NULL));
	 }  		  
	 }
	 
	 //q words
	 //r words
	 
	 if (g_strcmp0(event_title_list_str_lower,"radio")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/r/radio.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/r/radio.wav", NULL));
	 }		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"religious")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/r/religious.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/r/religious.wav", NULL));
	 }   	  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"reminder")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/r/reminder.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/r/reminder.wav", NULL));
	 }  		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"repair")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/r/repair.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/r/repair.wav", NULL));
	 }	  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"repeat")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/r/repeat.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/r/repeat.wav", NULL));
	 }   		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"restaurant")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/r/restaurant.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/r/restaurant.wav", NULL));
	 } 		  
	 }
	 	 
	 // s words
	 if (g_strcmp0(event_title_list_str_lower,"school")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/s/school.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/s/school.wav", NULL));
	 }   	  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"seminar")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/s/seminar.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/s/seminar.wav", NULL));
	 }  		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"service")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/s/service.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/s/service.wav", NULL));
	 }   		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"shopping")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/s/shopping.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/s/shopping.wav", NULL));
	 }  		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"social")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/s/social.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/s/social.wav", NULL));
	 }     
	 }
	 if (g_strcmp0(event_title_list_str_lower,"software")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/s/software.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/s/software.wav", NULL));
	 } 		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"sport")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/s/sport.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/s/sport.wav", NULL)); 
	 } 		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"spring")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/s/spring.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/s/spring.wav", NULL));
	 }	  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"station")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/s/station.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/s/station.wav", NULL));
	 }		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"subscription")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/s/subscription.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/s/subscription.wav", NULL));
	 } 		  
	 }
		 
	 // t words
	 if (g_strcmp0(event_title_list_str_lower,"talk")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/t/talk.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/t/talk.wav", NULL));
	 }		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"teacher")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/t/teacher.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/t/teacher.wav", NULL));
	 }		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"team")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/t/team.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/t/team.wav", NULL));
	 }		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"the")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/t/the.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/t/the.wav", NULL));
	 }		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"theatre")==0) {	 
	 if (g_file_test(g_build_filename (cur_dir,"talk/t/theatre.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/t/theatre.wav", NULL)); 
	 }
	 }
	 if (g_strcmp0(event_title_list_str_lower,"tiki")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/t/tiki.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/t/tiki.wav", NULL));
	 }  		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"to")==0) {	 
	 if (g_file_test(g_build_filename (cur_dir,"talk/t/to.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/t/to.wav", NULL));
	 }		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"train")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/t/train.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/t/train.wav", NULL));
	 } 	  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"travel")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/t/travel.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/t/travel.wav", NULL));
	 } 	  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"tutor")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/t/tutor.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/t/tutor.wav", NULL));
	 } 		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"tv")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/t/tv.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/t/tv.wav", NULL));
	 } 	  
	 }
	 	 
	 // u words
	 if (g_strcmp0(event_title_list_str_lower,"university")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/u/university.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/u/university.wav", NULL));
	 } 		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"update")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/u/update.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/u/update.wav", NULL));
	 }	  
	 }
	 	 
	 //v words
	 if (g_strcmp0(event_title_list_str_lower,"valentine")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/v/valentine.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/v/valentine.wav", NULL));
	 } 		  
	 }
	 if (g_strcmp0(event_title_list_str_lower,"visit")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/v/visit.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/v/visit.wav", NULL));
	 } 		  
	 }
	 
	 // w words
	 if (g_strcmp0(event_title_list_str_lower,"walk")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/w/walk.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/w/walk.wav", NULL));
	 } 
	 }
	 if (g_strcmp0(event_title_list_str_lower,"wedding")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/w/wedding.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/w/wedding.wav", NULL));
	 }
	 }
	 if (g_strcmp0(event_title_list_str_lower,"with")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/w/with.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/w/with.wav", NULL));
	 }
	 }
	 if (g_strcmp0(event_title_list_str_lower,"work")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/w/work.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/w/work.wav", NULL));
	 }
	 }
	 if (g_strcmp0(event_title_list_str_lower,"world")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/w/world.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/w/world.wav", NULL));
	 }
	 }
	 
	 //y words
	 if (g_strcmp0(event_title_list_str_lower,"year")==0) {
	 if (g_file_test(g_build_filename (cur_dir,"talk/y/year.wav", NULL), G_FILE_TEST_IS_REGULAR)) {
	 wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/y/year.wav", NULL));
	 }		  
	 }
	 
	 }//glist
	} //m_title_speaking
	   
	} //else
	
		 
	 if (g_build_filename (cur_dir,"talk/f/fullstop.wav", NULL), G_FILE_TEST_IS_REGULAR) {
	  wavlist = g_list_append(wavlist, g_build_filename (cur_dir,"talk/f/fullstop.wav", NULL));
	  }
	
	
    
    //use wavcat for concatenation (see audio limitations) 
	gpointer pt_data;
	gchar* list_str;
			  
	char* merge_file ="/tmp/talkout.wav";
	int num_files = g_list_length(wavlist);
	char* file_names[g_list_length(wavlist)];
	
	for(int i=0;i<g_list_length(wavlist);i++) //iterate through GList wavlist 
	{	  
	pt_data=g_list_nth_data(wavlist,i);
	list_str=(char *)pt_data;	
	file_names[i] = list_str;	//populate char* array
	//printf("main: locate file_names[%d] = '%s'\n",i,file_names[i]);
	}
	
	merge_wav_files(merge_file, num_files, file_names);
    
	
	g_list_free(wavlist);	
    g_free (cur_dir);	
	
	//play audio in a thread
	GThread *thread_audio; 	
	gchar* wav_file ="/tmp/talkout.wav"; 
	g_mutex_lock (&lock);
    thread_audio = g_thread_new(NULL, thread_playwav, wav_file);  
	g_thread_unref (thread_audio);	
	
}



//---------------------------------------------------------------------


//------------------------------------------------------------------
// Read events
//-------------------------------------------------------------------
static void callbk_read_events(GSimpleAction *action,
							G_GNUC_UNUSED  GVariant      *parameter,
							  gpointer       window)
{
			
	GtkCalendar *calendar =g_object_get_data(G_OBJECT(window), "calendar-key");
		
    if(m_talk) {
       speak_events_at_date(calendar);
	}
	   
}

//--------------------------------------------------------------------
// Options callback
//--------------------------------------------------------------------
static void options_callbk(GSimpleAction *action,
							G_GNUC_UNUSED  GVariant      *parameter,
							  gpointer       user_data){
	
	GtkWidget *window = (GtkWidget *) user_data;
   
   if( !GTK_IS_WINDOW(window)) { 
	  return;
  }
	
		
	talkcalendar_options_dialog(window);
	
		
}


//--------------------------------------------------------------------
// About
//---------------------------------------------------------------------

static void callbk_about_close (GtkDialog *dialog, gint response_id, gpointer user_data)
{
  /* This will cause the dialog to be destroyed */
  gtk_widget_destroy (GTK_WIDGET (dialog));
}


static void callbk_about(GtkWindow *window){	
	
		
	const gchar *authors[] = {"Alan Crispin", NULL};		
	GtkWidget *about_dialog;
	about_dialog = gtk_about_dialog_new();	
	g_signal_connect (GTK_DIALOG (about_dialog), "response", G_CALLBACK (callbk_about_close), NULL);
	
	gtk_window_set_transient_for(GTK_WINDOW(about_dialog),GTK_WINDOW(window));
	gtk_widget_set_size_request(about_dialog, 200,200);
    gtk_window_set_modal(GTK_WINDOW(about_dialog),TRUE);	
	gtk_about_dialog_set_program_name(GTK_ABOUT_DIALOG(about_dialog), "Gtk Talk Calendar");
	gtk_about_dialog_set_version (GTK_ABOUT_DIALOG(about_dialog), "1.1.1");
	gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(about_dialog),"Copyright © 2021");
	gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(about_dialog),"Calendar Assistant"); 	
	//gtk_about_dialog_set_wrap_license(GTK_ABOUT_DIALOG(about_dialog),TRUE);	
	gtk_about_dialog_set_license_type (GTK_ABOUT_DIALOG(about_dialog), GTK_LICENSE_GPL_2_0);
	gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(about_dialog),"https://github.com/crispinalan/"); 
	gtk_about_dialog_set_website_label(GTK_ABOUT_DIALOG(about_dialog),"Talk Calendar Website");
	gtk_about_dialog_set_authors(GTK_ABOUT_DIALOG(about_dialog), authors);
	//gtk_about_dialog_set_logo_icon_name(GTK_ABOUT_DIALOG(about_dialog), NULL);	
	gtk_about_dialog_set_logo_icon_name(GTK_ABOUT_DIALOG(about_dialog), "x-office-calendar");
	gtk_widget_show(about_dialog);	
		
}

//---------------------------------------------------------------------
// List view  //G_GNUC_UNUSED
//---------------------------------------------------------------------

//-------------------------------------------------------------------
// List row activated (double click)
//-------------------------------------------------------------------

static void list_row_activated_callbk(GtkTreeView  *tree_view,
										 GtkTreePath       *path,
										 GtkTreeViewColumn *column,
										 gpointer           user_window)
										 
{
   
   gint id =0;   
   gchar *title;
  
   GtkWindow *window = user_window; //window   
   GtkTreeIter iter; //row iterator (internal structure)
   GtkTreeModel *model = gtk_tree_view_get_model(tree_view);

   if (gtk_tree_model_get_iter(model, &iter, path)) {      
   //Get selected data   
   //gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &id, 1, &title, -1);      
   gtk_tree_model_get (GTK_TREE_MODEL(model), &iter, 0, &id, 1, &title, -1);
   
   Event *event =g_malloc(sizeof(Event));    
   db_get_event(id, event);    
   talkcalendar_update_event(GTK_WIDGET(window), event); 
   }
}

//--------------------------------------------------------------------
// List view -inialise - add -remove -remove all
//--------------------------------------------------------------------

static void init_list(GtkWidget *list)
{
    GtkCellRenderer *renderer = gtk_cell_renderer_text_new();
    GtkTreeViewColumn *id, *title; 
    GtkListStore *store;

    id = gtk_tree_view_column_new_with_attributes("id", renderer, "text", 0, NULL);      
    title = gtk_tree_view_column_new_with_attributes("title", renderer,"text",1, NULL);
 
    gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(list),FALSE);

    gtk_tree_view_append_column(GTK_TREE_VIEW(list), id);
    gtk_tree_view_column_set_visible (id,FALSE); 
       
    gtk_tree_view_append_column(GTK_TREE_VIEW(list), title);
    gtk_tree_view_column_set_visible (title,TRUE); 
   
    store = gtk_list_store_new(2, G_TYPE_INT, G_TYPE_STRING);
    gtk_tree_view_set_model(GTK_TREE_VIEW(list), GTK_TREE_MODEL(store));
    g_object_unref(store);
}

static void add_to_list(GtkWidget *list, const gint id, const gchar* title)
{
    
    GtkListStore *store;      
    GtkTreeIter iter;   
    store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(list)));    
    gtk_list_store_append(store, &iter);
    gtk_list_store_set(store, &iter, 0, id, -1); 
    gtk_list_store_set(store, &iter, 1, title, -1);   
}


void remove_all(GtkWidget *list, gpointer selection) {
    
  GtkListStore *store;
  GtkTreeModel *model;
  GtkTreeIter  iter;

  store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(list)));
  model = gtk_tree_view_get_model(GTK_TREE_VIEW(list));

  if (gtk_tree_model_get_iter_first(model, &iter) == FALSE) {
      return;
  }
  
  gtk_list_store_clear(store);
  
  //g_object_unref(store);
  //g_object_unref (model);
}

void remove_item(GtkWidget *list, gpointer selection) {
    
  GtkListStore *store;
  GtkTreeModel *model;
  GtkTreeIter  iter;

  store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(list)));
  model = gtk_tree_view_get_model(GTK_TREE_VIEW(list));

  if (gtk_tree_model_get_iter_first(model, &iter) == FALSE) {
      return;
  }

  if (gtk_tree_selection_get_selected(GTK_TREE_SELECTION(selection), 
         &model, &iter)) {
    gtk_list_store_remove(store, &iter);
  }
}

//------------------------------------------------------------------
// Start up
//------------------------------------------------------------------

static void startup (GtkApplication *application)
{
	GMenu *main_menu;
	GMenu *file_menu;
	GMenu *edit_menu;
	GMenu *tools_menu;
	GMenu *help_menu;
	GMenuItem *item;
    
    main_menu = g_menu_new(); //main menu
    file_menu = g_menu_new(); //file menu
    edit_menu = g_menu_new(); //edit menu
    tools_menu = g_menu_new(); //tools menu    
    help_menu = g_menu_new(); //help menu
   
	
	item = g_menu_item_new("Import", "app.import");    
    g_menu_insert_item(file_menu,1,item);    
    g_object_unref(item);
  
    item = g_menu_item_new("Export", "app.export");    
    g_menu_insert_item(file_menu,2,item);    
    g_object_unref(item);
     
    item = g_menu_item_new("Quit", "app.quit");
    g_menu_append_item(file_menu,item);
	g_object_unref(item);
	
	item = g_menu_item_new("Options", "app.options");
    g_menu_append_item(edit_menu,item);
	g_object_unref(item);
	
	item = g_menu_item_new("Delete All Events", "app.delete");
    g_menu_append_item(edit_menu,item);
	g_object_unref(item);
	
	item = g_menu_item_new("New Event (Selected Date)", "app.new");
    g_menu_append_item(tools_menu,item);
	g_object_unref(item);
		
	item = g_menu_item_new("Talk Selected Date", "app.read");
    g_menu_append_item(tools_menu,item);
	g_object_unref(item);
		
	item = g_menu_item_new("Goto Today (Home Key)", "app.gotoday");
    g_menu_append_item(tools_menu,item);
	g_object_unref(item);
		
	item = g_menu_item_new("About", "app.about");
    g_menu_append_item(help_menu,item);
	g_object_unref(item); 
	
	item = g_menu_item_new("Audio Test", "app.audio");
    g_menu_append_item(help_menu,item);
	g_object_unref(item);
        
    //insert  menu into main menu          
    g_menu_insert_submenu(main_menu, 0, "File", G_MENU_MODEL(file_menu));
    g_menu_append_submenu(main_menu,"Edit", G_MENU_MODEL(edit_menu));
    g_menu_append_submenu(main_menu,"Tools", G_MENU_MODEL(tools_menu));
    g_menu_append_submenu(main_menu,"Help", G_MENU_MODEL(help_menu));
	//create the actions
    //create_actions(application);
        
    gtk_application_set_menubar(application, G_MENU_MODEL(main_menu));
    g_object_unref(main_menu);
    g_object_unref(file_menu);
    g_object_unref(tools_menu);
    g_object_unref(help_menu);     
	
}

/* signal handler for "toggled" signal of the CheckButton */
static void check_button_isyearly_toggled_callbk (GtkToggleButton *toggle_button, gpointer user_data)
{
 	 	
 	if (gtk_toggle_button_get_active(toggle_button)){		
	 //IsYearly TRUE	
	}     
	else{	
	//IsYearly FALSE
	}
  
}


/* signal handler for "toggled" signal of the CheckButton */
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

static void callbk_combo_box_priority_on_changed(GtkComboBox *widget,  gpointer  user_data)
{
	GtkComboBox *combo_box_priorities = widget;
	gchar *priority_str = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(combo_box_priorities));   
	g_free (priority_str);
}


//------------------------------------------------------------------
//RELOAD 
//------------------------------------------------------------------
static void reload_events(GtkWidget *widget, int year, int month, int day ) {

GtkWidget *window = (GtkWidget *) widget;
   
   if( !GTK_IS_WINDOW(window)) {	  
	   return;
  }
 
 
   GtkWidget *text_view = g_object_get_data(G_OBJECT(window), "textview-key"); //object-key association  
   GtkWidget *list = g_object_get_data(G_OBJECT(window), "list-key"); //object-key association
   
  remove_all(list, NULL); 
  
  GtkTextBuffer *text_buffer;
  gchar *output_str;  	 
  text_buffer = gtk_text_buffer_new (NULL);   
  output_str ="";
  gtk_text_buffer_set_text (text_buffer, output_str, -1);	//CLEAR
  gtk_text_view_set_buffer(GTK_TEXT_VIEW(text_view), text_buffer); 
  
	
	 
gint n_regular_events = db_get_number_of_rows_year_month_day(year, month, day);    
gint n_isyearly_month_events = db_get_number_of_isyearly_events_month(month);   
gint n_isyearly_day_events=0;
 
Event isyearly_array[n_isyearly_month_events];	 
db_get_isyearly_events_month(isyearly_array, month, n_isyearly_month_events);
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
db_get_all_events_year_month_day(event_array, year, month, day, n_regular_events);
		
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
//cycle through event array total	 
Event e3;

for(int i=0; i<total_number_events; i++) {	

e3=event_array_total[i];

GDateTime  *time_start;		 
gchar* time_start_str;
time_start = g_date_time_new_local(e3.year,e3.month,e3.day,e3.startHour, e3.startMin,0.0);         
time_start_str = g_date_time_format (time_start, "%l:%M %P");

GDateTime  *time_end;        
gchar* time_end_str;
time_end = g_date_time_new_local(e3.year,e3.month,e3.day,e3.endHour, e3.endMin,0.0);         
time_end_str = g_date_time_format (time_end, "%l:%M %P");
         
output_str= g_strconcat(output_str, e3.title, "\n", NULL);
		
if(e3.isAllday) {
	output_str= g_strconcat(output_str, "This is an all day event\n", NULL);			
}
else {			
	output_str= g_strconcat(output_str, time_start_str, " to ", time_end_str, "\n", NULL); 		
   //Two new lines for spacing -option?	
} //else
output_str= g_strconcat(output_str, e3.description, "\n", "\n", NULL);

gtk_text_buffer_set_text (text_buffer, output_str, -1);	
gtk_text_view_set_buffer(GTK_TEXT_VIEW(text_view), text_buffer);
add_to_list(list,e3.id,e3.title);
g_date_time_unref (time_start);
g_date_time_unref (time_end);		
		
} //for i <event_number		
	
 free(event_array_total); 	  
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
    GtkWidget *list = g_object_get_data(G_OBJECT(dialog), "dialog-list-key");
    GtkTreeSelection *selection;
    
    //GPOINTER_TO_INT()
    gint year = GPOINTER_TO_INT(g_object_get_data(G_OBJECT(dialog), "dialog-year-key")); 
    gint month = GPOINTER_TO_INT(g_object_get_data(G_OBJECT(dialog), "dialog-month-key"));  
    gint day= GPOINTER_TO_INT(g_object_get_data(G_OBJECT(dialog), "dialog-day-key"));  
    //gint year = g_object_get_data(G_OBJECT(dialog), "dialog-year-key"); 
    //gint month = g_object_get_data(G_OBJECT(dialog), "dialog-month-key");  
    //gint day= g_object_get_data(G_OBJECT(dialog), "dialog-day-key");  
 
	
	switch (response_id)
	{
	case 1: //OK pressed
	
	selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(list));
	
	//CHECK DELETE request
	
	if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check_button_delete)) ==1) {		
	db_delete_row(id);	//DELETE  
	//event deleted no longer exists so cant get data from it
	remove_item(GTK_WIDGET(list), selection); 	
	reload_events(window, year,month, day); //everything
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
    reload_events(window, year, month, day );	
	
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
 
    //GtkWidget *text_view = g_object_get_data(G_OBJECT(window), "textview-key"); //object-key association  
    GtkWidget *list = g_object_get_data(G_OBJECT(window), "list-key"); //object-key association
        
    GtkWidget *dialog;    
    GtkWidget *container;	
	
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
        
    
    //Create dialog
    dialog= gtk_dialog_new();
    //callbacks   
    g_signal_connect(dialog,"response",G_CALLBACK(callbk_talkcalendar_update_event_response),event);
    //g_signal_connect(dialog,"close",G_CALLBACK(callbk_event_dialog_close),NULL); 
        
    gtk_window_set_title (GTK_WINDOW (dialog), update_event_str);  
    
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
     // GtkWidget *list = g_object_get_data(G_OBJECT(window), "list-key");
     
     g_object_set_data(G_OBJECT(dialog), "dialog-year-key",GINT_TO_POINTER(event->year)); 
     g_object_set_data(G_OBJECT(dialog), "dialog-month-key",GINT_TO_POINTER(event->month));  
     g_object_set_data(G_OBJECT(dialog), "dialog-day-key",GINT_TO_POINTER(event->day));  
    
     //g_object_set_data(G_OBJECT(dialog), "year-key",event->year); 
     //g_object_set_data(G_OBJECT(dialog), "month-key",event->month);  
     //g_object_set_data(G_OBJECT(dialog), "day-key",event->day);  
	 
	
	//--------------------------------------------------------------
	// Dialog PACKING
	//--------------------------------------------------------------  
	container = gtk_dialog_get_content_area (GTK_DIALOG(dialog));	
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


//---------------------------------------------------------------------
// New event
//---------------------------------------------------------------------

//--------------------------------------------------------------------
// New event close callback
//---------------------------------------------------------------------

static void callbk_event_dialog_close(GtkDialog *dialog,
					     G_GNUC_UNUSED gpointer   user_data)  
{
	if( !GTK_IS_DIALOG(dialog)) { 
	return;
	}
	gtk_widget_destroy(GTK_WIDGET(dialog));
} 

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
  reload_events(window, year, month, day );
   
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


static void talkcalendar_new_event(GtkWidget *widget, guint year, guint month, guint day ) {

 GtkWidget *window = (GtkWidget *) widget;
   
   if( !GTK_IS_WINDOW(window)) { 
	  return;
  }
 
    //GtkWidget *text_view = g_object_get_data(G_OBJECT(window), "textview-key"); //object-key association  
   // GtkWidget *list = g_object_get_data(G_OBJECT(window), "list-key"); //object-key association
    //GtkCalendar *calendar =g_object_get_data(G_OBJECT(window), "calendar-key");
    
    GtkWidget *dialog;    
    GtkWidget *container;	
	
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
        
    //Create dialog
    dialog= gtk_dialog_new(); 
    gtk_window_set_title (GTK_WINDOW (dialog), new_event_str); 
   
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
    
		
	//--------------------------------------------------------------
	// Dialog PACKING
	//--------------------------------------------------------------  
	container = gtk_dialog_get_content_area (GTK_DIALOG(dialog));	
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
// Calendar callbacks
//----------------------------------------------------------------------
static void calendar_month_changed_callbk(GtkCalendar *calendar, gpointer user_data) {
	
   
   guint day, month, year;

   gtk_calendar_get_date(GTK_CALENDAR (calendar), &year, &month, &day); 
   
   gtk_calendar_clear_marks(GTK_CALENDAR (calendar));    
   
     
   mark_holidays_on_calendar(calendar, month+1,year);
   
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
	
	 // printout then mark up calendar
	Event evty;	
	for(int i=0; i<isyearly_number; i++) {		
		evty=isyearly_array[i];	
		evty.year=year;	
		guint rday = evty.day;
		gtk_calendar_mark_day(calendar, rday);
	} 
}


static void calendar_day_selected_double_click_callbk(GtkCalendar *calendar, gpointer user_data)
{
   guint day, month, year;

   gtk_calendar_get_date(GTK_CALENDAR (calendar), &year, &month, &day);    
   
   GtkWidget *window = (GtkWidget *) user_data;
   
   if( !GTK_IS_WINDOW(window)) { 
	  return;
  }
  
  talkcalendar_new_event(window, year, month+1, day);
 
  reload_events(window, year, month+1, day);
  calendar_month_changed_callbk(calendar, NULL);
  
}



static void calendar_day_selected_callbk(GtkCalendar *calendar, gpointer user_data)
{
     
   //claendar day clicked   
   GtkWidget *window = (GtkWidget *) user_data;
   
   if( !GTK_IS_WINDOW(window)) { 
   return;
   }
   
   
   
   //GtkWidget *window = g_object_get_data(G_OBJECT(user_data), "window-key"); //object-key association
   GDateTime *dt;
   dt =g_date_time_new_now_local(); //initialise
   GDateTime  *time_start;
   time_start =g_date_time_new_now_local();   
   GDateTime  *time_end;
   time_end =g_date_time_new_now_local();          
   
   GtkWidget *list_widget = g_object_get_data(G_OBJECT(calendar), "calendar-list-key"); //object-key association     
   GtkWidget *label_date =g_object_get_data(G_OBJECT(calendar), "calendar-label-date-key");    
   GtkWidget *text_view = g_object_get_data(G_OBJECT(window), "textview-key"); //object-key association  
   //GtkWidget *list_widget = g_object_get_data(G_OBJECT(window), "list-key"); //object-key association
      
   //GtkWidget *label_date =g_object_get_data(G_OBJECT(calendar), "calendar-label-date-key");    
   //GtkWidget *text_view = g_object_get_data(G_OBJECT(window), "textview-key"); //object-key association  
   //GtkWidget *list_widget = g_object_get_data(G_OBJECT(window), "list-key"); //object-key association
     
   GtkTextBuffer *text_buffer;
   gchar *output_str;
    
   //setup and clear text_view text_buffer   
   text_buffer = gtk_text_buffer_new (NULL);   
   output_str =""; 
  
   gtk_text_buffer_set_text (text_buffer, output_str, -1);	//clear
   gtk_text_view_set_buffer(GTK_TEXT_VIEW(text_view), text_buffer);
	
   //get the day month and year from calendar
   guint day, month, year;
   gtk_calendar_get_date(GTK_CALENDAR (calendar), &year, &month, &day);
   
    gchar *dt_str;
    dt = g_date_time_new_local(year,month+1,day,0,0,0.0);   // get date    
    dt_str = g_date_time_format(dt, "%a %e %b %Y");	
    gtk_label_set_xalign(GTK_LABEL(label_date),0.5); //add date to label
    	
	gtk_label_set_text(GTK_LABEL(label_date), dt_str); 	
  
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

remove_all(list_widget, NULL);	
for(int i=0; i<total_number_events; i++) {	

Event e3=event_array_total[i];

		 
gchar* time_start_str;
time_start = g_date_time_new_local(e3.year,e3.month,e3.day,e3.startHour, e3.startMin,0.0);         
time_start_str = g_date_time_format (time_start, "%l:%M %P");
 
        
gchar* time_end_str;
time_end = g_date_time_new_local(e3.year,e3.month,e3.day,e3.endHour, e3.endMin,0.0);         
time_end_str = g_date_time_format (time_end, "%l:%M %P");
         
output_str= g_strconcat(output_str, e3.title, "\n", NULL);
		
if(e3.isAllday) {
	output_str= g_strconcat(output_str, "This is an all day event\n", NULL);			
}
else {			
	output_str= g_strconcat(output_str, time_start_str, " to ", time_end_str, "\n", NULL); 		
   //Two new lines for spacing -option?	
} //else
output_str= g_strconcat(output_str, e3.description, "\n", "\n", NULL);		

add_to_list(list_widget,e3.id,e3.title);
gtk_text_buffer_set_text (text_buffer, output_str, -1);	
gtk_text_view_set_buffer(GTK_TEXT_VIEW(text_view), text_buffer);		

} //for i <row_number
free(event_array_total);		
reload_events(window, year,month+1, day);
calendar_month_changed_callbk(calendar,NULL); 
g_date_time_unref (time_start);
g_date_time_unref (time_end);	
g_date_time_unref(dt); 
   
}


//---------------------------------------------------------------------
//Delete all events 
//---------------------------------------------------------------------

static void callbk_delete_all_response(GtkDialog *dialog, gint response_id, gpointer  user_data)								 
{
	
	GtkWindow *window = user_data; //window data
	GtkTextBuffer *text_buffer;
    gchar *output_str;  
    
    GtkWidget *text_view = g_object_get_data(G_OBJECT(window), "textview-key"); //object-key association
	GtkWidget *list =g_object_get_data(G_OBJECT(window), "list-key");
	GtkCalendar *calendar =g_object_get_data(G_OBJECT(window), "calendar-key");
	 //g_object_set_data(G_OBJECT(window), "textview-key",text_view);  
     //g_object_set_data(G_OBJECT(window), "list-key",list);  
     //g_object_set_data(G_OBJECT(window), "calendar-key",calendar);
     
     if (response_id == GTK_RESPONSE_OK) {
     //Delete everything
     db_delete_all();
     db_reset_sequence();
     //clear 
     text_buffer = gtk_text_buffer_new (NULL);   
     output_str ="";
     gtk_text_buffer_set_text (text_buffer, output_str, -1);	//clear
     gtk_text_view_set_buffer(GTK_TEXT_VIEW(text_view), text_buffer);
     //clear list
     remove_all(list, NULL);
      //clear calendar marks
     calendar_month_changed_callbk(calendar,NULL);
   
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

static void delete_events_callbk(GtkWidget *window){	
	
	GtkWidget *message_dialog;
	message_dialog = gtk_message_dialog_new (GTK_WINDOW(window), GTK_DIALOG_MODAL, 
                                            GTK_MESSAGE_WARNING, 
                                            GTK_BUTTONS_OK_CANCEL, 
                                            "Delete All Events?");
	
	g_signal_connect (GTK_DIALOG (message_dialog), "response",   G_CALLBACK (callbk_delete_all_response), window);
	
	gtk_widget_show(message_dialog); 	
		
}

static void new_event_menu_callbk(GtkWidget *window){	

	if( !GTK_IS_WINDOW(window)) { 
	return;
	}
	
	GtkCalendar *calendar =g_object_get_data(G_OBJECT(window), "calendar-key");                    	
	
	guint day, month, year;
	
	gtk_calendar_get_date(GTK_CALENDAR (calendar), &year, &month, &day);    
		
	talkcalendar_new_event(window, year, month+1, day);
	
	reload_events(window, year, month+1, day);
	calendar_month_changed_callbk(calendar, NULL);

}

gboolean callbk_window_on_key_press(GtkWidget * widget, GdkEvent * event,
                    gpointer data)
{
	GtkWidget *window = (GtkWidget *) widget;
   
   if( !GTK_IS_WINDOW(window)) {	
   return FALSE;
   }
   
   GtkCalendar *calendar =g_object_get_data(G_OBJECT(window), "calendar-key");
   GtkWidget *label_date =g_object_get_data(G_OBJECT(window), "label-date-key");   
   GdkEventKey key = event->key;
   
   if(key.keyval ==GDK_KEY_space) {
	     
		
		GtkCalendar *calendar =g_object_get_data(G_OBJECT(window), "calendar-key"); 
			
		if(m_talk) {
		speak_events_at_date(calendar);
		}
   }
   
   
   if(key.keyval ==GDK_KEY_Home) {   
   
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
   reload_events(window, year, month,day);
   g_date_time_unref(dt); 
   }
   
   
return TRUE;
	
}

//---------------------------------------------------------------------
// activate
//---------------------------------------------------------------------

static void activate (GtkApplication *app, gpointer user_data)
{
  GtkWidget *window;
  GtkWidget *calendar;
  GtkWidget *label_date;
  GtkWidget *paned;
  GtkWidget *text_view;
  GtkWidget *scrolled_window;
  GtkTextBuffer *buffer_text_view;
  
  GtkWidget *box_pane1;
  GtkWidget *box_pane2;
  
  GtkWidget *list;
  
  GDateTime *dt;
  gchar *dt_format;
  dt = g_date_time_new_now_local();   // get local time     
  dt_format = g_date_time_format(dt, "%a %e %b %Y");
  
 
  //----------------------------------------------------------------
  //set up window
  //------------------------------------------------------------------
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Talk Calendar");
  gtk_window_set_default_size (GTK_WINDOW (window), 800, 400);
  gtk_window_set_icon_name (GTK_WINDOW (window), "x-office-calendar");
  //gtk_window_set_resizable (GTK_WINDOW (window), 0); window not resizable
  
  g_signal_connect(G_OBJECT (window), "key_press_event", G_CALLBACK(callbk_window_on_key_press), NULL);
  
  //Set up list view    
  list = gtk_tree_view_new(); // a widget for displaying both trees and lists    
  gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(list), TRUE);    
  g_object_set(G_OBJECT(list), "activate-on-single-click", FALSE, NULL);
  g_signal_connect(GTK_TREE_VIEW(list), "row-activated", G_CALLBACK(list_row_activated_callbk), window);    
  init_list(list);
 
 
  //-------------------------------------------------------------------
  // set up text view
  //-------------------------------------------------------------------
  
  buffer_text_view = gtk_text_buffer_new (NULL); //text being edited  
  text_view = gtk_text_view_new_with_buffer (buffer_text_view);
  gtk_text_view_set_editable(GTK_TEXT_VIEW(text_view),FALSE); 
  
  gtk_text_view_set_wrap_mode (GTK_TEXT_VIEW (text_view), GTK_WRAP_WORD);   
 
  scrolled_window = gtk_scrolled_window_new (NULL, NULL);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolled_window), 
                                  GTK_POLICY_AUTOMATIC, 
                                  GTK_POLICY_AUTOMATIC); 
  
  gtk_container_add (GTK_CONTAINER (scrolled_window), text_view); //put textview inside scrolled window
  gtk_container_set_border_width (GTK_CONTAINER (scrolled_window), 5);
 
  
  //-------------------------------------------------------------------
  // Set up calendar
  //--------------------------------------------------------------------
  
  //set up calendar
  calendar = gtk_calendar_new();
 // gtk_calendar_set_display_options(calendar,GTK_CALENDAR_SHOW_DAY_NAMES); 
   
  //calendar clicked
  g_signal_connect(GTK_CALENDAR(calendar), "day-selected", G_CALLBACK(calendar_day_selected_callbk), window);
  //calendar double clicked
  g_signal_connect(GTK_CALENDAR(calendar), "day-selected-double-click", G_CALLBACK(calendar_day_selected_double_click_callbk), window);
  g_signal_connect(GTK_CALENDAR(calendar), "month-changed", G_CALLBACK(calendar_month_changed_callbk), NULL);
  
 
  //g_signal_connect(GTK_CALENDAR(calendar), "day-selected", G_CALLBACK(calendar_day_selected_callbk), list);
  //g_signal_connect(GTK_CALENDAR(calendar), "day-selected-double-click", G_CALLBACK(calendar_day_selected_double_click_callbk), window);
  //g_signal_connect(GTK_CALENDAR(calendar), "month-changed", G_CALLBACK(calendar_month_changed_callbk), NULL);
   //---------------------------------------------------------------
	// Date label
	//--------------------------------------------------------------
	
	label_date=gtk_label_new("");	
	gtk_label_set_xalign(GTK_LABEL(label_date),0.5);
	gtk_label_set_text(GTK_LABEL(label_date), dt_format); 	
	
 
	 //----------------------------------------------------------------
	 // Set up connections
	 //-----------------------------------------------------------------
	 //g_object_set_data() makes a connection between two objects
	 g_object_set_data(G_OBJECT(window), "textview-key",text_view);  
     g_object_set_data(G_OBJECT(window), "list-key",list);  
     g_object_set_data(G_OBJECT(window), "calendar-key",calendar);
     g_object_set_data(G_OBJECT(window), "label-date-key",label_date);
     
     g_object_set_data(G_OBJECT(text_view), "text-view-window-key",window);
     
	 g_object_set_data(G_OBJECT(calendar), "calendar-list-key",list);
	 g_object_set_data(G_OBJECT(calendar), "calendar-textview-key",text_view); 
	 g_object_set_data(G_OBJECT(calendar), "calendar-label-date-key",label_date);   
	 
	 g_object_set_data(G_OBJECT(list), "treeview-textview-key",text_view);
	 g_object_set_data(G_OBJECT(list), "treeview-calendar-key",calendar);   	
	
	//------------------------------------------------------------------
	// Menu Actions
	//------------------------------------------------------------------
	
	GSimpleAction *export_action;	
	export_action=g_simple_action_new("export",NULL); //app.export
	g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(export_action)); //make visible
	//connect the exit_action activate signal to the exit_callbk function with application user data
	g_signal_connect(export_action, "activate",  G_CALLBACK(export_callbk), NULL);
	
	
	GSimpleAction *import_action;	
	import_action=g_simple_action_new("import",NULL); //app.import
	g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(import_action)); //make visible
	//connect the exit_action activate signal to the exit_callbk function with application user data
	g_signal_connect(import_action, "activate",  G_CALLBACK(import_callbk), calendar);
	
	
	GSimpleAction *exit_action;	
	exit_action=g_simple_action_new("quit",NULL); //app.quite
	g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(exit_action)); //make visible
	//connect the exit_action activate signal to the exit_callbk function with application user data
	g_signal_connect(exit_action, "activate",  G_CALLBACK(exit_callbk), app);
	
	GSimpleAction *options_action;
	options_action=g_simple_action_new("options",NULL); //action = app.options
	g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(options_action)); //make visible	
	g_signal_connect(options_action, "activate",  G_CALLBACK(options_callbk), window);
	
	GSimpleAction *delete_events_action;	
	delete_events_action=g_simple_action_new("delete",NULL); //action = app.event
	g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(delete_events_action)); //make visible	
	g_signal_connect_swapped(delete_events_action, "activate",  G_CALLBACK(delete_events_callbk), window);
	//g_signal_connect(delete_events_action, "activate",  G_CALLBACK(delete_events_callbk), calendar);
	
	GSimpleAction *new_event_action;	
	new_event_action=g_simple_action_new("new",NULL); //action = app.event
	g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(new_event_action)); //make visible	
	g_signal_connect_swapped(new_event_action, "activate",  G_CALLBACK(new_event_menu_callbk), window);
	
	
	GSimpleAction *gotoday_action;		
	gotoday_action=g_simple_action_new("gotoday",NULL); 
	g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(gotoday_action)); //make visible	
	g_signal_connect(gotoday_action, "activate",  G_CALLBACK(callbk_gotoday), window);
	
	GSimpleAction *action_read_events;		
	action_read_events=g_simple_action_new("read",NULL); 
	g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(action_read_events)); //make visible	
	g_signal_connect(action_read_events, "activate",  G_CALLBACK(callbk_read_events), window);
	
	
	GSimpleAction *about_action;	
	about_action=g_simple_action_new("about",NULL); //app.about
	g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(about_action)); //make visible	
	g_signal_connect_swapped(about_action, "activate",  G_CALLBACK(callbk_about), window);
	
	GSimpleAction *audio_action;		
	audio_action=g_simple_action_new("audio",NULL); 
	g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(audio_action)); //make visible	
	g_signal_connect(audio_action, "activate",  G_CALLBACK(audio_callbk), window);
	
	  
    box_pane1=gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
    gtk_box_pack_start(GTK_BOX(box_pane1),calendar,FALSE, FALSE, 2);
    gtk_box_pack_start(GTK_BOX(box_pane1),list,FALSE, FALSE, 2);
    
    box_pane2=gtk_box_new(GTK_ORIENTATION_VERTICAL,0);    
    gtk_box_pack_start(GTK_BOX(box_pane2),label_date,FALSE, FALSE, 5);
    //textview inside scrolled window
	gtk_box_pack_start(GTK_BOX(box_pane2),scrolled_window,TRUE, TRUE, 5);	
	
	paned = gtk_paned_new (GTK_ORIENTATION_HORIZONTAL);	
	gtk_paned_add1 (GTK_PANED (paned), box_pane1);
	gtk_paned_add2 (GTK_PANED (paned), box_pane2);
	
	//GtkAllocation allocation;
	//gtk_widget_get_allocation (window, &allocation);
    gtk_paned_set_position(GTK_PANED (paned), 450); //window 800x400
    
	gtk_container_add (GTK_CONTAINER (window), paned);	
	calendar_month_changed_callbk(GTK_CALENDAR(calendar),NULL);
	
	//call calendar day clicked directly at startup
	calendar_day_selected_callbk(GTK_CALENDAR(calendar), GTK_WINDOW(window));
	//mark_holidays_on_calendar(calendar);
	if(m_talk_at_startup) speak_events_at_date(GTK_CALENDAR(calendar));
	g_date_time_unref(dt); 
	//calendar_day_selected_callbk(calendar, list);
  //gtk_widget_show(calendar);
    
  gtk_widget_show_all (window);
  
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
