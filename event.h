/*
 * event.h
 */
#ifndef __EVENT_H__
#define __EVENT_H__

#define BUFLEN 100 /* total number of chars per line */
#define MAXEVENTS 100 /* total number of events */

/* macros for the command names */
#define CMD_HELP "help"
#define CMD_GOTO "goto"
#define CMD_LIST "list"
#define CMD_ADD  "add"
#define CMD_DEL  "delete"
#define CMD_QUIT "quit"


/* set current event number to eventNumber */
void GotoEvent(int eventNumber);

/* print eventNumber's event string, or all events' event strings if
 * -1
 */
void ListEvent(int eventNumber);

/* set the current event number's event string to evt if the current
 * event is not empty, or else report an error
 */
void AddEvent(char *evt);

/* if eventNumber is not -1, then delete the eventNumber's event
 * string (set to empty string); otherwise, delete the current event
 * number's event
 */
void DeleteEvent(int eventNumber);

/* print the help string */
void PrintHelp();

/* called once to initialize the array */
void InitTable();

/* prints the current event number and > */
void PrintPrompt();

#endif /* __EVENT_H__ */

