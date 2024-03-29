//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


// } Driver Code Ends
class Solution
{
    public:
        void selectionSort(int arr[], int n)
        {
            int min,index;
            for (int i = 0; i < n; i++) {
                index=i;
                min=arr[i]; // Assumen first element is the minimum
                for (int j = i; j < n; j++) {
                    // find the minimum
                    if (min>arr[j])
                    {
                        min=arr[j];
                        index=j; // Storing the index
                    }
                }
                // Swap min with arr[i]
                swap(arr[i],arr[index]);
            }

        }
};

//{ Driver Code Starts.
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver program to test above functions
int main()
{
    int arr[1000],n,T,i;
  
    scanf("%d",&T);
    
    while(T--){
        
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      
    Solution ob;  
    ob.selectionSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends
