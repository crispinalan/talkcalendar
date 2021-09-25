/***************************************************************************
 * GPL v2.0 license (see license document distributed with this software)
 * SQlite db manager 
 * Author: crispinalan@gmail.com
 ***************************************************************************/


#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
#include "dbmanager.h"

#define CONFIG_DIRNAME "talkcalendar-v1-4"

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i < argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

void remove_apostrophes(char* str)
{    
    int from, to;       
    for (from = 0, to = 0; str[from] != '\0'; ++from) {
        if (!(str[from] == '\'')) {
            str[to] = str[from];
            ++to;
        }
    }
    str[to] = '\0';
}


//-------------------------------------------------------------------
// Create Events table
//-------------------------------------------------------------------

void db_create_events_table() {
  
sqlite3 *db;
char *zErrMsg = NULL;
int rc=0;
char *sql;

	gchar * config_dir = g_build_filename(g_get_user_config_dir(), CONFIG_DIRNAME, NULL);
	if(!g_file_test(config_dir, G_FILE_TEST_IS_DIR))
	g_mkdir(config_dir, 0777); //create if does not exist
	gchar *path = g_strconcat(config_dir, "/calendar.db", NULL);
	rc = sqlite3_open(path, &db);

   if(rc) {
      //printf("Can't open database: %s\n", sqlite3_errmsg(db));
      return;
   } else {
      //printf("Opened database successfully\n");
   }
     
  sql = "CREATE TABLE EVENTS("\
        "ID 				INTEGER PRIMARY KEY AUTOINCREMENT,"\
        "TITLE      		TEXT,"\
        "PRIORITY      		INT,"\
        "DESCRIPTION        TEXT,"\
        "YEAR            	INT,"\
        "MONTH            	INT,"\
        "DAY            	INT,"\
        "STARTHOUR      	INT,"\
        "STARTMIN       	INT,"\
        "ENDHOUR      		INT,"\
        "ENDMIN       		INT,"\
        "ISYEARLY     		INT,"\
        "ISALLDAY        	INT);" ;
        
      
   //printf("Execute sql to create tables\n"); 

/* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   
   if(rc != SQLITE_OK){
      //printf("Sql1 message: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      //printf(" Events table created successfully\n");
   }
      
   sqlite3_close(db); 
  
}

//---------------------------------------------------------------------
// Insert Event (import)
//---------------------------------------------------------------------
 
void db_insert_event_struct(Event event) {

//int insert_id=0;
char *title= event.title;
int priority =event.priority;
char *description = event.description;
int year =event.year;
int month =event.month;
int day =event.day;
int start_hour =event.startHour;
int start_min =event.startMin;
int end_hour =event.endHour;
int end_min = event.endMin;
int is_yearly = event.isYearly;
int is_allday=event.isAllday;

sqlite3 *db;
int rc=0;
char sql_query[2048] = ""; //string on the stack (not heap)
sqlite3_stmt *stmt;

/* Open database */
   gchar * config_dir = g_build_filename(g_get_user_config_dir(), CONFIG_DIRNAME, NULL);
	if(!g_file_test(config_dir, G_FILE_TEST_IS_DIR))
	g_mkdir(config_dir, 0777); //create if does not exist
	gchar *path = g_strconcat(config_dir, "/calendar.db", NULL);
	rc = sqlite3_open(path, &db);
   
   if(rc) {
      //printf("Can't open database: %s\n", sqlite3_errmsg(db));
      return;
   } else {
      //printf("Opened database successfully\n");
   }


sprintf(sql_query, "INSERT INTO EVENTS (TITLE,PRIORITY,DESCRIPTION,YEAR, MONTH, DAY,STARTHOUR,STARTMIN,ENDHOUR,ENDMIN,ISYEARLY,ISALLDAY)\
VALUES  ('%s',%d,'%s',%d,%d,%d,%d,%d,%d,%d,%d,%d);",
        title,priority,description,year,month,day,start_hour,start_min,end_hour,end_min,is_yearly,is_allday);

//printf("sql = %s\n",sql_query);
//printf("Length of sql1 =%d\n",strlen(sql_query));

// Prepare the query
if (sqlite3_prepare_v2(db, sql_query, -1, &stmt, NULL) != SQLITE_OK){
     //printf("SQL get events prepare error: %s\n", sqlite3_errmsg(db));
}

rc = sqlite3_step(stmt); 
sqlite3_finalize(stmt);  // Finialize the usage
sqlite3_close(db);
	
}


