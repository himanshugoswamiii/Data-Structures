#include "stdio.h"
void printArr(int Arr[],int f,int r,int n){
    // n -> size of the array
    // f -> front
    // r -> rear -- no need for rear
    int temp=f;
    while (temp!=r)
    {
        printf("%d\n",Arr[temp]);
        temp++;
        temp=temp%n;
        if (temp==r){
            break;
        }
    }
}
int main (int argc, char *argv[])
{
    int myArr[]={70,-1,-1,10,20,30,40,50,60};
    // Here -1 represents these elements are empty
    int n=sizeof(myArr)/sizeof(int);
    printArr(myArr,3,0,n); 
    return 0;
}
