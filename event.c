#include <stdio.h>
#include <string.h>
#include "event.h"

static int CurrentEvent=0;
static char A[MAXEVENTS][BUFLEN];
const char *noPtr="(no event)\n";
/* print the help string */
void PrintHelp(){
    printf("goto n    : go to event #n\n");
    printf("list [n]  : list events #n, or current event if n is not specified\n");
    printf("add evt   : add description to current event number\n");
    printf("delete [n]: delete event #n, or current event if n is not provided\n");
    printf("quit      : exit the program\n");
    printf("help      : shows this command list\n");
}

/* called once to initialize the array */
void InitTable(){
    int i;
    /*set "(no event)\n" to event from 1 to MAXEVENTS*/
    for(i=0; i<MAXEVENTS; i++){
        strcpy(A[i], noPtr);
    }
}

/* prints the current event number and > */
void PrintPrompt(){
    printf("%d> ", CurrentEvent);
}

/* set current event number to eventNumber */
void GotoEvent(int eventNumber){
    /*check eventNumber range between 1 and MAXEVENTS*/
    if(eventNumber>0&&eventNumber<=MAXEVENTS){
        CurrentEvent=eventNumber;
    }
    else
    printf("Event number %d is invalid.\n"
           "Please input eventNumber between 1~%d\n", eventNumber, MAXEVENTS);
}

/* print eventNumber's event string, or all events' event strings if
 * -1
 */
void ListEvent(int eventNumber){
   /*check eventNumber range between 1 and MAXEVENTS, or no input*/
   if(eventNumber>=-1&&
       eventNumber!=0&&
       eventNumber<=MAXEVENTS){

        /*no eventNumber input, list all schedules without empty*/
        if(eventNumber==-1){
            int i;
            for(i=0; i<MAXEVENTS; i++){
                if(strcmp(A[i], noPtr)!=0){
                    printf(" %d: %s", i+1, A[i]);
                }
            }
        }
        /*list schedule of eventNumber*/
        else
            printf(" %d: %s", eventNumber, A[eventNumber-1]);

    }
    else
        printf("event #%d is out of range\n", eventNumber);
}

/* set the current event number's event string to evt if the current
 * event is not empty, or else report an error
 */
void AddEvent(char *evt){
    if(CurrentEvent>0&&CurrentEvent<=MAXEVENTS){
        /*CurrentEvent is empty*/
        if(!strcmp(A[CurrentEvent-1], noPtr)){
            /*copy strings into A[CurrentEvent-1]*/
            strcpy(A[CurrentEvent-1], evt);
        }
        else
            printf("Event number #%d exists.  Event not added.\n", CurrentEvent);
    }
    else
        printf("Event number %d is invalid.\n"
               "Please goto eventNumber between 1~%d\n", CurrentEvent, MAXEVENTS);

}

/* if eventNumber is not -1, then delete the eventNumber's event
 * string (set to empty string); otherwise, delete the current event
 * number's event
 */
void DeleteEvent(int eventNumber){
    /*check eventNumber range between 1 and MAXEVENTS, or no input*/
    if(eventNumber>=-1&&
       eventNumber!=0&&
       eventNumber<=MAXEVENTS){
        /*eventNumber=-1, represents no input, check CurrentEvent*/
        if(eventNumber==-1){
            if(CurrentEvent==0)
                 printf("event #%d is out of range\n", CurrentEvent);
            else if(strcmp(A[CurrentEvent-1], noPtr)==0){
                printf("event #%d empty\n", CurrentEvent);
            }
            else
                sprintf(A[CurrentEvent-1] ,noPtr);
        }

        /*eventNumber!=-1, check eventNumber*/
        else{
            if(strcmp(A[eventNumber-1], noPtr)==0){
                printf("event #%d empty\n", eventNumber);
            }
            else
                sprintf(A[eventNumber-1] ,noPtr);
        }
    }

    else
        printf("event #%d is out of range\n", eventNumber);
}
