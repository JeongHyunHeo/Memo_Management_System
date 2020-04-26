#ifndef _RECORD_H_
#define _RECORD_H_
#define MAX_SIZE 1000
// type defition
typedef struct{
	char user_name[30];
  char user_content[MAX_SIZE];
  char written_date[20]; 
  int note_count;
	// TODO: define your own structure type here.
} Record;

#endif
