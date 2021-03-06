// Array of Vectors(https://www.geeksforgeeks.org/array-of-vectors-in-c-stl/)
#include "iostream"
#include <vector>
using namespace std;

class himanshu{
    public:
        vector<vector<vector<int>>> vect; // Array of vectors
        vector <vector<int>> va;
        vector <vector<int>> vb;
        vector <vector<int>> vc;
        vector <vector<int>> vd;

        himanshu(int A[],int n){
            // An array is passed into the constructor
            int Arr[n];
            for (int i=0;i<n;i++){
                Arr[i]=A[i];
            }

        }

        void addtoVec(int a[]){
            if (a[3]==1)
            {
                vector <int> v1;
                v1.push_back(a[0]);
                v1.push_back(a[1]);
                v1.push_back(a[2]);
                v1.push_back(a[3]);
                va.push_back(v1);
            } 
            else if (a[3]==2){
                vector <int> v2;
                v2.push_back(a[0]);
                v2.push_back(a[1]);
                v2.push_back(a[2]);
                v2.push_back(a[3]);
                vb.push_back(v2);
            }
            else if (a[3]==3){
                vector <int> v3;
                v3.push_back(a[0]);
                v3.push_back(a[1]);
                v3.push_back(a[2]);
                v3.push_back(a[3]);
                vc.push_back(v3);
            }
            else if (a[3]==4){
                vector <int> v4;
                v4.push_back(a[0]);
                v4.push_back(a[1]);
                v4.push_back(a[2]);
                v4.push_back(a[3]);
                vd.push_back(v4);
            }

        }

        void finalvec(){
            vect.push_back(va);
            vect.push_back(vb);
            vect.push_back(vc);
            vect.push_back(vd);
        }

        void permute(int a[], int l, int r)
        { 
            // Base case 
            // Create a vector to store the possible combination
            if (l == r) {
                for (int i=0;i<=r;i++){
                    cout<<a[i]<<" "; 
                }
                addtoVec(a);
                cout<<endl;
            }

            else
            { 
                // Permutations made 
                for (int i = l; i <= r; i++) 
                { 
          
                    // Swapping done 
                    swap(a[l], a[i]); 
          
                    // Recursion called 
                    permute(a, l+1, r);
          
                    //backtrack 
                    swap(a[l], a[i]); 
                } 
            } 
        } 

        void printVec(){
            for (int i = 0; i < vect.size(); i++) {
            cout<<"\n **  Instances in which A[i] is inserted at : "<<i+1<<endl;
                for (int j = 0; j < vect[i].size(); j++){
                    cout << " -- ";
                    for (int k = 0; k < vect[i][j].size(); k++)
                        cout << vect[i][j][k] << " ";
                }
                cout<<"\n Total no of Permutations : "<<vect[i].size();
                cout<<"\n Probability that A[i] will be inserted at "<<i+1<<" is "<<" 1/4";
                cout<<endl;
            }
        }
}; 

  
// Driver Code 
int main() 
{ 
    int Arr[]={1,2,3,4};
    int n = sizeof(Arr)/sizeof(int);
    himanshu H(Arr,n);
    int **m_Arr=new int*[24]; // Multidimensional array
    cout<<"\n*** Total Combinations of Permutations *** \n";
    H.permute(Arr, 0, n-1);
    H.finalvec();
    H.printVec();
    return 0; 
} 
