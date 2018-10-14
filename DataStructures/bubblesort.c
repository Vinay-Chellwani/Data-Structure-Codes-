
#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
        int i,j,n,temp,a[5];
    printf("enter the elements");
    for(i=0;i<5;i++)
        {
          scanf("%d",&a[i]);
        }
    for(i=1;i<5;i++)
    {
        for(j=0;j<(5-i);j++)
        {
            if(a[j+1]<a[j])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("\nSorted elements are:\t");
 for(i=0;i<5;i++)
        {
          printf("%d ",a[i]);
        }
    printf("\n");
    
    return (EXIT_SUCCESS);
}

