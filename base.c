#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "base.h"

// Function: print_all_records()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Leave a brief information about the function
void print_all_records(Record records[],int *count){
	// TODO: Modify this function as you need
	for(int i = 0 ; i< *count; i++){
    printf("Name: %s\n",records[i].user_name);
    printf("Date: %s\n",records[i].written_date);
    printf("<Note Contents>\n");
    printf("%s \n\n",records[i].user_content);
  }
}


// Function: add_a_record()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Leave a brief information about the function
void add_a_record(Record records[],int *count){
	// TODO: Modify this function as you need
	char str[10];
    
  printf("Would you like to add user? (Yes/No)");
  scanf("%s",str);
    
  if(strcmp(str,"Yes") == 0){
    while(1){
      printf("Enter a new user name : ");
      scanf("%s",records[*count].user_name);
      if((records[*count].user_name[0] >= 'A' && records[*count].user_name[0] <= 'Z') || (records[*count].user_name[0] >= 'a' && records[*count].user_name[0] <= 'z')){
        break;
      }else{  
        printf("The first letter must be letter !\n");
      }
    }
    printf("User is added !\n");
    strcpy(records[*count].written_date,"No_date");
    strcpy(records[*count].user_content,"No contents");
    *count = *count + 1;

    FILE *p = fopen("User.txt","wt");
    if(p == NULL){printf("Error is take placed on the process FILE to open !");exit(0);}
    else{
      for(int i = 0 ; i < *count; i++){
        if(i == *count-1){
          fprintf(p,"%s %s %s",records[i].user_name,records[i].written_date,records[i].user_content);
        }else{
          fprintf(p,"%s %s %s\n",records[i].user_name,records[i].written_date,records[i].user_content);
        }
      }
      fclose(p);
    }
  }else if(strcmp(str,"No") == 0){
    printf("Okey !\n");
  }
  getchar();
}

// TODO: Add more functions to fulfill the requirements

// Read the entire data from filesystem
int load_list(Record records[]){ // User information list
    int i = 0;
//    int c_count = 0;
    FILE *fp = fopen("User.txt","r");
    
    if(fp == NULL) {printf("Error is take placed on the process FILE to open !");exit(0);}
    else{
        for(i = 0;; i++){
          if(feof(fp)){
             break;
          }else{
            fscanf(fp,"%s %s %[^\n]s",records[i].user_name,records[i].written_date,records[i].user_content);
            records[i].note_count += 1;
          }
        }
    }
    // if you run in the Linux, you have to -1 to variable of i // i--;
    // In the process of reading the file, variable of i is counted in User_list + 1 in Linux.
    fclose(fp);
    return i;
}

// Create a new data record from a data file
void take_note(Record records[], int count){ // 2
    char name[30];
    char c[10]; // check
    int check = 0;
    int i;
    
    printf("Are you sure you want to edit the note? (Yes/No): ");
    scanf("%s",c);

  if(strncmp(c,"Yes",strlen(c)) == 0){
    printf("Enter a user name: ");
    scanf("%s",name);
    for(i = 0 ; i<count; i++){
        if(strcmp(records[i].user_name,name) == 0){
            check = 1;
            break;
        }
    }
    if(check == 1){
      FILE *p = fopen("User.txt","wt");
        printf("Confirmed !\n");
        printf("Enter the contents: ");
        scanf(" %[^\n]s ",records[i].user_content);
        printf("Enter a date (Form: 2020/04/02): ");
        scanf("%s",records[i].written_date);
        printf("The contents is entered in note !\n");
        records[i].note_count += 1;
        for(int j = 0 ; j < count; j++){
          if(j == count-1){
            fprintf(p,"%s %s %s",records[j].user_name,records[j].written_date,records[j].user_content);
          }else{
            fprintf(p,"%s %s %s\n",records[j].user_name,records[j].written_date,records[j].user_content);
          }
        }
        fclose(p);
    }else if(check == 0){
        printf("It is not registered.\n");
    }
  }
  getchar();
}

