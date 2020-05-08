
#Mini Project: <Memo_Management_System>

***

Purpose: To manage it easy to store and view important information
Recommender: This program that is managed by the administrator serves to store each of the information about the user, manage stored the contents in the database, and show the statistical materials. The manager can use the function (= creating the user, deleting the user, editing the note, finding the user by searching, changing the username, showing each of the statistic materials, storing the data, etc..) if the manager think that this functions will be very useful, I hope the program will be used. 

***

##Function
***
###Create
Create: Create a new data record from a data file	*add_a_record (+load_list)
Create: Create a new record from the standard input	*take_note (+load_list)	

###Read

Read: According to user specified conditions, print a record, multiple or all records to the standard output *search_note		
Read: Read/write the entire data from/to filesystem	*load_list, *save_information		
Read: Export the entire data in a report format as a .txt file	*Save_report		

###Update

Update: Update a specific field of a record, multiple or all records *name_change	

###Delete
Delete: Delete a record, multiple or all records	*delete_note, *delete_user	

###Extra

Extra: Perform a data defragmentation	defragment	
Extra: Arrange (sort) the order of data records	rank	
Extra: delete multiple users	defragment	
Extra: display statistics	display_stats	
Extra: category username	categories		
***
