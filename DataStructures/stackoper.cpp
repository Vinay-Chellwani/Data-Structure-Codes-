/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: VINAY CHELLWANI
 *
 * Created on September 24, 2017, 11:27 AM
 */
#include <iostream>
#include <cstdlib>
#define max 5
using namespace std;
struct stack
{
	int a[5];
	int top;
};

void push(int x,struct stack* s)
{
    int y;
	if(s->top==(max-1))
	{
		cout<<"Stack overflow:";
	}
	else
	{
            s->top++;
		y=s->top;
		s->a[y]=x;
	}
}
int pop(struct stack* s)
{
   int x,y;
	if(s->top ==-1)
	{
		cout<<"Stack underflow:";
		return(-1);
	}
	else 
	{
                y=s->top;
		x= s->a[y];
		s->top--;
		return x;	
	}
}
 


/*
 * 
 */
int main(int argc, char** argv) {
    int ch,x;
    struct stack p;
    p.top=-1;
    struct stack *s=&p;
    do{
    cout<<"1.Push\n2.Pop\n3.Exit";
    cout<<"Enter your choice:";
    cin>>ch;
    switch(ch)
    {
        case 1:cout<<"Enter value:";
               cin>>x;
               push(x,s);
               break;
        case 2:x=pop(s);
               cout<<x <<"has been popped from the stack";
               break;
        case 3:exit(EXIT_SUCCESS);
        default:cerr<<"WRONG SELECTION";
        break;
    }
    }while(ch!=3);
    return 0;
}

