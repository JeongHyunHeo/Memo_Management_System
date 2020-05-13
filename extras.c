#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "extras.h"
#include "base.h"

void multiple_search(Record records[], int count) {
  
    char name[30];
    char date[20];
    int note_count;
    int selection = 0;
    int check;
    int i;
    
    printf("Enter number of field for search(1~3): ");
    scanf("%d", &selection);

    if (selection == 1) {
      search_note(records, count);
      return;
    }
    else if (selection == 2) {
      printf("2 field");
    }
    else if (selection == 3) {
      printf("Enter a user name: ");
      scanf("%s", name);
      printf("Enter date: ");
      scanf("%s", date);
      printf("Enter note count: ");
      scanf("%d", &note_count);

      for (i = 0; i < count; i++) {
        if(!strcmp(records[i].user_name, name) && !strcmp(records[i].written_date, date) 
        && records[i].note_count == note_count){
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
    }
    else {
      printf("No");
    }
    getchar();

  return;
}

// Function: defragment()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: 1 if successful, otherwise 0
// - Leave a brief information about the function
int defragment(Record records[], int *count){
  // defragment + extra3 (delete multiple users)
	// TODO: Modify this function as you need
  int num = 0, idx = 0;
  int store_count = *count;
	printf("How many users do you want to delete? ");
  scanf("%d",&num);

  int *idx_arr = (int*)malloc(sizeof(int)*num);
  char **p = (char**)malloc(sizeof(char*) * num);
  for(int i = 0 ; i < num; i++){
     p[i] = (char*)malloc(sizeof(char) * 30 );
  }
  for(int i = 0 ; i < num; i++){
    printf("Enter the user name to be deleted : ");
    scanf("%s",p[i]);
  }
  for(int i = 0 ; i < *count ;i++){
    for(int j = 0 ; j < num; j++){
      if(strcmp(records[i].user_name, p[j]) == 0){
        idx_arr[idx++] = i; 
        break;
      }
    }
  }
  int k = 0;
  if(num == idx){
    for(int i = 0 ; i < *count; i++){
      if(i == idx_arr[k]){
        for(int j = i+1; j < *count; j++){
          strncpy(records[j-k-1].user_name,records[j-k].user_name,sizeof(records[j-k].user_name));
          strncpy(records[j-k-1].written_date,records[j-k].written_date,sizeof(records[j-k].written_date));
          strncpy(records[j-k-1].user_content,records[j-k].user_content,sizeof(records[j-k].user_content));
          records[j-k-1].note_count = records[j-k].note_count;
        }
        k++;
      }
    }
    for(int z = *count-idx; z < *count; z++){
      strncpy(records[z].user_name," ",sizeof(" "));
      strncpy(records[z].written_date," ",sizeof(" "));
      strncpy(records[z].user_content," ",sizeof(" "));
      records[z].note_count = 0;
    }
    *count = *count - num;
  }
  for(int i = 0 ; i < 3; i++){
    free(p[i]);
  }
  free(p);
  free(idx_arr);
  getchar();
  
  // num (entered value) idx (the number of entered correctly)
  if(store_count != *count && num == idx ){
    printf("They has been completely deleted.\n");
    return 1;
  }else{
    printf("Deletion failed by entering a user that does not exist.\n");
    return 0;
  }	// TODO: return 1 if defragment succeed; return 0 otherwise 
}


// Function: add_a_record()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Leave a brief information about the function
void display_stats(Record records[], int count){
	// TODO: Modify this function as you need
  printf("---------------------------------------------\n");
  printf("|              Total Statistics              |\n");
  printf("---------------------------------------------\n");
  printf("|    Name    | Last updated date | NumofNote |\n");
  printf("---------------------------------------------\n");
	for(int i = 0 ; i < count; i++){
    printf("| %-11s |    %-10s    |     %d     |\n",records[i].user_name,records[i].written_date,records[i].note_count);
  }
  printf("---------------------------------------------\n");
}
// TODO: Add more functions to fulfill the optional requirements

//extra credit function
void rank(Record records[], int count){
  Record* new_user[1000];
  for(int i = 0 ; i<count; i++){
    new_user[i] = (Record*)malloc(sizeof(Record));
    strcpy(new_user[i]->user_name,records[i].user_name);
    strcpy(new_user[i]->written_date,records[i].written_date);
    strcpy(new_user[i]->user_content,records[i].user_content);
    new_user[i]->note_count = records[i].note_count;
  }// copy
  int min;
  for(int i = 0 ; i <count; i++){
    min = i;
    for(int j = i; j < count; j++){
      if(new_user[i]->note_count < new_user[j]->note_count){
        min = j;
      }
    }
    if(min != i){
        char tmp[30];
        strcpy(tmp,new_user[i]->user_name);
        if(strlen(new_user[i]->user_name) > strlen(new_user[min]->user_name)){
          strncpy(new_user[i]->user_name,new_user[min]->user_name,sizeof(new_user[min]->user_name));
        }else{
          strncpy(new_user[i]->user_name,new_user[min]->user_name,sizeof(new_user[i]->user_name));
        }
        strncpy(new_user[min]->user_name,tmp,sizeof(tmp));
        // name change

        int temp = new_user[i]->note_count;
        new_user[i]->note_count = new_user[min]->note_count;
        new_user[min]->note_count = temp;
        //count change
      }
  }
  printf("***************RANK***************\n");
  printf("(Sort the number of modified notes)\n");
  for(int i = 0; i<count; i++){
    printf("%d. USER NAME: %s, The number of revised note: %d\n",i+1,new_user[i]->user_name, new_user[i]->note_count);
  }
  for(int i = 0; i < count; i++){
    free(new_user[i]);
  }
}

void categories(Record records[], int count){
  int cnt[26] = {0};
  int CNT[26] = {0};

  for(int i = 0 ; i < count ; i++){
    if((int)(records[i].user_name[0]) >= 97 && (int)(records[i].user_name[0]) <= 122 ){
      cnt[(int)(records[i].user_name[0])-97] += 1;
    }else if((int)(records[i].user_name[0]) >= 65 && (records[i].user_name[0]) <= 90 ){
      CNT[(int)(records[i].user_name[0])-65] += 1;
    }
  }
  printf("*********<Category by Username>*********\n");
  for(int i = 0 ; i < 26; i++){
    if(cnt[i] != 0){
      printf("[Collection of names starting with \"%c\"] \n",i+97);
      for(int j = 0; j < count; j++){
        if((char)(i+97) == records[j].user_name[0]){
          printf("%s %s %s \n",records[j].user_name, records[j].written_date,records[j].user_content);
        }
      }
    }
  }
  for(int i = 0 ; i < 26; i++){
    if(CNT[i] != 0){
      printf("[Collection of names starting with \"%c\"] \n",i+65);
      for(int j = 0; j < count; j++){
        if((char)(i+65) == records[j].user_name[0]){
          printf("%s %s %s \n",records[j].user_name, records[j].written_date,records[j].user_content);
        }
      }
    }
  }
  printf("***************************************\n");
}
