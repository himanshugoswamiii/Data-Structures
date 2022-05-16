// Output: 1,1,2,3,1,5,6
#include <stdio.h>
int main (int argc, char *argv[])
{
    int arr[]={18,6,8,10,5,12,13};
    int len=sizeof(arr)/sizeof(int);
    int farr[len];
    int i=0;
    while (i!=len) {
        int count=0;
        for(int j=0;j<i;j++){
            if (arr[j]<=arr[i]){
                count++;
            }
        }
        farr[i]=count+1;
        i++;
    }
    // Printing the span
    for (i=0;i<len;i++){
        printf("S_%d: %d\n",i,farr[i]);
    }
    return 0;
}
