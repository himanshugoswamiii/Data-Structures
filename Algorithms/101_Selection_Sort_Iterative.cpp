#include <iostream>
#include <type_traits>
using namespace std;

void SelectionSortItertive(int Arr[],int size){
    int min,index;
    for (int i = 0; i < size; i++) {
        min=Arr[i];
        index=i;
        for (int j = i+1; j < size; j++) {
            // Unsorted Array
            if(min>Arr[j]){
                min=Arr[j];
                index=j;
            }
        }
        if (i!=index)
        {
            swap(Arr[i],Arr[index]);
        }

        // Printing after each step
        for(int k=0;k<size;k++){
            cout<<Arr[k]<<" ";
        }
        cout<<endl;
    }

}

int main ()
{
    int Arr[]={23,1,11,45,3,4,5,-9,121};
    int size=sizeof(Arr)/sizeof(int);

    for(int x:Arr){
        cout << x << " ";
    }
    cout << endl;

    SelectionSortItertive(Arr,size);
    for(int x:Arr){
        cout << x << " ";
    }

    
    return 0;
}
