#include <stdio.h>
void disArr(int Arr[],int len){
    for (int i=0; i<len; i++) {
        printf("Index: %d, Value: %d\n",i,Arr[i]);
    }
}


int binarySearch(int arr[],int x,int l, int h){
    // l : low, h: high
    if (h >= l) {
        int mid = (l + h) / 2; // index of the mid element
 
        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;
 
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, x, l, mid-1);
        else
            return binarySearch(arr, x,mid + 1, h);
        // Else the element can only be present
        // in right subarray
    }
     
    // We reach here when element is not
    // present in array
    return -1;
}

int main (int argc, char *argv[])
{
    int Arr[]={1,3,4,6,10,20,31,34,35,40,61};
    int len=sizeof(Arr)/sizeof(Arr[0]); // Here i shouldn't use sizeof
    printf("The length of the array is : %d \n",len);
    disArr(Arr,len);

    int el;
    printf("Enter element to search in the array: ");
    scanf("%d",&el); // Input for the element to search
    int pos=binarySearch(Arr,el,0,len-1); // 0: start of the array, len-1 : length of the array
    printf("The element is at index position %d\n",pos);

    return 0;
}
