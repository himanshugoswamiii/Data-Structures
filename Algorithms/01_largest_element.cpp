#include <iostream>
using namespace std;
int main ()
{
    int Arr[]={-8,45,1,2,5,98,2,-4,111,21};
    int length=sizeof(Arr)/sizeof(int);
    int max;
    int min;
    int cmax;
    int cmin;
    // Check if Array contains even no of elements or odd no of elements
    if(length%2==0){
        // Even
        // Make the first min and max
        if (Arr[0]<Arr[1])
        {
            min=Arr[0];
            max=Arr[1];
        }
        else
        {
            max=Arr[0];
            min=Arr[1];
        }

    }
    else{
        max=min=Arr[0];
    }


    // Remaining elements n-2
    for (int i = 2; i < length; i=i+2) {
        if (Arr[i]<Arr[i+1])
        {
            cmin=Arr[i];
            cmax=Arr[i+1];
        }
        else{
            cmin=Arr[i+1];
            cmax=Arr[i];
        }

        // Change min
        if (min>cmin)
        {
            min=cmin;
        }
        
        // Change max
        if (max<cmax){
            max=cmax;
        }

        
    }

    cout << "min is: "<<min << endl;
    cout << "max is: "<<max << endl;
    return 0;
}
