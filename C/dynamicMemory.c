#include <stdio.h>
#include <stdlib.h>
 
int main()
{
 
    // This pointer will hold the
    // base address of the block created
    int* ptr;
    int n, i;
 
    // Get the number of elements for the array
    printf("Enter number of elements: ");
    scanf("%d",&n);
 
    // Dynamically allocate memory using calloc()
    ptr = (int*)calloc(n, sizeof(int));
 
    // Check if the memory has been successfully
    // allocated by calloc or not
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {
        // Memory has been successfully allocated
        printf("Memory successfully allocated using calloc.\n");
 
        printf("Enter your elements: \n");
        // Get the elements of the array
        for (i = 0; i < n; ++i) {
            scanf("%d",&ptr[i]);
        }
 
        // Print the elements of the array
        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i) {
            printf("%d\n", ptr[i]);
        }
    }
 
    return 0;
}
