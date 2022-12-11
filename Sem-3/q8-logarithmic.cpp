#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int kth(int Arr1[], int Arr2[],int s1, int e1, int s2, int e2, int k){
    int index1 = k-1;
    int index2 = -1;

    // Length
    int l1=e1-s1;
    int l2=e2-s2;

    if (k > l1+l2)
    {
        return -1;
    }

    while (true){
        if (index2 < 0 && Arr1[index1] <= Arr2[index2+1])
        {
            return Arr1[index1];
            
        }
        else if (index1 < 0 && Arr2[index2] <= Arr1[index1+1])
        {
            return Arr1[index1];
            
        }

        if(Arr1[index1] < Arr1[index1+1] && Arr1[index1] < Arr2[index2+1]){
            return(max(Arr1[index1], Arr2[index2]));
        }
        else{
            index1--;
            index2++;
        }
            
    }
}


int main ()
{

    int Arr1[] = {2, 3, 6, 7, 9};
    int Arr2[] = {1, 4, 8, 10};
    int l1 = sizeof(Arr1)/sizeof(int);
    int l2 = sizeof(Arr2)/sizeof(int);

    int k=3;

    cout << kth(Arr1, Arr2, l1, l2, k);
    return 0;
}