//---------------------------------------------------------------------
// Insert Event pointer
//---------------------------------------------------------------------
 
int db_insert_event(Event *event) {
	
int insert_id=0;
char *title= event->title;
int priority =event->priority;
char *description = event->description;
int year =event->year;
int month =event->month;
int day =event->day;
int start_hour =event->startHour;
int start_min =event->startMin;
int end_hour =event->endHour;
int end_min = event->endMin;
int is_yearly = event->isYearly;
int is_allday=event->isAllday;

remove_apostrophes(title); //clean to prevent sql crash
remove_apostrophes(description);

//printf("dbInsert: title = %s\n",title);
//printf("dbInsert: description = %s\n",description);
//printf("dbInsert: priority = %d\n",priority);
//printf("dbInsert: start_hour = %d\n", start_hour);
//printf("dbInsert: start_min = %d\n",start_min);
 
sqlite3 *db;
int rc=0;
char sql_query[2048] = ""; //string on the stack (not heap)
 //Use statement to prevent injection errors  
sqlite3_stmt *stmt;

/* Open database */
    gchar * config_dir = g_build_filename(g_get_user_config_dir(), CONFIG_DIRNAME, NULL);
	if(!g_file_test(config_dir, G_FILE_TEST_IS_DIR))
	g_mkdir(config_dir, 0777); //create if does not exist
	gchar *path = g_strconcat(config_dir, "/calendar.db", NULL);
	rc = sqlite3_open(path, &db);
   
   if(rc) {
      //printf("Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   } else {
      //printf("Opened database successfully\n");
   }

sprintf(sql_query, "INSERT INTO EVENTS (TITLE,PRIORITY,DESCRIPTION,YEAR, MONTH, DAY,STARTHOUR,STARTMIN,ENDHOUR,ENDMIN,ISYEARLY,ISALLDAY)\
VALUES  ('%s',%d,'%s',%d,%d,%d,%d,%d,%d,%d,%d,%d);",
        title,priority,description,year,month,day,start_hour,start_min,end_hour,end_min,is_yearly,is_allday);

//printf("sql = %s\n",sql_query);
//printf("Length of sql_query =%d\n",strlen(sql_query));

// Prepare the query
//printf("Preparing the insert query..\n");
if (sqlite3_prepare_v2(db, sql_query, -1, &stmt, NULL) != SQLITE_OK){
     //printf("SQL get events prepare error: %s\n", sqlite3_errmsg(db));
}

rc = sqlite3_step(stmt); // execute (step) insert
sqlite3_finalize(stmt);  // finialize insert query
insert_id = sqlite3_last_insert_rowid(db);
//printf("insert id = %d\n",insert_id);
sqlite3_close(db); //close db
return insert_id;
}  



//--------------------------------------------------------------------
// Update event
//---------------------------------------------------------------------

void db_update_event(Event *event){

int idx=event->id;
char *title= event->title;
int priority =event->priority;
char *description = event->description;
int start_hour =event->startHour;
int start_min =event->startMin;
int end_hour =event->endHour;
int end_min = event->endMin;
int is_yearly = event->isYearly;
int is_allday=event->isAllday;

remove_apostrophes(title); //clean to prevent sql crash
remove_apostrophes(description);

sqlite3 *db;
int rc=0;
sqlite3_stmt *stmt;
char query[2048] = "";


  /* Open database */
    gchar * config_dir = g_build_filename(g_get_user_config_dir(), CONFIG_DIRNAME, NULL);
	if(!g_file_test(config_dir, G_FILE_TEST_IS_DIR))
	g_mkdir(config_dir, 0777); //create if does not exist
	gchar *path = g_strconcat(config_dir, "/calendar.db", NULL);
	rc = sqlite3_open(path, &db);
   
   if(rc) {
      //printf("Can't open database: %s\n", sqlite3_errmsg(db));
      return;
   } else {
      //printf("Opened database successfully\n");
   }


sprintf(query, "UPDATE EVENTS SET TITLE ='%s',PRIORITY =%i, DESCRIPTION='%s',\
        STARTHOUR=%i, STARTMIN=%i, ENDHOUR=%i, ENDMIN=%i, ISYEARLY=%i, ISALLDAY=%i\
        WHERE ID ='%i'", title,priority,description,start_hour,start_min,end_hour,end_min,is_yearly,is_allday,idx);
       

// Prepare the query
rc = sqlite3_prepare_v2(db, query, -1, &stmt, NULL);
if (rc != SQLITE_OK) {
  // error handling -> statement not prepared
  //printf("SQL prepare error: %s\n", sqlite3_errmsg(db));
}

 rc = sqlite3_step(stmt); // execute (step) insert
 sqlite3_finalize(stmt);// finialize
 
sqlite3_close(db);  	
}


