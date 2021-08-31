/***************************************************************************
 * dbmanager.h
 * SQlite db manager 
 * Author: crispinalan@gmail.com
 ***************************************************************************/


#ifndef DBMANAGER_H
#define DBMANAGER_H

#include "event.h"


void db_create_events_table();
int db_insert_event(Event *event);
void db_insert_event_struct(Event event);
void db_update_event(Event *event);

void db_get_event(int index, Event *event);

int db_get_number_of_rows_all();
int db_get_number_of_rows_month_year(int month, int year);
int db_get_number_of_rows_year_month_day(int year, int month, int day);
int db_get_number_of_isyearly_events_month(int month);


int db_get_number_of_rows_less_than(int year, int month, int day);


void db_get_all_events(Event *event_buff, int count);
void db_get_all_events_year_month(Event *event_buff, int year, int month, int count);
void db_get_isyearly_events_month(Event *event_buff, int month, int count);
void db_get_all_events_year_month_day(Event *event_buff, int year, int month, int day, int count);

void db_delete_row(int id);
void db_delete_all();
void db_reset_sequence();



#endif // DBMANAGER_H
