/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   insertion_sort.cpp
 * Author: VINAY CHELLWANI
 *
 * Created on November 8, 2017, 9:14 PM
 */

//insertion sort any binary search

#include<iostream>
using namespace std;

main()
{
    int i,j,n,temp,a[5];
    cout<<"enter the elements";
    for(i=0;i<5;i++)
        {
          cin>>a[i];
        }

    for(i=1;i<5;i++)
        {
            temp=a[i];
            for(j=i-1;j>=0&&a[j]>temp;j--)
            {
              a[j+1]=a[j];
            }
            a[j+1]=temp;
        }
    cout<<"array after sorting is \n ";
    for(i=0;i<5;i++)
        {
          cout<<a[i]<<"\t";
        }

    cout<<"\nEnter the element to be found\n";
    cin>>n;
    int k=0;
    int flag=0;
    while(k<5)
        {
            if(a[k]==n)
            {
                cout<<"\n"<<"element found at position:\t"<< k+1<<"\n";
                flag=1;
                break;
            }

            else if(a[k]<n){
            k++;    
            continue;
            }

            else if(a[k]>n){
                k++;
                continue;
            }
    }//while
           if(flag==0){
                cout<<"element not found\n";
            }

       

}//main

