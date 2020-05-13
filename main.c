#include <stdio.h>
#include <string.h>
#include "base.h"
#include "extras.h"
#include "record.h"

#define MAX_RECORDS 1000

// function prototypes
void input_handler(char user_input[], Record[],int *count);
void display_menu();

// main function
int main(){

	Record records[MAX_RECORDS];
	char user_input[64]="";
  int count = load_list(records);
  //printf("%d",count); // ()
	while(strcmp(user_input,"99") != 0){
		display_menu();
		printf("\nSelect a menu> ");
		fgets(user_input,64,stdin);
    user_input[strlen(user_input)-1] = '\0'; 
		input_handler(user_input, records,&count);
	}

	return 0;
}


// Function: input_handler()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Handles the user input and invokes functions that correspond to the user input
void input_handler(char input[], Record records[],int *count){
  
	// TODO: Modify this function as you need

  if(!strcmp(input,"1"))
    add_a_record(records,count);
  else if(!strcmp(input,"2"))
    take_note(records,*count);
  else if(!strcmp(input,"3"))
    name_change(records, *count);
  else if(!strcmp(input,"4"))
    print_all_records(records,count);	
  else if(!strcmp(input,"5"))
    delete_note(records,*count);
  else if(!strcmp(input,"6"))
    *count = delete_user(records,count);
  else if(!strcmp(input,"7"))
    search_note(records,*count);
  else if(!strcmp(input,"8"))
    rank(records,*count);
  else if(!strcmp(input,"9"))
    save_information(records,*count);
  else if(!strcmp(input,"10"))
    save_report(records,*count);
  else if(!strcmp(input,"11"))
    defragment(records,count);
  else if(!strcmp(input,"12"))
    display_stats(records,*count);
  else if(!strcmp(input,"13"))
    categories(records,*count);
  else if (!strcmp(input,"14"))
    multiple_search(records, *count);
  else if(!strcmp(input,"99"))
    printf("Terminating... bye!\n"); // Quit - no operation (an empty statement with a semi-colon)
  else
    printf("Unknown menu: %s \n\n", input);
}



// Function: display_menu()
// Input: none
// Output: none
// - Leave a brief information about the function
void display_menu(){

	// TODO: Modify this function as you need

	printf("\n********************************\n");
    printf("**** Memo Management System ****\n");
    printf("********************************\n");
    printf("1. Add a new member\n");
    printf("2. Taking notes (Edit note)\n");
    printf("3. Update after name change\n");
    printf("4. Print all member and contents\n");
    printf("5. Delete written note\n");
    printf("6. Delete a member\n");
    printf("7. Search written note through username\n");
    printf("8. Sort note taking rank\n");
    printf("9. Save to the all information file\n");
    printf("10. Save to a report file\n");
    printf("11. Delete multiple users(+defragment)\n");
    printf("12. Show the total statistics\n");
    printf("13. Category by Username\n");
    printf("14. Multiple Search\n");
    printf("99. Exit\n\n");
}





