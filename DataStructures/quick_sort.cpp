#include <iostream>
#include <cstring>
using namespace std;

int quick_sort(int a[],int low,int up);
int partition(int a[],int low,int up);
strtok()
   int main()
	{
		int n=5,i=0;
                int a[5];
		cout<<"enter the elements";
                for(i=0;i<5;i++)
                    {
                      cin>>a[i];
                    }

		int low=0;
		int up=n-1;
		quick_sort(a,low,up);
        for(int i=0;i<n;i++)
		{
          cout<<a[i] <<"\t";
}
		return 0;
    }

int partition(int a[],int low,int up)
{
	int pivot=low;
        int left=low+1;
        int right=up;
	while(left<right)
	{
            while(a[left]<a[pivot])
		{
                    left++;
		}
		while( a[right]>a[pivot])
                {  
			right--;
		}
		
		if(left<=right)
		{
			int temp;
			temp=a[left];
			a[left]=a[right];
			a[right]=temp;
                        continue;
		}
	}
	int neo;
	neo=a[pivot];
	a[pivot]=a[right];
        a[right]=neo;
		
        return right;
}
int quick_sort(int a[],int low,int up)
{
    if(low<up)
{
	int pivpo=partition(a,low,up);
	quick_sort(a,low,(pivpo-1));
	quick_sort(a,(pivpo+1),up);
}
}
