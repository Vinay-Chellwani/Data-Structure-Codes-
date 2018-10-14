/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   stack challenge.c
 * Author: VINAY CHELLWANI
 *
 * Created on November 15, 2017, 8:37 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char string[50];
struct node
{
    int p;
    char s[MAX];
};
struct stack
{
  struct node a[MAX];
  int top;
}*sp;

void push(struct node data)
{
  if((sp->top)==MAX-1)
    cout<<"Stack overflow";
  else
  {
    (sp->top)++;
    (sp->a[sp->top]).p=data.p;
    strcpy((sp->a[sp->top]).s,data.s);
  }  
}
struct node pop()
{
  struct node c;
  if(sp->top==-1)
    printf("Stack underflow");
  else
    {c.p=(sp->a[sp->top]).p;
     strcpy(c.s,sp->a[sp->top].s);
     sp->top--;}
 return c;
}
void append()
{
    printf("Enter the string:");
    scanf("%s",string);
    strcat(s->str,string);
}

int menu(){
   
    int ch;
    printf("\n\t\t TEXT EDITOR\n****************");
    printf("\n\t1.Append string");
    printf("\n\t2.Delete k characters");
    printf("\n\t3.Print kth character");
    printf("\n\t4.Undo");
    printf("\n\t5.Exit");
    printf("\n\t\tPlease enter the choice");
    scanf("%d",&ch);
    return ch;
}

/*
 * 
 */
int main() {
    int choice;
     STACK s;
    do{
        choice=menu();
        switch(choice)
        {
            case 1:append(s);
                    break;
            case 2:printf("\n\t\t\tEnter number of elements to be deleted");
                   scanf("%d",&k);
                   delete(string,k);
                   break;
            case 3:printf("\n\t\t\tEnter the element number to be displayed");
                    scanf("%d",&k);
                    for(i=0;i<=k;i++);
                    printf("%c",&string[k]);
                    break;
            case 4:printf("\n\t\t\tThe previous result is:");
                   undo();
                   break;
            case 5:exit(EXIT_SUCCESS);
            default:fprintf(stderr,"INVALID SELECTION");
        }
    }while(choice!=5);
    

    
      
    return (EXIT_SUCCESS);
}