//-------------------------------------------------------------------
// Get number of rows all events
//-------------------------------------------------------------------
int db_get_number_of_rows_all() {
//printf("Get number of  db rows all\n");
sqlite3 *db;
int rc=0;
int row_count=0;
sqlite3_stmt *stmt;
char sql[200] = "";

/* Open database */
  gchar * config_dir = g_build_filename(g_get_user_config_dir(), CONFIG_DIRNAME, NULL);
	if(!g_file_test(config_dir, G_FILE_TEST_IS_DIR))
	g_mkdir(config_dir, 0777); //create if does not exist
	gchar *path = g_strconcat(config_dir, "/calendar.db", NULL);
	rc = sqlite3_open(path, &db);
   
   if(rc) {
      //printf("Can't open database: %s\n", sqlite3_errmsg(db));
      return 0;
   } else {
      //printf("Opened database successfully\n");
   }

sprintf(sql, "SELECT Count(*) FROM EVENTS"); 
//printf("sql = %s\n",sql);

rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
if (rc != SQLITE_OK) {
  // error handling -> statement not prepared
  //printf("SQL prepare error: %s\n", sqlite3_errmsg(db));
}
rc = sqlite3_step(stmt);
if (rc != SQLITE_ROW) {
  // error handling -> no rows returned, or an error occurred
 // printf("SQL return no rows");
  return 0;
}
row_count = sqlite3_column_int(stmt, 0);

sqlite3_finalize(stmt);  
sqlite3_close(db); 
return row_count;
}

//-----------------------------------------------------------------
// Get number of rows year month
//-----------------------------------------------------------------

int db_get_number_of_rows_month_year(int month, int year) {

sqlite3 *db;
int rc=0;
int row_count=0;
sqlite3_stmt *stmt;
char sql[200] = "";

/* Open database */
    gchar * config_dir = g_build_filename(g_get_user_config_dir(), CONFIG_DIRNAME, NULL);
	if(!g_file_test(config_dir, G_FILE_TEST_IS_DIR))
	g_mkdir(config_dir, 0777); //create if does not exist
	gchar *path = g_strconcat(config_dir, "/calendar.db", NULL);
	rc = sqlite3_open(path, &db);
   
   if(rc) {
      //printf("Can't open database: %s\n", sqlite3_errmsg(db));
      return 0;
   } else {
      //printf("Opened database successfully\n");
   }

sprintf(sql, "SELECT Count(*) FROM EVENTS WHERE YEAR = '%i' AND MONTH = '%i'", year, month); 
//printf("sql = %s\n",sql);


rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
if (rc != SQLITE_OK) {
  // error handling -> statement not prepared
  //printf("SQL prepare error: %s\n", sqlite3_errmsg(db));
}
rc = sqlite3_step(stmt);
if (rc != SQLITE_ROW) {
  // error handling -> no rows returned, or an error occurred
  return 0;
}
row_count = sqlite3_column_int(stmt, 0);
sqlite3_finalize(stmt);  
sqlite3_close(db); 
return row_count; 
	
}

//-----------------------------------------------------------------
// Get number of rows year month
//-----------------------------------------------------------------

