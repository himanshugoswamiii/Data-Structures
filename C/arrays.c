#include <stdio.h>
int main(){
    int myarr[]={10,20,30,40,50};
    // len of array
    int s=sizeof(myarr);
    int sOne=sizeof(myarr[0]);
    printf("Size of array is: %d \n",s);
    printf("Size of one element is: %u \n",sOne);
    int len=sizeof(myarr)/sizeof(myarr[0]);
    printf("Length of array is: %d \n",len);
    // Display array
    printf("\n Array is: \n");
    for (int i=0;i<len;i++){
        printf("%d\n",myarr[i]);
    }
    return 0;
}