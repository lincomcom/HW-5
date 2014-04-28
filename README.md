HW-5
====

schedule list

For this assignment, write a simple events management program.
It should use a simple command-line interface and implement simple functions for adding, deleting, listing, and goto an event. It should use an array data structure for storing events in the form of text strings. The commands are as follows. (note: [ ] indicates an optional argument to the command)
•	goto n: sets the current event number to n. n must be in the range of 0..MAXEVENTS-1.
•	list [n]: list the event text of entry n if n is provided; if omitted, list all events entered.
•	add evt: add the evt (which is a text string) to the current event entry. But if the current entry has already been entered, then it should report an error for duplicate entry.
•	delete [n]: delete event entry #n if it is not empty. If n is not provided, then delete the current entry. In either case, if it is empty, then an error message should be printed saying that the entry (with the event number) is empty, and that nothing is deleted.
•	quit: exits the program
•	help: shows the list of commands.
