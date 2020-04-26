#ifndef _BASE_H_
#define _BASE_H_

#include "record.h"

// function prototypes

void add_a_record(Record[],int *count); // 1
int load_list(Record[]); // load from file.
void take_note(Record records[], int count); //2
void name_change(Record records[],int count); //3
void print_all_records(Record[],int *count); //4
void delete_note(Record records[],int count); //5
int delete_user(Record records[], int *count); //6
void search_note(Record records[], int count); //7
void save_information(Record records[], int count); // 9
void save_report(Record records[], int count); // 10
#endif
