/*Find h : the closest previous day on which the stock price is greater than that on the ith day
Use of stack: 
- Storing the possible values of h(7) ?
*/

#include <stdio.h>
void reverseArr(int arr[],int *myarr,int len){
    for (int i=0; i<len; i++) {
    myarr[i]=arr[len-i-1]; // Reversing an array
    }
}

int main (int argc, char *argv[])
{
    int arr[]={18,6,8,10,5,12,13};
    int len=sizeof(arr)/sizeof(int);
    int myarr[len];
    reverseArr(arr,myarr,len);
    // Reversing the array
    for (int i=0;i<len;i++){
        printf("S_%d: %d\n",i,myarr[i]);
    }
    return 0;
}

