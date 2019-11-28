//Arvinbayar Jamsranjav
// CS 211 Project 4
// Fall 2019

#include "ajamsr2proj4.h"

// function that adds order to the list
// ...
// ...
void addToList(queue **hd, char *name, int burgers, int salads, orderStatus status)
{
    // filling the info
    queue *temp = (queue *)malloc(sizeof(queue));
    temp->Next = NULL;
    temp->name = name;
    temp->burgers = burgers;
    temp->salads = salads;
    if(status == waiting) {
        temp->status = waiting;
    }
    else {
        temp->status = callAhead;
    }
    // DEBUG printing
    if(debugMode == TRUE) {
        printf("\n*** DEBUG ***\n");
        printf("%s ordered %d burgers %d salads, status is ",temp->name,temp->burgers,temp->salads);
        if(status == waiting) {
            printf("waiting\n");
        }
        else {
            printf("call-ahead\n");
        }
        printf("*** END ***\n");
    }
    
    // if there is no order yet
    if(*hd == NULL) {
        *hd = temp;
        return;
    }
    
    // put the order at the end
    else {
        queue *temp1 = *hd;
        while(temp1->Next != NULL) {
            temp1 = temp1->Next;
        }
        temp1->Next = temp;
        return;
    }
    return;
}

// check the orders list if that name exists or not
// if yes then return 1
// ...
int doesNameExist(queue **hd, char *name) 
{
    queue *temp = *hd;
    // if there is no order yet
    if(temp == NULL) {
        return 0;
    }
    // seaching through the order list
    while(temp != NULL) {
        if(strcmp(temp->name, name) == 0) {
            return 1;
        }
        temp = temp->Next;
    }
    return 0;
}

// function that changes call-ahead orders to waiting
// ...
// ...
boolean updateStatus(queue **hd, char* name) 
{
    queue *temp = *hd;
    // if there is no order yet
    if(temp == NULL) {
        return FALSE;
    }
    
    // if that order is call-ahead change to waiting
    // and return TRUE
    while(temp != NULL) {
        if(strcmp(temp->name, name) == 0) {
            if(temp->status == waiting) {
                return FALSE;
            }
            else {
                temp->status = waiting;
                if(debugMode == TRUE) {
                    printf("\n*** DEBUG ***\nORDERS AFTER MODIFICATIONS\n");
                    displayListInformation(hd);
                    printf("*** END ***\n");
                }
                return TRUE;
            }
        }
        temp = temp->Next; 
    }
    return FALSE;
}

// restaurant makes some num of burgers and salads and hands to the customer
// erase customers who had less # of items of items than prepared
// ...
void retrieveAndRemove(queue **hd, int burgers, int salads)
{
    queue *temp = *hd;
    queue *temp1;
    // if there is no order yet
    if(temp == NULL) {
        printf("No orders\n");
        return;
    }
    // checking first order
    if(temp->status == waiting && temp->burgers <= burgers && temp->salads <= salads) {
        *hd = (*hd)->Next;
        printf("Order made by %s has been erased.\n", temp->name);
        if(debugMode == TRUE) {
            printf("\n*** DEBUG ***\nORDERS AFTER MODIFICATIONS\n");
            displayListInformation(hd);
            printf("*** END ***\n");
        }
        free(temp);
        return;
    }
    // checking all the rest
    // if find then we done with the customer
    while(temp->Next != NULL) {
        if(temp->Next->status == waiting && temp->Next->burgers <= burgers && 
           temp->Next->salads <= salads) {
            printf("Order made by %s has been erased.\n", temp->Next->name);
            temp1 = temp->Next;
            temp->Next = temp1->Next;
            free(temp1);
            // debug print
            if(debugMode == TRUE) {
                printf("\n*** DEBUG ***\nORDERS AFTER MODIFICATIONS\n");
                displayListInformation(hd);
                printf("*** END ***\n");
            }
            return;
        }
        temp = temp->Next;
    }
    // print statement that says do more FOOD !!!
    printf("Prepared burgers and salads are too few.\n");
    if(debugMode == TRUE) {
        printf("\n*** DEBUG ***\nNo modifications needed\n");
        printf("*** END ***\n");  
    }
   
}

// function that counts how many orders are in front
// of that particular customer
// ...
int countOrdersAhead(queue **hd, char *name)
{
    queue *temp = *hd;
    int orderCount = 0;
    // if there is no order yet
    if(temp == NULL) {
        return 0;
    }
    // add till find the correct customer
    while (temp != NULL) {
        if(strcmp(temp->name,name) == 0) {
            return orderCount;
        }
        orderCount++;
        temp = temp->Next;
    }
}

// function that used to print how many minutes the customer
// need to wait in order to get a food
// ...
int displayWaitingTime(queue**hd, char *name)
{
    queue *temp = *hd;
    int waitingTime = 0;
    // if there is no order yet
    if(temp == NULL) {
        return 0;
    }
    
    // add waitingtime for prev orders till the particular customer
    while(temp != NULL) {
        if(strcmp(temp->name,name) == 0) {
            return waitingTime;
        }
        else {
            waitingTime += ((temp->burgers)*10 + (temp->salads)*5);
        }
        temp = temp->Next;
    }
    return -1;
}

// function that helps to display all the orders 
// in front of the particular customer
// ...
void displayOrdersAhead(queue **hd, int ordersCount) 
{
    queue *temp = *hd;
    int alreadyCounted = 0;
    int i;
    // if there is no order yet
    if(temp == NULL) {
        return;
    }
    // print for the first customer
    if(ordersCount == 0) {
        printf("No orders ahead\n");
        return;
    }
    // if not the first one then print all the orders ahead
    else {
        for(i =0; i < ordersCount;i++) {
            if(debugMode == TRUE) {
                printf("*** Debugging info *** %s, %d burgers and %d salads, status is ",temp->name,temp->burgers, temp->salads);
                if(temp->status == waiting) {
                    printf("waiting\n");
                }
                else {
                    printf("call-ahead\n");
                }   
            }
        printf("%s ordered %d burgers and %d salads\n", temp->name, temp->burgers, temp->salads);
        temp = temp->Next;
        }
    }
    return;
}

// display all the orders 
// ...
// ...
void displayListInformation(queue **hd)
{
    int i = 0;
    queue *temp = *hd;
    // if there is no order yet
    if(temp == NULL) {
        printf("No orders\n");
        return;
    }
    
    while(temp != NULL) {
        // debug printing
        if(debugMode == TRUE) {
            printf("*** Debugging info *** %s, %d burgers and %d salads, status is ",temp->name,temp->burgers, temp->salads);
            if(temp->status == waiting) {
                printf("waiting\n");
            }
            else {
                printf("call-ahead\n");
            }   
        }
        
        printf("%s ordered %d burgers and %d salads, status is ", temp->name, temp->burgers, temp->salads);
        if(temp->status == waiting) {
            printf("waiting");
        }
        else {
            printf("call-ahead");
        }
        printf("\n");
        temp = temp->Next;
        i++;
    }
    printf("Total number of orders: %d\n", i);
    return;
}