int db_get_number_of_isyearly_events_month(int month) {

sqlite3 *db;
int rc=0;
int row_count=0;
sqlite3_stmt *stmt;
char sql[200] = "";

/* Open database */
    gchar * config_dir = g_build_filename(g_get_user_config_dir(), CONFIG_DIRNAME, NULL);
	if(!g_file_test(config_dir, G_FILE_TEST_IS_DIR))
	g_mkdir(config_dir, 0777); //create if does not exist
	gchar *path = g_strconcat(config_dir, "/calendar.db", NULL);
	rc = sqlite3_open(path, &db);
   
   if(rc) {
      //printf("Can't open database: %s\n", sqlite3_errmsg(db));
      return 0;
   } else {
      //printf("Opened database successfully\n");
   }

sprintf(sql, "SELECT Count(*) FROM EVENTS WHERE MONTH = '%i' AND ISYEARLY = '%i'", month,1); 
//printf("sql = %s\n",sql);

rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
if (rc != SQLITE_OK) {
  // error handling -> statement not prepared
  //printf("SQL prepare error: %s\n", sqlite3_errmsg(db));
}
rc = sqlite3_step(stmt);
if (rc != SQLITE_ROW) {
  // error handling -> no rows returned, or an error occurred
  return 0;
}
row_count = sqlite3_column_int(stmt, 0);
sqlite3_finalize(stmt);  
sqlite3_close(db); 
return row_count; 
	
}

//-------------------------------------------------------------------
// Get MONTH isYearly events
//-------------------------------------------------------------------


void db_get_isyearly_events_month(Event *event_buff, int month, int count) {
	

sqlite3 *db;
int rc=0;
sqlite3_stmt *stmt;
char sql[2048] = "";


/* Open database */
   gchar * config_dir = g_build_filename(g_get_user_config_dir(), CONFIG_DIRNAME, NULL);
	if(!g_file_test(config_dir, G_FILE_TEST_IS_DIR))
	g_mkdir(config_dir, 0777); //create if does not exist
	gchar *path = g_strconcat(config_dir, "/calendar.db", NULL);
	rc = sqlite3_open(path, &db);
   
   if(rc) {
      //printf("Can't open database: %s\n", sqlite3_errmsg(db));
      return;
   } else {
      //printf("Opened database successfully\n");
   }


sprintf(sql, "SELECT * FROM EVENTS WHERE MONTH = '%i' AND ISYEARLY = '%i'", month, 1);


if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK){

     printf("SQL get events prepare error: %s\n", sqlite3_errmsg(db));
     return;
}

int i=0;
while (sqlite3_step(stmt) == SQLITE_ROW) {
Event e;	
e.id = sqlite3_column_int(stmt, 0);  
const char *title =sqlite3_column_text(stmt, 1);
strcpy(e.title,title);
int priority =sqlite3_column_int(stmt, 2);
e.priority=priority;
const char *description =sqlite3_column_text(stmt, 3);
strcpy(e.description,description);
e.year = sqlite3_column_int(stmt, 4);
e.month = sqlite3_column_int(stmt, 5);
e.day =sqlite3_column_int(stmt, 6);		
e.startHour = sqlite3_column_int(stmt, 7);
e.startMin = sqlite3_column_int(stmt, 8);	
e.endHour = sqlite3_column_int(stmt, 9);
e.endMin = sqlite3_column_int(stmt, 10);
e.isYearly = sqlite3_column_int(stmt, 11);
e.isAllday=sqlite3_column_int(stmt, 12);
event_buff[i]=e;
i=i+1;	 
}
    
sqlite3_finalize(stmt);
sqlite3_close(db); 
}	




//----------------------------------------------------------------
// Get number of rows YEAR MONTH DAY
//-----------------------------------------------------------------

int db_get_number_of_rows_year_month_day(int year, int month, int day) {

sqlite3 *db;
int rc=0;
int row_count=0;
sqlite3_stmt *stmt;
char sql[200] = "";

/* Open database */
    gchar * config_dir = g_build_filename(g_get_user_config_dir(), CONFIG_DIRNAME, NULL);
	if(!g_file_test(config_dir, G_FILE_TEST_IS_DIR))
	g_mkdir(config_dir, 0777); //create if does not exist
	gchar *path = g_strconcat(config_dir, "/calendar.db", NULL);
	rc = sqlite3_open(path, &db);
   
   if(rc) {
      //printf("Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   } else {
      //printf("Opened database successfully\n");
   }

sprintf(sql, "SELECT Count(*) FROM EVENTS WHERE YEAR = '%i' AND MONTH = '%i' AND DAY = '%i'", year, month, day); 


rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
if (rc != SQLITE_OK) {
  // error handling -> statement not prepared
  //printf("SQL prepare error: %s\n", sqlite3_errmsg(db));
  return 0;
}
rc = sqlite3_step(stmt);
if (rc != SQLITE_ROW) {
  // error handling -> no rows returned, or an error occurred
  return 0;
}
row_count = sqlite3_column_int(stmt, 0);
sqlite3_finalize(stmt);  
sqlite3_close(db); 
return row_count; 	
}

