

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_QUEUE_SIZE 5 
struct QUEUE{
        
        int container[ MAX_QUEUE_SIZE ];
        int front;
        int rear;
        int  count;
    };

    typedef struct QUEUE QUEUE;
    
    bool isEmpty(QUEUE* qptr) {
    return (qptr-> count==0);
}

    bool isFull(QUEUE* qptr) {
    return (qptr->count== (MAX_QUEUE_SIZE - 1));
}
void enqueue(QUEUE* qptr, int data) {
    bool added = true;
   
    if (isFull(qptr)) {
        added = false;
    } 
    else {
         qptr->rear = (qptr->rear + 1) % MAX_QUEUE_SIZE;
        qptr->container[ qptr->rear] = data;
        qptr->count = qptr->count + 1;
    }
     if (added == true) {
     printf("\t\'%d\' has been added to the Queue\n", data);
    } 
     else {
       printf("\tQueue is Full\n");             
      }
}

int dequeue(QUEUE *qptr) {
    
    int data = -0.0001;
    if (!isEmpty(qptr)) {
       qptr->front = (qptr->front + 1) % MAX_QUEUE_SIZE;
        data = qptr->container[ qptr->front ];
        qptr->count = qptr->count- 1;
       
    }
    else  {
        
//        printf("Queue is empty");
        qptr->rear=qptr->front=-1;
        qptr->count=0;
    }
    
    return (data);
}
/*
 * 
 */
int main() {
    int ch=0,data=0;
    QUEUE a;
    a.rear=a.front=-1;
    do{
    printf("1.ENQUEUE\n2.DEQUEUE\n3.EXIT\n");
    printf("Enter your choice");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:printf("\tPlease enter a integer : ");
                scanf("%i", &data);
                enqueue(&a, data);
                break;
        case 2:data = dequeue(&a);
                if(data != 0)
               printf("\tThe element deleted is \'%d\'\n", data);
                else
                    printf("Queue is empty\n");
                break;
        case 3:exit(EXIT_SUCCESS);
        default:printf("Invalid selection");
    } 
    }while(ch!=3);

    return (EXIT_SUCCESS);
}

