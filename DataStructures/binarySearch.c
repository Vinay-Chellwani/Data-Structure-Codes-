

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
void binarySearch(int arr[],int size ,int target) {
    int mid; 
    int upper = (size - 1);
    int lower = 0; 

    while (lower <= upper) {
        mid = (upper + lower) / 2;
        if (arr[ mid ] == target) {
            printf("Found at position %d\n", mid + 1);
            break; 
        }
        if (arr[ mid ] > target) {
            upper = mid - 1;
        } else {
            lower = mid + 1;
        }
    }
    if (lower > upper) {
        printf("%d is not found in the array\n", target);
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
   binarySearch(a,n,target);
    return (EXIT_SUCCESS);
}

