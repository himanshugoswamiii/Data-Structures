#include <iostream>
using namespace std;

void printArray(int Arr[],int length){
    for (int i = 0; i < length; i++) {
        cout << Arr[i] << " ";
    }
    cout << endl;
}
int binarySearch(int Arr[],int end,int el,int start=0){
    /* l -> length of the array
    el -> element to be searched
    */
    int mid=(start+end)/2;
    if (el<Arr[start] || el>Arr[end])
    {
        return 0;
    }

    if (el==Arr[mid])
    {
        return 1;
    }
    else if (el>Arr[mid])
    {
       return binarySearch(Arr, end, el, mid+1);
    }
    else
    {
        return binarySearch(Arr, mid-1, el, 0);
    }

}

int main ()
{
    int Arr[]={2,4,5,7,9,20};
    int len=sizeof(Arr)/sizeof(int);
    printArray(Arr,len);
    int el,times;
    cin >> times;
    for (int i = 0; i < times; i++) {
        cout << "\nEnter the element" << endl;
        cin >> el;
        int x=binarySearch(Arr,len,el);
        if (x==1)
        {
            printf("element found\n");
        }
        else
        {
            printf("Element not found\n");
        }
        
    }
    return 0;
}