//-------------------------------------------------------------------
// Get Event
//-------------------------------------------------------------------

void db_get_event(int index, Event *event){


sqlite3 *db;
int rc=0;
sqlite3_stmt *stmt;
char sql[2048] = "";

/* Open database */
   gchar * config_dir = g_build_filename(g_get_user_config_dir(), CONFIG_DIRNAME, NULL);
	if(!g_file_test(config_dir, G_FILE_TEST_IS_DIR))
	g_mkdir(config_dir, 0777); //create if does not exist
	gchar *path = g_strconcat(config_dir, "/calendar.db", NULL);
	rc = sqlite3_open(path, &db);
   
   if(rc) {
      //printf("Can't open database: %s\n", sqlite3_errmsg(db));
      return;
   } else {
      //printf("Opened database successfully\n");
   }

sprintf(sql, "SELECT * FROM EVENTS WHERE ID = %i", index);

if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK){
     //printf("SQL get events prepare error: %s\n", sqlite3_errmsg(db));
}

rc = sqlite3_step(stmt); // execute statement (query.first?)

int id = sqlite3_column_int(stmt, 0);  
const char *title =sqlite3_column_text(stmt, 1);
int priority =sqlite3_column_int(stmt, 2);
const char *description =sqlite3_column_text(stmt, 3);
int year = sqlite3_column_int(stmt, 4);
int month = sqlite3_column_int(stmt, 5);
int day =sqlite3_column_int(stmt, 6);  
int startHour = sqlite3_column_int(stmt, 7);
int startMin = sqlite3_column_int(stmt, 8);  
int endHour = sqlite3_column_int(stmt,9);
int endMin = sqlite3_column_int(stmt, 10); 
int isYearly = sqlite3_column_int(stmt, 11);   
int isAllday=sqlite3_column_int(stmt, 12);

//*event is the parameter
event->id =id;
strcpy(event->title,title);  
event->priority=priority;   
strcpy(event->description,description); 
event->year=year;
event->month =month;
event->day=day;
event->startHour=startHour;
event->startMin=startMin;
event->endHour=endHour;
event->endMin=endMin;
event->isYearly=isYearly;
event->isAllday=isAllday;

sqlite3_finalize(stmt); 
sqlite3_close(db);  
}
	
//-------------------------------------------------------------------
// Get all events 
//-------------------------------------------------------------------
void db_get_all_events(Event *event_buff, int count) {

sqlite3 *db;
int rc=0;
sqlite3_stmt *stmt;
char sql[2048] = "";
/* Open database */
   gchar * config_dir = g_build_filename(g_get_user_config_dir(), CONFIG_DIRNAME, NULL);
	if(!g_file_test(config_dir, G_FILE_TEST_IS_DIR))
	g_mkdir(config_dir, 0777); //create if does not exist
	gchar *path = g_strconcat(config_dir, "/calendar.db", NULL);
	rc = sqlite3_open(path, &db); 
   if(rc) {
      //printf("Can't open database: %s\n", sqlite3_errmsg(db));
      return;
   } else {
      //printf("Opened database successfully\n");
   }

sprintf(sql, "SELECT * FROM EVENTS LIMIT %i", count);

if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK){
     //printf("SQL get events prepare error: %s\n", sqlite3_errmsg(db));
}

int i=0;

