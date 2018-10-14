


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   airport.c
 * Author: VINAY CHELLWANI
 *
 * Created on October 24, 2017, 9:43 PM
 */

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define MAX 3
#define EMPTY_INDICATOR -99999999


typedef struct
{
    int data[MAX];
    int front;
    int rear;
    int count;
     
}QUEUE;
    QUEUE runway1;
    QUEUE runway2;
    QUEUE takeoff;
    QUEUE landing;
    int NoofTakeoff ;
    int NoofLanding ;
    
    bool isEmpty(QUEUE * qptr)
    {
        return qptr->count==0;
    }
    bool isFull(QUEUE * qptr)
    {
        return qptr->count==MAX;
    }
    
    bool Enqueue(QUEUE * qptr, int planeno)
    {
        if(!isFull(qptr)){
       qptr->rear=(qptr->rear+1)%MAX; 
        qptr->data[ qptr-> rear ] = planeno;
        qptr->count++;
        return true;
        }
        else
            return false;
    }
    
    int Dequeue(QUEUE *qptr)
    {
        int data=EMPTY_INDICATOR;
        if(isEmpty(qptr)){
            fprintf(stderr,"QUEUE IS EMPTY");
        }
        else
        {
            qptr->front=(qptr->front+1)%MAX;
            data=qptr->data[qptr->front];
            qptr->count--;
        }
        return data;
    }

int isPlanenoValid(int planeno){
    if(planeno>0 && planeno<10000)
        return 1;
    else
        return 0;
}
void func()
{
    int oper,temp;
    bool b1;
    do
    {
        
    if(runway1.count==0 && landing.count>2)
      
    {
        oper=Dequeue(&landing);
        b1= Enqueue(&runway1,oper);
        NoofLanding++;
    }
    
    else if(runway2.count==0 && landing.count!=0)
    {
        oper=Dequeue(&landing);
        b1= Enqueue(&runway2,oper);
        NoofLanding++;
    }
    if(runway1.count!=0)
    temp=Dequeue(&runway1);
    
    if(runway1.count==0 && takeoff.count!=0)
    {
        oper=Dequeue(&takeoff);
        b1=Enqueue(&runway1,oper);
        NoofTakeoff++;
    }
    if(runway2.count!=0)
        temp=Dequeue(&runway2);
     if(runway2.count==0 && takeoff.count!=0)
    {
        oper=Dequeue(&takeoff);
        b1=Enqueue(&runway2,oper);
        NoofTakeoff++;
    }
     
    }while(landing.count!=0 && takeoff.count!=0);

}

int randomno()
{
       int planeno;
    int valid ;
    do{
    planeno=rand()/1000000;
   
    valid=isPlanenoValid(planeno);
    }while(!isPlanenoValid);
    return planeno;
}
bool nextBool(int planeno )
{
    if((planeno%100)>45)
        return 1;
    else
        return 0;
}
void generatePlanes(int num ){
    int planeno,i;
    
    bool pro,add;
    
    do
    {
      planeno=randomno();
      printf("%d\n",planeno);
      pro=nextBool(planeno);
 
      if(pro==1){
          add= Enqueue( &landing,planeno);
         if(add)
          {
           printf("Plane number %d's request to land is accepted...\n",planeno);
           func();
           
          }
          else
          {
              printf("Couldn't serve plane number %d 's request to land\n",planeno);
          }
      }
      else{
        add=  Enqueue(&takeoff, planeno);
            if(add)
           {
            printf("Plane number %d's request to takeoff is accepted...\n",planeno);   
            func();
           }
           else
           {
               printf("Couldn't serve plane number %d 's request to takeoff\n",planeno);
           }
      }
      i++;
//      sleep();
}while(i < num);
}

void main()
{
   
    int planeno,i=0,num;
    bool pro;
    printf("How many planes to handle?");
    scanf("%d",&num);
    
    generatePlanes(num );
        printf("No of planes:\t\t %d",num);
    printf("\nNo of landings:\t\t %d",NoofLanding);
    printf("\nNo of takeoffs:\t\t %d",NoofTakeoff);
    exit(EXIT_SUCCESS);
  
}