// (update !)
void name_change(Record records[],int count){
  char name[30];
  char new_name[30];
  int check = 0, i = 0;
  printf("Enter an existing user name: ");
  scanf("%s",name);

  for(i = 0 ; i < count ;i++){
    if(strcmp(records[i].user_name,name) == 0){
      check = 1;
      break;
    }
  }
  if(check == 1){
    printf("Enter the name you want to change:");
    scanf("%s",new_name);
    strncpy(records[i].user_name,new_name,strlen(new_name));
    printf("The name is changed !\n");

    FILE *p = fopen("User.txt","wt");
    for(int j = 0 ; j < count; j++){
      if(j == count-1){
        fprintf(p,"%s %s %s",records[j].user_name,records[j].written_date,records[j].user_content);
      }else{
        fprintf(p,"%s %s %s\n",records[j].user_name,records[j].written_date,records[j].user_content);
      }
    }
    fclose(p);
  }else{
    printf("The user doesn't exist.\n");
  }
  getchar();
}
void delete_note(Record records[],int count){
    char name[30];
    int i, check = 0;
    printf("Enter a user name to delete the note: ");
    scanf("%s",name);
    
    for(i = 0; i < count; i++){
        if(strcmp(records[i].user_name, name) == 0){
            check = 1;
            break;
        }
    }
    if(check == 1){
        strcpy(records[i].user_content,"No contents"); // reset
        strcpy(records[i].written_date,"No_date");
        printf("The contents of note is deleted !\n");
    }else{
        printf("User does't exist.\n");
    }
    getchar();
}

int delete_user(Record records[], int *count){
    char name[30];
    int i = 0 , check = 0;
    
    printf("Enter a user name to delete: ");
    scanf("%s",name);
    
    for(i = 0 ; i<*count; i++){
        if(strcmp(records[i].user_name, name) == 0){
            check = 1;
            break;
        }
    }
    
    if(check == 1){
      for(int k = i+1 ; k < *count; k++){
        strncpy(records[k-1].user_name,records[k].user_name,sizeof(records[k].user_name));
        strncpy(records[k-1].written_date,records[k].written_date,sizeof(records[k].written_date));
        strncpy(records[k-1].user_content,records[k].user_content,sizeof(records[k].user_content));
        if(k == *count-1){
          strncpy(records[k].user_name,"",sizeof(""));
          strncpy(records[k].written_date,"",sizeof(""));
          strncpy(records[k].user_content,"",sizeof(""));
        }
      }
      *count = *count -1;
        FILE *p = fopen("User.txt", "wt");
        for(int j = 0; j < *count; j++){
          if(j == *(count)-1){
            fprintf(p,"%s %s %s", records[j].user_name,records[j].written_date,records[j].user_content);
          }else{
            fprintf(p,"%s %s %s\n", records[j].user_name, records[j].written_date,records[j].user_content);
          }
        }
        printf("User is removed !\n");
        fclose(p);
        p = fopen("User.txt","rt");
        for(int j = 0; j < *count; j++){
            fscanf(p, "%s %s %[^\n]s\n",records[j].user_name,records[j].written_date,records[j].user_content);
        }
        fclose(p);
    }else{
        printf("The user doesn't exist !\n");
    }
    getchar();
    return *count;
}

void search_note(Record records[], int count){
    char name[30];
    int i = 0 , check = 0;
    printf("Enter a user name: ");
    scanf("%s",name);
    
    for(i = 0 ; i<count; i++){
        if(strcmp(records[i].user_name, name) == 0){
            check = 1;
            break;
        }
    }
    if(check == 1){
        printf("The date: %s\n",records[i].written_date);
        printf("The content of note <%s>: \n",records[i].user_name);
        printf("%s\n",records[i].user_content);
    }else{
        printf("The user doesn't exist !\n");
    }
    getchar();
}

void save_information(Record records[], int count){
    FILE *p = fopen("User.txt","wt");
    
    if(p == NULL) printf("Error is take placed on the process FILE to open !");
    else{
        for(int i = 0 ; i<count ; i++){
          if(i == count-1){
            fprintf(p,"%s %s %s",records[i].user_name, records[i].written_date,records[i].user_content);
          }else{
            fprintf(p,"%s %s %s\n",records[i].user_name, records[i].written_date,records[i].user_content);
          }
        }
        printf("The contents is saved ! \n");
    }
    fclose(p);
}

void save_report(Record records[], int count){
    FILE *p = fopen("Report.txt","wt");
    char c[10];
    
    if(p == NULL) {printf("Error is take placed on the process FILE to open !");
    }else{
        fprintf(p,"*************REPORT*************\n");
        fprintf(p,"Total the number of USER is %d\n",count);
        fprintf(p,"      <USER NICKNAME LIST>      \n");
        for(int i = 0 ; i < count; i ++){
          fprintf(p,"USER NAME: %s, The number of note: %d\n",records[i].user_name,records[i].note_count);
        }
        fprintf(p,"*******************************");
        fclose(p);
    }
    
    printf("Do you wanna show the report ? (Yes/No): ");
    scanf("%s",c);
    
    if(strcmp(c,"Yes") == 0 ){
        printf("\n*************REPORT*************\n");
        printf("Total the number of USER is %d\n",count);
        printf("      <USER NICKNAME LIST>      \n");
        for(int i = 0 ; i<count; i++){
            printf("USER NAME: %s, The number of revised note: %d\n",records[i].user_name,records[i].note_count);
        }
        printf("*******************************\n");
    }
    getchar();
}

