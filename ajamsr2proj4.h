//Arvinbayar Jamsranjav
// CS 211 Project 4
// Fall 2019

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum {waiting = 0, callAhead = 1} orderStatus; 
typedef enum {FALSE = 0, TRUE, NO = 0, YES} boolean;

boolean debugMode;

typedef struct NODE
{
    char* name;
    int burgers;
    int salads;
    int groupSize;
    orderStatus status;
    struct NODE* Next;
}queue;

// in ajamsr2proj4_1.c file
// user interface functions
void clearToEoln ();
int getNextNWSChar ();
int getPosInt ();
char *getName();
void printCommands();

// in ajamsr2proj4_2.c file
// 
void doAdd (queue **hd);
void doCallAhead(queue **hd);
void doWaiting (queue **hd);
void doRetrieve (queue **hd);
void doList (queue **hd);
void doDisplay (queue **hd);
void doEstimateTime(queue **hd);

// in ajamsr2proj4_3.c file
// 
void addToList(queue **hd, char *name, int burgers, int salads, orderStatus status);
int doesNameExist(queue **hd, char *name);
boolean updateStatus(queue **hd, char* name);
void retrieveAndRemove(queue **hd, int burgers, int salads);
int countOrdersAhead(queue **hd, char *name);
int displayWaitingTime(queue**hd, char *name);
void displayOrdersAhead(queue **hd, int ordersCount);
void displayListInformation(queue**hd);