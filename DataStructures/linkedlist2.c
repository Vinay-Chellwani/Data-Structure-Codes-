
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
 
 struct student{
    int roll;
    float marks;
 char   name[50];
    struct student* next;    
};
typedef struct student NODE;
int displaymenu();
void acceptdata(NODE* ptr){
    printf("\t\t\tENTER ROLL NO:");
    scanf("%d",&ptr->roll);
    printf("\t\t\tENTER MARKS:");
    scanf("%f",&ptr->marks);
    printf("\t\t\tENTER NAME:");
    scanf("%s",ptr->name);
    ptr->next=NULL;
    
}
bool isListEmpty(NODE * start) {
    return (start == NULL);
}
void display(NODE *ptr) {
    if (isListEmpty(ptr)) {
        printf("\tThe list is empty!!\n");
    } else { 
        printf("\n\t**** List of Students *****\n");
       
       
        while (ptr != NULL) {
            
            printf("\tROLL NO: %d\t NAME:%s\n", ptr->roll, ptr->name);
            ptr = ptr->next; 
        }
    }
    return;
}




NODE* update(NODE* start)
{
    NODE* ptr;
    NODE* newnode;
    newnode=(NODE*)malloc(sizeof(NODE));
    if(newnode!=NULL)
      acceptdata(newnode);
    else
      fprintf(stderr,"Insufficient memory! Unable to create Node");
    ptr=start;
    if(start==NULL)
    {
       start=newnode; 
    }
    else{
        
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=newnode;
    }
    return start;
}

NODE* delete(NODE *start, int rollno) {
    NODE *ptr; 
    NODE *temp; 
    ptr=start;
    
    if (isListEmpty(start)) {
        printf("\tList is not Existing !\n");
        return NULL;
    }
    ptr = start;
   
    while (ptr->roll != rollno && ptr != NULL) {
        temp = ptr;
        ptr = ptr->next;
        
    }
    if (ptr == NULL) {
        printf("\tPosition out of the list\n");
    } else {
        if (rollno == 1) 
        {
            start = ptr->next;
        } else {
            temp->next = ptr->next;
        }
         printf("Record of Roll No %d is deleted",rollno);
        free(ptr);
    }
    return start;
}


void insertNode(NODE *start) {
    NODE *newNode;
    NODE *ptr;
    int r;
    if (isListEmpty(start)) { 
        printf("\tList is  Empty! \n");
        printf("\tPlease create the list first \n");
        return;
    }

    printf("\tAfter which Roll No. you would like to insert the new node: ");
    scanf("%i", &r);
    ptr = start;
    while (ptr != NULL && ptr->roll != r) {
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        printf("\tRoll No %d is not found\n", r);
    } else {
        newNode = (NODE*) malloc(sizeof ( NODE));
        if (newNode == NULL) {
            printf("\tInsufficient memory!!\n");
        } else {
            acceptdata(newNode);
            newNode->next = ptr->next;
            ptr->next = newNode;
        }
    }
    return;
}




NODE* reverse(NODE *start) {
    NODE *ptr;
    NODE *temp;
    NODE *ptr1;
    if (isListEmpty(start)) {
        printf("\tThe list is empty\n");
    }
    else { 
        ptr = start;  
        temp = ptr->next;  
        ptr->next = NULL; 
        while (temp != NULL) {
            ptr1 = temp->next;
            temp->next = ptr;
            ptr = temp;
            temp = ptr1;
        }
        start = ptr;
    }
    return start;
}
NODE * move(NODE* start, int i) {
    NODE *ptr = NULL;
    if (!isListEmpty(start)) {
        if (i > 0) {
            ptr = start;
            while (i > 1) {
                ptr = ptr->next;
                i--;
            }
        }
    }
    return ptr;
}
int countNodes(NODE *ptr) {
    int count = 0;
    if (isListEmpty(ptr)) {
        printf("\tThe List is empty!!\n");
    } else {
        while (ptr != NULL) {
            count++;
            ptr = ptr->next;
        }
    }
    return count;
}
NODE* sort(NODE *start) {
    NODE *ptr1;
    NODE *temp1;
    NODE *ptr2;
    NODE *temp2;
    int i;
    int j;
    int no_nodes;

    if (isListEmpty(start)) {
        printf("\tThe list is empty\n");
    } else {
        no_nodes = countNodes(start);

        for (i = 2; i <= no_nodes; i++) {
            ptr1 = move(start, i); 
            temp1 = move(start, i - 1);
            for (j = 1; j < i; j++) { 
                ptr2 = move(start, j); 
                temp2 = move(start, j - 1);
                if (ptr1->roll < ptr2->roll) {
                    temp1->next = ptr1->next;
                    ptr1->next = ptr2;
                    if (ptr2 == start) {
                        start = ptr1;
                    } else {
                        temp2->next = ptr1;
                    }
                    break;  
                }
            } 
        } 
    }
    return start;
}
/*
 * 
 */
int main(int argc, char** argv) {
    int ch,roll1;
    NODE* start=NULL;
    do{
      ch=displaymenu();
      switch(ch)
      {
          case 1:start=update(start);
                 break;
          case 2:printf("Enter roll no to delete:");
                 scanf("%d",&roll1);
                 start=delete(start,roll1);
                 break;
          case 3:insertNode(start);
                 break;
          case 4:start=sort(start);
                 break;
          case 5:start=reverse(start);
                 break;
          case 6:display(start);
                 break;
          case 7:exit(EXIT_SUCCESS);
          default:fprintf(stderr,"Wrong selection");
                    break;
            
      }
    }while(ch!=8);
    
    

    return (EXIT_SUCCESS);
}

int displaymenu(){
    int ch;
    printf("\n\t1.Create list or update/append list");
    printf("\n\t2.Delete by roll no");
    printf("\n\t3.Insert after specific roll no");
    printf("\n\t4.Sort list by roll no");
    printf("\n\t5.Reverse the list");
    printf("\n\t6.Display list");
    printf("\n\t7.Exit");
    printf("\n\nPlease enter your choice");
    do{
    scanf("%d",&ch);
    if(ch>0 && ch<8)
        break;
    
    }while(1);
    return ch;
}
