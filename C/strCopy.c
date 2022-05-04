#include <string.h>
#include <stdio.h>
int main(){
    char name[]="Himanshu Goswami";
    char name2[30]; // Here we've to give size
    int l1=strlen(name);
    printf("Length of name %d \n",l1);
    strcpy(name2, name);
    printf("Copied value is: %s\n",name2);
    int l2=strlen(name);
    printf("Length of name2 %d \n",l2);
}