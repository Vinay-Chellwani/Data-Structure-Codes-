

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * 
 */
void linearSearch(int arr[],int SIZE, int target) {
    int idx; 
    bool found = false;
    for (idx = 0; idx < SIZE; idx++) {
            if (arr[idx] == target) {
            found = true;
            break; 
        }
    }
    if (found == true) {
        printf("The number %d is found at position %d\n", target, (idx + 1));
    } else {
        printf("Number %d is not found!\n", target);
    }
    return;
}
int main() {
        int i,n,target,a[100];
   printf("enter the number of elements(1-100)\n");
   scanf("%d",&n);
   printf("enter the elements\n");
    for(i=0;i<n;i++)
        {
         scanf("%d",&a[i]);
        }
   printf("enter the target:\n");
   scanf("%d",&target);
   linearSearch(a,n,target);


    
}

