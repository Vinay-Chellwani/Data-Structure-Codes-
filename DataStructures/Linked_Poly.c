/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Linked_Poly.c
 * Author: VINAY CHELLWANI
 *
 * Created on November 11, 2017, 8:12 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct POLYNOMIAL {
    int coeff;
    int expo;
    struct POLYNOMIAL *next;
};
typedef struct POLYNOMIAL NODE;

void acceptNodeData (NODE* node);
 bool isListEmpty(NODE* start);
 NODE* multiply(NODE* poly1,NODE* poly2);
 NODE* multiterm(NODE* poly1,NODE* poly2);
 NODE* add(NODE* r3,NODE* temp);
 


NODE* createList(NODE *start) {
    NODE* newNode ; //used for creating new nodes
    NODE* ptr ; //used traversing the list

    
    newNode = (NODE*) malloc(sizeof ( NODE));
    
    if (newNode == NULL) {
        printf("\tInsufficient memory!!! new node cannot be created\n");
    } 
    else {
        //if allocation is successful accept data
        newNode->next = NULL;
        acceptNodeData (newNode);

        //check whether the list is empty
        if (isListEmpty(start)) { 
            start = newNode;
        } 
        else {
            //point ptr to the begining of the list
            ptr = start;
            //traverse to the end of the existing list
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            //add new node to the end of list
            ptr->next = newNode;
        }
    }
}
    void acceptNodeData (NODE* node) 
    {
    printf("\tEnter Coefficient : ");
    scanf("%d", &node->coeff);
    printf("\tEnter Exponent: ");
    scanf("%d", &node->expo);
    
    return;
}
   bool isListEmpty(NODE* start)
   {
       return start==NULL;       
   }
   void displayData(NODE* start)
   {
       if(isListEmpty(start))
           printf("NO LIST FOUND");
       else
       {
           do{
               printf("+(%d x^%d)",start->coeff,start->expo);
               start=start->next;
             }while(start!=NULL);
             
       }
   }
   NODE* multiply(NODE* poly1,NODE* poly2){
       NODE* temp;
       NODE* r3;
       r3=NULL;
       while(poly2!=NULL)
       {
           temp=multiterm(poly1,poly2);
           r3=add(r3,temp);
           poly2=poly2->next;
       }
       return r3;
   }
   
   NODE* multiterm(NODE* poly1,NODE* x){
       NODE* new;
       NODE* r1;
       new=NULL;
       while(poly1!=NULL)
       {
           if(new==NULL)
           {
               r1=new=(NODE*)malloc(sizeof(NODE));
               r1->next=NULL;
           }
           else
           {
               r1->next=(NODE*)malloc(sizeof(NODE));
               r1=r1->next;
               r1->next=NULL;
           }
           r1->coeff=poly1->coeff*x->coeff;
           r1->expo=poly1->expo+x->expo;
           poly1=poly1->next;
       }
    return new;   
   }
   NODE* add(NODE* poly1,NODE* poly2)
   {
       NODE* p3;
       NODE* r3;
       p3=NULL;
       while(poly1 !=NULL && poly2!=NULL)
       {
           if(p3==NULL)
           {
               p3=r3=(NODE*)malloc(sizeof(NODE));
               r3->next=NULL;
           }
           else
           {
               r3->next=(NODE*)malloc(sizeof(NODE));
               r3=r3->next;
               r3->next=NULL;
           }
           if(poly1->expo < poly2->expo)
           {
               r3->expo=poly1->expo;
               r3->coeff=poly1->coeff;
               poly1=poly1->next;
           }
           else if(poly1->expo > poly2->expo)
           {
               r3->expo=poly2->expo;
               r3->coeff=poly2->coeff;
               poly2=poly2->next;
           }
           else{
               r3->expo=poly1->expo;
               r3->coeff=poly1->coeff+poly2->coeff;
               poly1=poly1->next;
               poly2=poly2->next;
           }
       }
       
       while(poly1!=NULL)
       {
           if(p3==NULL)
           {
               p3=r3=(NODE*)malloc(sizeof(NODE));
               r3->next=NULL;
           }
           else
           {
               r3->next=(NODE*)malloc(sizeof(NODE));
               r3=r3->next;
               r3->next=NULL;
           }
           r3->expo=poly1->expo;
           r3->coeff=poly1->coeff;
           poly1=poly1->next;
       }
       while(poly2!=NULL)
       {
           if(p3==NULL)
           {
               p3=r3=(NODE*)malloc(sizeof(NODE));
               r3->next=NULL;
           }
           else
           {
               r3->next=(NODE*)malloc(sizeof(NODE));
               r3=r3->next;
               r3->next=NULL;
           }
           r3->expo=poly2->expo;
           r3->coeff=poly2->coeff;
           poly2=poly2->next;
       }
       return p3;
   }
/*
 * 
 */
int main() {
    int noOfTerms,i;
    NODE* start_1;
    NODE* start_2;
    NODE* mul;
    
    printf("Enter first polynomial");
    printf("\nEnter number of terms:");
    scanf("%d",&noOfTerms);
    for(i=0;i<noOfTerms;i++)
    {
        start_1=createList(start_1);
    }
    
    printf("Enter second polynomial");
    printf("\nEnter number of terms:");
    scanf("%d",&noOfTerms);
    for(i=0;i<noOfTerms;i++)
    {
        start_2=createList(start_2);
    }


    mul=multiply(start_1,start_2);
    displayData(mul);
    
}

