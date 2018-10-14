/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   stackChallenge.cpp
 * Author: VINAY CHELLWANI
 *
 * Created on November 15, 2017, 11:33 PM
 */
#include<iostream>
#include <cstdlib>
#include <string>
#include <cstring>

#define MAX 100
using namespace std;
struct element
{
    int p;
    string s;
};
struct stack
{
  struct element a[MAX];
  int top;
}*sp;

string str;

void push(struct element c)
{
  if((sp->top)==MAX-1)
    cout<<"Stack overflow";
  else
  {
    (sp->top)++;
    (sp->a[sp->top]).p=c.p;
     (sp->a[sp->top]).s=c.s;
  }  
}
struct element pop()
{
  struct element c;
  if(sp->top==-1)
    cout<<"Stack underflow";
  else
    {c.p=(sp->a[sp->top]).p;
      c.s=sp->a[sp->top].s;
     sp->top--;}
 return c;
}
int menu(){
   
    int ch;
    cout<<"\n\t\t TEXT EDITOR\n****************)";
    cout<<"\n\t1.Append string";
    cout<<"\n\t2.Delete k characters";
    cout<<"\n\t3.Print kth character";
    cout<<"\n\t4.Undo";
    cout<<"\n\t5.Exit";
    cout<<"\n\t\tPlease enter the choice";
    cin>>ch;
    return ch;
}
/*
 * 
 */
int main(int argc, char** argv) {
     struct stack st;
     
    sp=&st;
    st.top=-1;
    int choice,k,x;
    string str1;
    struct element temp;
    
    do{
        choice=menu();
        switch(choice)
        {
            case 1:cout<<"Enter the string:";
                   cin>>str1;
                   str.append(str1);
                   temp.p=choice;
                   temp.s=str;
                   push(temp);
                   break;
            case 2:cout<<"\n\t\t\tEnter number of elements to be deleted";
                    cin>>k;
                    x=str.length();
                    for(int i=0;i<(x-k);i++)
                    {
                        str1.at(i)=str.at(i);
                        str.clear();
                    }
                    str=str1;
                    temp.p=choice;
                    temp.s=str;
                    push(temp);
                    break;
            case 3:cout<<"\n\t\t\tEnter the element number to be displayed";
                    cin>>k;
                    cout<<str.at(k-1);
                    break;
            case 4:temp=pop();
                    if(temp.p==1)
                    {
                       k=str.length()-temp.s.length();
                       for(int i=0;i<k;i++)
                       {
                           str1.at(i)=str.at(i);
                           str.clear();
                       }
                       str=str1;
                        break;
                    }
                    else{
                        str.append(temp.s);
                        break;
                    }
            case 5: cout<<str<<endl;
                exit(EXIT_SUCCESS);
            default:cout<<"INVALID OPERATION";
                    break;
        }
        
    }while(choice!=5);
   
    
    return 0;
}

