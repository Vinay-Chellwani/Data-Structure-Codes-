#include <stdio.h>
#include <stdlib.h>
#include "SingleLinearList.h"
#include "stdbool.h"

#define CREATE_LIST 1
#define DISPLAY_LIST 2
#define INSERT_AFTER_ROLL_NO 3
#define INSERT_BY_POSITION 4
#define DELETE_BY_POSTION 5
#define DELETE_BY_NAME 6
#define REVERSE_LIST 7
#define COUNT_NODES 8
#define SORT_LIST 9
#define EXIT_CHOICE 10

int displayMenuChoice(void);

int main() {
    //initialize the list to be empty
    NODE *start = NULL;
    char nameToDelete[MAX_NAME_LENGTH];
    int choice;
    int position;

    do {
        choice = displayMenuChoice();
        switch (choice) {
            case CREATE_LIST:
                start = createList(start);
                break;
            case DISPLAY_LIST:
                displayList(start);
                break;
            case INSERT_AFTER_ROLL_NO:
                insertNode(start);
                break;
            case INSERT_BY_POSITION:
                printf("\tPlease enter the position number ");
                scanf("%i", &position);
                start = insertNodeByPosition(start, position);
                break;
            case DELETE_BY_POSTION:
                printf("\tEnter position of the node to be deleted : ");
                scanf("%i", &position);
                start = deleteNodeByPosition(start, position);
                break;
            case DELETE_BY_NAME:
                printf("\tEnter the name of the student to be deleted : ");
                //    while (getchar() != 10); //clear input stream
                fgets(nameToDelete, MAX_NAME_LENGTH, stdin);
                start = deleteNodeByName(start, nameToDelete);
                break;
            case REVERSE_LIST:
                start = reverseList(start);
                printf("\tThe list has been reversed\n");
                break;
            case COUNT_NODES:
                printf("\tNumber of nodes = %d\n", countNodes(start));
                break;
            case SORT_LIST:
                start = sort(start);
                printf("\tThe list has been sorted\n");
                break;
            case EXIT_CHOICE:
                printf("\tFinished with list operations !!\n ");
                break;
            default:
                printf("\n\tIncorrect choice !!! \n");
        }
        printf("\tPress Enter key to continue");
        while (getchar() != '\n');
        getchar();
        system("clear");
    } while (choice != EXIT_CHOICE);
    return EXIT_SUCCESS;
}

int displayMenuChoice(void) {
    int choice;
    bool isScanSuccessful = false;
    do {
        printf("\n\t**** OPERATIONS ON SINGLE LINKED LIST  ****\n");
        printf("\t%d] Create List or Append the List\n", CREATE_LIST);
        printf("\t%d] Display  List \n", DISPLAY_LIST);
        printf("\t3] Insert node in the List (after specified Roll No)\n");
        printf("\t4] Insert node By Position \n");
        printf("\t5] Delete node from the List ( By Position )\n");
        printf("\t6] Delete node from the List ( By Name )\n");
        printf("\t7] Reverse List \n");
        printf("\t8] Count Nodes in the List \n");
        printf("\t9] Sort the list(After Creation)\n");
        printf("\t10] Exit\n");
        printf("\n\tPlease enter your choice (1/2/3/4/5/6/7/8/9/10 ): ");
        isScanSuccessful = scanf("%i", &choice);
        while (getchar() != '\n'); //clear stdin

    } while (!isScanSuccessful);
    return choice;
}