while (sqlite3_step(stmt) == SQLITE_ROW) {
Event e;	
e.id = sqlite3_column_int(stmt, 0);  
const char *title =sqlite3_column_text(stmt, 1);
strcpy(e.title,title);
int priority =sqlite3_column_int(stmt, 2);
e.priority=priority;
const char *description =sqlite3_column_text(stmt, 3);
strcpy(e.description,description);
e.year = sqlite3_column_int(stmt, 4);
e.month = sqlite3_column_int(stmt, 5);
e.day =sqlite3_column_int(stmt, 6);		
e.startHour = sqlite3_column_int(stmt, 7);
e.startMin = sqlite3_column_int(stmt, 8);	
e.endHour = sqlite3_column_int(stmt, 9);
e.endMin = sqlite3_column_int(stmt, 10);
e.isYearly = sqlite3_column_int(stmt, 11);
e.isAllday=sqlite3_column_int(stmt, 12);

event_buff[i]=e;
i=i+1;	 
}   
sqlite3_finalize(stmt);
sqlite3_close(db); 
}	

//-------------------------------------------------------------------
// Get all events YEAR MONTH 
//-------------------------------------------------------------------


void db_get_all_events_year_month(Event *event_buff, int year, int month, int count) {
	

sqlite3 *db;
int rc=0;
sqlite3_stmt *stmt;
char sql[2048] = "";


/* Open database */
   gchar * config_dir = g_build_filename(g_get_user_config_dir(), CONFIG_DIRNAME, NULL);
	if(!g_file_test(config_dir, G_FILE_TEST_IS_DIR))
	g_mkdir(config_dir, 0777); //create if does not exist
	gchar *path = g_strconcat(config_dir, "/calendar.db", NULL);
	rc = sqlite3_open(path, &db);
   
   if(rc) {
      //printf("Can't open database: %s\n", sqlite3_errmsg(db));
      return;
   } else {
      //printf("Opened database successfully\n");
   }


sprintf(sql, "SELECT * FROM EVENTS WHERE YEAR = '%i' AND MONTH = '%i' LIMIT '%i'", year, month, count);

if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK){

     //printf("SQL get events prepare error: %s\n", sqlite3_errmsg(db));
}

int i=0;
while (sqlite3_step(stmt) == SQLITE_ROW) {
Event e;	
e.id = sqlite3_column_int(stmt, 0);  
const char *title =sqlite3_column_text(stmt, 1);
strcpy(e.title,title);
int priority =sqlite3_column_int(stmt, 2);
e.priority=priority;
const char *description =sqlite3_column_text(stmt, 3);
strcpy(e.description,description);
e.year = sqlite3_column_int(stmt, 4);
e.month = sqlite3_column_int(stmt, 5);
e.day =sqlite3_column_int(stmt, 6);		
e.startHour = sqlite3_column_int(stmt, 7);
e.startMin = sqlite3_column_int(stmt, 8);	
e.endHour = sqlite3_column_int(stmt, 9);
e.endMin = sqlite3_column_int(stmt, 10);
e.isYearly = sqlite3_column_int(stmt, 11);
e.isAllday=sqlite3_column_int(stmt, 12);
event_buff[i]=e;
i=i+1;	 
}
    
sqlite3_finalize(stmt);
sqlite3_close(db); 
}	

//-------------------------------------------------------------------
// Get all events YEAR MONTH DAY
//-------------------------------------------------------------------

void db_get_all_events_year_month_day(Event *event_buff, int year, int month, int day, int count) {

sqlite3 *db;
int rc=0;
sqlite3_stmt *stmt;
char sql[2048] = "";


/* Open database */
  gchar * config_dir = g_build_filename(g_get_user_config_dir(), CONFIG_DIRNAME, NULL);
	if(!g_file_test(config_dir, G_FILE_TEST_IS_DIR))
	g_mkdir(config_dir, 0777); //create if does not exist
	gchar *path = g_strconcat(config_dir, "/calendar.db", NULL);
	rc = sqlite3_open(path, &db);   
   if(rc) {
      //printf("Can't open database: %s\n", sqlite3_errmsg(db));
      return;
   } else {
      //printf("Opened database successfully\n");
   }

sprintf(sql, "SELECT * FROM EVENTS WHERE YEAR = '%i' AND MONTH = '%i' AND DAY = '%i' ORDER BY STARTHOUR, STARTMIN asc LIMIT '%i'", year, month, day, count);

if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK){
     //printf("SQL get events prepare error: %s\n", sqlite3_errmsg(db));
}

