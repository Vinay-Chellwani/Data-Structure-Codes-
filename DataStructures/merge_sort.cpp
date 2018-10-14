/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   merge_sort.cpp
 * Author: VINAY CHELLWANI
 *
 * Created on November 8, 2017, 7:23 PM
 */

#include<iostream>
using namespace std;
void merge_sort(int a[], int low,int up);
void merge(int a[],int low,int mid,int up);


// definitions complete
// definition of main begins
int main()
{
  int n=5,i;
  int a[5];
  cout<<"Enter array elements";
  for(i=0;i<n;i++)
  {
      cin>>a[i];
  }
  int up=n-1;
  int low=0;
  merge_sort(a,low,up);
for(i=0;i<5;i++)
	{
 		cout<<a[i] <<"\t";
	}
 
return 0;
  
}
void merge_sort(int a[], int low,int up)
{
  int mid;
   mid=(low+up)/2;
   if(up>low)
	{
		merge_sort(a,low,mid);
		merge_sort(a,(mid+1),up);
		merge(a,low,mid,up);
	}

}
void merge(int a[],int low,int mid,int up)
{
	int temp[5],i,j,k;

	i=low;
	j=mid+1;
	k=low;
	while(i<=mid && j<=up)
	{
		if(a[i]<a[j])
		{
			temp[k]=a[i];
			i++;
			k++;

		}
		else
		{ 
			temp[k]=a[j];

			j++;
			k++;

		}
}
	
	while(j<=up)
	{
		temp[k]=a[j];
		k++;
		j++;
	}
	while(i<=mid)
	{
		temp[k]=a[i];
		k++;
		i++;
	}

  for(i=low;i<=up;i++)
  {
	
	a[i]=temp[i];

	
  }
	
}


