#ifndef _EXTRAS_H_
#define _EXTRAS_H_

#include "record.h"

// function prototypes
// delete multiple users (+extra)
int defragment(Record[], int *count); 
void display_stats(Record[],int count);
void rank(Record records[], int count);
void categories(Record records[],int count);
void multiple_search(Record records[], int count);
#endif