int i=0;
while (sqlite3_step(stmt) == SQLITE_ROW) {
Event e;	
e.id = sqlite3_column_int(stmt, 0);  
const  char *title =sqlite3_column_text(stmt, 1);
strcpy(e.title,title);
int priority =sqlite3_column_int(stmt, 2);
e.priority=priority;
const char *description =sqlite3_column_text(stmt, 3);
strcpy(e.description,description);
e.year = sqlite3_column_int(stmt, 4);
e.month = sqlite3_column_int(stmt, 5);
e.day =sqlite3_column_int(stmt, 6);		
e.startHour = sqlite3_column_int(stmt, 7);
e.startMin = sqlite3_column_int(stmt, 8);	
e.endHour = sqlite3_column_int(stmt, 9);
e.endMin = sqlite3_column_int(stmt, 10);
e.isYearly = sqlite3_column_int(stmt, 11);
e.isAllday=sqlite3_column_int(stmt, 12);
event_buff[i]=e;
i=i+1;	 
}
    
sqlite3_finalize(stmt);
sqlite3_close(db);  
}	

//-------------------------------------------------------------------
// Delete row (single event)
//-------------------------------------------------------------------		
void db_delete_row(int id){
 
//printf("Delete row  %d\n", id);

sqlite3 *db;
int rc=0;
sqlite3_stmt *stmt;
char sql[2048] = "";

/* Open database */
    gchar * config_dir = g_build_filename(g_get_user_config_dir(), CONFIG_DIRNAME, NULL);
	if(!g_file_test(config_dir, G_FILE_TEST_IS_DIR))
	g_mkdir(config_dir, 0777); //create if does not exist
	gchar *path = g_strconcat(config_dir, "/calendar.db", NULL);
	rc = sqlite3_open(path, &db);
   
   if(rc) {
      //printf("Can't open database: %s\n", sqlite3_errmsg(db));
      return;
   } else {
     // printf("Opened database successfully\n");
   }

sprintf(sql, "DELETE FROM EVENTS WHERE ID=%i", id);

if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK){
     //printf("SQL get events prepare error: %s\n", sqlite3_errmsg(db));
}

rc = sqlite3_step(stmt);
sqlite3_finalize(stmt);
sqlite3_close(db);
}
//------------------------------------------------------------------
// Delete all events
//------------------------------------------------------------------
void db_delete_all(){

sqlite3 *db;
int rc=0;
sqlite3_stmt *stmt;
char sql[2048] = "";

/* Open database */
    gchar * config_dir = g_build_filename(g_get_user_config_dir(), CONFIG_DIRNAME, NULL);
	if(!g_file_test(config_dir, G_FILE_TEST_IS_DIR))
	g_mkdir(config_dir, 0777); //create if does not exist
	gchar *path = g_strconcat(config_dir, "/calendar.db", NULL);
	rc = sqlite3_open(path, &db);
   
   if(rc) {
      //printf("Can't open database: %s\n", sqlite3_errmsg(db));
      return;
   } else {
      //printf("Opened database successfully\n");
   }

	sprintf(sql, "DELETE FROM EVENTS");	

	if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK){
	//printf("SQL get events prepare error: %s\n", sqlite3_errmsg(db));
	}

	rc = sqlite3_step(stmt);
	sqlite3_finalize(stmt);
	sqlite3_close(db); 
}

//---------------------------------------------------------------------
// Reset sequence
//----------------------------------------------------------------------

void db_reset_sequence(){

sqlite3 *db;
int rc=0;
sqlite3_stmt *stmt;
char sql[2048] = "";

/* Open database */
    gchar * config_dir = g_build_filename(g_get_user_config_dir(), CONFIG_DIRNAME, NULL);
	if(!g_file_test(config_dir, G_FILE_TEST_IS_DIR))
	g_mkdir(config_dir, 0777); //create if does not exist
	gchar *path = g_strconcat(config_dir, "/calendar.db", NULL);
	rc = sqlite3_open(path, &db);
   
   if(rc) {
      //printf("Can't open database: %s\n", sqlite3_errmsg(db));
      return;
   } else {
      //printf("Opened database successfully\n");
   }

	sprintf(sql, "DELETE FROM SQLITE_SEQUENCE WHERE NAME= 'EVENTS'");
	

	if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK){
	//printf("SQL get events prepare error: %s\n", sqlite3_errmsg(db));
	}

	rc = sqlite3_step(stmt);
	sqlite3_finalize(stmt);
	sqlite3_close(db);  
}

